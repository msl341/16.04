#include "st_main_uvc_host.h"
#include "st_common.h"
#include "mi_jpd.h"
#include "mi_vdec.h"
#include "mi_scl.h"
#include "mi_disp.h"
#include "mi_hdmi.h"
#include "mi_sys.h"
#include "mi_sys_datatype.h"
#include "mi_panel_datatype.h"
#include "mi_panel.h"
#include "mi_venc.h"
#include "mi_venc_datatype.h"
#include "st_fb.c"
#include <string>
#include "liveMedia.hh"
#include "Live555RTSPServer.hh"
#include "mi_ao.h"
#include "mi_ao_datatype.h"
#include "mi_ai.h"
#include "mi_ai_datatype.h"
#include "mi_isp.h"
#include "mi_isp_datatype.h"
#include "mi_isp_iq.h"
#include "mi_isp_iq_datatype.h"
#include "mi_isp_cus3a_api.h"
#include "st_rgn.h"
#include "mi_rgn.h"

#include "isp_cus3a_if.h"
#include "mi_iqserver.h"



#include "mi_wlan.h"
#include <sys/poll.h>
#include <sys/prctl.h>
#include "kjd_uvc_host.h"
#include <mutex>
#include <sys/vfs.h>






#include "st_main_uvc_host.h"
#include "st_common.h"
#include "mi_jpd.h"
#include "mi_scl.h"
#include "mi_disp.h"
#include "mi_sys.h"
#include "mi_sys_datatype.h"
#include "mi_panel_datatype.h"
#include "mi_panel.h"
#include "mi_hdmi.h"
#include "rjt.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>



#include "kjd_uvc_host.h"








#define JPD_DEV_ID 0
#define JPD_CHN_ID 0
#define JPD_PORT_ID 0

#define VDEC_DEV_ID 0
#define VDEC_CHN_ID 0
#define VDEC_PORT_ID 0

#define SCL_DEV_ID 1
#define SCL_CHN_ID 0
#define SCL_PORT_ID 0

#define DISP_DEV_ID 0
#define DISP_CHN_ID 0
#define DISP_PORT_ID 0
#define DISP_LAYER_ID 0



#define GPIO_PANEL_BL		136//PAD_GPIO8                           已校骿
#define GPIO_PANEL_BL_ADJ		138//PAD_GPIO10                      已校骿
#define GPIO_PANEL_RST       130

#define GPIO_MIPIOUT_SEL	147//PAD_SD1_GPIO1  //L:MIPI	H:9022A HDMI

#define GPIO_IN_HIGH 	1
#define GPIO_IN_LOW 	0

#define DISP_WIDTH      1280
#define DISP_HEIGHT     800

#define SCL_SMALL_WIDTH  380
#define SCL_SMALL_HEIGHT  240 

#define RTSP_LISTEN_PORT        554

#define SARADC_IOC_MAGIC               'a'
#define MS_SAR_SET_CHANNEL_READ_VALUE  _IO(SARADC_IOC_MAGIC, 1)
#define MS_SAR_INIT   _IO(SARADC_IOC_MAGIC, 0)

#define     AUDIO_INPUT_SAMPRATE        48000
#define     AUDIO_INPUT_CHLAYOUT        AV_CH_LAYOUT_MONO
#define     AUDIO_INPUT_SAMPFMT         AV_SAMPLE_FMT_S16

#define     AUDIO_OUTPUT_SAMPRATE       E_MI_AUDIO_SAMPLE_RATE_48000
#define     AUDIO_OUTPUT_CHLAYOUT       E_MI_AUDIO_SOUND_MODE_MONO
#define     AUDIO_OUTPUT_SAMPFMT        E_MI_AUDIO_BIT_WIDTH_16
#define MI_AUDIO_SAMPLE_PER_FRAME 4096


#define     MI_AUDIO_MAX_DATA_SIZE      25000
#define AUDIO_DEV   0
#define     SUCCESS     0
#define     FAIL        1

#define USER_BUF_DEPTH      (20)
#define TOTAL_BUF_DEPTH		(20)



#define MAX_CHN_NEED_OSD        4

class CanvasScopeLock
{
    public:
        explicit CanvasScopeLock()
        {
            pthread_mutex_lock(&_gstCanvasMutex);
        }
        ~CanvasScopeLock()
        {
            pthread_mutex_unlock(&_gstCanvasMutex);
        }
        static void CanvasLock()
        {
            pthread_mutex_lock(&_gstCanvasMutex);
        }
        static void CanvasUnlock()
        {
            pthread_mutex_unlock(&_gstCanvasMutex);
        }
    private:
        static pthread_mutex_t _gstCanvasMutex;
};
pthread_mutex_t CanvasScopeLock::_gstCanvasMutex = PTHREAD_MUTEX_INITIALIZER;

#define CANVAS_LOCK CanvasScopeLock::CanvasLock()
#define CANVAS_UNLOCK CanvasScopeLock::CanvasUnlock()
#define RGN_OSD_TIME_WIDTH        3600
#define RGN_OSD_TIME_HEIGHT        720
#define RGN_OSD_HANDLE                    0



typedef struct AVPacketQueue {
    AVPacketList *pkt;
    AVPacketList *next_pkt;
    int nb_packets;
    int abort_request;
    int size;
    pthread_mutex_t mutex;
    pthread_cond_t  cond;
}AVPacketQueue;


typedef struct AVPlayer {
    AVFormatContext *format_ctx;
    AVCodecContext *v_codec_ctx;
    AVCodecContext *a_codec_ctx;
    AVPacketQueue v_pkt_queue;
    AVPacketQueue a_pkt_queue;
    int video_stream_idx;
    int audio_stream_idx;
    double audio_clock;
    double audio_pts;
    double video_clock;
    double video_pts;
}AVPlayer;



typedef struct 
{
    int channel_value;  ////0~3
    int adc_value;  ///读取到的值
}ADC_CONFIG_READ_ADC;


typedef struct
{
    WLAN_HANDLE *pHandle;
    MI_WLAN_ConnectParam_t *pConnParam;
} WlanConnectInfo_t;

typedef struct KJD_VencAttr_s
{
    MI_VENC_CHN vencChn;
    MI_VENC_ModType_e eType;
    MI_U32    u32Width;
    MI_U32     u32Height;
    MI_U32     u32Fps;
    char *szStreamName;
    MI_BOOL bUsed;
    MI_BOOL bCreate;
    MI_VENC_DEV DevId;

    MI_S32 s32DumpBuffNum;
    char FilePath[128];
    MI_U8 u8MD5ExpectValue[16];
    MI_BOOL bNeedCheckMd5;
}KJD_VencAttr_t;

typedef struct
{
    pthread_t pt;
    MI_VDEC_CHN vdecChn;
    char szFileName[64];
    MI_BOOL bEsAddHead;
    MI_BOOL bRunFlag;
} VDEC_Thread_Args_t;

typedef struct
{
    int startcodeprefix_len;
    unsigned int len;
    unsigned int max_size;
    char *buf;
    unsigned short lost_packets;
} NALU_t;

typedef struct AiChnPriv_s
{
    MI_AUDIO_DEV AiDevId;
    MI_AI_CHN AiChn;
    MI_S32 s32Fd;
    MI_U32 u32TotalSize;
    MI_U32 u32ChnCnt;
    pthread_t tid;
} AiChnPriv_t;

typedef struct
{
    pthread_t pt;
    MI_BOOL bRun;

    ST_OSD_INFO_S stOsdInfo[MAX_CHN_NEED_OSD][MAX_OSD_NUM_PER_CHN];
} ST_RGN_Osd_T;


//电压检测
typedef struct SAdc_Config_Read_Adc_T_
{
    int channel_value;
    int adc_value;
} SAdc_Config_Read_Adc_T;




/* global variable */
static unsigned int g_device_index = 0;
static unsigned int g_buf_cnt = 3;
static int g_run_mode = STREAM_MODE;
static bool g_stream = false;
static bool g_rtsp = false;
static bool g_auto_onoff = false;
static bool g_exit = false;
static bool fp_g_exit = true;

static bool video_pth_g_exit = false;
static bool audio_pth_g_exit = false;


static bool video_pause = false;
static bool b_exit = false;
static bool mp4_exit = false;

MI_U16 u16OutWidth, u16OutHeight;
MI_U16 u16SrcWidth, u16SrcHeight;
static AVPlayer *mmplayer_static = NULL;
static pthread_t audio_tid;
static pthread_t video_tid;
static pthread_t av_tid;

static pthread_t video_mp4_tid = NULL;
static pthread_t audio_mp4_tid = NULL;




static pthread_t stream_tid;
static pthread_t fp_tid;

static pthread_t proc_comp;

static pthread_t close_mem;
static int scl3_width = 0;
static int scl3_height = 0;
static bool video_flag = true;
static bool sd_flag = false;	

static Device_Handle_t *pvideo_dev=NULL;
	
static MI_U32 panel_width = 0;
static MI_U32 panel_height = 0;
	
	
bool usb_open_flag = true;
bool old_usb_open_flag = true;

static VDEC_Thread_Args_t g_stVdecThreadArgs;
static FILE *g_pStreamFile[32] = {NULL};
static MI_BOOL g_PushEsExit = FALSE;
static char change_proportion_flag = 1;




static AiChnPriv_t stAiChnPriv;
static MI_BOOL  bAiExit = FALSE;
static ST_RGN_Osd_T g_stRgnOsd;




int g_i_Usb_bright = 8;


unsigned char g_i_TakePhoto = 0;
unsigned char g_i_RecordVideo = 0;
unsigned char g_i_Display = 0;
char g_szFileName[64];
FILE* g_Fd = NULL;

unsigned char g_i_MainCam = 0;
unsigned char g_i_UsbCam = 0;
unsigned char g_i_MipiCam = 0;

unsigned long g_i_PhotoFileIndex = 0x7FFFFFFF;
unsigned char g_i_Read_PhotoFileIndex_Flag = 0;
 
unsigned char g_i_MainViewFlag = 0;
unsigned char g_i_MainSclDispFlag = 0;

unsigned char g_i_InitUsbFlag = 0;
unsigned char g_i_InitMipiFlag = 0;


unsigned char g_i_Check_Vol_Flag = 0;



//电压检测驱动文件句柄
int g_i_Vol_Fd = -1;

//电压值
float g_f_Vol = 0.0;


SEND_MSG_TO_UI funSendMsgToUi;

unsigned char iFirstStart = 0;

int iChangeSen = 0;

static void *framebuffer = NULL;
static Live555RTSPServer *g_pRTSPServer = NULL;



static WLAN_HANDLE g_wlanHdl = 1;
static pthread_t g_ptConn = NULL;
static MI_WLAN_OpenParams_t g_stOpenParam = {E_MI_WLAN_NETWORKTYPE_INFRA};
static MI_WLAN_InitParams_t g_stParam = {"/customer/wifi/wlan.json"};
// 连接热点信息, 可替换为其它指定的热点，如:ssid为"EnglishName"，密码为"12345678"
static MI_WLAN_ConnectParam_t g_stConnectParam[] = {
    {
        E_MI_WLAN_SECURITY_WPA,
        "vivo U3",
        "chenyu123",
        5000
    },
    {
        E_MI_WLAN_SECURITY_WPA,
        "test",
        "12345678",
        5000
    }
};




MI_S32 St_DispModuleDeinit(Device_Handle_t *video_dev);
MI_S32 St_SclModuleDeinit(Device_Handle_t *video_dev);





//基于Linux Framebuff实现
void drawRect_rgb32_my(int x0, int y0, int width, int height, int color, struct fb_var_screeninfo *fb_vinfo, struct fb_fix_screeninfo *fb_finfo, char *fb)
{
    const int bytesPerPixel = 4;
    const int stride = fb_finfo->line_length / bytesPerPixel;

    int *dest = (int *) (fb)
        + (y0 + fb_vinfo->yoffset) * stride + (x0 + fb_vinfo->xoffset);

    int x, y;
    for (y = 0; y < height; ++y)
    {
        for (x = 0; x < width; ++x)
        {
            dest[x] = color;
        }
        dest += stride;
    }
}



int video_init(Device_Handle_t *video_dev)
{
    int fd;
    int err;
    int flags = O_RDWR | O_NONBLOCK;

    struct v4l2_capability cap;

    fd = open(video_dev->path, flags, 0);
    if(fd < 0)
    {
        UVC_ERR(video_dev, "Cannot open video device: %s.\n", strerror(errno));
        return -errno;
    }

    if(ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0)
    {
        UVC_ERR(video_dev, "ioctl(VIDIOC_QUERYCAP): %s.\n", strerror(errno));
        err = -errno;
        goto fail;
    }

    if(!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE))
    {
        UVC_ERR(video_dev, "Not a video capture device.\n");
        err = -ENODEV;
        goto fail;
    }

    if(!(cap.capabilities & V4L2_CAP_STREAMING))
    {
        UVC_ERR(video_dev, "The device does not support the streaming I/O method.\n");
        err = -ENOSYS;
        goto fail;
    }

    video_dev->fd = fd;

    return 0;

fail:
    close(fd);
    return err;
}


int video_deinit(Device_Handle_t *video_dev)
{
    close(video_dev->fd);
    return 0;
}

static char* format_fcc_to_str(int pixelformat)
{
    switch(pixelformat)
    {
        case V4L2_PIX_FMT_YUYV:
            return "YUYV";
        case V4L2_PIX_FMT_NV12:
            return "NV12";
        case V4L2_PIX_FMT_MJPEG:
            return "MJPEG";
        case V4L2_PIX_FMT_H264:
            return "H264";
        case V4L2_PIX_FMT_H265:
            return "H265";
        default:
            return "Not Known!";
    }
}

int video_enum_format(Device_Handle_t *video_dev , char proportion_flag)
{
    int index = 0, select;
    Stream_Info_t info[MAX_FMT_SUPPORT];
	int choose = -1;
	int max_width = 0;
	int max_height = 0;

    struct v4l2_fmtdesc fmt = {};
    struct v4l2_frmsizeenum frmsize = {};
    struct v4l2_frmivalenum framival = {};

    for(int i = 0; ; i++)
    {
        fmt.index = i;
        fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

        if(ioctl(video_dev->fd, VIDIOC_ENUM_FMT, &fmt) < 0)
            break;

#if 0
        /* h265 can not identify by some host, but still can get buffer */
        if(strcmp(format_fcc_to_str(fmt.pixelformat), "Not Known!") == 0)
            continue;
#endif

        for(int j = 0; ; j++)
        {
            frmsize.index = j;
            frmsize.pixel_format = fmt.pixelformat;

            if(ioctl(video_dev->fd, VIDIOC_ENUM_FRAMESIZES, &frmsize) < 0)
                break;

            /* don't enum frameinterval, use default value */
            for(int k = 0; ; k++)
            {
                framival.index = k;
                framival.pixel_format = fmt.pixelformat;
                framival.width = frmsize.discrete.width;
                framival.height = frmsize.discrete.height;

                if(ioctl(video_dev->fd, VIDIOC_ENUM_FRAMEINTERVALS, &framival) < 0)
                    break;

                info[index].pixelformat = frmsize.pixel_format;
                info[index].width = frmsize.discrete.width;
                info[index].height = frmsize.discrete.height;
                info[index].frame_rate = framival.discrete.denominator;
                index++;
            }
        }
    }

    if(index == 0)
    {
        UVC_ERR(video_dev, "Cannot enum video format.\n");
        goto fail;
    }

    printf("====================Support These Formats====================\n");

    for(int i = 0; i < index; i++)
    {
        printf("[%d]    Format: %s    Resolution: %d x %d    Fps: %d\n",
                i,
                format_fcc_to_str(info[i].pixelformat),
                info[i].width,
                info[i].height,
                info[i].frame_rate);
		if(format_fcc_to_str(info[i].pixelformat) == "MJPEG" )
		{
			if(proportion_flag == 1)// 16:9
			{
				if(info[i].width > max_width)
				{
					max_width = info[i].width;
					choose = i;
				}
			}
			else if(proportion_flag == 2)// 4:3
			{
				if(info[i].width > max_width && info[i].width * 3 == info[i].height * 4 )
				{
					max_width = info[i].width;
					choose = i;
				}
			}
			else if(proportion_flag == 3)// 1:1
			{
				if(info[i].width > max_width && info[i].width == info[i].height )
				{
					max_width = info[i].width;
					choose = i;
				}
			}
			else
			{
				if(info[i].width > max_width)
				{
					max_width = info[i].width;
					choose = i;
				}
			}
		}
    }

	if(choose == -1)
	{
		for(int i = 0; i < index; i++)
	    {
	        printf("[%d]    Format: %s    Resolution: %d x %d    Fps: %d\n",
	                i,
	                format_fcc_to_str(info[i].pixelformat),
	                info[i].width,
	                info[i].height,
	                info[i].frame_rate);
			if(format_fcc_to_str(info[i].pixelformat) == "MJPEG" )
			{

				if(info[i].width > max_width)
				{
					max_width = info[i].width;
					choose = i;
				}
			}
	    }
	}

	scl3_height = info[choose].width;
	scl3_width = info[choose].height;

	if(scl3_width < 800)
	{
		scl3_width = 1280;
		scl3_height = 800;
	}

	if(scl3_width > 1280 && scl3_height > 800 )
	{
		scl3_width = 1280;
		scl3_height = 800;
	}


	if(info[choose].width  > info[choose].height )
	{
		panel_width = info[choose].height;
		panel_height = panel_width;
	}
	else
	{
		panel_width = info[choose].width;
		panel_height = panel_width;
	}


    do {
        //scanf("%d", &select);
        select = choose;
        if(select >= index)
            UVC_ERR(video_dev, "Invalid choice.\n");
    } while(select >= index);

    video_dev->pixelformat = info[select].pixelformat;
    video_dev->width = info[select].width;
    video_dev->height = info[select].height;
    video_dev->frame_rate = info[select].frame_rate;

    return 0;

fail:
    close(video_dev->fd);
    return -1;
}

int video_set_format(Device_Handle_t *video_dev)
{
    int err;

    struct v4l2_format fmt = {};
    fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width = video_dev->width;
    fmt.fmt.pix.height = video_dev->height;
    fmt.fmt.pix.pixelformat = video_dev->pixelformat;
    fmt.fmt.pix.field = V4L2_FIELD_ANY;

    if(ioctl(video_dev->fd, VIDIOC_S_FMT, &fmt) < 0)
    {
        UVC_ERR(video_dev, "ioctl(VIDIOC_S_FMT): %s.\n", strerror(errno));
        err = -errno;
		close(video_dev->fd);
    	return err;
    }

    struct v4l2_streamparm param = {};
    param.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    param.parm.capture.timeperframe.numerator = 1;
    param.parm.capture.timeperframe.denominator = video_dev->frame_rate;

    if(ioctl(video_dev->fd, VIDIOC_S_PARM, &param) < 0)
    {
        UVC_ERR(video_dev, "ioctl(VIDIOC_S_PARM): %s.\n", strerror(errno));
        err = -errno;
		close(video_dev->fd);
    	return err;
    }

    video_dev->width = fmt.fmt.pix.width;
    video_dev->height = fmt.fmt.pix.height;
    video_dev->pixelformat = fmt.fmt.pix.pixelformat;
#if 0
    /* can't get update fps currently, don't know why */
    video_dev->frame_rate = param.parm.capture.timeperframe.denominator;
#endif

    switch(video_dev->pixelformat)
    {
        case V4L2_PIX_FMT_YUYV:
            video_dev->frame_size = video_dev->width * video_dev->height * 2.0;
            break;
        case V4L2_PIX_FMT_NV12:
            video_dev->frame_size = video_dev->width * video_dev->height * 1.5;
            break;
        case V4L2_PIX_FMT_MJPEG:
            video_dev->frame_size = video_dev->width * video_dev->height * 2.0 / 4;
            break;
        case V4L2_PIX_FMT_H264:
            video_dev->frame_size = video_dev->width * video_dev->height * 2.0 / 7;
            break;
        case V4L2_PIX_FMT_H265:
            video_dev->frame_size = video_dev->width * video_dev->height * 2.0 / 8;
            break;
    }

    printf("Format: %s    Resolution: %d x %d    Fps: %d    Expect Frame Size: %d\n",
        format_fcc_to_str(video_dev->pixelformat), video_dev->width, video_dev->height, video_dev->frame_rate, video_dev->frame_size);

    return 0;
}

int video_streamon(Device_Handle_t *video_dev, unsigned int buf_cnt)
{
    int err;

    struct v4l2_requestbuffers req = {};
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.count = buf_cnt;
    req.memory = V4L2_MEMORY_MMAP;

    if(ioctl(video_dev->fd, VIDIOC_REQBUFS, &req) < 0)
    {
        UVC_ERR(video_dev, "ioctl(VIDIOC_REQBUFS): %s.\n", strerror(errno));
        err = -errno;
        goto fail;
    }

    if(req.count < 2)
    {
        UVC_ERR(video_dev, "Insufficient buffer memory.\n");
        err = -ENOMEM;
        goto fail;
    }

    video_dev->buf_cnt = req.count;

    for(int i = 0; i < video_dev->buf_cnt; i++)
    {
        struct v4l2_buffer buf = {};
        buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buf.index = i;
        buf.memory = V4L2_MEMORY_MMAP;

        if(ioctl(video_dev->fd, VIDIOC_QUERYBUF, &buf) < 0)
        {
            UVC_ERR(video_dev, "ioctl(VIDIOC_QUERYBUF): %s.\n", strerror(errno));
            err = -errno;
            goto fail;
        }

        video_dev->buf_len[i] = buf.length;
        if(video_dev->frame_size > 0 && video_dev->buf_len[i] < video_dev->frame_size)
        {
            UVC_ERR(video_dev, "buf_len[%d] = %d < expected frame size %d.\n",
                    i, video_dev->buf_len[i], video_dev->frame_size);
            err = -ENOMEM;
            goto fail;
        }

        video_dev->buf_start[i] = mmap(NULL, buf.length,
                                    PROT_READ | PROT_WRITE, MAP_SHARED,
                                    video_dev->fd, buf.m.offset);
        if(video_dev->buf_start[i] == MAP_FAILED)
        {
            UVC_ERR(video_dev, "mmap: %s.\n", strerror(errno));
            err = -errno;
            goto fail;
        }

        UVC_INFO(video_dev, "mmap: index%d start0x%p.\n", i, video_dev->buf_start[i]);

        if(ioctl(video_dev->fd, VIDIOC_QBUF, &buf) < 0)
        {
            UVC_ERR(video_dev, "ioctl(VIDIOC_QBUF): %s.\n", strerror(errno));
            err = -errno;
            goto fail;
        }
    }

    enum v4l2_buf_type type;
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    if(ioctl(video_dev->fd, VIDIOC_STREAMON, &type) < 0)
    {
        UVC_ERR(video_dev, "ioctl(VIDIOC_STREAMON): %s.\n", strerror(errno));
        err = -errno;
        goto fail;
    }


    return 0;

fail:
    close(video_dev->fd);
    return err;
}

int video_streamoff(Device_Handle_t *video_dev)
{
    enum v4l2_buf_type type;
    type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

	for(int i = 0; i < video_dev->buf_cnt; i++)
        munmap(video_dev->buf_start[i], video_dev->buf_len[i]);

    if(ioctl(video_dev->fd, VIDIOC_STREAMOFF, &type) < 0)
        UVC_ERR(video_dev, "ioctl(VIDIOC_STREAMOFF): %s.\n", strerror(errno));



    return 0;
}

int video_get_buf(Device_Handle_t *video_dev, Stream_Buffer_t *video_buf)
{
    int err;

    struct v4l2_buffer buf = {};
    buf.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    buf.memory = V4L2_MEMORY_MMAP;

    err = ioctl(video_dev->fd, VIDIOC_DQBUF, &buf);
    if(err < 0)
    {
        if(errno != EAGAIN)
            UVC_ERR(video_dev, "ioctl(VIDIOC_DQBUF): %s.\n", strerror(errno));
		//printf("video_get_buf fail 786 \n");
        return -errno;
    }

    if(buf.index >= video_dev->buf_cnt)
    {
        UVC_ERR(video_dev, "Invalid buffer index received.\n");
        err = -EAGAIN;
		printf("video_get_buf fail 794 \n");
        goto fail;
    }

    if(buf.flags & V4L2_BUF_FLAG_ERROR)
    {
        UVC_ERR(video_dev, "Dequeued v4l2 buffer contains corrupted data (%d bytes).\n", buf.bytesused);
        err = -EAGAIN;
		printf("video_get_buf fail 802 \n");
        goto fail;
    }

    if(!buf.bytesused || (video_dev->frame_size > 0 && buf.bytesused > video_dev->frame_size))
    {
        UVC_ERR(video_dev, "Dequeued v4l2 buffer contains %d bytes, but %d were expected. Flags: 0x%08X.\n",
                    buf.bytesused, video_dev->frame_size, buf.flags);
        err = -EAGAIN;
		printf("video_get_buf fail 811 \n");
        goto fail;
    }

    /* copy to user buffer */
    video_buf->length = buf.bytesused;
    video_buf->buf = calloc(1, buf.bytesused);
    if(!video_buf->buf)
    {
        UVC_ERR(video_dev, "Error allocating a packet.\n");
        err = -ENOMEM;
        goto fail;
    }

    memcpy(video_buf->buf, video_dev->buf_start[buf.index], buf.bytesused);

    if(ioctl(video_dev->fd, VIDIOC_QBUF, &buf) < 0)
    {
        UVC_ERR(video_dev, "ioctl(VIDIOC_QBUF): %s.\n", strerror(errno));
        video_put_buf(video_dev, video_buf);
		printf("video_get_buf fail 831 \n");
        return -errno;
    }

    return 0;

fail:
    if(ioctl(video_dev->fd, VIDIOC_QBUF, &buf) < 0)
    {
        UVC_ERR(video_dev, "ioctl(VIDIOC_QBUF): %s.\n", strerror(errno));
        err = -errno;
    }

    return err;
}

int video_put_buf(Device_Handle_t *video_dev, Stream_Buffer_t *video_buf)
{
    video_buf->length = 0;
    if(video_buf->buf)
        free(video_buf->buf);

    return 0;
}

int video_enum_standard_control(Device_Handle_t *video_dev)
{
    struct v4l2_queryctrl ctrl = {};

    printf("====================Support These Controls====================\n");

    for(int i = V4L2_CID_BASE; i < V4L2_CID_LASTP1; i++)
    {
        ctrl.id = i;

        if(ioctl(video_dev->fd, VIDIOC_QUERYCTRL, &ctrl) < 0)
            continue;

        printf("Id: %d    Type: %d    Name: %s    Minimum: %d    Maximum: %d    Step: %d    Default Value: %d    flags: %d\n",
            ctrl.id, ctrl.type, ctrl.name, ctrl.minimum, ctrl.maximum, ctrl.step, ctrl.default_value, ctrl.flags);
    }

    return 0;
}

int video_send_standard_control(Device_Handle_t *video_dev, unsigned int id, int *value, int dir)
{
    struct v4l2_control ctrl = {};
    ctrl.id = id;

    switch(dir)
    {
        case CONTROL_GET:
            if(ioctl(video_dev->fd, VIDIOC_G_CTRL, &ctrl) < 0)
            {
                UVC_ERR(video_dev, "ioctl(VIDIOC_G_CTRL): %s.\n", strerror(errno));
                return -errno;
            }
            *value = ctrl.value;
            break;

        case CONTROL_SET:
            ctrl.value = *value;
            if(ioctl(video_dev->fd, VIDIOC_S_CTRL, &ctrl) < 0)
            {
                UVC_ERR(video_dev, "ioctl(VIDIOC_S_CTRL): %s.\n", strerror(errno));
                return -errno;
            }
            break;

        default:
            UVC_ERR(video_dev, "Unknown direction.\n");
            return -1;
    }

    return 0;
}

int video_send_standard_control_qw(unsigned int id, int *value, int dir)
{
//	printf("video send fd = %d\n",pvideo_dev->fd);

	return video_send_standard_control(pvideo_dev, id, value, dir);
}


int video_send_extension_control(Device_Handle_t *video_dev,
                    unsigned int unit,
                    unsigned int selector,
                    unsigned int query,
                    unsigned int size,
                    void *data)
{
    struct uvc_xu_control_query ctrl = {};
    ctrl.unit = unit;
    ctrl.selector = selector;
    ctrl.query = query;
    ctrl.size = size;
    ctrl.data = (__u8*)data;

    if(ioctl(video_dev->fd, UVCIOC_CTRL_QUERY, &ctrl) < 0)
    {
        UVC_ERR(video_dev, "ioctl(UVCIOC_CTRL_QUERY): %s.\n", strerror(errno));
        return -errno;
    }

    return 0;
}

int video_dump_buf(Device_Handle_t *video_dev, Stream_Buffer_t *video_buf, char *path, int type)
{
    int fd;

    switch(type)
    {
        case DUMP_PICTURE:
            fd = open(path, O_TRUNC | O_RDWR | O_CREAT, 0777);
            if(fd < 0)
            {
                UVC_ERR(video_dev, "open %s: %s.\n", path, strerror(errno));
                goto fail;
            }

            if(write(fd, video_buf->buf, video_buf->length) != video_buf->length)
                UVC_ERR(video_dev, "write %s: %s.\n", path, strerror(errno));

            close(fd);
            break;

        case DUMP_STREAM:
            fd = open(path, O_APPEND | O_RDWR | O_CREAT, 0777);
            if(fd < 0)
            {
                UVC_ERR(video_dev, "open %s: %s.\n", path, strerror(errno));
                goto fail;
            }

            if(write(fd, video_buf->buf, video_buf->length) != video_buf->length)
                UVC_ERR(video_dev, "write %s: %s.\n", path, strerror(errno));

            close(fd);
            break;

        default:
            UVC_ERR(video_dev, "Unknown dump type.\n");
            goto fail;
    }

    return 0;

fail:
    return -1;
}


/*static MI_S32 St_SclModuleInit(Device_Handle_t *video_dev)
{
	MI_U32 SCL_DEV_ID_1 = 1;
	MI_U32 SCL_CHN_ID_1 = 0;
	MI_U32 SCL_PORT_ID_1 = 1;


    MI_SYS_ChnPort_t stSysChnPort;
    MI_SCL_DevAttr_t stSclDevAttr;
    MI_SCL_ChannelAttr_t stSclChnAttr;
    MI_SCL_ChnParam_t stSclChnParam;
    MI_SCL_OutPortParam_t stSclOutputParam;

    memset(&stSysChnPort, 0x0, sizeof(stSysChnPort));
    memset(&stSclDevAttr, 0x0, sizeof(MI_SCL_DevAttr_t));
    memset(&stSclChnAttr, 0x0, sizeof(MI_SCL_ChannelAttr_t));
    memset(&stSclChnParam, 0x0, sizeof(MI_SCL_ChnParam_t));
    memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));

	if(usb_open_flag == false )
	{
		video_dev->width = 480;
		video_dev->height = 480;
	}



    stSclDevAttr.u32NeedUseHWOutPortMask = E_MI_SCL_HWSCL0 | E_MI_SCL_HWSCL1;
    stSclOutputParam.stSCLOutCropRect.u16X = 0;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
    stSclOutputParam.stSCLOutCropRect.u16Width = 0;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
    stSclOutputParam.stSCLOutputSize.u16Width = 480;//video_dev->width;
    stSclOutputParam.stSCLOutputSize.u16Height = 480;//video_dev->height;
    stSclOutputParam.bMirror = false;
    stSclOutputParam.bFlip = false;
    stSclOutputParam.eCompressMode= E_MI_SYS_COMPRESS_MODE_NONE;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;

    ExecFunc(MI_SCL_CreateDevice(SCL_DEV_ID_1, &stSclDevAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_CreateChannel(SCL_DEV_ID_1, SCL_CHN_ID_1, &stSclChnAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_SetChnParam(SCL_DEV_ID_1, SCL_CHN_ID_1, &stSclChnParam), MI_SUCCESS);
    ExecFunc(MI_SCL_StartChannel(SCL_DEV_ID_1, SCL_CHN_ID_1), MI_SUCCESS);
    ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID_1, SCL_CHN_ID_1, SCL_PORT_ID_1, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID_1, SCL_CHN_ID_1, SCL_PORT_ID_1), MI_SUCCESS);

	memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
	stSclOutputParam.stSCLOutCropRect.u16X = 0;//(video_dev->width - panel_width)/2;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;//(video_dev->height - panel_height)/2;
	stSclOutputParam.stSCLOutCropRect.u16Width = 0;//panel_width;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;//panel_width;
    stSclOutputParam.stSCLOutputSize.u16Width = 480;
    stSclOutputParam.stSCLOutputSize.u16Height = 480;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID_1, SCL_CHN_ID_1, 0, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID_1, SCL_CHN_ID_1, 0), MI_SUCCESS);

    return MI_SUCCESS;
}*/


static MI_S32 St_SclModuleInit(Device_Handle_t *video_dev)
{
    MI_SYS_ChnPort_t stSysChnPort;
    MI_SCL_DevAttr_t stSclDevAttr;
    MI_SCL_ChannelAttr_t stSclChnAttr;
    MI_SCL_ChnParam_t stSclChnParam;
    MI_SCL_OutPortParam_t stSclOutputParam;

    memset(&stSysChnPort, 0x0, sizeof(stSysChnPort));
    memset(&stSclDevAttr, 0x0, sizeof(MI_SCL_DevAttr_t));
    memset(&stSclChnAttr, 0x0, sizeof(MI_SCL_ChannelAttr_t));
    memset(&stSclChnParam, 0x0, sizeof(MI_SCL_ChnParam_t));
    memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));

	if(usb_open_flag == false )
	{
		video_dev->width = 1280;
		video_dev->height = 800;
	}

    stSysChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysChnPort.u32DevId = SCL_DEV_ID;
    stSysChnPort.u32ChnId = SCL_CHN_ID;
    stSysChnPort.u32PortId = SCL_PORT_ID;
    stSclDevAttr.u32NeedUseHWOutPortMask = E_MI_SCL_HWSCL0 | E_MI_SCL_HWSCL1 | E_MI_SCL_HWSCL2 | E_MI_SCL_HWSCL3 ;
    stSclOutputParam.stSCLOutCropRect.u16X = 0;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
    stSclOutputParam.stSCLOutCropRect.u16Width = 0;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
	

    stSclOutputParam.stSCLOutputSize.u16Width = 1280;
    stSclOutputParam.stSCLOutputSize.u16Height = 800;
	
	
    stSclOutputParam.bMirror = false;
    stSclOutputParam.bFlip = false;
    stSclOutputParam.eCompressMode= E_MI_SYS_COMPRESS_MODE_NONE;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;

    ExecFunc(MI_SCL_CreateDevice(SCL_DEV_ID, &stSclDevAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_CreateChannel(SCL_DEV_ID, SCL_CHN_ID, &stSclChnAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_SetChnParam(SCL_DEV_ID, SCL_CHN_ID, &stSclChnParam), MI_SUCCESS);
    ExecFunc(MI_SCL_StartChannel(SCL_DEV_ID, SCL_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID), MI_SUCCESS);
	



	memset(&stSysChnPort, 0x0, sizeof(stSysChnPort));
    memset(&stSclDevAttr, 0x0, sizeof(MI_SCL_DevAttr_t));
    memset(&stSclChnAttr, 0x0, sizeof(MI_SCL_ChannelAttr_t));
    memset(&stSclChnParam, 0x0, sizeof(MI_SCL_ChnParam_t));
    memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));

	panel_width = 1280;
	panel_height = 800;


	if(scl3_width == 0 )
	{
		scl3_width = panel_width;
		scl3_height = panel_height;
	}

    stSysChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysChnPort.u32DevId = 3;
    stSysChnPort.u32ChnId = SCL_CHN_ID;
    stSysChnPort.u32PortId = SCL_PORT_ID;
	stSclChnParam.eRot = E_MI_SYS_ROTATE_NONE;
    stSclDevAttr.u32NeedUseHWOutPortMask = E_MI_SCL_HWSCL5;
    stSclOutputParam.stSCLOutCropRect.u16X = 0;//80;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
    stSclOutputParam.stSCLOutCropRect.u16Width = 0;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
    stSclOutputParam.stSCLOutputSize.u16Width = SCL_SMALL_WIDTH;//panel_width;//video_dev->height;
    stSclOutputParam.stSCLOutputSize.u16Height = SCL_SMALL_HEIGHT;//panel_height;//video_dev->width;
    stSclOutputParam.bMirror = false;
    stSclOutputParam.bFlip = false;
    stSclOutputParam.eCompressMode= E_MI_SYS_COMPRESS_MODE_NONE;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;

    ExecFunc(MI_SCL_CreateDevice(3, &stSclDevAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_CreateChannel(3, SCL_CHN_ID, &stSclChnAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_SetChnParam(3, SCL_CHN_ID, &stSclChnParam), MI_SUCCESS);
    ExecFunc(MI_SCL_StartChannel(3, SCL_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_SCL_SetOutputPortParam(3, SCL_CHN_ID, SCL_PORT_ID, &stSclOutputParam), MI_SUCCESS);	
    ExecFunc(MI_SCL_EnableOutputPort(3, SCL_CHN_ID, SCL_PORT_ID), MI_SUCCESS);



	memset(&stSysChnPort, 0x0, sizeof(stSysChnPort));
    memset(&stSclDevAttr, 0x0, sizeof(MI_SCL_DevAttr_t));
    memset(&stSclChnAttr, 0x0, sizeof(MI_SCL_ChannelAttr_t));
    memset(&stSclChnParam, 0x0, sizeof(MI_SCL_ChnParam_t));
    memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));

	
	memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
	stSclOutputParam.stSCLOutCropRect.u16X = 0;//(video_dev->width - panel_width)/2;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;//(video_dev->height - panel_height)/2;
	stSclOutputParam.stSCLOutCropRect.u16Width = 0;//panel_width;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;//panel_width;
    stSclOutputParam.stSCLOutputSize.u16Width = panel_width;//video_dev->width;//480
    stSclOutputParam.stSCLOutputSize.u16Height = panel_height;//video_dev->height;//480
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, 1, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 1), MI_SUCCESS);
	memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));

	stSclOutputParam.stSCLOutCropRect.u16X = 0;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
    stSclOutputParam.stSCLOutCropRect.u16Width = 0;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
    stSclOutputParam.stSCLOutputSize.u16Width = panel_width;//video_dev->height;
    stSclOutputParam.stSCLOutputSize.u16Height = panel_height;//video_dev->width;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, 2, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 2), MI_SUCCESS);
	memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));

	stSclOutputParam.stSCLOutCropRect.u16X = 0;//80;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
    stSclOutputParam.stSCLOutCropRect.u16Width = 0;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
    stSclOutputParam.stSCLOutputSize.u16Width = panel_width;//video_dev->height;
    stSclOutputParam.stSCLOutputSize.u16Height = panel_height;//video_dev->width;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, 3, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 3), MI_SUCCESS);


    return MI_SUCCESS;
}


static MI_S32 St_SclModuleInitTest(Device_Handle_t *video_dev)
{
/*	MI_U32 SCL_DEV_ID = 1;
	MI_U32 SCL_CHN_ID = 0;
	MI_U32 SCL_PORT_ID = 1;
*/
    MI_SYS_ChnPort_t stSysChnPort;
    MI_SCL_DevAttr_t stSclDevAttr;
    MI_SCL_ChannelAttr_t stSclChnAttr;
    MI_SCL_ChnParam_t stSclChnParam;
    MI_SCL_OutPortParam_t stSclOutputParam;

    memset(&stSysChnPort, 0x0, sizeof(stSysChnPort));
    memset(&stSclDevAttr, 0x0, sizeof(MI_SCL_DevAttr_t));
    memset(&stSclChnAttr, 0x0, sizeof(MI_SCL_ChannelAttr_t));
    memset(&stSclChnParam, 0x0, sizeof(MI_SCL_ChnParam_t));
    memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));


    stSysChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysChnPort.u32DevId = SCL_DEV_ID;
    stSysChnPort.u32ChnId = SCL_CHN_ID;
    stSysChnPort.u32PortId = SCL_PORT_ID;
    stSclDevAttr.u32NeedUseHWOutPortMask = E_MI_SCL_HWSCL0 | E_MI_SCL_HWSCL1;
    stSclOutputParam.stSCLOutCropRect.u16X = 0;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
    stSclOutputParam.stSCLOutCropRect.u16Width = 0;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
    stSclOutputParam.stSCLOutputSize.u16Width = 1920;
    stSclOutputParam.stSCLOutputSize.u16Height = 1080;
    stSclOutputParam.bMirror = false;
    stSclOutputParam.bFlip = false;
    stSclOutputParam.eCompressMode= E_MI_SYS_COMPRESS_MODE_NONE;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;

    ExecFunc(MI_SCL_CreateDevice(SCL_DEV_ID, &stSclDevAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_CreateChannel(SCL_DEV_ID, SCL_CHN_ID, &stSclChnAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_SetChnParam(SCL_DEV_ID, SCL_CHN_ID, &stSclChnParam), MI_SUCCESS);
    ExecFunc(MI_SCL_StartChannel(SCL_DEV_ID, SCL_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID), MI_SUCCESS);

	memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
	panel_width = 1280;
	panel_height = 800;
	if(video_dev->width > panel_width)
	{
		stSclOutputParam.stSCLOutCropRect.u16X = (video_dev->width - panel_width)/2;
	    stSclOutputParam.stSCLOutCropRect.u16Y = (video_dev->height - panel_height)/2;
		stSclOutputParam.stSCLOutCropRect.u16Width = panel_width;
	    stSclOutputParam.stSCLOutCropRect.u16Height = panel_height;
	    stSclOutputParam.stSCLOutputSize.u16Width = panel_width;
	    stSclOutputParam.stSCLOutputSize.u16Height = panel_height;
	    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	}
	else
	{
		stSclOutputParam.stSCLOutCropRect.u16X = 0;
	    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
		stSclOutputParam.stSCLOutCropRect.u16Width = 0;
	    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
	    stSclOutputParam.stSCLOutputSize.u16Width = panel_width;
	    stSclOutputParam.stSCLOutputSize.u16Height = panel_height;
	    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	}
	printf("panel_width = %d panel_height = %d \n",panel_width,panel_height);
	ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, 0, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 0), MI_SUCCESS);

    return MI_SUCCESS;
}



static MI_S32 St_JpdModuleInit(Device_Handle_t *video_dev)
{
    MI_SYS_ChnPort_t stSysChnPort;
    MI_JPD_InitParam_t stJpdInitParam;
    MI_JPD_ChnCreatConf_t stJpdChnCreatConf;

    memset(&stSysChnPort, 0, sizeof(stSysChnPort));
    memset(&stJpdInitParam, 0, sizeof(stJpdInitParam));
    memset(&stJpdChnCreatConf, 0, sizeof(stJpdChnCreatConf));

	if(usb_open_flag == false )
	{
		video_dev->width = 1280;
		video_dev->height = 720;
	}

    stSysChnPort.eModId = E_MI_MODULE_ID_JPD;
    stSysChnPort.u32DevId = JPD_DEV_ID;
    stSysChnPort.u32ChnId = JPD_CHN_ID;
    stSysChnPort.u32PortId = JPD_PORT_ID;
    stJpdChnCreatConf.u32MaxPicWidth   = 8192;
    stJpdChnCreatConf.u32MaxPicHeight  = 8192;
    stJpdChnCreatConf.u32StreamBufSize = 2*1024*1024;

#if 0
    ExecFunc(MI_JPD_CreateDev(JPD_DEV_ID, &stJpdInitParam), MI_SUCCESS);
#endif
    ExecFunc(MI_JPD_CreateChn(JPD_DEV_ID, JPD_CHN_ID, &stJpdChnCreatConf), MI_SUCCESS);
    ExecFunc(MI_JPD_StartChn(JPD_DEV_ID, JPD_CHN_ID), MI_SUCCESS);
    //ExecFunc(MI_SYS_SetChnOutputPortDepth(0, &stSysChnPort, 4, 4), MI_SUCCESS);

    return MI_SUCCESS;
}

static MI_S32 St_VdecModuleInit(Device_Handle_t *video_dev)
{
    MI_SYS_ChnPort_t stSysChnPort;
    MI_VDEC_InitParam_t stVdecInitParam;
    MI_VDEC_ChnAttr_t stVdecChnAttr;
    MI_VDEC_OutputPortAttr_t stVdecOutputPortAttr;

    memset(&stSysChnPort, 0, sizeof(stSysChnPort));
    memset(&stVdecInitParam, 0, sizeof(stVdecInitParam));
    memset(&stVdecChnAttr, 0, sizeof(stVdecChnAttr));
    memset(&stVdecOutputPortAttr, 0, sizeof(stVdecOutputPortAttr));

	if(usb_open_flag == false)
	{
		video_dev->width = 1280;
		video_dev->height = 720;
	}

    stSysChnPort.eModId = E_MI_MODULE_ID_VDEC;
    stSysChnPort.u32DevId = VDEC_DEV_ID;
    stSysChnPort.u32ChnId = VDEC_CHN_ID;
    stSysChnPort.u32PortId = VDEC_PORT_ID;
    stVdecChnAttr.eCodecType = E_MI_VDEC_CODEC_TYPE_H264;
    stVdecChnAttr.eDpbBufMode = E_MI_VDEC_DPB_MODE_INPLACE_ONE_BUF;
    stVdecChnAttr.eVideoMode = E_MI_VDEC_VIDEO_MODE_FRAME;
    //stVdecChnAttr.stVdecVideoAttr.stErrHandlePolicy.bUseCusPolicy = false;
    stVdecChnAttr.stVdecVideoAttr.u32RefFrameNum = 1;
    stVdecChnAttr.u32BufSize = 1024*1024;
    stVdecChnAttr.u32PicHeight = 720;
    stVdecChnAttr.u32PicWidth = 1280;
    stVdecChnAttr.u32Priority = 0;
    stVdecOutputPortAttr.u16Height = 720;
    stVdecOutputPortAttr.u16Width = 1280;
    //stVdecChnAttr.stVdecVideoAttr.bDisableLowLatency = FALSE;

    //ExecFunc(MI_VDEC_CreateDev(VDEC_DEV_ID, &stVdecInitParam), MI_SUCCESS);
    ExecFunc(MI_VDEC_CreateChn(VDEC_DEV_ID, VDEC_CHN_ID, &stVdecChnAttr), MI_SUCCESS);
    //ExecFunc(MI_VDEC_SetDisplayMode(VDEC_DEV_ID, VDEC_CHN_ID, E_MI_VDEC_DISPLAY_MODE_PLAYBACK), MI_SUCCESS);
    ExecFunc(MI_VDEC_StartChn(VDEC_DEV_ID, VDEC_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_VDEC_SetOutputPortAttr(VDEC_DEV_ID, VDEC_CHN_ID, &stVdecOutputPortAttr), MI_SUCCESS);
    //ExecFunc(MI_SYS_SetChnOutputPortDepth(0, &stSysChnPort, 0, 4), MI_SUCCESS);

    return MI_SUCCESS;
}


static MI_S32 St_fastModuleInit(Device_Handle_t *video_dev)
{
	ST_Sys_BindInfo_T stSysBindInfo;
    memset(&stSysBindInfo, 0, sizeof(stSysBindInfo));


	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VDEC;
    stSysBindInfo.stSrcChnPort.u32DevId = 0;
    stSysBindInfo.stSrcChnPort.u32ChnId = 0;
    stSysBindInfo.stSrcChnPort.u32PortId = 0;
    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
    stSysBindInfo.stDstChnPort.u32DevId = 0;
    stSysBindInfo.stDstChnPort.u32ChnId = 0;
    stSysBindInfo.stDstChnPort.u32PortId = 0;
    stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
    stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
    ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);

	ExecFunc(MI_DISP_DisableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_DisableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_UnBindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_Disable(DISP_DEV_ID), MI_SUCCESS);

	ExecFunc(MI_VDEC_StopChn(VDEC_DEV_ID, VDEC_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_VDEC_DestroyChn(VDEC_DEV_ID, VDEC_CHN_ID), MI_SUCCESS);
	ExecFunc(MI_VDEC_DestroyDev(VDEC_DEV_ID), MI_SUCCESS);


	return MI_SUCCESS;
	
}



static MI_S32 St_DispModuleInitBak(Device_Handle_t *video_dev)
{
    MI_DISP_PubAttr_t stDispPubAttr;
    MI_DISP_VideoLayerAttr_t stDispLayerAttr;
    MI_DISP_InputPortAttr_t stDispInputPortAttr;

	if(usb_open_flag == false )
	{
		video_dev->width = 1280;
		video_dev->height = 720;
	}
	system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm10/duty_cycle");
	
	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
	stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 800;//768;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1280;//1024;
    stDispLayerAttr.stVidLayerDispWin.u16X = (1280-panel_width)/2;
    stDispLayerAttr.stVidLayerDispWin.u16Y = (800-panel_height)/2;
    stDispLayerAttr.stVidLayerSize.u16Height = 800;//768;
    stDispLayerAttr.stVidLayerSize.u16Width = 1280;//1024
    stDispInputPortAttr.stDispWin.u16Height = panel_height;
    stDispInputPortAttr.stDispWin.u16Width = panel_width;
    stDispInputPortAttr.stDispWin.u16X = (1280-panel_width)/2;
    stDispInputPortAttr.stDispWin.u16Y = (800-panel_height)/2;
    stDispInputPortAttr.u16SrcHeight = panel_width;
    stDispInputPortAttr.u16SrcWidth = panel_height;


    ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID,DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(DISP_LAYER_ID, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(DISP_LAYER_ID, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(DISP_LAYER_ID, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);

	//ST_InitMipiOut();
	MI_PANEL_Init(E_MI_PNL_INTF_MIPI_DSI);

	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));

    stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_1080P60;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_HDMI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 1080;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1920;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
    stDispLayerAttr.stVidLayerSize.u16Height = 1080;
    stDispLayerAttr.stVidLayerSize.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16Height = 1080;
    stDispInputPortAttr.stDispWin.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16X = 0;
    stDispInputPortAttr.stDispWin.u16Y = 0;
    stDispInputPortAttr.u16SrcHeight = video_dev->height;
    stDispInputPortAttr.u16SrcWidth = video_dev->width;

    ExecFunc(MI_DISP_SetPubAttr(1, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(1), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(2,1), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(2, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(2), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(2, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(2, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(2, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);

	system("echo 100000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm10/duty_cycle");
	
	
    return MI_SUCCESS;
}


static MI_S32 St_DispModuleInit(Device_Handle_t *video_dev)
{
    MI_DISP_PubAttr_t stDispPubAttr;
    MI_DISP_VideoLayerAttr_t stDispLayerAttr;
    MI_DISP_InputPortAttr_t stDispInputPortAttr;

	if(usb_open_flag == false )
	{
		video_dev->width = 1280;
		video_dev->height = 800;
	}
	system("echo 0 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm10/duty_cycle");
	
	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
	stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 800;//768;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1280;//1024;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
    stDispLayerAttr.stVidLayerSize.u16Height = 800;//768;
    stDispLayerAttr.stVidLayerSize.u16Width = 1280;//1024
    stDispInputPortAttr.stDispWin.u16Height = panel_height;
    stDispInputPortAttr.stDispWin.u16Width = panel_width;
    stDispInputPortAttr.stDispWin.u16X = 0;
    stDispInputPortAttr.stDispWin.u16Y = 0;
    stDispInputPortAttr.u16SrcHeight = panel_width;
    stDispInputPortAttr.u16SrcWidth = panel_height;


    ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID,DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(DISP_LAYER_ID, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(DISP_LAYER_ID, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(DISP_LAYER_ID, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);


	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
	stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = SCL_SMALL_HEIGHT;//768;
    stDispLayerAttr.stVidLayerDispWin.u16Width = SCL_SMALL_WIDTH;//1024;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
    stDispLayerAttr.stVidLayerSize.u16Height = 800;//768;
    stDispLayerAttr.stVidLayerSize.u16Width = 1280;//1024
    stDispInputPortAttr.stDispWin.u16Height = SCL_SMALL_HEIGHT;//panel_height;
    stDispInputPortAttr.stDispWin.u16Width = SCL_SMALL_WIDTH;//panel_width;
    stDispInputPortAttr.stDispWin.u16X = 50;
    stDispInputPortAttr.stDispWin.u16Y = 800 - SCL_SMALL_HEIGHT - 20;
    stDispInputPortAttr.u16SrcHeight = panel_width;
    stDispInputPortAttr.u16SrcWidth = panel_height;


    ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(1,DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(1, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(1), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(1, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(1, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(1, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);


	//ST_InitMipiOut();
	MI_PANEL_Init(E_MI_PNL_INTF_MIPI_DSI);

	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));

    stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_1080P60;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_HDMI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 1080;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1920;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
    stDispLayerAttr.stVidLayerSize.u16Height = 1080;
    stDispLayerAttr.stVidLayerSize.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16Height = 1080;
    stDispInputPortAttr.stDispWin.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16X = 0;
    stDispInputPortAttr.stDispWin.u16Y = 0;
    stDispInputPortAttr.u16SrcHeight = video_dev->height;
    stDispInputPortAttr.u16SrcWidth = video_dev->width;

    ExecFunc(MI_DISP_SetPubAttr(1, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(1), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(2,1), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(2, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(2), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(2, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(2, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(2, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);

	system("echo 100000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm10/duty_cycle");
	
	
    return MI_SUCCESS;
}

//隐藏主视频
MI_S32 St_HideLayerForMain()
{
	ExecFunc(MI_DISP_DisableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
	ExecFunc(MI_DISP_DisableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
	ExecFunc(MI_DISP_UnBindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
	return MI_SUCCESS;
}


//显示主视频
MI_S32 St_ShowLayerForMain()
{
	ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
	ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
	ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
	
	return MI_SUCCESS;
}

//隐藏小视频
MI_S32 St_HideLayerForSmall()
{
	ExecFunc(MI_DISP_DisableInputPort(1, 0), MI_SUCCESS);
	ExecFunc(MI_DISP_DisableVideoLayer(1), MI_SUCCESS);
	ExecFunc(MI_DISP_UnBindVideoLayer(1, DISP_DEV_ID), MI_SUCCESS);
	return MI_SUCCESS;
}

//显示小视频
MI_S32 St_ShowLayerForSmall()
{
	ExecFunc(MI_DISP_BindVideoLayer(1, DISP_DEV_ID), MI_SUCCESS);
	ExecFunc(MI_DISP_EnableVideoLayer(1), MI_SUCCESS);
	ExecFunc(MI_DISP_EnableInputPort(1, 0), MI_SUCCESS);
	
	return MI_SUCCESS;
}

//调整小视频的大小
MI_S32 St_ResizeLayer(unsigned char iFlag)
{
//	return MI_SUCCESS;
    //usleep(3000*1000);
    STCHECKRESULT(MI_DISP_ClearInputPortBuffer(DISP_LAYER_ID, 0, true));
    STCHECKRESULT(MI_DISP_ClearInputPortBuffer(1,0, true));
	//xz
     //usleep(3000*1000);
      printf("19191919191919191919\n");
	ExecFunc(MI_DISP_DisableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);

	// ExecFunc(MI_DISP_DisableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
	// ExecFunc(MI_DISP_UnBindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
	
	ExecFunc(MI_DISP_DisableInputPort(1, 0), MI_SUCCESS);

	// ExecFunc(MI_DISP_DisableVideoLayer(1), MI_SUCCESS);
	// ExecFunc(MI_DISP_UnBindVideoLayer(1, DISP_DEV_ID), MI_SUCCESS);

	// ExecFunc(MI_DISP_Disable(DISP_DEV_ID), MI_SUCCESS);

    if (iFlag == 0)//小视频的大小为全屏
	{		
			MI_DISP_PubAttr_t stDispPubAttr;
			MI_DISP_VideoLayerAttr_t stDispLayerAttr;
			MI_DISP_InputPortAttr_t stDispInputPortAttr;


			memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
			memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
			memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
			stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
			stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
			stDispPubAttr.u32BgColor = YUYV_BLACK;
			stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
			stDispLayerAttr.stVidLayerDispWin.u16Height = 800;//768;
			stDispLayerAttr.stVidLayerDispWin.u16Width = 1280;//1024;
			stDispLayerAttr.stVidLayerDispWin.u16X = 0;
			stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
			stDispLayerAttr.stVidLayerSize.u16Height = 800;//768;
			stDispLayerAttr.stVidLayerSize.u16Width = 1280;//1024
			stDispInputPortAttr.stDispWin.u16Height = 800;//panel_height;
			stDispInputPortAttr.stDispWin.u16Width = 1280;//panel_width;
			stDispInputPortAttr.stDispWin.u16X = 0;
			stDispInputPortAttr.stDispWin.u16Y = 0;
			stDispInputPortAttr.u16SrcHeight = 800;//panel_width;
			stDispInputPortAttr.u16SrcWidth = 1280;//panel_height;


			// ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID,DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_SetVideoLayerAttr(DISP_LAYER_ID, &stDispLayerAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);

			ExecFunc(MI_DISP_SetInputPortAttr(DISP_LAYER_ID, 0, &stDispInputPortAttr), MI_SUCCESS);
			ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
			ExecFunc(MI_DISP_SetInputPortSyncMode(DISP_LAYER_ID, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);


			memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
			memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
			memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
			stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
			stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
			stDispPubAttr.u32BgColor = YUYV_BLACK;
			stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
			stDispLayerAttr.stVidLayerDispWin.u16Height = 800;//768;
			stDispLayerAttr.stVidLayerDispWin.u16Width = 1280;//1024;
			stDispLayerAttr.stVidLayerDispWin.u16X = 0;
			stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
			stDispLayerAttr.stVidLayerSize.u16Height = 800;//768;
			stDispLayerAttr.stVidLayerSize.u16Width = 1280;//1024

			stDispInputPortAttr.stDispWin.u16Height = 800;//panel_height;
			stDispInputPortAttr.stDispWin.u16Width = 1280;//panel_width;

			stDispInputPortAttr.stDispWin.u16X = 0;
			stDispInputPortAttr.stDispWin.u16Y = 0;

			stDispInputPortAttr.u16SrcHeight = 800;//panel_width;
			stDispInputPortAttr.u16SrcWidth = 1280;//panel_height;


			// ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_BindVideoLayer(1,DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_SetVideoLayerAttr(1, &stDispLayerAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_EnableVideoLayer(1), MI_SUCCESS);

			ExecFunc(MI_DISP_SetInputPortAttr(1, 0, &stDispInputPortAttr), MI_SUCCESS);
			ExecFunc(MI_DISP_EnableInputPort(1, 0), MI_SUCCESS);
			ExecFunc(MI_DISP_SetInputPortSyncMode(1, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);	
	}
	else//小视频的大小为小屏
	{
			MI_DISP_PubAttr_t stDispPubAttr;
			MI_DISP_VideoLayerAttr_t stDispLayerAttr;
			MI_DISP_InputPortAttr_t stDispInputPortAttr;

			memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
			memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
			memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
			stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
			stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
			stDispPubAttr.u32BgColor = YUYV_BLACK;
			stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
			stDispLayerAttr.stVidLayerDispWin.u16Height = 800;//768;
			stDispLayerAttr.stVidLayerDispWin.u16Width = 1280;//1024;
			stDispLayerAttr.stVidLayerDispWin.u16X = 0;
			stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
			stDispLayerAttr.stVidLayerSize.u16Height = 800;//768;
			stDispLayerAttr.stVidLayerSize.u16Width = 1280;//1024
			stDispInputPortAttr.stDispWin.u16Height = 800;//panel_height;
			stDispInputPortAttr.stDispWin.u16Width = 1280;//panel_width;
			stDispInputPortAttr.stDispWin.u16X = 0;
			stDispInputPortAttr.stDispWin.u16Y = 0;
			stDispInputPortAttr.u16SrcHeight = 800;//panel_width;
			stDispInputPortAttr.u16SrcWidth = 1280;//panel_height;


			// ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID,DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_SetVideoLayerAttr(DISP_LAYER_ID, &stDispLayerAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);

			ExecFunc(MI_DISP_SetInputPortAttr(DISP_LAYER_ID, 0, &stDispInputPortAttr), MI_SUCCESS);
			ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
			ExecFunc(MI_DISP_SetInputPortSyncMode(DISP_LAYER_ID, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);


			memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
			memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
			memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
			stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
			stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
			stDispPubAttr.u32BgColor = YUYV_BLACK;
			stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
			stDispLayerAttr.stVidLayerDispWin.u16Height = SCL_SMALL_HEIGHT;//768;
			stDispLayerAttr.stVidLayerDispWin.u16Width = SCL_SMALL_WIDTH;//1024;
			stDispLayerAttr.stVidLayerDispWin.u16X = 0;
			stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
			stDispLayerAttr.stVidLayerSize.u16Height = SCL_SMALL_HEIGHT;//768;
			stDispLayerAttr.stVidLayerSize.u16Width = SCL_SMALL_WIDTH;//1024
			stDispInputPortAttr.stDispWin.u16Height = SCL_SMALL_HEIGHT;
			stDispInputPortAttr.stDispWin.u16Width = SCL_SMALL_WIDTH;
			stDispInputPortAttr.stDispWin.u16X = 50;
			stDispInputPortAttr.stDispWin.u16Y = 800 - SCL_SMALL_HEIGHT - 20;
			stDispInputPortAttr.u16SrcHeight = 800;//panel_width;
			stDispInputPortAttr.u16SrcWidth = 1280;//panel_height;

			// ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_BindVideoLayer(1,DISP_DEV_ID), MI_SUCCESS);
			// ExecFunc(MI_DISP_SetVideoLayerAttr(1, &stDispLayerAttr), MI_SUCCESS);
			// ExecFunc(MI_DISP_EnableVideoLayer(1), MI_SUCCESS);

			ExecFunc(MI_DISP_SetInputPortAttr(1, 0, &stDispInputPortAttr), MI_SUCCESS);
			ExecFunc(MI_DISP_EnableInputPort(1, 0), MI_SUCCESS);
			ExecFunc(MI_DISP_SetInputPortSyncMode(1, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);	
	}
	return MI_SUCCESS;
}


static MI_S32 St_HdmiModuleInit(Device_Handle_t *video_dev)
{
    MI_HDMI_InitParam_t stHdmiInitParam;
    MI_HDMI_Attr_t stHdmiAttr;
	MI_HDMI_Edid_t stEdid;

    memset(&stHdmiInitParam, 0, sizeof(stHdmiInitParam));
    memset(&stHdmiAttr, 0, sizeof(stHdmiAttr));
	memset(&stEdid, 0, sizeof(MI_HDMI_Edid_t));

    stHdmiInitParam.pCallBackArgs = NULL;
    stHdmiInitParam.pfnHdmiEventCallback = NULL;

    ExecFunc(MI_HDMI_Init(&stHdmiInitParam), MI_SUCCESS);
    ExecFunc(MI_HDMI_Open(E_MI_HDMI_ID_0), MI_SUCCESS);

	MI_HDMI_ForceGetEdid(E_MI_HDMI_ID_0, &stEdid);
	MI_HDMI_GetAttr(E_MI_HDMI_ID_0, &stHdmiAttr);
	
	stHdmiAttr.stVideoAttr.bEnableVideo = true;
    stHdmiAttr.stVideoAttr.eColorType = E_MI_HDMI_COLOR_TYPE_YCBCR444;
    stHdmiAttr.stVideoAttr.eDeepColorMode = E_MI_HDMI_DEEP_COLOR_24BIT;
    stHdmiAttr.stVideoAttr.eOutputMode = E_MI_HDMI_OUTPUT_MODE_HDMI;
    stHdmiAttr.stVideoAttr.eTimingType = E_MI_HDMI_TIMING_1080_60P;
	stHdmiAttr.stAudioAttr.bEnableAudio    = TRUE;
    stHdmiAttr.stAudioAttr.bIsMultiChannel = 0;
    stHdmiAttr.stAudioAttr.eBitDepth       = E_MI_HDMI_BIT_DEPTH_16;
    stHdmiAttr.stAudioAttr.eCodeType       = E_MI_HDMI_ACODE_PCM;
    stHdmiAttr.stAudioAttr.eSampleRate     = E_MI_HDMI_AUDIO_SAMPLERATE_48K;
    stHdmiAttr.stEnInfoFrame.bEnableAudInfoFrame = true;
    stHdmiAttr.stEnInfoFrame.bEnableAviInfoFrame = true;
    stHdmiAttr.stEnInfoFrame.bEnableSpdInfoFrame = true;
    ExecFunc(MI_HDMI_SetAttr(E_MI_HDMI_ID_0, &stHdmiAttr), MI_SUCCESS);
    ExecFunc(MI_HDMI_Start(E_MI_HDMI_ID_0), MI_SUCCESS);

    return MI_SUCCESS;
}


void *ST_UpdateRgnOsdProcExt(void *args)
{
    time_t now = 0;
    struct tm *tm = NULL;
    char szTime[64];
    int len = 0;
    struct timeval tv;
    MI_RGN_CanvasInfo_t* pstCanvasInfo = NULL;
    ST_Point_T stPoint;
    time_t defaultInterval = 980 * 1000;
	time_t timeTmp = 0;
    struct timeval timeBegin, timeEnd;

    while(g_stRgnOsd.bRun)
    {
        tv.tv_sec = 0;
        tv.tv_usec = defaultInterval;

        if(0 == select(0, NULL, NULL, NULL, &tv))
        {
            // time out
            gettimeofday(&timeBegin, NULL);

            now = time(NULL);

            if((tm = localtime(&now)) == NULL)
            {
                printf("localtime error\n");
                return NULL;
            }

            memset(szTime, 0, sizeof(szTime));
            len = 0;

            len += sprintf(szTime + len, "%d-", tm->tm_year + 1900);
            len += sprintf(szTime + len, "%02d-", tm->tm_mon + 1);
            len += sprintf(szTime + len, "%02d ", tm->tm_mday);
            len += sprintf(szTime + len, "%02d:", tm->tm_hour);
            len += sprintf(szTime + len, "%02d:", tm->tm_min);
            len += sprintf(szTime + len, "%02d", tm->tm_sec);

            stPoint.u32X = 0;
            stPoint.u32Y = 0;

            CANVAS_LOCK;
            (void)ST_OSD_GetCanvasInfo(RGN_OSD_HANDLE, &pstCanvasInfo);

            (void)ST_OSD_Clear(RGN_OSD_HANDLE, NULL);

            (void)ST_OSD_DrawText(RGN_OSD_HANDLE, stPoint, szTime, 4, DMF_Font_Size_32x32);

            (void)ST_OSD_Update(RGN_OSD_HANDLE);
            CANVAS_UNLOCK;

            gettimeofday(&timeEnd, NULL);

            //defaultInterval = 1000 * 1000 - ((timeEnd.tv_sec * 1000000 + timeEnd.tv_usec) -
             //                   (timeBegin.tv_sec * 1000000 + timeBegin.tv_usec));
             timeTmp = (timeEnd.tv_sec * 1000000 + timeEnd.tv_usec) - (timeBegin.tv_sec * 1000000 + timeBegin.tv_usec);
			if(timeTmp > 0 && timeTmp < 1000 * 1000)
			{
				defaultInterval = 1000 * 1000 - timeTmp;
			}
			else if(timeTmp >= 1000 * 1000)
			{
				defaultInterval = 10 * 1000;
			}
			else
			{
				defaultInterval = 980 * 1000;
			}
           // ST_DBG("defaultInterval:%d, szTime:%s\n", defaultInterval, szTime);
        }
    }

    return NULL;
}


static MI_S32 St_VencModuleInit(Device_Handle_t *video_dev)
{
	MI_S32 s32Ret;

    MI_VENC_DEV VeDev = MI_VENC_DEV_ID_H264_H265_0;

    MI_VENC_CHN VeChn = 0;

    MI_VENC_ChnAttr_t stAttr;

	if(video_dev->width == 0 )
	{
		video_dev->width = 1280;
		video_dev->height = 720;
	}

    /*set h264 chnnel video encode attribute*/
	memset(&stAttr, 0, sizeof(MI_VENC_ChnAttr_t));

    stAttr.stVeAttr.eType = E_MI_VENC_MODTYPE_H264E;

    stAttr.stVeAttr.stAttrH264e.u32PicWidth = video_dev->width;

    stAttr.stVeAttr.stAttrH264e.u32PicHeight = video_dev->height;

    stAttr.stVeAttr.stAttrH264e.u32MaxPicWidth = 3840;

    stAttr.stVeAttr.stAttrH264e.u32MaxPicHeight = 2160;

    stAttr.stVeAttr.stAttrH264e.u32Profile = 2;

    /*set h264 chnnel rate control attribute*/

    stAttr.stRcAttr.eRcMode = E_MI_VENC_RC_MODE_H264CBR;

    stAttr.stRcAttr.stAttrH264Cbr.u32BitRate = 2*1024*1024;

    stAttr.stRcAttr.stAttrH264Cbr.u32SrcFrmRateNum = video_dev->frame_rate;

    stAttr.stRcAttr.stAttrH264Cbr.u32SrcFrmRateDen  = 1;

    stAttr.stRcAttr.stAttrH264Cbr.u32Gop = 30;

    stAttr.stRcAttr.stAttrH264Cbr.u32FluctuateLevel = 1;

    stAttr.stRcAttr.stAttrH264Cbr.u32StatTime = 1;

    s32Ret = MI_VENC_CreateChn(VeDev, VeChn, &stAttr);

	s32Ret = MI_VENC_CreateChn(VeDev, 1, &stAttr);

    if (MI_SUCCESS != s32Ret)

    {

        printf("MI_VENC_CreateChn err0x%x\n", s32Ret);

        return E_MI_ERR_FAILED;

    }

	MI_VENC_ParamH264SliceSplit_t stSlice;
	memset(&stSlice, 0, sizeof(MI_VENC_ParamH264SliceSplit_t));
	//...omit other thing
    s32Ret = MI_VENC_GetH264SliceSplit(VeDev, VeChn, &stSlice);
    if (MI_SUCCESS != s32Ret)
    {
        printf("MI_VENC_GetH264SliceSplit err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }
	printf("VeChn 0  stSlice.u32SliceRowCount = %d\n",stSlice.u32SliceRowCount);
    stSlice.bSplitEnable = false;
    s32Ret = MI_VENC_SetH264SliceSplit(VeDev, VeChn, &stSlice);
    if(MI_SUCCESS != s32Ret)
    {
        printf("MI_VENC_SetH264SliceSplit err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }


	s32Ret = MI_VENC_GetH264SliceSplit(VeDev, 1, &stSlice);
    if (MI_SUCCESS != s32Ret)
    {
        printf("MI_VENC_GetH264SliceSplit err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }
	printf("VeChn 1  stSlice.u32SliceRowCount = %d\n",stSlice.u32SliceRowCount);
    stSlice.bSplitEnable = false;
    s32Ret = MI_VENC_SetH264SliceSplit(VeDev, 1, &stSlice);
    if(MI_SUCCESS != s32Ret)
    {
        printf("MI_VENC_SetH264SliceSplit err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }

	MI_VENC_SetMaxStreamCnt(VeDev,  1, 15 );

	

	

	MI_RGN_Attr_t stRgnAttr;
    MI_RGN_ChnPort_t stChnPort;
    MI_RGN_ChnPortParam_t stChnPortParam;

	

    memset(&stRgnAttr, 0, sizeof(MI_RGN_Attr_t));
    stRgnAttr.eType = E_MI_RGN_TYPE_OSD;
    stRgnAttr.stOsdInitParam.ePixelFmt = E_MI_RGN_PIXEL_FORMAT_I4;
    stRgnAttr.stOsdInitParam.stSize.u32Width = RGN_OSD_TIME_WIDTH;
    stRgnAttr.stOsdInitParam.stSize.u32Height = RGN_OSD_TIME_HEIGHT;
    ExecFunc(ST_OSD_Create(RGN_OSD_HANDLE, &stRgnAttr), MI_RGN_OK);
	memset(&stChnPort, 0, sizeof(MI_RGN_ChnPort_t));
    stChnPort.eModId = E_MI_MODULE_ID_SCL;
    stChnPort.s32DevId = 1;
    stChnPort.s32ChnId = SCL_CHN_ID;
    stChnPort.s32PortId = 3;
    memset(&stChnPortParam, 0, sizeof(MI_RGN_ChnPortParam_t));
    stChnPortParam.bShow = TRUE;
    stChnPortParam.stPoint.u32X = 100;
    stChnPortParam.stPoint.u32Y = pvideo_dev->height - 100;
    stChnPortParam.unPara.stOsdChnPort.u32Layer = 0;
    stChnPortParam.unPara.stOsdChnPort.stOsdAlphaAttr.eAlphaMode = E_MI_RGN_PIXEL_ALPHA;
    stChnPortParam.unPara.stOsdChnPort.stOsdAlphaAttr.stAlphaPara.stArgb1555Alpha.u8BgAlpha = 0;
    stChnPortParam.unPara.stOsdChnPort.stOsdAlphaAttr.stAlphaPara.stArgb1555Alpha.u8FgAlpha = 0xFF;
    ExecFunc(MI_RGN_AttachToChn(0,RGN_OSD_HANDLE, &stChnPort, &stChnPortParam), MI_RGN_OK);

	g_stRgnOsd.bRun = TRUE;
    pthread_create(&g_stRgnOsd.pt, NULL, ST_UpdateRgnOsdProcExt, NULL);

	return MI_SUCCESS;
}


static MI_S32 St_ispModuleInit()
{
	MI_ISP_DEV IspDevId = 0;
    MI_ISP_CHANNEL IspChnId = 0;
    MI_ISP_PORT  IspOutPortId =0;

    MI_ISP_DevAttr_t stCreateDevAttr;
    memset(&stCreateDevAttr, 0x0, sizeof(MI_ISP_DevAttr_t));
    stCreateDevAttr.u32DevStitchMask = E_MI_ISP_DEVICEMASK_ID0;

    MI_ISP_CreateDevice(IspDevId, &stCreateDevAttr);

    MI_ISP_ChannelAttr_t  stIspChnAttr;
    memset(&stIspChnAttr, 0x0, sizeof(MI_ISP_ChannelAttr_t));
    stIspChnAttr. u32SensorBindId = E_MI_ISP_SENSOR_INVALID;
    MI_ISP_CreateChannel(IspDevId, IspChnId, &stIspChnAttr);

    MI_SYS_WindowRect_t  stInputCropInfo;
    stInputCropInfo.u16X=0;
    stInputCropInfo.u16Y=0;
    stInputCropInfo.u16Width=0;
    stInputCropInfo.u16Height=0;//width/height==0 no use crop.
    MI_ISP_SetInputPortCrop(IspDevId, IspChnId, &stInputCropInfo);

    MI_ISP_ChnParam_t  stChnParam;
    stChnParam.eHDRType = E_MI_ISP_HDR_TYPE_OFF;
    stChnParam.e3DNRLevel = E_MI_ISP_3DNR_LEVEL_OFF;
    stChnParam.bMirror = FALSE;
    stChnParam.bFlip = FALSE;
    stChnParam.eRot = E_MI_SYS_ROTATE_NONE;
    //use rot or flip, 3dnr level must more than 0
    //stChnParam.bY2bEnable = FALSE;
    MI_ISP_SetChnParam(IspDevId, IspChnId, &stChnParam);
    MI_ISP_StartChannel(IspDevId, IspChnId);


    MI_ISP_OutPortParam_t  stIspOutputParam;
    memset(&stIspOutputParam, 0x0, sizeof(MI_ISP_OutPortParam_t));
    stIspOutputParam.stCropRect.u16X=0;
    stIspOutputParam.stCropRect.u16Y=0;
    stIspOutputParam.stCropRect.u16Width=0;
    stIspOutputParam.stCropRect.u16Height=0;//width/height use 0, not use crop
    stIspOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    MI_ISP_SetOutputPortParam(IspDevId, IspChnId, IspOutPortId, &stIspOutputParam);
    MI_ISP_EnableOutputPort(IspDevId, IspChnId, IspOutPortId);


	return MI_SUCCESS;
}


MI_S32 ST_IspModuleUnInit(MI_ISP_DEV IspDevId)
{
    MI_ISP_CHANNEL IspChnId = 0;
    MI_ISP_PORT  IspOutPortId =0;


    MI_ISP_DisableOutputPort(IspDevId, IspChnId, IspOutPortId);


    MI_ISP_StopChannel(IspDevId, IspChnId);
    MI_ISP_DestroyChannel(IspDevId, IspChnId);

    MI_ISP_DestoryDevice(IspDevId);

    return MI_SUCCESS;
}



int fb_init(void)
{
    const char *devfile = "/dev/fb0";
    int fbFd = 0;
    long int screensize = 0;

    fbFd = open(devfile, O_RDWR);
    if(fbFd == -1)
    {
        perror ("Error: cannot open framebuffer device");
        exit(1);
    }
    //get fb_fix_screeninfo
    if(ioctl(fbFd, FBIOGET_FSCREENINFO, &finfo) == -1)
    {
        perror("Error reading fixed information");
        exit(2);
    }
    //get fb_var_screeninfo
    if(ioctl(fbFd, FBIOGET_VSCREENINFO, &vinfo) == -1)
    {
        perror("Error reading variable information");
        exit(3);
    }	
	screensize = finfo.smem_len;
	
    /* Map the device to memory */
    framebuffer = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
            fbFd, 0);
    if(framebuffer == MAP_FAILED)
    {
        perror ("Error: Failed to map framebuffer device to memory");
        exit (4);
    }
    //draw red rectangle
    //drawRect_rgb32_my (vinfo.xres / 8, vinfo.yres / 16,
      //      vinfo.xres / 4, vinfo.yres / 4, 0xffff0000, &vinfo, &finfo, framebuffer);

    //draw DarkGoldenrod rectangle
    //drawRect_rgb32_my (vinfo.xres * 3 / 8, vinfo.yres * 5 / 16,
       //     vinfo.xres / 4, vinfo.yres / 4, 0xffb8860b, &vinfo, &finfo, framebuffer);

    //draw blue rectanble
    //drawRect_rgb32_my (vinfo.xres * 5 / 8, vinfo.yres * 9 / 16,
     //       vinfo.xres / 4, vinfo.yres / 4, 0xff0000ff, &vinfo, &finfo, framebuffer);

	//drawRect_rgb32_my (0, 0,100, 200, 0xff0000ff, &vinfo, &finfo, (char *)framebuffer);
	munmap(framebuffer, screensize);
    framebuffer = NULL;

    close(fbFd);


    return 0;
}

static KJD_VencAttr_t pstVencAttr[1];


void *KJD_OpenStream(char const *szStreamName, void *arg)
{
#if 1
    MI_U32 i = 0;
	MI_S32 s32Ret = MI_SUCCESS;

	s32Ret = MI_VENC_StartRecvPic(0, 0);

    if (s32Ret != MI_SUCCESS)
    {

        printf("MI_VENC_StartRecvPic err0x%x\n",s32Ret);

    }


	g_rtsp = true;

	KJD_VencAttr_t *stVencAttr = pstVencAttr;


    s32Ret = MI_VENC_RequestIdr(stVencAttr->DevId,stVencAttr->vencChn, TRUE);


	ST_DBG("open stream \"%s\" success, chn:0\n", szStreamName);

    if(MI_SUCCESS != s32Ret)
    {
        ST_WARN("request IDR fail, error:%x\n", s32Ret);
    }

    return stVencAttr;
#endif
	

}

MI_U32 u32GetCnt=0, u32ReleaseCnt=0;
int KJD_VideoReadStream(void *handle, unsigned char *ucpBuf, int BufLen, struct timeval *p_Timestamp, void *arg)
{
#if 1

    MI_SYS_BufInfo_t stBufInfo;
    MI_S32 s32Ret = MI_SUCCESS;
    MI_S32 len = 0;
    MI_VENC_Stream_t stStream;
    MI_VENC_Pack_t stPack;
    MI_VENC_ChnStat_t stStat;
    MI_VENC_CHN vencChn ;
    MI_VENC_DEV DevId =0;

    if(handle == NULL)
    {
        return -1;
    }


    vencChn = 0;
    DevId = 0;


    /*s32Ret = MI_VENC_GetChnDevid(vencChn, &u32DevId);

    if(MI_SUCCESS != s32Ret)
    {
        ST_INFO("MI_VENC_GetChnDevid %d error, %X\n", vencChn, s32Ret);
    }*/

    memset(&stBufInfo, 0x0, sizeof(MI_SYS_BufInfo_t));
    memset(&stStream, 0, sizeof(stStream));
    memset(&stPack, 0, sizeof(stPack));
    stStream.pstPack = &stPack;
    stStream.u32PackCount = 1;
    s32Ret = MI_VENC_Query(DevId, vencChn, &stStat);

    if(s32Ret != MI_SUCCESS || stStat.u32CurPacks == 0)
    {
        return 0;
    }

    s32Ret = MI_VENC_GetStream(DevId, vencChn, &stStream, 40);

    if(MI_SUCCESS == s32Ret)
    {
        u32GetCnt++;
        len = stStream.pstPack[0].u32Len;
        memcpy(ucpBuf, stStream.pstPack[0].pu8Addr, MIN(len, BufLen));

        s32Ret = MI_VENC_ReleaseStream(DevId, vencChn, &stStream);
        if(s32Ret != MI_SUCCESS)
        {
            ST_WARN("RELEASE venc buffer fail\n");
        }
        u32ReleaseCnt ++;
        return len;
    }

#endif
/*
	MI_S32 len = 0;
	Stream_Buffer_t video_buf;
    memset(&video_buf, 0, sizeof(Stream_Buffer_t));

	int ret = video_get_buf(&video_dev, &video_buf);
    if(ret == 0)
    {
    	u32GetCnt++;
        len = video_buf.length;
        memcpy(ucpBuf, video_buf.buf, MIN(len, BufLen));
  		printf("MIN(len, BufLen) = %d ===============================1324======================\n",MIN(len, BufLen));
		video_put_buf(&video_dev, &video_buf);
        u32ReleaseCnt ++;
        return len;
    }
    */
	return 0;
	
}

int KJD_CloseStream(void *handle, void *arg)
{
    if(handle == NULL)
    {
        return -1;
    }
	//g_rtsp = false;

	
	KJD_VencAttr_t *pstStreamInfo = (KJD_VencAttr_t *)handle;
	
    ST_DBG("close \"%s\" success\n", pstStreamInfo->szStreamName);
	
    return 0;
}

MI_S32 KJD_RtspServerStart(void)
{
    unsigned int rtspServerPortNum = RTSP_LISTEN_PORT;
    int iRet = 0;
    char *urlPrefix = NULL;
    int i = 0;
    ServerMediaSession *mediaSession = NULL;
    ServerMediaSubsession *subSession = NULL;
    Live555RTSPServer *pRTSPServer = NULL;


	

	pstVencAttr[0].DevId = 0;
	pstVencAttr[0].vencChn = 0;
	pstVencAttr[0].eType = E_MI_VENC_MODTYPE_JPEGE;
	pstVencAttr[0].bCreate = TRUE;
	pstVencAttr[0].bUsed = TRUE;
	pstVencAttr[0].u32Width = DISP_WIDTH;
	pstVencAttr[0].u32Height = DISP_HEIGHT;
	pstVencAttr[0].szStreamName = "video0";

	KJD_VencAttr_t *pstStreamAttr = pstVencAttr;


    pRTSPServer = new Live555RTSPServer();

	printf("KJD_RtspServerStart \n");
	

    if(pRTSPServer == NULL)
    {
        ST_ERR("malloc error\n");
        return -1;
    }

    iRet = pRTSPServer->SetRTSPServerPort(rtspServerPortNum);

    while(iRet < 0)
    {
        rtspServerPortNum++;

        if(rtspServerPortNum > 65535)
        {
            ST_INFO("Failed to create RTSP server: %s\n", pRTSPServer->getResultMsg());
            delete pRTSPServer;
            pRTSPServer = NULL;
            return -2;
        }

        iRet = pRTSPServer->SetRTSPServerPort(rtspServerPortNum);
    }

    urlPrefix = pRTSPServer->rtspURLPrefix();

    printf("=================URL===================\n");
    printf("%s%s\n", urlPrefix, pstStreamAttr[i].szStreamName);
    printf("=================URL===================\n");

    pRTSPServer->createServerMediaSession(mediaSession,
                                          pstStreamAttr[i].szStreamName,
                                          NULL, NULL);


    subSession = WW_H264VideoFileServerMediaSubsession::createNew(
                     *(pRTSPServer->GetUsageEnvironmentObj()),
                     pstStreamAttr[i].szStreamName,
                     KJD_OpenStream,
                     KJD_VideoReadStream,
                     KJD_CloseStream, 30);

    pRTSPServer->addSubsession(mediaSession, subSession);
    pRTSPServer->addServerMediaSession(mediaSession);


    pRTSPServer->Start();

    g_pRTSPServer = pRTSPServer;

    return 0;
}

MI_S32 KJD_RtspServerStop(void)
{
	printf("KJD_RtspServerStop \n");
    if(g_pRTSPServer)
    {
        g_pRTSPServer->Join();
        delete g_pRTSPServer;
        g_pRTSPServer = NULL;
    }
	
    return 0;
}


MI_S32 St_BaseInit(Device_Handle_t *video_dev)
{

    ST_Sys_BindInfo_T stSysBindInfo;

    memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));

    ExecFunc(ST_Sys_Init(), MI_SUCCESS);
	STCHECKRESULT(ST_OSD_Init());
	//if( usb_open_flag == false)
	{
		video_dev->pixelformat = V4L2_PIX_FMT_MJPEG;
		video_dev->frame_rate = 30;
	}


	/* fast disp */
	//ExecFunc(St_fastModuleInit(video_dev), MI_SUCCESS);
	/* scl start */
	ExecFunc(St_SclModuleInit(video_dev), MI_SUCCESS);
	/* disp start */
	ExecFunc(St_DispModuleInit(video_dev), MI_SUCCESS);
	/* hdmi start */
	ExecFunc(St_HdmiModuleInit(video_dev), MI_SUCCESS);
	//venc star
	ExecFunc(St_VencModuleInit(video_dev), MI_SUCCESS);
	
	
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
	stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stSrcChnPort.u32PortId = 2;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
	stSysBindInfo.stDstChnPort.u32DevId = MI_VENC_DEV_ID_JPEG_0;//0;
	stSysBindInfo.stDstChnPort.u32ChnId = 0;
	stSysBindInfo.stDstChnPort.u32PortId = 0;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
	stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stSrcChnPort.u32PortId = 3;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
	stSysBindInfo.stDstChnPort.u32DevId = MI_VENC_DEV_ID_JPEG_0;//0;
	stSysBindInfo.stDstChnPort.u32ChnId = 1;
	stSysBindInfo.stDstChnPort.u32PortId = 0;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
	stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stSrcChnPort.u32PortId = 2;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
	stSysBindInfo.stDstChnPort.u32DevId = 0;
	stSysBindInfo.stDstChnPort.u32ChnId = 0;
	stSysBindInfo.stDstChnPort.u32PortId = 0;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
	stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stSrcChnPort.u32PortId = 3;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
	stSysBindInfo.stDstChnPort.u32DevId = 0;
	stSysBindInfo.stDstChnPort.u32ChnId = 1;
	stSysBindInfo.stDstChnPort.u32PortId = 0;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	
	
	MI_DISP_WBC_Source_t stWbcSource;
	MI_DISP_WBC_Attr_t stWbcAttr;

	stWbcSource.eSourceType = MI_DISP_WBC_SOURCE_DEV;
	stWbcSource.u32SourceId = 0;
	MI_DISP_SetWBCSource(0, &stWbcSource);

	stWbcAttr.stTargetSize.u32Width = 1280;
	stWbcAttr.stTargetSize.u32Height = 800;
	stWbcAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	MI_DISP_SetWBCAttr(0, &stWbcAttr);
	MI_DISP_EnableWBC(0);

	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_WBC;
	stSysBindInfo.stSrcChnPort.u32DevId = 0;
	stSysBindInfo.stSrcChnPort.u32ChnId = 0;
	stSysBindInfo.stSrcChnPort.u32PortId = 0;

	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
	stSysBindInfo.stDstChnPort.u32DevId = 1;
	stSysBindInfo.stDstChnPort.u32ChnId = 0;
	stSysBindInfo.stDstChnPort.u32PortId = 0;

	MI_SYS_BindChnPort(0, &(stSysBindInfo.stSrcChnPort), &(stSysBindInfo.stDstChnPort), 30, 30);				
	
	return MI_SUCCESS;
}

MI_S32 St_BaseMipiModuleInit(Device_Handle_t *video_dev)
{
    ST_Sys_BindInfo_T stSysBindInfo;

    memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));

/*    ExecFunc(ST_Sys_Init(), MI_SUCCESS);
	STCHECKRESULT(ST_OSD_Init());
	//if( usb_open_flag == false)
	{
		video_dev->pixelformat = V4L2_PIX_FMT_MJPEG;
		video_dev->frame_rate = 30;
	}
	*/
	
	ExecFunc(ST_SensorModuleInit(), MI_SUCCESS);
	ExecFunc(ST_VifModuleInit(), MI_SUCCESS);
	ExecFunc(ST_IspModuleInit(), MI_SUCCESS);
	
	
	/* bind vif and isp */
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VIF;
	stSysBindInfo.stSrcChnPort.u32DevId = 0;//chg 9734
//	stSysBindInfo.stSrcChnPort.u32DevId = 12;//chg 6946
	stSysBindInfo.stSrcChnPort.u32ChnId = 0;
	stSysBindInfo.stSrcChnPort.u32PortId = 0;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_ISP;
	stSysBindInfo.stDstChnPort.u32DevId = 0;
	stSysBindInfo.stDstChnPort.u32ChnId = 0;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	
	/* bind isp and scl */
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
	stSysBindInfo.stSrcChnPort.u32DevId = 0;
	stSysBindInfo.stSrcChnPort.u32ChnId = 0;
	stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
	stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
	stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
	stSysBindInfo.stDstChnPort.u32DevId = 0;
	stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
	stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);



    if (iFirstStart == 0)
	{ 
		printf("ST_DoSetIqBin func yes 0 \r\n");
		ST_DoSetIqBin(0, 0, "/customer/mp6946.bin");
		printf("ST_DoSetIqBin func yes 1 \r\n");
	}


    g_i_InitMipiFlag = 1;

    return MI_SUCCESS;
}

void St_BaseMipiModuleInitFun()
{
	St_BaseMipiModuleInit(pvideo_dev);
}

MI_S32 St_BaseMipiModuleUnInit(Device_Handle_t *video_dev)
{
    ST_Sys_BindInfo_T stSysBindInfo;

    memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));

  //  ExecFunc(ST_Sys_Init(), MI_SUCCESS);
	//STCHECKRESULT(ST_OSD_Init());
	//if( usb_open_flag == false)
	/*{
		video_dev->pixelformat = V4L2_PIX_FMT_MJPEG;
		video_dev->frame_rate = 30;
	}*/
	
	
	ExecFunc(ST_SensorModuleUnInit(0), MI_SUCCESS);
	ExecFunc(ST_VifModuleUnInit(), MI_SUCCESS);
	ExecFunc(ST_IspModuleUnInit(), MI_SUCCESS);



	/* bind vif and isp */
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VIF;
	stSysBindInfo.stSrcChnPort.u32DevId = 0;//chg 9734
//	stSysBindInfo.stSrcChnPort.u32DevId = 12;//chg 6946
	stSysBindInfo.stSrcChnPort.u32ChnId = 0;
	stSysBindInfo.stSrcChnPort.u32PortId = 0;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_ISP;
	stSysBindInfo.stDstChnPort.u32DevId = 0;
	stSysBindInfo.stDstChnPort.u32ChnId = 0;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
	
	/* bind isp and scl */
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
	stSysBindInfo.stSrcChnPort.u32DevId = 0;
	stSysBindInfo.stSrcChnPort.u32ChnId = 0;
	stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
	stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
	
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
	stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
	stSysBindInfo.stDstChnPort.u32DevId = 0;
	stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
	stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
	stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);

    return MI_SUCCESS;
}

void St_BaseMipiModuleUnInitFun()
{
	St_BaseMipiModuleUnInit(pvideo_dev);
}

//切换Mipi摄像头为主视频
MI_S32 ChangeMipiCamInMain()
{
	if (g_i_MainViewFlag == 0)
		ChangeSclBind(1);
	
	return MI_SUCCESS;	
}

//切换Usb摄像头为主视频
MI_S32 ChangeUsbCamInMain()
{
	if (g_i_MainViewFlag == 1)
		ChangeSclBind(0);
		
	return MI_SUCCESS;	
}


//切换某摄像头为主视频
MI_S32 ChangeSclBind(unsigned char iFlag)
{
	
    ST_Sys_BindInfo_T stSysBindInfo;

    memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		
	Device_Handle_t *video_dev = pvideo_dev;
		
    if (iFlag == 1)//切换mipi摄像头为主视频
	{		
                g_i_MainViewFlag = 1; 
				 
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
				stSysBindInfo.stSrcChnPort.u32DevId = 0;
				stSysBindInfo.stSrcChnPort.u32ChnId = 0;
				stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
				stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				


				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
				stSysBindInfo.stSrcChnPort.u32DevId = 0;
				stSysBindInfo.stSrcChnPort.u32ChnId = 0;
				stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;//1
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
				
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
				stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	}
	else{//切换usb摄像头为主视频
	
                g_i_MainViewFlag = 0; 
	
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
				stSysBindInfo.stSrcChnPort.u32DevId = 0;
				stSysBindInfo.stSrcChnPort.u32ChnId = 0;
				stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;//1
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
				stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				


				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
				stSysBindInfo.stSrcChnPort.u32DevId = 0;
				stSysBindInfo.stSrcChnPort.u32ChnId = 0;
				stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
				
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
				stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
		
	}

   return MI_SUCCESS;
}

//切换Sc11为主视频用于正常状态
MI_S32 ChangeSclDispBindForNor()
{
	RotateAction(0);	
	
	if (g_i_MainSclDispFlag == 1)
		ChangeSclDispBind(0);
	
	funSendMsgToUi("cmd_rotate_flag",CMD_ROTATE_FLAG,0,"");
		
	return MI_SUCCESS;	
}

//切换Sc13为主视频用于旋转
MI_S32 ChangeSclDispBindForRat(char RotateNum)
{
	
	if (g_i_MainSclDispFlag == 0)
		ChangeSclDispBind(1);
		
	 RotateAction(RotateNum);	
	 return MI_SUCCESS;	
}

//切换某Sc1为主视频
MI_S32 ChangeSclDispBind(unsigned char iFlag)
{
	
    ST_Sys_BindInfo_T stSysBindInfo;

    memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		
	Device_Handle_t *video_dev = pvideo_dev;
		
    if (iFlag == 1)//切换Scl3为主视频(用于旋转用)
	{		
                g_i_MainSclDispFlag = 1; 
				 
				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				else//主视频为Usb摄像头
				{
					if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
					{
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
						stSysBindInfo.stSrcChnPort.u32DevId = 0;
						stSysBindInfo.stSrcChnPort.u32ChnId = 0;
						stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
					}
				}

				if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
				{
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
						stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
						
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
						stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
						stSysBindInfo.stDstChnPort.u32DevId = 0;
						stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				}
				
				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
					stSysBindInfo.stSrcChnPort.u32DevId = 0;
					stSysBindInfo.stSrcChnPort.u32ChnId = 0;
					stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				}
				else//主视频为Usb摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);;


				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = 1;
				stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				//ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);


				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				else//主视频为Usb摄像头
				{
					if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
					{
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
						stSysBindInfo.stSrcChnPort.u32DevId = 0;
						stSysBindInfo.stSrcChnPort.u32ChnId = 0;
						stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
					}
				}
				if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
				{
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;//1
						stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
						
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
						stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
						stSysBindInfo.stDstChnPort.u32DevId = 0;
						stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
				}

				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
					stSysBindInfo.stSrcChnPort.u32DevId = 0;
					stSysBindInfo.stSrcChnPort.u32ChnId = 0;
					stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				}
				else//主视频为Usb摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;//SCL_PORT_ID
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;//SCL_PORT_ID
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = 1;
				stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				//ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	}
	else{//切换Scl1为主视频(用于正常状态用)
	
                g_i_MainSclDispFlag = 0; 
	
	
				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				else//主视频为Usb摄像头
				{
					if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
					{
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
						stSysBindInfo.stSrcChnPort.u32DevId = 0;
						stSysBindInfo.stSrcChnPort.u32ChnId = 0;
						stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
					}
				}
				if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
				{
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;//1
						stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
						
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
						stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
						stSysBindInfo.stDstChnPort.u32DevId = 0;
						stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				}


				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
					stSysBindInfo.stSrcChnPort.u32DevId = 0;
					stSysBindInfo.stSrcChnPort.u32ChnId = 0;
					stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				}
				else//主视频为Usb摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;//SCL_PORT_ID
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);;

				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;//SCL_PORT_ID
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = 1;
				stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			//	ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);


				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				else//主视频为Usb摄像头
				{
					if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
					{
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
						stSysBindInfo.stSrcChnPort.u32DevId = 0;
						stSysBindInfo.stSrcChnPort.u32ChnId = 0;
						stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
					}
				}
				if (g_i_InitMipiFlag == 1)//已经有初始化过Mipi摄像头
				{
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
						stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
						
						stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
						stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
						stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
						stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
						stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
						stSysBindInfo.stDstChnPort.u32DevId = 0;
						stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
						stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
						stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
						stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
						stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
						ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
				}

				if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//主视频为Mipi摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
					stSysBindInfo.stSrcChnPort.u32DevId = 0;
					stSysBindInfo.stSrcChnPort.u32ChnId = 0;
					stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
				}
				else//主视频为Usb摄像头
				{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
					stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
				}
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
				
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
				ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	
				stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
				stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
				stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
				stSysBindInfo.stSrcChnPort.u32PortId = 0;
				stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
				stSysBindInfo.stDstChnPort.u32DevId = 1;
				stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
				stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
				stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
				stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
				stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			//	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	}

   return MI_SUCCESS;
}


MI_S32 St_BaseModuleInit(Device_Handle_t *video_dev)
{
    ST_Sys_BindInfo_T stSysBindInfo;

    memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));

    //ExecFunc(ST_Sys_Init(), MI_SUCCESS);
	//STCHECKRESULT(ST_OSD_Init());
	if( usb_open_flag == false)
	{
		video_dev->pixelformat = V4L2_PIX_FMT_MJPEG;
		video_dev->frame_rate = 30;
	}

    switch(video_dev->pixelformat)
    {
        case V4L2_PIX_FMT_YUYV:
            /* bind scl and disp */
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 0;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
 
 			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
			stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
			stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
			stSysBindInfo.stSrcChnPort.u32PortId = 0;
			stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
			stSysBindInfo.stDstChnPort.u32DevId = 1;
			stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
			stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
			stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
			stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
			stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			//ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

            break;

        case V4L2_PIX_FMT_NV12:
           /* bind scl and disp */
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 0;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
			stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
			stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
			stSysBindInfo.stSrcChnPort.u32PortId = 0;
			stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
			stSysBindInfo.stDstChnPort.u32DevId = 1;
			stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
			stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
			stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
			stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
			stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			//ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
 
            break;

        case V4L2_PIX_FMT_MJPEG:
            /* jpd start */		
            ExecFunc(St_JpdModuleInit(video_dev), MI_SUCCESS);
            /* bind jpd and scl */
            stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
            stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

            /* bind scl and disp */
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 0;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
			
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
			stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
			stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
			stSysBindInfo.stSrcChnPort.u32PortId = 0;
			stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
			stSysBindInfo.stDstChnPort.u32DevId = 1;
			stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
			stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
			stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
			stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
			stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			//ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
			
            break;

        case V4L2_PIX_FMT_H264:
        case V4L2_PIX_FMT_H265:
            /* vdec start */
            ExecFunc(St_VdecModuleInit(video_dev), MI_SUCCESS);
			
            /* bind vdec and scl */
            stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VDEC;
            stSysBindInfo.stSrcChnPort.u32DevId = VDEC_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = VDEC_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = VDEC_PORT_ID;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

            /* bind scl and disp */
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 0;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
			stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
			stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
			stSysBindInfo.stSrcChnPort.u32PortId = 0;
			stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
			stSysBindInfo.stDstChnPort.u32DevId = 1;
			stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
			stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
			stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
			stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
			stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			//ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

            break;

        default:
            break;
    }
	
	g_i_InitUsbFlag = 1;

    return MI_SUCCESS;
}


MI_S32 St_SclModuleDeinit(Device_Handle_t *video_dev)
{
    ExecFunc(MI_SCL_DisableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 0), MI_SUCCESS);
	ExecFunc(MI_SCL_DisableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 1), MI_SUCCESS);
	ExecFunc(MI_SCL_DisableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 2), MI_SUCCESS);
    ExecFunc(MI_SCL_StopChannel(SCL_DEV_ID, SCL_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_SCL_DestroyChannel(SCL_DEV_ID, SCL_CHN_ID), MI_SUCCESS);
	ExecFunc(MI_SCL_DisableOutputPort(3, SCL_CHN_ID, 0), MI_SUCCESS);
    ExecFunc(MI_SCL_StopChannel(3, SCL_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_SCL_DestroyChannel(3, SCL_CHN_ID), MI_SUCCESS);

    return MI_SUCCESS;
}

MI_S32 St_JpdModuleDeinit(Device_Handle_t *video_dev)
{
    ExecFunc(MI_JPD_StopChn(JPD_DEV_ID, JPD_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_JPD_DestroyChn(JPD_DEV_ID, JPD_CHN_ID), MI_SUCCESS);
#if 0
    ExecFunc(MI_JPD_DestroyDev(JPD_DEV_ID), MI_SUCCESS);
#endif

    return MI_SUCCESS;
}

MI_S32 St_VdecModuleDeinit(Device_Handle_t *video_dev)
{
    ExecFunc(MI_VDEC_StopChn(VDEC_DEV_ID, VDEC_CHN_ID), MI_SUCCESS);
    ExecFunc(MI_VDEC_DestroyChn(VDEC_DEV_ID, VDEC_CHN_ID), MI_SUCCESS);
#if 0
    ExecFunc(MI_VDEC_DestroyDev(VDEC_DEV_ID), MI_SUCCESS);
#endif

    return MI_SUCCESS;
}

MI_S32 St_DispModuleDeinit(Device_Handle_t *video_dev)
{
    ExecFunc(MI_DISP_DisableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_DisableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_UnBindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_Disable(DISP_DEV_ID), MI_SUCCESS);

	ExecFunc(MI_DISP_DisableInputPort(2, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_DisableVideoLayer(2), MI_SUCCESS);
    ExecFunc(MI_DISP_UnBindVideoLayer(2, 1), MI_SUCCESS);
    ExecFunc(MI_DISP_Disable(1), MI_SUCCESS);

    return MI_SUCCESS;
}

MI_S32 St_HdmiModuleDeinit(Device_Handle_t *video_dev)
{
    ExecFunc(MI_HDMI_Stop(E_MI_HDMI_ID_0), MI_SUCCESS);

    return MI_SUCCESS;
}

 MI_S32 St_VencModuleDeinit(Device_Handle_t *video_dev)
{
    ExecFunc(MI_VENC_StopRecvPic(0, 0), MI_SUCCESS);
	ExecFunc(MI_VENC_StopRecvPic(0, 1), MI_SUCCESS);
    ExecFunc(MI_VENC_DestroyChn(0, 0), MI_SUCCESS);
	ExecFunc(MI_VENC_DestroyChn(0, 1), MI_SUCCESS);

    return MI_SUCCESS;
}


MI_S32 St_BaseModuleDeinit(Device_Handle_t *video_dev)
{
    ST_Sys_BindInfo_T stSysBindInfo;
    memset(&stSysBindInfo, 0, sizeof(stSysBindInfo));

    switch(video_dev->pixelformat)
    {
        case V4L2_PIX_FMT_YUYV:
            stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);

            ExecFunc(St_HdmiModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_DispModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_SclModuleDeinit(video_dev), MI_SUCCESS);
            break;

        case V4L2_PIX_FMT_NV12:
            ExecFunc(St_HdmiModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_DispModuleDeinit(video_dev), MI_SUCCESS);
            break;

        case V4L2_PIX_FMT_MJPEG:
			//KJD_RtspServerStop();

			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
            stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
            /* bind scl and disp */
            stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = 1;
            stSysBindInfo.stDstChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
         //   ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);



			

			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 1;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stDstChnPort.u32DevId = 3;
            stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = 0;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = 3;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 0;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
			

			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 2;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
            stSysBindInfo.stDstChnPort.u32DevId = 0;
            stSysBindInfo.stDstChnPort.u32ChnId = 0;
            stSysBindInfo.stDstChnPort.u32PortId = 0;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);

			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = 3;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
            stSysBindInfo.stDstChnPort.u32DevId = 0;
            stSysBindInfo.stDstChnPort.u32ChnId = 1;
            stSysBindInfo.stDstChnPort.u32PortId = 0;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);

			ExecFunc(St_VencModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_HdmiModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_DispModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_SclModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_JpdModuleDeinit(video_dev), MI_SUCCESS);
            break;

        case V4L2_PIX_FMT_H264:
        case V4L2_PIX_FMT_H265:
            stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VDEC;
            stSysBindInfo.stSrcChnPort.u32DevId = VDEC_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = VDEC_CHN_ID;
            stSysBindInfo.stSrcChnPort.u32PortId = VDEC_PORT_ID;
            stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysBindInfo.stDstChnPort.u32DevId = DISP_DEV_ID;
            stSysBindInfo.stSrcChnPort.u32ChnId = DISP_CHN_ID;
            stSysBindInfo.stDstChnPort.u32PortId = DISP_PORT_ID;
            stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
            stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
            stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
            ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);

            ExecFunc(St_HdmiModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_DispModuleDeinit(video_dev), MI_SUCCESS);
            ExecFunc(St_VdecModuleDeinit(video_dev), MI_SUCCESS);
            break;

        default:
            break;
    }

    ExecFunc(ST_Sys_Exit(), MI_SUCCESS);

    return MI_SUCCESS;
}


void fp_convert(void *addr,int src_width,int src_height)
{  
	uint8_t * src_Y = NULL;
	int i;
	int j;
 	// 拷贝Y数据
	for( i = 0; i < src_height; i ++ )
	{
		// 计算 dest 每行的起始位置
		src_Y = (uint8_t *)addr  + i*src_width;
		for( j = 0; j < src_width ;j +=4)
		{	
			*src_Y = ~*src_Y;
			src_Y++;
			*src_Y = ~*src_Y;
			src_Y++;
			*src_Y = ~*src_Y;
			src_Y++;
			*src_Y = ~*src_Y;
			src_Y++;
		}
	}
	//printf(" start  fp_convert = %d! \n",i*j );
}


static void * kjd_manual_scl(void *arg)
{
	MI_SYS_ChnPort_t stChnPort;
	MI_SYS_BufInfo_t stBufInfo;
    MI_SYS_BUF_HANDLE hHandle;
	MI_SYS_ChnPort_t sclChnPort;
	MI_SYS_BufConf_t stSysBufConf;
	struct timeval stTv;
	MI_SYS_BufInfo_t stSysBufInfo;
    MI_SYS_BUF_HANDLE stSysBufHandle;
	MI_S32 s32Ret;
	int width = 0;
	int height = 0;



	memset(&stSysBufConf, 0, sizeof(stSysBufConf));
	memset(&stSysBufInfo, 0, sizeof(stSysBufInfo));
    memset(&stSysBufHandle, 0, sizeof(stSysBufHandle));

	

	memset(&stChnPort, 0x0, sizeof(MI_SYS_ChnPort_t));
    stChnPort.eModId = E_MI_MODULE_ID_SCL;
    stChnPort.u32DevId = 1;
    stChnPort.u32ChnId = 0;
    stChnPort.u32PortId = 1;
    
	while(MI_SUCCESS != MI_SYS_SetChnOutputPortDepth(0, &stChnPort, 2, 3))
	{
	    ST_ERR("MI_SYS_SetChnOutputPortDepth err:%x, chn:%d,port:%d\n", s32Ret,
	        stChnPort.u32ChnId, stChnPort.u32PortId);
		usleep(1*1000*1000);
	}




	
	while (!fp_g_exit)
	{
		if(g_stream == true || pvideo_dev->width == 0)
    	{
    		usleep(1000*100);
			continue;
    	}
		else
		{
			width = pvideo_dev->width;
			height = pvideo_dev->height;
		}


		s32Ret = MI_SYS_ChnOutputPortGetBuf(&stChnPort, &stBufInfo, &hHandle);
		if (MI_SUCCESS == s32Ret)
	    {
	    	
	    	memset(&sclChnPort, 0x0, sizeof(MI_SYS_ChnPort_t));
		    sclChnPort.eModId = E_MI_MODULE_ID_SCL;
		    sclChnPort.u32DevId = 3;
		    sclChnPort.u32ChnId = SCL_CHN_ID;
		    sclChnPort.u32PortId = 0;


	        stSysBufConf.eBufType = E_MI_SYS_BUFDATA_FRAME;
	        gettimeofday(&stTv, NULL);
	        stSysBufConf.u64TargetPts = stTv.tv_sec*1000000 + stTv.tv_usec;
	        stSysBufConf.stFrameCfg.eFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	        stSysBufConf.stFrameCfg.eFrameScanMode = E_MI_SYS_FRAME_SCAN_MODE_PROGRESSIVE;
	        stSysBufConf.stFrameCfg.u16Width = width;
	        stSysBufConf.stFrameCfg.u16Height = height;

	        s32Ret = MI_SYS_ChnInputPortGetBuf(&sclChnPort, &stSysBufConf, &stSysBufInfo, &stSysBufHandle, -1);
	        if(MI_SUCCESS != s32Ret)
	        {
	            printf( "MI_SYS_ChnInputPortGetBuf: 0x%x.\n", s32Ret);
				continue;
	        }

	        stSysBufInfo.bEndOfStream = true;
	        memcpy(stSysBufInfo.stFrameData.pVirAddr[0], stBufInfo.stFrameData.pVirAddr[0], stBufInfo.stFrameData.u32BufSize);



			fp_convert(stSysBufInfo.stFrameData.pVirAddr[0],width,height);

	        s32Ret = MI_SYS_ChnInputPortPutBuf(stSysBufHandle ,&stSysBufInfo , false);
	        if(MI_SUCCESS != s32Ret)
	        {
	            printf("MI_SYS_ChnInputPortPutBuf: 0x%x.\n", s32Ret);
				continue;
	        }
		
	        MI_SYS_ChnOutputPortPutBuf(hHandle);



		}
		else
		{
			printf(" jpd  MI_SYS_ChnOutputPortGetBuf fail : 0x%x.\n", s32Ret);
		}
		usleep(30* 1000);

	}


	return NULL;
}

int k = 0;

static int photoIndex = 0;
static MI_S32 St_Start_Display(Device_Handle_t *video_dev, Stream_Buffer_t *video_buf)
{
    MI_S32 s32Ret;
    struct timeval stTv;

    MI_SYS_ChnPort_t stSysChnPort;
    MI_SYS_BufConf_t stSysBufConf;
    MI_SYS_BufInfo_t stSysBufInfo;
    MI_SYS_BUF_HANDLE stSysBufHandle;
    MI_JPD_StreamBuf_t stJpdStreamBuf;
    MI_VDEC_VideoStream_t stVdecVideoStream;

    memset(&stSysChnPort, 0, sizeof(stSysChnPort));
    memset(&stSysBufConf, 0, sizeof(stSysBufConf));
    memset(&stSysBufInfo, 0, sizeof(stSysBufInfo));
    memset(&stSysBufHandle, 0, sizeof(stSysBufHandle));
    memset(&stJpdStreamBuf, 0, sizeof(stJpdStreamBuf));
    memset(&stVdecVideoStream, 0, sizeof(stVdecVideoStream));

#if 1
	if (g_i_MainCam == 1)//(主视频为usb摄像头)
	{
			if (g_i_TakePhoto == 1){ 

				//if (g_i_Read_PhotoFileIndex_Flag == 0)
				{
					g_i_Read_PhotoFileIndex_Flag = 1;
					FILE* mFd = fopen("/mnt/Sys/PhotoFileIndex","rb+");
					if(mFd == NULL)
					{
						 mFd = fopen("/mnt/Sys/PhotoFileIndex","wb+");
						 if(mFd == NULL)
						 {
							printf("---------------------PhotoFileIndex open false !------------------------------\n");
						 }
						 fwrite(&g_i_PhotoFileIndex,1,sizeof(int),mFd);
						 fclose(mFd);
						 mFd = NULL;
					}
					else
					{
						 fread(&g_i_PhotoFileIndex,1,sizeof(int),mFd);
						 g_i_PhotoFileIndex--;
						 fseek(mFd,0,SEEK_SET);
						 fwrite(&g_i_PhotoFileIndex,1,sizeof(int),mFd);
						 fclose(mFd);
						 mFd = NULL;
					}
				}

				time_t now = 0;
				struct tm *tm = NULL;
				MI_U32 len = 0;
				char szFilePathName[120];

				memset(g_szFileName, 0, sizeof(g_szFileName));
				now = time(NULL);
				tm = localtime(&now);
				len = 0;

				len += sprintf(g_szFileName + len, "%08d_", g_i_PhotoFileIndex);
				len += sprintf(g_szFileName + len, "%d_", tm->tm_year + 1900);
				len += sprintf(g_szFileName + len, "%02d_", tm->tm_mon + 1);
				len += sprintf(g_szFileName + len, "%02d_", tm->tm_mday);
				len += sprintf(g_szFileName + len, "%02d_", tm->tm_hour);
				len += sprintf(g_szFileName + len, "%02d_", tm->tm_min);
				len += sprintf(g_szFileName + len, "%02d", tm->tm_sec);
				len += sprintf(g_szFileName + len, ".%s", "jpg");

				sprintf(szFilePathName,"%s%s",PATH_PHOTO,g_szFileName);

				if (g_Fd != NULL)
				{
					fclose(g_Fd);
					g_Fd = NULL;
				}

				g_Fd = fopen(szFilePathName,"wb+");
				if(g_Fd == NULL)
				{
					printf("---------------------open false !------------------------------\n");
					 /*system("mkdir /mnt/Photo");
					 g_Fd = fopen(szFilePathName,"ab+");
					 if(g_Fd == NULL)
					 {
						printf("---------------------open false !------------------------------\n");
					 }*/
				}
			}
	}
#endif

    switch(video_dev->pixelformat)
    {
        case V4L2_PIX_FMT_YUYV:
            stSysChnPort.eModId = E_MI_MODULE_ID_SCL;
            stSysChnPort.u32DevId = SCL_DEV_ID;
            stSysChnPort.u32ChnId = SCL_CHN_ID;
            stSysChnPort.u32PortId = SCL_PORT_ID;

            stSysBufConf.eBufType = E_MI_SYS_BUFDATA_FRAME;
            gettimeofday(&stTv, NULL);
            stSysBufConf.u64TargetPts = stTv.tv_sec*1000000 + stTv.tv_usec;
            stSysBufConf.stFrameCfg.eFormat = E_MI_SYS_PIXEL_FRAME_YUV422_YUYV;
            stSysBufConf.stFrameCfg.eFrameScanMode = E_MI_SYS_FRAME_SCAN_MODE_PROGRESSIVE;
            stSysBufConf.stFrameCfg.u16Width = video_dev->width;
            stSysBufConf.stFrameCfg.u16Height = video_dev->height;

        	if (g_i_MainCam == 1)//(主视频为usb摄像头)
			{
					if (g_i_TakePhoto == 1){ 
						if (g_Fd != NULL)
						{
							fclose(g_Fd);
							g_Fd = NULL;
						}
						g_i_TakePhoto = 2;
					}
			}

            s32Ret = MI_SYS_ChnInputPortGetBuf(&stSysChnPort, &stSysBufConf, &stSysBufInfo, &stSysBufHandle, -1);
            if(MI_SUCCESS != s32Ret)
            {
                UVC_ERR(video_dev, "MI_SYS_ChnInputPortGetBuf: 0x%x.\n", s32Ret);
                return -1;
            }

            stSysBufInfo.bEndOfStream = true;
            memcpy(stSysBufInfo.stFrameData.pVirAddr[0], video_buf->buf, video_buf->length);

			

            s32Ret = MI_SYS_ChnInputPortPutBuf(stSysBufHandle ,&stSysBufInfo , false);
            if(MI_SUCCESS != s32Ret)
            {
                UVC_ERR(video_dev, "MI_SYS_ChnInputPortPutBuf: 0x%x.\n", s32Ret);
                return -1;
            }
            break;

        case V4L2_PIX_FMT_NV12:
            stSysChnPort.eModId = E_MI_MODULE_ID_DISP;
            stSysChnPort.u32DevId = DISP_DEV_ID;
            stSysChnPort.u32ChnId = DISP_CHN_ID;
            stSysChnPort.u32PortId = DISP_PORT_ID;

            stSysBufConf.eBufType = E_MI_SYS_BUFDATA_FRAME;
            gettimeofday(&stTv, NULL);
            stSysBufConf.u64TargetPts = stTv.tv_sec*1000000 + stTv.tv_usec;
            stSysBufConf.stFrameCfg.eFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
            stSysBufConf.stFrameCfg.eFrameScanMode = E_MI_SYS_FRAME_SCAN_MODE_PROGRESSIVE;
            stSysBufConf.stFrameCfg.u16Width = video_dev->width;
            stSysBufConf.stFrameCfg.u16Height = video_dev->height;

		    if (g_i_MainCam == 1)//(主视频为usb摄像头)
			{
				   if (g_i_TakePhoto == 1){ 
						if (g_Fd != NULL)
						{
							fclose(g_Fd);
							g_Fd = NULL;
						}
						g_i_TakePhoto = 2;
					}
			}

            s32Ret = MI_SYS_ChnInputPortGetBuf(&stSysChnPort,&stSysBufConf,&stSysBufInfo,&stSysBufHandle, -1);
            if(MI_SUCCESS != s32Ret)
            {
                UVC_ERR(video_dev, "MI_SYS_ChnInputPortGetBuf: 0x%x.\n", s32Ret);
                return -1;
            }

            stSysBufInfo.bEndOfStream = true;
            memcpy(stSysBufInfo.stFrameData.pVirAddr[0], video_buf->buf, video_buf->length);

            s32Ret = MI_SYS_ChnInputPortPutBuf(stSysBufHandle ,&stSysBufInfo , false);
            if(MI_SUCCESS != s32Ret)
            {
                UVC_ERR(video_dev, "MI_SYS_ChnInputPortPutBuf: 0x%x.\n", s32Ret);
                return -1;
            }
            break;

        case V4L2_PIX_FMT_MJPEG:
            s32Ret = MI_JPD_GetStreamBuf(JPD_DEV_ID, JPD_CHN_ID, video_buf->length, &stJpdStreamBuf, -1);
            if(MI_SUCCESS != s32Ret)
            {
                UVC_ERR(video_dev, "MI_JPD_GetStreamBuf: 0x%x.\n", s32Ret);
                return -1;
            }

            memcpy(stJpdStreamBuf.pu8HeadVirtAddr, video_buf->buf, MIN(stJpdStreamBuf.u32HeadLength, video_buf->length));
			
			g_i_Display = 1;

        	if (g_i_MainCam == 1)//(主视频为usb摄像头)
			{
					if (g_i_TakePhoto == 1){ 
						if (g_Fd != NULL)
						{
							fwrite(video_buf->buf ,1, video_buf->length,g_Fd);
							fclose(g_Fd);
							g_Fd = NULL;
						}
						g_i_TakePhoto = 2;
					}
			}

            if(stJpdStreamBuf.u32HeadLength + stJpdStreamBuf.u32TailLength < video_buf->length)
            {
                UVC_ERR(video_dev, "MI_JPD_GetStreamBuf return wrong value: HeadLen%u TailLen%u RequiredLength%u.\n",
                        stJpdStreamBuf.u32HeadLength, stJpdStreamBuf.u32TailLength, video_buf->length);

                s32Ret = MI_JPD_DropStreamBuf(JPD_DEV_ID, JPD_CHN_ID, &stJpdStreamBuf);
                if(MI_SUCCESS != s32Ret)
                {
                    UVC_ERR(video_dev, "MI_JPD_DropStreamBuf: 0x%x.", s32Ret);
                    return -1;
                }

                return -1;
            }
            else if(stJpdStreamBuf.u32TailLength > 0)
            {
                memcpy(stJpdStreamBuf.pu8TailVirtAddr, video_buf->buf + stJpdStreamBuf.u32HeadLength,
                       MIN(stJpdStreamBuf.u32TailLength, video_buf->length - stJpdStreamBuf.u32HeadLength));
				
            }

            stJpdStreamBuf.u32ContentLength = video_buf->length;
            s32Ret = MI_JPD_PutStreamBuf(JPD_DEV_ID, JPD_CHN_ID, &stJpdStreamBuf);
            if(MI_SUCCESS != s32Ret)
            {
                UVC_ERR(video_dev, "MI_JPD_PutStreamBuf: 0x%x.\n", s32Ret);
                return -1;
            }
            break;

        case V4L2_PIX_FMT_H264:
        case V4L2_PIX_FMT_H265:
            stVdecVideoStream.bEndOfFrame = true;
            stVdecVideoStream.bEndOfStream = false;
            stVdecVideoStream.pu8Addr = (MI_U8 *)video_buf->buf;
            stVdecVideoStream.u32Len = video_buf->length;
            stVdecVideoStream.u64PTS = -1;
            s32Ret = MI_VDEC_SendStream(VDEC_DEV_ID, VDEC_CHN_ID, &stVdecVideoStream, -1);
            if(MI_SUCCESS != s32Ret)
            {
                UVC_ERR(video_dev, "MI_VDEC_SendStream: 0x%x.\n", s32Ret);
                return -1;
            }
            break;

        default:
            break;
    }

    return MI_SUCCESS;
}

static MI_S32 rtsp_Start_Display(Device_Handle_t *video_dev, Stream_Buffer_t *video_buf)
{
	


    return MI_SUCCESS;
}


static void Sig_Handler(int signum)
{
    if(signum == SIGINT)
    {
        printf("catch Ctrl + C, exit normally.\n");
        g_exit = true;
    }
}



static void usb_remove(int signum)
{
    if(signum == SIGUSR1)
    {
        printf("usb_remove\n");
    }
}




static void help_message(char **arg)
{
    printf("\n");
    printf("usage: %s\n", arg[0]);
    printf(" -a: stream on/off automatical\n");
    printf(" -b: v4l2 buffer count(default 3)\n");
    printf(" -m: run mode [1]:Stream(default) [2]:Control [3]:both\n");
    printf(" -n: /dev/videoX(default 0)\n");
    printf(" -d: display [0]:disable(default) [1]:enable(rely on MI)\n");
    printf(" -h: help message\n");
    printf("\nExample: %s -n1(open /dev/video1) -b5(request 5 v4l2 buffers) -m1(only get stream, don't send control) -a(restart stream after getting 200 frames) -d1(enable display)\n", arg[0]);
    printf("\n");
}

static void *close_thread(void *arg)
{
	FILE *File;
	char readBuf[1024] = {0};
	int i = 0;


	//printf("%c\n",readBuf[35]);
	while(1)
	{
		File = popen("/customer/riu_r 0x34 12","r");
    	fread(readBuf,1024,1,File);
		pclose(File);

		if(readBuf[35] == '4')
		{
			i++;
			if( i == 4 )
			{
				break;
			}
		}
		else
		{
			i = 0;
		}
		usleep(1000*500);
	}
	//printf("%s\n",readBuf);
	system("poweroff");
	pthread_exit(&close_mem);
}



static void *interrupt_ok(void *arg)
{
    char buff[1024];
    int gpio_id;
    struct pollfd fds[1];
	ADC_CONFIG_READ_ADC stCfg;
	int sar_fd = -1;
    int chn = 0;
	int ret = 0;


	sar_fd= open("/dev/sar", /*O_RDONLY*/O_RDWR);
	if (sar_fd < 0)
    {
        perror("/dev/sar open error\n");
    }
	ioctl(sar_fd, MS_SAR_INIT, 0);
	memset(&stCfg, 0, sizeof(ADC_CONFIG_READ_ADC));
	stCfg.channel_value=0;  ///SAR0
	

/*	system("echo 21 > /sys/class/gpio/export");
	system("echo in > /sys/class/gpio/gpio21/direction");
	system("echo rising > /sys/class/gpio/gpio21/edge");

	int gpio_fd = open("/sys/class/gpio/gpio21/value", O_RDONLY);
    if (gpio_fd == -1)
        printf("gpio open fail\n");
	fds[0].fd = gpio_fd;
    fds[0].events = POLLPRI;
	ret = read(gpio_fd, buff, 10);
    if (ret == -1)
        printf("read fail\n");

    while (1)
    {
        ret = poll(fds, 1, -1);
        if (ret == -1)
            printf("poll fail\n");

        if (fds[0].revents & POLLPRI)
        {
			ret = lseek(gpio_fd, 0, SEEK_SET);
            if (ret == -1)
                printf("lseek fail\n");
            ret = read(gpio_fd, buff, 10);
            if (ret == -1)
                printf("read fail \n");
            printf("get interrupt %s\n",buff);
			
			
        }
    }*/
	while(1)
	{
		ioctl(sar_fd, MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg);
		if(stCfg.adc_value > 400 && stCfg.adc_value <= 410)
		{
			printf("menu read stCfg.adc_value=:%d\n", stCfg.adc_value);
			while(stCfg.adc_value < 1000 )
			{
				ioctl(sar_fd, MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg);
			}
		}
		else if (stCfg.adc_value > 600 && stCfg.adc_value <= 610)
		{
			printf("up read stCfg.adc_value=:%d\n", stCfg.adc_value);
			while(stCfg.adc_value < 1000 )
			{
				ioctl(sar_fd, MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg);
			}

		}
		else if (stCfg.adc_value > 730 && stCfg.adc_value <= 740)
		{
			printf("down read stCfg.adc_value=:%d\n", stCfg.adc_value);
			while(stCfg.adc_value < 1000 )
			{
				ioctl(sar_fd, MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg);
			}

		}
		else if (stCfg.adc_value > 840 && stCfg.adc_value <= 850)
		{
			printf("ok read stCfg.adc_value=:%d\n", stCfg.adc_value);
			while(stCfg.adc_value < 1000 )
			{
				ioctl(sar_fd, MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg);
			}

		}
		else if (stCfg.adc_value > 930 && stCfg.adc_value <= 940)
		{
			printf("bri read stCfg.adc_value=:%d\n", stCfg.adc_value);
			while(stCfg.adc_value < 1000 )
			{
				ioctl(sar_fd, MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg);
			}

		}
		usleep(1000*50);
	}

	pthread_exit(&ret);

}

//改变分辨率
char change_scl_resolution(int width,int height,MI_SCL_DEV DevId, MI_SCL_CHANNEL ChnId, MI_SCL_PORT PortId)
{
	MI_SCL_OutPortParam_t stSCLOutPortParam;


    memset(&stSCLOutPortParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
	MI_SCL_DisableOutputPort(DevId, ChnId, PortId);
	MI_SCL_GetOutputPortParam(DevId,ChnId, PortId, &stSCLOutPortParam);
	stSCLOutPortParam.stSCLOutputSize.u16Width = width;
    stSCLOutPortParam.stSCLOutputSize.u16Height = height;
	MI_SCL_SetOutputPortParam(DevId, ChnId, PortId, &stSCLOutPortParam);
    MI_SCL_EnableOutputPort(DevId, ChnId, PortId);
}

//改变分辨率和旋转角度和水平翻转和垂直翻转
void change_scl_resolution_rotate(int width,int height,MI_SYS_Rotate_e rot,bool bMirror,bool bFlip)
{
	MI_SCL_ChnParam_t stSclChnParam;
	MI_SCL_OutPortParam_t stSCLOutPortParam;


    memset(&stSCLOutPortParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
	MI_SCL_DisableOutputPort(3, SCL_CHN_ID, SCL_PORT_ID);
	MI_SCL_StopChannel(3,SCL_CHN_ID);

	MI_SCL_GetChnParam(3,SCL_CHN_ID,&stSclChnParam);
	stSclChnParam.eRot = rot;
	MI_SCL_GetOutputPortParam(3,SCL_CHN_ID, SCL_PORT_ID, &stSCLOutPortParam);
	stSCLOutPortParam.stSCLOutputSize.u16Width = width;
    stSCLOutPortParam.stSCLOutputSize.u16Height = height;
    stSCLOutPortParam.bMirror = bMirror;
    stSCLOutPortParam.bFlip = bFlip;

    MI_SCL_SetChnParam(3, SCL_CHN_ID, &stSclChnParam);
    MI_SCL_StartChannel(3, SCL_CHN_ID);
	MI_SCL_SetOutputPortParam(3, SCL_CHN_ID, SCL_PORT_ID, &stSCLOutPortParam);
    MI_SCL_EnableOutputPort(3, SCL_CHN_ID, SCL_PORT_ID);
}


/*****************************************
函数名：change_BaseModuleInit
函数功能：改变模块的分辨率
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/

/*char change_BaseModuleInit(void)
{
	MI_RGN_ChnPort_t stChnPort;
    MI_RGN_ChnPortParam_t stChnPortParam;
	
	//change_scl_resolution(pvideo_dev->width,pvideo_dev->height,SCL_DEV_ID,SCL_CHN_ID, SCL_PORT_ID);
	change_scl_resolution(pvideo_dev->height,pvideo_dev->width,3, SCL_CHN_ID, SCL_PORT_ID);
	change_scl_resolution(pvideo_dev->width,pvideo_dev->height,SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID);//hdmi
	change_scl_resolution(pvideo_dev->width,pvideo_dev->height,SCL_DEV_ID, SCL_CHN_ID, 1);//panel
	change_scl_resolution(pvideo_dev->width,pvideo_dev->height,SCL_DEV_ID, SCL_CHN_ID, 2);//rtsp
	change_scl_resolution(pvideo_dev->width,pvideo_dev->height,SCL_DEV_ID, SCL_CHN_ID, 3);//mp4


	//disp
	MI_DISP_PubAttr_t stDispPubAttr;
    MI_DISP_VideoLayerAttr_t stDispLayerAttr;
    MI_DISP_InputPortAttr_t stDispInputPortAttr;


	ExecFunc(MI_DISP_DisableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_DisableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_UnBindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_Disable(DISP_DEV_ID), MI_SUCCESS);

	ExecFunc(MI_DISP_DisableInputPort(2, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_DisableVideoLayer(2), MI_SUCCESS);
    ExecFunc(MI_DISP_UnBindVideoLayer(2, 1), MI_SUCCESS);
    ExecFunc(MI_DISP_Disable(1), MI_SUCCESS);
	//MI_PANEL_DeInit();



	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
	stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = scl3_height;
    stDispLayerAttr.stVidLayerDispWin.u16Width = scl3_width;
    stDispLayerAttr.stVidLayerDispWin.u16X = (720-scl3_width)/2;
    stDispLayerAttr.stVidLayerDispWin.u16Y = (1280-scl3_height)/2;
    stDispLayerAttr.stVidLayerSize.u16Height = scl3_height;
    stDispLayerAttr.stVidLayerSize.u16Width = scl3_width;
    stDispInputPortAttr.stDispWin.u16Height = scl3_height;
    stDispInputPortAttr.stDispWin.u16Width = scl3_width;
    stDispInputPortAttr.stDispWin.u16X = (720-scl3_width)/2;
    stDispInputPortAttr.stDispWin.u16Y = (1280-scl3_height)/2;
    stDispInputPortAttr.u16SrcHeight = scl3_height;
    stDispInputPortAttr.u16SrcWidth = scl3_width;

    ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID,DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(DISP_LAYER_ID, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(DISP_LAYER_ID, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(DISP_LAYER_ID, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);

	//ST_InitMipiOut();
	//MI_PANEL_Init(E_MI_PNL_INTF_MIPI_DSI);

	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));

    stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_1080P60;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_HDMI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 1080;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1920;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
    stDispLayerAttr.stVidLayerSize.u16Height = 1080;
    stDispLayerAttr.stVidLayerSize.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16Height = 1080;
    stDispInputPortAttr.stDispWin.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16X = 0;
    stDispInputPortAttr.stDispWin.u16Y = 0;
    stDispInputPortAttr.u16SrcHeight = pvideo_dev->height;
    stDispInputPortAttr.u16SrcWidth = pvideo_dev->width;

    ExecFunc(MI_DISP_SetPubAttr(1, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(1), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(2,1), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(2, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(2), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(2, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(2, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(2, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);
	


	//venc
	MI_VENC_DEV VeDev = MI_VENC_DEV_ID_H264_H265_0;
    MI_VENC_CHN VeChn = 0;
	MI_VENC_ChnAttr_t ChnAttr_t;
	memset(&ChnAttr_t, 0, sizeof(ChnAttr_t));

	MI_VENC_GetChnAttr(VeDev,VeChn,&ChnAttr_t);
	ChnAttr_t.stVeAttr.stAttrH264e.u32PicWidth = pvideo_dev->width;
	ChnAttr_t.stVeAttr.stAttrH264e.u32PicHeight = pvideo_dev->height;
	MI_VENC_SetChnAttr(VeDev,VeChn,&ChnAttr_t);
	MI_VENC_GetChnAttr(VeDev,1,&ChnAttr_t);
	ChnAttr_t.stVeAttr.stAttrH264e.u32PicWidth = pvideo_dev->width;
	ChnAttr_t.stVeAttr.stAttrH264e.u32PicHeight = pvideo_dev->height;
	MI_VENC_SetChnAttr(VeDev,1,&ChnAttr_t);

	if(g_stRgnOsd.bRun == false)
	{
		//重启osd水印线程
		memset(&stChnPort, 0, sizeof(MI_RGN_ChnPort_t));
	    stChnPort.eModId = E_MI_MODULE_ID_SCL;
	    stChnPort.s32DevId = 1;
	    stChnPort.s32ChnId = SCL_CHN_ID;
	    stChnPort.s32PortId = 3;
	    memset(&stChnPortParam, 0, sizeof(MI_RGN_ChnPortParam_t));
	    stChnPortParam.bShow = TRUE;
	    stChnPortParam.stPoint.u32X = 100;
	    stChnPortParam.stPoint.u32Y = pvideo_dev->height - 100;
	    stChnPortParam.unPara.stOsdChnPort.u32Layer = 0;
	    stChnPortParam.unPara.stOsdChnPort.stOsdAlphaAttr.eAlphaMode = E_MI_RGN_PIXEL_ALPHA;
	    stChnPortParam.unPara.stOsdChnPort.stOsdAlphaAttr.stAlphaPara.stArgb1555Alpha.u8BgAlpha = 0;
	    stChnPortParam.unPara.stOsdChnPort.stOsdAlphaAttr.stAlphaPara.stArgb1555Alpha.u8FgAlpha = 0xFF;
	    ExecFunc(MI_RGN_AttachToChn(0,RGN_OSD_HANDLE, &stChnPort, &stChnPortParam), MI_RGN_OK);

		g_stRgnOsd.bRun = TRUE;
	    pthread_create(&g_stRgnOsd.pt, NULL, ST_UpdateRgnOsdProcExt, NULL);
	}
	
}
*/


/*****************************************
函数名：change_BaseModuleInit
函数功能：改变模块的分辨率
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/

char change_BaseModuleInit(Device_Handle_t *video_dev)
{

	/*MI_U32 SCL_DEV_ID = 1;
	MI_U32 SCL_CHN_ID = 0;
	MI_U32 SCL_PORT_ID = 0;
	*/
	
//	change_scl_resolution(video_dev->width,video_dev->height,SCL_DEV_ID, SCL_CHN_ID, 1);//panel
	change_scl_resolution(1280,800,SCL_DEV_ID, SCL_CHN_ID, 1);//panel


	MI_SCL_OutPortParam_t stSCLOutPortParam;
	
	int iWidth = 1280;
	int iHeight = 800;


    memset(&stSCLOutPortParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
	MI_SCL_DisableOutputPort(SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID);
	MI_SCL_GetOutputPortParam(SCL_DEV_ID,SCL_CHN_ID, SCL_PORT_ID, &stSCLOutPortParam);
	
	stSCLOutPortParam.stSCLOutCropRect.u16X = 0;//(video_dev->width - iWidth)/2;
    stSCLOutPortParam.stSCLOutCropRect.u16Y = 0;//(video_dev->height - iHeight)/2;
	stSCLOutPortParam.stSCLOutCropRect.u16Width = 0;//iWidth;
    stSCLOutPortParam.stSCLOutCropRect.u16Height = 0;//iWidth;
	
    stSCLOutPortParam.stSCLOutputSize.u16Width = 1280;
    stSCLOutPortParam.stSCLOutputSize.u16Height = 800;
	MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID, &stSCLOutPortParam);
    MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, SCL_PORT_ID);



    //modify 20240204
	memset(&stSCLOutPortParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
	stSCLOutPortParam.stSCLOutCropRect.u16X = (video_dev->width - panel_width)/2;
    stSCLOutPortParam.stSCLOutCropRect.u16Y = (video_dev->height - panel_height)/2;
	stSCLOutPortParam.stSCLOutCropRect.u16Width = panel_width;
    stSCLOutPortParam.stSCLOutCropRect.u16Height = panel_width;
    stSCLOutPortParam.stSCLOutputSize.u16Width = 1280;//video_dev->width;//480
    stSCLOutPortParam.stSCLOutputSize.u16Height = 800;//video_dev->height;//480
    stSCLOutPortParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
	ExecFunc(MI_SCL_SetOutputPortParam(SCL_DEV_ID, SCL_CHN_ID, 1, &stSCLOutPortParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(SCL_DEV_ID, SCL_CHN_ID, 1), MI_SUCCESS);
	memset(&stSCLOutPortParam, 0x0, sizeof(MI_SCL_OutPortParam_t));
    //modify 20240204

	//disp
	MI_DISP_PubAttr_t stDispPubAttr;
    MI_DISP_VideoLayerAttr_t stDispLayerAttr;
    MI_DISP_InputPortAttr_t stDispInputPortAttr;


	ExecFunc(MI_DISP_DisableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_DisableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_UnBindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_Disable(DISP_DEV_ID), MI_SUCCESS);

	ExecFunc(MI_DISP_DisableInputPort(2, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_DisableVideoLayer(2), MI_SUCCESS);
    ExecFunc(MI_DISP_UnBindVideoLayer(2, 1), MI_SUCCESS);
    ExecFunc(MI_DISP_Disable(1), MI_SUCCESS);
	//MI_PANEL_DeInit();



	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
	stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 800;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1280;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
    stDispLayerAttr.stVidLayerSize.u16Height = 800;
    stDispLayerAttr.stVidLayerSize.u16Width = 1280;
    stDispInputPortAttr.stDispWin.u16Height = 800;
    stDispInputPortAttr.stDispWin.u16Width = 1280;
    stDispInputPortAttr.stDispWin.u16X = 0;
    stDispInputPortAttr.stDispWin.u16Y = 0;
    stDispInputPortAttr.u16SrcHeight = 800;
    stDispInputPortAttr.u16SrcWidth = 1280;

    ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID,DISP_DEV_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(DISP_LAYER_ID, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(DISP_LAYER_ID, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(DISP_LAYER_ID, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);



    memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));

    stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_1080P60;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_HDMI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 1080;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1920;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;
    stDispLayerAttr.stVidLayerSize.u16Height = 1080;
    stDispLayerAttr.stVidLayerSize.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16Height = 1080;
    stDispInputPortAttr.stDispWin.u16Width = 1920;
    stDispInputPortAttr.stDispWin.u16X = 0;
    stDispInputPortAttr.stDispWin.u16Y = 0;
    stDispInputPortAttr.u16SrcHeight = video_dev->height;
    stDispInputPortAttr.u16SrcWidth = video_dev->width;

    ExecFunc(MI_DISP_SetPubAttr(1, &stDispPubAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_Enable(1), MI_SUCCESS);
    ExecFunc(MI_DISP_BindVideoLayer(2,1), MI_SUCCESS);
    ExecFunc(MI_DISP_SetVideoLayerAttr(2, &stDispLayerAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableVideoLayer(2), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortAttr(2, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(2, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(2, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);
}


/*****************************************
函数名：uvc_stream
函数功能：摄像头流输出线程
函数参数：无
函数返回值：无
作者：陈钰
*****************************************/
/*void *uvc_stream(void *arg)
{
    int ret = 0;
	ST_SetGpioOut(8,0);
#if 0
		int back = ic_encryption();
		if(back == 0)
		{
			printf("IC success!\n");
		}
		else
		{
			printf("IC fail!\n");
			return NULL;
		}
#endif

	printf("========================3056============\n");
	memset(pvideo_dev, 0x0, sizeof(Device_Handle_t));
	char path[20] = {};
	g_device_index = 0;
    sprintf(path, "/dev/video%d", g_device_index);
    memcpy(pvideo_dev->path, path, 20);
	printf("========================3062============\n");

	//video 初始化
    while(video_init(pvideo_dev) != 0)
    {
        printf("video_init is fail!\n");
		g_device_index++;
		sprintf(path, "/dev/video%d", g_device_index);
    	memcpy(pvideo_dev->path, path, 20);
		
		//判断没摄像头设备
		if(g_device_index > 99)
		{
			usb_open_flag = false;
			break;
		}
		
    }
	printf("========================3080============\n");
	if(g_device_index < 99)
	{
		usb_open_flag = true;

		//获取初始化参数
	    ret = video_enum_format(pvideo_dev,change_proportion_flag);
	    if(ret != 0)
	        printf("video_enum_format is fail!\n");



		//设置初始化参数
	    ret = video_set_format(pvideo_dev);
	    if(ret != 0)
	        printf("video_set_format is fail!\n");

		//发送标准命令
		//video_enum_standard_control(video_dev);
	}
	printf("========================3101============\n");

	if(video_flag == true)
	{
		//mi 模块初始化
		video_flag = false;
	//	ret = St_BaseMipiModuleInitTest(pvideo_dev);
		ret = St_BaseMipiModuleInit(pvideo_dev);
	  //  ret = St_BaseModuleInit(pvideo_dev);
		if(ret != 0)
			printf("St_BaseModuleInit false!\n");
	//	if(usb_open_flag == false)
		//{
			//printf("usb_open_flag == false\n");
			//return NULL;
		//}
	}
	else
	{
		if(usb_open_flag == false)
			return NULL;
		change_BaseModuleInit(pvideo_dev);
		
	}
	printf("========================3119===========\n");

	//申请流buff空间
    ret = video_streamon(pvideo_dev, g_buf_cnt);
    if(ret != 0)
		printf("video_streamon false!\n");

    Stream_Buffer_t video_buf;
    memset(&video_buf, 0, sizeof(Stream_Buffer_t));

    double video_time_Start;
    double video_time_End ;

	double mi_time_Start;
    double mi_time_End ;

	video_time_Start = (double)clock();
	printf("========================3135============\n");

    while(!g_exit)
    {
    	if(g_stream == true)
    	{
    		usleep(1000*100);
			continue;
    	}
    	//获取video buf
        ret = video_get_buf(pvideo_dev, &video_buf);
        if(ret == 0)
        {
			//送流给mi
			video_time_End = (double)clock();
			//printf("##########video get stream  time = %lf ms\n",(video_time_End - video_time_Start )/1000.0);
			video_time_Start = (double)clock();
			mi_time_Start = (double)clock();
            St_Start_Display(pvideo_dev, &video_buf);
			mi_time_End = (double)clock();
			//printf("mi cast  time = %lf ms\n",(mi_time_End - mi_time_Start )/1000.0);
			//释放video buf
            video_put_buf(pvideo_dev, &video_buf);
        }
        else if(ret == -EAGAIN)
        	continue;
        else
    	{		
			//continue;
			printf("break successful!\n");
			usb_open_flag = false;
        	break;
        }

		
    }
	//释放流buf空间
    ret = video_streamoff(pvideo_dev);
    if(ret != 0)
        printf("video_streamoff false!\n");
	printf("========================3176============\n");


	//去初始化mi
    //ret = St_BaseModuleDeinit(&video_dev);
    //if(ret != 0)
	//	printf("St_BaseModuleDeinit false!\n");
	


    video_deinit(pvideo_dev);
	return NULL;

}
*/


/*****************************************
函数名：uvc_stream
函数功能：摄像头流输出线程
函数参数：无
函数返回值：无
作者：陈钰
*****************************************/
void *uvc_stream(void *arg)
{
    int ret = 0;
	ST_SetGpioOut(8,0);
#if 0
		int back = ic_encryption();
		if(back == 0)
		{
			printf("IC success!\n");
		}
		else
		{
			printf("IC fail!\n");
			return NULL;
		}
#endif

	printf("========================3056============\n");
	memset(pvideo_dev, 0x0, sizeof(Device_Handle_t));
	char path[20] = {};
	g_device_index = 0;
    sprintf(path, "/dev/video%d", g_device_index);
    memcpy(pvideo_dev->path, path, 20);
	printf("========================3062============\n");

	//video 初始化
    while(video_init(pvideo_dev) != 0)
    {
        printf("video_init is fail!\n");
		g_device_index++;
		sprintf(path, "/dev/video%d", g_device_index);
    	memcpy(pvideo_dev->path, path, 20);
		
		//判断没摄像头设备
		if(g_device_index > 99)
		{
			usb_open_flag = false;
			break;
		}
		
    }
	printf("========================3080============\n");
	if(g_device_index < 99)
	{
		usb_open_flag = true;

		//获取初始化参数
	    ret = video_enum_format(pvideo_dev,change_proportion_flag);
	    if(ret != 0)
	        printf("video_enum_format is fail!\n");



		//设置初始化参数
	    ret = video_set_format(pvideo_dev);
	    if(ret != 0)
	        printf("video_set_format is fail!\n");

		//发送标准命令
		//video_enum_standard_control(video_dev);
	}
	printf("========================3100============\n");


	if(video_flag == true)
	{
		//mi 模块初始化
		video_flag = false;

		if (iChangeSen == 0)
		   St_BaseInit(pvideo_dev);
		ret = St_BaseModuleInit(pvideo_dev);

		if(ret != 0)
			printf("St_BaseModuleInit false!\n");
		if(usb_open_flag == false)
		{
			iChangeSen = 1;//这里没有插usb摄像头，所以提前设置好为1
			return NULL;
		}
	}
	else
	{
		if(usb_open_flag == false)
			return NULL;
		change_BaseModuleInit(pvideo_dev);
		
	}
	printf("========================3119===========\n");

	//申请流buff空间
    ret = video_streamon(pvideo_dev, g_buf_cnt);
    if(ret != 0)
		printf("video_streamon false!\n");

    Stream_Buffer_t video_buf;
    memset(&video_buf, 0, sizeof(Stream_Buffer_t));

    double video_time_Start;
    double video_time_End ;

	double mi_time_Start;
    double mi_time_End ;

	video_time_Start = (double)clock();
	printf("========================3135============\n");

    SetCamToMainVideo(1);//设置Usb摄像头为主视频
    
    iChangeSen = 1;


	unsigned int  iId = 9963776; //亮度
	video_send_standard_control_qw(iId,&g_i_Usb_bright,CONTROL_SET);


    while(!g_exit)
    {
    	if(g_stream == true)
    	{
    		usleep(1000*100);
			continue;
    	}
    	//获取video buf
        ret = video_get_buf(pvideo_dev, &video_buf);
        if(ret == 0)
        {
			//送流给mi
			video_time_End = (double)clock();
			//printf("##########video get stream  time = %lf ms\n",(video_time_End - video_time_Start )/1000.0);
			video_time_Start = (double)clock();
			mi_time_Start = (double)clock();
            St_Start_Display(pvideo_dev, &video_buf);
			mi_time_End = (double)clock();
			//printf("mi cast  time = %lf ms\n",(mi_time_End - mi_time_Start )/1000.0);
			//释放video buf
            video_put_buf(pvideo_dev, &video_buf);
        }
        else if(ret == -EAGAIN)
        	continue;
        else
    	{		
			//continue;
			printf("break successful!\n");
			usb_open_flag = false;
        	break;
        }
    }
	//释放流buf空间
    ret = video_streamoff(pvideo_dev);
    if(ret != 0)
        printf("video_streamoff false!\n");
	printf("========================3176============\n");


	//去初始化mi
    //ret = St_BaseModuleDeinit(&video_dev);
    //if(ret != 0)
	//	printf("St_BaseModuleDeinit false!\n");
	
    video_deinit(pvideo_dev);

    ReleaseCam(1);//释放Usb摄像头


	return NULL;

}




static void *uvc_control(void *arg)
{
    int ret = 0;

    Device_Handle_t *video_dev = (Device_Handle_t *)arg;

    video_enum_standard_control(video_dev);

    while(!g_exit)
    {
        int data = REQUEST_IFRAME;
        /*ret = video_send_extension_control(video_dev,
                        UVC_VC_EXTENSION2_UNIT_ID,
                        CUS_XU_SET_ISP,
                        UVC_SET_CUR,
                        sizeof(data),
                        (void *)&data);
        if(ret != 0)
            break;

        printf("%s Send XU Success.\n", video_dev->path);*/

        unsigned int id = V4L2_CID_BASE;
        int value = 0;
        ret = video_send_standard_control(video_dev, id, &value, CONTROL_SET);
#if 0
        /* still have problems, uvc driver will not send get_cur repeatly */
        ret = video_send_standard_control(video_dev, id, &value, CONTROL_GET);
#endif
        if(ret != 0)
            break;

        printf("%s Send PU Success.\n", video_dev->path);

        sleep(3);
    }

    pthread_exit(&ret);
}


//冻结画面
void FreezeStream(int iFlag)
{
	if (g_stream == false)
	   g_stream = true;
	else
	   g_stream = false;	
}

int ST_SetGpioOut(int gpio, char val)
{
    char cmd[100] = {0};

    snprintf(cmd, sizeof(cmd), "echo %d > /sys/class/gpio/export", gpio);
    system(cmd);
    usleep(100 * 1000);
    snprintf(cmd, sizeof(cmd), "echo out > /sys/class/gpio/gpio%d/direction", gpio);
    system(cmd);
    usleep(100 * 1000);
    snprintf(cmd, sizeof(cmd), "echo %d > /sys/class/gpio/gpio%d/value", val, gpio);
    system(cmd);
    usleep(100 * 1000);

    return MI_SUCCESS;
}

int ST_GetGpioIn(int gpio)
{
    char cmd[100] = {0};

    snprintf(cmd, sizeof(cmd), "echo %d > /sys/class/gpio/export", gpio);
    system(cmd);
    usleep(100 * 1000);
    snprintf(cmd, sizeof(cmd), "echo in > /sys/class/gpio/gpio%d/direction", gpio);
    system(cmd);
    usleep(100 * 1000);
    snprintf(cmd, sizeof(cmd), "cat /sys/class/gpio/gpio%d/value > /customer/gpiovalue", gpio);
    system(cmd);
    usleep(100 * 1000);
	int f;
    f = open("/customer/gpiovalue", O_RDWR | O_APPEND | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
    printf("%d\n", f);
	char rbuf[12];
    int size;
    size = read(f, rbuf, sizeof(rbuf) - 1);
    printf("%d\n", size);
    rbuf[size] = '\0';
	printf("%c\n", rbuf[0]);
	if(rbuf[0] == '1')
	{
		printf("input high\n");
		return GPIO_IN_HIGH;
	}
	else{
		printf("input low\n");
    	return GPIO_IN_LOW;
	}
}




void ST_InitMipiOut (void) 
{
	//char cmd[100] = {0};

	//snprintf(cmd, sizeof(cmd), "echo %d > /sys/class/gpio/export", gpio);
	//ST_SetGpioOut(GPIO_PANEL_BL, 1);
	//ST_SetGpioOut(GPIO_PANEL_BL_ADJ, 1);
	system("/customer/riu_w 0x103c 0x74 0x0004");
	usleep(100 * 1000);
	system("echo 10 >/sys/class/pwm/pwmchip0/export");
	usleep(100 * 1000);
	system("echo 100000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm10/period");
	usleep(100 * 1000);
    system("echo 100000 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm10/duty_cycle");
	usleep(100 * 1000);
	system("echo 1 >/sys/devices/soc0/soc/1f203200.pwm/pwm/pwmchip0/pwm10/enable");
	ST_SetGpioOut(GPIO_PANEL_RST, 1);
	//ST_SetGpioOut(GPIO_MIPIOUT_SEL, 0);
	//usleep(100 * 1000);
	//system("/customer/riu_w 0x103c 0x64 1");
	
}

void *_ConnectWorkThread(void *args)
{
    int nTimeoutCnt = 200;               // timeout 10s
    MI_WLAN_Status_t status;
    WlanConnectInfo_t *pstConnInfo = (WlanConnectInfo_t*)args;
	WLAN_HANDLE g_wlanHdl = 1;

    memset(&status, 0, sizeof(MI_WLAN_Status_t));

    if (MI_WLAN_Init(&g_stParam))
    {
        printf("Wlan init failed, please ensure wlan module is enabled.\n");
    }
    system("ifconfig wlan0 up ");

    if (MI_WLAN_Open(&g_stOpenParam))
    {
        printf("wlan open failed\n");
    }
	
    MI_WLAN_Connect(&g_wlanHdl, &g_stConnectParam[0]);


	

    while (1)
    {
        if (nTimeoutCnt-- <= 0)
        {
            printf("connect failed, timeout\n");
            break;
        }

        static int i = 0;
        MI_WLAN_GetStatus(g_wlanHdl, &status);
        if (status.stStaStatus.state == WPA_COMPLETED)
        {
            printf("connect success: ssid=%s, ip=%s\n", (char*)status.stStaStatus.ssid, (char*)status.stStaStatus.ip_address);
			break;
        }
        usleep(100000);
    }

    return NULL;
}

void ST_Flush(void)
{
    char c;

    while((c = getchar()) != '\n' && c != EOF);
}


int cmdinit(void)
{
	printf("select 1: close mi_init \n");
    printf("select 2: open mi_init \n");
	printf("select 3: pause vdec \n");
	printf("select 4: play vdec \n");
	return 0;
}



NALU_t *AllocNALU(int buffersize)
{
    NALU_t *n;
    if ((n = (NALU_t*)calloc (1, sizeof (NALU_t))) == NULL)
    {
        printf("AllocNALU: n");
        exit(0);
    }
    n->max_size=buffersize;
    if ((n->buf = (char*)calloc (buffersize, sizeof (char))) == NULL)
    {
        free (n);
        printf ("AllocNALU: n->buf");
        exit(0);
    }
    return n;
}

static int FindStartCode2 (unsigned char *Buf)
{
    if((Buf[0] != 0) || (Buf[1] != 0) || (Buf[2] != 1))
        return 0;
    else
        return 1;
}

static int FindStartCode3 (unsigned char *Buf)
{
    if((Buf[0] != 0) || (Buf[1] != 0) || (Buf[2] != 0) || (Buf[3] != 1))
        return 0;
    else
        return 1;
}


int GetAnnexbNALU (NALU_t *nalu, MI_S32 chn)
{
    int pos = 0;
    int StartCodeFound, rewind;
    unsigned char *Buf;
    int info2 = 0, info3 = 0;

    if ((Buf = (unsigned char*)calloc (nalu->max_size , sizeof(char))) == NULL)
        printf ("GetAnnexbNALU: Could not allocate Buf memory\n");
    nalu->startcodeprefix_len=3;
    if (3 != fread (Buf, 1, 3, g_pStreamFile[chn]))
    {
        free(Buf);
        return 0;
    }
    info2 = FindStartCode2 (Buf);
    if(info2 != 1)
    {
        if(1 != fread(Buf+3, 1, 1, g_pStreamFile[chn]))
        {
            free(Buf);
            return 0;
        }
        info3 = FindStartCode3 (Buf);
        if (info3 != 1)
        {
            free(Buf);
            return -1;
        }
        else
        {
            pos = 4;
            nalu->startcodeprefix_len = 4;
        }
    }
    else
    {
        nalu->startcodeprefix_len = 3;
        pos = 3;
    }
    StartCodeFound = 0;
    info2 = 0;
    info3 = 0;
    while (!StartCodeFound)
    {
        if (feof (g_pStreamFile[chn]))
        {
            nalu->len = (pos-1)-nalu->startcodeprefix_len;
            memcpy (nalu->buf, &Buf[nalu->startcodeprefix_len], nalu->len);
            free(Buf);
            fseek(g_pStreamFile[chn], 0, 0);
            return pos-1;
        }
        Buf[pos++] = fgetc (g_pStreamFile[chn]);
        info3 = FindStartCode3(&Buf[pos-4]);
        if(info3 != 1)
            info2 = FindStartCode2(&Buf[pos-3]);
        StartCodeFound = (info2 == 1 || info3 == 1);
    }
    rewind = (info3 == 1) ? -4 : -3;
    if (0 != fseek (g_pStreamFile[chn], rewind, SEEK_CUR))
    {
        free(Buf);
        printf("GetAnnexbNALU: Cannot fseek in the bit stream file");
    }
    nalu->len = (pos+rewind);
    memcpy (nalu->buf, &Buf[0], nalu->len);
    free(Buf);
    return (pos+rewind);
}

void dump(NALU_t *n)
{
    if (!n)
        return;
    //printf(" len: %d  ", n->len);
    //printf("nal_unit_type: %x\n", n->nal_unit_type);
}

void FreeNALU(NALU_t *n)
{
    if (n)
    {
        if (n->buf)
        {
            free(n->buf);
            n->buf=NULL;
        }
        free (n);
    }
}


void *ST_VdecSendStream(void *args)
{
	int ret = 0;
	MI_SYS_ChnPort_t stChnPort;
    MI_SYS_BufConf_t stBufConf;
    MI_SYS_BufInfo_t stBufInfo;
    MI_SYS_BUF_HANDLE hSysBuf;
    MI_S32 s32Ret = MI_SUCCESS;
    MI_VDEC_CHN vdecChn = 0;
    MI_S32 s32TimeOutMs = 20, s32ChannelId = 0, s32TempHeight = 0;
    MI_S32 s32Ms = 30;
    MI_BOOL bVdecChnEnable;
    MI_U16 u16Times = 20000;

    MI_S32 s32ReadCnt = 0;
    FILE *readfp = NULL;
    MI_U8 *pu8Buf = NULL;
    MI_S32 s32Len = 0;
    MI_U32 u32FrameLen = 0;
    MI_U64 u64Pts = 0;
    MI_U8 au8Header[32] = {0};
    MI_U32 u32Pos = 0;
    MI_VDEC_ChnStat_t stChnStat;
    MI_VDEC_VideoStream_t stVdecStream;

    MI_U32 u32FpBackLen = 0; // if send stream failed, file pointer back length

    VDEC_Thread_Args_t *pstArgs = (VDEC_Thread_Args_t *)args;

    char tname[32];
    memset(tname, 0, 32);

    NALU_t *n;
    if (!pstArgs->bEsAddHead)
        n = AllocNALU(2000000);

    vdecChn = pstArgs->vdecChn;
    snprintf(tname, 32, "push_t_%u", vdecChn);
    prctl(PR_SET_NAME, tname);

    memset(&stChnPort, 0x0, sizeof(MI_SYS_ChnPort_t));
    stChnPort.eModId = E_MI_MODULE_ID_VDEC;
    stChnPort.u32DevId = 0;
    stChnPort.u32ChnId = vdecChn;//0 1 2 3
    stChnPort.u32PortId = 0;

    readfp = fopen(pstArgs->szFileName, "rb"); //ES
    if (!readfp)
    {
        ST_ERR("Open %s failed!\n", pstArgs->szFileName);
        return NULL;
    }
    else
    {
        g_pStreamFile[vdecChn] = readfp;
    }

    printf("open %s success, vdec chn:%d\n", pstArgs->szFileName, vdecChn);
    // s32Ms = _stTestParam.stChannelInfo[s32VoChannel].s32PushDataMs;
    // bVdecChnEnable = _stTestParam.stChannelInfo[0].bVdecChnEnable;

    memset(&stBufConf, 0x0, sizeof(MI_SYS_BufConf_t));
    stBufConf.eBufType = E_MI_SYS_BUFDATA_RAW;
    stBufConf.u64TargetPts = 0;
    pu8Buf = (MI_U8*)malloc(NALU_PACKET_SIZE);

    s32Ret = MI_SYS_SetChnOutputPortDepth(0, &stChnPort, 0, 4);
    if (MI_SUCCESS != s32Ret)
    {
        ST_ERR("MI_SYS_SetChnOutputPortDepth error, %X\n", s32Ret);
        return NULL;
    }

    //stChnPort.eModId = E_MI_MODULE_ID_DIVP;
    //STCHECKRESULT(MI_SYS_SetChnOutputPortDepth(0, &stChnPort, 2, 5));

    s32Ms = 20;
    //printf("----------------------%d------------------\n", stChnPort.u32ChnId);
    while (!g_PushEsExit)
    {
        //usleep(s32Ms * 1000);//33
        if (pstArgs->bRunFlag == FALSE)
        {
		    usleep(100 * 1000);
            continue;
        }

        if (pstArgs->bEsAddHead)
        {
            memset(au8Header, 0, 16);
            u32Pos = fseek(readfp, 0, SEEK_CUR);
            s32Len = fread(au8Header, 1, 16, readfp);
            if(s32Len <= 0)
            {
                fseek(readfp, 0, SEEK_SET);
                continue;
            }

            u32FrameLen = MI_U32VALUE(au8Header, 4);
            // printf("vdecChn:%d, u32FrameLen:%d, %d\n", vdecChn, u32FrameLen, NALU_PACKET_SIZE);
            if(u32FrameLen > NALU_PACKET_SIZE)
            {
                fseek(readfp, 0, SEEK_SET);
                continue;
            }
            s32Len = fread(pu8Buf, 1, u32FrameLen, readfp);
            if(s32Len <= 0)
            {
                fseek(readfp, 0, SEEK_SET);
                continue;
            }

            stVdecStream.pu8Addr = pu8Buf;
            stVdecStream.u32Len = s32Len;
            stVdecStream.u64PTS = u64Pts;
            stVdecStream.bEndOfFrame = 1;
            stVdecStream.bEndOfStream = 0;

            u32FpBackLen = stVdecStream.u32Len + 16; //back length
        }
        else
        {
            GetAnnexbNALU(n, vdecChn);
            dump(n);
            stVdecStream.pu8Addr = (MI_U8 *)n->buf;
            if(9 == n->len
                && 0 == *(n->buf)
                && 0 == *(n->buf+1)
                && 0 == *(n->buf+2)
                && 1 == *(n->buf+3)
                && 0x68 == *(n->buf+4)
                && 0 == *(n->buf+n->len-1))
            {
                printf("pps data:0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", *(n->buf),*(n->buf+1),
                        *(n->buf+2),*(n->buf+3),*(n->buf+4),*(n->buf+5),*(n->buf+6),*(n->buf+7),*(n->buf+8));
                stVdecStream.u32Len = 8;
            }
            else
                stVdecStream.u32Len = n->len;
            stVdecStream.u64PTS = u64Pts;
            stVdecStream.bEndOfFrame = 1;
            stVdecStream.bEndOfStream = 0;

            u32FpBackLen = stVdecStream.u32Len; //back length
        }



        if(0x00 == stVdecStream.pu8Addr[0] && 0x00 == stVdecStream.pu8Addr[1]
            && 0x00 == stVdecStream.pu8Addr[2] && 0x01 == stVdecStream.pu8Addr[3]
            && 0x65 == stVdecStream.pu8Addr[4] || 0x61 == stVdecStream.pu8Addr[4]
            || 0x26 == stVdecStream.pu8Addr[4] || 0x02 == stVdecStream.pu8Addr[4]
            || 0x41 == stVdecStream.pu8Addr[4])
        {
            usleep(s32Ms * 1000);
        }

        if (MI_SUCCESS != (s32Ret = MI_VDEC_SendStream(0, vdecChn, &stVdecStream, s32TimeOutMs)))
        {
            ST_ERR("MI_VDEC_SendStream fail, chn:%d, 0x%X\n", vdecChn, s32Ret);
            fseek(readfp, - u32FpBackLen, SEEK_CUR);
			break;
        }

        u64Pts = u64Pts + ST_Sys_GetPts(30);


        if (0 == (s32ReadCnt++ % 30))
            ;// printf("vdec(%d) push buf cnt (%d)...\n", s32VoChannel, s32ReadCnt)
            ;//printf("###### ==> Chn(%d) push frame(%d) Frame Dec:%d  Len:%d\n", s32VoChannel, s32ReadCnt, stChnStat.u32DecodeStreamFrames, u32Len);
    }
    printf("\n\n");
    usleep(300000);
    free(pu8Buf);
    if (!pstArgs->bEsAddHead)
        FreeNALU(n);
    fclose(readfp);

    printf("End----------------------%d------------------End\n", stChnPort.u32ChnId);
	
	pthread_exit(&ret);
}


static int sstar_packet_get(AVPacketQueue *q, AVPacket *pkt, int block)
{
    AVPacketList *pkt_node;
    int ret = -1;
    pthread_mutex_lock(&q->mutex);
    while (1)
    {
        if(q->abort_request) {
            ret = -1;
            break;
        }
        pkt_node = q->pkt;
        if (pkt_node) {
            q->pkt = pkt_node->next;
            if (!q->pkt) {
                q->next_pkt = NULL;
            }
            q->nb_packets--;
            q->size -= pkt_node->pkt.size + sizeof(*pkt_node);
            *pkt = pkt_node->pkt;
            av_freep(&pkt_node);
            ret = 1;
            break;
        }
        else if (!block) {
            ret = 0;
            break;
        }
        else
        {
            //printf("no pkt wait pktnb: %d\n", q->nb_packets);
            pthread_cond_wait(&q->cond, &q->mutex);
        }
    }
    pthread_mutex_unlock(&q->mutex);
    return ret;
}


static void * sstar_audio_process(void *args)
{
    int ret;
    AVPlayer *is = (AVPlayer *)args;
    uint8_t *audio_buffer = NULL;
    struct SwrContext *audio_swr_ctx = NULL;
    AVPacket *packet = av_packet_alloc();
    AVFrame *frame = av_frame_alloc();

    //输入的采样格式, 采样率, 声道布局
    enum AVSampleFormat in_sample_fmt = AV_SAMPLE_FMT_S16;
    int in_sample_rate = 48000;
    uint64_t in_ch_layout = AV_CH_LAYOUT_MONO;
    int in_channels = 0;
    unsigned int audio_frm_rwr_size = 0;
    //输出的采样格式, 采样率, 声道布局
    enum AVSampleFormat out_sample_fmt = AUDIO_INPUT_SAMPFMT;
    int out_sample_rate = AUDIO_INPUT_SAMPRATE;
    uint64_t out_ch_layout = AUDIO_INPUT_CHLAYOUT;
    int out_channels = av_get_channel_layout_nb_channels(out_ch_layout);
    int bytes_per_sec = av_samples_get_buffer_size(NULL, out_channels, out_sample_rate, out_sample_fmt, 1);

    AVRational tb = is->format_ctx->streams[is->audio_stream_idx]->time_base;

    while (!b_exit)
    {
    	if (mp4_exit == true)
        {
		    usleep(100 * 1000);
            continue;
        }
        ret = sstar_packet_get(&is->a_pkt_queue, packet, 1);
        if(ret > 0)
        {
            if(packet->stream_index == is->audio_stream_idx)
            {
                MI_AUDIO_Frame_t stAoSendFrame;
                MI_S32 s32RetSendStatus = 0;
                MI_AUDIO_DEV AoDevId = AUDIO_DEV;
                MI_AO_CHN AoChn = 0;
                MI_S16 s16DataLen = 0;
                MI_U16 u16DataIndex = 0;
                MI_S32 s32TimeOut = 128;

                //解码AVPacket->AVFrame
                ret = avcodec_send_packet(is->a_codec_ctx, packet);
                if (ret < 0 && ret != AVERROR(EAGAIN))
                {
                    av_log(NULL, AV_LOG_ERROR, "avcodec_send_packet fail!\n");
                    goto audio_exit;
                }

                ret = avcodec_receive_frame(is->a_codec_ctx, frame);
                if (ret < 0 && ret != AVERROR(EAGAIN))
                {
                    printf("avcodec_receive_frame fail\n");
                    goto audio_exit;
                }
                else if (ret >= 0)
                {
                    enum AVSampleFormat sample_fmt = (enum AVSampleFormat)(frame->format);
                    // 根据frame中指定的音频参数获取缓冲区的大小
                    int data_size = av_samples_get_buffer_size(NULL, frame->channels, frame->nb_samples, sample_fmt, 1);

                    // 获取声道布局
                    uint64_t dec_channel_layout = (frame->channel_layout && frame->channels == av_get_channel_layout_nb_channels(frame->channel_layout)) ?
                                          frame->channel_layout : av_get_default_channel_layout(frame->channels);
                    int wanted_nb_samples = frame->nb_samples;

                    //printf("data size = %d, layout = %d, wanted_nb_samples = %d\n", data_size, dec_channel_layout, wanted_nb_samples);

                    if (sample_fmt != in_sample_fmt ||
                        dec_channel_layout != in_ch_layout ||
                        frame->sample_rate != in_sample_rate ||
                        frame->channels != in_channels)
                    {
                        swr_free(&audio_swr_ctx);

                        // 使用frame(源)和is->audio_param_tgt(目标)中的音频参数来设置is->audio_swr_ctx
                        audio_swr_ctx = swr_alloc_set_opts(NULL, out_ch_layout, out_sample_fmt, out_sample_rate,
                                                    dec_channel_layout, sample_fmt, frame->sample_rate, 0, NULL);
                        if (!audio_swr_ctx || swr_init(audio_swr_ctx) < 0)
                        {
                            av_log(NULL, AV_LOG_ERROR,
                                "cannot create sample rate converter for conversion of %d Hz %s %d channels to %d Hz %s %lld channels!\n",
                                frame->sample_rate, av_get_sample_fmt_name(sample_fmt), frame->channels,
                                out_sample_rate, av_get_sample_fmt_name(out_sample_fmt), out_ch_layout);
                            swr_free(&audio_swr_ctx);
                            goto audio_exit;
                        }

                        in_ch_layout = dec_channel_layout;
                        in_channels = frame->channels;
                        in_sample_rate = frame->sample_rate;
                        in_sample_fmt = sample_fmt;
                        av_log(NULL, AV_LOG_INFO, "swr_alloc_set_opts ok!\n");
                    }

                    if (audio_swr_ctx)
                    {
                        const uint8_t **in = (const uint8_t **)frame->extended_data;
                        // 重采样输出参数:输出音频样本数(多加了256个样本)
                        int out_count = (int64_t)wanted_nb_samples * out_sample_rate / frame->sample_rate + 256;
                        // 重采样输出参数:输出音频缓冲区尺寸(以字节为单位)
                        int out_size = av_samples_get_buffer_size(NULL, out_channels, out_count, out_sample_fmt, 1);
                        if (out_size < 0)
                        {
                            av_log(NULL, AV_LOG_ERROR, "av_samples_get_buffer_size() failed\n");
                            goto audio_exit;
                        }

                        av_fast_malloc(&audio_buffer, &audio_frm_rwr_size, out_size);
                        if (!audio_buffer)
                        {
                            goto audio_exit;
                        }

                        // 音频重采样：返回值是重采样后得到的音频数据中单个声道的样本数
                        int len2 = swr_convert(audio_swr_ctx, &audio_buffer, out_count, in, frame->nb_samples);
                        if (len2 < 0)
                        {
                            av_log(NULL, AV_LOG_ERROR, "swr_convert() failed\n");
                            goto audio_exit;
                        }

                        if (len2 == out_count)
                        {
                            av_log(NULL, AV_LOG_WARNING, "audio buffer is probably too small\n");
                            if (swr_init(audio_swr_ctx) < 0)
                                swr_free(&audio_swr_ctx);
                            goto audio_exit;
                        }

                        // 重采样返回的一帧音频数据大小(以字节为单位)
                        s16DataLen = len2 * out_channels * av_get_bytes_per_sample(out_sample_fmt);
                        //av_log(NULL, AV_LOG_INFO, "audio frame data size: %d, wanted_nb_samples: %d\n", s16DataLen, wanted_nb_samples);
                    }
                    else
                    {
                        audio_buffer = frame->data[0];
                        s16DataLen = data_size;
                    }

                    if (s16DataLen < 0)
                    {
                        av_log(NULL, AV_LOG_ERROR, "valid audio frame data size: %d\n", s16DataLen);
                    }

                    //read data and send to ao module
                    do {
                        if (s16DataLen <= MI_AUDIO_MAX_DATA_SIZE)
                            stAoSendFrame.u32Len[0] = s16DataLen;
                        else
                            stAoSendFrame.u32Len[0] = MI_AUDIO_MAX_DATA_SIZE;

                        stAoSendFrame.apVirAddr[0] = &audio_buffer[u16DataIndex];
                        stAoSendFrame.apVirAddr[1] = NULL;

                        s32TimeOut = s16DataLen * 1000 / (out_sample_rate * out_channels);
                        s32TimeOut = (s32TimeOut < 24) ? 24 : s32TimeOut;
                        //av_log(NULL, AV_LOG_INFO, "channels: %d, mi_ao_sendframe timeout: %d\n", out_channels, s32TimeOut);

                        s16DataLen   -= MI_AUDIO_MAX_DATA_SIZE;
                        u16DataIndex += MI_AUDIO_MAX_DATA_SIZE;

                        do{
                            s32RetSendStatus = MI_AO_SendFrame(AoDevId, AoChn, &stAoSendFrame, s32TimeOut);
                        }while(s32RetSendStatus == MI_AO_ERR_NOBUF);

                        if(s32RetSendStatus != MI_SUCCESS)
                        {
                            printf("[Warning]: MI_AO_SendFrame fail, error is 0x%x: \n",s32RetSendStatus);
                        }
                    }while(s16DataLen > 0);

                    //计算音频pts
                    MI_AO_ChnState_t stState;
                    MI_AO_QueryChnStat(AoDevId, AoChn, &stState);
                    double audio_pts = (frame->pts == AV_NOPTS_VALUE) ? NAN : frame->pts * av_q2d(tb);
                    if (!isnan(audio_pts))
                    {
                        is->audio_clock = audio_pts + (double)frame->nb_samples / frame->sample_rate;
                        is->audio_pts = is->audio_clock - stState.u32ChnBusyNum / bytes_per_sec;
                    }
                    else
                    {
                        is->audio_clock = NAN;
                        is->audio_pts = NAN;
                    }
                    //av_log(NULL, AV_LOG_INFO, "audio frame clock: %f %d %d\n", is->audio_pts, stState.u32ChnBusyNum, bytes_per_sec);

                    av_frame_unref(frame);
                }
            }
            av_packet_unref(packet);
        }
    }

audio_exit:
    av_frame_free(&frame);
    av_packet_free(&packet);
    av_freep(&audio_buffer);
    swr_free(&audio_swr_ctx);

    b_exit = true;
    av_log(NULL, AV_LOG_INFO, "audio process thread exit!\n");

    return NULL;
}

static MI_S32 sstar_module_bind(void)
{
    MI_SYS_ChnPort_t stSrcChnPort;
    MI_SYS_ChnPort_t stDstChnPort;
	int scl_width;
	int scl_height;


	MI_VDEC_OutputPortAttr_t stVdecOutputPortAttr;


	memset(&stVdecOutputPortAttr, 0, sizeof(stVdecOutputPortAttr));	
	MI_VDEC_GetOutputPortAttr (0, 0, &stVdecOutputPortAttr);
	printf("+++++++++++++++++++vdec width = %d , height = %d\n ",stVdecOutputPortAttr.u16Width,stVdecOutputPortAttr.u16Height);

	scl_width = stVdecOutputPortAttr.u16Width;
	scl_height = stVdecOutputPortAttr.u16Height;
	if(stVdecOutputPortAttr.u16Width > 1280 || stVdecOutputPortAttr.u16Height > 800)
	{
		scl_width = 1280;
		scl_height = 800;
	}
	

	MI_DISP_PubAttr_t stDispPubAttr;
    MI_DISP_VideoLayerAttr_t stDispLayerAttr;
    MI_DISP_InputPortAttr_t stDispInputPortAttr;

	//xz
    //usleep(3000*1000);
    printf("9999999999999999999999\n");
 
    //usleep(3000*1000);
	ExecFunc(MI_DISP_DisableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);

    // ExecFunc(MI_DISP_DisableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);
    // ExecFunc(MI_DISP_UnBindVideoLayer(DISP_LAYER_ID, DISP_DEV_ID), MI_SUCCESS);
    // ExecFunc(MI_DISP_Disable(DISP_DEV_ID), MI_SUCCESS);





	memset(&stDispPubAttr, 0, sizeof(stDispPubAttr));
    memset(&stDispLayerAttr, 0, sizeof(stDispLayerAttr));
    memset(&stDispInputPortAttr, 0, sizeof(stDispInputPortAttr));
	stDispPubAttr.eIntfSync = E_MI_DISP_OUTPUT_USER;
    stDispPubAttr.eIntfType = E_MI_DISP_INTF_MIPIDSI;
    stDispPubAttr.u32BgColor = YUYV_BLACK;
    stDispLayerAttr.ePixFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    stDispLayerAttr.stVidLayerDispWin.u16Height = 800;//scl_width;
    stDispLayerAttr.stVidLayerDispWin.u16Width = 1280;//scl_height;
    stDispLayerAttr.stVidLayerDispWin.u16X = 0;//(720-scl_height)/2;
    stDispLayerAttr.stVidLayerDispWin.u16Y = 0;//(1280-scl_width)/2;
    stDispLayerAttr.stVidLayerSize.u16Height = 800;//scl_width;
    stDispLayerAttr.stVidLayerSize.u16Width = 1280;//scl_height;
    stDispInputPortAttr.stDispWin.u16Height = 800;//scl_width;
    stDispInputPortAttr.stDispWin.u16Width = 1280;//scl_height;
    stDispInputPortAttr.stDispWin.u16X = 0;//(720-scl_height)/2;
    stDispInputPortAttr.stDispWin.u16Y = 0;//(1280-scl_width)/2;
    stDispInputPortAttr.u16SrcHeight = 800;//scl_width;
    stDispInputPortAttr.u16SrcWidth = 1280;//scl_height;

    // ExecFunc(MI_DISP_SetPubAttr(DISP_DEV_ID, &stDispPubAttr), MI_SUCCESS);
    // ExecFunc(MI_DISP_Enable(DISP_DEV_ID), MI_SUCCESS);
    // ExecFunc(MI_DISP_BindVideoLayer(DISP_LAYER_ID,DISP_DEV_ID), MI_SUCCESS);
    // ExecFunc(MI_DISP_SetVideoLayerAttr(DISP_LAYER_ID, &stDispLayerAttr), MI_SUCCESS);
    // ExecFunc(MI_DISP_EnableVideoLayer(DISP_LAYER_ID), MI_SUCCESS);

    ExecFunc(MI_DISP_SetInputPortAttr(DISP_LAYER_ID, 0, &stDispInputPortAttr), MI_SUCCESS);
    ExecFunc(MI_DISP_EnableInputPort(DISP_LAYER_ID, 0), MI_SUCCESS);
    ExecFunc(MI_DISP_SetInputPortSyncMode(DISP_LAYER_ID, 0, E_MI_DISP_SYNC_MODE_FREE_RUN), MI_SUCCESS);

	
	
	//change_scl_resolution(scl_height,scl_width,3, SCL_CHN_ID, SCL_PORT_ID);
	change_scl_resolution(scl_width,scl_height,3, SCL_CHN_ID, SCL_PORT_ID);
#if 1
	MI_SYS_ChnPort_t stSysChnPort;
    MI_SCL_ChannelAttr_t stSclChnAttr;
    MI_SCL_ChnParam_t stSclChnParam;
    MI_SCL_OutPortParam_t stSclOutputParam;
	MI_U8 scl_dev = 1;
	MI_U8 scl_chn = 1;
	MI_U8 scl_port = 0;

    memset(&stSysChnPort, 0x0, sizeof(stSysChnPort));
    memset(&stSclChnAttr, 0x0, sizeof(MI_SCL_ChannelAttr_t));
    memset(&stSclChnParam, 0x0, sizeof(MI_SCL_ChnParam_t));
    memset(&stSclOutputParam, 0x0, sizeof(MI_SCL_OutPortParam_t));



    stSysChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysChnPort.u32DevId = scl_dev;
    stSysChnPort.u32ChnId = scl_chn;
    stSysChnPort.u32PortId = scl_port;
    stSclOutputParam.stSCLOutCropRect.u16X = 0;
    stSclOutputParam.stSCLOutCropRect.u16Y = 0;
    stSclOutputParam.stSCLOutCropRect.u16Width = 0;
    stSclOutputParam.stSCLOutCropRect.u16Height = 0;
    stSclOutputParam.stSCLOutputSize.u16Width = scl_width;
    stSclOutputParam.stSCLOutputSize.u16Height = scl_height;
    stSclOutputParam.bMirror = false;
    stSclOutputParam.bFlip = false;
    stSclOutputParam.eCompressMode= E_MI_SYS_COMPRESS_MODE_NONE;
    stSclOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;

    ExecFunc(MI_SCL_CreateChannel(scl_dev, scl_chn, &stSclChnAttr), MI_SUCCESS);
    ExecFunc(MI_SCL_SetChnParam(scl_dev, scl_chn, &stSclChnParam), MI_SUCCESS);
    ExecFunc(MI_SCL_StartChannel(scl_dev, scl_chn), MI_SUCCESS);
    ExecFunc(MI_SCL_SetOutputPortParam(scl_dev, scl_chn, scl_port, &stSclOutputParam), MI_SUCCESS);
    ExecFunc(MI_SCL_EnableOutputPort(scl_dev, scl_chn, scl_port), MI_SUCCESS);


	//bind scl1 to scl3
    stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSrcChnPort.u32DevId = scl_dev;
    stSrcChnPort.u32ChnId = scl_chn;
    stSrcChnPort.u32PortId = scl_port;
    stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
    stDstChnPort.u32DevId = 3;
    stDstChnPort.u32ChnId = 0;
    stDstChnPort.u32PortId = 0;
    STCHECKRESULT(MI_SYS_BindChnPort(0, &stSrcChnPort, &stDstChnPort, 30, 30));
#endif

	

    //bind vdec to disp
    stSrcChnPort.eModId = E_MI_MODULE_ID_VDEC;
    stSrcChnPort.u32DevId = VDEC_DEV_ID;
    stSrcChnPort.u32ChnId = VDEC_CHN_ID;
    stSrcChnPort.u32PortId = VDEC_PORT_ID;
    stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
    stDstChnPort.u32DevId = scl_dev;
    stDstChnPort.u32ChnId = scl_chn;
    stDstChnPort.u32PortId = scl_port;
    STCHECKRESULT(MI_SYS_BindChnPort(0, &stSrcChnPort, &stDstChnPort, 30, 30));

	

	

    return SUCCESS;
}

static MI_S32 sstar_module_unbind(void)
{
    MI_SYS_ChnPort_t stSrcChnPort;
    MI_SYS_ChnPort_t stDstChnPort;


    //ubind vdec to disp
    stSrcChnPort.eModId = E_MI_MODULE_ID_VDEC;
    stSrcChnPort.u32DevId = VDEC_DEV_ID;
    stSrcChnPort.u32ChnId = VDEC_CHN_ID;
    stSrcChnPort.u32PortId = VDEC_PORT_ID;
    stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
    stDstChnPort.u32DevId = 1;
    stDstChnPort.u32ChnId = 1;
    stDstChnPort.u32PortId = 0;
    STCHECKRESULT(MI_SYS_UnBindChnPort(0, &stSrcChnPort, &stDstChnPort));

	//ubind scl1 to scl3
    stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSrcChnPort.u32DevId = 1;
    stSrcChnPort.u32ChnId = 1;
    stSrcChnPort.u32PortId = 0;
    stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
    stDstChnPort.u32DevId = 3;
    stDstChnPort.u32ChnId = 0;
    stDstChnPort.u32PortId = 0;
    STCHECKRESULT(MI_SYS_UnBindChnPort(0, &stSrcChnPort, &stDstChnPort));

	ExecFunc(MI_SCL_DisableOutputPort(SCL_DEV_ID, 1, 0), MI_SUCCESS);
    ExecFunc(MI_SCL_StopChannel(SCL_DEV_ID, 1), MI_SUCCESS);
    ExecFunc(MI_SCL_DestroyChannel(SCL_DEV_ID, 1), MI_SUCCESS);

	

    return SUCCESS;
}


static void * sstar_video_process(void *args)
{
    int ret, avsync_done = 1;
    bool is_soft_codec = false;
    AVPlayer *is = (AVPlayer *)args;
    AVFrame *frame_yuv = NULL;
    uint8_t *video_buffer = NULL;
    struct SwsContext *video_sws_ctx = NULL;
    AVPacket *packet = av_packet_alloc();
    AVFrame *frame = av_frame_alloc();

    AVStream *st = is->format_ctx->streams[is->video_stream_idx];
    AVRational tb = st->time_base;
    AVRational frame_rate = av_guess_frame_rate(is->format_ctx, st, NULL);
    double duration = av_q2d((AVRational){frame_rate.den, frame_rate.num});
    double start_time, now_time, diff_time, remaining_time;

    duration = isnan(duration) ? 0.040 : duration;
    av_log(NULL, AV_LOG_INFO, "video frame rate time:  %f\n", duration);


    is_soft_codec = false;


    //none h264 sw decode need transcode to NV12 for disp input
    if((is->v_codec_ctx->codec_id != AV_CODEC_ID_H264 && is->v_codec_ctx->codec_id != AV_CODEC_ID_HEVC) || is_soft_codec)
    {
        //转换成YUV420P
        frame_yuv = av_frame_alloc();
        //只有指定了AVFrame的像素格式,画面大小才能真正分配内存
        //缓冲区分配内存
        video_buffer = (uint8_t *)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_NV12, u16SrcWidth, u16SrcHeight, 1));
        if (!video_buffer)
        {
            av_log(NULL, AV_LOG_ERROR, "malloc video buffer failed!\n");
            goto video_exit;
        }
        //初始化缓冲区
        frame_yuv->width  = u16SrcWidth;
        frame_yuv->height = u16SrcHeight;
        ret = av_image_fill_arrays(frame_yuv->data,     // dst data[]
                                   frame_yuv->linesize, // dst linesize[]
                                   video_buffer,        // src buffer
                                   AV_PIX_FMT_NV12,     // pixel format
                                   u16SrcWidth,
                                   u16SrcHeight,
                                   1                    // align
                                   );
        if (ret < 0)
        {
            av_log(NULL, AV_LOG_ERROR, "av_image_fill_arrays() failed %d\n", ret);
            goto video_exit;
        }

        //用于转码（缩放）的参数，转之前的宽高，转之后的宽高，格式等
        video_sws_ctx = sws_getContext(is->v_codec_ctx->width, is->v_codec_ctx->height, is->v_codec_ctx->pix_fmt,
                                       u16SrcWidth, u16SrcHeight, AV_PIX_FMT_NV12,
                                       SWS_BICUBIC, NULL, NULL, NULL);
    }


    //h264 hw decode need bind vdec 2 disp
    if (is->v_codec_ctx->codec_id == AV_CODEC_ID_H264 || is->v_codec_ctx->codec_id == AV_CODEC_ID_HEVC)
    {
        is->v_codec_ctx->flags |= (1 << 8);
        sstar_module_bind();
    }


    while (!b_exit)
    {
    	if (mp4_exit == true)
        {
		    usleep(100 * 1000);
            continue;
        }
        ret = sstar_packet_get(&is->v_pkt_queue, packet, 1);
        if(ret > 0)
        {
            if (packet->stream_index == is->video_stream_idx)
            {
                #if 0
                if(codec_ctx->codec_id == AV_CODEC_ID_H264)
                {
                    const char start_code[4] = { 0, 0, 0, 1 };
                    if(memcmp(start_code, packet->data, 4) != 0)
                    {//is avc1 code, have no start code of H264
                        int len = 0;
                        uint8_t *p = packet->data;

                        do
                        {//add start_code for each NAL, one frame may have multi NALs.
                            len = ntohl(*((long*)p));
                            memcpy(p, start_code, 4);

                            p += 4;
                            p += len;
                            if(p >= packet->data + packet->size)
                            {
                                break;
                            }
                        } while (1);
                    }
                }
                #endif
                start_time = av_gettime_relative() / 1000000.0;
                //7.解码一帧视频压缩数据
                ret = avcodec_send_packet(is->v_codec_ctx, packet);
                if (ret < 0 && ret != AVERROR(EAGAIN))
                {
                    av_log(NULL, AV_LOG_ERROR, "avcodec_send_packet fail!\n");
                    goto video_exit;
                }

                ret = avcodec_receive_frame(is->v_codec_ctx, frame);
                if (ret < 0 && ret != AVERROR(EAGAIN))
                {
                    printf("avcodec_receive_frame fail\n");
                    goto video_exit;
                }
                else if (ret >= 0)
                {
                    double codec_time = av_gettime_relative() / 1000000.0;
                    //av_log(NULL, AV_LOG_INFO, "video decoder cost: %f \n", codec_time - start_time);
                    //none h264 sw decode need put frame to disp
                    if((is->v_codec_ctx->codec_id != AV_CODEC_ID_H264 && is->v_codec_ctx->codec_id != AV_CODEC_ID_HEVC) || is_soft_codec)
                    {
                        //av_log(NULL, AV_LOG_WARNING, "frame pixel format: %d\n", frame->format);
                        sws_scale(video_sws_ctx, frame->data, frame->linesize, 0, is->v_codec_ctx->height, frame_yuv->data, frame_yuv->linesize);

                        int y_size = frame_yuv->width * frame_yuv->height;

                        MI_SYS_BUF_HANDLE hHandle;
                        MI_SYS_ChnPort_t pstSysChnPort;
                        MI_SYS_BufConf_t stBufConf;
                        MI_SYS_BufInfo_t stBufInfo;

                        pstSysChnPort.eModId    = E_MI_MODULE_ID_DISP;
                        pstSysChnPort.u32ChnId  = DISP_DEV_ID;
                        pstSysChnPort.u32DevId  = DISP_CHN_ID;
                        pstSysChnPort.u32PortId = DISP_PORT_ID;


                        memset(&stBufInfo , 0 , sizeof(MI_SYS_BufInfo_t));
                        memset(&stBufConf , 0 , sizeof(MI_SYS_BufConf_t));

                        stBufConf.eBufType = E_MI_SYS_BUFDATA_FRAME;
                        stBufConf.u64TargetPts = 0;
                        stBufConf.stFrameCfg.u16Width  = frame_yuv->width;
                        stBufConf.stFrameCfg.u16Height = frame_yuv->height;
                        stBufConf.stFrameCfg.eFormat   = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
                        stBufConf.stFrameCfg.eFrameScanMode = E_MI_SYS_FRAME_SCAN_MODE_PROGRESSIVE;
						printf("frame_yuv->width =%d,frame_yuv->height = %d",frame_yuv->width,frame_yuv->height);
                        if(MI_SUCCESS == MI_SYS_ChnInputPortGetBuf(&pstSysChnPort,&stBufConf,&stBufInfo,&hHandle, -1))
                        {
                            stBufInfo.stFrameData.eCompressMode = E_MI_SYS_COMPRESS_MODE_NONE;
                            stBufInfo.stFrameData.eFieldType = E_MI_SYS_FIELDTYPE_NONE;
                            stBufInfo.stFrameData.eTileMode = E_MI_SYS_FRAME_TILE_MODE_NONE;
                            stBufInfo.bEndOfStream = FALSE;

                            memcpy(stBufInfo.stFrameData.pVirAddr[0], frame_yuv->data[0], y_size);
                            memcpy(stBufInfo.stFrameData.pVirAddr[1], frame_yuv->data[1], y_size / 2);

                            MI_SYS_ChnInputPortPutBuf(hHandle ,&stBufInfo , FALSE);
                        }
                    }
                    double convert_time = av_gettime_relative() / 1000000.0;
                    //av_log(NULL, AV_LOG_INFO, "video format convert cost: %f \n", convert_time - codec_time);

                    //计算视频时间戳
                    is->video_clock += duration;
                    if (frame->pts == AV_NOPTS_VALUE)
                        is->video_pts = is->video_clock;
                    else
                        is->video_pts = frame->pts * av_q2d(tb);

                    diff_time = (is->audio_pts > 0) ? (is->video_pts - is->audio_pts) : 0;

                    now_time = av_gettime_relative() / 1000000.0;
                    if (fabs(diff_time) > 5 * duration)
                    {
                        avsync_done = 0;
                        if (diff_time > 0)
                            remaining_time = 2 * duration;
                        else
                            remaining_time = FFMAX(0.01 + start_time - now_time, 0);
                    }
                    else
                    {
                        if (fabs(diff_time) < duration)
                            avsync_done = 1;
                        if (avsync_done)
                            remaining_time = FFMAX(duration + start_time - now_time, 0);
                    }
                    //av_log(NULL, AV_LOG_INFO, "video frame clock: %f %f %f\n", is->video_pts, remaining_time, now_time - start_time);
                    av_usleep((unsigned long)(remaining_time * 1000000.0));

                    av_frame_unref(frame);
                }
            }
            av_packet_unref(packet);
        }
    }

video_exit:

    if(is->v_codec_ctx->codec_id == AV_CODEC_ID_H264 || is->v_codec_ctx->codec_id == AV_CODEC_ID_HEVC)
    {
        sstar_module_unbind();
    }


    av_frame_free(&frame);
    av_frame_free(&frame_yuv);
    av_packet_free(&packet);
    av_freep(&video_buffer);
    sws_freeContext(video_sws_ctx);

    b_exit = true;
    av_log(NULL, AV_LOG_INFO, "video process thread exit!\n");

    return NULL;
}

static int sstar_packet_put(AVPacketQueue *q, AVPacket *pkt)
{
    AVPacketList *pkt_list;

    pkt_list = (AVPacketList *)av_mallocz(sizeof(AVPacketList));
    if (!pkt_list)
        return AVERROR(ENOMEM);

    pthread_mutex_lock(&q->mutex);

    pkt_list->pkt = *pkt;
    pkt_list->next = NULL;

    if (!q->next_pkt) {
        q->pkt = pkt_list;
    } else {
        q->next_pkt->next = pkt_list;
    }
    q->next_pkt = pkt_list;
    q->nb_packets++;
    q->size += pkt_list->pkt.size + sizeof(*pkt_list);

    pthread_cond_signal(&q->cond);
    pthread_mutex_unlock(&q->mutex);

    return 0;
}


static void sstar_packet_flush(AVPacketQueue *q)
{
    AVPacketList *pkt, *pkt1;

    pthread_mutex_lock(&q->mutex);
    for (pkt = q->pkt; pkt; pkt = pkt1) {
        pkt1 = pkt->next;
        av_packet_unref(&pkt->pkt);
        av_freep(&pkt);
    }
    q->pkt = NULL;
    q->next_pkt = NULL;
    q->nb_packets = 0;
    q->size = 0;
    pthread_mutex_unlock(&q->mutex);
}


static int sstar_ao_init(int ao_volume)
{
    MI_AUDIO_Attr_t stSetAttr;
    MI_AUDIO_Attr_t stGetAttr;
    MI_AUDIO_DEV AoDevId = AUDIO_DEV;
    MI_AO_CHN AoChn = 0;

    MI_S32 s32SetVolumeDb;
    MI_S32 s32GetVolumeDb;

    //set Ao Attr struct
    memset(&stSetAttr, 0, sizeof(MI_AUDIO_Attr_t));
    stSetAttr.eBitwidth = AUDIO_OUTPUT_SAMPFMT;
    stSetAttr.eWorkmode = E_MI_AUDIO_MODE_I2S_MASTER;
    stSetAttr.u32FrmNum = 6;
    stSetAttr.u32PtNumPerFrm = MI_AUDIO_SAMPLE_PER_FRAME;
    stSetAttr.u32ChnCnt   = 1;
    stSetAttr.eSoundmode  = AUDIO_OUTPUT_CHLAYOUT;
    stSetAttr.eSamplerate = AUDIO_OUTPUT_SAMPRATE;

    /* set ao public attr*/
    ExecFunc(MI_AO_SetPubAttr(AoDevId, &stSetAttr), MI_SUCCESS);
    /* get ao device*/
    ExecFunc(MI_AO_GetPubAttr(AoDevId, &stGetAttr), MI_SUCCESS);
    /* enable ao device */
    ExecFunc(MI_AO_Enable(AoDevId), MI_SUCCESS);
    /* enable ao channel of device*/
    ExecFunc(MI_AO_EnableChn(AoDevId, AoChn), MI_SUCCESS);


	s32SetVolumeDb = ao_volume;
    MI_AO_SetVolume(AoDevId, AoChn, s32SetVolumeDb, E_MI_AO_GAIN_FADING_16_SAMPLE);
    MI_AO_GetVolume(AoDevId, AoChn, &s32GetVolumeDb);

    return 0;
}


static int sstar_ao_deinit(void)
{
    MI_AUDIO_DEV AoDevId = AUDIO_DEV;
    MI_AO_CHN AoChn = 0;

    /* disable ao channel of */
    ExecFunc(MI_AO_DisableChn(AoDevId, AoChn), MI_SUCCESS);
    /* disable ao device */
    ExecFunc(MI_AO_Disable(AoDevId), MI_SUCCESS);

    return 0;
}



static void * mmplayer_av_process(void *args)
{
	int ret, file_eof = 0;
    //xz
   // usleep(3000*1000);
    printf("22222222222222222!!!!!!!!!\n");
	AVPlayer *mmplayer = (AVPlayer *)args;
	AVPacket pkt, *packet = &pkt;
	//usleep(3000*1000);
    printf("3333333333333333333311111111\n");
	//6.一帧一帧读取压缩的音频数据AVPacket
    while (!b_exit)
    {
    	if (mp4_exit == true)
        {
		    usleep(100 * 1000);
            continue;
        }
        if (mmplayer->a_pkt_queue.size + mmplayer->v_pkt_queue.size >= 2 * 1024 * 1024)
        {
            av_usleep(10 * 1000);
            continue;
        }

        if ((ret = av_read_frame(mmplayer->format_ctx, packet)) >= 0)
        {
            file_eof = 0;
            if (packet->stream_index == mmplayer->audio_stream_idx)
            {
                //usleep(3000 * 1000);
                //printf("&&&&&&&&&&&&&&&&&&&&&&\n");
                sstar_packet_put(&mmplayer->a_pkt_queue, packet);
                //printf("packet queue num : %d\n", mmplayer->a_pkt_queue.nb_packets);
            }
            else if (packet->stream_index == mmplayer->video_stream_idx)
            {
                //usleep(3000 * 1000);
               // printf("************************88\n");
                sstar_packet_put(&mmplayer->v_pkt_queue, packet);
                //printf("packet queue num : %d\n", mmplayer->v_pkt_queue.nb_packets);
            }
            else
            {
                //usleep(3000 * 1000);
                //printf("1111111111111111111222222\n");
                av_packet_unref(packet);
               // printf("unkown pkt[%d]\n",packet->stream_index);
            }
        }
        else
        {
            if ((ret == AVERROR_EOF || avio_feof(mmplayer->format_ctx->pb)) && !file_eof)
            {
                printf("avio buffer has been read finish!\n");
                //printf("555555555555555555555511111111111\n");
                //usleep(3000 * 1000);

                file_eof = 1;
            }

            if (file_eof && !mmplayer->a_pkt_queue.nb_packets && !mmplayer->v_pkt_queue.nb_packets)
            {
                /*int seekflag = AVSEEK_FLAG_ANY;
                seekflag &= ~AVSEEK_FLAG_BYTE;
                ret = avformat_seek_file(mmplayer->format_ctx, -1, INT64_MIN, mmplayer->format_ctx->start_time, INT64_MAX, seekflag);
                if (ret < 0)
                {
                    av_log(NULL, AV_LOG_ERROR, "%s: error while seeking\n", mmplayer->format_ctx->url);
                    b_exit = true;
                }
                mmplayer->audio_clock = 0;
                mmplayer->audio_pts = 0;
                mmplayer->video_clock = 0;
                mmplayer->video_pts = 0;*/
				printf("@@@@@@@@@@@@@@@@@@@@video start !\n");
				//kjd_stopplay_mp4();
				break;
				
            }
        }
    }
    printf("666666666666666666666\n");
    //usleep(3000 * 1000);
	mmplayer->a_pkt_queue.abort_request = 1;
    mmplayer->v_pkt_queue.abort_request = 1;
    pthread_cond_signal(&mmplayer->a_pkt_queue.cond);
    pthread_cond_signal(&mmplayer->v_pkt_queue.cond);

    if (mmplayer->audio_stream_idx >= 0)
    {
        pthread_join(audio_tid, NULL);
    }

    if (mmplayer->video_stream_idx >= 0)
    {
        pthread_join(video_tid, NULL);
    }

    sstar_packet_flush(&mmplayer->a_pkt_queue);
    sstar_packet_flush(&mmplayer->v_pkt_queue);
    pthread_mutex_destroy(&mmplayer->a_pkt_queue.mutex);
    pthread_cond_destroy(&mmplayer->a_pkt_queue.cond);
    pthread_mutex_destroy(&mmplayer->v_pkt_queue.mutex);
    pthread_cond_destroy(&mmplayer->v_pkt_queue.cond);


    avcodec_close(mmplayer->a_codec_ctx);
    avcodec_close(mmplayer->v_codec_ctx);
    avformat_close_input(&mmplayer->format_ctx);
    av_freep(&mmplayer);

    sstar_ao_deinit();
	mmplayer_static = NULL;

	return NULL;
	
}




static void sstar_getpanel_wh(uint16_t *width, uint16_t *height)
{
    MI_DISP_PubAttr_t stPubAttr;
    MI_DISP_GetPubAttr(0,&stPubAttr);
    *height = stPubAttr.stSyncInfo.u16Hact;
    *width = stPubAttr.stSyncInfo.u16Vact;

    printf("sstar_getpanel_wh = [%d %d]\n", *width, *height);
}


static int sstar_video_config(AVCodecContext *pVideoCodeCtx)
{
	pVideoCodeCtx->flags  = pVideoCodeCtx->width;
    pVideoCodeCtx->flags2 = pVideoCodeCtx->height;

	u16SrcWidth  = pVideoCodeCtx->width;
    u16SrcHeight = pVideoCodeCtx->height;
#if 0
	MI_DISP_InputPortAttr_t stInputPortAttr;
    MI_DISP_RotateConfig_t stRotateConfig;

    //获取屏幕宽高参数
    //sstar_getpanel_wh(&u16OutWidth, &u16OutHeight);


    //取较小值进行缩小
    //u16SrcWidth  = FFMIN(pVideoCodeCtx->width , u16OutWidth);
    //u16SrcHeight = FFMIN(pVideoCodeCtx->height, u16OutHeight);
	u16SrcWidth  = pVideoCodeCtx->width;
    u16SrcHeight = pVideoCodeCtx->height;
    pVideoCodeCtx->flags  = u16SrcWidth;
    pVideoCodeCtx->flags2 = u16SrcHeight;

    //重设DISP参数
    memset(&stInputPortAttr, 0, sizeof(stInputPortAttr));
    STCHECKRESULT(MI_DISP_GetInputPortAttr(0, 0, &stInputPortAttr));
    stInputPortAttr.stDispWin.u16X      = 0;
    stInputPortAttr.stDispWin.u16Y      = 0;
    stInputPortAttr.stDispWin.u16Width  = u16SrcWidth;
    stInputPortAttr.stDispWin.u16Height = u16SrcHeight;
    stInputPortAttr.u16SrcWidth         = u16SrcWidth;
    stInputPortAttr.u16SrcHeight        = u16SrcHeight;
    STCHECKRESULT(MI_DISP_SetInputPortAttr(0, 0, &stInputPortAttr));
    STCHECKRESULT(MI_DISP_EnableInputPort(0, 0));
    STCHECKRESULT(MI_DISP_SetInputPortSyncMode(0, 0, E_MI_DISP_SYNC_MODE_FREE_RUN));

    memset(&stRotateConfig, 0x0, sizeof(MI_DISP_RotateConfig_t));
    stRotateConfig.eRotateMode = E_MI_DISP_ROTATE_NONE;
    STCHECKRESULT(MI_DISP_SetVideoLayerRotateMode(0, &stRotateConfig));
#endif
	
	return 0;
}

int rev_mmplayer_time()
{
	if(mmplayer_static != NULL)
	{
		return mmplayer_static->format_ctx->duration;
	}
	else
	{
		return 0;
	}
}

MI_S32 mmplayer(const char *path,int ao_volume)
{
	int ret, file_eof = 0;
	const char *filename = NULL;
	AVPlayer *mmplayer;
	

	filename = path;

	printf("welcome to test mmplayer!\n");

	sstar_ao_init( ao_volume);

	mmplayer = (AVPlayer *)av_malloc(sizeof(AVPlayer));
    if (!mmplayer)
    {
        av_log(NULL, AV_LOG_ERROR, "no memory for mmplayer!\n");
        av_freep(&mmplayer);
		return 1;
    }
	memset(mmplayer, 0x0, sizeof(AVPlayer));
    mmplayer->audio_stream_idx = -1;
    mmplayer->video_stream_idx = -1;

    //1.封装格式上下文
    mmplayer->format_ctx = avformat_alloc_context();
    if (!mmplayer->format_ctx)
    {
        av_log(NULL, AV_LOG_ERROR, "avformat_alloc_context error!\n");
    	av_freep(&mmplayer);
		return 1;
    }

    //2.打开输入视频音频文件
    if (avformat_open_input(&mmplayer->format_ctx, filename, NULL, NULL) != 0) {
        av_log(NULL, AV_LOG_ERROR, "avformat_open_input error!\n");
    	av_freep(&mmplayer);
		return 1;
    }
 
    //3.获取视频音频信息
    if (avformat_find_stream_info(mmplayer->format_ctx, NULL) < 0) {
        av_log(NULL, AV_LOG_ERROR, "avformat_find_stream_info error!\n");
        avformat_close_input(&mmplayer->format_ctx);
    	av_freep(&mmplayer);
		return 1;
    }

	int time = mmplayer->format_ctx->duration;
	int minute = (time / 1000000) / 60;
	int second = (time / 1000000) % 60;

	printf("avformat_find_stream_info get time  %02d : %02d \n",minute,second);

	av_dump_format(mmplayer->format_ctx,0, filename, 0);


	//音频解码，需要找到对应的AVStream所在的pFormatCtx->streams的索引位置
    for (int i = 0; i < mmplayer->format_ctx->nb_streams; i ++) {
        //根据类型判断是否是音频流
        if (mmplayer->format_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            mmplayer->audio_stream_idx = i;
            break;
        }
    }
    for (int i = 0; i < mmplayer->format_ctx->nb_streams; i ++) {
        //根据类型判断是否是音频流
        if (mmplayer->format_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            mmplayer->video_stream_idx = i;
            break;
        }
    }
    if (mmplayer->audio_stream_idx < 0 && mmplayer->video_stream_idx < 0)
    {
        av_log(NULL, AV_LOG_ERROR, "cannot find valid audio or video stream!\n");
        avformat_close_input(&mmplayer->format_ctx);
    	av_freep(&mmplayer);
		return 1;
    }


	//4.获取解码器
    //根据索引拿到对应的流,根据流拿到解码器上下文
    if (mmplayer->audio_stream_idx >= 0)
    {
        AVCodecParameters *pAudioPar = mmplayer->format_ctx->streams[mmplayer->audio_stream_idx]->codecpar;

        //再根据上下文拿到编解码id，通过该id拿到解码器
        AVCodec *pAudioCodec = avcodec_find_decoder(pAudioPar->codec_id);
        if (pAudioCodec == NULL) {
            av_log(NULL, AV_LOG_ERROR, "avcodec_find_decoder error!\n");
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }
        av_log(NULL, AV_LOG_INFO, "open audio codec: %s\n", pAudioCodec->name);

        mmplayer->a_codec_ctx = avcodec_alloc_context3(pAudioCodec);
        if (!mmplayer->a_codec_ctx)
        {
            av_log(NULL, AV_LOG_ERROR, "audio avcodec_alloc_context3 failed\n");
            avcodec_close(mmplayer->a_codec_ctx);
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }
        ret = avcodec_parameters_to_context(mmplayer->a_codec_ctx, pAudioPar);
        if (ret < 0)
        {
            av_log(NULL, AV_LOG_ERROR, "audio avcodec_parameters_to_context failed %d\n", ret);
            avcodec_close(mmplayer->a_codec_ctx);
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }

        //5.打开解码器
        if (avcodec_open2(mmplayer->a_codec_ctx, pAudioCodec, NULL) < 0) {
            av_log(NULL, AV_LOG_ERROR, "avcodec_open2 audio failed!\n");
            avcodec_close(mmplayer->a_codec_ctx);
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }
    }

    if (mmplayer->video_stream_idx >= 0)
    {
        AVCodecParameters *pVideoPar = mmplayer->format_ctx->streams[mmplayer->video_stream_idx]->codecpar;

        AVCodec *pVideoCodec = NULL;

        if (pVideoPar->codec_id == AV_CODEC_ID_H264)
        {
            pVideoCodec = avcodec_find_decoder_by_name("ssh264_ss268");
        }
        else if (pVideoPar->codec_id == AV_CODEC_ID_HEVC)
        {
            pVideoCodec = avcodec_find_decoder_by_name("sshevc_ss268");
        }
        else
        {
            pVideoCodec = avcodec_find_decoder(pVideoPar->codec_id);
        }


        if (pVideoCodec == NULL) {
            av_log(NULL, AV_LOG_ERROR, "avcodec_find_decoder failed!\n");
            avcodec_close(mmplayer->a_codec_ctx);
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }
        av_log(NULL, AV_LOG_INFO, "open video codec: %s\n", pVideoCodec->name);

        mmplayer->v_codec_ctx = avcodec_alloc_context3(pVideoCodec);
        if (!mmplayer->v_codec_ctx)
        {
            av_log(NULL, AV_LOG_ERROR, "video avcodec_alloc_context3 failed\n");
            avcodec_close(mmplayer->a_codec_ctx);
			avcodec_close(mmplayer->v_codec_ctx);
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }
        ret = avcodec_parameters_to_context(mmplayer->v_codec_ctx, pVideoPar);
        if (ret < 0)
        {
            av_log(NULL, AV_LOG_ERROR, "video avcodec_parameters_to_context failed %d\n", ret);
            avcodec_close(mmplayer->a_codec_ctx);
			avcodec_close(mmplayer->v_codec_ctx);
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }
        printf("video code width: %d, height: %d, codeid: %d\n", mmplayer->v_codec_ctx->width, mmplayer->v_codec_ctx->height, mmplayer->v_codec_ctx->codec_id);

		sstar_video_config(mmplayer->v_codec_ctx);

        if (avcodec_open2(mmplayer->v_codec_ctx, pVideoCodec, NULL) < 0) {
            av_log(NULL, AV_LOG_ERROR, "avcodec_open2 video failed!\n");
            avcodec_close(mmplayer->a_codec_ctx);
			avcodec_close(mmplayer->v_codec_ctx);
			avformat_close_input(&mmplayer->format_ctx);
			av_freep(&mmplayer);
			return 1;
        }
    }

	pthread_mutex_init(&mmplayer->a_pkt_queue.mutex, NULL);
    pthread_cond_init(&mmplayer->a_pkt_queue.cond, NULL);
    pthread_mutex_init(&mmplayer->v_pkt_queue.mutex, NULL);
    pthread_cond_init(&mmplayer->v_pkt_queue.cond, NULL);

	 if (mmplayer->audio_stream_idx >= 0)
    {
        pthread_create(&audio_tid, NULL, sstar_audio_process, (void *)mmplayer);
    }

    if (mmplayer->video_stream_idx >= 0)
    {
        pthread_create(&video_tid, NULL, sstar_video_process, (void *)mmplayer);
    }

	pthread_create(&av_tid, NULL, mmplayer_av_process, (void *)mmplayer);

	

    mmplayer_static = mmplayer;


	return 0;
	
}



MI_S32 kjd_play_mp4(const char *path,int ao_volume)
{

	//解绑jpd-scl
	ST_Sys_BindInfo_T stSysBindInfo;

	if(fp_g_exit == true)
	{

	/*	memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	    stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
	    stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	    stSysBindInfo.stSrcChnPort.u32PortId = 1;
	    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
	    stSysBindInfo.stDstChnPort.u32DevId = 3;
	    stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
	    stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
	    stSysBindInfo.u32SrcFrmrate = 30;
	    stSysBindInfo.u32DstFrmrate = 30;
	    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	    ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);*/
		
        St_ResizeLayer(0);
        //xz
		//usleep(3000*1000);
        printf("#################\n");
		memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		Device_Handle_t *video_dev = pvideo_dev;
		
		if (g_i_MainViewFlag == 0)//当前Usb摄像头为主视频 
		{				 
            if (g_i_InitMipiFlag == 1)//已经初始化过Mipi摄像头
			{				
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
					stSysBindInfo.stSrcChnPort.u32DevId = 0;
					stSysBindInfo.stSrcChnPort.u32ChnId = 0;
					stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
					stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
					stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
					stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
					stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
					stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
					stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
					stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
					ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
                    //xz
                   // usleep(3000*1000);
                    printf("^^^^^^^^^^^^^^^^^^6\n");
			}
			else//还没初始化过Mipi摄像头
			{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
					stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
					stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
					stSysBindInfo.stDstChnPort.u32DevId = 0;
					stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
					stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
					stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
					stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
					stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
					ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);	
                    //xz
                    //usleep(3000*1000);		
                    printf("$$$$$$$$$$$$$$$$$$$$$$$\n");	
			}
		}
		else//当前Mipi摄像头为主视频
		{
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
			stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
			stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
			stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
			stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
			stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;
			stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
			stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
			stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
			stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
			stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
		}		
		
	}

	//停掉摄像头的流
	g_stream = true;



	b_exit = false;
    //usleep(3000*1000);
    printf("%%%%%%%%%%%%%%%%%%%%%\n");

	int ret = mmplayer(path,ao_volume);
	if(ret == 0)
	{
		printf("mmplayer success! \n");
	}
	else
	{
		printf("mmplayer fail! \n");
	}

	
	return 0;
}

MI_S32 kjd_stopplay_mp4(void)
{
  //  printf("=====4923=============== \n");	
	b_exit = true;

	if(av_tid != NULL)
	{
		pthread_join(av_tid, NULL);
	}


	ST_Sys_BindInfo_T stSysBindInfo;

	if(fp_g_exit == true)
	{
		//change_scl_resolution(pvideo_dev->height,pvideo_dev->width,3, SCL_CHN_ID, SCL_PORT_ID);
	/*	change_scl_resolution(1280,800,3, SCL_CHN_ID, SCL_PORT_ID);
		memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
		stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
		stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
		stSysBindInfo.stSrcChnPort.u32PortId = 1;
		stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
		stSysBindInfo.stDstChnPort.u32DevId = 3;
		stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
		stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
		stSysBindInfo.u32SrcFrmrate = 30;
		stSysBindInfo.u32DstFrmrate = 30;
		stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
       // printf("=====4949=============== \n");	
		ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);*/

	    change_scl_resolution(SCL_SMALL_WIDTH,SCL_SMALL_HEIGHT,3, SCL_CHN_ID, SCL_PORT_ID);


        St_ResizeLayer(1);

		memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		Device_Handle_t *video_dev = pvideo_dev;
		
		if (g_i_MainViewFlag == 0)//当前Usb摄像头为主视频 
		{				 
            if (g_i_InitMipiFlag == 1)//已经初始化过Mipi摄像头
			{		
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_ISP;
					stSysBindInfo.stSrcChnPort.u32DevId = 0;
					stSysBindInfo.stSrcChnPort.u32ChnId = 0;
					stSysBindInfo.stSrcChnPort.u32PortId = 1;//0;
					stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
					stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;//1
					stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
					stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
					stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
					stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
					stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
					ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
			}
			else//还没初始化过Mipi摄像头
			{
					stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
					stSysBindInfo.stSrcChnPort.u32DevId = 3;//SCL_DEV_ID;
					stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
					stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;
					stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_DISP;
					stSysBindInfo.stDstChnPort.u32DevId = 0;
					stSysBindInfo.stDstChnPort.u32ChnId = 16;//DISP_CHN_ID;
					stSysBindInfo.stDstChnPort.u32PortId = 0;//DISP_PORT_ID;
					stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
					stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
					stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
					ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);				
			}
		}
		else//当前Mipi摄像头为主视频
		{
			stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
			stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
			stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
			stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
			stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
			stSysBindInfo.stDstChnPort.u32DevId = 3;//SCL_DEV_ID;
			stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
			stSysBindInfo.stDstChnPort.u32PortId = 0;//SCL_PORT_ID;
			stSysBindInfo.u32SrcFrmrate = video_dev->frame_rate;
			stSysBindInfo.u32DstFrmrate = video_dev->frame_rate;
			stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
			ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
		}		


	}

	g_stream = false;

	return 0;
}




MI_S32 start_vdec(const char *path)
{	
	//g_exit = true;
	//pthread_join(stream_tid, NULL);
	g_stream = true;
	

	ST_Sys_BindInfo_T stSysBindInfo;
	memset(&stSysBindInfo, 0, sizeof(stSysBindInfo));

	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
    stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
    stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
    stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
    stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
    stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
    stSysBindInfo.u32SrcFrmrate = pvideo_dev->frame_rate;
    stSysBindInfo.u32DstFrmrate = pvideo_dev->frame_rate;
    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
    ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
	ExecFunc(St_JpdModuleDeinit(pvideo_dev), MI_SUCCESS);

	ExecFunc(St_VdecModuleInit(pvideo_dev), MI_SUCCESS);
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VDEC;
    stSysBindInfo.stSrcChnPort.u32DevId = VDEC_DEV_ID;
    stSysBindInfo.stSrcChnPort.u32ChnId = VDEC_CHN_ID;
    stSysBindInfo.stSrcChnPort.u32PortId = VDEC_PORT_ID;
    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
    stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
    stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
    stSysBindInfo.u32SrcFrmrate = 0;
    stSysBindInfo.u32DstFrmrate = 0;
    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
    ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);


	g_stVdecThreadArgs.vdecChn = VDEC_CHN_ID;
	g_stVdecThreadArgs.bRunFlag = true;
	snprintf(g_stVdecThreadArgs.szFileName, sizeof(g_stVdecThreadArgs.szFileName) - 1, path);
    g_stVdecThreadArgs.bEsAddHead = 0;
	g_PushEsExit = FALSE;

	pthread_create(&g_stVdecThreadArgs.pt, NULL, ST_VdecSendStream, (void *)&g_stVdecThreadArgs);

	return 0;
}

MI_S32 stop_vdec(void)
{
	g_PushEsExit = true;
	pthread_join(g_stVdecThreadArgs.pt, NULL);
	ST_Sys_BindInfo_T stSysBindInfo;
	memset(&stSysBindInfo, 0, sizeof(stSysBindInfo));


	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VDEC;
    stSysBindInfo.stSrcChnPort.u32DevId = VDEC_DEV_ID;
    stSysBindInfo.stSrcChnPort.u32ChnId = VDEC_CHN_ID;
    stSysBindInfo.stSrcChnPort.u32PortId = VDEC_PORT_ID;
    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
    stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
    stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
    stSysBindInfo.u32SrcFrmrate = 0;
    stSysBindInfo.u32DstFrmrate = 0;
    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
    ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);
	ExecFunc(St_VdecModuleDeinit(pvideo_dev), MI_SUCCESS);

	ExecFunc(St_JpdModuleInit(pvideo_dev), MI_SUCCESS);
	stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_JPD;
	stSysBindInfo.stSrcChnPort.u32DevId = JPD_DEV_ID;
	stSysBindInfo.stSrcChnPort.u32ChnId = JPD_CHN_ID;
	stSysBindInfo.stSrcChnPort.u32PortId = JPD_PORT_ID;
	stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
	stSysBindInfo.stDstChnPort.u32DevId = SCL_DEV_ID;
	stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
	stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
	stSysBindInfo.u32SrcFrmrate = pvideo_dev->frame_rate;
	stSysBindInfo.u32DstFrmrate = pvideo_dev->frame_rate;
	stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);

	//g_exit = false;
	//pthread_create(&stream_tid, NULL, uvc_stream, NULL);
	g_stream = false;

	return 0;
	
}

int stopplay(void)
{
	mp4_exit = true;
}

int startplay(void)
{
	mp4_exit = false;
}


int start_video(void)
{
	g_stream = false;
}

int stop_video(void)
{
	g_stream = true;
}


int panel_lock(void)
{
	g_stream = true;
}

int panel_unlock(void)
{
	g_stream = false;
}




static bool m_bNeedGlobalHeader;
static bool m_bHadFillGlobalHeader;
static SwrContext *acc_ctx = NULL;
static AVFrame *frame = NULL;
static AVPacket *pkt = NULL;
static bool synchronization = false;

pthread_mutex_t MP4_audio_mutex;
//pthread_mutex_t MP4_video_mutex;

pthread_cond_t MP4_audio_cond;
pthread_cond_t MP4_video_cond;


static int64_t MP4_video_pts = 0;
static int64_t MP4_audio_pts = 0;
static FILE* MP4_fd=NULL;










/* check that a given sample format is supported by the encoder */
static int check_sample_fmt(const AVCodec *codec, enum AVSampleFormat sample_fmt)
{
    const enum AVSampleFormat *p = codec->sample_fmts;

    while (*p != AV_SAMPLE_FMT_NONE) {
        if (*p == sample_fmt)
            return 1;
        p++;
    }
    return 0;
}

static int select_channel_layout(const AVCodec *codec)
{
    const uint64_t *p;
    uint64_t best_ch_layout = 0;
    int best_nb_channels   = 0;

    if (!codec->channel_layouts)
        return AV_CH_LAYOUT_STEREO;

    p = codec->channel_layouts;
    while (*p) {
        int nb_channels = av_get_channel_layout_nb_channels(*p);

        if (nb_channels > best_nb_channels) {
            best_ch_layout    = *p;
            best_nb_channels = nb_channels;
        }
        p++;
    }
    return best_ch_layout;
}

static int select_sample_rate(const AVCodec *codec)
{
    const int *p;
    int best_samplerate = 0;

    if (!codec->supported_samplerates)
        return 44100;

    p = codec->supported_samplerates;
    while (*p) {
        if (!best_samplerate || abs(44100 - *p) < abs(44100 - best_samplerate))
            best_samplerate = *p;
        p++;
    }
    return best_samplerate;
}


MI_S32 initAi(int AiVolume, Device_Handle_t *video_dev)
{
    MI_AUDIO_Attr_t     stAiSetAttr;
    MI_AUDIO_Attr_t     stAiGetAttr;
    MI_U32              u32ChnCnt = 1;
    MI_S32              s32Ret;

    MI_SYS_ChnPort_t    stAiChnOutputPort0[MI_AUDIO_MAX_CHN_NUM];


    memset(&stAiSetAttr, 0x0, sizeof(MI_AUDIO_Attr_t));
    memset(&stAiGetAttr, 0x0, sizeof(MI_AUDIO_Attr_t));
    stAiSetAttr.eBitwidth = E_MI_AUDIO_BIT_WIDTH_16;
    stAiSetAttr.eSamplerate = E_MI_AUDIO_SAMPLE_RATE_16000;
    stAiSetAttr.eSoundmode = E_MI_AUDIO_SOUND_MODE_MONO;
    stAiSetAttr.eWorkmode = E_MI_AUDIO_MODE_I2S_MASTER;
    stAiSetAttr.u32ChnCnt = u32ChnCnt;
    stAiSetAttr.u32PtNumPerFrm = 1024; // for aec
    stAiSetAttr.WorkModeSetting.stI2sConfig.bSyncClock = FALSE;
    stAiSetAttr.WorkModeSetting.stI2sConfig.eFmt = E_MI_AUDIO_I2S_FMT_I2S_MSB;
    stAiSetAttr.WorkModeSetting.stI2sConfig.eMclk = E_MI_AUDIO_I2S_MCLK_0;
    stAiSetAttr.WorkModeSetting.stI2sConfig.u32TdmSlots = 4;
	stAiSetAttr.WorkModeSetting.stI2sConfig.eI2sBitWidth = E_MI_AUDIO_BIT_WIDTH_16;




 

    ExecFunc(MI_AI_SetPubAttr(0, &stAiSetAttr), MI_SUCCESS);
    ExecFunc(MI_AI_GetPubAttr(0, &stAiGetAttr), MI_SUCCESS);
    ExecFunc(MI_AI_Enable(0), MI_SUCCESS);


    ExecFunc(MI_AI_SetVqeVolume(0, 0, AiVolume), MI_SUCCESS);

 
    memset(&stAiChnPriv, 0x0, sizeof(stAiChnPriv));
    memset(&stAiChnOutputPort0, 0x0, sizeof(stAiChnOutputPort0));





    stAiChnPriv.AiChn = 0;
    stAiChnPriv.AiDevId = 0;
    stAiChnPriv.u32ChnCnt = u32ChnCnt;
    stAiChnPriv.u32TotalSize = 0;

    stAiChnOutputPort0[0].eModId = E_MI_MODULE_ID_AI;
    stAiChnOutputPort0[0].u32DevId = 0;
    stAiChnOutputPort0[0].u32ChnId = 0;
    stAiChnOutputPort0[0].u32PortId = 0;
    ExecFunc(MI_SYS_SetChnOutputPortDepth(0, &stAiChnOutputPort0[0], USER_BUF_DEPTH, TOTAL_BUF_DEPTH), MI_SUCCESS);
    ExecFunc(MI_AI_EnableChn(0, 0), MI_SUCCESS);
    //pthread_create(&stAiChnPriv.tid, NULL, aiGetChnPortBuf, &stAiChnPriv);

    //printf("create ai thread.\n");
    return 0;

}


const int sampling_frequencies[] = {
    96000,  // 0x0
    88200,  // 0x1
    64000,  // 0x2
    48000,  // 0x3
    44100,  // 0x4
    32000,  // 0x5
    24000,  // 0x6
    22050,  // 0x7
    16000,  // 0x8
    12000,  // 0x9
    11025,  // 0xa
    8000   // 0xb
    // 0xc d e f是保留的
};



int adts_header(char * const p_adts_header, const int data_length,
                const int profile, const int samplerate,
                const int channels)
{

    int sampling_frequency_index = 3; // 默认使用48000hz
    int adtsLen = data_length + 7;
    //ADTS不是单纯的data，是hearder+data的，所以加7这个头部hearder的长度，这里7是因为后面protection absent位设为1，不做校验，所以直接加7，如果做校验，可能会是9

    int frequencies_size = sizeof(sampling_frequencies) / sizeof(sampling_frequencies[0]);
    int i = 0;
    for(i = 0; i < frequencies_size; i++)   //查找采样率
    {
        if(sampling_frequencies[i] == samplerate)
        {
            sampling_frequency_index = i;
            break;
        }
    }
    if(i >= frequencies_size)
    {
        printf("unsupport samplerate:%d\n", samplerate);
        return -1;
    }

    p_adts_header[0] = 0xff;         //syncword:0xfff                          高8bits
    p_adts_header[1] = 0xf0;         //syncword:0xfff                          低4bits
    p_adts_header[1] |= (0 << 3);    //MPEG Version:0 for MPEG-4,1 for MPEG-2  1bit
    p_adts_header[1] |= (0 << 1);    //Layer:0                                 2bits
    p_adts_header[1] |= 1;           //protection absent:1                     1bit

    p_adts_header[2] = (profile)<<6;            //profile:profile               2bits
    p_adts_header[2] |= (sampling_frequency_index & 0x0f)<<2; //sampling frequency index:sampling_frequency_index  4bits
    p_adts_header[2] |= (0 << 1);             //private bit:0                   1bit
    p_adts_header[2] |= (channels & 0x04)>>2; //channel configuration:channels  高1bit

    p_adts_header[3] = (channels & 0x03)<<6; //channel configuration:channels 低2bits
    p_adts_header[3] |= (0 << 5);               //original：0                1bit
    p_adts_header[3] |= (0 << 4);               //home：0                    1bit
    p_adts_header[3] |= (0 << 3);               //copyright id bit：0        1bit
    p_adts_header[3] |= (0 << 2);               //copyright id start：0      1bit
    p_adts_header[3] |= ((adtsLen & 0x1800) >> 11);           //frame length：value   高2bits

    p_adts_header[4] = (uint8_t)((adtsLen & 0x7f8) >> 3);     //frame length:value    中间8bits
    p_adts_header[5] = (uint8_t)((adtsLen & 0x7) << 5);       //frame length:value    低3bits
    p_adts_header[5] |= 0x1f;                                 //buffer fullness:0x7ff 高5bits
    p_adts_header[6] = 0xfc;      //11111100       //buffer fullness:0x7ff 低6bits
    // number_of_raw_data_blocks_in_frame：
    //    表示ADTS帧中有number_of_raw_data_blocks_in_frame + 1个AAC原始帧。

    return 0;
}






static void *audio_mp4_pth(void *arg)
{
	AVFormatContext *audio_format_ctx = (AVFormatContext *)arg;
	AVStream *stream = audio_format_ctx->streams[1];
	AVPacket pkt_acc;
	int ret = -1;
	int m_frameNum = 0;
	uint8_t *acc_in[AV_NUM_DATA_POINTERS];
	uint8_t **acc_out = NULL;
	int acc_size = 0;
	int i = 0;

	char is_first_flag = 0;
	MI_U64 last_pts = 0;
	double audio_time_Start;
    double audio_time_End ;
	


	AiChnPriv_t* priv = &stAiChnPriv;
    MI_AUDIO_Frame_t stAiChFrame;
    MI_AUDIO_AecFrame_t stAecFrame;
    MI_S32 s32Ret;
    MI_U32 u32ChnIndex;


    memset(&stAiChFrame, 0, sizeof(MI_AUDIO_Frame_t));
    memset(&stAecFrame, 0, sizeof(MI_AUDIO_AecFrame_t));

#if 1
	char adts_header_buf[7] = {0};

    int64_t pts = 0;
	int64_t delay = 0;
	int                 dst_nb_samples;
	int                 max_dst_nb_samples; 
	int                 src_nb_samples  = 1024; 
	int                 dst_linesize = 0;
	int                 dst_bufsize;
	int                 dst_nb_channels = av_get_channel_layout_nb_channels(AV_CH_LAYOUT_MONO);

	//拿到音频帧的字节数
	int frame_bytes = av_get_bytes_per_sample(AV_SAMPLE_FMT_S16) \
            * frame->channels \
            * frame->nb_samples;
    printf("frame_bytes %d\n", frame_bytes);


    // 计算输出采样数量
    max_dst_nb_samples = dst_nb_samples = av_rescale_rnd(src_nb_samples, 16000, 16000, AV_ROUND_UP);


    //申请对应采样值的空间
	ret = av_samples_alloc_array_and_samples((uint8_t***)&acc_out, &dst_linesize, dst_nb_channels, dst_nb_samples, AV_SAMPLE_FMT_S16, 0);
    if (ret < 0)
	{ 
		printf(" fisrt av_samples_alloc_array_and_samples fail \n"); 
	}

#endif

	MI_SYS_ChnPort_t stChnPort;
	MI_S32 s32AiFd;
	fd_set read_fds;

	memset(&stChnPort, 0, sizeof(stChnPort));

	stChnPort.eModId = E_MI_MODULE_ID_AI;
	stChnPort.u32DevId = 0;
	stChnPort.u32ChnId = 0;
	stChnPort.u32PortId = 0;

	s32Ret = MI_SYS_GetFd(&stChnPort, &s32AiFd);
	if(MI_SUCCESS != s32Ret)
	{
	    ST_ERR("MI_SYS_GetFd 0, error, %X\n", s32Ret);
	    return NULL;
	}


    while(!audio_pth_g_exit)
    {	

		FD_ZERO(&read_fds);
        FD_SET(s32AiFd, &read_fds);
        s32Ret = select(s32AiFd+1, &read_fds, NULL, NULL, NULL);
        if (s32Ret < 0)
        {
            printf("select err\n");
        }
        else if (0 == s32Ret)
        {
            printf("timeout\n");
        }
        else
        {
            if (FD_ISSET(s32AiFd, &read_fds))
            {
            

		        s32Ret = MI_AI_GetFrame(priv->AiDevId, priv->AiChn, &stAiChFrame, &stAecFrame, -1);
		        if (MI_SUCCESS == s32Ret && audio_pth_g_exit == false)
		        {

					//读数据 1113
					acc_in[0] = (uint8_t *)stAiChFrame.apVirAddr[0];
					//acc_size = stAiChFrame.u32Len[0];
				   

		       

#if 0
					delay = swr_get_delay(acc_ctx, 16000); // swr_convert可能有没转换的数据，这里需要获取缓存
					// 计算新的采样数量 dst_nb_samples = (delay + src_nb_samples) * OUT_RATE / IN_RATE，结果向上取整
					dst_nb_samples = av_rescale_rnd(delay + src_nb_samples, 16000, 16000, AV_ROUND_UP);
					if (dst_nb_samples > max_dst_nb_samples) {// 采样数量不够大，重新分配
						av_freep(&acc_out[0]);
			        	ret = av_samples_alloc(acc_out, &dst_linesize, dst_nb_channels, dst_nb_samples, AV_SAMPLE_FMT_FLTP, 1);
			        	if (ret < 0) { 
							printf("  av_samples_alloc fail \n"); 
						}       
						max_dst_nb_samples = dst_nb_samples; // 更新最大采样数量
			    	}

				






					//重采样,返回值是采样的点数
					ret = swr_convert(acc_ctx,acc_out,dst_nb_samples,
										(const uint8_t**)acc_in,src_nb_samples);	
					
					if (ret < 0) {
						fprintf(stderr, "Error swr_convert  %d: %s\n",ret, av_err2str(ret));
						break;
					}
					acc_size = ret;
					


					
					//将采样点转换为字节
					if ((dst_bufsize = av_samples_get_buffer_size(&dst_linesize, dst_nb_channels, ret, AV_SAMPLE_FMT_FLTP, 1)) < 0)
					{ 
						printf("av_samples_get_buffer_size \n");
					}
					//printf("acc_size len = %d , %d \n",acc_size , dst_bufsize);

					while(( acc_size - 1024) >= 0){
						acc_size = acc_size - 1024;
					
#endif	

#if 1
					 

					
						//拷贝数据
						avcodec_fill_audio_frame(frame, dst_nb_channels, AV_SAMPLE_FMT_S16,
			                         (const uint8_t *) acc_in[0] , frame_bytes, 1);
			            //memcpy(frame->data[0],acc_out[0] + j*frame_bytes,frame_bytes);


						//送帧给编码器
						ret = avcodec_send_frame(stream->codec, frame);
					    if (ret < 0) {
					        fprintf(stderr, "Error sending the frame to the encoder  %d: %s\n",ret, av_err2str(ret));
					        continue;
					    }
						
						/* read all the available output packets (in general there may be any number of them */
					    // 编码和解码都是一样的，都是send 1次，然后receive多次, 直到AVERROR(EAGAIN)或者AVERROR_EOF
					    while (ret >= 0) {
					        ret = avcodec_receive_packet(stream->codec, pkt);
					        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) 
							{
								//fprintf(stderr, "no data  frame\n");
					            break;
					        }
							else if (ret < 0) {
					            fprintf(stderr, "Error encoding audio frame\n");
					            continue;
					        }


							pkt->dts = pkt->pts = av_rescale_q(m_frameNum * 1024 ,stream->codec->time_base , stream->time_base);
							pkt->duration = 0;
							pkt->stream_index = 1;
							printf("+++++++++++audio write pts = %llu  %d\n",pkt->pts,stream->time_base.den);

							MP4_audio_pts = pkt->pts;
							pthread_mutex_lock(&MP4_audio_mutex);
							if(pkt->pts > MP4_video_pts)
							{
								
								//pthread_cond_wait(&MP4_audio_cond, &MP4_audio_mutex);
								pthread_cond_signal(&MP4_audio_cond);
								ret = av_interleaved_write_frame(audio_format_ctx, pkt);
								if(ret < 0)
								{
								 	 printf("+++++++++++audio av_interleaved_write_frame failed\n");
								}

							}
							else
							{
								
								ret = av_interleaved_write_frame(audio_format_ctx, pkt);
								if(ret < 0)
								{
								 	 printf("+++++++++++audio av_interleaved_write_frame failed\n");
								}
								
							}

							pthread_mutex_unlock(&MP4_audio_mutex);


							m_frameNum++;
							
						}
					//}

				    
			        
#endif		   


#if 0	



					
					
			
				av_init_packet(&pkt_acc);	
				//pkt.flags |= bIsIDR ? AV_PKT_FLAG_KEY : 0;
				pkt_acc.stream_index = stream->index;
				pkt_acc.data = (uint8_t *)stAiChFrame.apVirAddr[0];
				pkt_acc.size = stAiChFrame.u32Len[0];		
				//pkt.pts = audio_format_ctx->streams[0]->time_base.den/16 * m_frameNum;
				//pkt.pts = m_frameNum * (stream->time_base.den/16);
				pkt_acc.pts = av_rescale_q(m_frameNum * 1000 ,stream->codec->time_base , stream->time_base);
				pkt_acc.dts = pkt_acc.pts;
				pkt_acc.duration = 0;
				//pkt.duration = av_rescale_q(pkt.duration ,stream->time_base , stream->time_base);	//0 if unknown.
				pkt_acc.pos = -1;		//-1 if unknown


				//pkt.dts = pkt.pts = (stAiChFrame.u64TimeStamp - fist_pts)/1000000.0 /  av_q2d(stream->time_base);





				printf("audio write pts = %llu  %d\n",pkt_acc.pts,stream->time_base.den);
				
				
				ret = av_interleaved_write_frame(audio_format_ctx, &pkt_acc);
				if(ret < 0)
				{
				 	 printf("av_interleaved_write_frame failed\n");
				}
				else
				{
					 //printf("audio write pts = %llu  %llu\n",pkt.pts,pkt.duration);
				}

				m_frameNum++;
				
#endif
					MI_AI_ReleaseFrame(priv->AiDevId, priv->AiChn,  &stAiChFrame,  NULL);
				}
		        else
		        {
		        	
		        }
		
            }
        }

        
    }
	avcodec_send_frame(stream->codec, NULL);
	while(avcodec_receive_packet(stream->codec, pkt)!=AVERROR_EOF);
    printf("Dev%dChn%d get frame failed!!!error:0x%x\n", priv->AiDevId, priv->AiChn, s32Ret);



    MI_AI_DisableChn(0, 0);
    MI_AI_Disable(0);



	av_freep(&acc_out[0]);

#if 0	

	pthread_mutex_destroy(&MP4_audio_mutex);
	//pthread_mutex_destroy(&MP4_video_mutex);
    pthread_cond_destroy(&MP4_audio_cond);
	//pthread_cond_destroy(&MP4_video_cond);

	MP4_video_pts = 0;
	MP4_audio_pts = 0;

	if(acc_ctx != NULL)
	{
		swr_free(&acc_ctx);
		av_frame_free(&frame);
		av_packet_free(&pkt);
	}


	

	av_write_trailer(audio_format_ctx);
	if (audio_format_ctx && !(audio_format_ctx->flags & AVFMT_NOFILE))
		avio_close(audio_format_ctx->pb);

	//avcodec_close(video_stream->codec);


	avformat_free_context(audio_format_ctx);

	audio_format_ctx = NULL;
#endif

    return NULL;
}


static void *video_mp4_pth(void *arg)
{
	MI_S32 s32Ret = MI_SUCCESS;
    MI_SYS_ChnPort_t stChnPort;
    MI_VENC_Stream_t stStream;
    MI_VENC_Pack_t stPack;
    MI_U32 u32BypassCnt = 1;
    MI_U32 i=0;
	MI_U32 j=0;
	MI_U8 *pps_sps_buff = NULL;

	AVFormatContext *pvideo_format_ctx = (AVFormatContext *)arg;
	bool m_bFoundFirstIDR = false;
	bool bIsIDR;
	AVStream *stream = pvideo_format_ctx->streams[0];
	AVPacket pkt_mp4;
	MI_S64 m_frameNum = 0;
	int ret = -1;
    
//	MI_VENC_FrameHistoStaticInfo_t ppFrmHistoStaticInfo;
//	memset(&ppFrmHistoStaticInfo, 0, sizeof(MI_VENC_FrameHistoStaticInfo_t));
//	MI_VENC_FrameHistoStaticInfo_t *p = &ppFrmHistoStaticInfo;
    MI_VENC_DEV  VencDev = MI_VENC_DEV_ID_H264_H265_0;
    MI_VENC_CHN VencChn = 1;


	
    s32Ret = MI_VENC_StartRecvPic(VencDev,VencChn);

    if(MI_SUCCESS != s32Ret)
    {
        ST_ERR("ST_Venc_StartChannel fail, 0x%x\n", s32Ret);
		return NULL;
    }


    memset(&stStream, 0, sizeof(MI_VENC_Stream_t));
    memset(&stPack, 0, sizeof(MI_VENC_Pack_t));
    stStream.pstPack = &stPack;
    stStream.u32PackCount = 1;


    MI_S32 s32VencFd;
    fd_set read_fds;
    MI_VENC_ChnStat_t stStat;
    memset(&stStat, 0, sizeof(MI_VENC_ChnStat_t));
    s32VencFd = MI_VENC_GetFd(VencDev, VencChn);



	double audio_time_Start;
    double audio_time_End ;
	MI_S64 mp4_pts;
	MI_U64 stream_pts;
	char add_frame = 0;
	char audio_video_pts_flag = 1;
	struct timeval time_fd;
	time_fd.tv_sec = 2;
	time_fd.tv_usec = 0;
	
	//audio_time_Start = (double)clock();
	
	
	
    while(!video_pth_g_exit)
	{
        FD_ZERO(&read_fds);
        FD_SET(s32VencFd, &read_fds);
        s32Ret = select(s32VencFd+1, &read_fds, NULL, NULL, &time_fd);
        if (s32Ret < 0)
        {
            printf("select err\n");
        }
        else if (0 == s32Ret)
        {
            //printf("timeout\n");
        }
        else
        {
            if (FD_ISSET(s32VencFd, &read_fds))
            {
			
                s32Ret = MI_VENC_Query(VencDev, VencChn, &stStat);
                if (0 == stStat.u32CurPacks )
                {
                    continue;
                }
				

                stStream.pstPack = (MI_VENC_Pack_t*)malloc(sizeof(MI_VENC_Pack_t)*stStat.u32CurPacks);
                stStream.u32PackCount = stStat.u32CurPacks;
                s32Ret = MI_VENC_GetStream(VencDev, VencChn, &stStream, -1);

                if (MI_SUCCESS == s32Ret )
                {
                	//判断是否是I帧
					if(stStream.pstPack->stDataType.eH264EType == E_MI_VENC_H264E_NALU_ISLICE)
					{
						bIsIDR = true;
					}
					else
					{
						bIsIDR = false;
					}

					

					//判断第一帧是否是I帧
					if(!m_bFoundFirstIDR)
					{
						if(!bIsIDR)
						{
							printf("bIsIDR = false\n");
							s32Ret = MI_VENC_ReleaseStream(VencDev, VencChn, &stStream);
			                if (MI_SUCCESS != s32Ret)
			                {
			                	ST_ERR("MI_VENC_ReleaseStream fail, 0x%x\n", s32Ret);
			                }
							free(stStream.pstPack);
		                    stStream.pstPack=NULL;
							pps_sps_buff=NULL;
							continue;
							
						}
						else
						{
							m_bFoundFirstIDR = true;
						}
					}

					if(add_frame == 0)
					{
						mp4_pts = 0;
                        add_frame = 1;
					}
					else
					{
						mp4_pts = (stStream.pstPack->u64PTS - stream_pts)/1000000.0 * 16000;
						if(mp4_pts > 16000 / pvideo_dev->frame_rate * 2)
							mp4_pts = 16000 / pvideo_dev->frame_rate * 2;
						printf("MI_VENC_GetStream pts = %llu \n",mp4_pts);
					}
					stream_pts = stStream.pstPack->u64PTS;

					//计算实际帧率
					//audio_time_End = (double)clock();
					//printf("video get stream  time = %lf ms\n",(audio_time_End - audio_time_Start )/1000.0);
					//audio_time_Start = (double)clock();

					for (i=0; i<stStream.u32PackCount; i++)
	                {
						//当需要global header时，将SPS, PPS, SEI填入CodecContext的extradata
						if(bIsIDR && m_bNeedGlobalHeader )
						{
							if(!m_bHadFillGlobalHeader )
							{
								m_bHadFillGlobalHeader = true;
								pps_sps_buff = stStream.pstPack[i].pu8Addr + stStream.pstPack[i].u32Offset;

								//读取 pps_sps_buff 后面的值判断 i的大小
								for(i=0;i<1024;i++) 
								{
									printf("  %#x",*(pps_sps_buff+i));
									if(*(pps_sps_buff+i) == 0x0)
									{
										j++;
										if(j == 3 && *(pps_sps_buff+i+2) == 0x65 && *(pps_sps_buff+i+1) == 0x1)
										{
											i = i - 2;
											break;
										}
									}
									else
									{
										j=0;
									}
								}
								printf("\n");
								if(i == 1024)
									i = 100;
								//extradata空间大小只需能装下SPS,PPS,SEI等即可
								printf(" i = %d\n",i);

								stream->codecpar->extradata = (uint8_t*)av_malloc(i+64);
								//一定要写0
								stream->codecpar->extradata_size = i;
								
								memcpy(stream->codecpar->extradata, stStream.pstPack[0].pu8Addr + stStream.pstPack[0].u32Offset ,i);
								
							}
							
						}
						i = 0;

						//printf("av_init_packet up\n");
						av_init_packet(&pkt_mp4);	
						//printf("av_init_packet down\n");
						pkt_mp4.flags |= bIsIDR ? AV_PKT_FLAG_KEY : 0;
						pkt_mp4.stream_index = stream->index;
						pkt_mp4.data = (unsigned char*)(stStream.pstPack[i].pu8Addr + stStream.pstPack[i].u32Offset);
						pkt_mp4.size = stStream.pstPack[i].u32Len - stStream.pstPack[i].u32Offset;	
						//pkt.pts = pvideo_format_ctx->streams[0]->time_base.den/30 * m_frameNum;
						//pkt_mp4.pts = (44100 / pvideo_dev->frame_rate)*m_frameNum;
						//pkt_mp4.pts = av_rescale_q((16000 / pvideo_dev->frame_rate)*m_frameNum ,stream->codec->time_base , stream->time_base);
						m_frameNum += (mp4_pts * audio_video_pts_flag);
						pkt_mp4.pts = m_frameNum;
						pkt_mp4.dts = pkt_mp4.pts;
						pkt_mp4.duration = 0;	//0 if unknown.
						pkt_mp4.pos = -1;		//-1 if unknown
						
						//pkt.dts = pkt.pts = (stStream.pstPack[i].u64PTS - fist_pts)/1000000.0 /  av_q2d(stream->time_base);

	 

//						printf("------------video write av_interleaved_write_frame pts = %llu   %d  %d\n",pkt_mp4.pts,stream->time_base.den ,stream->codec->time_base.den);
						MP4_video_pts = pkt_mp4.pts;
						
						

						pthread_mutex_lock(&MP4_audio_mutex);

						
						if(pkt_mp4.pts > (MP4_audio_pts + 2048)  )
						{
							audio_video_pts_flag = 1;
							if(audio_pth_g_exit == false)
							{
								pthread_cond_wait(&MP4_audio_cond, &MP4_audio_mutex);
							}
						}
						else if(pkt_mp4.pts < (MP4_audio_pts - 2048))
						{
							audio_video_pts_flag = 2;
						}
						else
						{
							audio_video_pts_flag = 1;
						}
						ret = av_interleaved_write_frame(pvideo_format_ctx, &pkt_mp4);
						if(ret < 0)
						{
						 	 printf("------------video av_interleaved_write_frame failed\n");
						}

						pthread_mutex_unlock(&MP4_audio_mutex);


					}


	                s32Ret = MI_VENC_ReleaseStream(VencDev, VencChn, &stStream);


	                if (MI_SUCCESS != s32Ret)
	                {
	                	ST_ERR("MI_VENC_ReleaseStream fail, 0x%x\n", s32Ret);
	                }
					free(stStream.pstPack);
                    stStream.pstPack=NULL;
					pps_sps_buff=NULL;
					
                }

                free(stStream.pstPack);
                stStream.pstPack = NULL;
				pps_sps_buff=NULL;
				 
            }
			else
			{
				printf("FD_ISSET fail\n");
			}
        }
        //QMutexLocker locker(&mWaitMutex);
    }

	printf("pthread exit \n");

    s32Ret = MI_VENC_StopRecvPic(VencDev,VencChn);
	if(MI_SUCCESS != s32Ret)
    {
        ST_ERR("MI_VENC_StopRecvPic fail, 0x%x\n", s32Ret);
    }

	pthread_mutex_destroy(&MP4_audio_mutex);
	//pthread_mutex_destroy(&MP4_video_mutex);
    pthread_cond_destroy(&MP4_audio_cond);
	//pthread_cond_destroy(&MP4_video_cond);

	MP4_video_pts = 0;
	MP4_audio_pts = 0;

	if(acc_ctx != NULL)
	{
		swr_free(&acc_ctx);
		av_frame_free(&frame);
		av_packet_free(&pkt);
	}

	av_write_trailer(pvideo_format_ctx);
	if (pvideo_format_ctx && !(pvideo_format_ctx->flags & AVFMT_NOFILE))
		avio_close(pvideo_format_ctx->pb);

	
	if(stream->codec->extradata != NULL)
	{
		free(stream->codec->extradata);
		stream->codec->extradata = NULL;
	}
	avcodec_close(stream->codec);

	avformat_free_context(pvideo_format_ctx);

	pvideo_format_ctx = NULL;
	
	printf("video return!\n");
	if(MP4_fd != NULL)
	{
		system("sync");
		fclose(MP4_fd);
	}
    return NULL;
}



int video_mp4(Device_Handle_t *video_dev,int ai_volume,char *pszFileName)
{

    char szFileName[120];
	
	sprintf(szFileName, "%s%s", "/mnt/VIDEO/",pszFileName);

	MP4_fd = fopen(szFileName,"ab+");
    if(MP4_fd == NULL)
    {
         system("mkdir /mnt/VIDEO");
         MP4_fd = fopen(szFileName,"ab+");
         if(MP4_fd == NULL)
         {
            printf("---------------------open false !------------------------------\n");
            return -1;
         }
    }


	initAi(ai_volume,video_dev);


	int ret = -1;
	AVFormatContext *m_format_ctx = NULL;
	AVOutputFormat *ofmt = NULL;
	AVStream *video_stream = NULL;
	AVStream *audio_stream = NULL;
	AVCodec *m_codec = NULL; 
	AVCodec *acc_codec = NULL;
	

	//注册ffmepg函数
	av_register_all();

	//拿到封装的上下文
	ret = avformat_alloc_output_context2(&m_format_ctx,NULL,NULL,szFileName);
	if(ret)
	{
		printf("video_mp4 avformat_alloc_output_context2 fail!\n");
		goto fail;
	}


	
	ofmt = m_format_ctx->oformat;		//获取输出Format指针
    if (ofmt->video_codec == AV_CODEC_ID_NONE)	//检查视频编码器
    {
        printf("Muxing:add_video_stream ID failed\n"); 
		goto fail;
	}
	if (ofmt->audio_codec == AV_CODEC_ID_NONE)	//检查音频编码器
    {
        printf("Muxing:add_audio_stream ID failed\n"); 
		goto fail;
	}

	//打开输出流文件句柄
	if(!(ofmt->flags & AVFMT_NOFILE))
	{
	 
		ret = avio_open(&m_format_ctx->pb, szFileName, AVIO_FLAG_WRITE );
		if (ret < 0)
		{
			printf("could not open %s error  %d: %s\n", szFileName,ret, av_err2str(ret));
			goto fail;
		}
	}
	
#if 1
	//根据id拿到编码器
	//ofmt = m_format_ctx->oformat;
	m_codec = avcodec_find_encoder(ofmt->video_codec);
	if(m_codec == NULL)
	{
		printf("video_mp4 avcodec_find_decoder fail!\n");
		goto fail;
	}




	

	//添加视频流信息
	video_stream = avformat_new_stream(m_format_ctx,m_codec);
	if(video_stream == NULL)
	{
		printf("video_mp4 avformat_new_stream fail!\n");
		goto fail;
	}

	//codecCtx = video_stream->codec;

	video_stream->codecpar->codec_id = AV_CODEC_ID_H264;
	video_stream->codecpar->height = video_dev->height;
	video_stream->codecpar->width = video_dev->width;
	//codecCtx->gop_size = 30;
	//video_stream->codecpar->bit_rate = 0;
	video_stream->codecpar->format = AV_PIX_FMT_YUV420P;
	//video_stream->codec->gop_size = 30;
	video_stream->codecpar->codec_type = AVMEDIA_TYPE_VIDEO;
	video_stream->index = 0;
	video_stream->codec->time_base.den = 16000;
	video_stream->codec->time_base.num = 1;
	video_stream->time_base = (AVRational){1, 16000};
	//video_stream->r_frame_rate.den = video_dev->frame_rate;

	


	//MP4格式需要全局头信息，AVI不需要	
	m_bNeedGlobalHeader = (m_format_ctx->oformat->flags & AVFMT_GLOBALHEADER);
	if(m_bNeedGlobalHeader)
	{ 		
		video_stream->codec->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
		m_bHadFillGlobalHeader = false;
	}

#endif

#if 1	
	//拿到aac编码器
	acc_codec = avcodec_find_encoder_by_name("libfdk_aac");
	//acc_codec = avcodec_find_encoder(AV_CODEC_ID_AAC);
	if(acc_codec == NULL)
	{
		printf("video_mp4 avcodec_find_decoder fail!\n");
		goto fail;
	}
	
	


	//添加音频流信息
	audio_stream = avformat_new_stream(m_format_ctx,acc_codec);
	if(audio_stream == NULL)
	{
		printf("video_mp4 avformat_new_stream fail!\n");
		goto fail;
	}

	//申请音频编码器上下文
	audio_stream->codec = avcodec_alloc_context3(acc_codec);
    if (!audio_stream->codec) {
        fprintf(stderr, "Could not allocate audio codec context\n");
        goto fail;
    }
	
#if 1
	audio_stream->codecpar->codec_id = AV_CODEC_ID_AAC;
	audio_stream->codecpar->codec_type = AVMEDIA_TYPE_AUDIO;
	audio_stream->codecpar->bit_rate = 64000;
	//audio_stream->codecpar->bit_rate = 0;
	audio_stream->codecpar->sample_rate = 16000;
	audio_stream->codecpar->channels = av_get_channel_layout_nb_channels(AV_CH_LAYOUT_MONO);
	audio_stream->codecpar->channel_layout = AV_CH_LAYOUT_MONO;
	audio_stream->codecpar->format = AV_SAMPLE_FMT_S16;
	audio_stream->codecpar->frame_size = 1024;
	audio_stream->codecpar->profile = FF_PROFILE_AAC_LOW;
	//audio_stream->codec->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
	//audio_stream->codecpar->block_align = 1;
	//audio_stream->index = 1;
	audio_stream->time_base = (AVRational){1, 16000};
	audio_stream->codec->time_base.den = 16000;
	audio_stream->codec->time_base.num = 1;
	audio_stream->codec->channels = 1;
	

#else
	audio_stream->codecpar->codec_id = AV_CODEC_ID_PCM_S16LE;
	audio_stream->codecpar->codec_type = AVMEDIA_TYPE_AUDIO;
	//audio_stream->codecpar->bit_rate = 64000;
	audio_stream->codecpar->sample_rate = 16000;
	audio_stream->codecpar->channels = 1;
	audio_stream->codecpar->channel_layout = AV_CH_LAYOUT_MONO;
	audio_stream->codecpar->format = AV_SAMPLE_FMT_S16;
	audio_stream->codecpar->frame_size = 1000;
	//audio_stream->codecpar->profile = FF_PROFILE_AAC_LOW;
	//audio_stream->codec->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
	//audio_stream->codecpar->block_align = 1;
	audio_stream->index = 1;
	audio_stream->time_base = (AVRational){1, 16000};
	audio_stream->codec->time_base.den = 16000;
	audio_stream->codec->time_base.num = 1;
	*/

#endif
#endif
	

#if 0
	//初始化重采样上下文
	acc_ctx = swr_alloc();

	//设置重采样参数
	swr_alloc_set_opts(acc_ctx,
		AV_CH_LAYOUT_MONO,AV_SAMPLE_FMT_FLTP,audio_stream->codecpar->sample_rate,
		AV_CH_LAYOUT_MONO,AV_SAMPLE_FMT_S16,16000,
		0,0);

	//重采样初始化
	ret = swr_init(acc_ctx);
	if (0 != ret) {
		// 错误处理
		printf("swr_init fail !\n");
		goto fail;
	}

	
#endif






#if 1

	//复制coderpar 给coder
	ret = avcodec_parameters_to_context(video_stream->codec, video_stream->codecpar);
    if (ret < 0)
	{
		printf("avcodec_parameters_to_context  error  %d: %s\n",ret, av_err2str(ret));
		goto fail;
	}

	//复制coderpar 给coder
	ret = avcodec_parameters_to_context(audio_stream->codec, audio_stream->codecpar);
    if (ret < 0)
	{
		printf("avcodec_parameters_to_context  error  %d: %s\n",ret, av_err2str(ret));
		goto fail;
	}

#endif




#if 1

	//打开音频编码器
	if (avcodec_open2(audio_stream->codec, acc_codec, NULL) < 0) {
        fprintf(stderr, "Could not open codec\n");
        goto fail;
    }

	//申请音频包空间
	pkt = av_packet_alloc();
    if (!pkt) {
        fprintf(stderr, "could not allocate the packet\n");
        goto fail;
    }

    /* frame containing input raw audio */
	//申请音频帧空间
    frame = av_frame_alloc();
    if (!frame) {
        fprintf(stderr, "Could not allocate audio frame\n");
       	goto fail;
    }

	frame->nb_samples     = 1024;
    frame->format         = AV_SAMPLE_FMT_S16;
    frame->channel_layout = AV_CH_LAYOUT_MONO;
	frame->channels = av_get_channel_layout_nb_channels(AV_CH_LAYOUT_MONO);
		

	printf("frame %d  %d  \n",frame->nb_samples,frame->format);

	//拿到音频帧的buff
	ret = av_frame_get_buffer(frame, 0);
	if (ret < 0) {
		fprintf(stderr, "Could not allocate audio data buffers\n");
		goto fail;
	}
	
#endif

	
	printf("==========Output Information==========\n");

	//打印封装格式信息
	av_dump_format(m_format_ctx,0, szFileName, 1);


	//写mp4文件头
	ret = avformat_write_header(m_format_ctx,NULL);
	if(ret)
	{
		printf("video_mp4 avformat_write_header fail!\n");	
		goto fail;
	}


	pthread_mutex_init(&MP4_audio_mutex, NULL);
	//pthread_mutex_init(&MP4_video_mutex, NULL);
    pthread_cond_init(&MP4_audio_cond, NULL);
	//pthread_cond_init(&MP4_video_cond, NULL);



	
	video_pth_g_exit = false;
	audio_pth_g_exit = false;
	pthread_create(&video_mp4_tid, NULL, video_mp4_pth, (void *)m_format_ctx);
	pthread_create(&audio_mp4_tid, NULL, audio_mp4_pth, (void *)m_format_ctx);

	return 0;
	
fail:
	avcodec_close(video_stream->codec);
	if(acc_ctx != NULL)
		swr_free(&acc_ctx);
	if(video_stream && video_stream->codec->extradata)
		av_free(video_stream->codec->extradata);
	av_freep(&m_format_ctx);
	m_format_ctx = NULL;
	if(MP4_fd != NULL)
		fclose(MP4_fd);


	return -1;
}

int stop_video_mp4(void)
{
	audio_pth_g_exit = true;
	if(audio_mp4_tid != NULL)
		pthread_join(audio_mp4_tid,NULL);
	video_pth_g_exit = true;
	pthread_cond_signal(&MP4_audio_cond);
	if(video_mp4_tid != NULL)
		pthread_join(video_mp4_tid,NULL);

	video_mp4_tid = NULL;
	audio_mp4_tid = NULL;
	
}


void stop_video_mp4_fun(void)
{
	if (g_i_RecordVideo == 1)
	{
		//ChangeSclDispBindForNor();
		stop_video_mp4();
		funSendMsgToUi("cmd_rec_video_flag",CMD_REC_VIDEO_FLAG,0,"");
		g_i_RecordVideo = 0;
	}
}

int dealcmdinit(void)
{
	int cmd = 0;	
	MI_S32 ret = -1;
	
	scanf("%d", &cmd);
    ST_Flush();
	printf("########you select is %d\n",cmd);
	switch(cmd)
	{
		case 1:
			g_exit = true;
			pthread_join(stream_tid, NULL);
		
			//start_vdec();

			break;
		case 2:
			g_PushEsExit = true;
			pthread_join(g_stVdecThreadArgs.pt, NULL);

			stop_vdec();
			
			g_exit = false;
			pthread_create(&stream_tid, NULL, uvc_stream, NULL);
			break;
		case 3:
			g_stVdecThreadArgs.bRunFlag = false;
			break;
		case 4:
			g_stVdecThreadArgs.bRunFlag = true;
			break;
	}

	return 0;
}

bool video_back_usb()
{
	return usb_open_flag;
}

void* aiGetChnPortBuf(void* data)
{
    AiChnPriv_t* priv = (AiChnPriv_t*)data;
    MI_AUDIO_Frame_t stAiChFrame;
    MI_AUDIO_AecFrame_t stAecFrame;
    MI_S32 s32Ret;
    MI_U32 u32ChnIndex;
    struct timeval tv_before, tv_after;
    MI_S64 before_us, after_us;

    memset(&stAiChFrame, 0, sizeof(MI_AUDIO_Frame_t));
    memset(&stAecFrame, 0, sizeof(MI_AUDIO_AecFrame_t));

 
    while(FALSE == bAiExit)
    {
        s32Ret = MI_AI_GetFrame(priv->AiDevId, priv->AiChn, &stAiChFrame, &stAecFrame, -1);
        if (MI_SUCCESS == s32Ret)
        {
            {
                gettimeofday(&tv_before, NULL);
                write(priv->s32Fd, stAiChFrame.apVirAddr[0], stAiChFrame.u32Len[0]);
                gettimeofday(&tv_after, NULL);
                before_us = tv_before.tv_sec * 1000000 + tv_before.tv_usec;
                after_us = tv_after.tv_sec * 1000000 + tv_after.tv_usec;
                if (after_us - before_us > 10 * 1000)
                {
                    printf("Chn:%d, cost time:%lldus = %lldms.\n", priv->AiChn, after_us - before_us, (after_us - before_us) / 1000);
                }
                priv->u32TotalSize += stAiChFrame.u32Len[0];
            }
            MI_AI_ReleaseFrame(priv->AiDevId, priv->AiChn,  &stAiChFrame,  NULL);
        }
        else
        {
            printf("Dev%dChn%d get frame failed!!!error:0x%x\n", priv->AiDevId, priv->AiChn, s32Ret);
        }
    }
    close(priv->s32Fd);
    MI_AI_DisableChn(0, 0);
    MI_AI_Disable(0);

    return NULL;
}

static void * system_cmd_pthread(void *args)
{
	const char *name = (const char *)args;

	printf("system_cmd_pthread : %s\n",name);
	
	system(name);
	//system("rm /mnt/VIDEO/input.pcm");
	//system("rm /mnt/VIDEO/input.h264");

	return NULL;
}


bool system_cmd(const char * cmd)
{
	pthread_t cmd_tid;

	const char * cmd_ret = cmd;

	printf("system_cmd : %s\n",cmd_ret);

	int ret = pthread_create(&cmd_tid, NULL, system_cmd_pthread, (void *)cmd_ret);
	if(ret == 0)
	{
		printf("pthread_create  successful\n");
	}
	else
	{
		printf("pthread_create  false\n");
	}

	return 0;
	
}









MI_S32 deinitAi(void)
{
	bAiExit = true;
}

#if 0

bool set_fp_open()
{
	MI_ISP_IQ_YUVGAMMA_TYPE_t st_ISP_IQ_YUVGAMMA_TYPE_t;
	memset(&st_ISP_IQ_YUVGAMMA_TYPE_t, 0x0, sizeof(st_ISP_IQ_YUVGAMMA_TYPE_t));

	MI_U16 fp_Y[256] = {
0,
1018,
1014,
1010,
1006,
1002,
998,
994,
990,
986,
982,
978,
974,
970,
966,
962,
959,
955,
951,
947,
943,
939,
935,
931,
927,
923,
919,
915,
911,
907,
903,
899,
896,
892,
888,
884,
880,
876,
872,
868,
864,
860,
856,
852,
848,
844,
841,
837,
833,
829,
825,
821,
817,
813,
809,
805,
801,
797,
793,
789,
785,
781,
777,
773,
769,
765,
761,
757,
753,
749,
745,
741,
737,
733,
729,
725,
721,
717,
713,
709,
705,
701,
697,
693,
689,
685,
681,
677,
673,
669,
665,
661,
657,
653,
649,
645,
642,
638,
634,
630,
626,
622,
618,
614,
610,
606,
602,
598,
594,
590,
586,
582,
578,
574,
570,
566,
562,
558,
554,
550,
546,
542,
538,
534,
530,
526,
522,
518,
514,
509,
505,
501,
497,
493,
489,
485,
481,
477,
473,
469,
465,
461,
457,
453,
449,
445,
441,
437,
433,
429,
425,
421,
417,
413,
409,
405,
401,
397,
393,
389,
385,
381,
377,
373,
369,
365,
361,
357,
353,
349,
345,
341,
337,
333,
329,
325,
321,
317,
312,
308,
304,
300,
296,
292,
288,
284,
280,
276,
272,
268,
264,
260,
256,
252,
248,
244,
240,
236,
232,
228,
224,
220,
216,
212,
207,
203,
199,
195,
191,
187,
183,
179,
175,
171,
167,
163,
159,
155,
151,
147,
143,
139,
135,
131,
126,
122,
118,
114,
110,
106,
102,
98,
94,
90,
86,
82,
78,
74,
70,
66,
62,
57,
53,
49,
45,
41,
37,
33,
29,
25,
21,
17,
13,
9,
5,
1,
	
};                //0 ~ 1023
	
    MI_U16 fp_U[128] = {
0,
4,
8,
12,
16,
20,
24,
28,
32,
36,
40,
44,
48,
52,
56,
60,
64,
68,
72,
76,
80,
84,
88,
92,
96,
100,
104,
108,
112,
116,
120,
124,
128,
132,
136,
140,
144,
148,
152,
156,
160,
164,
168,
172,
176,
180,
184,
188,
192,
196,
200,
204,
208,
212,
216,
220,
224,
228,
232,
236,
240,
244,
248,
252,
256,
260,
264,
268,
272,
276,
280,
284,
288,
292,
296,
300,
304,
308,
312,
316,
320,
324,
328,
332,
336,
340,
344,
348,
352,
356,
360,
364,
368,
372,
376,
380,
384,
388,
392,
396,
400,
404,
408,
412,
416,
420,
424,
428,
432,
436,
440,
444,
448,
452,
456,
460,
464,
468,
472,
476,
480,
484,
488,
492,
496,
500,
504,
511,

};                //0 ~  511
    MI_U16 fp_V[128] = {
0,
4,
8,
12,
16,
20,
24,
28,
32,
36,
40,
44,
48,
52,
56,
60,
64,
68,
72,
76,
80,
84,
88,
92,
96,
100,
104,
108,
112,
116,
120,
124,
128,
132,
136,
140,
144,
148,
152,
156,
160,
164,
168,
172,
176,
180,
184,
188,
192,
196,
200,
204,
208,
212,
216,
220,
224,
228,
232,
236,
240,
244,
248,
252,
256,
260,
264,
268,
272,
276,
280,
284,
288,
292,
296,
300,
304,
308,
312,
316,
320,
324,
328,
332,
336,
340,
344,
348,
352,
356,
360,
364,
368,
372,
376,
380,
384,
388,
392,
396,
400,
404,
408,
412,
416,
420,
424,
428,
432,
436,
440,
444,
448,
452,
456,
460,
464,
468,
472,
476,
480,
484,
488,
492,
496,
500,
504,
511,

};				 //0 ~  511
	
	ExecFunc(MI_ISP_IQ_GetYUVGamma(0, 0, &st_ISP_IQ_YUVGAMMA_TYPE_t), MI_SUCCESS);

	st_ISP_IQ_YUVGAMMA_TYPE_t.bEnable = SS_TRUE;
	st_ISP_IQ_YUVGAMMA_TYPE_t.enOpType = SS_OP_TYP_MANUAL;

	for(int i = 0; i < 256 ;i++)
	{
		st_ISP_IQ_YUVGAMMA_TYPE_t.stManual.stParaAPI.u16LutY[i] = fp_Y[i];
	}
	for(int i = 0; i < 128 ;i++)
	{
		st_ISP_IQ_YUVGAMMA_TYPE_t.stManual.stParaAPI.u16LutU[i] = fp_U[i];
	}
	for(int i = 0; i < 128 ;i++)
	{
		st_ISP_IQ_YUVGAMMA_TYPE_t.stManual.stParaAPI.u16LutV[i] = fp_V[i];
	}

	
	ExecFunc(MI_ISP_IQ_SetYUVGamma(0, 0, &st_ISP_IQ_YUVGAMMA_TYPE_t), MI_SUCCESS);


	
	return 0;
}

bool set_fp_close()
{
	MI_ISP_IQ_YUVGAMMA_TYPE_t st_ISP_IQ_YUVGAMMA_TYPE_t;
	memset(&st_ISP_IQ_YUVGAMMA_TYPE_t, 0x0, sizeof(st_ISP_IQ_YUVGAMMA_TYPE_t));


	ExecFunc(MI_ISP_IQ_GetYUVGamma(0, 0, &st_ISP_IQ_YUVGAMMA_TYPE_t), MI_SUCCESS);
	st_ISP_IQ_YUVGAMMA_TYPE_t.bEnable = SS_FALSE;
	ExecFunc(MI_ISP_IQ_SetYUVGamma(0, 0, &st_ISP_IQ_YUVGAMMA_TYPE_t), MI_SUCCESS);
		
	
	return 0;
}



#endif

/*****************************************
函数名：set_fp_open
函数功能：开启负片
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
bool set_fp_open()
{
	ST_Sys_BindInfo_T stSysBindInfo;
	//判断负片状态
	if(fp_g_exit == true)
	{

	    memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	    stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
	    stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	    stSysBindInfo.stSrcChnPort.u32PortId = 1;
	    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
	    stSysBindInfo.stDstChnPort.u32DevId = 3;
	    stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
	    stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
	    stSysBindInfo.u32SrcFrmrate = 30;
	    stSysBindInfo.u32DstFrmrate = 30;
	    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	     ExecFunc(ST_Sys_UnBind(&stSysBindInfo), MI_SUCCESS);

		fp_g_exit = false;
		pthread_create(&fp_tid, NULL, kjd_manual_scl, NULL);
	}

}

/*****************************************
函数名：set_fp_close
函数功能：关闭负片
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
bool set_fp_close()
{
	ST_Sys_BindInfo_T stSysBindInfo;

	if(fp_g_exit == false)
	{
		fp_g_exit = true;
		pthread_join(fp_tid, NULL);
		

		memset(&stSysBindInfo, 0x0, sizeof(stSysBindInfo));
		stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
	    stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
	    stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
	    stSysBindInfo.stSrcChnPort.u32PortId = 1;
	    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_SCL;
	    stSysBindInfo.stDstChnPort.u32DevId = 3;
	    stSysBindInfo.stDstChnPort.u32ChnId = SCL_CHN_ID;
	    stSysBindInfo.stDstChnPort.u32PortId = SCL_PORT_ID;
	    stSysBindInfo.u32SrcFrmrate = 30;
	    stSysBindInfo.u32DstFrmrate = 30;
	    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
	    ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
	}
}

/*****************************************
函数名：proportion_switch
函数功能：显示比例切换
函数参数：
		  参数1：显示比例状态的flag
		  参数2：负片状态的flag
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
char proportion_switch(char proportion_flag,char is_fp)
{
	MI_RGN_ChnPort_t stChnPort;

	memset(&stChnPort, 0, sizeof(stChnPort));
	stChnPort.eModId = E_MI_MODULE_ID_SCL;
    stChnPort.s32DevId = 1;
    stChnPort.s32ChnId = SCL_CHN_ID;
    stChnPort.s32PortId = 3;
    

	//退出osd水印线程
	g_stRgnOsd.bRun = FALSE;
	pthread_join(g_stRgnOsd.pt, NULL);
	ExecFunc(MI_RGN_DetachFromChn(0, RGN_OSD_HANDLE, &stChnPort), MI_RGN_OK);
	
	//判断负片是否存在 0 是存在
	if(is_fp == 0)
	{
		fp_g_exit = true;
		pthread_join(fp_tid, NULL);
	}
	
	
	//退出摄像头线程
	g_exit = true;
	pthread_join(stream_tid, NULL);

	//选择合适摄像头比例输出
	change_proportion_flag = proportion_flag;

	//开启摄像头线程
	g_exit = false;
	pthread_create(&stream_tid, NULL, uvc_stream, NULL);


	//判断负片是否存在 0 是存在
	if(is_fp == 0)
	{
		fp_g_exit = false;
		pthread_create(&fp_tid, NULL, kjd_manual_scl, NULL);
	}

	


	
}

/*****************************************
函数名：usb_host_out
函数功能：usb摄像头拔出事件
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
char usb_host_out(void)
{
	//退出摄像头线程
	g_exit = true;
	pthread_join(stream_tid, NULL);
	usb_open_flag = false;
	

	return 0;
}





/*****************************************
函数名：usb_host_insert
函数功能：usb摄像头插入事件
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
void usb_host_insert(void)
{
/*	bool fp;
	
	printf("usb host insert start\n");

	MI_RGN_ChnPort_t stChnPort;

	memset(&stChnPort, 0, sizeof(stChnPort));
	stChnPort.eModId = E_MI_MODULE_ID_SCL;
    stChnPort.s32DevId = 1;
    stChnPort.s32ChnId = SCL_CHN_ID;
    stChnPort.s32PortId = 3;
    

	//退出osd水印线程
	g_stRgnOsd.bRun = FALSE;
	pthread_join(g_stRgnOsd.pt, NULL);
	MI_RGN_DetachFromChn(0, RGN_OSD_HANDLE, &stChnPort);
	


	
	fp = fp_g_exit;
	if(fp == false)
	{
		fp_g_exit = true;
		pthread_join(fp_tid, NULL);
	}
	
	*/
	
	
	g_exit = false;
	pthread_create(&stream_tid, NULL, uvc_stream, NULL);
	/*if(fp == false)
	{
		fp_g_exit = false;
		pthread_create(&fp_tid, NULL, kjd_manual_scl, NULL);
	}
*/
    printf("usb host insert suc suc\n");	
}

/*****************************************
函数名：check_disk
函数功能：检测sd卡硬盘信息
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
int check_disk()
{
	struct statfs diskInfo;

	int kjd_ret;

	kjd_ret = statfs("/mnt", &diskInfo);
	if (0 != kjd_ret)
    {
    	printf("statfs fail!\n");
		return -1;
    }

   	unsigned long long blocksize = diskInfo.f_bsize; //每个block里包含的字节数

	unsigned long long totalsize = blocksize * diskInfo.f_blocks; //总的字节数，f_blocks为block的数目

	printf("Total_size = %llu B = %llu KB = %llu MB = %llu GB\n",

	totalsize, totalsize>>10, totalsize>>20, totalsize>>30);

	unsigned long long freeDisk = diskInfo.f_bfree * blocksize; //剩余空间的大小

	unsigned long long availableDisk = diskInfo.f_bavail * blocksize; //可用空间大小

	printf("Disk_free = %llu MB = %llu GB\nDisk_available = %llu MB = %llu GB\n",

	freeDisk>>20, freeDisk>>30, availableDisk>>20, availableDisk>>30);

	if(freeDisk>>20 < 200)
		return -1;
	return 0;
}

/*****************************************
函数名：rev_sd_flag
函数功能：返回第一次sd卡插拔状态
函数参数：无
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
bool rev_sd_flag(void)
{
	return sd_flag;
}
Device_Handle_t video_dev_1;

Device_Handle_t *video_dev;


/*****************************************
函数名：KJD_UVC_HOST_init
函数功能：摄像头线程启动和准备工作
函数参数：1.video结构体地址。
函数返回值：0成功 非0失败
作者：陈钰
*****************************************/
int KJD_UVC_HOST_init(Device_Handle_t *video_dev)
//int main()
{
	printf("=======18:57=====7262==============\n");
    //signal(SIGINT, Sig_Handler); 
	
	//signal(SIGUSR1, usb_remove); 

	time_t now = 0;
    struct tm *tm = NULL;

	now = time(NULL);
    tm = localtime(&now);

	if(tm->tm_year + 1900 == 1970)
	{
		system("date 010100002023");
	}
	
	

	pvideo_dev = video_dev;
	uvc_debug_level = UVC_DBG_ERR;	


	

	FILE *File;
	char readBuf[1024] = {0};
	char bootAnim[3] = {0};
	char kill_cmd[128] = {0};

	//删除开机动画进程
	File = popen("ps -el | grep -i /etc/bootAnim/bootAnim","r");
	fread(readBuf,1024,1,File);
	pclose(File);

	bootAnim[0] = readBuf[2];
	bootAnim[1] = readBuf[3];
	bootAnim[2] = readBuf[4];
	sprintf(kill_cmd,"kill %s",bootAnim);
	system(kill_cmd);

/*
	//识别sd卡状态
	memset(&readBuf,0,sizeof(readBuf));
	File = popen("ls -l /dev | grep -i mmcblk0p1","r");
	fread(readBuf,1024,1,File);
	pclose(File);


    if(readBuf[0] != 'b')
    {
    	sd_flag = false;
    }
	else
	{
		sd_flag = true;
		system("rm /mnt/UBOOT");
		system("rm /mnt/IPL");
		system("rm /mnt/IPL_CUST");
		system("rm /mnt/SigmastarUpgradeSD.bin");
		system("rm /mnt/upgrade_script.txt");
		system("sync");
	}
    */
	
    MI_S32 s32Ret;
    ST_Sys_BindInfo_T stSysBindInfo;
    MI_VENC_DEV VeDev = MI_VENC_DEV_ID_JPEG_0;
    MI_VENC_CHN VeChn=0;
    MI_VENC_ChnAttr_t stAttr;
    MI_VENC_RecvPicParam_t stRecvParam;
    MI_VENC_ChnStat_t stStat;
    MI_VENC_Stream_t stStream;

    /*set jpeg channel video encode attribute*/
    memset(&stAttr, 0x0, sizeof(MI_VENC_ChnAttr_t));
    stAttr.stVeAttr.eType = E_MI_VENC_MODTYPE_JPEGE;
    stAttr.stVeAttr.stAttrJpeg.u32PicWidth = 1024;
    stAttr.stVeAttr.stAttrJpeg.u32PicHeight = 600;
    stAttr.stVeAttr.stAttrJpeg.u32MaxPicWidth = 1920;
    stAttr.stVeAttr.stAttrJpeg.u32MaxPicHeight = 1080;

    stAttr.stVeAttr.stAttrJpeg.u32BufSize = 1024*600*4;
    stAttr.stVeAttr.stAttrJpeg.bByFrame = 1;
    stAttr.stVeAttr.stAttrJpeg.bSupportDCF = 0;
    stAttr.stVeAttr.stAttrJpeg.u32RestartMakerPerRowCnt = 0;

    stAttr.stRcAttr.eRcMode = E_MI_VENC_RC_MODE_MJPEGCBR;
    
    stAttr.stRcAttr.stAttrH264Cbr.u32BitRate = 2*1024*1024;
    stAttr.stRcAttr.stAttrH264Cbr.u32SrcFrmRateNum = 30;
    stAttr.stRcAttr.stAttrH264Cbr.u32SrcFrmRateDen  = 1;
    stAttr.stRcAttr.stAttrH264Cbr.u32Gop = 30;
    stAttr.stRcAttr.stAttrH264Cbr.u32FluctuateLevel = 1;
    stAttr.stRcAttr.stAttrH264Cbr.u32StatTime = 1;
	

    //create jpeg channel
    s32Ret = MI_VENC_CreateChn(VeDev, VeChn, &stAttr);
    if (MI_SUCCESS != s32Ret)
    {
        printf("StartJpegRecord MI_VENC_CreateChn err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }
    
    s32Ret = MI_VENC_CreateChn(VeDev, 1, &stAttr);
    if (MI_SUCCESS != s32Ret)
    {
        printf("StartJpegRecord MI_VENC_CreateChn err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }
    MI_VENC_SetMaxStreamCnt(VeDev, 1, 2);
    
/*    memset(&stSysBindInfo, 0x0, sizeof(ST_Sys_BindInfo_T));
    stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
    stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
    stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;//2;
    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
    stSysBindInfo.stDstChnPort.u32DevId = MI_VENC_DEV_ID_JPEG_0;
    stSysBindInfo.stDstChnPort.u32ChnId = 0;
    stSysBindInfo.stDstChnPort.u32PortId = 0;
    stSysBindInfo.u32SrcFrmrate = 30;
    stSysBindInfo.u32DstFrmrate = 1;
    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
    ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
    
    stSysBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_SCL;
    stSysBindInfo.stSrcChnPort.u32DevId = SCL_DEV_ID;
    stSysBindInfo.stSrcChnPort.u32ChnId = SCL_CHN_ID;
    stSysBindInfo.stSrcChnPort.u32PortId = SCL_PORT_ID;//3;
    stSysBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_VENC;
    stSysBindInfo.stDstChnPort.u32DevId = MI_VENC_DEV_ID_JPEG_0;
    stSysBindInfo.stDstChnPort.u32ChnId = 1;
    stSysBindInfo.stDstChnPort.u32PortId = 0;
    stSysBindInfo.u32SrcFrmrate = 30;
    stSysBindInfo.u32DstFrmrate = 1;
    stSysBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
    ExecFunc(ST_Sys_Bind(&stSysBindInfo), MI_SUCCESS);
*/


	//关机线程
	//pthread_create(&close_mem, NULL, close_thread, NULL);




	//开启uvc_host线程
	pthread_create(&stream_tid, NULL, uvc_stream, NULL);
	//开启综合线程
    pthread_create(&proc_comp, NULL, Proc_Composite, NULL);



	//pthread_join(close_mem, NULL);
	//pthread_join(stream_tid, NULL);


    return 0;
}

/*
[todo list]
1. refine control thread.
2. dynamaic change format.
3. support mult stream.
4. support uac (hdmi audio output?)
*/









////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//sensor初始化
MI_S32 ST_SensorModuleInit()
{
    MI_SNR_PADID eSnrPadId = 0;//chg 9734  //gstSensorAttr[Index].eSensorPadID;
 //   MI_SNR_PADID eSnrPadId = 3;//chg 6946
    MI_SNR_PADInfo_t  stPad0Info;
    MI_SNR_PlaneInfo_t stSnrPlane0Info;
    MI_U32 u32ResCount =0;
    MI_U8 u8ResIndex =0;
    MI_U8 u8ChocieRes = 0;//gstSensorAttr[Index].u8ResIndex;
    MI_S32 s32Input =0;
    MI_SNR_Res_t stRes;
    
	printf("Sensor 0\r\n");
	
    memset(&stRes, 0x0, sizeof(MI_SNR_Res_t));
    memset(&stPad0Info, 0x0, sizeof(MI_SNR_PADInfo_t));
    memset(&stSnrPlane0Info, 0x0, sizeof(MI_SNR_PlaneInfo_t));

	printf("Sensor 1\r\n");
    STCHECKRESULT(MI_SNR_SetPlaneMode(eSnrPadId, FALSE));

    STCHECKRESULT(MI_SNR_QueryResCount(eSnrPadId, &u32ResCount));
	
	printf("Sensor 2\r\n");
	
    for(u8ResIndex=0; u8ResIndex < u32ResCount; u8ResIndex++)
    {
        STCHECKRESULT(MI_SNR_GetRes(eSnrPadId, u8ResIndex, &stRes));
        printf("index %d, Crop(%d,%d,%d,%d), outputsize(%d,%d), maxfps %d, minfps %d, ResDesc %s\n",
        u8ResIndex,
        stRes.stCropRect.u16X, stRes.stCropRect.u16Y, stRes.stCropRect.u16Width,stRes.stCropRect.u16Height,
        stRes.stOutputSize.u16Width, stRes.stOutputSize.u16Height,
        stRes.u32MaxFps,stRes.u32MinFps,
        stRes.strResDesc);
    }
	
	printf("Sensor 3\r\n");

    if((u8ChocieRes == 0xff) || (u8ChocieRes >= u32ResCount && u8ChocieRes != 0xff))
    {
        printf("choice which resolution use, cnt %d\n", u32ResCount);
        do
        {
            scanf("%d", &s32Input);
            u8ChocieRes = (MI_U8)s32Input;
            ST_Flush();
            STCHECKRESULT(MI_SNR_QueryResCount(eSnrPadId, &u32ResCount));
            if(u8ChocieRes >= u32ResCount)
            {
                printf("choice err res %d > =cnt %d\n", u8ChocieRes, u32ResCount);
            }
        }while(u8ChocieRes >= u32ResCount);
        printf("You select %d res\n", u8ChocieRes);
    }
    printf("Rest %d\n", u8ChocieRes);

	printf("Sensor 4\r\n");

    STCHECKRESULT(MI_SNR_SetRes(eSnrPadId, u8ChocieRes));
    STCHECKRESULT(MI_SNR_Enable(eSnrPadId));

	printf("Sensor 5\r\n");

    return MI_SUCCESS;
}

//sensor模块去初始化
MI_S32 ST_SensorModuleUnInit(MI_SNR_PADID eSnrPad)
{
    MI_SNR_PADID eSnrPadId = eSnrPad;

    STCHECKRESULT(MI_SNR_Disable(eSnrPadId));

    return MI_SUCCESS;
}

//vif模块初始化

MI_S32 ST_VifModuleInit()
{
	MI_VIF_GROUP groupId = 0;   //chg 9734
	MI_VIF_DEV vifDev =0;      //chg 9734 
//	MI_VIF_GROUP groupId = 3;   //chg 6946
//	MI_VIF_DEV vifDev =12;      //chg 6949

    MI_VIF_PORT vifPort = 0;
    MI_SNR_PADID SnrPadId = 0;
    MI_U32 u32PlaneId = 0;
    MI_U16 vifDevIdPerGroup=0;

    MI_SNR_PADInfo_t  stPad0Info;
    MI_SNR_PlaneInfo_t stSnrPlane0Info;
    memset(&stPad0Info, 0x0, sizeof(MI_SNR_PADInfo_t));
    memset(&stSnrPlane0Info, 0x0, sizeof(MI_SNR_PlaneInfo_t));

    MI_VIF_GroupAttr_t stGroupAttr;
    memset(&stGroupAttr, 0x0, sizeof(MI_VIF_GroupAttr_t));

    STCHECKRESULT(MI_SNR_GetPadInfo(SnrPadId, &stPad0Info));
    STCHECKRESULT(MI_SNR_GetPlaneInfo(SnrPadId, u32PlaneId, &stSnrPlane0Info));

    stGroupAttr.eIntfMode = E_MI_VIF_MODE_MIPI;
    stGroupAttr.eWorkMode = E_MI_VIF_WORK_MODE_1MULTIPLEX;
    stGroupAttr.eHDRType = E_MI_VIF_HDR_TYPE_OFF;
    if(stGroupAttr.eIntfMode == E_MI_VIF_MODE_BT656)
        stGroupAttr.eClkEdge = (MI_VIF_ClkEdge_e)stPad0Info.unIntfAttr.stBt656Attr.eClkEdge;
    else
        stGroupAttr.eClkEdge = E_MI_VIF_CLK_EDGE_DOUBLE;

    STCHECKRESULT(MI_VIF_CreateDevGroup(groupId, &stGroupAttr));


        MI_VIF_DevAttr_t stVifDevAttr;
        memset(&stVifDevAttr, 0x0, sizeof(MI_VIF_DevAttr_t));

        vifDev = 0; //chg 9734
	   // vifDev = 12;//chg 6946
		
        stVifDevAttr.stInputRect.u16X = stSnrPlane0Info.stCapRect.u16X;
        stVifDevAttr.stInputRect.u16Y = stSnrPlane0Info.stCapRect.u16Y;
        stVifDevAttr.stInputRect.u16Width = stSnrPlane0Info.stCapRect.u16Width;
        stVifDevAttr.stInputRect.u16Height = stSnrPlane0Info.stCapRect.u16Height;
        if(stSnrPlane0Info.eBayerId >= E_MI_SYS_PIXEL_BAYERID_MAX)
        {
            stVifDevAttr.eInputPixel = stSnrPlane0Info.ePixel;
        }
        else
            stVifDevAttr.eInputPixel = (MI_SYS_PixelFormat_e)RGB_BAYER_PIXEL(stSnrPlane0Info.ePixPrecision, stSnrPlane0Info.eBayerId);

        printf("setchnportattr (%d,%d,%d,%d) \n", stVifDevAttr.stInputRect.u16X, stVifDevAttr.stInputRect.u16Y, stVifDevAttr.stInputRect.u16Width, stVifDevAttr.stInputRect.u16Height);
        STCHECKRESULT(MI_VIF_SetDevAttr(vifDev, &stVifDevAttr));
        STCHECKRESULT(MI_VIF_EnableDev(vifDev));


            MI_VIF_OutputPortAttr_t stVifPortInfo;
            memset(&stVifPortInfo, 0, sizeof(MI_VIF_OutputPortAttr_t));

            stVifPortInfo.stCapRect.u16X = stSnrPlane0Info.stCapRect.u16X;
            stVifPortInfo.stCapRect.u16Y = stSnrPlane0Info.stCapRect.u16Y;
            stVifPortInfo.stCapRect.u16Width =  stSnrPlane0Info.stCapRect.u16Width;
            stVifPortInfo.stCapRect.u16Height = stSnrPlane0Info.stCapRect.u16Height;
            stVifPortInfo.stDestSize.u16Width = stSnrPlane0Info.stCapRect.u16Width;
            stVifPortInfo.stDestSize.u16Height = stSnrPlane0Info.stCapRect.u16Height;
            printf("sensor bayerid %d, bit mode %d \n", stSnrPlane0Info.eBayerId, stSnrPlane0Info.ePixPrecision);
            if(stSnrPlane0Info.eBayerId >= E_MI_SYS_PIXEL_BAYERID_MAX)
            {
                stVifPortInfo.ePixFormat = stSnrPlane0Info.ePixel;
            }
            else
                stVifPortInfo.ePixFormat = (MI_SYS_PixelFormat_e)RGB_BAYER_PIXEL(stSnrPlane0Info.ePixPrecision, stSnrPlane0Info.eBayerId);
            stVifPortInfo.eFrameRate = E_MI_VIF_FRAMERATE_FULL;

            STCHECKRESULT(MI_VIF_SetOutputPortAttr(vifDev, vifPort, &stVifPortInfo));
            STCHECKRESULT(MI_VIF_EnableOutputPort(vifDev, vifPort));
        
    
    return MI_SUCCESS;

}


//vif模块初始化
//MI_S32 ST_VifModuleInit()
MI_S32 ST_VifModuleInit_pad1()
{
	printf("enter vif 0\r\n");
	MI_VIF_GROUP groupId = 2;
	MI_VIF_DEV vifDev =8;
    MI_VIF_PORT vifPort = 0;
    MI_SNR_PADID SnrPadId = 1;
    MI_U32 u32PlaneId = 0;
    MI_U16 vifDevIdPerGroup=0;

    MI_SNR_PADInfo_t  stPad0Info;
    MI_SNR_PlaneInfo_t stSnrPlane0Info;
    memset(&stPad0Info, 0x0, sizeof(MI_SNR_PADInfo_t));
    memset(&stSnrPlane0Info, 0x0, sizeof(MI_SNR_PlaneInfo_t));

	printf("enter vif 1\r\n");

    MI_VIF_GroupAttr_t stGroupAttr;
    memset(&stGroupAttr, 0x0, sizeof(MI_VIF_GroupAttr_t));

    STCHECKRESULT(MI_SNR_GetPadInfo(SnrPadId, &stPad0Info));
    STCHECKRESULT(MI_SNR_GetPlaneInfo(SnrPadId, u32PlaneId, &stSnrPlane0Info));

	printf("enter vif 2\r\n");

    stGroupAttr.eIntfMode = E_MI_VIF_MODE_MIPI;
    stGroupAttr.eWorkMode = E_MI_VIF_WORK_MODE_1MULTIPLEX;
    stGroupAttr.eHDRType = E_MI_VIF_HDR_TYPE_OFF;
    if(stGroupAttr.eIntfMode == E_MI_VIF_MODE_BT656)
        stGroupAttr.eClkEdge = (MI_VIF_ClkEdge_e)stPad0Info.unIntfAttr.stBt656Attr.eClkEdge;
    else
        stGroupAttr.eClkEdge = E_MI_VIF_CLK_EDGE_DOUBLE;

	printf("enter vif 3\r\n");

    STCHECKRESULT(MI_VIF_CreateDevGroup(groupId, &stGroupAttr));

  //  for(vifDevIdPerGroup=0; vifDevIdPerGroup< ST_MAX_VIF_DEV_PERGROUP; vifDevIdPerGroup++)
    {
        MI_VIF_DevAttr_t stVifDevAttr;
        memset(&stVifDevAttr, 0x0, sizeof(MI_VIF_DevAttr_t));

       // vifDev = groupId*ST_MAX_VIF_DEV_PERGROUP+vifDevIdPerGroup;
	    vifDev = 0;
        stVifDevAttr.stInputRect.u16X = stSnrPlane0Info.stCapRect.u16X;
        stVifDevAttr.stInputRect.u16Y = stSnrPlane0Info.stCapRect.u16Y;
        stVifDevAttr.stInputRect.u16Width = stSnrPlane0Info.stCapRect.u16Width;
        stVifDevAttr.stInputRect.u16Height = stSnrPlane0Info.stCapRect.u16Height;
        if(stSnrPlane0Info.eBayerId >= E_MI_SYS_PIXEL_BAYERID_MAX)
        {
            stVifDevAttr.eInputPixel = stSnrPlane0Info.ePixel;
        }
        else
            stVifDevAttr.eInputPixel = (MI_SYS_PixelFormat_e)RGB_BAYER_PIXEL(stSnrPlane0Info.ePixPrecision, stSnrPlane0Info.eBayerId);

	printf("enter vif 4\r\n");

        printf("setchnportattr (%d,%d,%d,%d) \n", stVifDevAttr.stInputRect.u16X, stVifDevAttr.stInputRect.u16Y, stVifDevAttr.stInputRect.u16Width, stVifDevAttr.stInputRect.u16Height);
        STCHECKRESULT(MI_VIF_SetDevAttr(vifDev, &stVifDevAttr));
        STCHECKRESULT(MI_VIF_EnableDev(vifDev));

	printf("enter vif 5\r\n");

       // for(vifPort=0; vifPort< ST_MAX_VIF_OUTPORT_NUM; vifPort++)
        {
            MI_VIF_OutputPortAttr_t stVifPortInfo;
            memset(&stVifPortInfo, 0, sizeof(MI_VIF_OutputPortAttr_t));

            stVifPortInfo.stCapRect.u16X = stSnrPlane0Info.stCapRect.u16X;
            stVifPortInfo.stCapRect.u16Y = stSnrPlane0Info.stCapRect.u16Y;
            stVifPortInfo.stCapRect.u16Width =  stSnrPlane0Info.stCapRect.u16Width;
            stVifPortInfo.stCapRect.u16Height = stSnrPlane0Info.stCapRect.u16Height;
            stVifPortInfo.stDestSize.u16Width = stSnrPlane0Info.stCapRect.u16Width;
            stVifPortInfo.stDestSize.u16Height = stSnrPlane0Info.stCapRect.u16Height;
            printf("sensor bayerid %d, bit mode %d \n", stSnrPlane0Info.eBayerId, stSnrPlane0Info.ePixPrecision);
            if(stSnrPlane0Info.eBayerId >= E_MI_SYS_PIXEL_BAYERID_MAX)
            {
                stVifPortInfo.ePixFormat = stSnrPlane0Info.ePixel;
            }
            else
                stVifPortInfo.ePixFormat = (MI_SYS_PixelFormat_e)RGB_BAYER_PIXEL(stSnrPlane0Info.ePixPrecision, stSnrPlane0Info.eBayerId);
            stVifPortInfo.eFrameRate = E_MI_VIF_FRAMERATE_FULL;

	printf("enter vif 6\r\n");

            STCHECKRESULT(MI_VIF_SetOutputPortAttr(vifDev, vifPort, &stVifPortInfo));
            STCHECKRESULT(MI_VIF_EnableOutputPort(vifDev, vifPort));
        }
    }
	
	printf("enter vif 7\r\n");
	
    return MI_SUCCESS;

}


//vif模块去初始化
MI_S32 ST_VifModuleUnInit()
{
    MI_VIF_DEV vifDev =0;
    MI_VIF_PORT vifPort = 0;
    MI_VIF_GROUP GroupId;

    vifDev = 0;
    GroupId = 0;
    STCHECKRESULT(MI_VIF_DisableOutputPort(vifDev, vifPort));

    STCHECKRESULT(MI_VIF_DisableDev(vifDev));

    STCHECKRESULT(MI_VIF_DestroyDevGroup(GroupId));

    return MI_SUCCESS;
}

//载入iq文件
MI_BOOL ST_DoSetIqBin(MI_ISP_DEV IspDev, MI_ISP_CHANNEL Vpechn, char *pConfigPath)
{
    MI_ISP_IQ_PARAM_INIT_INFO_TYPE_t status;
    MI_U8 u8ispreadycnt = 0;
    if (NULL == pConfigPath || strlen(pConfigPath) == 0)
    {
        printf("IQ Bin File path NULL!\n");
        return FALSE;
    }

    do
    {
//        if(u8ispreadycnt > 100)
        if(u8ispreadycnt > 500)
        {
            printf("%s:%d, isp ready time out \n", __FUNCTION__, __LINE__);
            u8ispreadycnt = 0;
            break;
        }

        memset(&status, 0, sizeof(status));
        MI_ISP_IQ_GetParaInitStatus(IspDev, Vpechn, &status);
        if(status.stParaAPI.bFlag != 1)
        {
            usleep(300*1000);
            u8ispreadycnt++;
            continue;
        }

        u8ispreadycnt = 0;

        printf("loading api bin...path:%s\n",pConfigPath);
        STCHECKRESULT(MI_ISP_API_CmdLoadBinFile(IspDev, Vpechn, (char *)pConfigPath, 1234));

        usleep(10*1000);
    }while(!status.stParaAPI.bFlag);

  //  MI_ISP_AE_FLICKER_TYPE_e Flicker= SS_AE_FLICKER_TYPE_50HZ;
  //  MI_ISP_AE_SetFlicker(IspDev,Vpechn, &Flicker);

    return 0;
}

//载入iq文件
/*MI_BOOL ST_DoSetIqBin(MI_ISP_DEV IspDevId, MI_ISP_CHANNEL IspChnId, char *pConfigPath)
{
    CUS3A_ALGO_STATUS_t stCus3aStatus;
    memset(&stCus3aStatus, 0, sizeof(CUS3A_ALGO_STATUS_t));

    MI_U8  u8ispreadycnt = 0;
    if (strlen(pConfigPath) == 0)
    {
        ST_ERR("IQ Bin File path is NULL!\n");
        return FALSE;
    }

    while(1)
    {
        if(u8ispreadycnt > 100)
        {
            ST_ERR("ISP ready time out!\n");
            u8ispreadycnt = 0;
            break;
        }

        CUS3A_GetAlgoStatus((CUS3A_ISP_DEV_e)IspDevId,(CUS3A_ISP_CH_e)IspChnId, &stCus3aStatus);

        if((stCus3aStatus.Ae == E_ALGO_STATUS_RUNNING) && (stCus3aStatus.Awb == E_ALGO_STATUS_RUNNING))
        {
            ST_DBG("Ready to load IQ bin :%s u8ispreadycnt:%d\n",pConfigPath, u8ispreadycnt);
            MI_ISP_API_CmdLoadBinFile(IspDevId,IspChnId, (char *)pConfigPath, 1234);

            usleep(10*1000);

            u8ispreadycnt = 0;
            break;

        }
        else
        {
            usleep(10*1000);
            u8ispreadycnt++;
        }

    }

    MI_ISP_AE_FLICKER_TYPE_e Flicker= SS_AE_FLICKER_TYPE_50HZ;
    MI_ISP_AE_SetFlicker(IspDevId,IspChnId, &Flicker);

    ST_DBG("MI_ISP_AE_SetFlicker:%d !\n", (int)Flicker);
    return 0;
}*/


//isp初始化
/*MI_S32 ST_IspModuleInit()
{
   MI_ISP_DEV ispDevId = 0;
    MI_ISP_CHANNEL ispChnId = 0;
    MI_ISP_PORT ispOutPortId = 1;
    MI_ISP_DevAttr_t stCreateDevAttr;
    MI_ISP_ChannelAttr_t stIspChnAttr;
    MI_ISP_ChnParam_t stIspChnParam;
    MI_ISP_OutPortParam_t stIspOutputParam;
    MI_SYS_ChnPort_t stChnPort;
    ST_Sys_BindInfo_T stBindInfo;
    memset(&stCreateDevAttr, 0x0, sizeof(MI_ISP_DevAttr_t));
    stCreateDevAttr.u32DevStitchMask = E_MI_ISP_DEVICEMASK_ID0;
    STCHECKRESULT(MI_ISP_CreateDevice(ispDevId, &stCreateDevAttr));
 
    ispChnId = 0;//pstSensorAttr->eSensorPadID;
    memset(&stIspChnAttr, 0x0, sizeof(MI_ISP_ChannelAttr_t));
    //ST_TransMISnrPadToMIIspBindSensorId(0, (MI_ISP_BindSnrId_e *)&stIspChnAttr.u32SensorBindId);
    STCHECKRESULT(MI_ISP_CreateChannel(ispDevId, ispChnId, &stIspChnAttr));
    

    memset(&stIspChnParam, 0x0, sizeof(MI_ISP_ChnParam_t));
    stIspChnParam.eHDRType = E_MI_ISP_HDR_TYPE_OFF;
    stIspChnParam.e3DNRLevel = E_MI_ISP_3DNR_LEVEL2;
    stIspChnParam.eRot = E_MI_SYS_ROTATE_NONE;
    stIspChnParam.bMirror = 0;
    stIspChnParam.bFlip = 0;
    STCHECKRESULT(MI_ISP_SetChnParam(ispDevId, ispChnId, &stIspChnParam));
    STCHECKRESULT(MI_ISP_StartChannel(ispDevId, ispChnId));

    memset(&stIspOutputParam, 0x0, sizeof(MI_ISP_OutPortParam_t));
    stIspOutputParam.stCropRect.u16X = 0;
    stIspOutputParam.stCropRect.u16Y = 0;
    stIspOutputParam.stCropRect.u16Width = 0;//pstSensorAttr->u16Width;
    stIspOutputParam.stCropRect.u16Height = 0;//pstSensorAttr->u16Height;
    stIspOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    STCHECKRESULT(MI_ISP_SetOutputPortParam(ispDevId, ispChnId, ispOutPortId, &stIspOutputParam));
    STCHECKRESULT(MI_ISP_EnableOutputPort(ispDevId, ispChnId, ispOutPortId));
    stChnPort.eModId = E_MI_MODULE_ID_ISP;
    stChnPort.u32DevId = ispDevId;
    stChnPort.u32ChnId = ispChnId;
    stChnPort.u32PortId = ispOutPortId;
    STCHECKRESULT(MI_SYS_SetChnOutputPortDepth(0, &stChnPort , 0, 4));
    printf("isp module Dev%d, chn%d, port%d\n", stChnPort.u32DevId, stChnPort.u32ChnId, stChnPort.u32PortId);


    return MI_SUCCESS;
}


//isp去初始化
MI_S32 ST_IspModuleUnInit()
{
    MI_ISP_DEV ispDevId = 0;
    MI_ISP_CHANNEL ispChnId = 0;
    MI_ISP_PORT ispOutPortId = 1;
    ST_Sys_BindInfo_T stBindInfo;

    ispChnId = 0;
    memset(&stBindInfo, 0x0, sizeof(ST_Sys_BindInfo_T));
    stBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VIF;
    stBindInfo.stSrcChnPort.u32DevId = 0;
    stBindInfo.stSrcChnPort.u32ChnId = 0;
    stBindInfo.stSrcChnPort.u32PortId = 0;
    stBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_ISP;
    stBindInfo.stDstChnPort.u32DevId = ispDevId;
    stBindInfo.stDstChnPort.u32ChnId = ispChnId;
    stBindInfo.stDstChnPort.u32PortId = ispOutPortId;
    STCHECKRESULT(ST_Sys_UnBind(&stBindInfo));

    STCHECKRESULT(MI_ISP_DisableOutputPort(ispDevId, ispChnId, ispOutPortId));

    STCHECKRESULT(MI_ISP_StopChannel(ispDevId, ispChnId));

    STCHECKRESULT(MI_ISP_DestroyChannel(ispDevId, ispChnId));
	
    STCHECKRESULT(MI_ISP_DestoryDevice(ispDevId));


    return MI_SUCCESS;
}
*/


MI_S32 ST_TransMISnrPadToMIIspBindSensorId(MI_SNR_PADID eMiSnrPadId, MI_ISP_BindSnrId_e *peMiIspSnrBindId)
{
    switch(eMiSnrPadId)
    {
        case 0:
            *peMiIspSnrBindId = E_MI_ISP_SENSOR0;
            break;
        case 1:
            *peMiIspSnrBindId = E_MI_ISP_SENSOR1;
            break;
        case 2:
            *peMiIspSnrBindId = E_MI_ISP_SENSOR2;
            break;
        case 3:
            *peMiIspSnrBindId = E_MI_ISP_SENSOR3;
            break;
        default:
            *peMiIspSnrBindId = E_MI_ISP_SENSOR0;
            printf("[%s]%d snrPad%d fail \n", __FUNCTION__, __LINE__, eMiSnrPadId);
            break;
    }

    return MI_SUCCESS;
}

MI_S32 ST_IspModuleInit()
{
    MI_ISP_DEV ispDevId = 0;
    MI_ISP_CHANNEL ispChnId = 0;
    MI_ISP_PORT ispOutPortId =1;
    MI_ISP_DevAttr_t stCreateDevAttr;
    MI_ISP_ChannelAttr_t stIspChnAttr;
    MI_ISP_ChnParam_t stIspChnParam;
    MI_ISP_OutPortParam_t stIspOutputParam;
    MI_SYS_ChnPort_t stChnPort;
    ST_Sys_BindInfo_T stBindInfo;


    printf("theone jason ST_IspModuleInit\n");
  //  if(0 == u32IspRef)
    {
        memset(&stCreateDevAttr, 0x0, sizeof(MI_ISP_DevAttr_t));
        stCreateDevAttr.u32DevStitchMask = E_MI_ISP_DEVICEMASK_ID0;
        STCHECKRESULT(MI_ISP_CreateDevice(ispDevId, &stCreateDevAttr));
    }
   // u32IspRef++;

    ispChnId = 0;
    memset(&stIspChnAttr, 0x0, sizeof(MI_ISP_ChannelAttr_t));
    ST_TransMISnrPadToMIIspBindSensorId(0, (MI_ISP_BindSnrId_e *)&stIspChnAttr.u32SensorBindId);
    STCHECKRESULT(MI_ISP_CreateChannel(ispDevId, ispChnId, &stIspChnAttr));
    //STCHECKRESULT(MI_ISP_SetInputPortCrop(IspDevId, IspChnId, &pstIspChnAttr->stIspInPortAttr[0].stInputCropWin));

    memset(&stIspChnParam, 0x0, sizeof(MI_ISP_ChnParam_t));
    stIspChnParam.eHDRType = E_MI_ISP_HDR_TYPE_OFF;
    stIspChnParam.e3DNRLevel = E_MI_ISP_3DNR_LEVEL2;
    stIspChnParam.eRot = E_MI_SYS_ROTATE_NONE;
    stIspChnParam.bMirror = 0;
    stIspChnParam.bFlip = 0;
    STCHECKRESULT(MI_ISP_SetChnParam(ispDevId, ispChnId, &stIspChnParam));
    STCHECKRESULT(MI_ISP_StartChannel(ispDevId, ispChnId));

    memset(&stIspOutputParam, 0x0, sizeof(MI_ISP_OutPortParam_t));
    stIspOutputParam.stCropRect.u16X = 0;
    stIspOutputParam.stCropRect.u16Y = 0;
    stIspOutputParam.stCropRect.u16Width = 0;
    stIspOutputParam.stCropRect.u16Height = 0;
    stIspOutputParam.ePixelFormat = E_MI_SYS_PIXEL_FRAME_YUV_SEMIPLANAR_420;
    STCHECKRESULT(MI_ISP_SetOutputPortParam(ispDevId, ispChnId, ispOutPortId, &stIspOutputParam));
    STCHECKRESULT(MI_ISP_EnableOutputPort(ispDevId, ispChnId, ispOutPortId));
    stChnPort.eModId = E_MI_MODULE_ID_ISP;
    stChnPort.u32DevId = ispDevId;
    stChnPort.u32ChnId = ispChnId;
    stChnPort.u32PortId = ispOutPortId;
    STCHECKRESULT(MI_SYS_SetChnOutputPortDepth(0, &stChnPort , 0, 4));
    printf("isp module Dev%d, chn%d, port%d\n", stChnPort.u32DevId, stChnPort.u32ChnId, stChnPort.u32PortId);

/*    memset(&stBindInfo, 0x0, sizeof(ST_Sys_BindInfo_T));
    stBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VIF;
    stBindInfo.stSrcChnPort.u32DevId = 0;
    stBindInfo.stSrcChnPort.u32ChnId = 0;
    stBindInfo.stSrcChnPort.u32PortId = 0;
    stBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_ISP;
    stBindInfo.stDstChnPort.u32DevId = ispDevId;
    stBindInfo.stDstChnPort.u32ChnId = ispChnId;
    stBindInfo.stDstChnPort.u32PortId = ispOutPortId;
    stBindInfo.u32SrcFrmrate = 30;
    stBindInfo.u32DstFrmrate = 30;
    stBindInfo.eBindType = E_MI_SYS_BIND_TYPE_FRAME_BASE;
    STCHECKRESULT(ST_Sys_Bind(&stBindInfo));*/

    return MI_SUCCESS;
}

MI_S32 ST_IspModuleUnInit()
{
    MI_ISP_DEV ispDevId = 0;
    MI_ISP_CHANNEL ispChnId = 0;
    MI_ISP_PORT ispOutPortId =1;
    ST_Sys_BindInfo_T stBindInfo;

 
    ispChnId = 0;
  /*  memset(&stBindInfo, 0x0, sizeof(ST_Sys_BindInfo_T));
    stBindInfo.stSrcChnPort.eModId = E_MI_MODULE_ID_VIF;
    stBindInfo.stSrcChnPort.u32DevId = 0;
    stBindInfo.stSrcChnPort.u32ChnId = 0;
    stBindInfo.stSrcChnPort.u32PortId = 0;
    stBindInfo.stDstChnPort.eModId = E_MI_MODULE_ID_ISP;
    stBindInfo.stDstChnPort.u32DevId = ispDevId;
    stBindInfo.stDstChnPort.u32ChnId = ispChnId;
    stBindInfo.stDstChnPort.u32PortId = ispOutPortId;
    STCHECKRESULT(ST_Sys_UnBind(&stBindInfo));*/

    STCHECKRESULT(MI_ISP_DisableOutputPort(ispDevId, ispChnId, ispOutPortId));

    STCHECKRESULT(MI_ISP_StopChannel(ispDevId, ispChnId));

    STCHECKRESULT(MI_ISP_DestroyChannel(ispDevId, ispChnId));

  //  u32IspRef--;
   // if(0 == u32IspRef)
    {
        STCHECKRESULT(MI_ISP_DestoryDevice(ispDevId));
    }

    return MI_SUCCESS;
}



MI_S32 StartJpegRecord(void)
{
    MI_S32 s32Ret;
    ST_Sys_BindInfo_T stSysBindInfo;
    MI_VENC_DEV VeDev = MI_VENC_DEV_ID_JPEG_0;
    MI_VENC_CHN VeChn=0;
    MI_VENC_RecvPicParam_t stRecvParam;
    MI_VENC_ChnStat_t stStat;
    MI_VENC_Stream_t stStream;
 
    //start snapping
    stRecvParam.s32RecvPicNum = 1;//2;
    s32Ret = MI_VENC_StartRecvPicEx(VeDev, VeChn, &stRecvParam);
    if (s32Ret != MI_SUCCESS)
    {
        printf("StartJpegRecord MI_VENC_StartRecvPicEx err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }
    printf("theone jason MI_VENC_StartRecvPicEx ok\n");

    //…wait until all pictures have been encoded.
    if(g_Fd != NULL)
    {
        int i;
        int Count=0;
                   
        while(1)
        {
            s32Ret = MI_VENC_Query(VeDev, VeChn, &stStat);
            if (s32Ret != MI_SUCCESS)
            {
                printf("theone jason JPG MI_VENC_Query error\n");
                return E_MI_ERR_FAILED;
            }
            if (0 != stStat.u32CurPacks)
            {
                break;
            }
            Count++;
            usleep(1000);
            if(Count >= 1000)
                break;
        }
        printf("theone jason JPG stStat.u32CurPacks=%d\n",stStat.u32CurPacks);
        stStream.pstPack = (MI_VENC_Pack_t*)malloc(sizeof(MI_VENC_Pack_t)*stStat.u32CurPacks);
        if (NULL == stStream.pstPack)
        {
            printf("theone jason JPG malloc error\n");
            return E_MI_ERR_FAILED;
        }
        stStream.u32PackCount = stStat.u32CurPacks;
        s32Ret = MI_VENC_GetStream(VeDev, VeChn, &stStream, -1);
        printf("theone jason JPEG wrtie.....\n");
        if (MI_SUCCESS != s32Ret)
        {
            printf("theone jason JPEG MI_VENC_GetStream error\n");
            free(stStream.pstPack);
            stStream.pstPack = NULL;
            return E_MI_ERR_FAILED;
        }
        for (i=0; i<stStream.u32PackCount; i++)
        {
            fwrite(stStream.pstPack[i].pu8Addr+stStream.pstPack[i].u32Offset, 1,
                stStream.pstPack[i].u32Len-stStream.pstPack[i].u32Offset, g_Fd);
        }
        s32Ret = MI_VENC_ReleaseStream(VeDev, VeChn, &stStream);
        if (MI_SUCCESS != s32Ret)
        {
            printf("theone jason JPEG MI_VENC_ReleaseStream error\n");
            free(stStream.pstPack);
            stStream.pstPack=NULL;
            return E_MI_ERR_FAILED;
        }
        free(stStream.pstPack);
        stStream.pstPack = NULL;
    }
    
    s32Ret = MI_VENC_StopRecvPic(VeDev, VeChn);
    if (s32Ret != MI_SUCCESS)
    {
        printf("StartJpegRecord MI_VENC_StopRecvPic err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }
    
    s32Ret = MI_VENC_ResetChn(VeDev, VeChn);
    if (s32Ret != MI_SUCCESS)
    {
        printf("StartJpegRecord MI_VENC_ResetChn err0x%x\n", s32Ret);
        return E_MI_ERR_FAILED;
    }
    printf("StartJpegRecord Over\n");
    system("echo 1 >/proc/sys/vm/drop_caches"); 
    return MI_SUCCESS;
}

int GetWaterMark(void)
{
  //  return TheoneConfig.WaterMark;
    return 1;
}


//设置某摄像头为主视频
void SetCamToMainVideo(unsigned char iFlag)
{
	if (iFlag == 1)//Usb摄像头
	{
		ChangeSclDispBindForNor();
		g_i_MainCam = iFlag;
		g_i_UsbCam = iFlag;
		//切换Usb摄像头为主视频
		ChangeUsbCamInMain();		
		//显示主视频
		St_ShowLayerForMain();		
		//若Mipi摄像头存在，则显示小视频				
		if (g_i_MipiCam > 0)
			St_ShowLayerForSmall();
	}
	else if ((iFlag == 2)||(iFlag == 3))//Mipi摄像头
	{
		ChangeSclDispBindForNor();
		g_i_MainCam = iFlag;
		g_i_MipiCam = iFlag;
		//切换Mipi摄像头为主视频
		ChangeMipiCamInMain();		
		//显示主视频
		St_ShowLayerForMain();	
		//若Usb摄像头存在，则显示小视频		
		if (g_i_UsbCam > 0)
			St_ShowLayerForSmall();	
	}	
}

//释放某摄像头
void ReleaseCam(unsigned char iFlag)
{
	if (iFlag == 1)//Usb摄像头
	{
		g_i_UsbCam = 0;
		if (g_i_MainCam == 1)//当前Usb摄像头为主视频
		{
            stop_video_mp4_fun();
			//隐藏主视频
			St_HideLayerForMain();	
            //若Mipi摄像头存在，则设置Mipi摄像头为主视频			
			if (g_i_MipiCam > 0)
			{
				SetCamToMainVideo(g_i_MipiCam);
				//隐藏小视频
				St_HideLayerForSmall();	
			}
			else//若没有任何一个摄像头存在
			{
				g_i_MainCam = 0;
			}
		}
		else//当前Usb摄像头为小视频
		{
			//隐藏小视频
			St_HideLayerForSmall();	
		}
	}	
	else if ((iFlag == 2)||(iFlag == 3))//Mipi摄像头
	{
		g_i_MipiCam = 0;
		if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//当前Mipi摄像头为主视频
		{
            stop_video_mp4_fun();
			//隐藏主视频
			St_HideLayerForMain();	
            //若Usb摄像头存在，则设置Usb摄像头为主视频		
			if (g_i_UsbCam > 0)
			{
				SetCamToMainVideo(g_i_UsbCam);
				//隐藏小视频
				St_HideLayerForSmall();	
			}
			else//若没有任何一个摄像头存在
			{
				g_i_MainCam = 0;
			}
		}
		else//当前Mipi摄像头为小视频
		{
			//隐藏小视频
			St_HideLayerForSmall();	
		}
	}	
}

//旋转角度
int RotateAction(char RotateNum)
{
	int iWidth = 1280;
	int iHeight = 800;
	
    if(0 == RotateNum)//0度
    {
        change_scl_resolution_rotate(iWidth,iHeight,E_MI_SYS_ROTATE_NONE,false,false);	
    }
    else if(1 == RotateNum)//0度水平翻转
    {
        change_scl_resolution_rotate(iWidth,iHeight,E_MI_SYS_ROTATE_NONE,true,false);	
    }
    else if(2 == RotateNum)//0度垂直翻转
    {
        change_scl_resolution_rotate(iWidth,iHeight,E_MI_SYS_ROTATE_NONE,false,true);	
    }
    else if(3 == RotateNum)//0度水平翻转垂直翻转
    {
        change_scl_resolution_rotate(iWidth,iHeight,E_MI_SYS_ROTATE_NONE,true,true);	
    }
    else if(4 == RotateNum)//0度转90度
    {
        change_scl_resolution_rotate(iHeight,iWidth,E_MI_SYS_ROTATE_90,false,false);	
    }
    else if(5 == RotateNum)//0度转180度
    {
        change_scl_resolution_rotate(iWidth,iHeight,E_MI_SYS_ROTATE_180,false,false);	
    }
    else if(6 == RotateNum)//0度转270度
    {
        change_scl_resolution_rotate(iHeight,iWidth,E_MI_SYS_ROTATE_270,false,false);	
    }
	
}


void TakePhoto()
{
    FILE* mFd;
    time_t now = 0;
	struct tm *tm = NULL;
	MI_U32 len = 0;
	char szFilePathName[128];
    
	if ((g_i_MainCam == 2)||(g_i_MainCam == 3))//(主视频为mipi摄像头)
    {
        g_i_Display = 1;
        if (g_i_TakePhoto == 1)
        {
            printf("theone jason g_i_TakePhoto\n");
          /*  if(1 == GetWaterMark())
            {
                ST_UpdateRgnOsdProcExt();
                usleep(100*1000);
            }*/ 
			g_i_Read_PhotoFileIndex_Flag = 1;
			mFd = fopen("/mnt/Sys/PhotoFileIndex","rb+");
			if(mFd == NULL)
			{
                mFd = fopen("/mnt/Sys/PhotoFileIndex","wb+");
                if(mFd == NULL)
                {
                    printf("---------------------PhotoFileIndex open false !------------------------------\n");
                }
                fwrite(&g_i_PhotoFileIndex,1,sizeof(int),mFd);
                fclose(mFd);
                mFd = NULL;
			}
			else
			{
                fread(&g_i_PhotoFileIndex,1,sizeof(int),mFd);
                g_i_PhotoFileIndex--;
                fseek(mFd,0,SEEK_SET);
                fwrite(&g_i_PhotoFileIndex,1,sizeof(int),mFd);
                fclose(mFd);
                mFd = NULL;
			}
           
    		memset(g_szFileName, 0, sizeof(g_szFileName));
    		now = time(NULL);
    		tm = localtime(&now);
    		len = 0;

    		len += sprintf(g_szFileName + len, "%08d_", g_i_PhotoFileIndex);
    		len += sprintf(g_szFileName + len, "%d_", tm->tm_year + 1900);
    		len += sprintf(g_szFileName + len, "%02d_", tm->tm_mon + 1);
    		len += sprintf(g_szFileName + len, "%02d_", tm->tm_mday);
    		len += sprintf(g_szFileName + len, "%02d_", tm->tm_hour);
    		len += sprintf(g_szFileName + len, "%02d_", tm->tm_min);
    		len += sprintf(g_szFileName + len, "%02d", tm->tm_sec);
    		len += sprintf(g_szFileName + len, ".%s", "jpg");

            sprintf(szFilePathName,"%s%s",PATH_PHOTO,g_szFileName);
            printf("g_i_TakePhoto FilePathName=%s\n",szFilePathName);
            //printf("g_szFileName=%s\n",g_szFileName);

            if (g_Fd != NULL)
    		{
    			fclose(g_Fd);
    			g_Fd = NULL;
    		}

    		g_Fd = fopen(szFilePathName,"wb+");
    		if(g_Fd == NULL)
    		{
    			printf("---------------------open false !------------------------------\n");
    		}
            if (g_i_TakePhoto == 1)
            { 
        	    if (g_Fd != NULL)
        		{ 
                    StartJpegRecord();
                    printf("theone jason g_i_TakePhoto ok\n");
        			fclose(g_Fd);
        			g_Fd = NULL;
                    
               /*     if(1 == GetWaterMark())
                    {
                        MI_RGN_CanvasInfo_t* pstCanvasInfo = NULL;
                        g_stRgnOsd.bRun = FALSE;
                        CANVAS_LOCK;
                        (void)ST_OSD_GetCanvasInfo(RGN_OSD_HANDLE, &pstCanvasInfo);
                        (void)ST_OSD_Clear(RGN_OSD_HANDLE, NULL);
                        (void)ST_OSD_Update(RGN_OSD_HANDLE);
                        CANVAS_UNLOCK;
                    }*/
                    
        		}
        		g_i_TakePhoto = 2;
        	}
		}
//        usleep(1000*100);
    }
}

//切换主视频
void ChangeMainCam()
{
 	if (g_i_UsbCam > 0)
	{
		if (g_i_MipiCam > 0)
		{
			if (g_i_MainCam == g_i_UsbCam)
		      SetCamToMainVideo(g_i_MipiCam);//设置Mipi摄像头为主视频
		    else
			  SetCamToMainVideo(g_i_UsbCam);//设置Usb摄像头为主视频	
		}
	}
}

//初始话电压检测
int InitCheckVoltage()
{
#ifdef SYS_WIN
#else
    if (g_i_Check_Vol_Flag == 1)
        return 0;

    g_i_Vol_Fd = open("/dev/sar", O_RDWR);
    if (g_i_Vol_Fd < 0)
    {
        printf("open voltage error");
        return -1;
    }

    if (0 > ioctl(g_i_Vol_Fd, MS_SAR_INIT))
    {
        printf("ioctl MS_SAR_INIT error");
        close(g_i_Vol_Fd);
        return -2;
    }

    g_i_Check_Vol_Flag = 1;
#endif
    return 0;
}



//电压检测
int CheckVoltage()
{
#ifdef SYS_WIN
#else
    SAdc_Config_Read_Adc_T stCfg;

    if  (InitCheckVoltage() >= 0)
    {
          memset(&stCfg, 0, sizeof(SAdc_Config_Read_Adc_T));

          stCfg.channel_value = 0;
          if (0 > ioctl(g_i_Vol_Fd,MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg))
          {
              printf("ioctl MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC error");
              close(g_i_Vol_Fd);
              g_i_Check_Vol_Flag = -1;
              return -1;
          }

          g_f_Vol = ((float)(stCfg.adc_value)/(float)0x3FF) * 3.3;
		  

		  if (iChangeSen == 1)
		  {
				  if ((g_f_Vol >=1.2)&&(g_f_Vol <= 1.6))//Mipi摄像头插入(6946)
				  {
					 if (g_i_MipiCam != 2)
					 {
							 //if (iFirstStart > 0) 
								//St_BaseMipiModuleUnInitFun();
							 if (iFirstStart == 0) 
							    St_BaseMipiModuleInitFun();
							 SetCamToMainVideo(2);//设置Mipi摄像头为主视频
							 iFirstStart = 1;
							 printf("init mipi module\r\n");
					 }
				  }
				  else if (g_f_Vol <= 0.4)//Mipi摄像头拔出
				  {
					 if (g_i_MipiCam == 2)
					 {
						 ReleaseCam(2);//释放Mipi摄像头
						 printf("release mipi module\r\n");
					 }
				  }
		  }

     //     printf("get success for sar0, chn=%d, value=%d, vol=%f\n", stCfg.channel_value, stCfg.adc_value,g_f_Vol);
    }
#endif
    return 0;
}

//综合线程
void *Proc_Composite(void *arg)
{
    while (1)
	{
		//拍照
		TakePhoto();
		//电压检测(摄像头切换和各个按键用)
		CheckVoltage();
		
		usleep(20000);
	}
}

//删除SD卡的文件
/*void ST_RemoveSdCardFile()
{
	system("rm sdupgrade -rf");
	system("mkdir sdupgrade");
	system("mv IPL sdupgrade;mv IPL_CUST sdupgrade;mv UBOOT sdupgrade;mv upgrade_script sdupgrade;sync;");
}*/