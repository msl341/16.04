-- 常用回调函数，基于物联型LUA脚本API开发
-- 修复说明：解决cmd1/cmd2粘包问题、E4指令变3F问题、串口配置异常、变量重复定义等bug
global_cmd_group = nil
local current_screen = nil
-- 全局变量声明（含新增修复相关变量）
oldScreen = 0
flag_init = 0
GainNum = 0  -- 存储256文本值（保留）
timerNumber = 0  -- 定时计数
oldScreen01 = 0  -- 画面切换标记
current_cmd_value = 0  -- 与257值绑定，cmd_map下标（-10~10）
delay_send_bytes = nil  -- 延时发送缓存
delay_current_cmd = nil	
delay_cmd_direction = 0  -- 0:递减(95按键), 1:递增(96按键)
delay_cmd2 = nil  -- 缓存cmd2，用于延时发送（新增）
a = {}  -- 全局存储Flash读取数据（避免局部变量冲突）

-- 已验证发送成功的字节数组
us_data = {0XB1 ,0X11 ,0X00 ,0X00 ,0X00 ,0X45 ,0X10 ,0X01 ,0X01 ,0XFF, 0XFC, 0XFF, 0XFF}
us_data[0] = 0XEE
us_data1 = {0XB1 ,0X11 ,0X00 ,0X01 ,0X00 ,0X16 ,0X10 ,0X01 ,0X01 ,0XFF, 0XFC, 0XFF, 0XFF}
us_data1[0] = 0XEE

uart_free_protocol = 1  -- 开启自由串口协议，触发on_uart_recv_data回调
send_table = {0x5A, 0xA5}
send_table[0] = 0xED

-- 接收缓存相关（串口1）
local recv_buf = {}  -- 存储待解析的45字节数据
local recv_count = 0 -- 接收字节计数
local cmd_head_tag = 0  -- 帧头标记：0=未找到，1=找到EE，2=找到AA（完整帧头）
local cmd_length = 0    -- 串口1接收缓存字节数

-- 测试数据数组
test_data = {0XB1 ,0X10 ,0X00 ,0X00 ,0X00 ,0XA5 ,0X01  ,0XFF, 0XFC, 0XFF}
test_data[0] = 0XEE
test_data1 = {0XB1 ,0X10 ,0X00 ,0X00 ,0X00 ,0XA6 ,0X00  ,0XFF, 0XFC, 0XFF}
test_data1[0] = 0XEE

-- 串口3接收相关
local cmd_head = 0x5A           -- 帧头
local buff = {}                 -- 缓冲区
local data_length = 0
local uart3_cmd_head_tag = 0    -- 串口3帧头标记（避免与串口1冲突）
local uart3_cmd_length = 0      -- 串口3缓存字节数（重命名避免重复）

-- 设备指令发送数组
send_table1 = {0XB1 ,0X11 ,0X00 ,0X00 ,0X00 ,0X45 ,0X10 ,0X01 ,0X01 ,0XFF, 0XFC, 0XFF, 0XFF}
send_table1[0] = 0XEE

-- 荧光参数状态存储
OldlightValue = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
lightValue = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

-- 指令映射表（下标-10~10，E4系列指令）
cmd_map = {
    [-10] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x00}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x00}},
    [-9] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x05}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x05}},
    [-8] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x0A}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x0A}},
    [-7] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x0F}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x0F}},
    [-6] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x14}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x14}},
    [-5] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x19}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x19}},
    [-4] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x1E}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x1E}},
    [-3] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x23}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x23}},
    [-2] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x28}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x28}},
    [-1] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x2D}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x2D}},
    [0] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x32}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x32}},
    [1] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x37}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x37}},
    [2] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x3C}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x3C}},
    [3] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x41}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x41}},
    [4] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x46}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x46}},
    [5] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x48}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x48}},
    [6] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x50}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x50}},
    [7] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x55}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x55}},
    [8] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x5A}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x5A}},
    [9] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x5F}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x5F}},
    [10] = {cmd1 = {[0]=0xE4, [1]=0x00, [2]=0x64}, cmd2 = {[0]=0xE4, [1]=0x01, [2]=0x64}}
}
-- 新增全局函数：确保current_cmd_value在-10~10有效范围
function check_cmd_value_range(val)
    local ret = tonumber(val) or 0  -- 非数字转为0（容错）
    ret = math.max(-10, math.min(10, ret))  -- 锁定边界
    return ret
end

-- 初始化函数
function on_init()
    -- 串口3配置（固定波特率，明确开启接收）
    uart_set_baudrate3(115200)
    print("串口3初始化完成：波特率115200，接收已开启")

    -- 读取Flash数据（屏幕ID、256值、257关联下标）
   -- a = read_flash(0x0010, 48)
   -- change_screen(a[1] or 1)  -- 容错：默认屏幕1
    flag_init = 1
 change_screen(6)
current_screen=6
	   set_text(4, 257, 0)
    set_text(5, 257, 0)
    set_text(0, 101, 0)
    set_text(4, 258, 0)
    set_text(5, 258, 0)
set_text(0, 102, 0)
  set_text(4, 259, 0)
  set_text(5, 259, 0)
set_text(0, 103, 0)



    -- 256文本初始化（保留原逻辑）
  local gain_val = a[2] or 0
   set_text(1, 256, tostring(gain_val))
    set_text(2, 256, tostring(gain_val))
   set_text(4, 256, tostring(gain_val))
  set_text(5, 256, tostring(gain_val))
   set_text(0, 158, gain_val)   

    GainNum = tonumber(gain_val) or 0


    -- 初始化current_cmd_value（257关联，强化边界校验）
   -- current_cmd_value = check_cmd_value_range(a[3])
    print("---------INIT完成----------")
    print("屏幕ID：", a[1] or 1)
    print("256文本值：", gain_val)
    print("257关联下标（current_cmd_value）：", current_cmd_value)
    print("--------------------------")
end

-- 定时回调函数
function on_systick()
    
   -- local gain_val = a[2] or 0
   -- set_text(1, 1111, tostring(gain_val))
    --set_text(2, 1111, tostring(gain_val))

    -- 屏幕未切换时，定时保存数据到Flash
    --if oldScreen01 == oldScreen then
      --  if timerNumber < 10 then
         --   timerNumber = timerNumber + 1
       -- end
      --  if timerNumber == 5 then
            -- 保存：屏幕ID、256值、current_cmd_value（257关联）
         --   local save_data = {oldScreen, gain_val, current_cmd_value}
           -- write_flash(0x0010, save_data)
            -- print("Flash保存完成：", table.concat(save_data, ","))
       -- end
   -- else
   --     oldScreen01 = oldScreen
   -- end

    -- 循环发送固定指令（0xED 0x5A 0xA5）
    uart_send_data(send_table)
    -- print("已发送固定指令：0xED, 0x5A, 0xA5")
end

-- 串口1接收数据回调（解析45字节帧）
-- 串口1接收数据回调（解析45字节帧，新增第4位0/1判断+显示）
function on_uart_recv_data(packet)
    for i = 0, #packet - 1 do
        local curr_byte = packet[i]
        -- 分步校验帧头（EE AA）
        if cmd_head_tag == 0 then
            if curr_byte == 0xEE then
                cmd_head_tag = 1
                recv_buf[0] = curr_byte
                cmd_length = 1
            end
        elseif cmd_head_tag == 1 then
            if curr_byte == 0xAA then
                cmd_head_tag = 2
                recv_buf[1] = curr_byte
                cmd_length = 2
            else
                -- 帧头不完整，重置
                cmd_head_tag = 0
                recv_buf = {}
                cmd_length = 0
            end
        else
            -- 缓存数据，满45字节解析
            recv_buf[cmd_length] = curr_byte
            cmd_length = cmd_length + 1
            if cmd_length == 45 then
                -- 提取Byte11和Byte12（索引11、12）
                local byte11_val = recv_buf[11] or 0
                local byte12_val = recv_buf[12] or 0
                -- 显示Byte11/Byte12到原有文本框
                set_text(1, 17, tostring(byte12_val))
                set_text(1, 18, tostring(byte11_val))
                set_text(4, 17, tostring(byte12_val))
                set_text(4, 18, tostring(byte11_val)) 
                print("串口1解析成功：Byte11=" .. byte11_val .. ", Byte12=" .. byte12_val)

                -- ========== 新增：判断第4位 ==========
                local byte4_val = recv_buf[4] or 0  -- 提取第4位值，默认0避免nil
                print("串口1帧第4位值：" .. byte4_val)  -- 调试日志
                
                -- 判断值为0/1，显示到ID20文本框；非0/1时显示"异常"
                if  byte4_val == 1 then
					 if current_screen==6 then
							change_screen(1)
						current_screen=1
					end
                else
					current_screen=6
					  change_screen(6)
                    -- 异常值处理：显示"异常"并打印警告
                   -- set_text(1, 36,tostring(byte4_val))
                    print("警告：串口1帧第4位值为" .. byte4_val .. "，非预期的0/1")
                end
                -- =============================================================

                -- 重置缓存，准备下次接收
                cmd_head_tag = 0
                recv_buf = {}
                cmd_length = 0
            end
        end
    end
end
-- 定时器回调函数（处理延时发送、重绘）

function on_timer(timer_id)
    -- 定时器0：界面重绘
    if timer_id == 0 then
        redraw()
    -- 定时器1：处理95/96按键的指令发送（更新下标+发送cmd1）
    elseif timer_id == 1 then
        -- 1. 更新current_cmd_value（根据按键方向增减，强制边界）
        if delay_cmd_direction == 0 then
            -- 95按键：递减
           -- current_cmd_value = check_cmd_value_range(delay_current_cmd - 1)
        else
            -- 96按键：递增
          --  current_cmd_value = check_cmd_value_range(delay_current_cmd + 1)
        end
        -- 2. 获取当前下标对应的指令组
        --local cmd_group = cmd_map[current_cmd_value]


     --   if not cmd_group or type(cmd_group) ~= "table" then
         --   print("指令发送失败：未找到下标" .. current_cmd_value .. "对应的cmd_map配置")
         --   delay_cmd2 = nil
         --   return
      --  end
        -- 3. 直接发送cmd1（无需手动构造，校验表格完整性即可）
        local cmd1 = global_cmd_group.cmd1
        -- 校验：cmd1必须是连续下标表格（含0、1、2位，且0位是E4）
        if cmd1 and type(cmd1) == "table" and cmd1[0] == 0xE4 and cmd1[1] ~= nil and cmd1[2] ~= nil then
            -- 发送前清空串口3缓存（可选，根据硬件稳定性决定）
           -- if uart_clear_buf3 then
            --    uart_clear_buf3()
            --end
            -- 直接发送cmd1表格（大彩Lua会自动解析下标0-2的连续字节）
            uart_send_data(cmd1)
            -- 打印完整3字节指令（修正日志索引，直接取cmd1的0-2位）
            print("发送cmd1（下标" .. current_cmd_value .. "）：" .. string.format("%02X %02X %02X", cmd1[0], cmd1[1], cmd1[2]))
        else
            print("cmd1非法：下标" .. current_cmd_value .. "（缺失E4/字节不完整）")
            delay_cmd2 = nil
            return
        end
        -- 4. 延时50ms发送cmd2（同样直接发送，无需构造）
        local cmd2 = global_cmd_group.cmd2
        if cmd2 and type(cmd2) == "table" and cmd2[0] == 0xE4 and cmd2[1] ~= nil and cmd2[2] ~= nil then
            
            delay_cmd2 = cmd2
	  -- uart_send_data(cmd2)
	-- print("发送cmd2（下标" .. current_cmd_value .. "）：" .. string.format("%02X %02X %02X",  cmd2[0], cmd2[1], cmd2[2]))

            -- 启动定时器2：单次触发，50ms后发送
            start_timer(2, 5, 0, 1)
        else
            print("cmd2非法：下标" .. current_cmd_value .. "（缺失E4/字节不完整）")
            delay_cmd2 = nil
        end
        -- 5. 保存更新后的下标到Flash
       -- local save_data = {oldScreen, a[2] or 0, current_cmd_value}
        --write_flash(0x0010, save_data)
       -- print("Flash已保存：current_cmd_value=" .. current_cmd_value)
    -- 定时器2：直接发送缓存的cmd2
   elseif timer_id == 2 then
        if delay_cmd2 and type(delay_cmd2) == "table" and delay_cmd2[0] == 0xE4 and delay_cmd2[1] ~= nil and delay_cmd2[2] ~= nil then
            -- 直接发送cmd2表格
            uart_send_data(delay_cmd2)
            -- 打印完整3字节指令
            print("发送cmd2（下标" .. current_cmd_value .. "）：" .. string.format("%02X %02X %02X", delay_cmd2[0], delay_cmd2[1], delay_cmd2[2]))
            -- 清空缓存
           delay_cmd2 = nil
       else
            print("cmd2发送失败：缓存数据不完整")      
        end
    end
end
-- 画面绘制函数
function on_draw()
    
end

-- 控件触发回调函数
function on_control_notify(screen, control, value)
    print("===========控件触发============")
    print("屏幕ID: " .. tostring(screen) .. ", 控件ID: " .. tostring(control) .. ", 状态: " .. tostring(value))

    -- 屏幕1控件（设备切换、参数调节）
    if screen == 1 or screen == 2 then
        if value == 1 then
            -- 设备切换指令（修改send_table1第6位）
            local cmd6_map = {
                [14] = 0x0E,   -- 耳鼻镜
                [11] = 0x0B,   -- 腹腔
                [15] = 0x0F,   -- 喉镜
                [12] = 0x0C,   -- 宫腔泌尿镜
                [13] = 0x0D,   -- 关节
                [180] = 0xB4,  -- 纤维
                [181] = 0xB5,  -- 预留
                [5] = 0x05,    -- 预留
                [6] = 0x06,    -- 预留
                [7] = 0x07,    -- 预留
                [8] = 0x08,    -- 预留
                [9] = 0x09,    -- 预留
                [4] = 0x04,    -- 预留
                [2] = 0x02,    -- 预留
                [1] = 0x01,    -- 预留
                [3] = 0x03     -- 预留
            }
            local cmd6 = cmd6_map[control]
            if cmd6 then
                send_table1[6] = cmd6
                uart_send_data3(send_table1)
                print("发送设备指令：send_table1[6] = 0x" .. string.format("%02X", cmd6))
            end

            -- 荧光增益调节（屏幕1）
            if control == 93 then
                us_data[6] = 0x5D
                uart_send_data3(us_data)
                print("荧光增益-（控件93）")
            elseif control == 94 then
                us_data[6] = 0x5E
                uart_send_data3(us_data)
                print("荧光增益+（控件94）")
            elseif control == 41 then
                test_data[7] = 0x01
                uart_send_data3(test_data)
                print("荧光调节（控件41）")
            elseif control == 26 then
                test_data1[7] = 0x00
                uart_send_data3(test_data1)
                print("荧光调节（控件26）")
            elseif control == 27 then
                test_data1[7] = 0x01
                uart_send_data3(test_data1)
                print("荧光调节（控件27）")
            elseif control == 28 then
                test_data1[7] = 0x02
                uart_send_data3(test_data1)
                print("荧光调节（控件28）")
            elseif control == 22 then
                us_data1[6] = 0x16
                uart_send_data3(us_data1)
                print("荧光增益+（控件22）")
            elseif control == 23 then
                us_data1[6] = 0x17
                uart_send_data3(us_data1)
                print("荧光增益+（控件23）")
            end
        else
            -- 控件松开状态（仅处理控件41）
            if control == 41 then
                test_data[7] = 0x00
                uart_send_data3(test_data)
                print("荧光调节复位（控件41松开）")
            end
        end
    end



    -- 屏幕4/5控件（荧光调节+95/96按键）
    local adjust_screens = {4, 5}
    if table.contains(adjust_screens, screen) and value == 1 then
        -- 荧光调节指令
        local us6_map = {
            [93] = 0x5D,   -- 增益-
            [94] = 0x5E,   -- 增益+
            [95] = 0x5F,   -- 预留-
            [96] = 0x60,   -- 预留+
            [97] = 0x61,   -- 预留-
            [98] = 0x62,   -- 预留+
            [99] = 0x63,   -- 预留-
            [124] = 0x7C   -- 预留+
        }
        local us6 = us6_map[control]
        if us6 then
            us_data[6] = us6
            uart_send_data3(us_data)
            print("屏幕" .. screen .. "荧光调节：us_data[6] = 0x" .. string.format("%02X", us6))
        end

        -- 其他荧光调节控件
        if control == 41 then
            test_data[7] = 0x01
            uart_send_data3(test_data)
            print("屏幕" .. screen .. "荧光调节（控件41）")
        elseif control == 21 then
            test_data[7] = 0x00
            uart_send_data3(test_data)
            print("屏幕" .. screen .. "荧光调节复位（控件21）")
        elseif control == 26 then
            test_data1[7] = 0x00
            uart_send_data3(test_data1)
            print("屏幕" .. screen .. "荧光调节（控件26）")
        elseif control == 27 then
            test_data1[7] = 0x01
            uart_send_data3(test_data1)
            print("屏幕" .. screen .. "荧光调节（控件27）")
        elseif control == 28 then
            test_data1[7] = 0x02
            uart_send_data3(test_data1)
            print("屏幕" .. screen .. "荧光调节（控件28）")
        end
    end

    -- 95/96按键处理
    if control == 95 and value == 0 then
        local current_val = current_cmd_value
        delay_current_cmd = current_val
        delay_cmd_direction = 0  -- 递减
        local cmd_group = cmd_map[current_val]
        if cmd_group and type(cmd_group) == "table" then
            delay_send_bytes = cmd_group
            print("95键松开：从下标" .. current_val .. "递减，20ms后发送指令")
            start_timer(1, 0, 0, 1)
        else
            print("95键指令不存在：下标" .. current_val)
        end
    elseif control == 96 and value == 0 then
        local current_val = current_cmd_value
        delay_current_cmd = current_val
        delay_cmd_direction = 1  -- 递增
        local cmd_group = cmd_map[current_val]
        if cmd_group and type(cmd_group) == "table" then
            delay_send_bytes = cmd_group
            print("96键松开：从下标" .. current_val .. "递增，20ms后发送指令")
            start_timer(1, 0, 0, 1)
        else
            print("96键指令不存在：下标" .. current_val)
        end
    end
end

-- 串口3接收数据处理（设备反馈）
function my_processmessage(msg)  --处理接收到的串口3的数据
    local recv_string = ''
	if msg[0] == 0xB1 then
	if msg[1] == 0x10 then
	if msg[2] == 0x00 then
	if msg[3] == 0x00 then
	if msg[4] == 0x00 then
		if msg[5] == 0x20 then
			if msg[6] == 0x01 then
				set_value(1,32,1)	
				set_value(2,32,1)	
			else
				set_value(1,32,0)
				set_value(1,32,0)	
			end	
		end
		if msg[5] == 0x1f then
			if msg[6] == 0x01 then
				set_value(1,31,1)	
				set_value(2,31,1)	
			else
				set_value(1,31,0)
				set_value(1,31,0)	
			end	
		end
			if msg[5] == 0x21 then
			if msg[6] == 0x01 then
				set_value(1,33,1)	
				set_value(2,33,1)	
			else
				set_value(1,33,0)
				set_value(1,33,0)	
			end	
		end

		
if msg[5] == 0x9E then
			if  msg[6] > 0XF0 then 
				GainNum = 0x100-msg[6]
				set_text(1,256,"-"..tostring(GainNum))
				set_text(2,256,"-"..tostring(GainNum))
				set_text(4,256,"-"..tostring(GainNum))
				set_text(5,256,"-"..tostring(GainNum))

			else
				set_text(1,256,tostring(msg[6]))
				set_text(2,256,tostring(msg[6]))
				set_text(4,256,tostring(msg[6]))
				set_text(5,256,tostring(msg[6]))

			end
		end 
-- 257值
		if msg[5] == 0x65 then
			local new_257_val = msg[6]
			-- 步骤1：计算真实257值
			if new_257_val > 0XF0 then 
				GainNum = 0x100 - new_257_val
				new_257_val = -GainNum  
			end
			-- 步骤2：更新UI显示
			set_text(1,257,tostring(new_257_val))
			set_text(2,257,tostring(new_257_val))
			set_text(4,257,tostring(new_257_val))
			set_text(5,257,tostring(new_257_val))
			-- 步骤3：同步current_cmd_value
			current_cmd_value = check_cmd_value_range(new_257_val)
			print("串口3更新257值：" .. new_257_val .. " → 同步指令索引：" .. current_cmd_value)
			-- 步骤4：从cmd_map匹配指令并下发
			--local cmd_group =
			global_cmd_group = cmd_map[current_cmd_value]
			--end
		end 
if msg[5] == 0x66 then
			if  msg[6] > 0XF0 then 
				GainNum = 0x100-msg[6]
				set_text(1,258,"-"..tostring(GainNum))
				set_text(2,258,"-"..tostring(GainNum))
				set_text(4,258,"-"..tostring(GainNum))
				set_text(5,258,"-"..tostring(GainNum))

			else
				set_text(1,258,tostring(msg[6]))
				set_text(2,258,tostring(msg[6]))
				set_text(4,258,tostring(msg[6]))
				set_text(5,258,tostring(msg[6]))

			end
		end 
if msg[5] == 0x67 then
			if  msg[6] > 0XF0 then 
				GainNum = 0x100-msg[6]
				set_text(1,259,"-"..tostring(GainNum))
				set_text(2,259,"-"..tostring(GainNum))
				set_text(4,259,"-"..tostring(GainNum))
				set_text(5,259,"-"..tostring(GainNum))

			else
				set_text(1,259,tostring(msg[6]))
				set_text(2,259,tostring(msg[6]))
				set_text(4,259,tostring(msg[6]))
				set_text(5,259,tostring(msg[6]))

			end
		end
	end
	end
	end
	end
	end
	
	--uart_send_data3(msg)  --      
end



-- 系统函数: 串口接收函数
function on_uart_recv_data3(packet)

	local recv_packet_size = (#(packet))
	local check16          = 0
	
	for i = 0, recv_packet_size 
	do
		if packet[i] == 0xEE and cmd_head_tag == 0
		then
			cmd_head_tag = 1
		end
		
		if packet[i] == 0xB1 and cmd_head_tag == 1
		then
			cmd_head_tag = 2
		end
		
		if cmd_head_tag == 2
		then
			buff[cmd_length] = packet[i]  -- 注意这样写数组传递是少了第 1 BYTE的
			cmd_length = cmd_length + 1
			
			if cmd_length == 2
			then 
				data_length = packet[i]
			end
			
			if 11 <= cmd_length and  cmd_length >= 2
			then
				
				my_processmessage(buff)
                
				buff         = {}
				cmd_length   = 0
				data_length  = 0
				cmd_head_tag = 0
			end
		end
	end
end
-- 辅助函数：判断table是否包含指定元素
function table.contains(tbl, elem)
    for _, v in ipairs(tbl) do
        if v == elem then
            return true
        end
    end
    return false
end