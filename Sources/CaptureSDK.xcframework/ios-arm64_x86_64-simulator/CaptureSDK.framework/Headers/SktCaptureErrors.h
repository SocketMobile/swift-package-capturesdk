/**
  @file SktCaptureErrors.h
  @brief Error codes used in Capture.

  THIS FILE IS AUTO-GENERATED, DO NOT EDIT

  @date 7/6/2017
  @copyright ©2017 Socket Mobile, inc.
*/

#ifndef __SKTCAPTUREERRORS_H
#define __SKTCAPTUREERRORS_H

/**
  macro to use to know if the result is
  successful
*/
#define SKTSUCCESS(result) (result>=0)

/**
  macro to execute code only if the previous result
  was successful
*/
#define SKTCHECKSUCCESS(result,Expression) SKTSUCCESS(result)?result=Expression:result

/**
  define the error codes used by Capture.
  The positive values can be interpreted as successful with a warning.
  That's why it is recommended to use the SKTSUCCESS macro to check for
  success.
*/
typedef NS_ENUM(NSInteger, SKTCaptureErrors) {
	/**
	The wait timed out
	*/
	SKTCaptureE_WAITTIMEOUT = 1,

	/**
	This operation is already complete
	*/
	SKTCaptureE_ALREADYDONE = 2,

	/**
	This operation is pending
	*/
	SKTCaptureE_PENDING = 3,

	/**
	This operation is still pending
	*/
	SKTCaptureE_STILLPENDING = 4,

	/**
	The object has been created
	*/
	SKTCaptureE_CREATED = 5,

	/**
	There is no error
	*/
	SKTCaptureE_NOERROR = 0,

	/**
	At least one test has failed
	*/
	SKTCaptureE_TESTFAILED = -1,

	/**
	There is not enough memory to complete the operation
	*/
	SKTCaptureE_NOTENOUGHMEMORY = -2,

	/**
	A lock cannot be created
	*/
	SKTCaptureE_UNABLECREATELOCK = -3,

	/**
	Unable to lock a shared resource
	*/
	SKTCaptureE_UNABLELOCK = -4,

	/**
	Unable to unlock a shared resource
	*/
	SKTCaptureE_UNABLEUNLOCK = -5,

	/**
	Unable to remove an item from a list because the list is empty
	*/
	SKTCaptureE_LISTEMPTY = -6,

	/**
	An event cannot be created
	*/
	SKTCaptureE_UNABLECREATEEVENT = -7,

	/**
	Unable to set an event
	*/
	SKTCaptureE_UNABLESETEVENT = -8,

	/**
	Unable to reset an event
	*/
	SKTCaptureE_UNABLERESETEVENT = -9,

	/**
	The event is not created
	*/
	SKTCaptureE_EVENTNOTCREATED = -10,

	/**
	The provided handle is invalid
	*/
	SKTCaptureE_INVALIDHANDLE = -11,

	/**
	A thread cannot be created
	*/
	SKTCaptureE_UNABLECREATETHREAD = -12,

	/**
	The thread is already created
	*/
	SKTCaptureE_THREADALREADYCREATED = -13,

	/**
	The thread is still running
	*/
	SKTCaptureE_THREADSTILLRUNNING = -14,

	/**
	This operation is not supported
	*/
	SKTCaptureE_NOTSUPPORTED = -15,

	/**
	The previous operation is not completed
	*/
	SKTCaptureE_PENDINGOPERATIONNOTCOMPLETED = -16,

	/**
	The item cannot be found
	*/
	SKTCaptureE_NOTFOUND = -17,

	/**
	The provided parameter is invalid
	*/
	SKTCaptureE_INVALIDPARAMETER = -18,

	/**
	Trying to use an object that is not yet initialized
	*/
	SKTCaptureE_NOTINITIALIZED = -19,

	/**
	The timeout value is out of range
	*/
	SKTCaptureE_TIMEOUTOUTOFRANGE = -20,

	/**
	The object cannot be initialized
	*/
	SKTCaptureE_UNABLEINITIALIZE = -21,

	/**
	The object cannot be un-initialized
	*/
	SKTCaptureE_UNABLEDEINITIALIZE = -22,

	/**
	The configuration is unknown
	*/
	SKTCaptureE_UNKNOWNCONFIGURATION = -23,

	/**
	The configuration is invalid
	*/
	SKTCaptureE_INVALIDCONFIGURATION = -24,

	/**
	Creating or adding an item that already exists
	*/
	SKTCaptureE_ALREADYEXISTING = -25,

	/**
	The provided buffer is too small
	*/
	SKTCaptureE_BUFFERTOOSMALL = -26,

	/**
	The specified device cannot be opened
	*/
	SKTCaptureE_UNABLEOPENDEVICE = -27,

	/**
	The specified device cannot be configured
	*/
	SKTCaptureE_UNABLECONFIGUREDEVICE = -28,

	/**
	The string cannot be converted
	*/
	SKTCaptureE_UNABLECONVERTSTRING = -29,

	/**
	The specified string cannot be copied
	*/
	SKTCaptureE_UNABLECOPYSTRING = -30,

	/**
	The specified device is not open
	*/
	SKTCaptureE_DEVICENOTOPEN = -31,

	/**
	The specified item is not available
	*/
	SKTCaptureE_NOTAVAILABLE = -32,

	/**
	The specified file cannot be written
	*/
	SKTCaptureE_UNABLEWRITEFILE = -33,

	/**
	The specified file cannot be read
	*/
	SKTCaptureE_UNABLEREADFILE = -34,

	/**
	The wait has failed
	*/
	SKTCaptureE_WAITFAILED = -35,

	/**
	The specified checksum is invalid
	*/
	SKTCaptureE_INVALIDCHECKSUM = -36,

	/**
	This command has been denied
	*/
	SKTCaptureE_COMMANDDENIED = -37,

	/**
	There was an error during communication
	*/
	SKTCaptureE_COMMUNICATIONERROR = -38,

	/**
	An unexpected command has been received
	*/
	SKTCaptureE_RECEIVEUNEXPECTEDCOMMAND = -39,

	/**
	The GUID cannot be created
	*/
	SKTCaptureE_UNABLECREATEGUID = -40,

	/**
	The specified value is invalid
	*/
	SKTCaptureE_INVALIDVALUE = -41,

	/**
	The request has timed out
	*/
	SKTCaptureE_REQUESTTIMEDOUT = -42,

	/**
	The operation is invalid
	*/
	SKTCaptureE_INVALIDOPERATION = -43,

	/**
	The protocol used is not the correct one
	*/
	SKTCaptureE_WRONGPROTOCOL = -44,

	/**
	The queue has been reset
	*/
	SKTCaptureE_QUEUERESETED = -45,

	/**
	The data size exceeeds maximum transmission unit
	*/
	SKTCaptureE_EXCEEDINGMTUSIZE = -46,

	/**
	The listener thread has nothing to listen to
	*/
	SKTCaptureE_NOTHINGTOLISTEN = -47,

	/**
	The current version is outdated
	*/
	SKTCaptureE_OUTDATEDVERSION = -48,

	/**
	The XML tag is invalid
	*/
	SKTCaptureE_INVALIDXMLTAG = -49,

	/**
	Cannot register for  HID change notifications
	*/
	SKTCaptureE_UNABLEREGISTERFORHIDCHANGES = -50,

	/**
	The message cannot be retrieved
	*/
	SKTCaptureE_UNABLERETRIEVEMESSAGE = -51,

	/**
	There is a syntax error
	*/
	SKTCaptureE_SYNTAXERROR = -52,

	/**
	The specified file cannot be opened
	*/
	SKTCaptureE_UNABLEOPENFILE = -53,

	/**
	The file path cannot be retrieved
	*/
	SKTCaptureE_UNABLERETRIEVEPATH = -54,

	/**
	The specified directory cannot be created
	*/
	SKTCaptureE_UNABLECREATEDIRECTORY = -55,

	/**
	The specified file cannot be deleted
	*/
	SKTCaptureE_UNABLEDELETEFILE = -56,

	/**
	The specified directory cannot be deleted
	*/
	SKTCaptureE_UNABLEDELETEDIRECTORY = -57,

	/**
	The modem status cannot be read
	*/
	SKTCaptureE_UNABLEREADMODEMSTATUS = -60,

	/**
	The Class of Devices cannot be retrieved
	*/
	SKTCaptureE_UNABLEGETCLASSDEVICES = -61,

	/**
	The device interface cannot be retrieved
	*/
	SKTCaptureE_UNABLEGETDEVICEINTERFACE = -62,

	/**
	The specified file or device cannot be found
	*/
	SKTCaptureE_FILENOTFOUND = -63,

	/**
	The specified file or device is not accessible
	*/
	SKTCaptureE_FILEACCESSDENIED = -64,

	/**
	The HID information cannot be read
	*/
	SKTCaptureE_UNABLEREADHIDINFO = -70,

	/**
	The profile file causes a conflict
	THIS ERROR IS DEPRECATED
	*/
	SKTCaptureE_CONFLICTPROFILE = -80,

	/**
	The current profile cannot be deleted
	THIS ERROR IS DEPRECATED
	*/
	SKTCaptureE_DELETECURRENTPROFILE = -81,

	/**
	Data editing cannot be initialized
	THIS ERROR IS DEPRECATED
	*/
	SKTCaptureE_UNABLEINITIALIZEDATAEDITING = -82,

	/**
	The data editing operation is invalid
	THIS ERROR IS DEPRECATED
	*/
	SKTCaptureE_UNKNOWNDATAEDITINGOPERATION = -83,

	/**
	The number of parameters is incorrect
	*/
	SKTCaptureE_INCORRECTNUMBEROFPARAMETERS = -84,

	/**
	The specified format is invalid
	*/
	SKTCaptureE_INVALIDFORMAT = -85,

	/**
	The version is invalid
	*/
	SKTCaptureE_INVALIDVERSION = -86,

	/**
	The service does not respond
	*/
	SKTCaptureE_SERVICENOTCOMMUNICATING = -87,

	/**
	The SocketCam overlay view is not set
	*/
	SKTCaptureE_OVERLAYVIEWNOTSET = -90,

	/**
	This operation has been canceled
	*/
	SKTCaptureE_CANCEL = -91,

	/**
	The operation has expired
	*/
	SKTCaptureE_EXPIRED = -92,

	/**
	The AppInfo information is invalid
	*/
	SKTCaptureE_INVALIDAPPINFO = -93,

	/**
	BLE operation failed
	*/
	SKTCaptureE_BLEGATT = -94,

	/**
	Auto-discovery is in progress
	*/
	SKTCaptureE_FAVORITENOTEMPTY = -95,

	/**
	Location permission is required to complete the operation
	*/
	SKTCaptureE_LOCATIONPERMISSIONMISSING = -96,

	/**
	The requested operation cannot be completed
	*/
	SKTCaptureE_UNABLETOCOMPLETEOPERATION = -97,

	/**
	Location service is disabled
	*/
	SKTCaptureE_LOCATIONSERVICEDISABLED = -98,

};

#endif

