// -----------------------------------------------------------------------------
// KsCamFeature.h
// -----------------------------------------------------------------------------

#pragma once

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define CAM_FEA_CAPACITY				64
#define CAM_FEA_VARIANT_MAX				256
#define CAM_FEA_COMMENT_MAX				64
#define CAM_FEA_DESC_LIST_MAX			256
#define CAM_FEA_MULTIEXPOSURETIME_MAX	15
#define CAM_FEA_FRAME_SIZE_MAX			74226768	//	(7448 * (4982 + 1) * 2)


enum ECamFormatMode
{
	ecfmUnknown					= 0,
	ecfmMax						= 13,

	//	Ri2/Qi2
	ecfm4908x3264				= 1,		//	Full-16M
	ecfm2454x1632				= 2,		//		ROI
	ecfm1636x1088				= 3,		//		1/3 Average
	ecfm818x544					= 4,		//		1/3 Average and ROI
	ecfm1608x1608				= 5,		//	Full
	ecfm804x804					= 6,		//		ROI
	ecfm536x536					= 7,		//		1/3 Average
	ecfm22p2136x2136			= 8,		//	ROI-22phi of Full-16M
	ecfm22p712x712				= 9,		//			  of Full-16M 1/3 Average
	ecfm25p2424x2424			= 10,		//	ROI-25phi of Full-16M
	ecfm25p808x808				= 11,		//			  of Full-16M 1/3 Average
	ecfm17p1608x1608			= 12,		//	ROI-17phi of Full-16M
	ecfm17p536x536				= 13,		//			  of Full-16M 1/3 Average
	//	Fi3
	ecfsH2880x2048				= 1,		//	Full
	ecfsH1440x1024Roi			= 2,		//		ROI
	ecfsH1440x1024				= 3,		//		1/2 Average
	ecfsH3096x2088				= 4,		//	Raw-Full			-> Application can't use.
	ecfsH1548x1044				= 5,		//		1/2 Average		-> Application can't use.
};

enum ECamFormatColor
{
	ecfcUnknown					= 0,
	ecfcMax						= 4,

	ecfcRgb24					= 1,
	ecfcYuv444					= 2,
	ecfcMono16					= 3,
	ecfcMonoUp16				= 4,
};

enum ECamFeatureId
{
	eUnknown				= 0,

	//	Normal features
	eExposureMode			= 1,
	eExposureBias			= 2,
	eExposureTime			= 3,
	eGain					= 4,
	eMeteringMode			= 5,
	eMeteringArea			= 6,
	eExposureTimeLimit		= 7,
	eGainLimit				= 8,
	eCaptureMode			= 9,

	eBrightness				= 13,
	eSharpness				= 14,
	eHue					= 15,
	eSaturation				= 16,

	eTone					= 17,	//	is not used by application.

	eWhiteBalanceRed		= 18,
	eWhiteBalanceBlue		= 19,
	eWhiteBalanceGreen		= 20,	//	is not used by application.

	eOnePushWhiteBalance	= 25,	//	is not used by application.(by Command)
	ePresets				= 26,
	eMeteringAim			= 27,	//	is not used by application.(by Command)

	eTriggerOption			= 33,
	eOnePushSoftTrigger		= 34,	//	is not used by application.(by Command)
	eMultiExposureTime		= 35,
	eSignalExposureEnd		= 36,
	eSignalTriggerReady		= 37,
	eSignalDeviceCapture	= 38,
	eExposureOutput			= 39,	//	TTL
	eOnePushTriggerCancel	= 40,	//	is not used by application.(by Command)
	eCisPower				= 41,	//	is not used by application.(by Command)

	eDefectBlackShading		= 48,	//	is not used by application.
	eDefectPixel			= 49,	//	is not used by application.
	eDefectClump			= 50,	//	is not used by application.
	eDefectFillGamma		= 51,	//	is not used by application.
	eDefectGain				= 52,	//	is not used by application.
	eDefectShading			= 53,	//	is not used by application.
	eDefectMaxMin			= 54,	//	is not used by application.
	eDefectEdge				= 55,	//	is not used by application.
	eDefectVertGainFpn		= 56,	//	is not used by application.
	eDefectImitation		= 57,	//	is not used by application.
	eDefectUserGamma		= 58,	//	is not used by application.
	eDefectAxis				= 59,	//	is not used by application.
	eDefectRgb				= 60,	//	is not used by application.

	eVersion				= 61,	//	is not used by application.
	eStandbyMode			= 62,	//	is not used by application.
	eTemperature			= 63,	//	is not used by application.(by Command)

	//	Additional features
	eFormat					= 80,
	eRoiPosition			= 81,
	eTriggerMode			= 82,
};

typedef struct
{
	lx_uint32		uiFeatureId;
	lx_wchar		wszName[CAM_FEA_COMMENT_MAX];
} CAM_FeatureNameRef;

const CAM_FeatureNameRef stFeatureNameRef[] =
{
    {	eExposureMode,			L"ExposureMode"			}
//	{	eExposureBias,			L"ExposureBias"			},
//	{	eExposureTime,			L"ExposureTime"			},
//	{	eGain,					L"Gain"					},
//	{	eMeteringMode,			L"MeteringMode"			},
//	{	eMeteringArea,			L"MeteringArea"			},
//	{	eExposureTimeLimit,		L"ExposureTimeLimit"	},
//	{	eGainLimit,				L"GainLimit"			},
//	{	eCaptureMode,			L"CaptureMode"			},
//	{	eBrightness,			L"Brightness"			},

//	{	eSharpness,				L"Sharpness"			},
//	{	eHue,					L"Hue"					},
//	{	eSaturation,			L"Saturation"			},
//	{	eTone,					L"Tone"					},
//	{	eWhiteBalanceRed,		L"WhiteBalanceRed"		},
//	{	eWhiteBalanceBlue,		L"WhiteBalanceBlue"		},
//	{	eWhiteBalanceGreen,		L"WhiteBalanceGreen"	},
//	{	ePresets,				L"Presets"				},
//	{	eTriggerOption,			L"TriggerOption"		},
//	{	eMultiExposureTime,		L"MultiExposureTime"	},

//	{	eSignalExposureEnd,		L"SignalExposureEnd"	},
//	{	eSignalTriggerReady,	L"SignalTriggerReady"	},
//	{	eSignalDeviceCapture,	L"SignalDeviceCapture"	},
//	{	eExposureOutput,		L"ExposureOutput"		},

//	{	eFormat,				L"Format"				},
//	{	eRoiPosition,			L"RoiPosition"			},
//	{	eTriggerMode,			L"TriggerMode"			},

//	{	eUnknown,				L"Unknown"				}
};

enum ECamExposureMode
{
	ecemContinuousAE			= 0,
	ecemOnePushAE				= 1,	//	Exclude from select list.  Application run OnePushAE by command[CAM_CMD_ONEPUSH_AE].
	ecemManual					= 2,
	ecemMultiExposureTime		= 3,
};

enum ECamMeteringMode
{
	ecmmAverage					= 0,
	ecmmPeak					= 1,
};

enum ECamTone
{
	ectUnknown					= 0,
	ectWideDinamicRange			= 1,
	ectContrastWeak				= 2,
	ectContrastNomal			= 3,
	ectContrastStrong			= 4,
	ectLinear					= 5,
	ectMetalOrganization		= 6,
	ectContrastEmphasis			= 7,
};

enum ECamPresetsId
{
	ecpiDefault					= 0,
	ecpiIndustry_WaferIc		= 16,
	ecpiIndustry_Metal			= 17,
	ecpiIndustry_CircuitBoard	= 18,
	ecpiIndustry_Fpd			= 19,
	ecpiBio_BrightField			= 32,
	ecpiBio_He					= 33,
	ecpiBio_Ela					= 34,
	ecpiBioLed_BrightField		= 48,
	ecpiOther_Asbestos			= 64,
	ecpiOther_Linear			= 80,
};

enum ECamSignalOutput
{
	ecsoOff						= 0,
	ecsoOutput					= 1,
	ecsoLast					= 2,
};

enum ECamTriggerMode
{
	ectmOff						= 0,
	ectmHard					= 1,
	ectmSoft					= 2,
	ectmBoth					= 3,		//	Application can't use.
	ectmTriggerMax				= 3,
};


// ---- Vector_CAM_FeatureValue -----------------------------------------------------------------------------

enum ECamVariantRunType
{
	evrt_unknown = 0,
	evrt_int32,
	evrt_uint32,
	evrt_int64,
	evrt_uint64,
	evrt_double,
	evrt_bool,
	evrt_voidptr,
	evrt_wstr,
	evrt_Area,
	evrt_Position,
	evrt_TriggerOption,
	evrt_MultiExposureTime,
	evrt_Format,
};

struct CAM_Area
{
	lx_uint32	uiLeft;
	lx_uint32	uiTop;
	lx_uint32	uiWidth;		//	4x step
	lx_uint32	uiHeight;

public:
	bool operator == (CAM_Area& var)
	{
		return (uiLeft == var.uiLeft &&
				uiTop == var.uiTop &&
				uiWidth == var.uiWidth &&
				uiHeight == var.uiHeight);
	}
	bool operator != (CAM_Area& var)
	{
		return (uiLeft != var.uiLeft ||
				uiTop != var.uiTop ||
				uiWidth != var.uiWidth ||
				uiHeight != var.uiHeight);
	}
};

struct CAM_Position
{
	lx_uint32	uiX;
	lx_uint32	uiY;

public:
	bool operator == (CAM_Position& var)
	{
		return (uiX == var.uiX &&
				uiY == var.uiY);
	}
	bool operator != (CAM_Position& var)
	{
		return (uiX != var.uiX ||
				uiY != var.uiY);
	}
};

struct CAM_TriggerOption
{
	lx_uint32	uiFrameCount;
	lx_int32	iDelayTime;		//	(usec)

public:
	bool operator == (CAM_TriggerOption& var)
	{
		return (uiFrameCount == var.uiFrameCount && iDelayTime == var.iDelayTime);
	}
	bool operator != (CAM_TriggerOption& var)
	{
		return (uiFrameCount != var.uiFrameCount || iDelayTime != var.iDelayTime);
	}
};

struct CAM_MultiExposureTime
{
	lx_uint32	uiNum;
	lx_uint32	uiExposureTime[CAM_FEA_MULTIEXPOSURETIME_MAX];

public:
	bool operator == (CAM_MultiExposureTime& var)
	{
		if (uiNum != var.uiNum)
			return false;
		lx_uint32 i;
		for (i = 0; i < uiNum; i++)
			if (uiExposureTime[i] != var.uiExposureTime[i])
				return false;
		return true;
	}
	bool operator != (CAM_MultiExposureTime& var)
	{
		if (uiNum != var.uiNum)
			return true;
		lx_uint32 i;
		for (i = 0; i < uiNum; i++)
			if (uiExposureTime[i] != var.uiExposureTime[i])
				return true;
		return false;
	}
};

struct CAM_Format
{
	ECamFormatColor		eColor;
	ECamFormatMode		eMode;

public:
	bool operator == (CAM_Format& var)
	{
		return (eColor == var.eColor &&
				eMode == var.eMode);
	}
	bool operator != (CAM_Format& var)
	{
		return (eColor != var.eColor ||
				eMode != var.eMode);
	}
};

struct CAM_Variant
{
	ECamVariantRunType	eVarType;
	union
	{
		lx_int32				i32Value;
		lx_uint32				ui32Value;
		lx_int64				i64Value;
		lx_uint64				ui64Value;
		double					dValue;
		bool					bValue;
		void*					pValue;
		lx_wchar				wszValue[CAM_FEA_VARIANT_MAX];
		CAM_Area				stArea;
		CAM_Position			stPosition;
		CAM_TriggerOption		stTriggerOption;
		CAM_MultiExposureTime	stMultiExposureTime;
		CAM_Format				stFormat;
	};

public:
	bool operator == (CAM_Variant& var)
	{
		switch (eVarType) {
		case evrt_int32:				return (i32Value == var.i32Value); break;
		case evrt_uint32:				return (ui32Value == var.ui32Value); break;
		case evrt_int64:				return (i64Value == var.i64Value); break;
		case evrt_uint64:				return (ui64Value == var.ui64Value); break;
		case evrt_double:				return (dValue == var.dValue); break;
		case evrt_bool:					return (bValue == var.bValue); break;
		case evrt_voidptr:				return (pValue == var.pValue); break;
		case evrt_wstr:					return (wcscmp(wszValue, var.wszValue) == 0) ? true : false; break;
		case evrt_Area:					return (stArea == var.stArea); break;
		case evrt_Position:				return (stPosition == var.stPosition); break;
		case evrt_TriggerOption:		return (stTriggerOption == var.stTriggerOption); break;
		case evrt_MultiExposureTime:	return (stMultiExposureTime == var.stMultiExposureTime); break;
		case evrt_Format:				return (stFormat == var.stFormat); break;
		default:						return false; break;
		}
	}
	bool operator != (CAM_Variant& var)
	{
		switch (eVarType) {
		case evrt_int32:				return (i32Value != var.i32Value); break;
		case evrt_uint32:				return (ui32Value != var.ui32Value); break;
		case evrt_int64:				return (i64Value != var.i64Value); break;
		case evrt_uint64:				return (ui64Value != var.ui64Value); break;
		case evrt_double:				return (dValue != var.dValue); break;
		case evrt_bool:					return (bValue != var.bValue); break;
		case evrt_voidptr:				return (pValue != var.pValue); break;
		case evrt_wstr:					return (wcscmp(wszValue, var.wszValue) != 0) ? true : false; break;
		case evrt_Area:					return (stArea != var.stArea); break;
		case evrt_Position:				return (stPosition != var.stPosition); break;
		case evrt_TriggerOption:		return (stTriggerOption != var.stTriggerOption); break;
		case evrt_MultiExposureTime:	return (stMultiExposureTime != var.stMultiExposureTime); break;
		case evrt_Format:				return (stFormat != var.stFormat); break;
		default:						return false; break;
		}
	}
};

struct CAM_FeatureValue
{
	lx_uint32			uiFeatureId;
	CAM_Variant			stVariant;
	lx_uchar8			ucTransSize;		//	Application don't use.

public:
	CAM_FeatureValue() { uiFeatureId = 0; stVariant.wszValue[0] = L'\0'; ucTransSize = 0;}
};

struct Vector_CAM_FeatureValue
{
	lx_uint32			uiCountUsed;		//	used count
	lx_uint32			uiCapacity;			//	allocated pstFeatureValue num --> max is CAM_FEA_CAPACITY
	lx_uint32			uiPauseTransfer;	//	used by SetFeatures (0=not pause, 1=pause)
	CAM_FeatureValue*	pstFeatureValue;	//	allocated by application (sizeof(CAM_FeatureValue) * uiCapacity);

public:
	Vector_CAM_FeatureValue()	{ uiCountUsed = 0; uiCapacity = 0; uiPauseTransfer=0; pstFeatureValue = NULL; };
	Vector_CAM_FeatureValue& operator = (Vector_CAM_FeatureValue& vec)
	{
		lx_uint32	count = min(vec.uiCountUsed, uiCapacity);
		uiCountUsed = count;
		uiPauseTransfer = vec.uiPauseTransfer;
		memcpy(pstFeatureValue, vec.pstFeatureValue, sizeof(CAM_FeatureValue) * uiCountUsed);
		return *this;
	}
};


// ---- CAM_FeatureDesc -----------------------------------------------------------------------------

//	for...
//		eExposureMode
//		ePresets
struct CAM_FeatureDescElement
{
	CAM_Variant				varValue;							//	enumeration
	lx_wchar				wszComment[CAM_FEA_COMMENT_MAX];
public:
	bool operator == (CAM_FeatureDescElement& var)
	{
		return (varValue == var.varValue &&
				wcscmp(wszComment, var.wszComment) == 0);
	}
	bool operator != (CAM_FeatureDescElement& var)
	{
		return (varValue != var.varValue ||
				wcscmp(wszComment, var.wszComment) != 0);
	}
};

struct CAM_FeatureDescRange
{
	CAM_Variant				stMin;
	CAM_Variant				stMax;
	CAM_Variant				stRes;
	CAM_Variant				stDef;
public:
	bool operator == (CAM_FeatureDescRange& var)
	{
		return (stMin == var.stMin &&
				stMax == var.stMax &&
				stRes == var.stRes &&
				stDef == var.stDef);
	}
	bool operator != (CAM_FeatureDescRange& var)
	{
		return (stMin != var.stMin ||
				stMax != var.stMax ||
				stRes != var.stRes ||
				stDef != var.stDef);
	}
};

struct CAM_FeatureDescArea
{
	CAM_Area				stMin;
	CAM_Area				stMax;
	CAM_Area				stRes;
	CAM_Area				stDef;
public:
	bool operator == (CAM_FeatureDescArea& var)
	{
		return (stMin == var.stMin &&
				stMax == var.stMax &&
				stRes == var.stRes &&
				stDef == var.stDef);
	}
	bool operator != (CAM_FeatureDescArea& var)
	{
		return (stMin != var.stMin ||
				stMax != var.stMax ||
				stRes != var.stRes ||
				stDef != var.stDef);
	}
};

struct CAM_FeatureDescPosition
{
	CAM_Position			stMin;
	CAM_Position			stMax;
	CAM_Position			stRes;
	CAM_Position			stDef;
public:
	bool operator == (CAM_FeatureDescPosition& var)
	{
		return (stMin == var.stMin &&
				stMax == var.stMax &&
				stRes == var.stRes &&
				stDef == var.stDef);
	}
	bool operator != (CAM_FeatureDescPosition& var)
	{
		return (stMin != var.stMin ||
				stMax != var.stMax ||
				stRes != var.stRes ||
				stDef != var.stDef);
	}
};

struct CAM_FeatureDescTriggerOption
{
	CAM_FeatureDescRange	stRangeFrameCount;
	CAM_FeatureDescRange	stRangeDelayTime;
public:
	bool operator == (CAM_FeatureDescTriggerOption& var)
	{
		return (stRangeFrameCount == var.stRangeFrameCount &&
				stRangeDelayTime == var.stRangeDelayTime);
	}
	bool operator != (CAM_FeatureDescTriggerOption& var)
	{
		return (stRangeFrameCount != var.stRangeFrameCount ||
				stRangeDelayTime != var.stRangeDelayTime);
	}
};

struct CAM_FeatureDescFormat
{
	CAM_Format				stFormat;							//	CAM_Format
	lx_uint32				uiImageWidth;
	lx_uint32				uiImageHeight;						//	Not include line of footer
	lx_uint32				uiBitPerPixel;
	lx_wchar				wszComment[CAM_FEA_COMMENT_MAX];	//	Ex. "4908x3264 RGB 24"

	//	These have a different attribute every each format.
	lx_uint32				uiTriggerListCount;					//	for stTriggerList num
	CAM_FeatureDescElement	stTriggerList[ectmTriggerMax];
	CAM_FeatureDescArea		stDescArea;
	CAM_FeatureDescPosition	stDescPosition;
};

enum ECamFeatureDescType
{
	edesc_unknown = 0,
	edesc_ElementList,
	edesc_Range,
	edesc_Area,
	edesc_Position,
	edesc_TriggerOption,
	edesc_FormatList,
};

struct CAM_FeatureDesc
{
	lx_uint32							uiFeatureId;
	lx_uint32							uiListCount;		//	for xxxList num

	ECamFeatureDescType					eFeatureDescType;
	union
	{
		CAM_FeatureDescElement			stElementList[CAM_FEA_DESC_LIST_MAX];
		CAM_FeatureDescRange			stRange;
		CAM_FeatureDescArea				stArea;
		CAM_FeatureDescPosition			stPosition;
		CAM_FeatureDescTriggerOption	stTriggerOption;
		CAM_FeatureDescFormat			stFormatList[CAM_FEA_DESC_LIST_MAX];
	};
public:
	CAM_FeatureDesc() { uiFeatureId = -1; uiListCount = 0; eFeatureDescType = edesc_unknown; }
};
