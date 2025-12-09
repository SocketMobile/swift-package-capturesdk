//
//  SktCaptureEventIds.h
//  CaptureService
//
//  Copyright © 2017 Socket Mobile. All rights reserved.
//

#ifndef SktCaptureEventIds_h
#define SktCaptureEventIds_h



@class SKTCaptureEventData;

typedef NS_ENUM(NSInteger, SKTCaptureEventDataType) {
	/**
	For capture events that don't have any value.
	*/
	SKTCaptureEventDataTypeNone = 0,

	/**
	The event has a byte value.
	*/
	SKTCaptureEventDataTypeByte = 1,

	/**
	The event has a unsigned long value.
	*/
	SKTCaptureEventDataTypeUlong = 2,

	/**
	The event has a byte array value.
	*/
	SKTCaptureEventDataTypeArray = 3,

	/**
	The event has a string value.
	*/
	SKTCaptureEventDataTypeString = 4,

	/**
	The event has a decoded data structure as value.
	*/
	SKTCaptureEventDataTypeDecodedData = 5,

	/**
	The event has a device info structure as value (read only).
	*/
	SKTCaptureEventDataTypeDeviceInfo = 6,

	/**
	The event has an object structure (array, map, dictionary) as value (read only).
	*/
	SKTCaptureEventDataTypeObject = 7,

	/**
	The event type should not be equal or higher that kLastID otherwise
	it means the SDK is not in sync with the actual version of Socket
	Mobile Companion running on the host.
	*/
	SKTCaptureEventDataTypeLastID = 8,

};

typedef NS_ENUM(NSInteger, SKTCaptureEventID) {
	/**
	Capture has not been correctly initialized after its first open.

	Type: kNone
	*/
	SKTCaptureEventIDNotInitialized = 0,

	/**
	Event when a device has connected or is present.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDDeviceArrival = 1,

	/**
	Event when a device is no longer present.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDDeviceRemoval = 2,

	/**
	Event when Capture is terminated.

	Type: kUlong
	*/
	SKTCaptureEventIDTerminate = 3,

	/**
	Event when Capture had an error.

	Type: kUlong
	*/
	SKTCaptureEventIDError = 4,

	/**
	Event when Capture has some decoded data available.

	Type: kDecodedData
	*/
	SKTCaptureEventIDDecodedData = 5,

	/**
	Event when a device sends a power change notification.

	Type: kUlong
	*/
	SKTCaptureEventIDPower = 6,

	/**
	Event when the device button status has changed.

	Type: kUlong
	*/
	SKTCaptureEventIDButtons = 7,

	/**
	Event when the battery Level has changed.

	Type: kUlong
	*/
	SKTCaptureEventIDBatteryLevel = 8,

	/**
	Event when the communication listener thread has started.

	Type: kUlong
	*/
	SKTCaptureEventIDListenerStarted = 9,

	/**
	Event when a device ownership has changed.

	Type: kString
	*/
	SKTCaptureEventIDDeviceOwnership = 10,

	/**
	Event when the Device Manager (BLE) is present.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDDeviceManagerArrival = 11,

	/**
	Event when the Device Manager (BLE) is gone.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDDeviceManagerRemoval = 12,

	/**
	A device has been discovered.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDDeviceDiscovered = 13,

	/**
	The device discovery has ended.

	Type: kNone
	*/
	SKTCaptureEventIDDiscoveryEnd = 14,

	/**
	Event when a PC/SC device in coupler mode is present.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDPcscCouplerArrival = 15,

	/**
	Event when a PC/SC device in coupler mode is gone.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDPcscCouplerRemoval = 16,

	/**
	Event when a Tag is present in PC/SC mode.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDPcscTagArrival = 17,

	/**
	Event when a Tag is gone in PC/SC mode.

	Type: kDeviceInfo
	*/
	SKTCaptureEventIDPcscTagRemoval = 18,

	/**
	Event when a Tag Transmit response is received.

	Type: kArray
	*/
	SKTCaptureEventIDPcscTagTransmitResponse = 19,

	/**
	Event when a PC/SC Device Control Response is received.

	Type: kArray
	*/
	SKTCaptureEventIDPcscDeviceControlResponse = 20,

	/**
	The Last Event should always be the last ID in the list of possible events.

	Type: kNone
	*/
	SKTCaptureEventIDLastID = 21,

};


/**
    @class SKTCaptureEvent

    @brief define a Capture event, which has an ID, a data type and data.
 */
@interface SKTCaptureEvent : NSObject

/** @brief get or set the Capture event ID */
@property SKTCaptureEventID ID;

/** @brief get or set the Capture event data */
@property (nullable, nonatomic, strong) SKTCaptureEventData *Data;

@end


/**
 @class SKTCaptureDecodedData

 @brief define a Capture event Decoded Data, which has a Symbology ID, Symbology Name and decoded data.
 */
@interface SKTCaptureDecodedData : NSObject

/** @brief get the decoded data source ID */
@property SKTCaptureDataSourceID DataSourceID;

/** @brief get the data source name */
@property (nullable, nonatomic, strong) NSString *DataSourceName;

/** @brief get the decoded data*/
@property (nullable, nonatomic, strong) NSData *DecodedData;

/** @brief get the NFC Tag ID data*/
@property (nullable, nonatomic, strong) NSData *TagIdData;

/**
 @brief get the decoded data as string UTF8 encoded

 @remark there is no guaranty this property displays
        the decoded data if the data in the barcode
        are not UTF8 encoded.
 */
-(NSString * _Nullable)stringFromDecodedData;

/**

 @brief get the decoded data as string with the encoding of your choice

 @remark there is no guaranty this property displays
        the decoded data if the data in the barcode
        are not the chose encoding.
 */
-(NSString * _Nullable)stringFromDecodedDataWithEncoding:(NSStringEncoding)encoding;

/**
 @brief get the NFC Tag Id data as string
 */
-(NSString * _Nullable)stringFromTagIdData;

@end

/**
 @class SKTCaptureDeviceInfo

 @brief contains the information about the device such as
        the device type, the device GUID
 */
@interface SKTCaptureDeviceInfo : NSObject

/**
 @brief Name of the device
 */
@property (nullable, retain, nonatomic) NSString *Name;

/**
 @brief GUID of the device
 */
@property (nullable, retain, nonatomic) NSString *Guid;

/**
 @brief Handle of the device
 */
@property SKTHandle _Nullable Handle;

/**
 @brief Device Type: (D750, S800 etc..)
 */
@property SKTCaptureDeviceType DeviceType;

@end

/**
 @class SKTCaptureDiscoveredDeviceInfo

 @brief contains the information about the discovered device from a manual discovery process
 */
@interface SKTCaptureDiscoveredDeviceInfo : NSObject

/**
 @brief Name of the device
 */
@property (nullable, retain, nonatomic) NSString *Name;

/**
 @brief IdentifierUuid of the device
 */
@property (nullable, retain, nonatomic) NSString *IdentifierUuid;

/**
 @brief ServiceUuid of the device
 */
@property (nullable, retain, nonatomic) NSString *ServiceUuid;

@end

/**
 @class SKTCaptureEventData
 @brief Contains the definition of the data attached to a Capture event.
 */
@interface SKTCaptureEventData : NSObject
/**
 @brief Type of the data (Byte, Long, Array etc...)
 */
@property SKTCaptureEventDataType Type;

/**
 @brief Byte value, only relevant if the Type is <b>SKTCaptureEventDataTypeByte</b>
 */
@property int8_t ByteValue;

/**
 @brief Ulong value, only relevant if the Type is <b>SKTCaptureEventDataTypeUlong</b>
 */
@property unsigned long ULongValue;

/**
 @brief String value, only relevant if the Type is <b>SKTCaptureEventDataTypeString</b>
 */
@property (nullable, nonatomic, strong) NSString *StringValue;

/**
 @brief Array value, only relevant if the Type is <b>SKTCaptureEventDataTypeArray</b>
 */
@property (nullable, nonatomic, strong) NSData *ArrayValue;

/**
 @brief Decoded data value, only relevant if the Type is <b>SKTCaptureEventDataTypeDecodedData</b>
 */
@property (nullable, nonatomic, strong) SKTCaptureDecodedData *DecodedData;

/**
 @brief Device info value, only relevant if the Type is <b>SKTCaptureEventDataTypeDeviceInfo</b>
 */
@property (nullable, nonatomic, strong) SKTCaptureDeviceInfo *DeviceInfo;

/**
 @brief Device info value, only relevant if the Type is <b>SKTCaptureEventDataTypeObject</b>
 */
@property (nullable, nonatomic, strong) SKTCaptureDiscoveredDeviceInfo *DiscoveredDeviceInfo;

@end

#endif /* SktCaptureEvent_h */
