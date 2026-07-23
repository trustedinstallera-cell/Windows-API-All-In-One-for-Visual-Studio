#if _MSC_VER > 1000
#pragma once
#endif   

#ifndef HAS_INCLUDED_WIN_CPP
#define HAS_INCLUDED_WIN_CPP

// Environment definitions

#ifdef NOMINMAX
#undef NOMINMAX
#define _NOMINMAX
#endif

#ifdef NOEXCLUSIONMACROS
#undef NOGDI
#undef NONAMELESSUNION
#undef NOSERVICE
#endif

#if (defined NOGDI) || (defined NONAMELESSUNION) || (defined NOSERVICE)\
|| (defined WIN32_LEAN_AND_MEAN)
#error Fatal error: NOGDI, NONAMELESSUNION, NOSERVICE and WIN32_LEAN_AND_MEAN are not compatible with this header.
#error use NOEXCLUSIONMACROS to undef these macros.
#endif

// scsi.h requires _NTSCSI_USER_MODE_ only when compiling in pure user-mode.
// Do NOT define it if any kernel/driver mode macro is active.
#if (!defined _KERNEL_MODE) && (!defined _NTSRB_) && (!defined _NTSRB_) && (!defined _MINIPORT_) && (!defined _NTDDK_)
#ifndef _NTSCSI_USER_MODE_
#define _NTSCSI_USER_MODE_  1
#endif
#endif

#if __cplusplus >= 202603L || _MSVC_LANG >= 202603L
#define cppver 2026
#elif __cplusplus >= 202302L || _MSVC_LANG >= 202302L
#define cppver 2023
#elif __cplusplus >= 202002L || _MSVC_LANG >= 202002L
#define cppver 2020
#elif __cplusplus >= 201703L || _MSVC_LANG >= 201703L
#define cppver 2017
#elif __cplusplus >= 201402L || _MSVC_LANG >= 201402L
#define cppver 2014
#elif __cplusplus >= 201103L || _MSVC_LANG > 201103L
#define cppver 2011
#else
#define cppver 1998
#endif

#if (defined WIN7_SUPPORT) || (defined WINDOWS7_SUPPORT)
#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif
#define _WIN32_WINNT 0x0601
#endif

// Compiler version definitions
#ifdef _MSC_VER
#define VS_VERSION _MSC_VER
#else
#define VS_VERSION 700
#endif

#define VC_1     800
#define VC_2     900
#define VC_4     1000
#define VC_5     1100
#define VC_6     1200
#define VS_2002  1300
#define VS_2003  1310
#define VS_2005  1400
#define VS_2008  1500
#define VS_2010  1600
#define VS_2012  1700
#define VS_2013  1800
#define VS_2015  1900
#define VS_2017  1910
#define VS_2019  1920
#define VS_2022  1930
#define VS_2026  1950

#define VS_VER VS_VERSION
#define MSVC_VER VS_VERSION
#define MSVC_VERSION VS_VERSION

#if _MSC_VER >= 1950
#define TOOLSET 145  // VS 2026 and later
#elif _MSC_VER >= 1930
#define TOOLSET 143  // VS 2022
#elif _MSC_VER >= 1920
#define TOOLSET 142  // VS 2019
#elif _MSC_VER >= 1910
#define TOOLSET 141  // VS 2017
#elif _MSC_VER >= 1900
#define TOOLSET 140  // VS 2015
#elif _MSC_VER >= 1800
#define TOOLSET 120  // VS 2013
#elif _MSC_VER >= 1700
#define TOOLSET 110  // VS 2012
#elif _MSC_VER >= 1600
#define TOOLSET 100  // VS 2010
#elif _MSC_VER >= 1500
#define TOOLSET 90   // VS 2008
#elif _MSC_VER >= 1400
#define TOOLSET 80   // VS 2005
#elif _MSC_VER >= 1310
#define TOOLSET 71   // VS 2003
#elif _MSC_VER >= 1300
#define TOOLSET 70   // VS 2002
#elif _MSC_VER >= 1200
#define TOOLSET 60   // VC++ 6.0
#elif _MSC_VER >= 1100
#define TOOLSET 50   // VC++ 5.0
#elif _MSC_VER >= 1000
#define TOOLSET 40   // VC++ 4.0
#elif _MSC_VER >= 900
#define TOOLSET 20   // VC++ 2.0
#elif _MSC_VER >= 800
#define TOOLSET 10   // VC++ 1.0
#else
#define TOOLSET 10   // Fallback for unknown/older
#endif

#ifdef NOWARNINGS
#if VS_VER == VC_6
// #pragma push_macro : '_MP' is not currently defined as a macro
#pragma warning(disable: 4601)
#endif
#if MSVC_VER == VS_2003
#pragma warning(disable: 4267) // ChString.h: from size_t to int
#endif
#if MSVC_VER <= VS_2003
// Calling _set_se_translator() requires /EHa. 
//The _set_se_translator function requires the /EHa compiler option, not /EHs or /EHsc.
#pragma warning(disable: 4535)
#endif
#if MSVC_VER == VS_2005
#pragma warning(disable: 4819)
#endif
#if MSVC_VER >= VS_2005
#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _SILENCE_ALL_CXX20_DEPRECATION_WARNINGS
#define _SILENCE_ALL_CXX23_DEPRECATION_WARNINGS
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING
#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING // VS 2022
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#define _CRT_NONSTDC_NO_WARNINGS		  // POSIX function names
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#define _SCL_SECURE_NO_WARNINGS // potentially unsafe methods
#define _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_STDIO_ISO_WIDE_SPECIFIERS 0
#define _AFX_SECURE_NO_WARNINGS // Suppresses compiler warnings for the use of deprecated MFC functions.
#define _CRT_OBSOLETE_NO_WARNINGS   // MFC or ATL code
#define SUPPRESS_LEGACY_ICU_HEADER_WARNINGS // The wchar_t versions of the ICU headers are no longer being updated...
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#define _SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS
#define _SILENCE_IO_PFX_SFX_DEPRECATION_WARNING
#define _SILENCE_LOCALE_EMPTY_DEPRECATION_WARNING
#define _SILENCE_NONFLOATING_COMPLEX_DEPRECATION_WARNING
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#define _SILENCE_TR1_RANDOM_DEPRECATION_WARNING
#define _SILENCE_AMP_DEPRECATION_WARNINGS
#define _SILENCE_CLR_PURE_DEPRECATION_WARNING
#define _SILENCE_LIFETIMEBOUND_WARNING
#define _SILENCE_NODISCARD_LOCK_WARNINGS
#define _ALLOW_KEYWORD_MACROS
#if MSVC_VER > VS_2013
#pragma warning(disable: 5040) // Cannot recognize in VS 2013
#endif
#if (MSVC_VER == VS_2013) || (MSVC_VER == VS_2012) || (MSVC_VER == VS_2010)
#pragma warning(disable: 4068) // Unknown pargma
#endif
#pragma warning(disable: 4995)
#pragma warning(disable: 4477)
#pragma warning(disable: 4091)
#pragma warning(disable: 4290)
#pragma warning(disable: 4005)
#pragma warning(disable: 4038)
#pragma warning(disable: 4324)
#pragma warning(disable: 4201)
#pragma warning(disable: 4458)
#pragma warning(push)
#endif
#endif
// todo The macros the header uses

#if ((defined(_WIN32_WINNT) && _WIN32_WINNT == 0x0603) || (defined(NTDDI_VERSION) && NTDDI_VERSION == 0x06030000)) && (defined(_MSC_VER) && _MSC_VER >= 1951) // VS 2026, SDK 8.1
#error Cannot use this SDK 8.1 on VS 2026
#include <con/unexist.hppx>
#endif

#include <tchar.h>
// todo test the next line
//#include "WinSock2.h"
#if (defined _USING_V110_SDK71_ /*XP support*/) || (MSVC_VER <= 2015)
typedef struct IUnknown IUnknown;
#endif
#if (defined SE_WIN_ENCLAVE)
#include "winenclave.h"
#else
#include <Windows.h>
#endif
#if VS_VER > VC_4
#include <Wininet.h>
#endif
#if VS_VER > VC_5
#include <shlwapi.h>
#endif
#if VS_VERSION > VC_2
#include <Shlobj.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if MSVC_VER > 2015
#include <ShlObj_core.h>
#endif
#if VS_VER > VS_2010
#include <dcompanimation.h> // for IDirectCompositionAnimation interface"
#include <dcomptypes.h>     // for CompositionSurfaceType"
#endif
#endif
#if TOOLSET > 90
#include <wincodec.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <wrl.h>
#include <wrl\client.h>
#include <wrl\def.h>
#include <wrl\event.h>
#include <wrl\ftm.h>
#include <wrl\implements.h>
#include <wrl\internal.h>
//#include <wrl\internalasync.h>
//#include <wrl\internalevent.h>
#include <wrl\module.h>
#include <wrl\wrappers\corewrappers.h>
#endif
/*
// todo: check in XP system or toolset
#if defined(_USING_V110_SDK71_)
#include <wia_xp.h>
#else
#include <wiadef.h>
#include <wia_lh.h>
#endif*/
// wia.h has been included, but not determined in previous compilers
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <wiamindr_lh.h>
#endif
// todo: check in XP system or toolset
//#include <wiamindr_xp.h>
//#include <initguid.h>
#if VS_VER > VC_4
#include <wincrypt.h>
#endif
#if TOOLSET > 90
#include <wsdattachment.h>
#include <wsdbase.h>
#include <wsdxml.h>
#include <wsdclient.h>
#include <wsddisco.h>
#include <wsdhost.h>
#include <wsdns.h>
#include <wsdtypes.h>
#include <wsdutil.h>
//#include "AudioClient.h"
#include "BdaTypes.h"
#endif
#if VS_VER >= VS_2015
#pragma warning(push)
#pragma warning(disable : 4596)
#include "Gdiplus.h"
#include "GdiplusFlat.h"
#include "GdiplusBase.h"
#include "GdiplusGpStubs.h"
#include "GdiplusHeaders.h"
#include "GdiplusGraphics.h"
#include "GdiplusTypes.h"
#include "GdiplusBitmap.h"
#include "GdiplusBrush.h"
#include "GdiplusCachedBitmap.h"
#include "GdiplusColor.h"
#include "GdiplusColorMatrix.h"
#include "GdiplusEffects.h"
#include "GdiplusEnums.h"
#include "GdiplusFont.h"
#include "GdiplusFontCollection.h"
#include "GdiplusFontFamily.h"
#include "GdiplusImageAttributes.h"
#include "GdiplusImageCodec.h"
#include "GdiplusImaging.h"
#include "GdiplusInit.h"
#include "GdiplusLineCaps.h"
#include "GdiplusMem.h"
#include "GdiplusMetaHeader.h"
#include "GdiplusMetafile.h"
#include "GdiplusPath.h"
#include "GdiplusPen.h"
#include "GdiplusPixelFormats.h"
#include "GdiplusRegion.h"
#include "GdiplusStringFormat.h"
#pragma warning(pop)
#endif
#if VS_VER > VC_5
#include "activeds.h"
#include "filter.h"
#endif
#if VS_VER > VC_4
#include "hlink.h"
#endif
#include "Ole2Ver.h"
//#include "dvbsiparser.h" // redefinition of tagAnalogVideoStandard and tagTunerInputType
#if VS_CER > VC_6
#include <WbemCli.h>
#include "WmiUtils.h"
#include <WbemProv.h>
#endif
//#include "kxarm64unw.h"
//#include <instance.h>
//#include <MethodCo.h>
#if VS_VER > VC_5
#include "mstask.h"
#endif
#if VS_CER > VC_6
#include "msxml2did.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#define __MIDL_itf_msxml6_0000_0000_v0_0_c_ifspec
#include "msxml6.h"
#endif
#if VS_VER > VC_5
#include "msxmldid.h"
#endif
#if TOOLSET > 90
#include "nserror.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ntverp.ver"
#endif
#if VS_VERSION > VC_2
#include "oledlg.h"
#endif
//#include "opcbase.idl"
//#include "opcdigitalsignature.idl"
//#include "opcobjectmodel.idl"
//#include "opcparturi.idl"
//#include <pix_xbox.h>
#if TOOLSET > 90
#include "portabledeviceapi.h"
#endif
#if VS_CER > VC_6
#include "propidl.h"
#endif
//#include "propidlbase.idl"
#if TOOLSET > 90
#include "propkeydef.h"
#endif
#if VS_CER > VC_6
#include "shobjidl.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "shobjidl_core.h"
#endif
//#include "srchntfyinlinesite.idl"
//#include "srchprth.idl"
#if VS_VER > VS_2005
#include "tapi3ds.h"	 // included ddraw, but No such file or directory
#include "tapi3if.h"
#endif
#if VS_VER > VS_2005 // no such header at all
#include "textstor.h"
#endif
#if VS_VER > VC_5
#include "transact.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "transportsettingcommon.h"
#endif
#if VS_VER > VC_5
#include "txcoord.h"
#include "txdtc.h"
#endif
//#include "uconfig_local.h"
#if VS_VER > VC_4
#include "AclAPI.h"
#endif
//#include "ActivityCoordinator.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "AppxPackaging.h"
#endif
#if VS_VER > VS_2005
#include "AtscPsipParser.h"
#include "AudioEngineEndpoint.h"
#endif
#if VS_CER > VC_6
#include "BiDiSpl.h"
#include "CDOSys.h"
#endif
//#include "CDOSys_I.c"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "CameraUIControl.h"
#if MSVC_VER > 2015
#include "CastingInterop.h"
#endif
#if MSVC_VER > 2012
#include "DefaultBrowserSyncSettings.h"
#endif
#endif

#if (TOOLSET > 90)
#include "DeleteBrowsingHistory.h"
//#include "DeleteBrowsingHistory.idl"
#include "DeviceCategories.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "DirectML.h"
#endif
#if (TOOLSET > 90)
#include "DocObjectService.h"
#include "DownloadMgr.h"
#endif
#if VS_VER > VC_5
#include "DskQuota.h"
#endif
#if VS_VER > VS_2005
#include "DvbSiParser.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "EditionUpgradeHelper.h"
#endif
#if VS_CER > VC_6
#include "EmptyVC.h"
#include "EventSys.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "ExtensionValidation.h"
#endif
#ifdef NOWARNINGS
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "FhCfg.h"
#endif
#endif
#if VS_CER > VC_6
#include "GPEdit.h"
#endif
//#include "GameInput.h" // try /clr option
#if VS_VER > VC_5
#include "IAccess.h"
#endif
#if VS_VER > VS_2005
#include "IChannelCredentials.h"
#include "IContact.h"
#include "IContactProperties.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "IContentPrefetcherTaskTrigger.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "IE12Plugin.h"
#endif
#endif
#if VS_CER > VC_6
#include <iedial.h>
#endif
#if VS_VER > VS_2005
#include "IEPMapi.h"
#endif
#if (TOOLSET > 90) && ((defined _UNICODE) || (defined UNICODE))
#include "IEProcess.h" 
#endif
//#include "IImgCtx.h"
//#include "IMessage.h" // none of <mapix.h>, <mapidefs.h> nor <mapitags.h> has been found
#if VS_VER > VS_2005
#include "ISysmon.h"
#endif
#if VS_CER > VC_6
#include "Iadmext.h"
#include "Iadmw.h"
#include "Iads.h"
#endif
#if TOOLSET > 90
#include "IdentityProvider.h"
#include "IdentityStore.h"
#endif
#if VS_VER > VC_5
#include "Ilogobj.Hxx"
#endif
//#include "ImageHlp.h"
#if VS_VER > VS_2005
#include "ImageTranscode.h"
#endif
#if VS_VER > VC_4
#include "Ime.h"
#endif
#if VS_VER > VC_5
#include "InetReg.h"
#endif
#if VS_VER > VC_4
#include "InetSDK.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "InkPresenterDesktop.h"
//#include "InkPresenterDesktop_i.c"
#endif
#if VS_VER > VS_2003
#include "InputScope.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "InteractionContext.h"
#endif
#if TOOLSET > 90
#include "ImgUtil.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "IsolatedAppLauncher.h"
#endif
#if VS_CER > VC_6
#include "Iwamreg.h"
#endif
#if VS_VER > VS_2005
#include "MDhcp.h"
#endif
#if VS_VER > VC_5
#include "MLang.h"
#endif
#if VS_VER > VS_2005
#include "MSAAText.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "MemoryBuffer.h"
#endif
#if VS_VER > VC_5
#include "MimeInfo.h"
#endif
#if VS_CER > VC_6
#include "Mobsync.h"
#endif
#if TOOLSET > 90
#include "MpegType.h"
#endif
#if VS_VER > VC_5
#include "Mprapi.h"
#include "Mq.h"
#include "MsHtmHst.h"
#endif
#if VS_VER > VS_2005
#include "Msp.h"
#endif
#if VS_CER > VC_6
#include "ObjSel.h"
#endif
#if TOOLSET > 90
#include "PNPXAssoc.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "PerceptionDevice.h"
#endif
#if VS_VER > VS_2005
#include "PhotoAcquire.h"
#endif
//#include "PortableDeviceConnectApi.h"
//#include "PortableDeviceConnectImports.idl"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "Presentation.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "PrintPreview.h"
//#include "PrinterExtension.idl"
#if MSVC_VER > 2012
#include "ProofOfPossessionCookieInfo.h"
#endif
//#include "Query.h"
#include "RadioMgr.h"
#endif
#if VS_VERSION > VC_2
#include "Reconcil.h"
#endif
#if VS_CER > VC_6
#include "RrasCfg.h"
#endif
#if VS_VER > VS_2005
#include "RTSCOM.h"
#include "SearchAPI.h"
#endif
//#include "SearchApi.idl"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "ShellHandwriting.h"
#endif
//#include "SpatialAudioHrtf.h"
#if VS_CER > VC_6
#include "Sti.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "StorageProvider.h"
#endif
#if VS_VER > VC_5
#include "SubsMgr.h"
#endif
#if VS_VER > VS_2005
#include "SyncMgr.h"
#endif
#if VS_CER > VC_6
#include "TOM.h"
#endif
#if TOOLSET > 90
#include "TSGAuthenticationEngine.h"
#include "TSGPolicyEngine.h"
#endif
#if VS_VER > VS_2005
#include "Tapi3cc.h"
#endif
//#include "TextServ.h"
#if VS_VER > VS_2005
#include "TipAutoComplete.h"
#endif
#if TOOLSET > 90
#include "UIAnimation.h"
//#include "UIAnimation.idl"
#include "UIRibbon.h"
//#include "UIRibbon.idl"
#include "UIRibbonPropertyHelpers.h"
#endif
#if VS_VER > VS_2005
//#include "UPnP.Idl"
#include "UPnP.h"
#endif
#if VS_VER > VC_5
#include "UrlHist.h"
#endif
#if VS_CER > VC_6
#include "UserEnv.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "WRdsGraphicsChannels.h"
#if VS_VER > VS_2015
#include "WaaSApi.h"
#endif
#endif
#if VS_VER > VS_2005
#include "WdsClientApi.h"
#endif
#if TOOLSET > 90
#include "WebEvnts.h"
#include "WebServices.h"
#endif
#if VS_VER > VS_2005
#include "WerApi.h"
#endif
#if VS_CER > VC_6
#include "WiaDevD.h"
#include "WiaVideo.h"
#endif
#if TOOLSET > 90
#include "WinBio.h"
#endif
#if VS_CER > VC_6
#include "WinDNS.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "WinHvPlatform.h"
#include "Windows.Graphics.Capture.Interop.h"
#include "Windows.Devices.Display.Core.Interop.h"
#endif
#if VS_VER > VS_2005
#include "WindowsSideShowAPI.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "WindowsStorageCOM.h"
#endif
#include "Winineti.h"
#endif
#if VS_VER > VC_5
#include "Winldap.h"
#endif
#if VS_VER > VS_2005
#include "Wscapi.h"
#endif
#if VS_CER > VC_6
#include "WtsApi32.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "XblIdpAuthManager.h"
#endif
#if TOOLSET > 90
#include "activaut.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "activdbg100.h"
#endif
#if VS_VER > VS_2005
#include "adhoc.h"
#include "alg.h"
#endif
#if VS_VER > VC_4
#include <wincrypt.h>
#endif
#if VS_VER > VC_6
#include "sqloledb.h"
#endif
#if TOOLSET > 90
#include "txfw32.h"
#endif
#if VS_VER > VC_5
#if VS_VER == VC_6
// following definitions come from C:\Program Files (x86)\Windows Kits\10\Include\10.0.28000.0\um\wincrypt.h

//+-------------------------------------------------------------------------
//  CRYPTOAPI BLOB definitions
//--------------------------------------------------------------------------
// certenrolls_begin -- *_BLOB
#ifndef CRYPTO_BLOBS_DEFINED
#define CRYPTO_BLOBS_DEFINED
typedef struct _CRYPTOAPI_BLOB {
	DWORD   cbData;
	/*_Field_size_bytes_(cbData)*/  BYTE* pbData; // no sal.h for Source-code Annotation Language
} CRYPT_INTEGER_BLOB, * PCRYPT_INTEGER_BLOB,
CRYPT_UINT_BLOB, * PCRYPT_UINT_BLOB,
CRYPT_OBJID_BLOB, * PCRYPT_OBJID_BLOB,
CERT_NAME_BLOB, * PCERT_NAME_BLOB,
CERT_RDN_VALUE_BLOB, * PCERT_RDN_VALUE_BLOB,
CERT_BLOB, * PCERT_BLOB,
CRL_BLOB, * PCRL_BLOB,
DATA_BLOB, * PDATA_BLOB,
CRYPT_DATA_BLOB, * PCRYPT_DATA_BLOB,
CRYPT_HASH_BLOB, * PCRYPT_HASH_BLOB,
CRYPT_DIGEST_BLOB, * PCRYPT_DIGEST_BLOB,
CRYPT_DER_BLOB, * PCRYPT_DER_BLOB,
CRYPT_ATTR_BLOB, * PCRYPT_ATTR_BLOB;
#endif
// certenrolls_end
// basetsd.h
#if !defined _W64
#define _W64
#endif
typedef _W64 unsigned long ULONG_PTR, * PULONG_PTR;
typedef ULONG_PTR HCRYPTPROV;
// wincrypt.h
typedef struct _CRYPT_ALGORITHM_IDENTIFIER {
	LPSTR               pszObjId;
	CRYPT_OBJID_BLOB    Parameters;
} CRYPT_ALGORITHM_IDENTIFIER, * PCRYPT_ALGORITHM_IDENTIFIER;
typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE {
	LPSTR               pszObjId;
	CRYPT_OBJID_BLOB    Value;
} CRYPT_ATTRIBUTE_TYPE_VALUE, * PCRYPT_ATTRIBUTE_TYPE_VALUE;
#endif
#include "mssip.h"
#endif
/*
//#if cppver >= 2017
//#if 1
// todo mix in #if statement
// todo define has_winrt
#if defined INCLUDE_WINRT && \
defined _SILENCE_EXPERIMENTAL_COROUTINE_DEPRECATION_WARNINGS
// it will take about 40 secounds if include these files
//#if 0
#include "winrt/Windows.AI.Actions.h"
#include "winrt/Windows.AI.MachineLearning.h"
#include "winrt/Windows.ApplicationModel.Appointments.h"
#include "winrt/Windows.ApplicationModel.Calls.h"
#include "winrt/Windows.ApplicationModel.DataTransfer.DragDrop.h"
#include "winrt/Windows.ApplicationModel.DataTransfer.h"
#include "winrt/Windows.ApplicationModel.Email.h"
#include "winrt/Windows.ApplicationModel.ExtendedExecution.h"
#include "winrt/Windows.ApplicationModel.Payments.h"
#include "winrt/Windows.ApplicationModel.Preview.h"
#include "winrt/Windows.ApplicationModel.Resources.h"
#include "winrt/Windows.ApplicationModel.Search.h"
#include "winrt/Windows.ApplicationModel.SocialInfo.h"
#include "winrt/Windows.ApplicationModel.Store.Preview.h"
#include "winrt/Windows.ApplicationModel.Store.h"
#include "winrt/Windows.ApplicationModel.UserActivities.h"
#include "winrt/Windows.ApplicationModel.UserDataAccounts.h"
#include "winrt/Windows.ApplicationModel.UserDataTasks.h"
#include "winrt/Windows.ApplicationModel.Wallet.h"
#include "winrt/Windows.ApplicationModel.h"
#include "winrt/Windows.Devices.Adc.h"
#include "winrt/Windows.Devices.Bluetooth.h"
#include "winrt/Windows.Devices.Display.h"
#include "winrt/Windows.Devices.Enumeration.h"
#include "winrt/Windows.Devices.Geolocation.h"
#include "winrt/Windows.Devices.Gpio.h"
#include "winrt/Windows.Devices.I2c.h"
#include "winrt/Windows.Devices.Input.h"
#include "winrt/Windows.Devices.Lights.h"
#include "winrt/Windows.Devices.Perception.h"
#include "winrt/Windows.Devices.PointOfService.h"
#include "winrt/Windows.Devices.Printers.h"
#include "winrt/Windows.Devices.Pwm.h"
#include "winrt/Windows.Devices.Sensors.h"
#include "winrt/Windows.Devices.Spi.h"
#include "winrt/Windows.Devices.WiFiDirect.h"
#include "winrt/Windows.Devices.h"
#include "winrt/Windows.Foundation.h"
#include "winrt/Windows.Gaming.Input.h"
#include "winrt/Windows.Globalization.h"
#include "winrt/Windows.Graphics.DirectX.h"
#include "winrt/Windows.Graphics.Display.h"
#include "winrt/Windows.Graphics.Printing.h"
#include "winrt/Windows.Graphics.h"
#include "winrt/Windows.Management.Deployment.h"
#include "winrt/Windows.Management.h"
#include "winrt/Windows.Media.Capture.h"
#include "winrt/Windows.Media.Core.h"
#include "winrt/Windows.Media.Devices.h"
#include "winrt/Windows.Media.Protection.h"
#include "winrt/Windows.Media.h"
#include "winrt/Windows.Networking.h"
#include "winrt/Windows.Perception.Spatial.h"
#include "winrt/Windows.Perception.h"
#include "winrt/Windows.Security.Authentication.Identity.h"
#include "winrt/Windows.Security.Authentication.Web.h"
#include "winrt/Windows.Security.Credentials.h"
#include "winrt/Windows.Security.Cryptography.h"
#include "winrt/Windows.Services.Maps.h"
#include "winrt/Windows.Storage.Pickers.h"
#include "winrt/Windows.Storage.h"
#include "winrt/Windows.System.Diagnostics.h"
#include "winrt/Windows.System.Power.h"
#include "winrt/Windows.System.Profile.h"
#include "winrt/Windows.System.RemoteDesktop.h"
#include "winrt/Windows.System.Threading.h"
#include "winrt/Windows.System.h"
#include "winrt/Windows.UI.Composition.h"
#include "winrt/Windows.UI.Core.h"
#include "winrt/Windows.UI.Input.Inking.h"
#include "winrt/Windows.UI.Input.Preview.h"
#include "winrt/Windows.UI.Input.h"
#include "winrt/Windows.UI.Notifications.h"
#include "winrt/Windows.UI.Shell.h"
#include "winrt/Windows.UI.Text.h"
#include "winrt/Windows.UI.UIAutomation.h"
#include "winrt/Windows.UI.ViewManagement.h"
#include "winrt/Windows.UI.WebUI.h"
#include "winrt/Windows.UI.WindowManagement.h"
#include "winrt/Windows.UI.Xaml.Automation.h"
#include "winrt/Windows.UI.Xaml.Controls.h"
#include "winrt/Windows.UI.Xaml.Media.h"
#include "winrt/Windows.UI.Xaml.h"
#include "winrt/Windows.UI.h"
#include "winrt/Windows.Web.Http.h"
#include "winrt/Windows.Web.UI.h"
#include "winrt/Windows.Web.h"
#include "winrt/base.h"
#endif
*/ // comment for too large to compile
//#include "MqOaI.h"
#if VS_VER > VC_6
#include "NetCon.h"
#endif
#if VS_VER > VS_2005
#include "NetSh.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "NotificationActivationCallback.h"
#endif      
#if VS_VER > VC_1
#include <basetyps.h> 
#endif
#if cppver > 2017
#include <ATLBASE.h>
#include <ATLCONV.H>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <ActivityCoordinatorTypes.h>
#endif
#if ((defined WINVER) && (WINVER >= 0x0602)) || (( defined _WIN32_WINNT && _WIN32_WINNT >= 0x0602)) \
	&& (defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8))
// Windows Vista and Windows 8 SDK
#include <AudioEngineBaseAPO.h>
#include <BthLEDef.h>

#include <CHPtrArr.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400) // above VS2005
#include <propkey.h>
#endif
#if VS_VER > VC_6
#include <CHString.h>
#include <CHStrArr.h> 
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <ComputeDefs.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <D2D1EffectAuthor.h>
#endif
#if TOOLSET > 90
#include <D2DBaseTypes.h>
#include <D2DErr.h>
#include <DWrite.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <DWrite_1.h>
#if (defined WIN7_SUPPORT) || (defined WINDOWS7_SUPPORT)
#include <DWrite_2.h>
#endif
#include <DirectXMath.h>
#endif
// #include <DeviceServices.h>  // discarded because included bridgedeviceservice.h
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <EapTypes.h>
#include <FunctionDiscoveryKeys_devpkey.h>
#include <GL/gl.h>
#endif
#if VS_VER > VC_6
#include <GenLex.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <IMessageDispatcher.h>
#include <IVectorChangedEventArgs.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "Inspectable.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <InputEventFlags.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <Inspectable.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "MFMediaEngine.h"
#include "MFSharingEngine.h"
#endif
#if VS_VER > VS_2005
#include "MFTransform.h"
#endif
#if VS_VER > VC_5
#if (!(defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL == 0))
#include "Mshtml.h"
#endif
#endif
#if VS_VER > VC_6
#include <OPathLex.h>
#include <ObjPath.h>
#include <Objsafe.h>
#endif
// Do not include this because you are popping a compiler stack
#if 0 
#include <POPPACK.H>
#include <PSHPACK1.H>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <PerceptionDeviceCore.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <PhotoAcquireProperties.h>
#include <PhysicalMonitorEnumerationAPI.h>
#endif
#if VS_VER > VC_6
#include <Polarity.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <PropKeyDef.h>
#endif
#if VS_VER > VC_6
#include <ProvExce.h>
#endif
#if VS_VER > VS_2005
#include "RecDefs.h"
#include "RecTypes.h"
#endif
#if VS_VER > VC_5
#include "SCardErr.h"
#endif
#ifdef __midl // MIDL compiler, Microsoft Interface Definition Language, generate C/C++ code for COM/DCOM components
// todo: move all *.idl files and begin test
#include "SearchAdmin.idl"
#include "SearchCatalog.idl"
#include "SearchCrawlScopeManager.idl"
#include "SearchLanguageSupport.idl"
#include "SearchNotifications.idl"
#include "SearchQuery.idl"
#endif
#if TOOLSET > 90
#include "SessdirPublicTypes.h"
#endif
#if VS_VER > VS_2005
#include "StructuredQuery.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "TpmVscAttestation.h"
//#include "VMRender.idl"
#endif
#include "VSStyle.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "VmSavedStateDumpDefs.h"
#include "WaaSAPITypes.h"
#endif
#if VS_VER > VS_2005
#include "Wincodec.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <SCSISCAN.H>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <SPError.h>
#endif
//#ifdef  _CRT_SECURE_NO_WARNINGS 
#if 0
#include <SPHelper.h>
#endif
#if _MSC_VER > 1500
#include <SensorsApi.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <SensorsStructures.h>
#endif
#include <Shellapi.h>
#if VS_VER > VS_2003
#include <SpecStrings.h>
#endif
#if VS_VER > VS_2005
#include <TPCError.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <TraceLoggingActivity.h>
#include <TraceLoggingProvider.h>
#endif
#if _MSC_VER > 1500
#include <UIAutomationClient.h>
#include <UIAutomationCore.h>
#include <UIAutomationCoreApi.h>
#include <UIRibbonKeyDef.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <VFWMSGS.H>
#endif
#if VS_VER > VC_6
#include <WbemTime.h>
#endif
#if _MSC_VER > 1500
#include <WcnDevice.h>
#include <WcnTypes.h>
#endif                   
#if VS_VER > VC_1
#include <WinDef.h> 
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <WinHvPlatformDefs.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <WinString.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <Windows.Media.Protection.PlayReadyResults.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <Windows.Media.Streaming.h>
#include <Windows.System.h>
#include <Windows.UI.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <Windows.graphics.h>
#include <Windows.ui.composition.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <WlanIhvTypes.h>
#include <WlanTypes.h>
#include <WpcApi.h>
#include <WpcEvent.h>
// #include <_dbdao.h> // internal implements
#endif
#if VS_VER > VC_4
#include <accctrl.h>
#endif
#if VS_VER > VC_6
#include <aclui.h> 
#endif
#if VS_VER > VC_4
#include "activscp.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <activation.h>
#include <activationregistration.h>
#endif
#if _MSC_VER > 1500
#include <activdbg.h>
#include <activprof.h>
#endif
#if VS_VER > VC_6
#include "adodef.h"
#endif
//#include "adoint_backcompat.h"
#if VS_VER > VC_5
#include "adsdb.h"
// #include <adogpool.h> // Cannot be used directly
#include "adserr.h"
#include "adshlp.h"
#include "adsiid.h"
#include "adsnms.h"
#include "adssts.h"
#endif
#if VS_VER > VS_2005
#include "asferr.h"
#endif
#if TOOLSET > 90
#include "audioapotypes.h"
#endif
// #include "axcore.idl"
#if VS_VER > VC_6
#include "DSAdmin.h"
#endif
#if VS_VER > VS_2005
#include "DSAttrib.h"
#endif
#if VS_VER > VC_6
#include "DSClient.h"
#include "DSQuery.h"
#include "DSRole.h"
#include "DbgHelp.h"
#endif
//#include "DbgModel.h"
#if VS_VER > VC_6
#include <adtgen.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ahadmin.h>
#endif
#if VS_VER > VC_4
#include <algorithm>
#endif
#ifdef DXSDK_DIR // Microsoft DirectX SDK required
#include <amaudio.h>
#endif
#if VS_VER > VS_2005
#include "amparse.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "amsi.h"
#endif
#include "amstream.h"
#include "amva.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <amvideo.h> 
#endif
#if TOOLSET > 90
#include "amxmlgraphbuilder.h"
#endif
//#include "anchorsyncdeviceservice.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if MSVC_VER > 2012
#include "animationcoordinator.h"
#endif
#include "apdevpkey.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <apiquery2.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <apiset.h>
#include <apisetcconv.h>
#include <appmodel.h>
#endif
#if MSVC_VER > 2012
#include "appcompatapi.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "appnotify.h"
#if VS_VER > VS_2015
#include "appserviceinterop.h"
#endif
#endif
//#include "async.h"
#include "assert.h"
//#include "asynot.idl"
//#include "asysta.idl"
#if VS_VER > VS_2005
#include "atacct.h"
#endif
#if VS_VER > VC_5
#include <ks.h>
#endif
/*
#include <ksmedia.h>
#include <bdamedia.h>
#include "atsmedia.h"
*/
#if defined (_M_ARM64) || defined(_M_HYBRID_X86_ARM64) || defined(_M_ARM64EC)
#include <arm64_neon.h>
#include <arm_neon.h>
#endif
#if IS_ARM
#include <arm64_neon.h>
#include <arm_neon.h>
#endif
#if cppver >= 2011
#include <array>
#endif
#include <assert.h>
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <asyncinfo.h>
#include <atomic>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <audevcod.h>   // audio filter device error event codes"
#include <audiosessiontypes.h> // For AUDIO_STREAM_CATEGORY"
#include <austream.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "audioclientactivationparams.h"
//#include "audioengineextensionapo.h"
//#include "audiopolicy.h"
#include "audiostatemonitorapi.h"
#endif
#if VS_VER > VS_2005
#include "austream.h"
#endif
#if TOOLSET > 90
#include "aux_ulib.h"
#endif
#if VS_VER > VC_6
#include <authz.h>
#endif
#if VS_VER > VS_2005
#include "aviriff.h"
#include "avrfsdk.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <avrt.h>
//#include <axextendenums.h>
#endif
#if VS_VER > VS_2003
#include "azroles.h"
#endif
//#include "base.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <dvp.h>
#include "baseaudioprocessingobject.h"
#endif
#if VS_VER > VC_5
#include <basetsd.h>
#endif                
#if VS_VER > VC_1
#include "basetyps.h"
#endif
//#include "batclass.h"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <bcrypt.h>
#include <bthdef.h>
#endif
//#include "bdaiface.idl"
#if VS_VER > VC_6
#include <ksmedia.h>
#endif
#if VS_VER > VS_2005
#include "bdamedia.h"
#include "bdatif.h"
#include "bdatypes.h"
#endif
//#include "binres.idl"
#if VS_VER > VC_6
#include "bits.h"
#endif
#if VS_VER > VS_2005
#include "bits3_0.h"
#endif
#if VS_VER > VS_2002
#include "bitscfg.h"
#endif
#if VS_VER > VC_6
#include "bitsmsg.h"
#endif
#if VS_VER > VS_2005
#include "bluetoothapis.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "bluetoothleapis.h"
#endif
#if VS_VER > VS_2005
#include "bthdef.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "bthioctl.h"
#include "bthledef.h"
#endif
//#include "calendardeviceservice.h"
#if VS_VER > VS_2002
#include "callobj.h"
#endif
#if TOOLSET > 90
#include "capi.h"
#endif
#if VS_VER > VS_2005
#include "casetup.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "ccgplugins.h"
#endif
#if MSVC_VER > 2012
#include "cchannel.h"
#endif
#if cppver >= 2011
#if defined _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING || defined _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <ccomplex>
#endif
#endif
#include <cderr.h>
#if VS_VER > VC_6
#include "cdosysstr.h"
#include "celib.h"
#endif
#ifdef printf
#undef printf
#endif
//#include "certbcli.idl"
#if VS_VER > VS_2003
#include "certreqd.h"
#include "certbase.h"
#endif
#if VS_VER > VC_5
#include <certadm.h>
#endif
#if VS_VER > VC_6
#include <certbcli.h>
#endif
#if VS_VER > VC_5
#include <certcli.h>
#include <certenc.h>
#include <certexit.h>
#include <certif.h>
#endif
#if VS_VER > VC_6
#include <certmod.h>
#endif
#if VS_VER > VC_5
#include <certpol.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include <wldp.h>
#endif
#if VS_VER > VC_6
#include <schannel.h>
#endif
#if VS_VER > VS_2002
#include <winternl.h> // define _UNICODE_STRING
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <ntlsa.h>
#endif
#if TOOLSET > 90
#include <LsaLookup.h>
#endif
#ifdef _USING_V110_SDK71_
typedef enum _SECURITY_LOGON_TYPE {
	UndefinedLogonType = 0, // This is used to specify an undefied logon type
	Interactive = 2,      // Interactively logged on (locally or remotely)
	Network,              // Accessing system via network
	Batch,                // Started via a batch queue
	Service,              // Service started by service controller
	Proxy,                // Proxy logon
	Unlock,               // Unlock workstation
	NetworkCleartext,     // Network logon with cleartext credentials
	NewCredentials,       // Clone caller, new default credentials
	//The types below only exist in Windows XP and greater
#if (_WIN32_WINNT >= 0x0501)
	RemoteInteractive,  // Remote, yet interactive. Terminal server
	CachedInteractive,  // Try cached credentials without hitting the net.
	// The types below only exist in Windows Server 2003 and greater
#endif
#if (_WIN32_WINNT >= 0x0502)
	CachedRemoteInteractive, // Same as RemoteInteractive, this is used internally for auditing purpose
	CachedUnlock        // Cached Unlock workstation
#endif
} SECURITY_LOGON_TYPE, * PSECURITY_LOGON_TYPE;
#include <ntsecpkg.h>
#include "CertPolEng.h"
#endif
#if VS_VER > VC_5
#include "CertSrv.h"
#endif
#if VS_VER > VC_6
#include <certview.h>
#endif
#if VS_VER > VC_5
#include "Certif.h"
#endif
#if VS_VER > VS_2003
#include <cfg.h>
#include <cfgmgr32.h>
#endif          
#if VS_VER > VC_1
#include <cguid.h>
#endif
//#include "chakrart.h"
#if cppver >= 2017
#include <charconv>
#endif
//#include "checksum.h"
//#include "chprst.idl"
#if VS_VER > VS_2005
#include "clfs.h"
//#include "clfslsn.h"
#include "clfsmgmt.h"
#include "clfsmgmtw32.h"
#include "clfsw32.h"
#endif
//#include "client.h"
//#include "clinf2.idl"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "cloneviewhelper.h"
#endif
#if VS_VER > VC_5
#include "clusapi.h"
#endif
//#include "cmdbas.idl"
//#include "cmdcst.idl"
//#include "cmdpre.idl"
//#include "cmdprp.idl"
//#include "cmdprst.idl"
//#include "cmdstrm.idl"
//#include "cmdtre.idl"
#if VS_VER > VC_6
#include "cmdtree.h"
#endif
/*#include "cmdtree.idl"
#include "cmdtxt.idl"
#include "cmdval.idl"
#include "cmdwpr.idl"*/
#if VS_VER > VC_6
#include "CmnQuery.h"
#endif
#if VS_VER > VS_2005
#include "codecapi.h"
#endif
//#include "coguid.h"
//#include "Color.Dlg" // This is a dialog file
// #include "colinf.idl"
//#include "colrst.idl"
//#include "ComAdmin.Idl"
#if VS_VER > VC_6
#include "comadmin.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "combaseapi.h"
#if VS_VER > VS_2015
#include "coml2api.h"
#endif
#endif
#if VS_VER > VS_2005
#include "comlite.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "commapi.h"
#endif
//#include "commctrl.inl"
#include "commdlg.h"
//#include "commdlg.inl"
#if VS_VER > VC_6
#include "commoncontrols.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "compressapi.h"
#include "compstui.h"
#if VS_VER > VS_2015
#include "computecore.h"
#include "computenetwork.h"
#include "computestorage.h"
#endif
#endif
#if VS_VER > VC_6
#include "comsvcs.h"
#endif
#include "conio.h"
#ifdef USE_EDGEMODE_JSRT
#include <jsrt.h>
#include <chakrart.h>
#endif
#if VS_VER > VC_6
#include <chptrarr.h>
#endif
#if cppver >= 2011
#include <chrono>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "CimFs.h"
#endif
#if VS_VER > VC_5
#include "CluAdmEx.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <clfs.h>
#include <clfsmgmt.h>
#include <clfsw32.h>
#include <clusapi.h>
//#include <clfslsn.h>
#endif
#if VS_VER > VC_4
#include <cmath>
#endif
#if NTDDI_VERSION >= 0x06000000	 // Windows Vista
#include <Ks.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <codecapi.h>
#include <colordlg.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <combaseapi.h>
#include <assert.h>
#endif
#if VS_VER > VC_4
#include <comcat.h>
#include <comdef.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <coml2api.h>
#endif
#if VS_VER > VC_1
#include <commctrl.h>    
#endif
#if VS_VER > VC_5
#include <commctrl.rh>
#endif
#include <commdlg.h>
#if cppver > 2017
#include <compare>
#endif
#if defined _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING || defined _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#if cppver >= 2011
#include <complex.h>
#endif
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "CompPkgSup.h"
#endif
//#ifdef _CRT_SECURE_NO_DEPRECATE // not determined
#if 0
#include "ContactAggregation.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <compstui.h>
#include <concurrencysal.h>
#include <consoleapi.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <consoleapi2.h>
#include <consoleapi3.h>
#endif
//#include "contactdeviceservice.h"
#if VS_VER > VS_2005
#include "contentpartner.h"
#endif
#if VS_VER > VC_5
#include <control.h>
#endif
#if NTDDI_VERSION > 0x0A000C00 // v143
#include <cor.h>
#endif
#if cppver >= 2017
#include <corecrt.h>
#include <corecrt_io.h>
#include <corecrt_malloc.h>
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <corecrt_math.h>
#include <corecrt_math_defines.h>
#endif
#include <corecrt_memcpy_s.h>
#include <corecrt_memory.h>
#include <corecrt_search.h>
#include <corecrt_share.h>
#include <corecrt_startup.h>
#include <corecrt_stdio_config.h>
#include "corecrt_terminate.h"
#include <corecrt_wconio.h>
#include <corecrt_wctype.h>
#include <corecrt_wdirect.h>
#include <corecrt_wio.h>
#include <corecrt_wprocess.h>
#include <corecrt_wstdio.h>
#include <corecrt_wstdlib.h>
#include <corecrt_wstring.h>
#include <corecrt_wtime.h>
#endif
//#include "corewrappers.h"
#if TOOLSET > 90
#include "corrEngine.h"
#endif
#if NTDDI_VERSION > 0x0A000C00 // v143
#include <corhdr.h>
#endif
#if cppver > 2017
#include <coroutine>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "CoreWindow.h"
#endif
//#include "cper.h"
//#include "cperguid.h"
#include "Cpl.h"
#if VS_VERSION > VC_2
#include <crtdbg.h>
#endif
#if VS_VER > VS_2005
#include "credentialprovider.h"
#include "credssp.h"
#endif
//#include "crtrow.idl"
#if VS_VER > VS_2005
#include "cryptdlg.h"
#endif
#if VS_VER > VS_2003
#include <crtdefs.h>
#endif
#if VS_VERSION > VC_2
#include "Cplext.h"
#endif
#if VS_VER > VC_6
#include "cryptuiapi.h"
#endif
#if TOOLSET > 90
#include "cryptxml.h"
#include "cscapi.h"
#include "cscobj.h"
#include "cscsearchapiif.hxx"
#endif
#if VS_VER > VC_4
#include <cstddef>
#endif
#if cppver >= 2011
#include <cstdint>
#endif
#if VS_VER > VC_4
#include <cstring>
#endif
//#include "ctffunc.h"
#if MSVC_VER > 2012
#if defined _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING || defined _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <ctgmath>
#endif
#endif
#if VS_VER > VS_2005
#include "ctfspui.h"
#endif
#if VS_VER > VS_2002
#include "ctxtcall.h"
#endif
#include <ctype.h>
#include "CustCntl.h"
//#include "cvttyp.idl"
#if _MSC_VER > 1500
#include <d2d1.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <d2d1effectauthor.h>
#include <d2d1effects.h>
#if MSVC_VER > 2012
#include <d2d1effects_1.h>
#endif
#if MSVC_VER > VS_2015
#include <d2d1effects_2.h>
#endif
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <d2d1_1.h>
#include <d2d1_1helper.h>
#if (defined WIN7_SUPPORT) || (defined WINDOWS7_SUPPORT)
#include <d2d1_2.h>
#include <d2d1_2helper.h>
#endif
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <d2d1_3.h>
#include <d2d1_3helper.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <d2d1effects.h>
#if (defined WIN7_SUPPORT) || (defined WINDOWS7_SUPPORT)
#include <d2d1effects_1.h>
#endif
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <d2d1effects_2.h>
#endif
#if _MSC_VER > 1500
#include <d2d1helper.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <d2d1svg.h>
#endif
#if TOOLSET > 90
#include <d2dbasetypes.h>
#include "D2DErr.h"
#endif
#if _MSC_VER > 1500
#include <d3d10_1.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <d3d9.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if VS_VER > VS_2015
#include "d3d11_4.h"
#endif
#include "d3d11shadertracing.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "d3d12compatibility.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "d3d12video.h"
#endif
#if VS_VER > VS_2005
#include "d3d9helper.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "d3d9on12.h"
#endif
//#include <d3dcaps.h>
#if _MSC_VER > 1500
#include <d3dcommon.h>
#endif
//#include "d3dcompiler.inl"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "d3dcsx.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <d3dhal.h>
#endif
#include "d3dhalex.h"
//#include <d3dkmdt.h> // Should not be included directly
#if VS_VER > VS_2015
#include "d3dkmthk.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <d3dnthal.h>
#include <d3dtypes.h>
#endif
#include <d3d.h> 
#include <d3dcaps.h>
#if VS_VER > VS_2015
#include "d3dkmthk.h"
#endif
//#include <d3dukmdt.h> // Should not be included directly
#endif
#if NTDDI_VERSION == 0x0A000010 // 10.0.26100.0
#include "d3dshadercacheregistration.h"
#endif
#if VS_VERSION > VC_2
#include <daogetrw.h>
#endif
//#include "databuffer.h"
//#include "databuffertypes.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <datetimeapi.h>  // Datetime APISET dependencies"
#endif
#if TOOLSET > 90
#include "davclnt.h"
#endif
//#include <d3dukmdt.h> // Should not be included directly
//#include "dbccmd.idl"
//#include "dbcses.idl"
#if _MFC_VER >= 0x0420
#include "dbdao.h"
#endif
#if VS_VERSION > VC_2
#include "dbdaoerr.h"
#include <dbdaoid.h>
#include <dbdaoint.h>
#endif
/*#include "dbdsad.idl"
#include "dbinfo.idl"
#include "dbinit.idl"*/
#if VS_VER > VS_2005
#include "dbnetlib.h"
#endif
/*#include "dbprop.idl"
#include "dbrtpr.idl"
#include "dbscmd.idl"
#include "dbseci.idl"
#include "dbsrst.idl"*/
#if VS_VER > VS_2003
#include "dciman.h"
#endif
#if _MSC_VER > 1500
#include <dcommon.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "dcomp.h"
#endif
#if VS_VERSION > VC_2
#include <unknwn.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <dcomptypes.h>     // for CompositionSurfaceType"
#endif
#include <dde.h>
#if VS_VER > VC_5
#include <dde.rh>
#endif       
#if VS_VER == VC_1    
DECLARE_HANDLE(HSZ);
#endif
#include <ddeml.h>
//#include "ddkmapi.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ddpbackup.h"
#if VS_VER > VS_2015
#include "ddpchunk.h"
#include "ddpdataport.h"
#endif
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ddraw.h>
#endif
/*#include <dx95type.h>
#include "ddrawgdi.h"*/
//#include <ddrawi.h>
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <ddrawint.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ddstream.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <debugapi.h>
#endif
#if VS_VER > VC_6
#include "dbgprop.h"
#endif
/*#include "dbs.idl"
#include "dbsdep.idl"
#include "devenum.idl"*/
#if VS_VERSION > VC_2
#include "Dbt.h"
#endif
//#include "def.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "deliveryoptimization.h"
#endif
#if VS_VER > VS_2002
#include "devguid.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <devfiltertypes.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "deviceaccess.h"
#endif
//#include "deviceservices.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <devioctl.h>
#endif
//#include <devpkey.h>
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <devpropdef.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <devquerydef.h>
#include <diagnosticdataquerytypes.h>
#endif
#if VS_VER > VC_6
#include "DhcpCSdk.h"
#endif
#if VS_VER > VS_2003
#include "dhcpsapi.h"
#endif
#if VS_VER > VC_6
#include "DhcpSSdk.h"
#include "dimm.h"
#endif
#if VS_VER > VS_2005
#include "Dhcpv6cSdk.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "DiagnosticDataQuery.h"
#include "DiagnosticDataQueryTypes.h"
#endif                
#if VS_VER > VC_1
#include "Digitalv.h"
#endif
#if TOOLSET > 90
#include "dinput.h"
#include "dinputd.h"
#endif
//#include "direct.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "directmanipulation.h"
#include "DirectXCollision.h"
#include "DirectXColors.h"
#endif
//#include "DirectXPackedVector.h"
#if VS_VER > VC_6
#include <diskguid.h>
#endif
#if VS_VER > VC_5
#include "dispex.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "DispatcherQueue.h"
#endif
//#include <dlfcn.h>
#include <dlgs.h>
#if VS_VER > VC_4
#include "docobj.h"
#endif
#if TOOLSET > 90
#include "dls2.h"
#endif
//#include "dpa_dsa.inl"
//#include "dmksctrl.h"
#if VS_VER > VS_2005
#include "dmo.h"
#include "dmodshow.h"
#include "dmoimpl.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "dmprocessxmlfiltered.h"
#endif
#if TOOLSET > 90
#include "dmusics.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "dontuse.h"
#endif
#include "dos.h"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <dot1x.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <dpa_dsa.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <dpapi.h>
#endif
#if VS_VER > VS_2005
#include "dpx.h"
#include <dpx1.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "dragdropinterop.h"
#endif
#if _MSC_VER > 1500
#include <driverspecs.h>
//#include <dsound.h>	
#endif
#if TOOLSET > 90
#include "dsconf.h"
#endif
//#include "drt.h"
#if VS_VER > VC_6
#include "DsGetDC.h"
#endif
//#include "dshow.h"
#if VS_VER > VS_2005
#include "dshowasf.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "dsparse.h"
#endif
#if VS_VER > VS_2005
#include "dssec.h"
#endif
#if VS_VER > VC_5
#include "DtcHelp.h"
#endif
#if VS_VER > VS_2005
#include "dv.h"
#include "dvdevcod.h"
#include "dvdmedia.h"
#include "dwmapi.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "dxcapi.h"
#include "dxcore.h"
#include "dxdiag.h"
#include "dxgiddi.h"
#include "dxgidebug.h"
//#include "dxmini.h"
#endif
#if ((MSVC_VER != VS_2013) || (defined NOWARNINGS)) && (VS_VER > VS_2003) 
#include "dxtmpl.h"
#endif
#if VS_VER > VS_2005
#include "dxva.h"
#include <dxva2api.h>
#include "dxva2swdev.h"
#include "eapauthenticatortypes.h"
#include "EapHostError.h"
#include "eaphostpeerconfigapis.h"
#include "EapHostPeerTypes.h"
#include <eapmethodtypes.h>
#include "eapmethodauthenticatorapis.h"
#include "eapmethodpeerapis.h"
#include "eappapis.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "easencryptprov.h"
#include "easregprov.h"
#endif
#if VS_VER > VS_2005
#include "edevdefs.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "edpwin32.h"
#endif
#if VS_VER > VS_2005
#include "eaptypes.h"
#include "effects.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "efswrtinterop.h"
#endif
#if TOOLSET > 90
#include "ehstorapi.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ehstorbandmgmt.h"
#endif
#include "ehstorextensions.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ehstorioctl.h"
#endif
#include "ElsCore.h"
#include "ElsSrvc.h"
#include "encdec_enums.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
//#include "encdec.idl"
#if VS_VER > VS_2015
#include "enclaveapi.h"
#endif
#include "errhandlingapi.h"
#endif
//#include "errlup.idl"
#include "errno.h"
#if VS_VER > VS_2005
#include "errors.h"
//#include "errrec.idl"
#include "esent.h"
#include "evalcom2.h"
#include "evcode.h"
#include "EvColl.h"
#endif
#if VS_VER > VC_4
#include "ExDisp.h"
#include "ExDispid.h"
#endif
//#include "ExDisp.Idl"
//#include "event.h"
//#include "evntcons.h"
#if VS_VER > VS_2005
#include "evntprov.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "evntrace.h"
#endif
#include "evr9.h"
#endif
//#include "exemptionaction.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "expandedresources.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400) // undetermined value
#include "FaxComEx.h"
//#include "FaxComEx_i.c"
//#include "FaxDev.h"
#else
#if VS_VER > VS_2005
#include "FaxCom.h"
#endif
//#include "FaxCom_i.c"
#endif
#if VS_VER > VS_2005
#include "FaxMmc.h"
#include "FaxRoute.h"
#endif
#if VS_VER > VC_6
#include "fci.h"
#endif
#include "fcntl.h"
#if VS_VER > VC_6
#include "fdi.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "fdi_fci_types.h"
#include "featurestagingapi.h"
#endif
#if MSVC_VER > 2012
#include "fenv.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "FhStatus.h"
#include "FhSvcCtl.h"
#include "fileapi.h"
#if VS_VER > VS_2015
#include "fileapifromapp.h"
#endif
#include "fibersapi.h"
#endif
#if VS_VER > VC_6
#include "FileHC.h"
#endif
//#include "FileOpen.Dlg"
#if VS_VER > VC_5
#include "Filter.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "filterpipeline.h"
#include "filterpipelineutil.h"
#endif
#if VS_VER > VC_6
#include "fltdefs.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "fltUser.h"
#include "fltUserStructures.h"
#endif
#if VS_VER > VS_2005
#include "fontsub.h"
#endif                      
#if VS_VER > VC_1
#include "fpieee.h"
#endif
// todo retest
#if 0
#if VS_VER > VC_6
#include "FrQuery.h"
#endif
#endif
#if TOOLSET > 90
#include "fsrmtlb.h"
//#include "ftm.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "fttypes.h"
#endif
#include "ftpext.h"
#endif
#if TOOLSET > 90
//#include "fullenumsyncdeviceservice.h"
// #include "functiondiscovery.h"
#include "functiondiscoveryapi.h"
//#include "functiondiscoveryapi.idl"
#include "functiondiscoverycategories.h"
#include "functiondiscoveryconstraints.h"
#include "functiondiscoveryerror.h"
#include "functiondiscoverykeys.h"
#include "functiondiscoverykeys_devpkey.h" // all of the texts are definitions and now has redefinition
#include "functiondiscoverynotification.h"
#include "functiondiscoveryprovider.h"
#include "functiondiscoveryproviderhelper.h"
#include "functiondiscoveryserviceids.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "fwpmu.h"
//#include "fwpsu.h"
#endif
#if VS_VER > VS_2005
#include "fxsutility.h"
#include "gameux.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "gamingdeviceinformation.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "gamingexperience.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "gamingtcui.h"
#endif
#if VS_VER > VS_2002
#include "gb18030.h"
#endif
//#include "GL.h"
//#include "GLU.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "gnssdriver.h"
#include "gpio.h"
#endif
#if VS_VER > VS_2003
#include "gpmgmt.h"
#endif
//#include "gso.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "handleapi.h"
//#include "hashtypes.h"
//#include "hbaapi.h"
#include "hidsdi.h"
#endif
#if VS_VER > VS_2005
#include "highlevelmonitorconfigurationapi.h"
#endif
//#include "hintsdeviceservice.h"
#if VS_VER > VC_4
#include "HLink.h"
#endif
#if VS_VER > VC_5
#include "HlGuids.h"
#endif
#if VS_VER > VC_4
#include "HlIface.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if VS_VER > VS_2015
#include "HolographicSpaceInterop.h"
#endif
#if MSVC_VER > 2012
#include "homepagesetting.h"
#endif
#include <xapo.h>
#if VS_VER > VS_2015
#include "hrtfapoapi.h"
#endif
#endif
#if VS_VER > VS_2003
#include "htiface.h"
#endif
#if VS_VER > VC_6
#include "HtmlHelp.h"
#endif
//#include "http.h"
/*#include <httpserv.h>
#include "httpcach.h"*/
#if TOOLSET > 90
#include "httpcompression.h"
#endif
//#include "httprequest.idl"
#if VS_VER > VC_4
#include "HttpExt.h"
#endif
//#include "httpserv.h"
#if VS_VER > VS_2005
#include "httptrace.h"
//#include "hvsocket.h"
#include "hwebcore.h"
#endif
#if VS_VER > VC_4
#include "HttpFilt.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "hwreqchkapi.h"
#endif
#if VS_VER > VS_2005
#include "hxhelppaneproxy.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "hypervdevicevirtualization.h"
#endif
#if VS_VER > VS_2003
#include "i_cryptasn1tls.h"
#endif
//#include "icodecapi.h"
#if VS_VER > VC_5
#include "icrsint.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "icu.h"
#include "icui18n.h"
#endif
#if VS_VER > VS_2005
#include "icwcfg.h"
#endif
#if VS_VER > VC_6
#include "IDLMULTI.H"
#endif
#if VS_VER > VC_4
#include "IDispIds.h"
#endif
//#include "ieautomation.h"
//#include "ieautomation.idl"
//#include "ieee8021q.h"
//#include "iewebdriver.h"
#if VS_VER > VS_2005
#include "iextag.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <dsparse.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <dvdevcod.h>   // DVD error event codes"
#endif
//#include <dxgi.h>
//#include <dxgi1_5.h>    // for DXGI_ALPHA_MODE, DXGI_HDR_METADATA_TYPE"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <dxgiformat.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <dxgitype.h>   // for DXGI_RATIONAL"
#include <edevdefs.h>  
#endif             
#if VS_VER > VC_1
#include <eh.h>  
#endif
#if VS_VER > VC_6
#include <emmintrin.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <encdec_enums.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <enclaveapi.h>
#include <enclaveium.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <errhandlingapi.h>
#endif
#include <errno.h>
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <errors.h>     // HRESULT status and error definitions"if
#include <evcode.h>     // event code definitions"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <eventtoken.h>  // used for EventRegistrationToken"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <evntcons.h>
#include <evntprov.h>
#include <evntrace.h>
#endif
#if VS_VER > VC_4
#include <exception>
#endif               
#if VS_VER > VC_1
#include <excpt.h> 
#endif
//#include <exdisp.h>
//#include <experimental/coroutine>
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <exposeenums2managed.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <fdi_fci_types.h>
#endif
//#include <features.h>
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <fibersapi.h>
#include <fileapi.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <fileapifromapp.h>
#endif
#include <float.h>       // float bounds"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <fltUserStructures.h>
#endif
#if cppver > 2017
#include <format>
#endif
#if VS_VER > VC_6
#include <guiddef.h>    // REVIEW: or just redefine GUID here"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <handleapi.h>
#include <heapapi.h>
#include <hstring.h>
#endif
//#include <http.h>
#if VS_VER > VC_4
#include <idispids.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ifdef.h>
#include <ifmib.h>
#endif
#if VS_VER > VS_2002
#include "iiisext.h"
#endif
//#include "iketypes.idl"
#if VS_VER > VS_2005
#include "il21dec.h"
//#include "iisext_i.c"
#include "iisrsta.h"
#endif
#if VS_VER > VC_5
#include "IIScnfg.h"
#endif
#if VS_VER > VS_2005
#include "imapi.h"
//#include "imapi2.idl"
#include "imapi2fs.h"
#include "imapierror.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <ime_cmodes.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "imepad.h"
#endif
#if VS_VERSION > VC_2
#include <imm.h>
#endif
//#include "immdev.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <immintrin.h>
#endif
//#include "implements.h"
//#include "inddef.idl"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <in6addr.h>
#include <inaddr.h>
#endif
#if VS_VER > VS_2002
#include "indexsrv.h"
#endif
//#include "infocard.h"
//#include "infotech.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "infstr.h"
#endif
#include <initguid.h>   
#if VS_VER > VS_2005
#include "inked.h"
#endif
//#include "inked_i.c"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if VS_VER > VS_2015
#include "inkrenderer.h"
//#include "inkrenderer_i.c"
#include "inputpaneinterop.h"
#endif
#include "inputpanelconfiguration.h"
//#include "inputpanelconfiguration_i.c"
#include <inspectable.h>
#endif
#if VS_VER > VS_2002
#include <indexsrv.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <interlockedapi.h>
#endif
#if VS_VER > VS_2005
#include "intsafe.h"
#endif
#if MSVC_VER > 2012
//#include "internal.h"
#include "inttypes.h"
#endif
#if VS_VER > VS_2003
#include <intrin.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#pragma warning(push)
#pragma warning(disable: 4005)
#include <intsafe.h>
#pragma warning(pop)
#endif
#include "io.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <ioapiset.h>
#include <ipexport.h>
#include "Icm.h"
#include "IcmpAPI.h"
#endif
//#include "ioctltypes.h"
#if VS_VER > VC_6
#include "ioevent.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "ioringapi.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ip2string.h"
#endif
#if VS_VER > VC_6
#include "iphlpapi.h"
#endif
#if VS_VER > VC_5
#include <ipifcons.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ipmib.h>
#endif
#if VS_VER > VC_5
#include <iprtrmib.h>
#endif
#if VS_VER > VC_6
#pragma warning(push)
#pragma warning(disable: 4005)
#include <iptypes.h>
#pragma warning(pop)
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <ipv6prefast.h>
#endif
#if VS_VER > VC_5
#include <ipxconst.h>
#include <ipxrip.h>
#include <ipxsap.h>
#include <ipxtfflt.h>
#endif
//#include "iscsidsc.h"
#if VS_VER > VC_4 // IsGuids.h(13) : error C2374: 'IID_IUniformResourceLocator' : redefinition; multiple initialization
#if VS_VER <= VC_6
// redefinition errors in VC++ 6 and below
#ifndef CLSID_InternetShortcut
#define CLSID_InternetShortcut
#ifdef UNICODE
#define IID_IUniformResourceLocator     IID_IUniformResourceLocatorW
#else
#define IID_IUniformResourceLocator     IID_IUniformResourceLocatorA
#endif
#endif
#endif
#include <isguids.h>            // internet shortcut GUIDs"
#endif
#if VS_VER > VC_5
#pragma warning(push)
#pragma warning(disable: 4005)
#include <issper16.h>
#pragma warning(push)
#endif
#if VS_VER > VC_4
#include <iterator>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <ivectorchangedeventargs.h>
//#include "ivectorchangedeventargs.idl"
#include "iwscapi.h"
#endif
#if VS_VER > VS_2005
#include "iwstdec.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <jobapi.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <jobapi2.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "jscript9diag.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <joystickapi.h>
#endif
#if MSVC_VER > 2012
#include "jscript9diag.h"
#include "jsrt.h"
#endif
#if VS_VER > VS_2015
#include "jsrt9.h"
#endif
#pragma push_macro("X10")
#pragma push_macro("X19")
#pragma push_macro("X20")
#pragma push_macro("X21")
#pragma push_macro("X22")
#pragma push_macro("X24")
#pragma push_macro("X30")
#undef X10
#undef X19
#undef X20
#undef X21
#undef X22
#undef X24
#undef X30
#include "kbd.h"
#pragma pop_macro("X10")
#pragma pop_macro("X19")
#pragma pop_macro("X20")
#pragma pop_macro("X21")
#pragma pop_macro("X22")
#pragma pop_macro("X24")
#pragma pop_macro("X30")
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <kernelspecs.h>
#endif
#if VS_VER > VS_2015
#include "keycredmgr.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <knownfolders.h>
#endif
#if VS_VER > VS_2015
#include "knownfolderpathscom.h"
#endif
#endif
#if IS_ARM64 // todo not determined
#include "ksarm64.h"
#endif
#if VS_VER > VC_5
#include <ks.h>
#endif
#if VS_VER > VC_6
#include "ksguid.h"
#endif
#if TOOLSET > 90
#include "ksopmapi.h"
#endif
#if VS_VER > VC_6
#include "ksproxy.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ktmtypes.h>
#include <l2cmn.h>
#endif
#if VS_VER > VS_2005
#include "ktmw32.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "lamp.h"
#if (NTDDI_VERSION >= 0x0A000010 /* 10.0.26100.0 */) && (cppver >= 2017)
#include "lamparray.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <libloaderapi.h> // LibLoader Apiset dependencies"
#endif
#if VS_VER > VS_2015
#include "libloaderapi2.h"
#endif
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "LicenseProtection.h"
#endif
#include <limits.h>
#if VS_VER > VC_4
#include <limits>
#endif
#if VS_VER > VS_2005
#include "listeneradapter.h"
#endif                           
#if VS_VER > VC_1
#include "LM.h"
#include <lmaccess.h>   // Access, Domain, Group and User classes"
#include <lmalert.h>    // Alerter"
#include <lmapibuf.h>   // NetApiBuffer class"
#include "LMat.h"
#include <lmaudit.h>    // NetAudit class"
#include <lmconfig.h>   // NetConfig class"
#include <lmcons.h>     // LAN Manager common definitions"
#include <lmerr.h>      // LAN Manager network error definitions"
#include <lmerrlog.h>   // NetErrorLog class"    
#endif
#if VS_VER > VC_6
#include <lmjoin.h>     // NetJoinDomain class"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "lmon.h"
#endif          
#if VS_VER > VC_1
#include <lmmsg.h>      // Message class"
#include <lmremutl.h>   // Remote Utility class"     
#include <lmrepl.h>     // Replicator class"
#include <lmserver.h>   // Server class"
#include <lmshare.h>    // Connection, File, Session and Share classes"
#include <lmsname.h>
#include <lmstats.h>    // NetStats class"
#include <lmsvc.h>      // Service class"
#include <lmuse.h>      // Use class"
#include <lmuseflg.h>                   // Deletion force level flags"
#include <lmwksta.h>    // Workstation class"       
#endif
#if VS_VER > VC_4
#include "LoadPerf.h"
#endif
#include "locale.h"
#if TOOLSET > 90
#include "locationapi.h"
#endif
//#include "locking.h"
//#include "logicaladdress.h"
#if VS_VER > VS_2005
#include "lowlevelmonitorconfigurationapi.h"
#endif
#if VS_VER > VC_6
#include "LpmApi.h"
#endif
#if VS_VER > VC_5
#include "Ipinfoid.h"
#endif
#if TOOLSET > 90
#include "LsaLookup.h"
#endif
#if VS_VER > VC_5
#include "Iprtrmib.h"
#include "IpxConst.h"
#include "Ipxrip.h"
#endif
//#include "Ipxrtdef.h"
#if VS_VER > VC_5
#include "Ipxtfflt.h"
#endif
#if VS_VERSION > VC_2
#include "IsGuids.h"
#endif
#if VS_VER > VC_5
#include "IssPer16.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <lsalookup.h>
#endif
#include <lzexpand.h>
#if VS_VER <= VS_2005 && VS_VER > VC_1
// this definition is copied from https://learn.microsoft.com/en-us/windows/win32/api/ntdef/ns-ntdef-_unicode_string directly.
// struct _MCAST_SCOPE_ENTRY used this definition as UNICODE_STRING  ScopeDesc; , which is not recognized.
// and ntdef.h is not included in Visual Studio 2005
// Visual Studio 2003 detected having this issue
// No USHORT definitions in Visual C++ 1
typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PWSTR  Buffer;
} UNICODE_STRING, * PUNICODE_STRING;
#endif
#if VS_VER > VC_6
#include "madcapcl.h"
#endif
#if VS_VER > VS_2005
#include "magnification.h"
#endif
#if VS_VER > VC_6
#include "MailMsgProps.h"
#endif
#if TOOLSET > 90
//#include "manipulations_i.c"
#endif
#include <malloc.h>             // calloc()"
#if VS_VER > VC_4
#include <map>
#endif
#ifdef FLAGS
#ifdef _MSC_VER
#pragma push_macro("FLAGS")
#undef FLAGS
#elif defined(__GNUC__) || defined(__clang__)
#pragma GCC push_macro("FLAGS")
#undef FLAGS
#endif
#define FLAGS_UNDEFINED
#undef FLAGS
#endif
#if VS_VERSION > VC_2
#include "MAPI.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "MapiUnicodeHelp.h"
#endif
#ifdef FLAGS_UNDEFINED
#pragma pop_macro("FLAGS")
#undef FLAGS_UNDEFINED
#endif
#include <math.h>           // For log10()"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "Math3DHelper.h"
#endif
#if TOOLSET > 90
#include "mbnapi.h"
#endif
#if VS_VER > VC_5 // VC++ 5 cannot recoginze push_macro but no such error in this compiler
#pragma push_macro("_MP")
#undef _MP
#endif       
#if VS_VER > VC_1
#include "mbctype.h"
#endif
#if VS_VER > VC_5
#pragma pop_macro("_MP")
#endif          
#if VS_VER > VC_1
#include <mbstring.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <mciapi.h>
#endif
//#include "mddset.idl"
//#include "mdfind.idl"
#if VS_VERSION > VC_2
#include <mcx.h>
#endif
#if VS_VER > VC_5
#include <mdcommsg.h>
#include "Mddefw.h"
#endif
//#include "mdl.h"
#if VS_VER > VC_5
#include <mdmsg.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "mdmlocalmanagement.h"
#include "MDMRegistration.h"
#endif
#if VS_VER > VS_2005
#include "medparam.h"
#endif
#include <memory.h>
#if VS_VER > VC_4
#include <memory>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <memoryapi.h>
#endif
#if VS_VER > VC_6
#include "mergemod.h"
#endif
//#include "mdrrst.idl"
//#include "messagedeviceservice.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "MessageDispatcherApi.h"
#endif
//#include "metadatadeviceservice.h"
#if VS_VER > VS_2005
#include "mfapi.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "mfcaptureengine.h"
#if VS_VER > VS_2015
#include "mfcontentdecryptionmodule.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "mfd3d12.h"
#endif
#include "mfmediacapture.h"
#endif
#if TOOLSET > 90
#include "mfmp2dlna.h"
#include "mfplay.h"
#include "mfreadwrite.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "mfsharingengine.h"
#if VS_VER > VS_2015
#include "mfspatialaudio.h"
#endif
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "mfvirtualcamera.h"
#endif
#if VS_VER > VC_6
#include "Mgm.h"
#endif      
#if VS_VER > VC_1
#include "MgmtAPI.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "mi.h"
#endif
#if TOOLSET > 90
#include "micaut.h"
//#include "micaut_i.c"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "microsoft.diagnostics.appanalysis.h"
#endif
//#include "microsoft.diagnostics.appanalysis.idl"
#if VS_VERSION > VC_2
#include "Midles.h"
#endif
//#include "mileffects.h"
//#include "mimeole.idl"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <minappmodel.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "mindumpdef.h"
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <minidumpapiset.h>
#endif
//#include "minidrv.h"
#include "minidumpapiset.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <minschannel.h>
#include <minwinbase.h>
#include <minwindef.h>
#include <mmeapi.h>
#include <mmiscapi.h>
#include <mmiscapi2.h>
#endif
#if VS_VER > VC_4
#ifndef NOMINMAX
#include "minmax.h"
#endif
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "minwindef.h"
#endif
#if VS_VER > VS_2005
#include "mixerocx.h"
#endif
//#include "mmddk.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "mmeapi.h"
#include "mmiscapi.h"
#include "mmiscapi2.h"
#endif   
#if VS_VER > VC_1
#include <mmreg.h>
#endif 
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <mmstream.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <mmsyscom.h> // mm common definitions"
#endif
#include <mmsystem.h>
//#include "module.h"
#if VS_VER > VS_2005
#include "Mpeg2Error.h"
//#include "Mpeg2Structs.idl"
#include "mpconfig.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "mprapidef.h"
#endif
#if VS_VER > VC_5
#include <mprapi.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8) && ((defined WIN7_SUPPORT) || (defined WINDOWS7_SUPPORT))
#include <mprapidef.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "MrmResourceIndexer.h"
#endif
#if VS_VER > VS_2005
#include "MsCtfMonitorApi.h"
#endif             
#if VS_VER > VC_1
#include <msacm.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "msacmdrv.h"
#endif           
#if VS_VER > VC_1
#include "MSAcmDlg.h"
#endif
#if VS_VER > VC_6
// todo recheck
//#include "msado15.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
// todo recheck
//#include "msado15_Backcompat.h"
#if MSVC_VER > 2012
#include "msapofxproxy.h"
#endif
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <mscat.h>
#endif            
#if VS_VER > VC_1
#if TOOLSET <= 90  // VS2005 also has this issue
#define CYPHER_BLOCK_LENGTH 8
typedef struct _CYPHER_BLOCK {
	CHAR data[CYPHER_BLOCK_LENGTH];
} CYPHER_BLOCK;

typedef struct _LM_OWF_PASSWORD {
	CYPHER_BLOCK data[2];
} LM_OWF_PASSWORD;
typedef LM_OWF_PASSWORD* PLM_OWF_PASSWORD;
typedef LM_OWF_PASSWORD NT_OWF_PASSWORD;
typedef NT_OWF_PASSWORD* PNT_OWF_PASSWORD;

typedef struct _SAMPR_ENCRYPTED_USER_PASSWORD {
	UCHAR Buffer[(256 * 2) + 4];
} SAMPR_ENCRYPTED_USER_PASSWORD, * PSAMPR_ENCRYPTED_USER_PASSWORD;

typedef struct _ENCRYPTED_LM_OWF_PASSWORD {
	CYPHER_BLOCK data[2];
} ENCRYPTED_LM_OWF_PASSWORD, * PENCRYPTED_LM_OWF_PASSWORD;
typedef ENCRYPTED_LM_OWF_PASSWORD ENCRYPTED_NT_OWF_PASSWORD;
typedef ENCRYPTED_NT_OWF_PASSWORD* PENCRYPTED_NT_OWF_PASSWORD;
// define _NTCRYPT_ to skip blocks with issues
#define _NTCRYPT_
#endif                           
#endif
#if VS_VER > VC_6
#include <mschapp.h>
#endif
//#include "MSClus.Idl"
#if VS_VER > VC_5
#include "MSClus.h"
#endif
#if VS_VER == VC_6
#include <oledb.h>
#endif
#if VS_VER > VC_5
#include "msdadc.h"
#include "msdaguid.h"
#include "msdaora.h"
#include "msdaosp.h"
#include "msdasc.h"
#include "msdasql.h"
#endif
#if VS_VER > VS_2005
#include "msdelta.h"
#include "msdrmerror.h"
#include "msdrmgetinfo.h"
#endif
//#include "MsHTML.Idl"
#if VS_VER > VC_6
#include "msdshape.h"
#endif
#if VS_VER > VS_2005
#include "msfeeds.h"
#endif
//#include "msfeeds.idl"
#if VS_VER > VC_5
#include "MsHTML.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "mshtmldiagnostics.h"
#endif
#if TOOLSET > 90
#include "msiehost.h"
#endif
#if VS_VER > VS_2005
#include "msiltcfg.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "msime.h"
#include "msimeapi.h"
#endif
#if VS_VER > VS_2005
#include "msinkaut15.h"
#endif
//#include "msinkaut15_i.c"
//#include "msinkaut_i.c"
//#include "msoav.h"
//#include "msopc.idl"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "msports.h"
#endif
#if VS_VER > VS_2005
#include "msrdc.h"
#endif
//#include "msrdc.idl"
#if VS_VERSION > VC_2
#include "MSPST.h"
#endif
#if VS_VER > VC_5
#include "MSTErr.h"
#include "MSTask.h"
#include <mshtmcid.h>
#include <mshtmdid.h>
#endif
#if VS_VER > VC_6
#include "msremote.h"
#endif
#if VS_VER > VC_5
#include "mssip.h"
#endif
#if VS_VER > VC_4
#include "msstkppg.h"
#endif
#if VS_VER > VC_6
#include "mstcpip.h"
#endif
//#include "msvidctl.h"
//#include "msvidctl.idl"
#if VS_VER > VS_2005
#include "mswsockdef.h"
#endif
//#include "MsXml.Idl"
//#include "MsXml2.Idl"
#if VS_VER > VC_6
#include "MsXml2.h"
#include "MsXml2DId.h"
#include <mstcpip.h>
#endif
//#include "MSWSock.h"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <mswsockdef.h>
#endif
//#include "MsXml6.Idl"
#if VS_VER > VS_2005
#include "MsXml6.h"
#endif
#if VS_VER > VC_5
#include "MsXmlDId.h"
#endif
#if VS_VER > VC_6
#include "Mshtmlc.h"
#endif
#if VS_VER > VC_5
#include "Msi.h"
#endif
#if VS_VER > VC_6
#include "MsiDefs.h"
#endif
#if VS_VER > VC_5
#include "MsiQuery.h"
#include <msxml.h>
#endif
//#include "MspAddr.h"
//#include "MspCall.h"
//#include "MspEnum.h"
//#include "MspStrm.h"
//#include "Mspcoll.h"
#if VS_VER > VS_2005
#include "mtpext.h"
#endif
#if VS_VER > VC_6
#include "Msplog.h"
#endif
//#include "Mspterm.h"
//#include "Mspthrd.h"
//#include "Msptrmac.h"
//#include "Msptrmar.h"
//#include "Msptrmvc.h"
//#include "Msputils.h"
#if VS_VER > VC_6
#include "MtsAdmin.h"
#endif
#if VS_VER > VC_5
#include "MtsEvents.h"
#include "MtsGrp.h"
#endif
#if VS_VER > VC_4
#include "Mtx.h"
#endif
#if VS_VER > VC_5
#include "MtxAdmin.h"
#endif
#if VS_VER > VC_4
#include "MtxAttr.h"
#endif
#if VS_VER > VC_5
#include "Mtxdm.h"
#include "MultiMon.h"
#include "NTMSAPI.h"
#include "NTMSMli.h"
#endif
#endif
#if VS_VER > VC_5
#if VS_VER == VC_6
// cannot find cmdtree
// ntquery.h(185) : error C2061: syntax error : identifier 'DBCOMMANDTREE'
typedef ULONG DBLENGTH; // from oledb.h
typedef WORD DBCOMMANDOP;
typedef DWORD DBCOMMANDREUSE;
typedef struct tagDBBYGUID
{
	/* [size_is] */ BYTE* pbInfo;
	DBLENGTH cbInfo;
	GUID guid;
} 	DBBYGUID;

#define GENERATE_METHOD_EXACT    ( 0 )
#define GENERATE_METHOD_PREFIX   ( 1 )
#define GENERATE_METHOD_INFLECT  ( 2 )
typedef struct tagDBCONTENT
{
	LPOLESTR pwszPhrase;
	DWORD dwGenerateMethod;
	LONG lWeight;
	LCID lcid;
} 	DBCONTENT;

#define SCOPE_FLAG_MASK      ( 0x000000ff )
#define SCOPE_FLAG_INCLUDE   ( 0x00000001 )
#define SCOPE_FLAG_DEEP      ( 0x00000002 )
#define SCOPE_TYPE_MASK      ( 0xffffff00 )
#define SCOPE_TYPE_WINPATH   ( 0x00000100 )
#define SCOPE_TYPE_VPATH     ( 0x00000200 )
typedef struct tagDBCONTENTSCOPE
{
	DWORD dwFlags;
	LPOLESTR* rgpwszTagName;
	LPOLESTR pwszElementValue;
} 	DBCONTENTSCOPE;

typedef struct tagDBCONTENTTABLE
{
	LPOLESTR pwszMachine;
	LPOLESTR pwszCatalog;
} 	DBCONTENTTABLE;

#define PROPID_QUERY_RANKVECTOR  ( 0x2 )
#define PROPID_QUERY_RANK        ( 0x3 )
#define PROPID_QUERY_HITCOUNT    ( 0x4 )
#define PROPID_QUERY_ALL         ( 0x6 )
#define PROPID_STG_CONTENTS      ( 0x13 )
#define VECTOR_RANK_MIN          ( 0 )
#define VECTOR_RANK_MAX          ( 1 )
#define VECTOR_RANK_INNER        ( 2 )
#define VECTOR_RANK_DICE         ( 3 )
#define VECTOR_RANK_JACCARD      ( 4 )
typedef struct tagDBCONTENTVECTOR
{
	LONG lWeight;
	DWORD dwRankingMethod;
} 	DBCONTENTVECTOR;

typedef struct tagDBGROUPINFO
{
	LCID lcid;
} 	DBGROUPINFO;

typedef struct tagDBPARAMETER
{
	LPOLESTR pwszName;
	ITypeInfo* pTypeInfo;
	DB_NUMERIC* pNum;
	DBLENGTH cbMaxLength;
	DBPARAMFLAGS dwFlags;
	DBTYPE wType;
} 	DBPARAMETER;

#define DBSETFUNC_NONE       0x0
#define DBSETFUNC_ALL        0x1
#define DBSETFUNC_DISTINCT   0x2
typedef struct tagDBSETFUNC
{
	DWORD dwSetQuantifier;
} 	DBSETFUNC;

typedef struct tagDBSORTINFO
{
	BOOL fDesc;
	LCID lcid;
} 	DBSORTINFO;

typedef struct tagDBTEXT
{
	LPOLESTR pwszText;
	ULONG ulErrorLocator;
	ULONG ulTokenLength;
	GUID guidDialect;
} 	DBTEXT;

typedef struct tagDBLIKE
{
	LONG lWeight;
	GUID guidDialect;
} 	DBLIKE;

#define PROXIMITY_UNIT_WORD           ( 0 )
#define PROXIMITY_UNIT_SENTENCE       ( 1 )
#define PROXIMITY_UNIT_PARAGRAPH      ( 2 )
#define PROXIMITY_UNIT_CHAPTER        ( 3 )
typedef struct tagDBCONTENTPROXIMITY
{
	DWORD dwProximityUnit;
	ULONG ulProximityDistance;
	LONG lWeight;
} 	DBCONTENTPROXIMITY;

typedef struct tagDBPROBABILISTIC
{
	LONG lWeight;
	float flK1;
	float flK2;
	float flK3;
	float flB;
} 	DBPROBABILISTIC;

typedef struct tagDBRELEVANTDOCUMENT
{
	LONG lWeight;
	VARIANT vDocument;
} 	DBRELEVANTDOCUMENT;

typedef struct tagDBCOMMANDTREE
{
	DBCOMMANDOP op;
	WORD wKind;
	struct tagDBCOMMANDTREE* pctFirstChild;
	struct tagDBCOMMANDTREE* pctNextSibling;
	/* [switch_is][switch_type] */ union
	{
		/* [case()] */ __int64 llValue;
		/* [case()] */ unsigned __int64 ullValue;
		/* [case()] */ BOOL fValue;
		/* [case()] */ unsigned char uchValue;
		/* [case()] */ signed char schValue;
		/* [case()] */ unsigned short usValue;
		/* [case()] */ short sValue;
		/* [case()] */ LPOLESTR pwszValue;
		/* [case()] */ LONG lValue;
		/* [case()] */ ULONG ulValue;
		/* [case()] */ float flValue;
		/* [case()] */ double dblValue;
		/* [case()] */ CY cyValue;
		/* [case()] */ DATE dateValue;
		/* [case()] */ DBDATE dbdateValue;
		/* [case()] */ DBTIME dbtimeValue;
		/* [case()] */ SCODE scodeValue;
		/* [case()] */ BSTR* pbstrValue;
		/* [case()] */ ICommand* pCommand;
		/* [case()] */ IDispatch* pDispatch;
		/* [case()] */ IMoniker* pMoniker;
		/* [case()] */ IRowset* pRowset;
		/* [case()] */ IUnknown* pUnknown;
		/* [case()] */ DBBYGUID* pdbbygdValue;
		/* [case()] */ DBCOLUMNDESC* pcoldescValue;
		/* [case()] */ DBID* pdbidValue;
		/* [case()] */ DBLIKE* pdblikeValue;
		/* [case()] */ DBCONTENT* pdbcntntValue;
		/* [case()] */ DBCONTENTSCOPE* pdbcntntscpValue;
		/* [case()] */ DBCONTENTTABLE* pdbcntnttblValue;
		/* [case()] */ DBCONTENTVECTOR* pdbcntntvcValue;
		/* [case()] */ DBCONTENTPROXIMITY* pdbcntntproxValue;
		/* [case()] */ DBGROUPINFO* pdbgrpinfValue;
		/* [case()] */ DBPARAMETER* pdbparamValue;
		/* [case()] */ DBPROPSET* pdbpropValue;
		/* [case()] */ DBSETFUNC* pdbstfncValue;
		/* [case()] */ DBSORTINFO* pdbsrtinfValue;
		/* [case()] */ DBTEXT* pdbtxtValue;
		/* [case()] */ DBVECTOR* pdbvectorValue;
		/* [case()] */ SAFEARRAY* parrayValue;
		/* [case()] */ VARIANT* pvarValue;
		/* [case()] */ GUID* pGuid;
		/* [case()] */ BYTE* pbValue;
		/* [case()] */ char* pzValue;
		/* [case()] */ DB_NUMERIC* pdbnValue;
		/* [case()] */ DBTIMESTAMP* pdbtsValue;
		/* [case()] */ void* pvValue;
		/* [case()] */ DBPROBABILISTIC* pdbprobValue;
		/* [case()] */ DBRELEVANTDOCUMENT* pdbreldocValue;
	} 	value;
	HRESULT hrError;
} 	DBCOMMANDTREE;


EXTERN_C const IID IID_ICommandTree;

#if defined(__cplusplus) && !defined(CINTERFACE)

MIDL_INTERFACE("0c733a87-2a1c-11ce-ade5-00aa0044773d")
ICommandTree : public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE FindErrorNodes(
		/* [in] */ const DBCOMMANDTREE * pRoot,
		/* [out] */ ULONG * pcErrorNodes,
		/* [out] */ DBCOMMANDTREE * **prgErrorNodes) = 0;

	virtual HRESULT STDMETHODCALLTYPE FreeCommandTree(
		/* [in] */ DBCOMMANDTREE** ppRoot) = 0;

	virtual HRESULT STDMETHODCALLTYPE GetCommandTree(
		/* [out] */ DBCOMMANDTREE** ppRoot) = 0;

	virtual HRESULT STDMETHODCALLTYPE SetCommandTree(
		/* [in] */ DBCOMMANDTREE** ppRoot,
		/* [in] */ DBCOMMANDREUSE dwCommandReuse,
		/* [in] */ BOOL fCopy) = 0;

};


#else 	/* C style interface */

typedef struct ICommandTreeVtbl
{
	BEGIN_INTERFACE

		DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
		HRESULT(STDMETHODCALLTYPE* QueryInterface)(
			ICommandTree* This,
			/* [in] */ REFIID riid,
			/* [annotation][iid_is][out] */
			_COM_Outptr_  void** ppvObject);

	DECLSPEC_XFGVIRT(IUnknown, AddRef)
		ULONG(STDMETHODCALLTYPE* AddRef)(
			ICommandTree* This);

	DECLSPEC_XFGVIRT(IUnknown, Release)
		ULONG(STDMETHODCALLTYPE* Release)(
			ICommandTree* This);

	DECLSPEC_XFGVIRT(ICommandTree, FindErrorNodes)
		HRESULT(STDMETHODCALLTYPE* FindErrorNodes)(
			ICommandTree* This,
			/* [in] */ const DBCOMMANDTREE* pRoot,
			/* [out] */ ULONG* pcErrorNodes,
			/* [out] */ DBCOMMANDTREE*** prgErrorNodes);

	DECLSPEC_XFGVIRT(ICommandTree, FreeCommandTree)
		HRESULT(STDMETHODCALLTYPE* FreeCommandTree)(
			ICommandTree* This,
			/* [in] */ DBCOMMANDTREE** ppRoot);

	DECLSPEC_XFGVIRT(ICommandTree, GetCommandTree)
		HRESULT(STDMETHODCALLTYPE* GetCommandTree)(
			ICommandTree* This,
			/* [out] */ DBCOMMANDTREE** ppRoot);

	DECLSPEC_XFGVIRT(ICommandTree, SetCommandTree)
		HRESULT(STDMETHODCALLTYPE* SetCommandTree)(
			ICommandTree* This,
			/* [in] */ DBCOMMANDTREE** ppRoot,
			/* [in] */ DBCOMMANDREUSE dwCommandReuse,
			/* [in] */ BOOL fCopy);

	END_INTERFACE
} ICommandTreeVtbl;

interface ICommandTree
{
	CONST_VTBL struct ICommandTreeVtbl* lpVtbl;
};



#ifdef COBJMACROS


#define ICommandTree_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICommandTree_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICommandTree_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICommandTree_FindErrorNodes(This,pRoot,pcErrorNodes,prgErrorNodes)	\
    ( (This)->lpVtbl -> FindErrorNodes(This,pRoot,pcErrorNodes,prgErrorNodes) ) 

#define ICommandTree_FreeCommandTree(This,ppRoot)	\
    ( (This)->lpVtbl -> FreeCommandTree(This,ppRoot) ) 

#define ICommandTree_GetCommandTree(This,ppRoot)	\
    ( (This)->lpVtbl -> GetCommandTree(This,ppRoot) ) 

#define ICommandTree_SetCommandTree(This,ppRoot,dwCommandReuse,fCopy)	\
    ( (This)->lpVtbl -> SetCommandTree(This,ppRoot,dwCommandReuse,fCopy) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */
#endif
#include "NTQuery.h"
#endif
#if VS_VER > VS_2005
#include "muiload.h"
//#include "mulres.idl"
#include "mxdc.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <namedpipeapi.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "namespaceapi.h"
#endif
#include "napmicrosoftvendorids.h"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <naptypes.h>
#endif
#include "natupnp.h"
#endif         
#if VS_VER > VC_1
#include <nb30.h>
#endif
//#include "nbluro.h"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ncrypt.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ncryptprotect.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <ndattrib.h>
#endif
#if VS_VER > VS_2005
#include "ndfapi.h"
#include "ndhelper.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ndisguid.h"
#endif
//#include "ndisport.h"
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <ndis/hashtypes.h>
#include <ndis/ioctltypes.h>
#include <ndis/nbluro.h>
#include <ndis/ndisport.h>
#include <ndis/nicswitchtypes.h>
#include <ndis/objectheader.h>
#include <ndis/offloadtypes.h>
#include <ndis/oidtypes.h>
#include <ndis/types.h>
#include <ndis/version.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <ndkinfo.h>
#endif
#if VS_VER > VC_6
#include "ndr64types.h"
#endif
//#include <netioapi.h>
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "netcfgn.h"
#endif
#if VS_VER > VS_2005
#include "netfw.h"
#endif
//#include "netiodef.h"
#if VS_VER > VS_2005
#include "netlistmgr.h"
#endif
#if VS_VER > VS_2003
#include "netprov.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <nettypes.h>
#endif
#if _WIN32_WINNT > 0x0A00 // Windows 8.1
// redefinition errors on Windows 8.1
#include "networkisolation.h"
#endif
#include <new.h>
#if VS_VER > VC_4
#include <new>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if VS_VER > VS_2015
#include "nfcradiodev.h"
#endif
#include "nfpdev.h"
#endif
//#include "nicswitchtypes.h"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <nldef.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <no_sal2.h>
#endif
//#include "notesdeviceservice.h"
#if TOOLSET > 90
#include "nsemail.h"
#endif                   
#if VS_VER > VC_1
#include <NspAPI.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "nspapip.h"
#endif                   
#if VS_VER > VC_1
#include "NspAPI.h"
#endif
#if VS_VER > VS_2002
#include "Npapi.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ntdd1394.h"
#include "ntddbeep.h"
//#include "ntddcdrm.h"
//#include "ntddcdvd.h"
//#include "ntddchgr.h"
#include "ntdddisk.h"
#include "ntddkbd.h"
#include "ntddmmc.h"
#include "ntddmodm.h"
#include "ntddmou.h"
#endif
#if VS_VER > VC_6
#include "ntddndis.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ntddpar.h"
#endif
#if VS_VER > VC_6
#include "NtDDPSch.h"
#include <ntddndis.h>
#include "NtDsAPI.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "ntddscm.h"
#if VS_VER > VS_2003
#include <ntddscsi.h>
#endif
#include "ntddser.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <ntddstor.h> // STORAGE_DEVICE_DESCRIPTOR and similiar"
#endif
//#include "ntddtape.h"
#include "ntddtdi.h"
#include "ntddvdeo.h"
#include "ntddvol.h"
//#include "ntdef.h"
#include "ntdskreg.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <ntioring_x.h>
#endif
#if VS_VER > VC_6
#include "NtLdap.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ntlsa.h"
#endif  
#if VS_VER > VC_1
#include "NTSDExts.h"
#endif
//#include "NTSecAPI.h"
//#include "NTSecPKG.h"
#if VS_VER > VC_5
#include <ntverp.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "nvme.h"
#endif
#if VS_VERSION > VC_2
#include <oaidl.h>
#endif
//#include "objactnl.idl"
//#include "objectheader.h"
#if (defined(NTDDI_WIN10_VB)) && (NTDDI_VERSION > NTDDI_WIN10_VB)
#include <objbase.h>           // Windows COM declarations"
#endif            
#if VS_VER > VC_1
#include <objerror.h>
#endif
//#include "objidl.Idl"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "objidlbase.h"
#endif
#if VS_VERSION > VC_2
#include <objidl.h> // for IStream"
#endif
#if VS_VER > VC_4
#include <ocidl.h>
#endif
#include "odbcinst.h"
#if VS_VER > VC_5
#include "odbcss.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "oemupgex.h"
#endif
//#include "offloadtypes.h"
//#include "oidtypes.h"
//#include <ole.h>
#include <ole2.h>      // for DECLARE_INTERFACE_ and HRESULT"
#if VS_VER > VC_5
#include "oleTx2xa.h"
#endif         
#if VS_VER > VC_1
#include <oleauto.h>                 
#include <olectl.h> 
#endif
//#include "oledb.idl"
#if VS_VER > VC_6
#include "oledbdep.h"
#endif
//#include "oledbdep.idl"
//#include "oledbguid.h"
//#include "oledbnew.idl"
#if VS_VERSION > VC_2
#include <oleidl.h>
#include "OleDlg.h"
#endif
//#include "OleDlg.Dlg"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "ondemandconnroutehelper.h"
#include "oobenotification.h"
#endif
#if TOOLSET > 90
#include "openservice.h"
#endif
//#include "opmapi.h"
//#include "opnrst.idl"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "packagevirtualizationcontext.h"
#endif
//#include "packet.h"
//#include "packethash.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "pacmanclientapi.h"
//#include "pacmanclientapi_i.c"
#endif
//#include "parrst.idl"
#if VS_VER == VS_2002
//todo determine the actual value
#define MAX_NAME_SIZE 256
#include "parser.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "pbdaerrors.h"
#endif
#if VS_VER > VC_6
#include "pchannel.h"
#endif
#if VS_VER > VS_2005
#include "pciprop.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "pdrvver.h"
#endif
#include "peninputpanel.h"
//#include "peninputpanel_i.c"
#include "perflib.h"
#endif
#if TOOLSET == 90
//-----------------------------------------------------------------------------
//
// File:        persist.h
//
// Copyright:   Copyright (c) Microsoft Corporation
//
// Contents:    MSPersist external constants GUIDS and other things users need
//
// Comments:
//
//-----------------------------------------------------------------------------
// Modified to fix issues about type conversion

#ifndef PERSIST_H
#define PERSIST_H

#undef PERSISTDECLSPEC
#if _MSC_VER >= 1100 && (!defined(SHx) || (defined(SHx) && _MSC_VER >= 1200))
#define PERSISTDECLSPEC __declspec(selectany)
#else
#define PERSISTDECLSPEC 
#endif //_MSC_VER

// Persist Properties
#define DBPROPFLAGS_PERSIST 0x2000

#define DBPROPVAL_PERSIST_ADTG 0
#define DBPROPVAL_PERSIST_XML 1
#define DBPROP_PersistFormat 2
#define DBPROP_PersistSchema 3
#define DBPROP_HCHAPTER 4
#define DBPROP_MAINTAINPROPS 5

// XML writing only properties
#define DBPROP_Unicode  6

// internal property (read-only)
#define DBPROP_INTERLEAVEDROWS 8

extern const PERSISTDECLSPEC CLSID CLSID_MSPersist
= { 0x7c07e0d0, 0x4418, 0x11d2, { 0x92, 0x12, 0x0, 0xc0, 0x4f, 0xbb, 0xbf, 0xb3 } };

// {4D7839A0-5B8E-11d1-A6B3-00A0C9138C66}
extern const PERSISTDECLSPEC GUID   DBPROPSET_PERSIST
= { 0x4d7839a0, 0x5b8e, 0x11d1, { 0xa6, 0xb3, 0x0, 0xa0, 0xc9, 0x13, 0x8c, 0x66 } };

#define MS_PERSIST_PROGID "MSPersist"
#define MS_PERSIST_PROGID_W L"MSPersist"

extern const PERSISTDECLSPEC char* PROGID_MSPersist = MS_PERSIST_PROGID;

extern const PERSISTDECLSPEC wchar_t* PROGID_MSPersist_W = MS_PERSIST_PROGID_W;

extern const PERSISTDECLSPEC char* PROGID_MSPersist_Version = MS_PERSIST_PROGID ".1";

extern const PERSISTDECLSPEC wchar_t* PROGID_MSPersist_Version_W = L"MSPersist.1";

#endif // PERSIST_H
#else
#if VS_VER > VC_6
#include "persist.h"
#endif
#endif
#if TOOLSET > 90
#include "PNPXAssoc.h"
#endif
#if VS_VER > VC_6
#include "PatchApi.h"
#include "PatchWiz.h"
#endif
#if VS_VER > VC_6
// reason: pdh.h(50) : error C2040: 'HLOG' : 'void *' differs in levels of indirection from 'struct _HLOG' 
#include "Pdh.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "PeerDist.h"
#endif
#if VS_VER > VC_5
#include "PerHist.h"
#endif
#if VS_VER > VS_2005
#include "PhotoAcquireProperties.h"
#include "physicalmonitorenumerationapi.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "pix.h"
#endif
#include "pla.h"
#endif
#if TOOLSET > 90
#include "playlist.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "playsoundapi.h"
#include "playto.h"
#include "PlayToManagerInterop.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "pluginauthenticator.h"
#endif
#if VS_VER > VS_2005
#include "pnrpns.h"
#endif
//#include "poclass.h"
#if VS_VER > VC_6
#include "Polarity.h"
#endif
#if VS_VER > VS_2005
#include "PortableDevice.h"
#include "PortableDeviceApi.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "powerbase.h"
#include "powersetting.h"
#endif
#if VS_VER > VC_6
#include "powrprof.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <WinDDIUI.h>
#endif
//#include "prcomoem.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "prdrvcom.h"
#include "printoem.h"
#if VS_VER > VS_2015
#include "Print3DManagerInterop.h"
#endif
#include "PrintManagerInterop.h"
#endif
#if VS_VER > VS_2005
#include "prnasnot.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "prnasntp.h"
#endif
//#include "prntfont.h"
#if VS_VER > VS_2005
#include "prntvpt.h"
#endif
//#include "PrnSetup.Dlg"
#include "process.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "processenv.h"
#include "processthreadsapi.h"
#include "processtopologyapi.h"
#if MSVC_VER > 2012
#include "ProcessSnapshot.h"
#endif
#include "profileapi.h"
#endif
#if VS_VER > VC_6
#include "ProfInfo.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "projectedfslib.h"
#endif
#if VS_VER > VS_2005
#include "propapi.h"
#include "propkey.h"
#include "propvarutil.h"
#endif
//#include "prvmon.idl"
//#include "PropIdl.Idl"
#if VS_VER > VC_6
#include "PropIdl.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "PropIdlBase.h"
#endif
#if VS_VER > VC_6
#include "ProvExce.h"
#endif
//#include "Provider.h"
#if VS_VER > VC_6
#include "Psapi.h"
#endif
#if cppver >= 2017
#include <optional>
#endif
#if VS_VER > VC_4
#include <ostream>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <packoff.h>
#include <packon.h>
#endif
#if VS_VER > VC_6
#include <pchannel.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <pciprop.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <playsoundapi.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <pmmintrin.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <poclass.h>
#include <powerbase.h>
#include <powersetting.h>
#endif
//#include <printoem.h>
//#include <prntfont.h>
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <processenv.h>
#include <processthreadsapi.h>
#include <processtopologyapi.h>
#include <profileapi.h>
#endif
#if VS_VER > VC_6
#include <profinfo.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <propapi.h>
#endif
#if VS_VER > VC_6
#include <propidl.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <propidlbase.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <propkey.h>
#endif
//#include <propvarutil.h>  
//#include <provider.h>
#if VS_VERSION > VC_2
#include <prsht.h>
#endif      
#if VS_VER > VC_1
#include <pshpack2.h>
#include <pshpack4.h>
#include <pshpack8.h>           
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "pwm.h"
#endif
#if VS_VER > VS_2002
#include "qmgr.h"
#endif
#if VS_VER > VS_2005
#include "qnetwork.h"
#endif
#if VS_VER > VC_5
#include <qos.h>
#endif
//#include "qos2.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <qosobjs.h>
#endif
#if VS_VER > VC_6
#include "QosPol.h"
#include "qossp.h"
#endif
//#include "qrybas.idl"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "RadialControllerInterop.h"
#endif            
#if VS_VER > VC_1
#include <ras.h> 
#endif
#if VS_VER > VC_4
#include "RasDlg.h"
#endif       
#if VS_VER > VC_1
#include "RasError.h"
#endif
#if VS_VER > VC_5
#if VS_VER == VC_6
// Raseapif.h
//
// Value is set to the 32 bit integral value or a pointer to data.
// 32 bit integral values should be in host format, not network format.
// Length for a 32 bit integral value can be 1, 2 or 4. The array of
// attributes must be terminated with an attribute of type raatMinimum.
//
typedef enum _RAS_AUTH_ATTRIBUTE_TYPE_
{
	raatMinimum = 0,                // Undefined
	raatUserName,                   // Value field is a Pointer
	raatUserPassword,               // Value field is a Pointer
	raatMD5CHAPPassword,            // Value field is a Pointer
	raatNASIPAddress,               // Value field is a 32 bit integral value
	raatNASPort,                    // Value field is a 32 bit integral value
	raatServiceType,                // Value field is a 32 bit integral value
	raatFramedProtocol,             // Value field is a 32 bit integral value
	raatFramedIPAddress,            // Value field is a 32 bit integral value
	raatFramedIPNetmask,            // Value field is a 32 bit integral value
	raatFramedRouting = 10,         // Value field is a 32 bit integral value
	raatFilterId,                   // Value field is a Pointer
	raatFramedMTU,                  // Value field is a 32 bit integral value
	raatFramedCompression,          // Value field is a 32 bit integral value
	raatLoginIPHost,                // Value field is a 32 bit integral value
	raatLoginService,               // Value field is a 32 bit integral value
	raatLoginTCPPort,               // Value field is a 32 bit integral value
	raatUnassigned17,               // Undefined
	raatReplyMessage,               // Value field is a Pointer
	raatCallbackNumber,             // Value field is a Pointer
	raatCallbackId = 20,            // Value field is a Pointer
	raatUnassigned21,               // Undefined
	raatFramedRoute,                // Value field is a Pointer
	raatFramedIPXNetwork,           // Value field is a 32 bit integral value
	raatState,                      // Value field is a Pointer
	raatClass,                      // Value field is a Pointer
	raatVendorSpecific,             // Value field is a Pointer
	raatSessionTimeout,             // Value field is a 32 bit integral value
	raatIdleTimeout,                // Value field is a 32 bit integral value
	raatTerminationAction,          // Value field is a 32 bit integral value
	raatCalledStationId = 30,       // Value field is a Pointer
	raatCallingStationId,           // Value field is a Pointer
	raatNASIdentifier,              // Value field is a Pointer
	raatProxyState,                 // Value field is a Pointer
	raatLoginLATService,            // Value field is a Pointer
	raatLoginLATNode,               // Value field is a Pointer
	raatLoginLATGroup,              // Value field is a Pointer
	raatFramedAppleTalkLink,        // Value field is a 32 bit integral value
	raatFramedAppleTalkNetwork,     // Value field is a 32 bit integral value
	raatFramedAppleTalkZone,        // Value field is a Pointer
	raatAcctStatusType = 40,        // Value field is a 32 bit integral value
	raatAcctDelayTime,              // Value field is a 32 bit integral value
	raatAcctInputOctets,            // Value field is a 32 bit integral value
	raatAcctOutputOctets,           // Value field is a 32 bit integral value
	raatAcctSessionId,              // Value field is a Pointer
	raatAcctAuthentic,              // Value field is a 32 bit integral value
	raatAcctSessionTime,            // Value field is a 32 bit integral value
	raatAcctInputPackets,           // Value field is a 32 bit integral value
	raatAcctOutputPackets,          // Value field is a 32 bit integral value
	raatAcctTerminateCause,         // Value field is a 32 bit integral value
	raatAcctMultiSessionId = 50,    // Value field is a Pointer
	raatAcctLinkCount,              // Value field is a 32 bit integral value
	raatAcctEventTimeStamp = 55,    // Value field is a 32 bit integral value
	raatMD5CHAPChallenge = 60,      // Value field is a Pointer
	raatNASPortType,                // Value field is a 32 bit integral value
	raatPortLimit,                  // Value field is a 32 bit integral value
	raatLoginLATPort,               // Value field is a Pointer
	raatTunnelType,                 // Value field is a 32 bit integral value
	raatTunnelMediumType,           // Value field is a 32 bit integral value
	raatTunnelClientEndpoint,       // Value field is a Pointer
	raatTunnelServerEndpoint,       // Value field is a Pointer
	raatARAPPassword = 70,          // Value field is a Pointer
	raatARAPFeatures,               // Value field is a Pointer
	raatARAPZoneAccess,             // Value field is a 32 bit integral value
	raatARAPSecurity,               // Value field is a 32 bit integral value
	raatARAPSecurityData,           // Value field is a Pointer
	raatPasswordRetry,              // Value field is a 32 bit integral value
	raatPrompt,                     // Value field is a 32 bit integral value
	raatConnectInfo,                // Value field is a Pointer
	raatConfigurationToken,         // Value field is a Pointer
	raatEAPMessage,                 // Value field is a Pointer
	raatSignature = 80,             // Value field is a Pointer
	raatARAPChallengeResponse = 84, // Value field is a Pointer
	raatAcctInterimInterval = 85,   // Value field is a 32 bit integral value
	raatNASIPv6Address = 95,
	raatFramedInterfaceId,
	raatFramedIPv6Prefix,
	raatLoginIPv6Host,
	raatFramedIPv6Route,
	raatFramedIPv6Pool,
	raatARAPGuestLogon = 8096,        // Value field is a 32 bit integral value
	raatCertificateOID,               // Value field is a Pointer
	raatEAPConfiguration,             // Value field is a Pointer
	raatPEAPEmbeddedEAPTypeId = 8099, // Value field is a 32 bit integral value
	raatInnerEAPTypeId = 8099,        // Value field is a 32 bit integral value
	raatPEAPFastRoamedSession = 8100, // Value field is a 32 bit integral value
	raatFastRoamedSession = 8100,     // Value field is a 32 bit integral value
	raatEAPTLV = 8102,                // Value field is a Pointer
	raatCredentialsChanged,           // Value field is a Integer with boolean semantics
	raatCertificateThumbprint = 8250, // Value field is a Pointer
	raatPeerId = 9000,                // Value field is a pointer
	raatServerId,                     // Value field is a pointer
	raatMethodId,                     // Value field is a pointer
	raatEMSK,                         // Value field is a pointer
	raatSessionId,                    // Value field is a pointer
	raatReserved = 0xFFFFFFFF         // Undefined

} RAS_AUTH_ATTRIBUTE_TYPE;

typedef struct _RAS_AUTH_ATTRIBUTE
{
	RAS_AUTH_ATTRIBUTE_TYPE raaType;
	DWORD dwLength;
	/*_Field_size_(dwLength)*/ PVOID Value;

} RAS_AUTH_ATTRIBUTE, * PRAS_AUTH_ATTRIBUTE;
#endif
#include "Raseapif.h"
#endif
#if VS_VER == VC_6 // redefinition
#include "RassHost.h"
#endif
#if VS_VER > VC_5
#include "Ratings.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "rdpappcontainerclient.h"
#endif
//#include "rdpappcontainerclient.idl"
#if VS_VER > VS_2005
#include "rdpencomapi.h"
#endif
//#include "rdpencomapi.idl"
//#include "rdpencomapi_i.c"
//#include "readdt.idl"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <realtimeapiset.h>
#endif
#if VS_VER > VC_6
#include <reason.h>             // get the public reasons"
#endif
//#include "recapis.h"
#if VS_VER > VS_2005
#include "recdefs.h"
#include "rectypes.h"
#endif
//#include "regprv.idl"
#if VS_VERSION > VC_2
#include "RegStr.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "relogger.h"
#if VS_VER > VS_2015
#include "RemoteSystemsInterop.h"
#endif
#endif
#if VS_VER > VS_2005
#include "rendezvoussession.h"
#endif
//#include "rendezvoussession_i.c"
//#include "Resapi.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "reshub.h"
#if VS_VER > VS_2015
#include "ResourceIndexer.h"
#endif
#endif
#if VS_VER > VS_2005
#include "RestartManager.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <restrictedErrorInfo.h>
#endif
//#include "returncontext.h"
#if VS_VERSION > VC_2
#include "Richedit.h"
#endif
//#include "ringtonedeviceservice.h"
#if NTDDI_VERSION > 0x0A000C00 // v143
#include "RoMetadataApi.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <roapi.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "robuffer.h"
//#define MPR60 1
//#include "Routprot.h"
#include "roparameterizediid.h"
#include "roregistrationapi.h"
#endif
/*#include "row.idl"
#include "rowchg.idl"
#include "rowinf.idl"
#include "rowpos.idl"
#include "rowpsc.idl"*/
#if VS_VER > VC_1
#include <rpc.h> 
#endif
#if VS_VER > VC_5
#include <rpcasync.h>
#endif  
#if VS_VER > VC_1
#include <rpcdce.h>
#include <rpcdcep.h>
#include <rpcndr.h> // used for boolean"
#include <rpcnsi.h>
#include <rpcnsip.h>
#include <rpcnterr.h>   
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <rpcsal.h>
#endif
#if VS_VER > VS_2002
#include "rpcssl.h"
#endif
//#include "rsc.h"
/*#include "rstasn.idl"
#include "rstbas.idl"
#include "rstbmrk.idl"
#include "rstcei.idl"
#include "rstchg.idl"
#include "rstchpmb.idl"
#include "rstcpr.idl"
#include "rstcridx.idl"
#include "rstfnd.idl"
#include "rstidn.idl"
#include "rstind.idl"
#include "rstinf.idl"
#include "rstkys.idl"
#include "rstlkr.idl"
#include "rstloc.idl"
#include "rstnot.idl"
#include "rstnra.idl"
#include "rstnwr.idl"
#include "rstnxr.idl"
#include "rstres.idl"
#include "rstrfres.idl"
#include "rstscr.idl"
#include "rstupd.idl"
#include "rstvw.idl"
#include "rstwpr.idl"
#include "rstwta.idl"
#include "rstwtn.idl"
#include "rstwtr.idl"
#include "rstxsc.idl"*/
#if VS_VER > VC_6
#include "RrasCfg.h"
#include "rtccore.h"
#endif
#if VS_VER > VC_5
#include "RTInfo.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "rtlsupportapi.h"
#endif
#if VS_VER > VC_6
#include "RtmV2.h"
#endif
//#include "RTSCOM_i.c"
#if VS_VER > VC_5
#include <rtutils.h>
#endif
//#include "rwschg.idl"
#if TOOLSET > 90
#include "safeint.h"
#endif
#if VS_VER > VS_2003
#include <sal.h>
#endif
#if VS_VER > VC_6
#include <Sti.h>
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "stiusd.h"
#endif
#if VS_VER > VS_2005
#include <sapi.h>
//#include "sapi.idl"
#include <sapiddk.h>
#endif
#endif
#if TOOLSET > 90
#include "sas.h"
#endif
#if VS_VER > VS_2005
#include "sbe.h"
#endif
#if TOOLSET > 90
#include "sberrors.h"
#include "sbtsv.h"
#endif
#if VS_VER > VC_6
#include <schannel.h>
#include <schedule.h>
#include <schnlsp.h> // exists on VC++ 6 but found syntax errors
//todo recheck this error
#endif
#if VS_VER > VC_6
#include "Schemadef.h"
#endif
#if VS_VER > VS_2005
#include <mswmdm.h>
#include "scclient.h"
#endif
#if VS_VER > VC_6
#include "scesvc.h"
#endif
//#include "scpops.idl"
#include "ScrnSave.h"
#if VS_VER > VC_5
#include "ScrptIDs.h"
#endif
#if TOOLSET > 90
#include "scserver.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "scsi.h"
#include "scsiscan.h"
#endif
#if VS_VER > VC_6
#include "sddl.h"
#endif
//#include "sdoias.h"
#include <search.h>
#if TOOLSET == 90
#ifdef ISSP_LEVEL
#include "security.h"
#include <secext.h>
#endif
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <securityappcontainer.h>
#include <securitybaseapi.h>
#endif
//#include "segment.idl"
#if VS_VER > VC_6
#include "Sens.h"
#include "SensAPI.h"
#include "SensEvts.h"
#endif
#if TOOLSET > 90
#include "sensors.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "sensorsdef.h"
#include "sensorsutils.h"
#endif
//#include "sesprp.idl"
#if TOOLSET > 90
#include "sessdirpublictypes.h"
#endif
//#include "seurinfo.idl"
#if VS_VER > VC_4
#include <set>
#endif
#include <setjmp.h>
#if VS_VER > VC_4
#include <setupapi.h>
#endif
#if VS_VER > VC_6
#include "Sfc.h"
#endif
#if VS_VER > VS_2002
#include "shappmgr.h"
#endif
#include "share.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "sharewindowcommandsourceinterop.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "shcore.h"
#endif
#if VS_VER > VS_2005
#include "shdeprecated.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "ShellScalingApi.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <sherrors.h>
#endif
#if VS_VER > VS_2005
#include "shidfact.h"
#endif
//#include "shimgdata.h"
//#include "shldisp.idl"
#include "signal.h"
#if VS_VER > VC_6
#include "ShlDisp.h"
#endif
#if VS_VERSION > VC_2
#include "ShlGuid.h"
#endif
#if VS_VER > VC_6
#include <shtypes.h>
#include <sipbase.h> // included mssip.h
#endif
#if VS_VER > VS_2005
#include "sliddefs.h"
#include "slpublic.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "smbclnt.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <smmintrin.h>
#endif
#if VS_VER > VC_6
#include "SmtpGuid.h"
#endif     
#if VS_VER > VC_1
#include <snmp.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "socketapi.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "softintrin.h"
#endif
#if VS_VER > VC_6
#include "SoftPub.h"
#endif
#if cppver > 2017
#include <source_location>
#include <span>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <spapidef.h>
#include <specstrings_strict.h>
//#include <specstrings_undef.h>
#endif
//#include "SpOrder.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if VS_VER > 2015
#include "SpatialInteractionManagerInterop.h"
#endif
#if MSVC_VER > 2012
#include "spb.h"
#endif
#endif
//#include "spddkhlp.h"
#if VS_VER > VS_2005
#include "spcollec.h"
#endif
//#include "specstrings_strict.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "spellcheck.h"
//#include "spellcheck_i.c"
#include "spellcheckprovider.h"
//#include "spellcheckprovider_i.c"
#endif
#if VS_VER > VS_2005
#include "sperror.h"
#endif
//#include "sphelper.h"
//#include "speventq.h"
//#include "spuihelp.h"
//#include "sqleri.idl"
#include "sqlext.h"
#ifdef SUCCESS
#pragma push_macro("SUCCESS")
#undef SUCCESS
#if VS_VER > VC_6
#include "Sql_1.h"
#endif
#pragma pop_macro("SUCCESS")
#else
#if VS_VER > VC_6
#include "Sql_1.h"
#endif
#endif
//#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "sqlspi.h"
//#include "srcrst.idl"
#if VS_VER > VS_2015
#include "srpapi.h"
#endif
#endif
#if VS_VER > VC_6
#include "SrRestorePtApi.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <sqlext.h>
#endif
#if TOOLSET == 90
#ifdef ISSP_LEVEL
#include "sspi.h"
#endif
#endif
//#include "stat.h"
//#include "statehelpers.h"
//#include "status.h"
//#include "statusdeviceservice.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "stdalign.h"
#endif
#include <stdarg.h>
#include "stddef.h"
#include "stdlib.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "stdnoreturn.h"
#endif
#if VS_VER > VS_2005
#include "StgProp.h"
#endif
#if VS_VER > VC_6
#include "stierr.h"
#include "stireg.h"
#include "StlLock.h"
#endif
#ifdef ISSP_LEVEL
#include <sspi.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)  && ((defined WIN7_SUPPORT) || (defined WINDOWS7_SUPPORT))
#include <stdbool.h>
#endif
#include <stddef.h>
#if VS_VER > VC_4
#include <stdexcept>
#endif
#if _MSC_VER > 1500
#include <stdint.h>
#else
#if VS_VER > VC_1
//         
// stdint.h
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// The C Standard Library <stdint.h> header.
//
#pragma once
#define _STDINT

// C1083 in VS2008: no such file
//#include <vcruntime.h> 

// no such macro
//#if _VCRT_COMPILER_PREPROCESSOR

#pragma warning(push)
//#pragma warning(disable: _VCRUNTIME_DISABLED_WARNINGS)

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
#if cppver>= 2011
typedef long long          int64_t;
#else
typedef __int64            int64_t;
#endif
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
#if cppver>= 2011
typedef unsigned long long uint64_t;
#else    
#if VS_VER > VC_1 // error C2371: '__int64' : redefinition; different basic types
typedef unsigned __int64   uint64_t;
#endif
#endif

typedef signed char        int_least8_t;
typedef short              int_least16_t;
typedef int                int_least32_t;
typedef __int64            int_least64_t;
typedef unsigned char      uint_least8_t;
typedef unsigned short     uint_least16_t;
typedef unsigned int       uint_least32_t;
typedef unsigned __int64   uint_least64_t;

typedef signed char        int_fast8_t;
typedef int                int_fast16_t;
typedef int                int_fast32_t;
typedef __int64            int_fast64_t;
typedef unsigned char      uint_fast8_t;
typedef unsigned int       uint_fast16_t;
typedef unsigned int       uint_fast32_t;
typedef unsigned __int64   uint_fast64_t;

typedef __int64            intmax_t;
typedef unsigned __int64   uintmax_t;

// These macros must exactly match those in the Windows SDK's intsafe.h.
#define INT8_MIN         (-127i8 - 1)
#define INT16_MIN        (-32767i16 - 1)
#define INT32_MIN        (-2147483647i32 - 1)
#define INT64_MIN        (-9223372036854775807i64 - 1)
#define INT8_MAX         127i8
#define INT16_MAX        32767i16
#define INT32_MAX        2147483647i32
#define INT64_MAX        9223372036854775807i64
#define UINT8_MAX        0xffui8
#define UINT16_MAX       0xffffui16
#define UINT32_MAX       0xffffffffui32
#define UINT64_MAX       0xffffffffffffffffui64

#define INT_LEAST8_MIN   INT8_MIN
#define INT_LEAST16_MIN  INT16_MIN
#define INT_LEAST32_MIN  INT32_MIN
#define INT_LEAST64_MIN  INT64_MIN
#define INT_LEAST8_MAX   INT8_MAX
#define INT_LEAST16_MAX  INT16_MAX
#define INT_LEAST32_MAX  INT32_MAX
#define INT_LEAST64_MAX  INT64_MAX
#define UINT_LEAST8_MAX  UINT8_MAX
#define UINT_LEAST16_MAX UINT16_MAX
#define UINT_LEAST32_MAX UINT32_MAX
#define UINT_LEAST64_MAX UINT64_MAX

#define INT_FAST8_MIN    INT8_MIN
#define INT_FAST16_MIN   INT32_MIN
#define INT_FAST32_MIN   INT32_MIN
#define INT_FAST64_MIN   INT64_MIN
#define INT_FAST8_MAX    INT8_MAX
#define INT_FAST16_MAX   INT32_MAX
#define INT_FAST32_MAX   INT32_MAX
#define INT_FAST64_MAX   INT64_MAX
#define UINT_FAST8_MAX   UINT8_MAX
#define UINT_FAST16_MAX  UINT32_MAX
#define UINT_FAST32_MAX  UINT32_MAX
#define UINT_FAST64_MAX  UINT64_MAX

#ifdef _WIN64
#define INTPTR_MIN   INT64_MIN
#define INTPTR_MAX   INT64_MAX
#define UINTPTR_MAX  UINT64_MAX
#else
#define INTPTR_MIN   INT32_MIN
#define INTPTR_MAX   INT32_MAX
#define UINTPTR_MAX  UINT32_MAX
#endif

#define INTMAX_MIN       INT64_MIN
#define INTMAX_MAX       INT64_MAX
#define UINTMAX_MAX      UINT64_MAX

#define PTRDIFF_MIN      INTPTR_MIN
#define PTRDIFF_MAX      INTPTR_MAX

#ifndef SIZE_MAX
// SIZE_MAX definition must match exactly with limits.h for modules support.
#ifdef _WIN64
#define SIZE_MAX 0xffffffffffffffffui64
#else
#define SIZE_MAX 0xffffffffui32
#endif
#endif

#define SIG_ATOMIC_MIN   INT32_MIN
#define SIG_ATOMIC_MAX   INT32_MAX

#define WCHAR_MIN        0x0000
#define WCHAR_MAX        0xffff

#define WINT_MIN         0x0000
#define WINT_MAX         0xffff

#define INT8_C(x)    (x)
#define INT16_C(x)   (x)
#define INT32_C(x)   (x)
#define INT64_C(x)   (x ## LL)

#define UINT8_C(x)   (x)
#define UINT16_C(x)  (x)
#define UINT32_C(x)  (x ## U)
#define UINT64_C(x)  (x ## ULL)

#define INTMAX_C(x)  INT64_C(x)
#define UINTMAX_C(x) UINT64_C(x)

#pragma warning(pop) // _VCRUNTIME_DISABLED_WARNINGS

//#endif // _VCRT_COMPILER_PREPROCESSOR

#endif                
#endif
#include <stdio.h>  
#if VS_VER > VC_6
#include <stierr.h>
#include <stireg.h>
#include <stllock.h>
//#include <stm.h>
#if VS_VER > VS_2002
#include "storprop.h"
#endif
#include <stralign.h>
#endif
#include <string.h> 
#if VS_VER > VC_4
#include <string>
#endif
#if cppver >= 2017
#include <string_view>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <stringapiset.h>    
#endif
//#include "strmif.idl"
//#include <strmif.h>     // Generated IDL header file for streams interfaces"
#if VS_VER > VS_2005
#include "structuredquery.h"
#endif
//#include "SubAuth.h"
#if VS_VER > VS_2005
#include "subscriptionservices.h"
#endif                
#if VS_VER > VC_1
#include "SvcGuid.h" 
#endif
//#include "swdevice.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <suppress.h>
//#include <swdevicedef.h>
#include <synchapi.h>
#if VS_VER > VS_2015
#include "SystemMediaTransportControlsInterop.h"
#endif
#endif
#if TOOLSET > 90
#include "syncregistration.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "sysinfoapi.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "systemmanagementcontract.h"
#endif
#include "systemtopologyapi.h"
#endif
#include <sys/stat.h>
#include <sys/types.h>
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <sysinfoapi.h>
#include <systemtopologyapi.h>
#endif
#if (defined INCLUDE_WINDOWS_RT) || \
((defined _BIGOBJ) || (defined __BIGOBJ__))
/*
* 严重性	代码	说明	项目	文件	行	抑制状态	详细信息
错误	C1128	节数超过对象文件格式限制: 请使用 /bigobj 进行编译	Windows-API-All-In-One-for-Visual-Studio	C:\Users\Admin\source\repos\Windows-API-All-In-One-for-Visual-Studio\Windows-API-All-In-One-for-Visual-Studio\ConsoleApplication1.cpp	1

*/
#include "windows.ai.actions.h"
#include "windows.ai.actions.hosting.h"
#include "windows.ai.actions.provider.h"
#include "windows.ai.agents.h"
#include "windows.ai.agents.mcp.h"
#include "windows.ai.machinelearning.h"
#include "windows.ai.machinelearning.native.h"
#include "windows.ai.machinelearning.preview.h"
#include "windows.applicationmodel.activation.h"
#include "windows.applicationmodel.appextensions.h"
#include "windows.applicationmodel.appointments.appointmentsprovider.h"
#include "windows.applicationmodel.appointments.dataprovider.h"
#include "windows.applicationmodel.appointments.h"
#include "windows.applicationmodel.appservice.h"
#include "windows.applicationmodel.background.h"
#include "windows.applicationmodel.calls.background.h"
#include "windows.applicationmodel.calls.h"
#include "windows.applicationmodel.calls.provider.h"
#include "windows.applicationmodel.chat.h"
#include "windows.applicationmodel.communicationblocking.h"
#include "windows.applicationmodel.contacts.dataprovider.h"
#include "windows.applicationmodel.contacts.h"
#include "windows.applicationmodel.contacts.provider.h"
#include "windows.applicationmodel.conversationalagent.h"
#include "windows.applicationmodel.core.h"
#include "windows.applicationmodel.datatransfer.dragdrop.core.h"
#include "windows.applicationmodel.datatransfer.dragdrop.h"
#include "windows.applicationmodel.datatransfer.h"
#include "windows.applicationmodel.datatransfer.sharetarget.h"
#include "windows.applicationmodel.email.dataprovider.h"
#include "windows.applicationmodel.email.h"
#include "windows.applicationmodel.extendedexecution.foreground.h"
#include "windows.applicationmodel.extendedexecution.h"
#include "windows.applicationmodel.h"
#include "windows.applicationmodel.holographic.h"
#include "windows.applicationmodel.lockscreen.h"
#include "windows.applicationmodel.packageextensions.h"
#include "windows.applicationmodel.payments.h"
#include "windows.applicationmodel.payments.provider.h"
#include "windows.applicationmodel.preview.h"
#include "windows.applicationmodel.preview.holographic.h"
#include "windows.applicationmodel.preview.inkworkspace.h"
#include "windows.applicationmodel.preview.notes.h"
//#include "windows.applicationmodel.resources.core.h"
#include "windows.applicationmodel.resources.h"
#include "windows.applicationmodel.resources.management.h"
#include "windows.applicationmodel.search.core.h"
#include "windows.applicationmodel.search.h"
#include "windows.applicationmodel.socialinfo.h"
#include "windows.applicationmodel.socialinfo.provider.h"
#include "windows.applicationmodel.store.h"
#include "windows.applicationmodel.store.licensemanagement.h"
#include "windows.applicationmodel.store.preview.h"
#include "windows.applicationmodel.store.preview.installcontrol.h"
#include "windows.applicationmodel.useractivities.core.h"
#include "windows.applicationmodel.useractivities.h"
#include "windows.applicationmodel.userdataaccounts.h"
#include "windows.applicationmodel.userdataaccounts.provider.h"
#include "windows.applicationmodel.userdataaccounts.systemaccess.h"
#include "windows.applicationmodel.userdatatasks.dataprovider.h"
#include "windows.applicationmodel.userdatatasks.h"
#include "windows.applicationmodel.voicecommands.h"
#include "windows.applicationmodel.wallet.h"
#include "windows.applicationmodel.wallet.system.h"
#include "windows.data.html.h"
#include "windows.data.json.h"
#include "windows.data.pdf.h"
#include "windows.data.pdf.interop.h"
#include "windows.data.text.h"
#include "windows.data.xml.dom.h"
#include "windows.data.xml.xsl.h"
#include "windows.devices.adc.h"
#include "windows.devices.adc.provider.h"
#include "windows.devices.background.h"
#include "windows.devices.bluetooth.advertisement.h"
#include "windows.devices.bluetooth.background.h"
#include "windows.devices.bluetooth.genericattributeprofile.h"
#include "windows.devices.bluetooth.h"
#include "windows.devices.bluetooth.rfcomm.h"
#include "windows.devices.custom.h"
#include "windows.devices.display.core.h"
#include "windows.devices.display.h"
#include "windows.devices.enumeration.h"
#include "windows.devices.enumeration.pnp.h"
#include "windows.devices.geolocation.geofencing.h"
#include "windows.devices.geolocation.h"
#include "windows.devices.geolocation.provider.h"
#include "windows.devices.gpio.h"
#include "windows.devices.gpio.provider.h"
#include "windows.devices.h"
#include "windows.devices.haptics.h"
#include "windows.devices.humaninterfacedevice.h"
#include "windows.devices.i2c.h"
#include "windows.devices.i2c.provider.h"
#include "windows.devices.input.h"
#include "windows.devices.input.preview.h"
#include "windows.devices.lights.effects.h"
#include "windows.devices.lights.h"
#include "windows.devices.midi.h"
#include "windows.devices.perception.h"
#include "windows.devices.perception.provider.h"
#include "windows.devices.pointofservice.h"
#include "windows.devices.pointofservice.provider.h"
#include "windows.devices.portable.h"
#include "windows.devices.power.h"
#include "windows.devices.printers.extensions.h"
#include "windows.devices.printers.h"
#include "windows.devices.pwm.h"
#include "windows.devices.pwm.provider.h"
#include "windows.devices.radios.h"
#include "windows.devices.scanners.h"
#include "windows.devices.sensors.custom.h"
#include "windows.devices.sensors.h"
#include "windows.devices.serialcommunication.h"
#include "windows.devices.smartcards.h"
#include "windows.devices.sms.h"
#include "windows.devices.spi.h"
#include "windows.devices.spi.provider.h"
#include "windows.devices.usb.h"
#include "windows.devices.wifi.h"
#include "windows.devices.wifidirect.h"
#include "windows.devices.wifidirect.services.h"
#include "windows.foundation.collections.h"
#include "windows.foundation.diagnostics.h"
#include "windows.foundation.h"
#include "windows.foundation.metadata.h"
#include "windows.foundation.numerics.h"
#include "windows.gaming.input.custom.h"
#include "windows.gaming.input.forcefeedback.h"
#include "windows.gaming.input.h"
#include "windows.gaming.input.preview.h"
#include "windows.gaming.preview.gamesenumeration.h"
#include "windows.gaming.preview.h"
#include "windows.gaming.ui.h"
#include "windows.gaming.xboxlive.h"
#include "windows.gaming.xboxlive.storage.h"
#include "windows.globalization.collation.h"
#include "windows.globalization.datetimeformatting.h"
#include "windows.globalization.fonts.h"
#include "windows.globalization.h"
#include "windows.globalization.numberformatting.h"
#include "windows.globalization.phonenumberformatting.h"
#include "windows.graphics.capture.h"
#include "windows.graphics.directx.direct3d11.h"
#include "windows.graphics.directx.direct3d11.interop.h"
#include "windows.graphics.directx.h"
#include "windows.graphics.display.core.h"
#include "windows.graphics.display.h"
#include "windows.graphics.display.interop.h"
#include "windows.graphics.effects.h"
#include "windows.graphics.effects.interop.h"
#include "windows.graphics.h"
#include "windows.graphics.holographic.h"
#include "windows.graphics.imaging.h"
#include "windows.graphics.imaging.interop.h"
#include "windows.graphics.interop.h"
#include "windows.graphics.printing.h"
#include "windows.graphics.printing.optiondetails.h"
#include "windows.graphics.printing.printsupport.h"
#include "windows.graphics.printing.printticket.h"
#include "windows.graphics.printing.protectedprint.h"
#include "windows.graphics.printing.workflow.h"
#include "windows.graphics.printing.workflow.native.h"
//#include "windows.graphics.printing.workflow.native.idl"
//#include "windows.graphics.printing3d.h"
#include "windows.management.core.h"
#include "windows.management.deployment.h"
#include "windows.management.deployment.preview.h"
#include "windows.management.h"
#include "windows.management.policies.h"
#include "windows.management.setup.h"
#include "windows.management.update.h"
#include "windows.management.workplace.h"
#include "windows.media.appbroadcasting.h"
#include "windows.media.apprecording.h"
#include "windows.media.audio.h"
#include "windows.media.capture.core.h"
#include "windows.media.capture.frames.h"
#include "windows.media.capture.h"
#include "windows.media.casting.h"
#include "windows.media.closedcaptioning.h"
#include "windows.media.contentrestrictions.h"
#include "windows.media.control.h"
#include "windows.media.core.h"
#include "windows.media.core.interop.h"
#include "windows.media.core.preview.h"
#include "windows.media.devices.core.h"
#include "windows.media.devices.h"
#include "windows.media.dialprotocol.h"
#include "windows.media.editing.h"
#include "windows.media.effects.h"
#include "windows.media.faceanalysis.h"
#include "windows.media.h"
#include "windows.media.import.h"
#include "windows.media.mediaproperties.h"
#include "windows.media.miracast.h"
#include "windows.media.ocr.h"
#include "windows.media.playback.h"
#include "windows.media.playlists.h"
#include "windows.media.playto.h"
#include "windows.media.protection.h"
#include "windows.media.protection.playready.h"
#include "windows.media.render.h"
#include "windows.media.speechrecognition.h"
#include "windows.media.speechsynthesis.h"
#include "windows.media.streaming.adaptive.h"
#include "windows.media.transcoding.h"
#include "windows.networking.backgroundtransfer.h"
#include "windows.networking.connectivity.h"
#include "windows.networking.h"
#include "windows.networking.networkoperators.h"
#include "windows.networking.proximity.h"
#include "windows.networking.pushnotifications.h"
#include "windows.networking.servicediscovery.dnssd.h"
#include "windows.networking.sockets.h"
#include "windows.networking.vpn.h"
#include "windows.networking.xboxlive.h"
#include "windows.perception.automation.core.h"
#include "windows.perception.h"
#include "windows.perception.people.h"
#include "windows.perception.spatial.h"
#include "windows.perception.spatial.preview.h"
#include "windows.perception.spatial.surfaces.h"
#include "windows.phone.h"
#include "windows.phone.networking.voip.h"
#include "windows.phone.startscreen.h"
#include "windows.phone.ui.core.h"
#include "windows.security.authentication.identity.core.h"
#include "windows.security.authentication.identity.h"
#include "windows.security.authentication.identity.provider.h"
#include "windows.security.authentication.onlineid.h"
#include "windows.security.authentication.web.core.h"
#include "windows.security.authentication.web.h"
#include "windows.security.authentication.web.provider.h"
#include "windows.security.authorization.appcapabilityaccess.h"
#include "windows.security.credentials.h"
#include "windows.security.credentials.ui.h"
#include "windows.security.cryptography.certificates.h"
#include "windows.security.cryptography.core.h"
#include "windows.security.cryptography.dataprotection.h"
#include "windows.security.cryptography.h"
#include "windows.security.dataprotection.h"
#include "windows.security.enterprisedata.h"
#include "windows.security.exchangeactivesyncprovisioning.h"
#include "windows.security.isolation.h"
#include "windows.security.isolation.isolatedenvironmentinterop.h"
//#include "windows.security.isolation.isolatedenvironmentinterop.idl"
//#include "windows.services.cortana.h"
#include "windows.services.maps.guidance.h"
#include "windows.services.maps.h"
#include "windows.services.maps.localsearch.h"
#include "windows.services.maps.offlinemaps.h"
#include "windows.services.store.h"
#include "windows.services.targetedcontent.h"
#include "windows.storage.accesscache.h"
#include "windows.storage.bulkaccess.h"
#include "windows.storage.compression.h"
#include "windows.storage.fileproperties.h"
#include "windows.storage.h"
#include "windows.storage.pickers.h"
#include "windows.storage.pickers.provider.h"
#include "windows.storage.provider.h"
#include "windows.storage.search.h"
#include "windows.storage.streams.h"
#include "windows.system.diagnostics.deviceportal.h"
#include "windows.system.diagnostics.h"
#include "windows.system.diagnostics.telemetry.h"
#include "windows.system.diagnostics.tracereporting.h"
#include "windows.system.display.h"
#include "windows.system.h"
#include "windows.system.implementation.fileexplorer.h"
#include "windows.system.inventory.h"
#include "windows.system.power.diagnostics.h"
#include "windows.system.power.h"
#include "windows.system.power.thermal.h"
#include "windows.system.preview.h"
#include "windows.system.profile.h"
#include "windows.system.profile.systemmanufacturers.h"
#include "windows.system.remotedesktop.h"
#include "windows.system.remotedesktop.input.h"
#include "windows.system.remotedesktop.provider.h"
#include "windows.system.remotesystems.h"
#include "windows.system.systemmanagement.h"
#include "windows.system.threading.core.h"
#include "windows.system.threading.h"
#include "windows.system.update.h"
#include "windows.system.userprofile.h"
#include "windows.ui.accessibility.h"
#include "windows.ui.applicationsettings.h"
#include "windows.ui.composition.core.h"
#include "windows.ui.composition.desktop.h"
#include "windows.ui.composition.diagnostics.h"
#include "windows.ui.composition.effects.h"
#include "windows.ui.composition.h"
#include "windows.ui.composition.interactions.h"
#include "windows.ui.composition.interop.h"
#include "windows.ui.composition.scenes.h"
#include "windows.ui.core.animationmetrics.h"
#include "windows.ui.core.corewindowfactory.h"
#include "windows.ui.core.h"
#include "windows.ui.core.preview.h"
#include "windows.ui.h"
#include "windows.ui.input.core.h"
#include "windows.ui.input.h"
#include "windows.ui.input.inking.analysis.h"
#include "windows.ui.input.inking.core.h"
#include "windows.ui.input.inking.h"
#include "windows.ui.input.inking.preview.h"
#include "windows.ui.input.preview.h"
#include "windows.ui.input.preview.injection.h"
#include "windows.ui.input.preview.text.h"
#include "windows.ui.input.spatial.h"
#include "windows.ui.interop.h"
#include "windows.ui.notifications.h"
#include "windows.ui.notifications.management.h"
#include "windows.ui.notifications.preview.h"
#include "windows.ui.popups.h"
#include "windows.ui.shell.companionwindows.h"
#include "windows.ui.shell.h"
#include "windows.ui.shell.tasks.h"
#include "windows.ui.startscreen.h"
#include "windows.ui.text.core.h"
#include "windows.ui.text.h"
#include "windows.ui.uiautomation.core.h"
#include "windows.ui.uiautomation.h"
#include "windows.ui.viewmanagement.core.coreframeworkinputviewinterop.h"
#include "windows.ui.viewmanagement.core.h"
#include "windows.ui.viewmanagement.h"
//#include "windows.ui.webui.core.h"
#include "windows.ui.webui.h"
#include "windows.ui.windowmanagement.h"
#include "windows.ui.windowmanagement.preview.h"
#include "windows.ui.xaml.automation.h"
#include "windows.ui.xaml.automation.peers.h"
#include "windows.ui.xaml.automation.provider.h"
#include "windows.ui.xaml.automation.text.h"
#include "windows.ui.xaml.controls.h"
#include "windows.ui.xaml.controls.maps.h"
#include "windows.ui.xaml.controls.primitives.h"
#include "windows.ui.xaml.core.direct.h"
#include "windows.ui.xaml.data.h"
#include "windows.ui.xaml.documents.h"
#include "windows.ui.xaml.h"
#include "windows.ui.xaml.hosting.desktopwindowxamlsource.h"
#include "windows.ui.xaml.hosting.h"
#include "windows.ui.xaml.hosting.referencetracker.h"
//#include "windows.ui.xaml.hosting.referencetracker.idl"
#include "windows.ui.xaml.input.h"
#include "windows.ui.xaml.interop.h"
#include "windows.ui.xaml.markup.h"
#include "windows.ui.xaml.media.animation.h"
#include "windows.ui.xaml.media.dxinterop.h"
#include "windows.ui.xaml.media.h"
#include "windows.ui.xaml.media.imaging.h"
#include "windows.ui.xaml.media.media3d.h"
#include "windows.ui.xaml.navigation.h"
#include "windows.ui.xaml.printing.h"
#include "windows.ui.xaml.resources.h"
#include "windows.ui.xaml.shapes.h"
#include "windows.web.atompub.h"
#include "windows.web.h"
#include "windows.web.http.diagnostics.h"
#include "windows.web.http.filters.h"
#include "windows.web.http.h"
#include "windows.web.http.headers.h"
#include "windows.web.syndication.h"
#include "windows.web.ui.h"
#include "windows.web.ui.interop.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "windowssideshowdriverevents.h"
#endif
#include "windowsx.h"
#if VS_VER > VC_6
#include "winefs.h"
#endif
#if VS_VER > VS_2005
#include "winevt.h"
#endif   
#if VS_VER > VC_1
#include "wingdi.h"      
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
// redefinition
#include "winhttp.h"
#endif
#if VS_VER > VC_4
#include "wininet.h"
#endif
//#include "winioctl.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "winml.h"
#endif              
#if VS_VER > VC_1
#include "winnetwk.h"
#include "winnt.h" 
#endif
#ifdef WIN32
#define ORIGINAL_WIN32 WIN32
#undef WIN32
#define WIN32 0
#endif
#ifdef _WIN16
// 16 bit code. Keep __pascal. 
#else
#define __pascal __stdcall
#ifndef __export
#define __export
#endif
#endif
#if VS_VERSION > VC_2
#include <tapi.h>
#endif
#ifdef ORIGINAL_WIN32
#undef WIN32
#define WIN32 ORIGINAL_WIN32
#undef ORIGINAL_WIN32
#endif
#if TOOLSET > 90
#define __callback               __allowed(on_function) 
#include "t2embapi.h"
#endif
#if VS_VER > VC_6
#include <tapi3err.h>
#endif
#if VS_VER > VS_2005
//#include "tabdef.idl"
#include "tabflicks.h"
#endif
//#include "tabren.idl"
//#include "taskdeviceservice.h"
#if VS_VER > VS_2005
#include "taskschd.h"
#endif
//#include "tbdefcnt.idl"
//#include "tblcrt.idl"
//#include "tbs.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "tbt3ioctls.h"
#endif
#if VS_VER > VC_6
#include "TCError.h"
#include "TCGuid.h"
#endif
#if VS_VER > VS_2002
#include <strsafe.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <tcpestats.h>
#include <tcpmib.h>
#endif
//#include "tcpioctl.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "tcpxcv.h"
//#include "tdh.h"
//#include "tdi.h"
//#include "tdiinfo.h"
#if (cppver >= 2017) && ((defined NOWARNINGS) || (defined _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING) || (defined _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS))
#include "tgmath.h"
#endif
#endif
#if defined(_MSC_VER) && (_MSC_VER == 1800) // v120 toolset (VS2013)
#include <thread>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <threadpoolapiset.h>
#include <threadpoollegacyapiset.h>
#endif
#if VS_VER > VS_2005
#include "thumbcache.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "thumbnailstreamcache.h"
#endif
#include <time.h>
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <timeapi.h>
#include <timezoneapi.h>
#endif
//#include "tnef.h"
//#include "tokenbinding.h"
#if VS_VER > VS_2005
#include "tpcerror.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if VS_VER > VS_2015
#include "tpmvscattestation.h"
#endif
#include "tpmvscmgr.h"
#include "tpwaitablehandle.h"
#endif
#if TOOLSET > 90
//#include "TSGAuthenticationEngine_i.c"
//#include "TSGPolicyEngine_i.c"
#endif
#if VS_VERSION > VC_2
#include "TSPI.h"
#include "Tapi.h"
#endif
//#include "Tapi3.h"
#if VS_VER > VS_2005 // not found ddraw.h
#include "Tapi3ds.h"
#include "Tapi3if.h"
#include "TimeProv.h"
#endif
#if VS_VER > VS_2005 // no such header
#include "TextStor.h"
#endif
//#include "TipAutoComplete_i.c"
#if VS_VERSION > VC_2
#include "TlHelp32.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "TraceLoggingActivity.h"
#endif
#if VS_VER > VC_5
#include "Transact.h"
#endif
//#include "Tune.h"
#if VS_VER > VC_6
#include "traffic.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "transportsettings.h"
/*#include "trnjoi.idl"
#include "trnlcl.idl"
#include "trnobj.idl"
#include "truadmin.idl"
#include "trugpadm.idl"*/
#if MSVC_VER > 2012
#include "tspubplugin2com.h"
#endif
#endif
#if TOOLSET > 90
#include "tssbx.h"
//#include "tssbx_i.c"
//#include "tsuserex.h"
#endif
//#include "tsuserex_i.c"
#if TOOLSET > 90
#include "tsvirtualchannels.h"
#endif
//#include "tuner.idl"
#if cppver >= 2011
#include <tuple>
#endif
#if VS_VER > VS_2005
#include "txlogpub.h"
#endif
#if NTDDI_VERSION > 0x0A000C00 // v143
#include "typeresolution.h"
#endif
//#include "types.h"
#if VS_VER > VC_6
#include <tvout.h>
#endif
#if VS_VER > VC_5
#include "TxCoord.h"
#include "TxCtx.h"
#include "TxDtc.h"
#endif
#if cppver >= 2011
#include <type_traits>
#endif
//#include "ual.h"
#if MSVC_VER > VS_2013
#include "uchar.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <udpmib.h>
#include <unexposeenums2managed.h>
#endif
#if TOOLSET > 90	  
#include "UIAutomation.h"
#include "UIAutomationClient.h"
#else
#if VS_VER > VS_2005
#include <UIAutomationCore.h>
#endif
#endif
#if VS_VER > VS_2005
#include "UIAutomationCoreApi.h"
#endif
#if TOOLSET > 90
#include "UIRibbonKeydef.h"
#endif
//#include "Unknwn.Idl"
#if VS_VERSION > VC_2
#include "Unknwn.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <unknwnbase.h>
#endif
//#include "unknwnbase.idl"
//#include "urlacc.idl"
//#include "urlaccsdk.idl"
#if VS_VER > VS_2005
#include "upnphost.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "usb.h"
#include "usb100.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "usb4dbgioctl.h"
#endif
#include "usbdi.h"
#if VS_VER > VS_2015
#include "usbfnbase.h"
#endif
#include "usbioctl.h"
#include "usbprint.h"
#include "usbscan.h"
#if VS_VER > VS_2015
#include "useractivityinterop.h"
#endif
#include "usbuser.h"
#if VS_VER > VS_2015
#include "UserConsentVerifierInterop.h"
#endif
#endif	  
#if VS_VER > VC_6
#include "utillib.h"
#endif
//#include "vdscmmn.idl"
//#include "vdscmprv.idl"
#if cppver >= 2011
#include <unordered_map>
#endif
#if VS_VER > VC_4
#include <urlmon.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <usb.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <usbfnbase.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <usbioctl.h>
#include <usbspec.h>
#include <utilapiset.h>
#endif
//#include "usp10.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "utilapiset.h"
#endif
#if VS_VER > VC_4
#include <utility>
#endif
//#include "utime.h"
#if VS_VER > VC_5
#include <uuids.h>      // declaration of type GUIDs and well-known clsids"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "uusbfn.h"
#endif
#define _UXTHEME_H_  	 // fix for VS 2010. Use condition macro if get warnings in higher versions of VS
#if VS_VER > VC_6
#include <uxtheme.h>
#endif
#if VS_VER > VS_2005
#include "vbinterf.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "vdmctxt.h"
#endif
#if VS_VER > VS_2005
#include "vds.h"
#endif
//#include "vds.idl"
//#include "vdshwprv.h"
//#include "vdshwprv.idl"
#if cppver >= 2017
#include <vcruntime.h>
#include <vcruntime_new_debug.h>
#include <vcruntime_startup.h>
#include <vcruntime_string.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "VDDSVC.H"
#endif           
#if VS_VER > VC_1
#include "VdmDbg.h" 
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <vdmctxt.h>
#endif
//#include "vdssys.idl"
#if VS_VER > VS_2005
#include "vdserr.h"
#endif
//#include "veinterop.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "VersionHelpers.h"
#endif
//#include "Vfw.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "vfwext.h"
#endif
#if VS_VER > VS_2005
#include "vidcap.h"
#endif
//#include "virtualaddress.h"
#if VS_VER > VS_2005
#include "vsserror.h"
#endif
//#include "vdshp.idl"
//#include "vdshpcm.idl"
//#include "vdsprvcm.idl"
//#include "vdssp.idl"
//#include "vdsvd.idl"
#if VS_VER > VC_4
#include <vector>
#endif
//#include <veinterop_kcm.h>
//#include <verrsrc.h>
#if cppver > 2017
#include <version>
#endif
#if VS_VER > VS_2005
#include "vmr9.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "vmsavedstatedump.h"
#include "vmsavedstatedumpdefs.h"
#endif
#if VS_VER > VS_2005
#include "vptype.h"
#include "vpconfig.h"
#include "vpnotify.h"
#include "vsadmin.h"
#endif
//#include "vsbackup.h"
#if VS_VER > VS_2005
#include "vsmgmt.h"
#include "vsprov.h"
#include "vssym32.h"
#endif
//#include "vswriter.h"
/*#include "vwchp.idl"
#include "vwflt.idl"
#include "vwrst.idl"
#include "vwsrt.idl"*/
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "WaaSApiTypes.h"
#endif
//#include <wabapi.h>
#if VS_VER > VC_5
#include <wabcode.h>
#endif
//#include <wabdefs.h>
//#include <wabiab.h>
//#include <wabmem.h>
//#include <wabnot.h>

// Mismatch	 #if/#endif in VS2003/2005 because solved */ as ?/
#if VS_VER <= VS_2005
/*
 *  WABTAGS.H
 *
 *  Property tag definitions for standard properties of WAB
 *  objects.
 *
 *  The following ranges should be used for all property IDs. Note that
 *  property IDs for objects other than messages and recipients should
 *  all fall in the range 0x3000 to 0x3FFF:
 *
 *  From    To      Kind of property
 *  --------------------------------
 *  0001    0BFF    MAPI_defined envelope property
 *  0C00    0DFF    MAPI_defined per-recipient property
 *  0E00    0FFF    MAPI_defined non-transmittable property
 *  1000    2FFF    MAPI_defined message content property
 *
 *  3000    3FFF    MAPI_defined property (usually not message or recipient)
 *
 *  4000    57FF    Transport-defined envelope property
 *  5800    5FFF    Transport-defined per-recipient property
 *  6000    65FF    User-defined non-transmittable property
 *  6600    67FF    Provider-defined internal non-transmittable property
 *  6800    7BFF    Message class-defined content property
 *  7C00    7FFF    Message class-defined non-transmittable
 *                  property
 *
 *  8000    FFFE    User-defined Name-to-id mapped property
 *
 *  The 3000-3FFF range is further subdivided as follows:
 *
 *  From    To      Kind of property
 *  --------------------------------
 *  3000    33FF    Common property such as display name, entry ID
 *  3400    35FF    Message store object
 *  3600    36FF    Folder or AB container
 *  3700    38FF    Attachment
 *  3900    39FF    Address book object
 *  3A00    3BFF    Mail user
 *  3C00    3CFF    Distribution list
 *  3D00    3DFF    Profile section
 *  3E00    3FFF    Status object
 *
 *  Copyright 1993-1998 Microsoft Corporation. All Rights Reserved.
 */

#if !defined(MAPITAGS_H) && !defined(WABTAGS_H)
#define WABTAGS_H

 /* Determine if a property is transmittable. */

#define FIsTransmittable(ulPropTag) \
    ((PROP_ID (ulPropTag) <  (ULONG)0x0E00) || \
    (PROP_ID (ulPropTag)  >= (ULONG)0x8000) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x1000) && (PROP_ID (ulPropTag) < (ULONG)0x6000)) || \
    ((PROP_ID (ulPropTag) >= (ULONG)0x6800) && (PROP_ID (ulPropTag) < (ULONG)0x7C00)))


/*
 * The range of non-message and non-recipient property IDs (0x3000 - 0x3FFF) is
 * further broken down into ranges to make assigning new property IDs easier.
 *
 *  From    To      Kind of property
 *  --------------------------------
 *  3000    32FF    MAPI_defined common property
 *  3200    33FF    MAPI_defined form property
 *  3400    35FF    MAPI_defined message store property
 *  3600    36FF    MAPI_defined Folder or AB Container property
 *  3700    38FF    MAPI_defined attachment property
 *  3900    39FF    MAPI_defined address book property
 *  3A00    3BFF    MAPI_defined mailuser property
 *  3C00    3CFF    MAPI_defined DistList property
 *  3D00    3DFF    MAPI_defined Profile Section property
 *  3E00    3EFF    MAPI_defined Status property
 *  3F00    3FFF    MAPI_defined display table property
 */

 /*
  *  Properties common to numerous MAPI objects.
  *
  *  Those properties that can appear on messages are in the
  *  non-transmittable range for messages. They start at the high
  *  end of that range and work down.
  *
  *  Properties that never appear on messages are defined in the common
  *  property range (see above).
  */

  /*
   * properties that are common to multiple objects (including message objects)
   * -- these ids are in the non-transmittable range
   */

#define PR_ENTRYID                                  PROP_TAG( PT_BINARY,    0x0FFF)
#define PR_OBJECT_TYPE                              PROP_TAG( PT_LONG,      0x0FFE)
#define PR_ICON                                     PROP_TAG( PT_BINARY,    0x0FFD)
#define PR_MINI_ICON                                PROP_TAG( PT_BINARY,    0x0FFC)
#define PR_STORE_ENTRYID                            PROP_TAG( PT_BINARY,    0x0FFB)
#define PR_STORE_RECORD_KEY                         PROP_TAG( PT_BINARY,    0x0FFA)
#define PR_RECORD_KEY                               PROP_TAG( PT_BINARY,    0x0FF9)
#define PR_MAPPING_SIGNATURE                        PROP_TAG( PT_BINARY,    0x0FF8)
#define PR_ACCESS_LEVEL                             PROP_TAG( PT_LONG,      0x0FF7)
#define PR_INSTANCE_KEY                             PROP_TAG( PT_BINARY,    0x0FF6)
#define PR_ROW_TYPE                                 PROP_TAG( PT_LONG,      0x0FF5)
#define PR_ACCESS                                   PROP_TAG( PT_LONG,      0x0FF4)

   /*
	* properties that are common to multiple objects (usually not including message objects)
	* -- these ids are in the transmittable range
	*/

#define PR_ROWID                                    PROP_TAG( PT_LONG,      0x3000)
#define PR_DISPLAY_NAME                             PROP_TAG( PT_TSTRING,   0x3001)
#define PR_DISPLAY_NAME_W                           PROP_TAG( PT_UNICODE,   0x3001)
#define PR_DISPLAY_NAME_A                           PROP_TAG( PT_STRING8,   0x3001)
#define PR_ADDRTYPE                                 PROP_TAG( PT_TSTRING,   0x3002)
#define PR_ADDRTYPE_W                               PROP_TAG( PT_UNICODE,   0x3002)
#define PR_ADDRTYPE_A                               PROP_TAG( PT_STRING8,   0x3002)
#define PR_EMAIL_ADDRESS                            PROP_TAG( PT_TSTRING,   0x3003)
#define PR_EMAIL_ADDRESS_W                          PROP_TAG( PT_UNICODE,   0x3003)
#define PR_EMAIL_ADDRESS_A                          PROP_TAG( PT_STRING8,   0x3003)
#define PR_COMMENT                                  PROP_TAG( PT_TSTRING,   0x3004)
#define PR_COMMENT_W                                PROP_TAG( PT_UNICODE,   0x3004)
#define PR_COMMENT_A                                PROP_TAG( PT_STRING8,   0x3004)
#define PR_DEPTH                                    PROP_TAG( PT_LONG,      0x3005)
#define PR_PROVIDER_DISPLAY                         PROP_TAG( PT_TSTRING,   0x3006)
#define PR_PROVIDER_DISPLAY_W                       PROP_TAG( PT_UNICODE,   0x3006)
#define PR_PROVIDER_DISPLAY_A                       PROP_TAG( PT_STRING8,   0x3006)
#define PR_CREATION_TIME                            PROP_TAG( PT_SYSTIME,   0x3007)
#define PR_LAST_MODIFICATION_TIME                   PROP_TAG( PT_SYSTIME,   0x3008)
#define PR_RESOURCE_FLAGS                           PROP_TAG( PT_LONG,      0x3009)
#define PR_PROVIDER_DLL_NAME                        PROP_TAG( PT_TSTRING,   0x300A)
#define PR_PROVIDER_DLL_NAME_W                      PROP_TAG( PT_UNICODE,   0x300A)
#define PR_PROVIDER_DLL_NAME_A                      PROP_TAG( PT_STRING8,   0x300A)
#define PR_SEARCH_KEY                               PROP_TAG( PT_BINARY,    0x300B)
#define PR_PROVIDER_UID                             PROP_TAG( PT_BINARY,    0x300C)
#define PR_PROVIDER_ORDINAL                         PROP_TAG( PT_LONG,      0x300D)


	/* Proptags 35E8-35FF reserved for folders "guaranteed" by PR_VALID_FOLDER_MASK */


	/*
	 *  Folder and AB Container properties
	 */

#define PR_CONTAINER_FLAGS                          PROP_TAG( PT_LONG,      0x3600)
#define PR_FOLDER_TYPE                              PROP_TAG( PT_LONG,      0x3601)
#define PR_CONTENT_COUNT                            PROP_TAG( PT_LONG,      0x3602)
#define PR_CONTENT_UNREAD                           PROP_TAG( PT_LONG,      0x3603)
#define PR_CREATE_TEMPLATES                         PROP_TAG( PT_OBJECT,    0x3604)
#define PR_DETAILS_TABLE                            PROP_TAG( PT_OBJECT,    0x3605)
#define PR_SEARCH                                   PROP_TAG( PT_OBJECT,    0x3607)
#define PR_SELECTABLE                               PROP_TAG( PT_BOOLEAN,   0x3609)
#define PR_SUBFOLDERS                               PROP_TAG( PT_BOOLEAN,   0x360a)
#define PR_STATUS                                   PROP_TAG( PT_LONG,      0x360b)
#define PR_ANR                                      PROP_TAG( PT_TSTRING,   0x360c)
#define PR_ANR_W                                    PROP_TAG( PT_UNICODE,   0x360c)
#define PR_ANR_A                                    PROP_TAG( PT_STRING8,   0x360c)
#define PR_CONTENTS_SORT_ORDER                      PROP_TAG( PT_MV_LONG,   0x360d)
#define PR_CONTAINER_HIERARCHY                      PROP_TAG( PT_OBJECT,    0x360e)
#define PR_CONTAINER_CONTENTS                       PROP_TAG( PT_OBJECT,    0x360f)
#define PR_FOLDER_ASSOCIATED_CONTENTS               PROP_TAG( PT_OBJECT,    0x3610)
#define PR_DEF_CREATE_DL                            PROP_TAG( PT_BINARY,    0x3611)
#define PR_DEF_CREATE_MAILUSER                      PROP_TAG( PT_BINARY,    0x3612)
#define PR_CONTAINER_CLASS                          PROP_TAG( PT_TSTRING,   0x3613)
#define PR_CONTAINER_CLASS_W                        PROP_TAG( PT_UNICODE,   0x3613)
#define PR_CONTAINER_CLASS_A                        PROP_TAG( PT_STRING8,   0x3613)
#define PR_CONTAINER_MODIFY_VERSION                 PROP_TAG( PT_I8,        0x3614)
#define PR_AB_PROVIDER_ID                           PROP_TAG( PT_BINARY,    0x3615)
#define PR_DEFAULT_VIEW_ENTRYID                     PROP_TAG( PT_BINARY,    0x3616)
#define PR_ASSOC_CONTENT_COUNT                      PROP_TAG( PT_LONG,      0x3617)
	 /* Don't use 36FE and 36FF */


	 /*
	  *  AB Object properties
	  */

#define PR_DISPLAY_TYPE                             PROP_TAG( PT_LONG,      0x3900)
#define PR_TEMPLATEID                               PROP_TAG( PT_BINARY,    0x3902)
#define PR_PRIMARY_CAPABILITY                       PROP_TAG( PT_BINARY,    0x3904)
#define PR_7BIT_DISPLAY_NAME                        PROP_TAG( PT_STRING8,   0x39FF)

	  /*
	   *  Mail user properties
	   */

#define PR_ACCOUNT                                  PROP_TAG( PT_TSTRING,   0x3A00)
#define PR_ACCOUNT_W                                PROP_TAG( PT_UNICODE,   0x3A00)
#define PR_ACCOUNT_A                                PROP_TAG( PT_STRING8,   0x3A00)
#define PR_ALTERNATE_RECIPIENT                      PROP_TAG( PT_BINARY,    0x3A01)
#define PR_CALLBACK_TELEPHONE_NUMBER                PROP_TAG( PT_TSTRING,   0x3A02)
#define PR_CALLBACK_TELEPHONE_NUMBER_W              PROP_TAG( PT_UNICODE,   0x3A02)
#define PR_CALLBACK_TELEPHONE_NUMBER_A              PROP_TAG( PT_STRING8,   0x3A02)
#define PR_CONVERSION_PROHIBITED                    PROP_TAG( PT_BOOLEAN,   0x3A03)
#define PR_DISCLOSE_RECIPIENTS                      PROP_TAG( PT_BOOLEAN,   0x3A04)
#define PR_GENERATION                               PROP_TAG( PT_TSTRING,   0x3A05)
#define PR_GENERATION_W                             PROP_TAG( PT_UNICODE,   0x3A05)
#define PR_GENERATION_A                             PROP_TAG( PT_STRING8,   0x3A05)
#define PR_GIVEN_NAME                               PROP_TAG( PT_TSTRING,   0x3A06)
#define PR_GIVEN_NAME_W                             PROP_TAG( PT_UNICODE,   0x3A06)
#define PR_GIVEN_NAME_A                             PROP_TAG( PT_STRING8,   0x3A06)
#define PR_GOVERNMENT_ID_NUMBER                     PROP_TAG( PT_TSTRING,   0x3A07)
#define PR_GOVERNMENT_ID_NUMBER_W                   PROP_TAG( PT_UNICODE,   0x3A07)
#define PR_GOVERNMENT_ID_NUMBER_A                   PROP_TAG( PT_STRING8,   0x3A07)
#define PR_BUSINESS_TELEPHONE_NUMBER                PROP_TAG( PT_TSTRING,   0x3A08)
#define PR_BUSINESS_TELEPHONE_NUMBER_W              PROP_TAG( PT_UNICODE,   0x3A08)
#define PR_BUSINESS_TELEPHONE_NUMBER_A              PROP_TAG( PT_STRING8,   0x3A08)
#define PR_OFFICE_TELEPHONE_NUMBER                  PR_BUSINESS_TELEPHONE_NUMBER
#define PR_OFFICE_TELEPHONE_NUMBER_W                PR_BUSINESS_TELEPHONE_NUMBER_W
#define PR_OFFICE_TELEPHONE_NUMBER_A                PR_BUSINESS_TELEPHONE_NUMBER_A
#define PR_HOME_TELEPHONE_NUMBER                    PROP_TAG( PT_TSTRING,   0x3A09)
#define PR_HOME_TELEPHONE_NUMBER_W                  PROP_TAG( PT_UNICODE,   0x3A09)
#define PR_HOME_TELEPHONE_NUMBER_A                  PROP_TAG( PT_STRING8,   0x3A09)
#define PR_INITIALS                                 PROP_TAG( PT_TSTRING,   0x3A0A)
#define PR_INITIALS_W                               PROP_TAG( PT_UNICODE,   0x3A0A)
#define PR_INITIALS_A                               PROP_TAG( PT_STRING8,   0x3A0A)
#define PR_KEYWORD                                  PROP_TAG( PT_TSTRING,   0x3A0B)
#define PR_KEYWORD_W                                PROP_TAG( PT_UNICODE,   0x3A0B)
#define PR_KEYWORD_A                                PROP_TAG( PT_STRING8,   0x3A0B)
#define PR_LANGUAGE                                 PROP_TAG( PT_TSTRING,   0x3A0C)
#define PR_LANGUAGE_W                               PROP_TAG( PT_UNICODE,   0x3A0C)
#define PR_LANGUAGE_A                               PROP_TAG( PT_STRING8,   0x3A0C)
#define PR_LOCATION                                 PROP_TAG( PT_TSTRING,   0x3A0D)
#define PR_LOCATION_W                               PROP_TAG( PT_UNICODE,   0x3A0D)
#define PR_LOCATION_A                               PROP_TAG( PT_STRING8,   0x3A0D)
#define PR_MAIL_PERMISSION                          PROP_TAG( PT_BOOLEAN,   0x3A0E)
#define PR_MHS_COMMON_NAME                          PROP_TAG( PT_TSTRING,   0x3A0F)
#define PR_MHS_COMMON_NAME_W                        PROP_TAG( PT_UNICODE,   0x3A0F)
#define PR_MHS_COMMON_NAME_A                        PROP_TAG( PT_STRING8,   0x3A0F)
#define PR_ORGANIZATIONAL_ID_NUMBER                 PROP_TAG( PT_TSTRING,   0x3A10)
#define PR_ORGANIZATIONAL_ID_NUMBER_W               PROP_TAG( PT_UNICODE,   0x3A10)
#define PR_ORGANIZATIONAL_ID_NUMBER_A               PROP_TAG( PT_STRING8,   0x3A10)
#define PR_SURNAME                                  PROP_TAG( PT_TSTRING,   0x3A11)
#define PR_SURNAME_W                                PROP_TAG( PT_UNICODE,   0x3A11)
#define PR_SURNAME_A                                PROP_TAG( PT_STRING8,   0x3A11)
#define PR_ORIGINAL_ENTRYID                         PROP_TAG( PT_BINARY,    0x3A12)
#define PR_ORIGINAL_DISPLAY_NAME                    PROP_TAG( PT_TSTRING,   0x3A13)
#define PR_ORIGINAL_DISPLAY_NAME_W                  PROP_TAG( PT_UNICODE,   0x3A13)
#define PR_ORIGINAL_DISPLAY_NAME_A                  PROP_TAG( PT_STRING8,   0x3A13)
#define PR_ORIGINAL_SEARCH_KEY                      PROP_TAG( PT_BINARY,    0x3A14)
#define PR_POSTAL_ADDRESS                           PROP_TAG( PT_TSTRING,   0x3A15)
#define PR_POSTAL_ADDRESS_W                         PROP_TAG( PT_UNICODE,   0x3A15)
#define PR_POSTAL_ADDRESS_A                         PROP_TAG( PT_STRING8,   0x3A15)
#define PR_COMPANY_NAME                             PROP_TAG( PT_TSTRING,   0x3A16)
#define PR_COMPANY_NAME_W                           PROP_TAG( PT_UNICODE,   0x3A16)
#define PR_COMPANY_NAME_A                           PROP_TAG( PT_STRING8,   0x3A16)
#define PR_TITLE                                    PROP_TAG( PT_TSTRING,   0x3A17)
#define PR_TITLE_W                                  PROP_TAG( PT_UNICODE,   0x3A17)
#define PR_TITLE_A                                  PROP_TAG( PT_STRING8,   0x3A17)
#define PR_DEPARTMENT_NAME                          PROP_TAG( PT_TSTRING,   0x3A18)
#define PR_DEPARTMENT_NAME_W                        PROP_TAG( PT_UNICODE,   0x3A18)
#define PR_DEPARTMENT_NAME_A                        PROP_TAG( PT_STRING8,   0x3A18)
#define PR_OFFICE_LOCATION                          PROP_TAG( PT_TSTRING,   0x3A19)
#define PR_OFFICE_LOCATION_W                        PROP_TAG( PT_UNICODE,   0x3A19)
#define PR_OFFICE_LOCATION_A                        PROP_TAG( PT_STRING8,   0x3A19)
#define PR_PRIMARY_TELEPHONE_NUMBER                 PROP_TAG( PT_TSTRING,   0x3A1A)
#define PR_PRIMARY_TELEPHONE_NUMBER_W               PROP_TAG( PT_UNICODE,   0x3A1A)
#define PR_PRIMARY_TELEPHONE_NUMBER_A               PROP_TAG( PT_STRING8,   0x3A1A)
#define PR_BUSINESS2_TELEPHONE_NUMBER               PROP_TAG( PT_TSTRING,   0x3A1B)
#define PR_BUSINESS2_TELEPHONE_NUMBER_W             PROP_TAG( PT_UNICODE,   0x3A1B)
#define PR_BUSINESS2_TELEPHONE_NUMBER_A             PROP_TAG( PT_STRING8,   0x3A1B)
#define PR_OFFICE2_TELEPHONE_NUMBER                 PR_BUSINESS2_TELEPHONE_NUMBER
#define PR_OFFICE2_TELEPHONE_NUMBER_W               PR_BUSINESS2_TELEPHONE_NUMBER_W
#define PR_OFFICE2_TELEPHONE_NUMBER_A               PR_BUSINESS2_TELEPHONE_NUMBER_A
#define PR_MOBILE_TELEPHONE_NUMBER                  PROP_TAG( PT_TSTRING,   0x3A1C)
#define PR_MOBILE_TELEPHONE_NUMBER_W                PROP_TAG( PT_UNICODE,   0x3A1C)
#define PR_MOBILE_TELEPHONE_NUMBER_A                PROP_TAG( PT_STRING8,   0x3A1C)
#define PR_CELLULAR_TELEPHONE_NUMBER                PR_MOBILE_TELEPHONE_NUMBER
#define PR_CELLULAR_TELEPHONE_NUMBER_W              PR_MOBILE_TELEPHONE_NUMBER_W
#define PR_CELLULAR_TELEPHONE_NUMBER_A              PR_MOBILE_TELEPHONE_NUMBER_A
#define PR_RADIO_TELEPHONE_NUMBER                   PROP_TAG( PT_TSTRING,   0x3A1D)
#define PR_RADIO_TELEPHONE_NUMBER_W                 PROP_TAG( PT_UNICODE,   0x3A1D)
#define PR_RADIO_TELEPHONE_NUMBER_A                 PROP_TAG( PT_STRING8,   0x3A1D)
#define PR_CAR_TELEPHONE_NUMBER                     PROP_TAG( PT_TSTRING,   0x3A1E)
#define PR_CAR_TELEPHONE_NUMBER_W                   PROP_TAG( PT_UNICODE,   0x3A1E)
#define PR_CAR_TELEPHONE_NUMBER_A                   PROP_TAG( PT_STRING8,   0x3A1E)
#define PR_OTHER_TELEPHONE_NUMBER                   PROP_TAG( PT_TSTRING,   0x3A1F)
#define PR_OTHER_TELEPHONE_NUMBER_W                 PROP_TAG( PT_UNICODE,   0x3A1F)
#define PR_OTHER_TELEPHONE_NUMBER_A                 PROP_TAG( PT_STRING8,   0x3A1F)
#define PR_TRANSMITABLE_DISPLAY_NAME                PROP_TAG( PT_TSTRING,   0x3A20)
#define PR_TRANSMITABLE_DISPLAY_NAME_W              PROP_TAG( PT_UNICODE,   0x3A20)
#define PR_TRANSMITABLE_DISPLAY_NAME_A              PROP_TAG( PT_STRING8,   0x3A20)
#define PR_PAGER_TELEPHONE_NUMBER                   PROP_TAG( PT_TSTRING,   0x3A21)
#define PR_PAGER_TELEPHONE_NUMBER_W                 PROP_TAG( PT_UNICODE,   0x3A21)
#define PR_PAGER_TELEPHONE_NUMBER_A                 PROP_TAG( PT_STRING8,   0x3A21)
#define PR_BEEPER_TELEPHONE_NUMBER                  PR_PAGER_TELEPHONE_NUMBER
#define PR_BEEPER_TELEPHONE_NUMBER_W                PR_PAGER_TELEPHONE_NUMBER_W
#define PR_BEEPER_TELEPHONE_NUMBER_A                PR_PAGER_TELEPHONE_NUMBER_A
#define PR_USER_CERTIFICATE                         PROP_TAG( PT_BINARY,    0x3A22)
#define PR_PRIMARY_FAX_NUMBER                       PROP_TAG( PT_TSTRING,   0x3A23)
#define PR_PRIMARY_FAX_NUMBER_W                     PROP_TAG( PT_UNICODE,   0x3A23)
#define PR_PRIMARY_FAX_NUMBER_A                     PROP_TAG( PT_STRING8,   0x3A23)
#define PR_BUSINESS_FAX_NUMBER                      PROP_TAG( PT_TSTRING,   0x3A24)
#define PR_BUSINESS_FAX_NUMBER_W                    PROP_TAG( PT_UNICODE,   0x3A24)
#define PR_BUSINESS_FAX_NUMBER_A                    PROP_TAG( PT_STRING8,   0x3A24)
#define PR_HOME_FAX_NUMBER                          PROP_TAG( PT_TSTRING,   0x3A25)
#define PR_HOME_FAX_NUMBER_W                        PROP_TAG( PT_UNICODE,   0x3A25)
#define PR_HOME_FAX_NUMBER_A                        PROP_TAG( PT_STRING8,   0x3A25)
#define PR_COUNTRY                                  PROP_TAG( PT_TSTRING,   0x3A26)
#define PR_COUNTRY_W                                PROP_TAG( PT_UNICODE,   0x3A26)
#define PR_COUNTRY_A                                PROP_TAG( PT_STRING8,   0x3A26)
#define PR_LOCALITY                                 PROP_TAG( PT_TSTRING,   0x3A27)
#define PR_LOCALITY_W                               PROP_TAG( PT_UNICODE,   0x3A27)
#define PR_LOCALITY_A                               PROP_TAG( PT_STRING8,   0x3A27)
#define PR_STATE_OR_PROVINCE                        PROP_TAG( PT_TSTRING,   0x3A28)
#define PR_STATE_OR_PROVINCE_W                      PROP_TAG( PT_UNICODE,   0x3A28)
#define PR_STATE_OR_PROVINCE_A                      PROP_TAG( PT_STRING8,   0x3A28)
#define PR_STREET_ADDRESS                           PROP_TAG( PT_TSTRING,   0x3A29)
#define PR_STREET_ADDRESS_W                         PROP_TAG( PT_UNICODE,   0x3A29)
#define PR_STREET_ADDRESS_A                         PROP_TAG( PT_STRING8,   0x3A29)
#define PR_POSTAL_CODE                              PROP_TAG( PT_TSTRING,   0x3A2A)
#define PR_POSTAL_CODE_W                            PROP_TAG( PT_UNICODE,   0x3A2A)
#define PR_POSTAL_CODE_A                            PROP_TAG( PT_STRING8,   0x3A2A)
#define PR_POST_OFFICE_BOX                          PROP_TAG( PT_TSTRING,   0x3A2B)
#define PR_POST_OFFICE_BOX_W                        PROP_TAG( PT_UNICODE,   0x3A2B)
#define PR_POST_OFFICE_BOX_A                        PROP_TAG( PT_STRING8,   0x3A2B)
#define PR_BUSINESS_ADDRESS_POST_OFFICE_BOX         PR_POST_OFFICE_BOX
#define PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_W       PR_POST_OFFICE_BOX_W
#define PR_BUSINESS_ADDRESS_POST_OFFICE_BOX_A       PR_POST_OFFICE_BOX_A
#define PR_TELEX_NUMBER                             PROP_TAG( PT_TSTRING,   0x3A2C)
#define PR_TELEX_NUMBER_W                           PROP_TAG( PT_UNICODE,   0x3A2C)
#define PR_TELEX_NUMBER_A                           PROP_TAG( PT_STRING8,   0x3A2C)
#define PR_ISDN_NUMBER                              PROP_TAG( PT_TSTRING,   0x3A2D)
#define PR_ISDN_NUMBER_W                            PROP_TAG( PT_UNICODE,   0x3A2D)
#define PR_ISDN_NUMBER_A                            PROP_TAG( PT_STRING8,   0x3A2D)
#define PR_ASSISTANT_TELEPHONE_NUMBER               PROP_TAG( PT_TSTRING,   0x3A2E)
#define PR_ASSISTANT_TELEPHONE_NUMBER_W             PROP_TAG( PT_UNICODE,   0x3A2E)
#define PR_ASSISTANT_TELEPHONE_NUMBER_A             PROP_TAG( PT_STRING8,   0x3A2E)
#define PR_HOME2_TELEPHONE_NUMBER                   PROP_TAG( PT_TSTRING,   0x3A2F)
#define PR_HOME2_TELEPHONE_NUMBER_W                 PROP_TAG( PT_UNICODE,   0x3A2F)
#define PR_HOME2_TELEPHONE_NUMBER_A                 PROP_TAG( PT_STRING8,   0x3A2F)
#define PR_ASSISTANT                                PROP_TAG( PT_TSTRING,   0x3A30)
#define PR_ASSISTANT_W                              PROP_TAG( PT_UNICODE,   0x3A30)
#define PR_ASSISTANT_A                              PROP_TAG( PT_STRING8,   0x3A30)
#define PR_SEND_RICH_INFO                           PROP_TAG( PT_BOOLEAN,   0x3A40)
#define PR_WEDDING_ANNIVERSARY                      PROP_TAG( PT_SYSTIME,   0x3A41)
#define PR_BIRTHDAY                                 PROP_TAG( PT_SYSTIME,   0x3A42)
#define PR_HOBBIES                                  PROP_TAG( PT_TSTRING,   0x3A43)
#define PR_HOBBIES_W                                PROP_TAG( PT_UNICODE,   0x3A43)
#define PR_HOBBIES_A                                PROP_TAG( PT_STRING8,   0x3A43)
#define PR_MIDDLE_NAME                              PROP_TAG( PT_TSTRING,   0x3A44)
#define PR_MIDDLE_NAME_W                            PROP_TAG( PT_UNICODE,   0x3A44)
#define PR_MIDDLE_NAME_A                            PROP_TAG( PT_STRING8,   0x3A44)
#define PR_DISPLAY_NAME_PREFIX                      PROP_TAG( PT_TSTRING,   0x3A45)
#define PR_DISPLAY_NAME_PREFIX_W                    PROP_TAG( PT_UNICODE,   0x3A45)
#define PR_DISPLAY_NAME_PREFIX_A                    PROP_TAG( PT_STRING8,   0x3A45)
#define PR_PROFESSION                               PROP_TAG( PT_TSTRING,   0x3A46)
#define PR_PROFESSION_W                             PROP_TAG( PT_UNICODE,   0x3A46)
#define PR_PROFESSION_A                             PROP_TAG( PT_STRING8,   0x3A46)
#define PR_PREFERRED_BY_NAME                        PROP_TAG( PT_TSTRING,   0x3A47)
#define PR_PREFERRED_BY_NAME_W                      PROP_TAG( PT_UNICODE,   0x3A47)
#define PR_PREFERRED_BY_NAME_A                      PROP_TAG( PT_STRING8,   0x3A47)
#define PR_SPOUSE_NAME                              PROP_TAG( PT_TSTRING,   0x3A48)
#define PR_SPOUSE_NAME_W                            PROP_TAG( PT_UNICODE,   0x3A48)
#define PR_SPOUSE_NAME_A                            PROP_TAG( PT_STRING8,   0x3A48)
#define PR_COMPUTER_NETWORK_NAME                    PROP_TAG( PT_TSTRING,   0x3A49)
#define PR_COMPUTER_NETWORK_NAME_W                  PROP_TAG( PT_UNICODE,   0x3A49)
#define PR_COMPUTER_NETWORK_NAME_A                  PROP_TAG( PT_STRING8,   0x3A49)
#define PR_CUSTOMER_ID                              PROP_TAG( PT_TSTRING,   0x3A4A)
#define PR_CUSTOMER_ID_W                            PROP_TAG( PT_UNICODE,   0x3A4A)
#define PR_CUSTOMER_ID_A                            PROP_TAG( PT_STRING8,   0x3A4A)
#define PR_TTYTDD_PHONE_NUMBER                      PROP_TAG( PT_TSTRING,   0x3A4B)
#define PR_TTYTDD_PHONE_NUMBER_W                    PROP_TAG( PT_UNICODE,   0x3A4B)
#define PR_TTYTDD_PHONE_NUMBER_A                    PROP_TAG( PT_STRING8,   0x3A4B)
#define PR_FTP_SITE                                 PROP_TAG( PT_TSTRING,   0x3A4C)
#define PR_FTP_SITE_W                               PROP_TAG( PT_UNICODE,   0x3A4C)
#define PR_FTP_SITE_A                               PROP_TAG( PT_STRING8,   0x3A4C)
#define PR_GENDER                                   PROP_TAG( PT_SHORT,     0x3A4D)
#define PR_MANAGER_NAME                             PROP_TAG( PT_TSTRING,   0x3A4E)
#define PR_MANAGER_NAME_W                           PROP_TAG( PT_UNICODE,   0x3A4E)
#define PR_MANAGER_NAME_A                           PROP_TAG( PT_STRING8,   0x3A4E)
#define PR_NICKNAME                                 PROP_TAG( PT_TSTRING,   0x3A4F)
#define PR_NICKNAME_W                               PROP_TAG( PT_UNICODE,   0x3A4F)
#define PR_NICKNAME_A                               PROP_TAG( PT_STRING8,   0x3A4F)
#define PR_PERSONAL_HOME_PAGE                       PROP_TAG( PT_TSTRING,   0x3A50)
#define PR_PERSONAL_HOME_PAGE_W                     PROP_TAG( PT_UNICODE,   0x3A50)
#define PR_PERSONAL_HOME_PAGE_A                     PROP_TAG( PT_STRING8,   0x3A50)
#define PR_BUSINESS_HOME_PAGE                       PROP_TAG( PT_TSTRING,   0x3A51)
#define PR_BUSINESS_HOME_PAGE_W                     PROP_TAG( PT_UNICODE,   0x3A51)
#define PR_BUSINESS_HOME_PAGE_A                     PROP_TAG( PT_STRING8,   0x3A51)
#define PR_CONTACT_VERSION                          PROP_TAG( PT_CLSID,     0x3A52)
#define PR_CONTACT_ENTRYIDS                         PROP_TAG( PT_MV_BINARY, 0x3A53)
#define PR_CONTACT_ADDRTYPES                        PROP_TAG( PT_MV_TSTRING, 0x3A54)
#define PR_CONTACT_ADDRTYPES_W                      PROP_TAG( PT_MV_UNICODE, 0x3A54)
#define PR_CONTACT_ADDRTYPES_A                      PROP_TAG( PT_MV_STRING8, 0x3A54)
#define PR_CONTACT_DEFAULT_ADDRESS_INDEX            PROP_TAG( PT_LONG,      0x3A55)
#define PR_CONTACT_EMAIL_ADDRESSES                  PROP_TAG( PT_MV_TSTRING, 0x3A56)
#define PR_CONTACT_EMAIL_ADDRESSES_W                PROP_TAG( PT_MV_UNICODE, 0x3A56)
#define PR_CONTACT_EMAIL_ADDRESSES_A                PROP_TAG( PT_MV_STRING8, 0x3A56)
#define PR_COMPANY_MAIN_PHONE_NUMBER                PROP_TAG( PT_TSTRING,   0x3A57)
#define PR_COMPANY_MAIN_PHONE_NUMBER_W              PROP_TAG( PT_UNICODE,   0x3A57)
#define PR_COMPANY_MAIN_PHONE_NUMBER_A              PROP_TAG( PT_STRING8,   0x3A57)
#define PR_CHILDRENS_NAMES                          PROP_TAG( PT_MV_TSTRING, 0x3A58)
#define PR_CHILDRENS_NAMES_W                        PROP_TAG( PT_MV_UNICODE, 0x3A58)
#define PR_CHILDRENS_NAMES_A                        PROP_TAG( PT_MV_STRING8, 0x3A58)
#define PR_HOME_ADDRESS_CITY                        PROP_TAG( PT_TSTRING,   0x3A59)
#define PR_HOME_ADDRESS_CITY_W                      PROP_TAG( PT_UNICODE,   0x3A59)
#define PR_HOME_ADDRESS_CITY_A                      PROP_TAG( PT_STRING8,   0x3A59)
#define PR_HOME_ADDRESS_COUNTRY                     PROP_TAG( PT_TSTRING,   0x3A5A)
#define PR_HOME_ADDRESS_COUNTRY_W                   PROP_TAG( PT_UNICODE,   0x3A5A)
#define PR_HOME_ADDRESS_COUNTRY_A                   PROP_TAG( PT_STRING8,   0x3A5A)
#define PR_HOME_ADDRESS_POSTAL_CODE                 PROP_TAG( PT_TSTRING,   0x3A5B)
#define PR_HOME_ADDRESS_POSTAL_CODE_W               PROP_TAG( PT_UNICODE,   0x3A5B)
#define PR_HOME_ADDRESS_POSTAL_CODE_A               PROP_TAG( PT_STRING8,   0x3A5B)
#define PR_HOME_ADDRESS_STATE_OR_PROVINCE           PROP_TAG( PT_TSTRING,   0x3A5C)
#define PR_HOME_ADDRESS_STATE_OR_PROVINCE_W         PROP_TAG( PT_UNICODE,   0x3A5C)
#define PR_HOME_ADDRESS_STATE_OR_PROVINCE_A         PROP_TAG( PT_STRING8,   0x3A5C)
#define PR_HOME_ADDRESS_STREET                      PROP_TAG( PT_TSTRING,   0x3A5D)
#define PR_HOME_ADDRESS_STREET_W                    PROP_TAG( PT_UNICODE,   0x3A5D)
#define PR_HOME_ADDRESS_STREET_A                    PROP_TAG( PT_STRING8,   0x3A5D)
#define PR_HOME_ADDRESS_POST_OFFICE_BOX             PROP_TAG( PT_TSTRING,   0x3A5E)
#define PR_HOME_ADDRESS_POST_OFFICE_BOX_W           PROP_TAG( PT_UNICODE,   0x3A5E)
#define PR_HOME_ADDRESS_POST_OFFICE_BOX_A           PROP_TAG( PT_STRING8,   0x3A5E)
#define PR_OTHER_ADDRESS_CITY                       PROP_TAG( PT_TSTRING,   0x3A5F)
#define PR_OTHER_ADDRESS_CITY_W                     PROP_TAG( PT_UNICODE,   0x3A5F)
#define PR_OTHER_ADDRESS_CITY_A                     PROP_TAG( PT_STRING8,   0x3A5F)
#define PR_OTHER_ADDRESS_COUNTRY                    PROP_TAG( PT_TSTRING,   0x3A60)
#define PR_OTHER_ADDRESS_COUNTRY_W                  PROP_TAG( PT_UNICODE,   0x3A60)
#define PR_OTHER_ADDRESS_COUNTRY_A                  PROP_TAG( PT_STRING8,   0x3A60)
#define PR_OTHER_ADDRESS_POSTAL_CODE                PROP_TAG( PT_TSTRING,   0x3A61)
#define PR_OTHER_ADDRESS_POSTAL_CODE_W              PROP_TAG( PT_UNICODE,   0x3A61)
#define PR_OTHER_ADDRESS_POSTAL_CODE_A              PROP_TAG( PT_STRING8,   0x3A61)
#define PR_OTHER_ADDRESS_STATE_OR_PROVINCE          PROP_TAG( PT_TSTRING,   0x3A62)
#define PR_OTHER_ADDRESS_STATE_OR_PROVINCE_W        PROP_TAG( PT_UNICODE,   0x3A62)
#define PR_OTHER_ADDRESS_STATE_OR_PROVINCE_A        PROP_TAG( PT_STRING8,   0x3A62)
#define PR_OTHER_ADDRESS_STREET                     PROP_TAG( PT_TSTRING,   0x3A63)
#define PR_OTHER_ADDRESS_STREET_W                   PROP_TAG( PT_UNICODE,   0x3A63)
#define PR_OTHER_ADDRESS_STREET_A                   PROP_TAG( PT_STRING8,   0x3A63)
#define PR_OTHER_ADDRESS_POST_OFFICE_BOX            PROP_TAG( PT_TSTRING,   0x3A64)
#define PR_OTHER_ADDRESS_POST_OFFICE_BOX_W          PROP_TAG( PT_UNICODE,   0x3A64)
#define PR_OTHER_ADDRESS_POST_OFFICE_BOX_A          PROP_TAG( PT_STRING8,   0x3A64)
#define PR_USER_X509_CERTIFICATE                    PROP_TAG( PT_MV_BINARY, 0x3A70)
#define PR_SEND_INTERNET_ENCODING                   PROP_TAG( PT_LONG,      0x3A71)



#define PR_BUSINESS_ADDRESS_CITY                    PR_LOCALITY
#define PR_BUSINESS_ADDRESS_COUNTRY                 PR_COUNTRY
#define PR_BUSINESS_ADDRESS_POSTAL_CODE             PR_POSTAL_CODE
#define PR_BUSINESS_ADDRESS_STATE_OR_PROVINCE       PR_STATE_OR_PROVINCE
#define PR_BUSINESS_ADDRESS_STREET                  PR_STREET_ADDRESS


	   /*
		*	Message recipient properties
		*/

#define PR_RECIPIENT_TYPE                           PROP_TAG( PT_LONG,      0x0C15)

		/*
		 * Secure property id range
		 */

#define PROP_ID_SECURE_MIN                          0x67F0
#define PROP_ID_SECURE_MAX                          0x67FF


		 /* These are the bits that show up in PR_SEND_INTERNET_ENCODING */

		 /* whether or not an encoding preference is specified
		 1 - pay attention to the rest of the bits for the encoding preferences
		 0 - let the mail system choose what's best for it
		 */
#define ENCODING_PREFERENCE                     ((ULONG) 0x00020000)

		 /*
		 1 - message in MIME;
		 0 - plain text/uuencode attachments
		 */
#define ENCODING_TEXT                           ((ULONG) 0x00000000)
#define ENCODING_MIME                           ((ULONG) 0x00040000)


		 /*Specifies how the body of the message is encoded.
		 00 - Body encoded as text
		 01 - body encoded as HTML (only valid if message in MIME)
		 10 - (actualy 1X) Text and HTML as multipart alternative (only valid if message in MIME)
		 */
#define BODY_ENCODING_MASK                      ((ULONG) 0x00180000)
#define BODY_ENCODING_TEXT                      ((ULONG) 0x00000000) /* for completeness */
#define BODY_ENCODING_HTML                      ((ULONG) 0x00080000)
#define BODY_ENCODING_TEXT_AND_HTML             ((ULONG) 0x00100000)

		 /*Specifies how to handle Mac attachments
		 00 - BinHex
		 01 - UUENCODED (not valid if message in MIME - will be ignored, BinHex used instead)
		 10 - Apple Single (only valid if message in MIME)
		 11 - Apple Double (only valid if message in MIME)
		 */
#define MAC_ATTACH_ENCODING_MASK                ((ULONG) 0x00600000)
#define MAC_ATTACH_ENCODING_BINHEX              ((ULONG) 0x00000000)
#define MAC_ATTACH_ENCODING_UUENCODE            ((ULONG) 0x00200000)
#define MAC_ATTACH_ENCODING_APPLESINGLE         ((ULONG) 0x00400000)
#define MAC_ATTACH_ENCODING_APPLEDOUBLE         ((ULONG) 0x00600000)


		 // Values for PR_GENDER property
enum Gender {
	genderUnspecified = 0,
	genderFemale,
	genderMale
};

#endif  /* WABTAGS_H */

#else
#include <wabtags.h>
#endif
//#include <wabutil.h>
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "warning.h"
#endif
//#include <wbcl.h>
#if VS_VER > VC_6
#include "WbemAds.h"
#endif
//#include <wbemcli.h>
#if VS_VER > VC_6
#include "wbemdisp.h"
#endif
//#include "FwCommon.h"
//#include "wbemglue.h"
#if VS_VER > VC_6
#include "WbemIdl.h"
#include "WbemProv.h"
#include "WbemTime.h"
#include "WbemTran.h"
#endif          
#if VS_VER > VC_1
#include <wchar.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <widemath.h>                // 64-bit and 128-bit math helper functions"
#endif
//#include "wcmapi.h"
//#include "wcmconfig.h"
//#include "wcmconfig.idl"
#if VS_VER > VS_2005
#include "wcmerrors.h"
#endif
#if TOOLSET > 90
#include "WcnApi.h"
#include "WcnDevice.h"
#include "WcnFunctionDiscoveryKeys.h"
#endif
#if VS_VER > VS_2005
#include "wcsplugin.h"
#include "wct.h"
#endif
#if VS_VER > VC_4
#include "wctype.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "WDBGEXTS.H"
#endif
#if VS_VER > VS_2005
#include "wdigest.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wdmguid.h"
#endif
//#include "wdspxe.h"
#if TOOLSET > 90
#include "wdstci.h"
#include "wdstpdi.h"
#include "WdsBp.h"
#include "WdsTptMgmt.h"
//#include "WdsTptMgmt_i.c"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include <weakreference.h>
#include "webapplication.h"
#endif
//#include "webauthn.h"
//#include "webauthnplugin.h"
//#include "webhost.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "websocket.h"
#if VS_VER > VS_2015
#include "WebAuthenticationCoreManagerInterop.h"
#endif
#endif
//#include "wheadef.h"
#if VS_VER > VC_6
#include "wia.h"
#include "wiadef.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wiaintfc.h"
#include "wiamicro.h"
#include "wiamindr.h"
#include "wiamindr_lh.h"
//#if winver<=Windows_XP
#if 0
#include "wiamindr_xp.h"
#endif
#include "wiatwcmp.h"
#endif
//#include "wiautil.h"
#if VS_VER > VS_2005
#include "wiawsdsc.h"
#endif
//#include "winbase.inl" 
#if VS_VER > VC_1
#include "WinBase.h"
#endif
//#include "WinBer.h"
//#include "winbio_adapter.h"
//#include "winbio_ioctl.h"
#if VS_VER > VS_2005
#include "wincodecsdk.h"
#include "WinFax.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <winapifamily.h>
#endif            
#if VS_VER > VC_1
#include <winbase.h>
#endif
#if TOOLSET > 90
#include "winbio_err.h"
#include "winbio_types.h"
#endif             
#if VS_VER > VC_1
#include <wincon.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "wincontypes.h"
//#include "wincred.h"
//#include "wincrypt.idl"
//#include "winddi.h"
#include "winddiui.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "windnsdef.h"
#endif
#if VS_VER > VS_2005
#include "windot11.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "Windows.ApplicationModel.Infrastructure.h"
#include "Windows.ApplicationModel.resources.management.h"
#if VS_VER > VS_2015
#include "Windows.ApplicationModel.store.preview.installcontrol.h"
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "Windows.Graphics.Display.DisplayEnhancementOverride.Interop.h"
#endif
#include "Windows.Graphics.Holographic.Interop.h"
//#include "Windows.Graphics.Holographic.Interop.idl"
#include "Windows.Media.Protection.PlayReadyErrors.h"
#endif
#if MSVC_VER > 2012
#include "Windows.Media.Streaming.Devices.h"
#endif
#if VS_VER > VS_2015
#include "Windows.Media.Streaming.Internal.h"
#include "Windows.Services.TargetedContent.h"
#endif
#include "WindowsCeip.h"
#if VS_VER > VS_2015
#include "windowscontracts.h"
#endif
#endif
#if VS_VER > VS_2005
#include "WindowsDefender.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "WindowsNumerics.h"
#endif
#if VS_VER > VS_2005
#include "WindowsSideShow.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if 0
typedef VOID* WHV_EMULATOR_HANDLE;
#include "WinHvEmulation.h"
#endif
#endif             
#if VS_VER > VC_1
#include "WinNls.h"
#endif
#if VS_VER > VC_4
#include "WinNls32.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "WinPhoneInput.h"
#include "WinRTBase.h"
#endif
#if NTDDI_VERSION >= 0x0A000010 // 10.0.26100.0
#include "WinRTRTTI.h"
#endif
#if VS_VER > VC_5
#include "winsmcrd.h"
#include "WinSnmp.h"
#endif
#if VS_VER == VC_6
//wintrust.h(139) : error C2143: syntax error : missing ';' before '*'
// from wincrypt.h
// definitions for the next definitions
typedef struct _CRYPT_ATTRIBUTE {
	LPSTR               pszObjId;
	DWORD               cValue;
	PCRYPT_ATTR_BLOB    rgValue;
} CRYPT_ATTRIBUTE, * PCRYPT_ATTRIBUTE;
typedef struct _CRYPT_ATTRIBUTES {
	DWORD                cAttr;
	PCRYPT_ATTRIBUTE     rgAttr;
} CRYPT_ATTRIBUTES, * PCRYPT_ATTRIBUTES;
typedef struct _CRYPT_BIT_BLOB {
	DWORD   cbData;
	BYTE* pbData;
	DWORD   cUnusedBits;
} CRYPT_BIT_BLOB, * PCRYPT_BIT_BLOB;
typedef struct _CERT_PUBLIC_KEY_INFO {
	CRYPT_ALGORITHM_IDENTIFIER    Algorithm;
	CRYPT_BIT_BLOB                PublicKey;
} CERT_PUBLIC_KEY_INFO, * PCERT_PUBLIC_KEY_INFO;
typedef struct _CERT_EXTENSION {
	LPSTR               pszObjId;
	BOOL                fCritical;
	CRYPT_OBJID_BLOB    Value;
} CERT_EXTENSION, * PCERT_EXTENSION;
typedef struct _CERT_INFO {
	DWORD                       dwVersion;
	CRYPT_INTEGER_BLOB          SerialNumber;
	CRYPT_ALGORITHM_IDENTIFIER  SignatureAlgorithm;
	CERT_NAME_BLOB              Issuer;
	FILETIME                    NotBefore;
	FILETIME                    NotAfter;
	CERT_NAME_BLOB              Subject;
	CERT_PUBLIC_KEY_INFO        SubjectPublicKeyInfo;
	CRYPT_BIT_BLOB              IssuerUniqueId;
	CRYPT_BIT_BLOB              SubjectUniqueId;
	DWORD                       cExtension;
	PCERT_EXTENSION             rgExtension;
} CERT_INFO, * PCERT_INFO;
typedef void* HCERTSTORE;
typedef struct _CERT_CONTEXT {
	DWORD                   dwCertEncodingType;
	BYTE* pbCertEncoded;
	DWORD                   cbCertEncoded;
	PCERT_INFO              pCertInfo;
	HCERTSTORE              hCertStore;
} CERT_CONTEXT, * PCERT_CONTEXT;
typedef const CERT_CONTEXT* PCCERT_CONTEXT;
typedef void* HCRYPTMSG;
// definitions for WinTrust.h
typedef struct _CMSG_SIGNER_INFO {
	DWORD                       dwVersion;
	CERT_NAME_BLOB              Issuer;
	CRYPT_INTEGER_BLOB          SerialNumber;
	CRYPT_ALGORITHM_IDENTIFIER  HashAlgorithm;

	// This is also referred to as the SignatureAlgorithm
	CRYPT_ALGORITHM_IDENTIFIER  HashEncryptionAlgorithm;

	CRYPT_DATA_BLOB             EncryptedHash;
	CRYPT_ATTRIBUTES            AuthAttrs;
	CRYPT_ATTRIBUTES            UnauthAttrs;
} CMSG_SIGNER_INFO, * PCMSG_SIGNER_INFO;
typedef void* HCERTSTORE;
#endif
#if VS_VER > VC_4
#include "WinTrust.h"
#endif               
#if VS_VER > VC_1
#include "WinUser.h"
#endif
//#include "winuser.inl"
#if VS_VERSION > VC_2
#include "WinWlx.h"
#endif
#if VS_VER > VC_6
#include "WMIUtils.h"
#endif               
#if VS_VER > VC_1
#include "WowNT32.h"
#endif
#if TOOLSET > 90
#include "WpdMtpExtensions.h"
#include "WpdShellExtension.h"
#endif
//#include "WS2atm.h"
//#include "WS2spi.h"
//#include "WS2tcpip.h"
#if VS_VER > VS_2005
#include "Wsdapi.h"
#include "Wsdattachment.h"
#include "Wsdbase.h"
#include "Wsdclient.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "Wsdevlicensing.h"
#endif
#include "Wsddisco.h"
#include "Wsdhost.h"
#include "Wsdutil.h"
#include "Wsdtypes.h"
#include "Wsdns.h"
#include "wsdtypes.h"
#include "Wsdxml.h"
#include "wsdxmldom.h"
#endif   
#if VS_VER > VC_1
#include "WSNwLink.h"
#endif
//#include "WSPiApi.h"  
#if VS_VER > VC_1
#include "WShisotp.h"
#include "WSipx.h"
#include "WSnetbs.h"  
#endif
#if VS_VER > VC_4
#include "WSvns.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wtypesbase.h"
#endif
#if VS_VER > VS_2005
#include "Xinput.h"
#endif
//#include "xmldom.idl"
#if VS_VER > VC_6
#include "xmldomdid.h"
#endif
//#include "xmldso.idl"
#if VS_VER > VC_6
#include "xmldsodid.h"
#endif
//#include "_dbdao.h"
//#include "access.idl"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#if VS_VER > VS_2015
#include "accountssettingspaneinterop.h"
#endif
#include "activation.h"
#include "activationregistration.h"
#endif
#if VS_VER > VS_2005
#include "activecf.h"
#endif
#if TOOLSET > 90
#include "activprof.h"
#endif
#if VS_VER > VC_6
#include "adc.h"
#endif
//#include "adoctint.h"
//#include "adogpool.h"
#if VS_VER > VC_5
#include "ADSIid.h"
#endif
#if VS_VER > VC_6
#include "AF_Irda.h"
#endif
#if VS_VER > VC_4
#include "AccCtrl.h"
#endif
#if VS_VER > VC_5
#include "ActiveDS.h"
#include "AdsErr.h"
#include "AdsHlp.h"
#endif
#if VS_VER > VC_6
#include "AdsProp.h"
#endif
#if VS_VER > VC_5
#include "Adsnms.h"
#include "Adssts.h"
#endif
#if VS_VER > VC_6
#include "AdtGen.h"
#include "Authif.h"
#endif
#if VS_VER > VC_5
#include "AviFmt.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "DLNADeviceInterfaceIds.h"
#include "DLNAMetadataProviderProperties.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <wincontypes.h>
#endif
//#include <winddi.h>
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <windnsdef.h>
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <windot11.h>
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <windows.foundation.collections.h>
#include <windows.foundation.diagnostics.h>
#include <windows.foundation.h>
#include <windows.storage.streams.h>
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include <windows.graphics.capture.h>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <windows.graphics.effects.h>
#endif
#include <windowsx.h>
#if VS_VER > VC_6
#include <winefs.h>
#endif            
#if VS_VER > VC_1
#include <winerror.h>
#include <wingdi.h>  
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include <winmeta.h> // optional, used here for WINEVENT_LEVEL_ERROR"
#endif     
#if VS_VER > VC_1
#include <winnetwk.h>
#include <winnls.h>
#include <winnt.h>      
#endif
#if VS_VER > VC_5
#include <winnt.rh>
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include <winpackagefamily.h>
#endif            
#if VS_VER > VC_1
#include <winperf.h>    // necessary for the Detail Level definitions"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "winppi.h"
#endif           
#if VS_VER > VC_1
#include <winreg.h>
#endif
#include "winres.h"
#if VS_VER > VC_4
#include <winresrc.h>
#endif
#if VS_VER > VC_6
#include "winsafer.h"
#endif
#if VS_VER > VS_2005
#include "winsatcominterfacei.h"
#endif
#if VS_VER == VC_6
#define _LPCBYTE_DEFINED // winscard.h(43) : error C2373: 'LPCBYTE' : redefinition; different type modifiers
#endif
#if VS_VER > VC_5
#include <winscard.h>
#endif
#if TOOLSET > 90
#include "winsdkver.h"
#endif
#include <winsock.h>
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "winsplp.h"
#endif    
#if VS_VER > VC_1
#include <winspool.h>
#endif
//#include "winsqlite3ext.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "winstring.h"
#endif                 
#if VS_VER > VC_1
#include <winsvc.h>     // SERVICE_STATUS_HANDLE"
#endif
#if VS_VER > VS_2005
#include "winsxs.h"
#endif
#if TOOLSET > 90
#include "winsync.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "winusb.h"
#include "winusbio.h"
#endif
//#include "winuser.rh"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <wintrust.h>
#include <winusbio.h>
#endif      
#if VS_VER > VC_1
#include <winuser.h>
#endif
#if VS_VER > VC_5
#include <winuser.rh>
#endif       
#if VS_VER > VC_1
#include <winver.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wkspbkax.h"
//#include "wkspbkax_i.c"
#if VS_VER > VS_2015
#include <wldp.h>
#endif
#endif
#if VS_VER > VS_2005
#include "wlanapi.h"
#include "wlanihv.h"
#include "wlanihvtypes.h"
//#include "wlanihvui.idl"
#include "wlantypes.h"
#include "wlclient.h"
#endif
#if VS_VER > VC_6
#include <wmistr.h>
#endif
//#include "wmcodecdsp.h"
#if VS_VER > VS_2005
#include "wmcontainer.h"
#include "wmdm.h"
#include "wmdmlog.h"
//#include "wmdmlog_i.c"
#include "wmdxva.h"
#endif
#if TOOLSET > 90
#include "wmlss.h"
#endif
#if VS_VER > VS_2005
#include "wmpdevices.h"
#include "wmpids.h"
#include "wmpplug.h"
#include "wmprealestate.h"
#include "wmpservices.h"
#include "wmsdk.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wmsdkvalidate.h"
#endif
#if TOOLSET > 90
#include "wmsecure.h"
#endif
#include "wmsinternaladminnetsource.h"
#include "wmsysprf.h"
#endif
#if VS_VER > VC_6
#include <wmiutils.h>
#endif
//#include "wnvapi.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "wofapi.h"
#endif
#if TOOLSET > 90
#include "workspaceax.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "workspaceruntime.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <wnnc.h>
#include <wow64apiset.h>
#include <wlclient.h>
#endif
#if VS_VER > VS_2005
#include "wpc.h"
#include "wpcapi.h"
#include "wpcevent.h"
#include "wpframework.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wrl.h"
#endif
#if VS_VER > VS_2005
#include "ws2bth.h"
#endif
//#include "ws2ipdef.h"
#if TOOLSET > 90
#include "wsbapp.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wsbonline.h"
#include "wsdemolicensing.h"
#endif
#if VS_VER > VS_2003
#include "wsipv6ok.h"
#endif
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2015)
#include "wslapi.h"
#endif
#if defined(WSMAN_API_VERSION_1_0) || defined(WSMAN_API_VERSION_1_1)
#include "wsman.h"
#endif
#if TOOLSET > 90
#include "wsmandisp.h"
//#include "wsmandisp_i.c"
#endif
#if VS_VER > VS_2015
#include "wsrm.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "wtshintapi.h"
#endif
#if TOOLSET > 90
#include "wtsprotocol.h"
#endif
#if VS_VER > VS_2005
#include "wuapi.h"
#endif
#if VS_VER > VS_2003
#include <wsipv6ok.h>
#endif
//#include <wspiapi.h>    
#if VS_VER > VC_1
#include <wtypes.h>
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "x3daudio.h"
//#include "xamlOM.h"
//#include "xamlOM.idl"
#include "xapo.h"
#include "xapobase.h"
#include "xapofx.h"
#include "xaudio2.h"
#include "xaudio2fx.h"
#endif
#if VS_VER > VC_6
#include "xenroll.h"
#endif
#if VS_VER > VS_2005
#include "xmllite.h"
#endif
#if VS_VER > VC_5
#include "xoleHlp.h"
#endif
#if VS_VER > VS_2005
#include "xprtdefs.h"
#endif
#if TOOLSET > 90
#include "xpsdigitalsignature.h"
#if (!defined _USING_V110_SDK71_) && (MSVC_VER > 2012)
#include "xpsobjectmodel_2.h"
#endif
#include "xpsprint.h"
#endif
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "xpsrassvc.h"
#endif
//#include "objidlbase.idl"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include <wtypesbase.h>
#endif
#if VS_VER > VC_6
#include <xmmintrin.h>
#endif
#if defined _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING || defined _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#include <yvals.h>
#endif
//#include "CameraUIControl.idl"
#if VS_VER > VC_6
#include "ADOGuids.h"
#endif
#if VS_VER > VS_2002
#include "advpub.h"
#endif
//todo file exists but needs to avoid redefition
//#include <netmon.h>
#if VS_VER > VS_2005
#include "ahadmin.h"
#endif
//#include "adojet.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "AsyncInfo.h"
#endif
//#include "ahadmin_i.c"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "BdaTypes.h"
#endif
//#include "CodeAnalysis/sourceannotations.h"
//#include "DirectXCollision.inl"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include "DirectXMathConvert.inl"
#include "DirectXMathMatrix.inl"
#include "DirectXMathMisc.inl"
#include "DirectXMathVector.inl"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "EapAuthenticatorTypes.h"
#include "EapMethodTypes.h"
//#include "FRQuery.h"
//#include "FunctionDiscoveryAPI.h"
#include "FunctionDiscoveryCategories.h"
#include "FunctionDiscoveryConstraints.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include "FunctionDiscoveryError.h"
#include "FunctionDiscoveryKeys.h"
#endif
//#include "FunctionDiscoveryNotification.h"
#include "FunctionDiscoveryServiceIDs.h"
//#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include "SessdirPublicTypes.h"
#endif
//#include "SpellCheck.h"
//#include "StructuredQuery.h"
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include "TpmVscAttestation.h"
#endif
//#include "VMRender.idl"
#include "VSStyle.h"
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include "VmSavedStateDumpDefs.h"
#include "WaaSAPITypes.h"
//#include "Wincodec.h"

#include "Windows.AI.Actions.Hosting.h"
#include "Windows.AI.Actions.h"
#include "Windows.AI.Agents.h"
#include "Windows.ApplicationModel.Activation.h"
#include "Windows.ApplicationModel.AppService.h"
#include "Windows.ApplicationModel.Appointments.AppointmentsProvider.h"
#include "Windows.ApplicationModel.Appointments.h"
#include "Windows.ApplicationModel.Background.h"
#include "Windows.ApplicationModel.Calls.Background.h"
#include "Windows.ApplicationModel.Calls.h"
#include "Windows.ApplicationModel.CommunicationBlocking.h"
#include "Windows.ApplicationModel.Contacts.Provider.h"
#include "Windows.ApplicationModel.Contacts.h"
#include "Windows.ApplicationModel.Core.h"
#include "Windows.ApplicationModel.DataTransfer.DragDrop.h"
#include "Windows.ApplicationModel.DataTransfer.ShareTarget.h"
#include "Windows.ApplicationModel.DataTransfer.h"
#include "Windows.ApplicationModel.Email.h"
//#include "Windows.ApplicationModel.Payments.h"
#include "Windows.ApplicationModel.Search.h"
#include "Windows.ApplicationModel.SocialInfo.h"
#include "Windows.ApplicationModel.UserActivities.h"
#include "Windows.ApplicationModel.UserDataAccounts.Provider.h"
#include "Windows.ApplicationModel.UserDataAccounts.h"
#include "Windows.ApplicationModel.UserDataTasks.h"
#include "Windows.ApplicationModel.Wallet.h"
#include "Windows.ApplicationModel.h"
#include "Windows.Data.Json.h"
#include "Windows.Data.Text.h"
#include "Windows.Data.Xml.Dom.h"
#include "Windows.Devices.Adc.Provider.h"
#include "Windows.Devices.Bluetooth.Advertisement.h"
#include "Windows.Devices.Bluetooth.Background.h"
#include "Windows.Devices.Bluetooth.GenericAttributeProfile.h"
#include "Windows.Devices.Bluetooth.Rfcomm.h"
#include "Windows.Devices.Bluetooth.h"
#include "Windows.Devices.Enumeration.h"
//#include "Windows.Devices.Geolocation.h"
#include "Windows.Devices.Gpio.Provider.h"
#include "Windows.Devices.Haptics.h"
#include "Windows.Devices.HumanInterfaceDevice.h"
#include "Windows.Devices.I2c.Provider.h"
#include "Windows.Devices.Input.h"
#include "Windows.Devices.Lights.h"
#include "Windows.Devices.Perception.h"
#include "Windows.Devices.PointOfService.h"
//#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include "Windows.Devices.Power.h"
#include "Windows.Devices.Printers.Extensions.h"
#include "Windows.Devices.Pwm.Provider.h"
#include "Windows.Devices.Radios.h"
#include "Windows.Devices.Sensors.h"
#include "Windows.Devices.SmartCards.h"
#include "Windows.Devices.Sms.h"
#include "Windows.Devices.Spi.Provider.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.Numerics.h"
#include "Windows.Gaming.Input.Custom.h"
#include "Windows.Gaming.Input.ForceFeedback.h"
#include "Windows.Gaming.Input.h"
#include "Windows.Gaming.Preview.h"
#include "Windows.Gaming.XboxLive.h"
#include "Windows.Globalization.h"
#include "Windows.Management.Deployment.h"
#include "Windows.Media.Audio.h"
#include "Windows.Media.Capture.Core.h"
#include "Windows.Media.Capture.Frames.h"
#include "Windows.Media.Capture.h"
#include "Windows.Media.Casting.h"
#include "Windows.Media.Core.h"
#include "Windows.Media.Devices.Core.h"
#include "Windows.Media.Devices.h"
#include "Windows.Media.Editing.h"
#include "Windows.Media.Effects.h"
#include "Windows.Media.FaceAnalysis.h"
#include "Windows.Media.MediaProperties.h"
#include "Windows.Media.PlayTo.h"
#include "Windows.Media.Playback.h"
#include "Windows.Media.Protection.h"
#include "Windows.Media.Render.h"
#include "Windows.Media.SpeechRecognition.h"
#include "Windows.Media.Streaming.Adaptive.h"
#include "Windows.Media.Transcoding.h"
#include "Windows.Media.h"
#include "Windows.Networking.BackgroundTransfer.h"
#include "Windows.Networking.Connectivity.h"
#include "Windows.Networking.Sockets.h"
#include "Windows.Networking.h"
#include "Windows.Perception.Spatial.h"
#include "Windows.Perception.h"
#include "Windows.Phone.h"
#include "Windows.Security.Authentication.Web.Core.h"
#include "Windows.Security.Authentication.Web.Provider.h"
#include "Windows.Security.Authentication.Web.h"
#include "Windows.Security.Authorization.AppCapabilityAccess.h"
#include "Windows.Security.Credentials.h"

#if (defined(_MSC_VER) && (_MSC_VER <= 1800)) && (defined(_MSC_VER) && (_MSC_VER <= 1800)) // VS 2013, SDK v120
#include "Windows.Security.Cryptography.Certificates.h"
#include "Windows.Security.Cryptography.Core.h"
#endif

#include "Windows.Security.EnterpriseData.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include "Windows.Services.Maps.LocalSearch.h"
#include "Windows.Services.Maps.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include "Windows.Storage.FileProperties.h"
#include "Windows.Storage.Pickers.Provider.h"
#include "Windows.Storage.Provider.h"
#include "Windows.Storage.Search.h"
#include "Windows.Storage.h"
#endif
#if defined(NTDDI_WIN10_VB) && NTDDI_VERSION > NTDDI_WIN10_VB
#include "Windows.System.Diagnostics.h"
#include "Windows.System.Power.h"
#include "Windows.System.RemoteSystems.h"
//#include "Windows.System.Threading.h"
#include "Windows.UI.Core.CoreWindowFactory.h"
#include "Windows.UI.Core.h"
#include "Windows.UI.Input.Inking.h"
#include "Windows.UI.Input.Spatial.h"
#include "Windows.UI.Input.h"
#include "Windows.UI.Notifications.h"
#include "Windows.UI.Popups.h"
#include "Windows.UI.Shell.h"
#include "Windows.UI.StartScreen.h"
#include "Windows.UI.Text.Core.h"
#include "Windows.UI.Text.h"
#include "Windows.UI.UIAutomation.h"

#include "Windows.UI.ViewManagement.h"
#include "Windows.UI.WindowManagement.h"
#include "Windows.Web.Http.Headers.h"
#include "Windows.Web.Http.h"
#include "Windows.Web.Syndication.h"
#include "Windows.Web.UI.h"
#include "Windows.Web.h"
#endif
#endif
//#include "FRQuery.h"
#if VS_VER > VC_4
#include "activscp.h"
#endif
#if VS_VER > VC_6
#include "adodef.h"
#endif
//#include "adoint_backcompat.h"
#if VS_VER > VC_5
#include "adsdb.h"
#include "adserr.h"
#endif
//#include "adshlp.h"
#if VS_VER > VC_5
#include "adsiid.h"
#include "adsnms.h"
#include "adssts.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "asferr.h"
#endif
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include "audioapotypes.h"
#endif
//#include "axcore.idl"
#if VS_VER > VC_5
#include "basetsd.h"
#endif
//#include "bits.h"
#if VS_VER > VC_6
#include "bitsmsg.h"
#include "cdosysstr.h"
#endif
#if VS_VER > VS_2003
#include "certbase.h"
#endif
#if VS_VER > VC_6
#include "comadmin.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "commctrl.inl"
#include "commdlg.inl"
#endif
#if VS_VER > VC_6
#include "comsvcs.h"
#endif
//#include "dbgprop.h"
//#include "dbs.idl"
//#include "dbsdep.idl"
//#include "devenum.idl"
#if VS_VER > VC_6
#include "dbgprop.h"
#endif
//#include "exdisp.h"
#if VS_VER > VC_4
#include "exdispid.h"
#endif
#if VS_VER > VC_5
#include "mddefw.h"
#endif
//#include "mmc.h"
//#include "propidlbase.idl"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "prsht.inl"
#endif
//#include "sapiaut.idl"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include "sdv_driverspecs.h"
#endif
#if TOOLSET > 90
#include "SessdirPublicTypes.h"
#endif
//#include "srchntfyinlinesite.idl"
//#include "srchprth.idl"
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "stgprop.h"
#endif
//#include "routprot.h"
//#include "stm.h"
#if defined(NTDDI_WIN8) && (NTDDI_VERSION >= NTDDI_WIN8)
#include "transportsettingcommon.h"
#endif
#if VS_VER > VC_6
#include "utillib.h"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "vsserror.h"
#endif
#if VS_VER > VC_5
#include "winsmcrd.h"
#endif
#if VS_VER > VC_6
#include "winuser.inl"
#endif
#if defined(_MSC_VER) && (_MSC_VER > 1400)
#include "wsdxmldom.h"
#endif
#if VS_VER > VC_6
#include "xmldomdid.h"
#endif
//#include "dvdif.idl"
//#include "dyngraph.idl"
#if VS_VER > VC_4
#include "exdisp.h"
#endif
//#include "guids.h"
#if (!defined _USING_V110_SDK71_) && (VS_VER > VS_2010)
#include "hidusage.h"
#endif
#if VS_VER > VC_5
#include "iads.h"
#endif
//#include "icodecapi.idl"
#if VS_VER > VC_6
#include "idlmulti.h"
#endif
#if MSVC_VER > VS_2013
using namespace Gdiplus;
#include "GdiplusMatrix.h"
#endif

// #include <BridgeDeviceService.h> // No <Bridge.h>
// ============================================================
// WARNING: User-mode project including kernel-mode header
// This is a minimal hack to satisfy cper.h dependencies
// DO NOT use any cper.h structures that require kernel-only types
// ============================================================
#if TOOLSET > 90
typedef UCHAR KIRQL;
#include <cper.h>
#endif
//#include <cperguid.h>
#if defined(__clang__)
#include "cpuid.h"
#endif

/*
#include "\"access.idl\"   // IAccessor                : IUnknown"
#include "\"altidx.idl\"   // IAlterIndex              : IUnknown"
#include "\"alttab.idl\"   // IAlterTable              : IUnknown"
#include "\"asynot.idl\"   // IDBAsynchNotify          : IUnknown"
#include "\"asysta.idl\"   // IDBAsynchStatus          : IUnknown"
#include "\"binres.idl\"        // IBindResource                        : IUnknown"
#include "\"chprst.idl\"   // IChapteredRowset         : IUnknown"
#include "\"clinf2.idl\"        // IColumnsInfo2                        : IColumnsInfo"
#include "\"cmdbas.idl\"   // ICommand                 : IUnknown"
#include "\"cmdcst.idl\"   // ICommandCost             : IUnknown"
#include "\"cmdpre.idl\"   // ICommandPrepare          : IUnknown"
#include "\"cmdprp.idl\"   // ICommandProperties       : IUnknown"
#include "\"cmdprst.idl\"  // ICommandPersist          : ICommand"
#include "\"cmdstrm.idl\"  // ICommandStream           : IUnknown"
#include "\"cmdtre.idl\"   // ICommandTree             : IUnknown"
#include "\"cmdtxt.idl\"   // ICommandText             : IUnknown"
#include "\"cmdval.idl\"        // ICommandValidate                     : IUnknown"
#include "\"cmdwpr.idl\"   // ICommandWithParameters   : IUnknown"
#include "\"colinf.idl\"   // IColumnsInfo             : IUnknown"
#include "\"colrst.idl\"   // IColumnsRowset           : IUnknown"
#include "\"crtrow.idl\"        // ICreateRow                           : IUnknown"
#include "\"cvttyp.idl\"   // IConvertType             : IUnknown"
#include "\"d3d10.h\" //"
#include "\"d3d11.h\" //"
#include "\"d3d11_1.h\" //"
#include "\"d3d11_2.h\" //"
#include "\"d3d11_3.h\" //"
#include "\"dbccmd.idl\"   // IDBCreateCommand         : IUnknown"
#include "\"dbcses.idl\"   // IDBCreateSession         : IUnknown"
#include "\"dbdsad.idl\"   // IDBDataSourceAdmin       : IUnknown"
#include "\"dbinfo.idl\"   // IDBInfo                  : IUnknown"
#include "\"dbinit.idl\"   // IDBInitialize            : IUnknown"
#include "\"dbprop.idl\"   // IDBProperties            : IUnknown"
#include "\"dbrtpr.idl\"        // IDBResetProperties           : IUnknown"
#include "\"dbscmd.idl\"   // IDBSchemaCommand         : IUnknown"
#include "\"dbsrst.idl\"   // IDBSchemaRowset          : IUnknown"
#include "\"dciddi.h\"         // interface to the DCI provider"
#include "\"errlup.idl\"   // IErrorLookup             : IUnknown"
#include "\"errrec.idl\"   // IErrorRecords            : IUnknown"
#include "\"getdts.idl\"   // IGetDataSource           : IUnknown"
#include "\"getrow.idl\"        // IGetRow                                      : IUnknown"
#include "\"getses.idl\"        // IGetSession                          : IUnknown"
#include "\"getsrw.idl\"        // IGetSourceRow                        : IUnknown"
#include "\"guids.h\"  // PRIVATE"
#include "\"inddef.idl\"   // IIndexDefinition         : IUnknown"
#include "\"mddset.idl\"   // IMDDataset               : IUnknown"
#include "\"mdfind.idl\"   // IMDFind                  : IUnknown"
#include "\"mdrrst.idl\"   // IMDRangeRowset           : IUnknown"
#include "\"msi.h\"  // INSTALLSTATE"
#include "\"mulres.idl\"   // IMultipleResults         : IUnknown"
#include "\"objactnl.idl\"      // IObjectAccessControl         : IUnknown"
#include "\"objbase.h\" //Required by msxml2.h"
#include "\"opnrst.idl\"   // IOpenRowset              : IUnknown"
#include "\"parrst.idl\"   // IParentRowset            : IUnknown"
#include "\"poppack.h\"                        // Back to 4 byte packing"
#include "\"poppack.h\"                    // Back to 4 byte packing"
#include "\"poppack.h\"                // Back to the initial value"
#include "\"poppack.h\"        /* Revert to default packing *//*"
#include "\"poppack.h\"    /* Revert to default packing *//*"
#include "\"prvmon.idl\"   // IProvideMoniker          : IUnknown"
#include "\"pshpack1.h\"   /* Assume byte packing throughout *//*"
#include "\"pshpack1.h\"   // Assume byte packing throughout"
#include "\"pshpack2.h\"                       // Symbols, relocs, and linenumbers are 2 byte packed"
#include "\"pshpack2.h\"                   // 16 bit headers are 2 byte packed"
#include "\"pshpack4.h\"                   // 4 byte packing is the default"
#include "\"pshpack8.h\"                       // Use align 8 for the 64-bit IAT."
#include "\"qrybas.idl\"   // IQuery                   : ICommandTree"
#include "\"readdt.idl\"   // IReadData                : IUnknown"
#include "\"regprv.idl\"        // IRegisterProvider            : IUnknown"
#include "\"row.idl\"           // IRow                                         : IUnknown"
#include "\"rowchg.idl\"        // IRowChange                           : IUnknown"
#include "\"rowinf.idl\"   // IRowInfo                : IUnknown"
#include "\"rowpos.idl\"   // IRowPosition             : IUnknown"
#include "\"rowpsc.idl\"   // IRowPositionChange       : IUnknown"
#include "\"rstasn.idl\"   // IRowsetAsynch            : IUnknown"
#include "\"rstbas.idl\"   // IRowset                  : IUnknown"
#include "\"rstbmrk.idl\"  // IRowsetBookmark          : IUnknown"
#include "\"rstchg.idl\"   // IRowsetChange            : IUnknown"
#include "\"rstchpmb.idl\" // IRowsetChapterMember     : IChapeteredRowset"
#include "\"rstcpr.idl\"   // IRowsetCopyRows          : IUnknown"
#include "\"rstcridx.idl\"      // IRowsetCurrentIndex          : IRowsetIndex"
#include "\"rstfnd.idl\"   // IRowsetFind              : IUnknown"
#include "\"rstidn.idl\"   // IRowsetIdentity          : IUnknown"
#include "\"rstind.idl\"   // IRowsetIndex             : IUnknown"
#include "\"rstinf.idl\"   // IRowsetInfo              : IUnknown"
#include "\"rstkys.idl\"   // IRowsetKeys              : IUnknown"
#include "\"rstloc.idl\"   // IRowsetLocate            : IRowset"
#include "\"rstnot.idl\"   // IRowsetNotify            : IUnknown"
#include "\"rstnra.idl\"   // IRowsetNewRowAfter       : IRowsetNewRow"
#include "\"rstnxr.idl\"   // IRowsetNextRowset        : IUnknown"
#include "\"rstres.idl\"   // IRowsetResynch           : IRowset"
#include "\"rstrfres.idl\" // IRowsetRefresh           : IUnknown"
#include "\"rstscr.idl\"   // IRowsetScroll            : IRowsetLocate"
#include "\"rstupd.idl\"   // IRowsetUpdate            : IRowsetChange"
#include "\"rstvw.idl\"    // IRowsetView              : IUnknown"
#include "\"rstwpr.idl\"   // IRowsetWithParamters     : IUnknown"
#include "\"rstwta.idl\"   // IRowsetWatchAll          : IUnknown"
#include "\"rstwtn.idl\"   // IRowsetWatchNotify       : IUnknown"
#include "\"rstwtr.idl\"   // IRowsetWatchRegion       : IUnknown"
#include "\"rstxsc.idl\"   // IRowsetExactScroll       : IRowsetScroll"
#include "\"rwschg.idl\"        // IRowSchemaChange                     : IRowsetChange"
#include "\"scpops.idl\"        // IScopedOperations            : IBindResource"
#include "\"sesprp.idl\"   // ISessionProperties       : IUnknown"
#include "\"seurinfo.idl\"      // ISecurityInfo                        : IUnknown"
#include "\"sqleri.idl\"   // ISQLErrorInfo            : IUnknown"
#include "\"srcrst.idl\"   // ISourcesRowset           : IUnknown"
#include "\"tabdef.idl\"   // ITableDefinition         : IUnknown"
#include "\"tabren.idl\"   // ITableRename             : IUnknown"
#include "\"tbdefcnt.idl\"      // ITableDefinitionWithConstraints                      : ITableCreation"
#include "\"tblcrt.idl\"        // ITableCreation                       : ITableDefinition"
#include "\"trnjoi.idl\"   // ITransactionJoin         : IUnknown"
#include "\"trnlcl.idl\"   // ITransactionLocal        : ITransaction"
#include "\"trnobj.idl\"   // ITransactionObject       : IUnknown"
#include "\"truadmin.idl\"      // ITrusteeAdmin                        : IUnknown"
#include "\"trugpadm.idl\"      // ITrusteeMemberAdmin          : IUnknown"
#include "\"vwchp.idl\"    // IViewChapter             : IUnknown"
#include "\"vwflt.idl\"    // IViewFilter              : IUnknown"
#include "\"vwrst.idl\"    // IViewRowset              : IUnknown"
#include "\"vwsrt.idl\"    // IViewSort                : IUnknown"*/

// extensions
#ifndef NO_EXTENSIONS
// if not support Windows 2000 and compiler is not later than  Microsoft Visual Studio .NET 2003
// Do NOT check Windows version, the definition is completely same in both Windows XP and Windows 2000
#if (!defined WIN2000_SUPPORT) && (!defined WIN98_SUPPORT) && (_MSC_VER <= 1310)
// Do NOT enable this without compiler VS .NET 2003
// or you will get warning C4273 (inconsistent DLL linkage)
#pragma comment(lib, "kernel32.lib")
extern "C" HWND WINAPI GetConsoleWindow(VOID);
extern "C" DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList, DWORD dwProcessCount);
#endif

// libraries
#if defined LINK_ALL
#pragma comment(lib, "shlwapi.lib")
#endif

#endif

#ifdef _NOMINMAX
#undef _NOMINMAX
#define NOMINMAX
#undef min
#undef max
#endif

#ifndef COMPILE_MULTIMON_STUBS
#undef GetSystemMetrics
#endif
