/*
SktCaptureDeviceTypes.h
Device Type definitions for Socket Capture
(c) Socket Mobile, Inc.
*/

/*
NOTES:
IF ANY MODIFICATION IS MADE IN THIS FILE THE CAPTURE INTERFACE VERSION
WILL NEED TO BE UPDATED TO IDENTIFY THIS CHANGE.
THE CAPTURE INTERFACE VERSION IS DEFINED IN CaptureSDK.h
THE MODIFICATION MUST BE DESCRIBED IN Capture.doc
*/

/*
Definition of a Socket Device Type

  31  30  29  28  27  26  25  24  23  22  21  20  19  18  17  16  15  14  13  12  11  10  9   8   7   6   5   4   3   2   1   0
---------------------------------------------------------------------------------------------------------------------------------
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
---------------------------------------------------------------------------------------------------------------------------------
  |	                  |   |    |   |                           |  |                            |   |                              |
  \==================/     \==/   \===========================/  \============================/   \==============================/
            |               |                   |                                       |                       |
            |               |                   |                                       |                       |
            |               |                   |                                       | Reserved              \------------------->Product ID
            |               |                   | Interface Type                        \------------------------------------------->Reserved must be 0
			|               | Class Type        \----------------------------------------------------------------------------------->Interface Type
			| Reserved      \------------------------------------------------------------------------------------------------------->Class Type(Device = 0, Device Manager = 1)
            \----------------------------------------------------------------------------------------------------------------------->Reserved must be 0


*/


#ifndef _SktCaptureDeviceTypes_h
#define _SktCaptureDeviceTypes_h

#define SKTCLASSTYPE(classType)					(classType<<24)
#define SKTINTERFACETYPE(interfaceType)			(interfaceType<<16)
#define SKTRETRIEVE_INTERFACETYPE(deviceType)	((deviceType>>16)&0x000000ff)

#define SKTPRODUCTID(productId)					(productId)
#define SKTRETRIEVE_PRODUCTID(deviceType)		(deviceType&0x000000ff)
#define SKTRETRIEVE_CLASS(deviceType)			(deviceType>>24)&0x00000003

typedef NS_ENUM(NSInteger, SKTCaptureDeviceTypeClasses){
	///<summary>
	/// the class is a device
	/// value: 0 (0x00000)
	///</summary>
	SKTCaptureDeviceTypeClassDeviceClass = 0,

	///<summary>
	/// the class is a device manager
	/// value: 1 (0x00001)
	///</summary>
	SKTCaptureDeviceTypeClassDeviceManagerClass = 1,

};

typedef NS_ENUM(NSInteger, SKTCaptureDeviceTypeInterfaces){
	///<summary>
	/// no interface
	/// value: 0 (0x00000)
	///</summary>
	SKTCaptureDeviceTypeInterfaceNone = 0,

	///<summary>
	/// SD interface
	/// value: 1 (0x00001)
	///</summary>
	SKTCaptureDeviceTypeInterfaceSD = 1,

	///<summary>
	/// CF interface
	/// value: 2 (0x00002)
	///</summary>
	SKTCaptureDeviceTypeInterfaceCF = 2,

	///<summary>
	/// Bluetooth interface
	/// value: 3 (0x00003)
	///</summary>
	SKTCaptureDeviceTypeInterfaceBluetooth = 3,

	///<summary>
	/// Serial interface
	/// value: 4 (0x00004)
	///</summary>
	SKTCaptureDeviceTypeInterfaceSerial = 4,

	///<summary>
	/// Bluetooth Low Energy interface
	/// value: 5 (0x00005)
	///</summary>
	SKTCaptureDeviceTypeInterfaceBle = 5,

	///<summary>
	/// NFC
	/// value: 6 (0x00006)
	///</summary>
	SKTCaptureDeviceTypeInterfaceNFC = 6,

};

typedef NS_ENUM(NSInteger, SKTCaptureDeviceType){
	/**
	no device type (initial value)

	value: 0 (0x00000)
	*/
	SKTCaptureDeviceTypeNone = 0,

	/**
	Model 7

	value: 196609 (0x30001)
	*/
	SKTCaptureDeviceTypeScanner7 = 196609,

	/**
	Model 7X

	value: 196610 (0x30002)
	*/
	SKTCaptureDeviceTypeScanner7x = 196610,

	/**
	Model 7Xi

	value: 196612 (0x30004)
	*/
	SKTCaptureDeviceTypeScanner7xi = 196612,

	/**
	Model 9 CRS

	value: 196611 (0x30003)
	*/
	SKTCaptureDeviceTypeScanner9 = 196611,

	/**
	SocketCam C820 (only used in iOS and Android)

	value: 5 (0x00005)
	*/
	SKTCaptureDeviceTypeSocketCamC820 = 5,

	/**
	Model S800

	value: 196614 (0x30006)
	*/
	SKTCaptureDeviceTypeScannerS800 = 196614,

	/**
	Model S850

	value: 196615 (0x30007)
	*/
	SKTCaptureDeviceTypeScannerS850 = 196615,

	/**
	Model S840

	value: 196616 (0x30008)
	*/
	SKTCaptureDeviceTypeScannerS840 = 196616,

	/**
	Model D700

	value: 196617 (0x30009)
	*/
	SKTCaptureDeviceTypeScannerD700 = 196617,

	/**
	Model D730

	value: 196618 (0x3000A)
	*/
	SKTCaptureDeviceTypeScannerD730 = 196618,

	/**
	Model D740

	value: 196619 (0x3000B)
	*/
	SKTCaptureDeviceTypeScannerD740 = 196619,

	/**
	Model D750

	value: 196620 (0x3000C)
	*/
	SKTCaptureDeviceTypeScannerD750 = 196620,

	/**
	Model D760

	value: 196621 (0x3000D)
	*/
	SKTCaptureDeviceTypeScannerD760 = 196621,

	/**
	Model S700

	value: 196622 (0x3000E)
	*/
	SKTCaptureDeviceTypeScannerS700 = 196622,

	/**
	Model S730

	value: 196623 (0x3000F)
	*/
	SKTCaptureDeviceTypeScannerS730 = 196623,

	/**
	Model S740

	value: 196624 (0x30010)
	*/
	SKTCaptureDeviceTypeScannerS740 = 196624,

	/**
	Model S750

	value: 196625 (0x30011)
	*/
	SKTCaptureDeviceTypeScannerS750 = 196625,

	/**
	Model S760

	value: 196626 (0x30012)
	*/
	SKTCaptureDeviceTypeScannerS760 = 196626,

	/**
	Model S860

	value: 196627 (0x30013)
	*/
	SKTCaptureDeviceTypeScannerS860 = 196627,

	/**
	Model D790

	value: 196628 (0x30014)
	*/
	SKTCaptureDeviceTypeScannerD790 = 196628,

	/**
	Model D600

	value: 327701 (0x50015)
	*/
	SKTCaptureDeviceTypeScannerD600 = 327701,

	/**
	Model S550

	value: 327702 (0x50016)
	*/
	SKTCaptureDeviceTypeScannerS550 = 327702,

	/**
	NFC Tag

	value: 393239 (0x60017)
	*/
	SKTCaptureDeviceTypeNFCTag = 393239,

	/**
	device type unknown by this version of Capture

	value: 196632 (0x30018)
	*/
	SKTCaptureDeviceTypeBtUnknown = 196632,

	/**
	device manager for controlling BLE

	value: 17104897 (0x1050001)
	*/
	SKTCaptureDeviceTypeDeviceManagerBle = 17104897,

};


#endif //_SktCaptureDeviceTypes_h
