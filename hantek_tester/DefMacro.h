#ifndef _HT_SCOPE_DEFINE_MACRO_H
#define _HT_SCOPE_DEFINE_MACRO_H
//
//#define DSO3064
//#define DSO3054R10
//校正
//#define DSO_6000_12DIV 
//#define NEW_DELAY_ZHANG

#define GDIPLUS
#define EE_OFFSET		0x200
#define D10_100DELAY 
#define AUTOSET_TIME1 19
#define AUTOSET_TIME2 18
#define DRIVERVERLEN	8//必须为偶数
#ifdef DSO_6000_12DIV
	#define ZERO_START_VOLT 4
#elif defined D10_100DELAY
	#define ZERO_START_VOLT 5
#else
	#define ZERO_START_VOLT 0
#endif
#define TRIGGER_VIDEO_POSITIVE (-900)//mV单位
#define TRIGGER_VIDEO_NEGATIVE (900)//mV单位
#ifdef DSO_6000_12DIV 
	#define CALI_2mV 	3//8
	#define CALI_5mV 	8//8
	#define CALI_10mV 	15
	#define CALI_20mV 	30
	#define CALI_50mV 	70
	#define CALI_100mV 	30
	#define CALI_200mV 	60//6.4
	#define CALI_500mV 	18
	#define CALI_1V 	35
	#define CALI_2V 	71
	#define CALI_5V 	35
	#define CALI_10V 	70
	#define CALI_FACTOR  0.6
#elif defined D10_100DELAY
	#define CALI_2mV 	2//8
	#define CALI_5mV 	6//8
	#define CALI_10mV 	12
	#define CALI_20mV 	30
	#define CALI_50mV 	60
	#define CALI_100mV 	120
	#define CALI_200mV 	30
	#define CALI_500mV 	60
	#define CALI_1V 	120
	#define CALI_2V 	30
	#define CALI_5V 	60
	#define CALI_10V 	120
	#define CALI_FACTOR  0.6

#else 
	#define CALI_5mV 	4//8
	#define CALI_10mV 	16
	#define CALI_20mV 	32
	#define CALI_50mV 	80
	#define CALI_100mV 	160
	#define CALI_200mV 	3.2//6.4
	#define CALI_500mV 	16
	#define CALI_1V 	32
	#define CALI_2V 	64
	#define CALI_5V 	160
	#define CALI_FACTOR  0.3

#endif
//校正
 #define HTQAS00028     //以起案书的编号为宏，内容是3074A软件改动
//#define FRAME_START_UP	//开机画面	2014.01.21
   
#define	HANA_FPGA_SOFT_FIND_POS		0x0248	//Hana的软件找触发处理

//#define VIEW_SELF_AUTOMOTIVE		//自定义汽车测量界面

#define DEF_AUTOMOTIVE_ITME_CNT		78		//自定义汽车项的个数
#define DEF_SEFT_TOOL_BAR_HEIGHT	70		//自定义工具条的默认高度

#define DSO3000_NEW		//2015-05-20经公司觉得，不在生产老板的3064，就用3074作为新的3064
							//而且，需要兼容旧板的运行程序

//#define HANASCOPE

//#define  LAN_DEBUG		//调试网口
//#define CONNECT_LAN			//
//#define _FPGA_TEST			//FPGA 升级测试

//Arial语言的字符集选择
//#define USE_ARIAL_CHARSET_CHOICE		//决定是否使用切换字符集

#ifdef	USE_ARIAL_CHARSET_CHOICE
	#ifdef HANASCOPE
		#define DEFAULT_ARIAL_CHARSET		ARABIC_CHARSET			//阿拉伯文
	#else
		#define DEFAULT_ARIAL_CHARSET		ANSI_CHARSET			//西欧
	#endif
#else
	#define DEFAULT_ARIAL_CHARSET			ANSI_CHARSET			//西欧
#endif


//不同电路板驱动的认定
#define DRIVER_CODE_FIRST				0			//1号驱动板
#define DRIVER_CODE_SECOND				1			//2号驱动板
#define MAX_DRIVER_CODE_NUM				2			//驱动板的数量


//不同硬件(型号)识别...............
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////********DSO3064*****///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#ifdef DSO3064
	#ifdef DSO3074
		#define	DEVICE_NAME					_T("DSO-3074")
		#define PROGRAM_TITLE				_T("DSO-3074 Ver1.0.8")
		#define SF_VERSION					_T("1.0.8");
		#define NO_MENU_AUTOMOTIVE
	#elif defined(SEALEY)
		#define	DEVICE_NAME					_T("TA4000")
		#define PROGRAM_TITLE				_T("Sealey TA4000 Ver1.0.5")
		#define SF_VERSION					_T("1.0.5");
	#elif defined(_8786N)
		#define	DEVICE_NAME					_T("8786N")
		#define PROGRAM_TITLE				_T("8786N Ver1.0.5")
		#define SF_VERSION					_T("1.0.5");
	#elif defined(_TENMA10175)
		#define	DEVICE_NAME					_T("TENMA72-10175")
		#define PROGRAM_TITLE				_T("TENMA72-10175 Ver1.0.9")		//在1.0.8基础上解决Autoset操作时时基到1us
		#define SF_VERSION					_T("1.0.9");
	#else
		#ifdef DSO3000_NEW
			#define	DEVICE_NAME					_T("DSO-3064_DSO6104")      //
			#define PROGRAM_TITLE				_T("DSO-3064_DSO6104 Ver2.0.11")
			#define SF_VERSION					_T("2.0.11");
		#else
			#define	DEVICE_NAME					_T("DSO-3064")
			#define PROGRAM_TITLE				_T("DSO-3064 Ver1.0.10")
			#define SF_VERSION					_T("1.0.10");
		#endif
	#endif
//定义垂直8bit精度
	#define VERTICAL_8BIT
//水平
	#define MAX_TIMEDIV_NUM				35	//总时基档位个数		
	#define TIMEDIV_OFFSET				3	//时基偏移量
	
	#define AUTOMOTIVE						//定义是否有汽车测量功能
//
	
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////********DSO3054R10*****///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#elif defined DSO3054R10

	#define	DEVICE_NAME					_T("DSO-3054R10 USB")
	#define PROGRAM_TITLE				_T("DSO-3054R10 USB Ver1.0.0")
	#define SF_VERSION					_T("1.0.0");
//定义垂直10bit精度
	#define VERTICAL_10BIT
//水平
	#define MAX_TIMEDIV_NUM				35	//总时基档位个数		
	#define TIMEDIV_OFFSET				3	//时基偏移量	
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////********DSO3064A*****///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#elif defined DSO3064A
	#ifdef AD_DS
		#define	DEVICE_NAME					_T("DS-3064A")
		#define PROGRAM_TITLE				_T("DS-3064A Ver1.0.8")
		#define SF_VERSION					_T("1.0.8");
	#elif defined(_TENMA10177)
		#define	DEVICE_NAME					_T("TENMA72-10177")
		#define PROGRAM_TITLE				_T("TENMA72-10177 Ver1.0.8")
		#define SF_VERSION					_T("1.0.8");
	#else
		#ifdef DSO3000_NEW
			#define	DEVICE_NAME					_T("DSO-6000")
			#define PROGRAM_TITLE				_T("DSO-6000")
			#define SF_VERSION					_T("2.0.9");
		#else
			#define	DEVICE_NAME					_T("DSO-3064A")
			#define PROGRAM_TITLE				_T("DSO-3064A Ver1.0.10")
			#define SF_VERSION					_T("1.0.10");
	//		#define NO_MENU_AUTOMOTIVE
		#endif
	#endif
//定义垂直8bit精度
	#define VERTICAL_8BIT
//水平
	#define MAX_TIMEDIV_NUM				36	//总时基档位个数		
	#define TIMEDIV_OFFSET				3	//时基偏移量
	#define AUTOMOTIVE						//定义是否有汽车测量功能
	#define FUN_DDS						1	//定义是否有DDS功能
	
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////********DSO6000*****///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#elif defined DSO6000

	#define	DEVICE_NAME					_T("DSO-6000")
	#define PROGRAM_TITLE				_T("DSO-6000")
	#define SF_VERSION					_T("2.0.9");
//定义垂直8bit精度
	#define VERTICAL_8BIT
//水平
	#define MAX_TIMEDIV_NUM				36	//总时基档位个数		
	#define TIMEDIV_OFFSET				3	//时基偏移量
	#define AUTOMOTIVE						//定义是否有汽车测量功能
	#define FUN_DDS						1	//定义是否有DDS功能
//////////////////////////////////////////////////////////////////////////////////////
///////////////////////********DSO3074A*****///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
#elif defined DSO3074A

	#ifdef VIEW_SELF_AUTOMOTIVE
		//汽车专用
		#define	DEVICE_NAME					_T("Automotive Oscilloscope")						//_T("DSO-3074")
		#define PROGRAM_TITLE				_T("Automotive Oscilloscope Ver1.0.1")			//_T("DSO-3074 Ver1.0.8")
		#define SF_VERSION					_T("1.0.1")								//_T("1.0.9")
	#else
		//给德国的定制
		#define	DEVICE_NAME					_T("DSO-2074G USB")						//_T("DSO-3074A")
		#define PROGRAM_TITLE				_T("DSO-2074G USB Ver1.0.2")			//_T("DSO-3074A Ver1.0.9")
		#define SF_VERSION					_T("1.0.2")								//_T("1.0.9")
		//	#define NO_MENU_AUTOMOTIVE
	#endif

//定义垂直8bit精度
	#define VERTICAL_8BIT
//水平
	#define MAX_TIMEDIV_NUM				35	//总时基档位个数		
	#define TIMEDIV_OFFSET				3	//时基偏移量
	#define AUTOMOTIVE						//定义是否有汽车测量功能
	#define FUN_DDS						1	//定义是否有DDS功能
///////////////////////////////////////////////////////////////////////////////////////	
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#elif defined MINISCOPE

//#define MINI_DSO5080
#define MINI_HAN1008
//#define MINI_YDG2088
//#define MINI_PX1374		//---> 德国

//生产用软件宏
//#define _DEBUG_SOFTWARE	



//特殊版本
#define NO_MENU_AUTOMOTIVE		//没有汽车功能菜单


#ifdef MINI_DSO5080
	#ifdef _DEBUG_SOFTWARE//生产使用版
		#define	DEVICE_NAME					_T("8CH 生产专用 -- 2012-05-15-16")	//_T("DSO5080Beta -- 2012-04-27-10")//	
		#define PROGRAM_TITLE				_T("8CH 生产专用 Ver1.0.8 -- 2012-05-15-16") //_T("DSO5080Beta Ver1.0.7 -- 2012-04-27-10")//	
	#else//发布版
		#define	DEVICE_NAME					_T("DSO5080")	//_T("DSO5080Beta -- 2012-04-27-10")//	
		#define PROGRAM_TITLE				_T("DSO5080 Ver1.0.8") //_T("DSO5080Beta Ver1.0.7 -- 2012-04-27-10")
	#endif
#elif defined(MINI_HAN1008)
	#define	DEVICE_NAME					_T("HANTEK1008")
	#define PROGRAM_TITLE				_T("HANTEK1008 Ver1.0.11")		//2013.3.19应于公要求升级到1.0.9
																		//2013.6.4修改2ms，5ms死机问题版本修改到1.0.10
																		//2013.11.13,修改保存数据值错误，版本修改到1.0.11
#elif defined(MINI_YDG2088)
	#define	DEVICE_NAME					_T("YDG-2088")
	#define PROGRAM_TITLE				_T("YDG-2088 Ver1.0.8")
#elif defined(MINI_PX1374)
	#define	DEVICE_NAME					_T("PX-1374")
	#define PROGRAM_TITLE				_T("PX-1374 Ver1.0.8")
#else
	#define	DEVICE_NAME					_T("HT2095NTLV")
	#define PROGRAM_TITLE				_T("HT2095NTLV Ver1.0.8")
#endif
	#define SF_VERSION					_T("1.0.11");
//定义垂直8bit精度
	#define VERTICAL_12BIT
//水平
	#define MAX_TIMEDIV_NUM				41	//总时基档位个数		
	#define TIMEDIV_OFFSET				1	//时基偏移量
	
	#define AUTOMOTIVE	//定义是否有汽车测量功能

#elif defined DSO2200G
	#define	DEVICE_NAME					_T("DSO2200G")
	#define PROGRAM_TITLE				_T("DSO2200G Ver1.0.0")
	#define SF_VERSION					_T("1.0.0");
//定义垂直8bit精度
	#define VERTICAL_8BIT
//水平
	#define MAX_TIMEDIV_NUM				35	//总时基档位个数		
	#define TIMEDIV_OFFSET				3	//时基偏移量
	
#else
	#ifdef _LAUNCH
		#ifdef HANASCOPE
			#define	DEVICE_NAME					_T("HanaScope 11")
			#define PROGRAM_TITLE				_T("HanaScope 11 USB Ver1.0.3")			//在1.0.2版本上，添加韩语  //在1.0.1版本，修改校正方式
			#define SF_VERSION					_T("1.0.3");


	#define AUTOMOTIVE	//定义是否有汽车测量功能

		#else
			#define	DEVICE_NAME					_T("DSO-2250 USB")
			#define PROGRAM_TITLE				_T("DSO-2250 USB Ver1.0.4")
			#define SF_VERSION					_T("1.0.4");
		#endif
	#else
		#define	DEVICE_NAME					_T("DSO-XXXX USB")
		#define PROGRAM_TITLE				_T("DSO-XXXX USB Ver1.0.1")
		#define SF_VERSION					_T("1.0.0");
	#endif
//定义垂直10bit精度
	#define VERTICAL_8BIT
//水平
	#define MAX_TIMEDIV_NUM				35	//总时基档位个数		
	#define TIMEDIV_OFFSET				3	//时基偏移量

#endif


//ID_UTILITY_UPDATE Update


//Scan 模式是否有10K长度限制(也就是说SCAN模式只有在10K长度下才能使用)
#define BUF_10K_LIMIT			

//**********************************

#define ROLL_STEP_32	32	//ROLL/SCAN读取一次数据的步进

//Project
#define DSO			0	//示波器
#define DDS			1	//信号源
#define LA			2	//逻辑分析仪


#define MAX_USB_DEV_NUMBER			32						//PC最大设备连接数目
//
#define _NO_SN				//不在设备列表和DOC标题栏显示SN
#define MIN_DEMO_POS	MAX_USB_DEV_NUMBER	//模拟状态在设备列表中最小位置

#define THREAD_TIMEOUT				0						//
#define	PI							3.14159265358979323846
//Communication
#define USB							0
#define NET							1
#define NET_LAN						2
#define NET_WIFI					3

#define UDP							0
#define TCP_IP						1

//频率单位定义
#define FREQUENCY_UNIT_HZ			0
#define FREQUENCY_UNIT_KHZ			1
#define FREQUENCY_UNIT_MHZ			2
#define MAX_FREQUENCY_UNIT			3

#define MIN_SWEEPSTEPS_NUM			2	//最小扫描步骤数
#define SWEEP_FREQUENCY_LINEAR		0	//线性扫频
#define SWEEP_FREQUENCY_LOGARITHM	1	//对数扫频
#define	MAX_SWEEP_FREQUENCY_TYPE	2	//最大扫频数目

//#define CREATE_DEV_ID(nMode,nIndex)	(((nMode)<<4) | nIndex)//设备ID，高4位：传输协议，低4位：设备索引
//水平***********************************************************/
//#define BUF_ETS_LEN				500
#define BUF_4K_LEN					0x1000
#define BUF_3K_LEN					0x0C00//3072
#define BUF_8K_LEN					0x2000
#define BUF_16K_LEN					0x4000
#define BUF_32K_LEN					0x8000
#define BUF_64K_LEN					0x10000
#define BUF_10K_LEN					10240  
#define BUF_1M_LEN					1048576
#define BUF_2M_LEN					2097152
#define BUF_4M_LEN					4194304
#define BUF_8M_LEN					8388608
#define BUF_12M_LEN					12582912			
#define BUF_16M_LEN					16252928
#define BUF_40K_LEN					40960 //40960//32768
#define BUF_INSERT_LEN 				BUF_40K_LEN


#ifndef MINISCOPE
	#define DEF_READ_DATA_LEN			BUF_4K_LEN //BUF_10K_LEN		//默认读取的数据长度
	#define DEF_DRAW_DATA_LEN			2500 //10000			
#else
	#define DEF_READ_DATA_LEN			BUF_4K_LEN		
	#define DEF_DRAW_DATA_LEN			BUF_4K_LEN
#endif

#define MAX_INSERT_TIMEDIV			6	//200nS						//最大需要插值的时基  //modified by zhang from 9 to 5  200ns
#define MAX_DOUBLE_TIMEDIV			MAX_INSERT_TIMEDIV
#define MAX_SF_T_TIMEDIV			MAX_INSERT_TIMEDIV - 2  //需要软件找触发的时基
#define MAX_SINE_TIMEDIV			3////2////2  //小于3必须正弦插值
//#define INSERT_DATA_LEN				4*BUF_1K_LEN
#define INSERT_MODE_SIN				2
#define INSERT_MODE_STEP			0
#define INSERT_MODE_LINEAR			1
#define YT							0
#define XY							1
#define YT_NORMAL					0
#define YT_SCAN						1
#define YT_ROLL						2
#define PEAK_START_TIMEDIV			5//13

#ifndef MINISCOPE

#define MIN_SCAN_TIMEDIV			25//22				//扫描模式最小时基
#define MIN_ROLL_TIMEDIV			27//24				//
#define MIN_ROLL_TIMEDIV			27//24				//

#else

#define MIN_SCAN_TIMEDIV			26				//扫描模式最小时基
#define MIN_ROLL_TIMEDIV			26				//

#endif

#define SINE_WAVE_LEN				128				//中间小窗口的波形长度
#define MAX_ETS_TIMEDIV				3		//0,1,2,3
#define ETS_SAMPLING_100M			0		//ETS 100M

//基准电平的9点校准*********************************************/
#define NEW_CAL_LEVEL_LEN			400		//1*9+9*(4*9)=334		//首个点为9代表9点校准发


//垂直***********************************************************/
//定义CH
#define CH1							0
#define CH2							1
#define CH3							2
#define CH4							3
#ifndef MINISCOPE
	#ifdef DSO2200G
		#define MAX_CH_NUM				2
	#else
		#define MAX_CH_NUM				4				//定义最大输入通道数(不包括MATH/REF)
	#endif
#else
	#define CH5						4
	#define CH6						5
	#define CH7						6
	#define CH8						7
	#define MAX_CH_NUM				8				//定义最大输入通道数(不包括MATH/REF)

//
#ifdef MINI_PX1374
	#define ENGLISH				0
	#define GERMAN				1
	#define LANGUAGE_NUM			GERMAN+1
#else
	#define ENGLISH				0
	#define SCHINESE			1
	#define GERMAN				2
//	#define FRANCE				3
//	#define JANPAN				4
//	#define KOREA				5
	#define LANGUAGE_NUM			GERMAN//+1
#endif

#endif

#define HORIZONTAL					MAX_CH_NUM		//CH1/CH2/CH3/CH4/HORIZONTAL/(水平lever)
#define MATH						MAX_CH_NUM		//CH1/CH2/CH3/CH4/MATH/REF (垂直lever)
#define REF							MAX_CH_NUM+1	//CH1/CH2/CH3/CH4/MATH/REF (垂直lever)
#define ALL_CH						MAX_CH_NUM+2
#define MIN_DATA						0				//
#ifdef VERTICAL_8BIT
	#define MAX_DATA					255				//
	#define MID_DATA					128				//
#elif defined VERTICAL_10BIT
	#define MAX_DATA					1023			//
	#define MID_DATA					512				//
#elif defined VERTICAL_12BIT
	#define MAX_DATA					4095			//
	#define MID_DATA					2048			//
#endif

#ifdef MINISCOPE
	#ifdef NO_1_2_5MV
		#define MAX_VOLTDIV_NUM				10				//总电压档位个数

	#else
		#define MAX_VOLTDIV_NUM				12				//总电压档位个数
	#endif
#else
	#ifdef DSO_6000_12DIV

		#define MAX_VOLTDIV_NUM				12				//总电压档位个数  //to cope with DSO6104 add by zhang 2015 0914
	#elif defined D10_100DELAY
		#define MAX_VOLTDIV_NUM				12
	#else
		#define MAX_VOLTDIV_NUM				10
	#endif

#endif
//Calibration
#define CAL_VOLTDIV_NUM				20   //change from 18 to 20 by zhang 6104
#ifndef MINISCOPE
	#define CAL_LEVEL_LEN				(ZEROCALI_LEN +1)//128////change from 72 to 80 by zhang 6104
#else
	#define CAL_LEVEL_LEN				64
	#define STEP_NULL					0
	#define STEP_1						1//Zero
	#define STEP_2						2//2mV
	#define STEP_3						3//10mV
	#define STEP_4						4//100mV
	#define STEP_5						5//1V
	#define STEP_6						6						//1V -7V
	#define STEP_7						7						//1V -10V
	#define STEP_8						8						//1V -12V
	#define STEP_9						9						//1V -15V
#define STEP_10							10//30mV
#define STEP_11							11//100mV
#define STEP_12							12//160mV
#define STEP_13							13//-30mV
#define STEP_14							14//-100mV
#define STEP_15							15//-160mV
#define STEP_16							16//-200mV
#define STEP_17							17//-500mV
#define STEP_18							18//500mV
#define STEP_19							19//800mV
#define STEP_20							20//-800mV

	#define STEP_21						21//结束
#endif

#define MAX_CAL_DATA				60000 //modified by  zhang from 2200 to 52000 to fit 6104
#define SIN_FACTOR					10				//正弦插值因子
#define DC							0
#define AC							1
#define GND							2

#define X1							0
#define X10							1
#define X100						2
#define X1000						3
#define X10000						4
#ifdef AUTOMOTIVE
	#define X20							5
	#define X20A						6
	#define X65A						7
	#define X60A						8
	#define X650A						9
	#define X100A						10
	#define X1100A						11
	#define XSIP_INVERTED				12
	#define XSIP_POS					13
	#define PROBE_NUM					XSIP_POS+1		//探头的总数
#else
	#define PROBE_NUM					X10000+1		//探头的总数
#endif

//MATH
#define MATH_ADD					0
#define MATH_SUB					1
#define MATH_MUL					2
#define MATH_DIV					3
#define MATH_FFT					4

#define RECTANGLE					0
#define HANNING						1
#define HAMMING						2
#define BLACKMAN					3
#define VRMS						0
#define DBRMS						1

#ifdef MINISCOPE
	#define FFT_SRC_DATA_LEN			256
#else
	#define FFT_SRC_DATA_LEN			2048//8192  modified zhang
#endif
//触发***********************************************************/
#define MAX_TRIGGER_SOURCE_NUM		MAX_CH_NUM+2	//CH1/CH2/CH3/CH4/EXT/(EXT/10)
#define MAX_ALT_TRIGGER_NUM			MAX_CH_NUM		//CH1/CH2/CH3/CH4
#define EXT							MAX_CH_NUM		
#define EXT10						MAX_CH_NUM + 1	

#define EDGE						0
#define PULSE						1
#define VIDEO						2
#define FORCE		0x80

#define AUTO						0
#define NORMAL						1
#define SINGLE						2

#define RISE						0
#define FALL						1
/*
#define PLESS						0
#define PEQUAL						1
#define PMORE						2
#define NLESS						3
#define NEQUAL						4
#define NMORE						5
*/

#define EQUAL						0
#define UNEQUAL						1
#define MORE						2
#define LESS						3



#define POSITIVE					1
#define NEGATIVE					0

//
#define ALL_LINES					0
#define ALL_FIELD					4
#define ODD_FIELD					2
#define EVEN_FIELD					3
#define LINE_NUM					1

//0:Pal/Secam;1:Ntsc;
#define PALSECAM					0
#define NTSC						1
#define PALSECAM_MAX_LINENUM		625
#define NTSC_MAX_LINENUM			525
#define MY_WM_MSG_UPDATA_BUFFERLEN	(WM_USER+105)

//幅度校正
#define ZEROCALI_FIX_OFFSET      16
#define ZEROCALI_STEP_NUM       15
#define ZEROCALI_DISCARD_NUM    2
#define ZEROCALI_ALLOWED_OFFSET 10
#define ZEROCALI_MIN_NUM        500
#define ZEROCALI_MAX_NUM        60000
#define ZEROCALI_MID_NUM        37000//35400
#define ZEROCALI_STEP_NUM       15

#define DATA_CHECK_HOP          0x01
#define DATA_CHECK_AVE          0x02
#define CALI_MSG_ERROR       0
#define CALI_MSG_PROGRASS    1
#define CALI_MSG_FINISHED    2
#define CALI_MSG_ABORT       3
#define CALI_MSG_INFO        4
#define CALI_MSG_CALI_RESULT 5
#define DEVICE_ADDRESS  "USB0::0x049F::0x505B::HTG10000522222::0::INSTR"

#define AMPCALI_DLG             0
#define ZEROCALI_DLG             1
#define AMPCALI_FLAG            0xFACF
#define TIMEDIV_1GSA            6
#define TIMEDIV_500MSA          7
#define TIMEDIV_250MSA          8

#define AMPCALI_NEED_FIRST_FRAME        1
#define AMPCALI_FRAME_NUM               5
#define AMPCALI_INPUT_RANGE             0.875
#define AMPCALI_PER_VOLT_Len    		6
#define AMPCALI_PER_CH_Len              (AMPCALI_PER_VOLT_Len*MAX_VOLTDIV_NUM)  
#define AMPCALI_ALLOW_OFFSET    		0.5
#define AMPCALI_DEGREE_OFFSET			180
#define AMPCALI_DEGREE                  1024
#define AMPCALI_Len                     (AMPCALI_PER_CH_Len*MAX_CH_NUM)
#define AMPCALI_DATA_Len                (AMPCALI_Len*2)
#define AMPCALI_ALLOWED_OFFSET  5//(1-AMPCALI_INPUT_RANGE)*(MAX_DATA-MIN_DATA)*0.5*0.5

#define ZERO_FLAG				0xFBCF
#define ZERO_MAN_OFFSET			0 
#define ZEROCALI_LEN            (ZEROCALI_PER_CH_LEN*MAX_CH_NUM)
#define ZEROCALI_PER_CH_LEN     (ZEROCALI_PER_VOLT_LEN*MAX_VOLTDIV_NUM)
#define ZEROCALI_PER_VOLT_LEN   12
#define ZEROCALI_FRAM_NUM       6
#define ZEROCALI_SLEEP			0//3


#define DDS_CALI_LEN	4      //注意这里指WORD
#define DDS_AMP_OK      0xEAEA
#define DDS_CALI_OK     0xABAB
//显示**********************************************************/
#define TRANSPARENT_COLOR			RGB(236,233,216)	//定义透明色
#define BLACK_COLOR					RGB(0,0,0)			//黑色
#define WHITE_COLOR					RGB(255,255,255)	//白色
#define RED_COLOR					RGB(255,0,0)		//红色
#define GREEN_COLOR					RGB(0,255,0)		//绿色
#define BLUE_COLOR					RGB(0,0,200)		//蓝色
#define SKY_COLOR					RGB(0,255,255)		//天蓝色
#define YELLOW_COLOR				RGB(255,255,0)		//黄色
#define	PINK_COLOR					RGB(255,0,255)		//粉红色
#define BROWN_COLOR					RGB(255,128,0)		//棕色
#define FRENCHGRAY_COLOR			RGB(155,155,155)	//浅灰色
#define DEEPGRAY_COLOR				RGB(50,50,50)		//深灰色
#define PURPLE_COLOR				RGB(128,0,255)		//紫色
#define JADEGREEN_COLOR				RGB(128,255,128)	//浅绿色
#define ORANGE_COLOR				RGB(255,127,0)		//橙色
#define AM1_COLOR					RGB(200,200,0)		//AM1 COLOR	较对应的CH1，颜色浅一些
#define AM2_COLOR					RGB(0,200,200)		//AM2 COLOR	较对应的CH2，颜色浅一些
#define AM3_COLOR					RGB(200,0,200)		//AM3 COLOR	较对应的CH3，颜色浅一些
#define AM4_COLOR					RGB(0,200,0)		//AM4 COLOR	较对应的CH4，颜色浅一些
#ifdef MINISCOPE

#define AM5_COLOR					RGB(0,100,225)		//AM5 COLOR	较对应的CH5，颜色浅一些
#define AM6_COLOR					RGB(100,100,227)		//AM6 COLOR	较对应的CH6，颜色浅一些
#define AM7_COLOR					RGB(100,0,227)		//AM7 COLOR	较对应的CH7，颜色浅一些
#define AM8_COLOR					RGB(227,100,164)		//AM8 COLOR	较对应的CH8，颜色浅一些

#endif
#define XY_COLOR					RGB(0,218,236)
#define CH1_COLOR					YELLOW_COLOR	
#define CH2_COLOR					SKY_COLOR
#define CH3_COLOR					PINK_COLOR
#define CH4_COLOR					GREEN_COLOR	
#define CH5_COLOR					RGB(0,128,255)
#define CH6_COLOR					RGB(255,208,100)
#define CH7_COLOR					PURPLE_COLOR
#define CH8_COLOR					RGB(255,128,192)
#define MATH_COLOR					RED_COLOR
#define REF_COLOR					WHITE_COLOR
#define EXT_COLOR					BROWN_COLOR
#define HORI_COLOR					BLUE_COLOR
#define TRIG_COLOR					BROWN_COLOR

#define GRID_BRIGHT					200 //网格亮度
#define MAX_VCH_LEVER_NUM			MAX_CH_NUM+2	//CH1/CH2/CH3/CH4/MATH/REF
#define MAX_H_LEVER_NUM				MAX_CH_NUM+1	//CH1/CH2/CH3/CH4/HORIZONTAL
#define VCH_LEVER					0
#define VT_LEVER					1
#define H_LEVER						2
#define AM_LEVER					3
#define CUR_NONE					0
#define CUR_CROSS					1
#define CUR_TRACE					2
#define CUR_VERTICAL				3
#define CUR_HORIZONTAL				4
#define VECTORS						0
#define DOTS						1
#define V_GRID_NUM					8//垂直8个大格
#define H_GRID_NUM					10//水平10个大格
//Lever Position
#define DIRECTION_LEFT				0
#define DIRECTION_RIGHT				1
#define DIRECTION_TOP				2
#define DIRECTION_BOTTOM			3


//Measure
#define MAX_MEAS_LEN				8
//Voltage 12种
#define MEAS_VPP			0
#define MEAS_VMAX			1
#define MEAS_VMIN			2
#define MEAS_VAMP			3
#define MEAS_VTOP			4
#define MEAS_VMID			5
#define MEAS_VBASE			6
#define MEAS_VAVG			7
#define MEAS_VCAVG			8
#define MEAS_VRMS			9
#define MEAS_VCRMS			10
#define MEAS_VPRE			11
#define MEAS_VOVER			12
//Time 10种
#define MEAS_PERIOD			13
#define MEAS_FREQ			14
#define MEAS_RISE			15
#define MEAS_FALL			16
#define MEAS_PDUTY			17
#define MEAS_NDUTY			18
#define MEAS_PWIDTH			19
#define MEAS_NWIDTH			20
#define MEAS_PDELAY12		21
#define MEAS_NDELAY12		22

//控制
#define SAMPLE_NORMAL			0
#define SAMPLE_PEAK				1
#define SAMPLE_ETS				2
#define SAMPLE_AVG				3

#define NO_ZOOM					-1
#define ZOOM_OUT				0
#define ZOOM_IN					1
//RunStatus--0:STOP;1:RUN;2:Tri'D;3:AUTO;4:WAIT;
#define STATUS_STOP			0
#define STATUS_RUN			1
#define STATUS_TRID			2
#define STATUS_AUTO			3
#define STATUS_WAIT			4
#define STATUS_PLAY			5
#define STATUS_ALT			6
#define STATUS_REC			7

#define AVG_0				0
#define AVG_4				4
#define AVG_16				16
#define AVG_64				64
#define AVG_128				128
#define AVG_MAX				AVG_128

//频率计模式
#define FC_F				100000000  //实际时间：1E8*8nS=0.8S
#define FC_C				1000000000	//正常运行  1S  nS单位
#define FC_OFF				2
//Save
#define FILE_TXT			0	//Text
#define FILE_DOC			1	//Word
#define FILE_XLS			2	//Excel
#define FILE_REF			3	//Ref
#define FILE_CSV			4	//CSV
#define FILE_WMS			5	//waveform setup//数据+配置

//PASSFAIL
#define FAIL				0
#define FAIL_BEEPER			1
#define PASS				2
#define PASS_BEEPER			3
//Record
#define MAX_RECORD_FRAME	1000

//Update
#define UPDATE_FIALE_LEN	524288	//bytes
//
#define TYPE_VERSION		0		//产品类型
#define NAME_VERSION		1		//产品名称
#define PCB_VERSION			2		//PCB版本
#define DRIVER_VERSION		3		//驱动版本号
#define PRODUCTOR_VERSION	4		//生产小组
#define PACKAGER_VERSION	5		//包装小组
#define SN_VERSION			6		//产品编号
#define PRODUCE_VERSION		7		//生产日期
#define TESTTIME_VERSION	8		//测试日期
#define TESTSN_VERSION		8		//测试人员
#define FPGA_VERSION		10		//FPGA版本号

//内存分配段
#define TYPE_LEN		6		//产品类型
#define NAME_LEN		8		//产品名称
#define PCB_LEN			6		//PCB版本
#define DRIVER_LEN		6		//驱动版本号
#define PRODUCTOR_LEN	4		//生产小组
#define PACKAGER_LEN	4		//包装小组
#define SN_LEN			8		//产品编号
#define PRODUCE_LEN		8		//生产日期
#define TESTTIME_LEN	8		//测试日期
#define TESTSN_LEN		4		//测试人员
#define FPGA_LEN		6		//FPGA版本号
#define SUBVERSION_LEN	2		//子版本
#define DEV_INFO_LEN	(TYPE_LEN+NAME_LEN+PCB_LEN+DRIVER_LEN+PRODUCTOR_LEN+PACKAGER_LEN+SN_LEN+PRODUCE_LEN+TESTTIME_LEN+TESTSN_LEN+FPGA_LEN+SUBVERSION_LEN) //128//
#define DDS_CALI_LEN	4      //注意这里指WORD
#define MAX_MINIFLASH_LEN		20

#define R_STORAGE	0
#define R_PLAY		1

#define STORAGE_MEMORY	0
#define STORAGE_DISK	1
//结构体
typedef struct _HT_MEASURE_ITEM
{
	BOOL Enable;
	short nSource;
	short nType;
}HT_MEASURE_ITEM,*PHT_MEASURE_ITEM;
//
typedef struct _HT_MSG_STRUCT
{
	USHORT nType;
	__int64 nValue;
	double dbValue;
}HTMSG,*PHTMSG;
//
typedef struct _HT_DATA_MATCH
{
	USHORT nTimeDIV;//时基
	USHORT nVoltDIV;//电压档位
	USHORT nLeverPos;//零电平位置
	long nHTriggerPos;//水平触发点
	ULONG nReadDataLen;//读取的数据长度
	ULONG nAlreadyReadLen;//已经读取的数据长度
}DATAMATCH,*PDATAMATCH;

#ifdef MINISCOPE

typedef struct _HT_MINI_CHANNEL
{
	BOOL bEnable[MAX_CH_NUM];
	USHORT nVoltDIV[MAX_CH_NUM];
	USHORT nTimeDIV;
	USHORT nDisLever[MAX_CH_NUM];
	ULONG nSrcDataLen;
//	ULONG nDisDataLen[MAX_CH_NUM];
//	COLORREF clrRGB[MAX_CH_NUM];
//	USHORT nHTriggerPos;
	USHORT nOpenCHNum;
	USHORT* pData[MAX_CH_NUM];
	ULONG nAlreadyReadLen;//已经读取的数据长度,ROLL/SCAN下有效
}MINICH;

#endif
//



//消息
#define MSG_NULL				0x00	//空消息
#define MSG_SET_TIMEDIV			0x01	//设置时基
#define MSG_SET_CHANNEL			0x02	//设置CH开和关
#define MSG_SET_TRIGGER			0x03	//设置触发(触发模式，上升沿/下降沿，脉冲条件 ，脉宽，视频同步，视频标准，视频行数，同步输出)
#define MSG_SET_TRIGGER_SOURCE		0x2C
#define MSG_SET_CHLEVER_POS		0x04	//设置通道Lever Pos
#define MSG_SET_VTLEVER_POS		0x05	//设置垂直触发Level
#define MSG_SET_HTLEVER_POS		0x06	//设置水平触发Pos
#define MSG_SET_BUFFERLEN		0x07	//设置内存大小
#define MSG_WRITE_CAL_LEVEL		0x08	//写校对电平
#define MSG_READ_CAL_LEVEL		0x09	//读校对电平
#define MSG_ETS_TDC_CAL			0x0A	//ETS Calibration
#define MSG_SET_CONNECT_TYPE	0x0B	//设置通信方式，USB或NET
#define MSG_SET_DEV_IP			0x0C	//设置设备IP等
#define MSG_GET_DEV_IP			0x0D
#define MSG_SET_TARGET_IP		0x0E	//设置连接IP
#define MSG_WRITE_FLASH			0x0F	//写FLASH
#define MSG_READ_FLASH			0x10	//
#define MSG_SET_NET_MODE		0x11	//网络连接模式设置,WIFI/LAN

#define MSG_SET_TRIGGER_SWEEP	0x20	//设置Sweep
#define MSG_CALIBRATION			0x22	//Calibration
#define MSG_PRE_CALIBRATE		0x23	//
#define MSG_END_CALIBRATE		0x24	//
#define MSG_START_COLLECT		0x25	//
#define MSG_STOP_COLLECT		0x26
#define MSG_AUTOSET				0x27
#define MSG_AUTOSET_TIMEDIV		0x28
#define MSG_RESET_TRIG_LEVEL	0x29
#define MSG_FACTORY_SETUP		0x2A
#define MSG_LOAD_SETUP_OK		0x2B

#define MSG_DEV_PULLOUT			0x30
#define MSG_DEV_PLUG			0x31

#ifdef AUTOMOTIVE
#define MSG_AM_DATA_CHANGE		0x32
#endif

#ifdef MINISCOPE
#define MSG_SET_MINISCOPE			0x33
#define MSG_RW_FLASH				0x34//读写FLASH
#define MSG_SET_GENERATOR_TIME		0x35
#define MSG_SET_GENERATOR_OUTPUT	0x36
#define MSG_SET_IOENABLE			0x37
#define MSG_SET_SAVETODEVICE		0x38
#endif

#define MSG_SET_H_FORMAT		0x42
#define MSG_SET_YT_FORMAT		0x43
#define MSG_SET_SAMPLEMODE		0x44
#define MSG_SET_INVERT			0x45
#define MSG_CENTER_TRIGGER		0x46
#define MSG_SET_FCTYPE			0x47
#define MSG_RESET_CNTER			0x48
#define MSG_CREATE_PFMASK		0x49
#define MSG_PASSFAIL_ONOFF		0x4A
#define MSG_SET_AVERAGE			0x4B
#define MSG_RECORDER_START			0x4C
#define MSG_RECORDER_STOP			0x4D

#define MSG_READ_FPGA_VERSION		0x4E

//DDS 设置消息
#define DDS_MSG_DDSONOFF			0x50//打开关闭DDS
#define DDS_MSG_DOWNLOAD			0x51//下载波形
#define DDS_MSG_SET_FREQUENCY		0x52//设置频率
#define DDS_MSG_SET_SYNCOUT			0x53//设置同步输出
#define DDS_MSG_SET_CMD				0x54//设置单次等参数
//#define DDS_MSG_SET_POWERON		0x55//设置上电输出
#define DDS_MSG_SWEEPONOFF			0x56//
#define DDS_MSG_SWEEP_INCFREQ		0x57//扫频，频率自加
#define DDS_MSG_INIT_ARB_WARE		0x58//重新设定任意波形
#define DDS_MSG_EMIT_SINGLE			0x59//发射 Single波形  //zhang
#define MSG_SET_ADCCHMOD_GAIN	0x60
#define MSG_SET_AMP_CALI		0x61//下载波形
#define MSG_SET_CHLEVEL_DIRECT	0x62
//
#define INFO_ALREADY_HIDE			0
#define INFO_NOW_HIDE				1
#define INFO_NOW_SHOW				2
#define INFO_ALREADY_SHOW			3

/*********************************DDS*************************************/
#define WAVE_SINE		0
#define WAVE_RAMP		1
#define WAVE_SQUARE		2
#define WAVE_TRAPE		3
#define WAVE_DC			4
#define WAVE_EXP		5
#define WAVE_AM			6
#define WAVE_STORAGE	7
#define WAVE_GAUSE		8
#define WAVE_WHITE		9
#define	WAVE_ARB		10	//用户自定义波形

#define MAX_BUFFER				2048
#define MAX_CLOCK				200000000	//200M(内部时钟频率)
#define MAX_VOLT				3.5f		//最大幅度电压
#define MAX_ARB_FREQUENCY		25000000	//任意波形最大25M
#define MAX_FREQUENCY			75000000	//75M DDS 最大输出频率
#define MAX_YOFFSET				7.0			//最大偏移量
#define MIN_YOFFSET				-7.0		//最小偏移量
#define MAX_PHASE				1.0			//最大相位
#define MIN_PHASE				0.0			//最小相位
#define MAX_DUTY				1.0			//最大占空比
#define MIN_DUTY				0.0			//最小占空比
#define MAX_TAO					1.0			//最大TAO
#define MIN_TAO					0.0			//最小TAO
#define MAX_AMFM_HIGH_FRE		25000000.0		//25M
#define MIN_AMFM_HIGH_FRE		0.0				//
#define MAX_AMFM_DEPTH			1.0
#define MIN_AMFM_DEPTH			0.0
#define SWEEP_MAXFREQUENCY		100000.0
#define SWEEP_MINFREQUENCY		20.0
#define SWEEP_MAXSTEP			99980.0
#define SWEEP_MINSTEP			1.0
#define SPEED_MAXTIME			3600*60		//1h
#define SPEED_MINTIME			5			//50ms


#define UNSIGNED				0//无符号，正数
#define SIGNED					1//有符号，自然数



/********************************DDS*****************************************/


typedef unsigned char	BOOLEAN;
typedef unsigned char	INT8U;                    /* Unsigned  8 bit quantity                           */
typedef signed   char	INT8S;                    /* Signed    8 bit quantity                           */
typedef unsigned short	INT16U;                   /* Unsigned 16 bit quantity                           */
typedef signed short	INT16S;                   /* Signed   16 bit quantity                           */
typedef unsigned long	INT32U;                   /* Unsigned 32 bit quantity                           */
typedef signed   long	INT32S;                   /* Signed   32 bit quantity                           */
typedef float			FP32;                     /* Single precision floating point                    */
typedef double			FP64;                     /* Double precision floating point                    */

typedef unsigned short  HT_DEVICE_ID; //设备ID
typedef INT32U HTSTATUS; //定义返回信息
#define HT_OK		1
#define HT_ERROR	0

//
#define MAX_DRIVER_NAME				64		//最大设备名称长度
#define USB_PACK_SIZE				512		//USB上传数据包大小

//AUTOMOTIVE
#define AM_ROOT		0
#ifdef _ADD_AM_FUNCTIONS
	#define FIRSTLOOK	AM_ROOT+1//1
#else
	#define FIRSTLOOK	AM_ROOT
#endif
#define IGNITION	FIRSTLOOK+1//2
#define SENSORS		IGNITION+1//3
#define CANBUS		SENSORS+1//4
#define ACTUATORS	CANBUS+1//5
#define CHANGING	ACTUATORS+1//6
#define PRIMARY		CHANGING+1//7
#define SECONDARY	PRIMARY+1//8
#define AIRFLOW		SECONDARY+1//9
#define CAMSHAFT	AIRFLOW+1//10
#define CRANKSHAFT	CAMSHAFT+1//11
#define DISTRIBUTOR	CRANKSHAFT+1//12
#define LAMBDA		DISTRIBUTOR+1//13
#define THROTTLE	LAMBDA+1//14
#define INJECTOR	THROTTLE+1//15
#define PETROL		INJECTOR+1//16
#define DIESEL		PETROL+1//17
#define CHARGINGCIRCUITS DIESEL+1//18
#ifdef MINISCOPE
	#define GENERATOR	CHARGINGCIRCUITS+1//19
#endif
#define GENERATOR_LEN	1440 //800

///////////////////////////////////////////////////
#endif
