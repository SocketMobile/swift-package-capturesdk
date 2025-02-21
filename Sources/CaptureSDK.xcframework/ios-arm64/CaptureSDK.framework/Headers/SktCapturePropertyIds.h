//
//  SktCapturePropertyIds.h
//  CaptureService
//
//  Copyright © 2017 Socket Mobile. All rights reserved.
//

#ifndef SktCapturePropertyIds_h
#define SktCapturePropertyIds_h

#import "SktCaptureDataSource.h"
#import "SktCaptureVersion.h"


typedef NS_ENUM(NSInteger, SKTCapturePropertyID) {
	/**
	Set to notify Capture that the client is shutting down gracefully.
	Capture will send device removal events followed by a terminate
	event. Once you receive the terminate event, it is safe to shut
	down Capture.

	Device: False	Get Type: NotApplicable 	Set Type: None
	*/
	SKTCapturePropertyIDAbort = -2146435072,

	/**
	Gets the Capture service version.

	Device: False	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDVersion = -2147418111,

	/**
	Gets the version of the firmware interface that Capture service
	supports. This can be useful for determining if the Capture service
	supports a particular hardware feature.

	Device: False	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDInterfaceVersion = -2147418112,

	/**
	property to set or get the Capture configuration

	Device: False	Get Type: String 	Set Type: String
	*/
	SKTCapturePropertyIDConfiguration = -2141913085,

	/**
	Gets or sets the data confirmation mode. The data confirmation mode
	determines who acknowledges whether the data received was good or
	bad.

	Device: False	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDDataConfirmationMode = -2147352572,

	/**
	Gets or sets the data confirmation action. Data confirmation action
	determines how good or bad data is acknowledged.

	Device: False	Get Type: None 	Set Type: Ulong
	*/
	SKTCapturePropertyIDDataConfirmationAction = -2147287035,

	/**
	Gets or sets the log level of various Capture service components
	(Only works on debug builds of the service).

	Device: False	Get Type: Byte 	Set Type: Array
	*/
	SKTCapturePropertyIDMonitorMode = -2145124346,

	/**
	property to get or set the SocketCam status
	(iOS only)

	Device: False	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDSocketCamStatus = -2147352569,

	/**
	Gets the firmware version of the device

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDVersionDevice = 65536,

	/**
	Gets the model of the device

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDDeviceType = 65538,

	/**
	Sends an arbitrary get or set command to the device

	Device: True	Get Type: Array 	Set Type: Array
	*/
	SKTCapturePropertyIDDeviceSpecific = 4456451,

	/**
	property to get or set the data source status / information

	Device: True	Get Type: DataSource 	Set Type: DataSource
	*/
	SKTCapturePropertyIDDataSourceDevice = 7798788,

	/**
	Sets the trigger of the device - can start or stop a read and
	enable or disable the physical trigger button on the device.

	Device: True	Get Type: NotApplicable 	Set Type: Byte
	*/
	SKTCapturePropertyIDTriggerDevice = 1179653,

	/**
	property to apply a config to a Capture Device (not yet enabled)

	Device: True	Get Type: NotApplicable 	Set Type: None
	*/
	SKTCapturePropertyIDApplyConfigDevice = 1048582,

	/**
	Gets or sets a preamble for data decoded by the device. When set,
	the preamble is added in front of the decoded data.

	Device: True	Get Type: None 	Set Type: String
	*/
	SKTCapturePropertyIDPreambleDevice = 327687,

	/**
	Gets or sets a postamble for data decoded by the device. When set,
	the postamble is added to the end of the decoded data.

	Device: True	Get Type: None 	Set Type: String
	*/
	SKTCapturePropertyIDPostambleDevice = 327688,

	/**
	property to get the Capture Device capabilities

	Device: True	Get Type: Byte 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDCapabilitiesDevice = 2162697,

	/**
	Gets the change id of the device. The change id is a checksum of
	all the engine settings - e.g. symbology settings, preamble,
	postamble, etc - and can be used to determine if the device
	configuration has been altered by another application or using a
	command barcode.

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDChangeIdDevice = 65546,

	/**
	property to get or set the Decoded Data Format of a Capture Device

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDDataFormatDevice = 131083,

	/**
	Gets or sets the friendly name of the device. The friendly name is
	the name that appears in Bluetooth settings.

	Device: True	Get Type: None 	Set Type: String
	*/
	SKTCapturePropertyIDFriendlyNameDevice = 327936,

	/**
	property to get or set the Capture Device Security Mode

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDSecurityModeDevice = 131329,

	/**
	property to get or set the Capture Device PIN code

	Device: True	Get Type: NotApplicable 	Set Type: String
	*/
	SKTCapturePropertyIDPinCodeDevice = 1376514,

	/**
	Set deletes pairing and bonding information off the device. Useful
	when preparing to pair the Capture device to a different host.

	Device: True	Get Type: NotApplicable 	Set Type: Byte
	*/
	SKTCapturePropertyIDDeletePairingBondingDevice = 1179907,

	/**
	Set resets all the settings on the device to their default values.

	Device: True	Get Type: NotApplicable 	Set Type: None
	*/
	SKTCapturePropertyIDRestoreFactoryDefaultsDevice = 1048836,

	/**
	Set turns the device off

	Device: True	Get Type: NotApplicable 	Set Type: None
	*/
	SKTCapturePropertyIDSetPowerOffDevice = 1048837,

	/**
	Gets the current state of each button on the device. Consider using
	kNotificationsDevice to subscribe to button events instead.

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDButtonsStatusDevice = 65792,

	/**
	Gets or sets the sound configuration of the device. There are
	separate sound configurations for when a good scan is acknowledged
	locally (by the Capture device) and when it is acknowledged by the
	host. The same applies to the bad scan sound configuration.

	Device: True	Get Type: Byte 	Set Type: Array
	*/
	SKTCapturePropertyIDSoundConfigDevice = 2359559,

	/**
	Gets or sets the trigger lock and auto-off timers. The trigger lock
	determines how long the trigger remains locked after decoding data
	without receiving confirmation. There are two auto-off timers, one
	for when the device is connected to a host and one for when it is
	not.

	Device: True	Get Type: None 	Set Type: Array
	*/
	SKTCapturePropertyIDTimersDevice = 262408,

	/**
	Gets or sets local device acknowledgement. When enabled, the device
	acknowledges decoded data as soon as it is decoded. When disabled,
	the device waits for the host to acknowledge decoded data and the
	trigger will be locked until acknowledgement is received or the
	trigger lock timeout has elapsed.

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDLocalAcknowledgmentDevice = 131337,

	/**
	Sends an acknowledgement to the device. Acknowledgement can either
	be positive or negative - a.k.a. good scan or bad scan.

	Device: True	Get Type: NotApplicable 	Set Type: Ulong
	*/
	SKTCapturePropertyIDDataConfirmationDevice = 1245450,

	/**
	Gets the current battery level of the device. Consider using 
	kNotificationsDevice to subscribe to battery level change events
	instead.

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDBatteryLevelDevice = 65803,

	/**
	Gets or sets the local decode action of the device. Determines how
	decoded data is acknowledged - i.e. with a beep, rumble, flash or
	some combination of all three.

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDLocalDecodeActionDevice = 131340,

	/**
	Gets the Bluetooth address of the device

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDBluetoothAddressDevice = 65805,

	/**
	Gets the statistics counters of the device. Counters record the
	absolute number of times a particular event has occurred.

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDStatisticCountersDevice = 65806,

	/**
	Gets or sets the rumble configuration of the device. There are
	separate rumble configurations for when a good scan is acknowledged
	locally (by the Capture device) and when it is acknowledged by the
	host. The same applies to the bad scan rumble configuration.

	Device: True	Get Type: Byte 	Set Type: Array
	*/
	SKTCapturePropertyIDRumbleConfigDevice = 2359567,

	/**
	property to get or set the Capture Device Profile Configuration

	Device: True	Get Type: None 	Set Type: Array
	*/
	SKTCapturePropertyIDProfileConfigDevice = 262416,

	/**
	Instructs the device to drop its connection. Note: After sending
	this command, the host will be unable to send any subsequent
	commands to this device.

	Device: True	Get Type: NotApplicable 	Set Type: Byte
	*/
	SKTCapturePropertyIDDisconnectDevice = 1179921,

	/**
	Gets or sets arbitrary bytes to store on the device. The device has
	16 storage locations which can hold up to 64 bytes each.

	Device: True	Get Type: Array 	Set Type: Array
	*/
	SKTCapturePropertyIDDataStoreDevice = 4456722,

	/**
	Gets or sets subscriptions to various events from the device.
	Events that can be subscribed to include, trigger press/release,
	power button press/release, power state and battery level change.

	Device: True	Get Type: None 	Set Type: Ulong
	*/
	SKTCapturePropertyIDNotificationsDevice = 196883,

	/**
	property to get the Capture Device Connect reason

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDConnectReasonDevice = 65812,

	/**
	Gets the current power state of the device. Consider using
	kNotificationsDevice to subscribe to power state events instead.

	Device: True	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDPowerStateDevice = 65813,

	/**
	Gets or sets the reconnect behavior of the device when it is
	powered on in application mode. By default, the device will attempt
	to reconnect to the last host, but this feature can be turned off
	using this property.

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDStartUpRoleSPPDevice = 131350,

	/**
	property to get or set the Capture Device Connection Beep
	Configuration.

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDConnectionBeepConfigDevice = 131351,

	/**
	Gets or sets the status of the flash on the SocketCam device.

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDFlashDevice = 131352,

	/**
	property to get or set the Capture Device Overlay View (SocketCam
	only)

	Device: True	Get Type: None 	Set Type: Object
	*/
	SKTCapturePropertyIDOverlayViewDevice = 590105,

	/**
	property to get or set the Capture Device Stand Configuration

	Device: True	Get Type: None 	Set Type: Ulong
	*/
	SKTCapturePropertyIDStandConfigDevice = 196890,

	/**
	property to start a BLE discovery from a Device Manager

	Device: True	Get Type: NotApplicable 	Set Type: Ulong
	*/
	SKTCapturePropertyIDStartDiscovery = 1245696,

	/**
	property to set or get the BLE favorites for a Device Manager

	Device: True	Get Type: None 	Set Type: String
	*/
	SKTCapturePropertyIDFavorite = 328193,

	/**
	property to get the BLE Unique Device Identifier that can be used to set favorite with

	Device: True	Get Type: String 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDUniqueDeviceIdentifier = 5308930,

	/**
	property to transmit through PC/SC an array of bytes often called APDU

	Device: True	Get Type: Array 	Set Type: Array
	*/
	SKTCapturePropertyIDPcScTagTransmit = 4456731,

	/**
	property to control the PC/SC coupler device by passing an array of bytes often called APDU

	Device: True	Get Type: Array 	Set Type: Array
	*/
	SKTCapturePropertyIDPcScCouplerControl = 4456732,

	/**
	property to define the theme that is used for the different events: Ready, Read, Read Success, Read Failure UI

	Device: True	Get Type: None 	Set Type: Array
	*/
	SKTCapturePropertyIDThemeSelectionDevice = 262429,

	/**
	property to define the theme selection mask. It applies the theme selection on the given device(s) set with the mask

	Device: True	Get Type: None 	Set Type: Array
	*/
	SKTCapturePropertyIDThemeSelectionMaskDevice = 262430,

	/**
	property to define if the Lasso feature is enabled or not

	Device: True	Get Type: None 	Set Type: Byte
	*/
	SKTCapturePropertyIDLassoStatusDevice = 131359,

	/**
	property to define the Lasso Id for a device

	Device: True	Get Type: NotApplicable 	Set Type: Array
	*/
	SKTCapturePropertyIDLassoIdDevice = 1311008,

	/**
	property to define the Lasso life span for a device

	Device: True	Get Type: None 	Set Type: Ulong
	*/
	SKTCapturePropertyIDLassoLifeSpanDevice = 196897,

	/**
	property to set a device's Permanent Partnership connection

	Device: False	Get Type: NotApplicable 	Set Type: None
	*/
	SKTCapturePropertyIDPermanentPartnership = -2146434782,

	/**
	property to get a stamp from the host for Permanent Partnership connection

	Device: False	Get Type: None 	Set Type: NotApplicable
	*/
	SKTCapturePropertyIDPermanentPartnershipStamp = -2147417821,


};

typedef NS_ENUM(NSInteger, SKTCapturePropertyType) {
	/** for capture properties that don't have any value */
	SKTCapturePropertyTypeNone,
	/** for capture properties that don't have a value for either a get operation or a set operation or neither of them. */
	SKTCapturePropertyTypeNotApplicable,
	/** the property has a byte value */
	SKTCapturePropertyTypeByte,
	/** the property has a unsigned long value */
	SKTCapturePropertyTypeUlong,
	/** the property has a byte array value */
	SKTCapturePropertyTypeArray,
	/** the property has a string value */
	SKTCapturePropertyTypeString,
	/** the property has a version structure as value (read only) */
	SKTCapturePropertyTypeVersion,
	/** the property has a data source structure as value */
	SKTCapturePropertyTypeDataSource,
	/** the property has an enum value */
	SKTCapturePropertyTypeEnum,
	/** the property has an object as value */
	SKTCapturePropertyTypeObject,
	/** the property type should not be equal or higher that kLast otherwise it means the SDK is not in sync with the actual version of Socket Mobile Companion running on the host */
	SKTCapturePropertyTypeLastType,

};

/**
 @brief Data Confirmation Mode indicates what is  expected to the send the Data ACK back to the scanner 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDataConfirmationMode) 
{
	/** use the device configuration (Local Confirmation or App) */
	SKTCaptureDataConfirmationModeModeOff=0,
	/** the device confirms the decoded data locally */
	SKTCaptureDataConfirmationModeModeDevice=1,
	/** Capture confirms the decoded data as it receives them and there is one app */
	SKTCaptureDataConfirmationModeModeCapture=2,
	/** the Application confirms the decoded data as it receives them */
	SKTCaptureDataConfirmationModeModeApp=3,
};

/**
 @brief Device Data Acknowledgment mode 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDeviceDataAcknowledgment) 
{
	/** the device won't locally acknowledge decoded data */
	SKTCaptureDeviceDataAcknowledgmentOff=0,
	/** the device will locally acknowledge decoded data */
	SKTCaptureDeviceDataAcknowledgmentOn=1,
};

/**
 @brief Security Mode 
*/
typedef NS_ENUM(NSInteger, SKTCaptureSecurityMode) 
{
	/** No security */
	SKTCaptureSecurityModeNone=0,
	/** communication protected by authentication */
	SKTCaptureSecurityModeAuthentication=1,
	/** communication protected by authentication and encrytion */
	SKTCaptureSecurityModeAuthenticationEncryption=2,
};

/**
 @brief trigger parameter 
*/
typedef NS_ENUM(NSInteger, SKTCaptureTrigger) 
{
	/** start a read */
	SKTCaptureTriggerStart=1,
	/** stop a read */
	SKTCaptureTriggerStop=2,
	/** enable the trigger */
	SKTCaptureTriggerEnable=3,
	/** disable the trigger */
	SKTCaptureTriggerDisable=4,
	/** start a read in continuous */
	SKTCaptureTriggerContinuousScan=5,
	/** start a read in continuous until a code is read */
	SKTCaptureTriggerContinuousScanUntilRead=6,
};

/**
 @brief Delete the pairing of the device 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDeletePairing) 
{
	/** delete the current pairing */
	SKTCaptureDeletePairingCurrent=0,
	/** delete all the pairing of the device */
	SKTCaptureDeletePairingAll=1,
};

/**
 @brief sound configuration for the a type of action 
*/
typedef NS_ENUM(NSInteger, SKTCaptureSoundActionType) 
{
	/** sound configuration for a good read action */
	SKTCaptureSoundActionTypeGoodRead=0,
	/** sound configuration for a good read local action */
	SKTCaptureSoundActionTypeGoodReadLocal=1,
	/** sound configuration for a bad read action */
	SKTCaptureSoundActionTypeBadRead=2,
	/** sound configuration for a bad read local action */
	SKTCaptureSoundActionTypeBadReadLocal=3,
};

/**
 @brief Sound frequency configuration 
*/
typedef NS_ENUM(NSInteger, SKTCaptureSoundFrequency) 
{
	/** no frequency */
	SKTCaptureSoundFrequencyNone=0,
	/** Low pitch frequency */
	SKTCaptureSoundFrequencyLow=1,
	/** Medium pitch frequency */
	SKTCaptureSoundFrequencyMedium=2,
	/** High pitch frequency */
	SKTCaptureSoundFrequencyHigh=3,
};

/**
 @brief Rumble configuration for the a type of action 
*/
typedef NS_ENUM(NSInteger, SKTCaptureRumbleActionType) 
{
	/** Rumble configuration for a good read action */
	SKTCaptureRumbleActionTypeGoodRead=0,
	/** Rumble configuration for a good read local action */
	SKTCaptureRumbleActionTypeGoodReadLocal=1,
	/** Rumble configuration for a bad read action */
	SKTCaptureRumbleActionTypeBadRead=2,
	/** Rumble configuration for a bad read local action */
	SKTCaptureRumbleActionTypeBadReadLocal=3,
};

/**
 @brief Define the action for a local decode 
*/
typedef NS_OPTIONS(NSInteger, SKTCaptureLocalDecodeAction) 
{
	/** no action */
	SKTCaptureLocalDecodeActionNone=0,
	/** Beep when a local decode occurs */
	SKTCaptureLocalDecodeActionBeep=1,
	/** Flash the LED when a local decode occurs */
	SKTCaptureLocalDecodeActionFlash=2,
	/** Rumble when a local decode occurs */
	SKTCaptureLocalDecodeActionRumble=4,
};

/**
 @brief Define the LED for data confirmation 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDataConfirmationLed) 
{
	/** no LED */
	SKTCaptureDataConfirmationLedNone=0,
	/** make the LED flash in green */
	SKTCaptureDataConfirmationLedGreen=1,
	/** make the LED flash in red */
	SKTCaptureDataConfirmationLedRed=2,
};

/**
 @brief Define the sound for data confirmation 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDataConfirmationBeep) 
{
	/** no sound */
	SKTCaptureDataConfirmationBeepNone=0,
	/** short beep for success */
	SKTCaptureDataConfirmationBeepGood=1,
	/** long beep for failure */
	SKTCaptureDataConfirmationBeepBad=2,
};

/**
 @brief Define the rumble for data confirmation 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDataConfirmationRumble) 
{
	/** no sound */
	SKTCaptureDataConfirmationRumbleNone=0,
	/** short rumble for success */
	SKTCaptureDataConfirmationRumbleGood=1,
	/** long rumble for failure */
	SKTCaptureDataConfirmationRumbleBad=2,
};

/**
 @brief Define the flash setting 
*/
typedef NS_ENUM(NSInteger, SKTCaptureFlash) 
{
	/** turn off the flash */
	SKTCaptureFlashOff=0,
	/** turn on the flash */
	SKTCaptureFlashOn=1,
};

/**
 @brief Define the SocketCam experience 
*/
typedef NS_ENUM(NSInteger, SKTCaptureSocketCam) 
{
	/** Enable SocketCam */
	SKTCaptureSocketCamEnable=0,
	/** Disable SocketCam */
	SKTCaptureSocketCamDisable=1,
	/** SocketCam is not supported, and cannot be enabled */
	SKTCaptureSocketCamNotSupported=2,
};

/**
 @brief Define the possible power states 
*/
typedef NS_ENUM(NSInteger, SKTCapturePowerState) 
{
	/** The power state is unknown */
	SKTCapturePowerStateUnknown=0,
	/** The power state is on battery */
	SKTCapturePowerStateOnBattery=1,
	/** The power state is on cradle */
	SKTCapturePowerStateOnCradle=2,
	/** The power state in on AC */
	SKTCapturePowerStateOnAc=4,
};

/**
 @brief Define the monitor feature (DEBUG build only) 
*/
typedef NS_ENUM(NSInteger, SKTCaptureMonitorDbg) 
{
	/** define the level for the debug traces */
	SKTCaptureMonitorDbgLevel=1,
	/** define the output channel for the debug traces */
	SKTCaptureMonitorDbgChannel=2,
	/** define the number of lines in the file */
	SKTCaptureMonitorDbgFileLineLevel=3,
};

/**
 @brief identifiers for the statistic counters 
*/
typedef NS_ENUM(NSInteger, SKTCaptureCounter) 
{
	/** use for convenience only to skip a counter */
	SKTCaptureCounterSkip=-1,
	/** unknow counter */
	SKTCaptureCounterUnknown=0,
	/** number of connections */
	SKTCaptureCounterConnect=1,
	/** number of disconnections */
	SKTCaptureCounterDisconnect=2,
	/** number of unbound operation */
	SKTCaptureCounterUnbound=3,
	/** number of reset to factory default */
	SKTCaptureCounterFactoryReset=4,
	/** number of reads (scans) */
	SKTCaptureCounterReads=5,
	/** number of trigger button released */
	SKTCaptureCounterTriggerButtonUp=6,
	/** number of trigger button pressed */
	SKTCaptureCounterTriggerButtonDown=7,
	/** number of power button released */
	SKTCaptureCounterPowerButtonUp=8,
	/** number of power button pressed */
	SKTCaptureCounterPowerButtonDown=9,
	/** number of minutes in AC power */
	SKTCaptureCounterOnAcTimeInMinutes=10,
	/** number of minutes on battery */
	SKTCaptureCounterOnBatTimeInMinutes=11,
	/** number of RFCOMM sent (SSI only) */
	SKTCaptureCounterRfcommSend=12,
	/** number of RFCOMM received (SSI only) */
	SKTCaptureCounterRfcommReceive=13,
	/** number of RFCOMM discarded (SSI only) */
	SKTCaptureCounterRfcommReceiveDiscarded=14,
	/** number of UART sent (SSI only) */
	SKTCaptureCounterUartSend=15,
	/** number of UART received (SSI only) */
	SKTCaptureCounterUartReceive=16,
	/** number of UART discarded (SSI only) */
	SKTCaptureCounterUartReceiveDiscarded=17,
	/** number of left button press (CRS only) */
	SKTCaptureCounterButtonLeftPress=18,
	/** number of left button release (CRS only) */
	SKTCaptureCounterButtonLeftRelease=19,
	/** number of right button press (CRS only) */
	SKTCaptureCounterButtonRightPress=20,
	/** number of right button release (CRS only) */
	SKTCaptureCounterButtonRightRelease=21,
	/** number of ring unit detach (CRS only) */
	SKTCaptureCounterRingUnitDetach=22,
	/** number of ring unit attach (CRS only) */
	SKTCaptureCounterRingUnitAttach=23,
	/** number of decoded bytes (7x only ISCI) */
	SKTCaptureCounterDecodedBytes=24,
	/** number of abnormal shutdowns (7x only ISCI) */
	SKTCaptureCounterAbnormalShutdowns=25,
	/** number of battery charge cycles (7x only ISCI) */
	SKTCaptureCounterBatteryChargeCycles=26,
	/** number of battery charge count (7x only ISCI) */
	SKTCaptureCounterBatteryChargeCount=27,
	/** number of power on (only 8Ci) */
	SKTCaptureCounterPowerOn=28,
	/** number of power off (only 8Ci) */
	SKTCaptureCounterPowerOff=29,
	/** number of stand mode change (only 7X/Q 7630 and higher) */
	SKTCaptureCounterStandModeChange=30,
};

/**
 @brief Disconnect parameters to instruct the device what to do after disconnection 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDisconnect) 
{
	/** disconnect and then start the current profile */
	SKTCaptureDisconnectStartProfile=0,
	/** Disconnect and disable radio (low power) */
	SKTCaptureDisconnectDisableRadio=1,
	/** Disconnect a device and make it available for a new connection (for Bluetooth Low Energy device) */
	SKTCaptureDisconnectMakeAvailable=2,
};

/**
 @brief Select a profile for the device (None, SPP, HID, Reader, Coupler) 
*/
typedef NS_ENUM(NSInteger, SKTCaptureProfileSelect) 
{
	/** The device is in acceptor mode, not trying to connect to any host */
	SKTCaptureProfileSelectNone=0,
	/** The device is in App mode */
	SKTCaptureProfileSelectSpp=1,
	/** The device is in Basic mode, sometimes referred as Keyboard emulation */
	SKTCaptureProfileSelectHid=2,
	/** The device is in Reader mode, for NFC devices */
	SKTCaptureProfileSelectReader=3,
	/** The device is in Coupler mode, for NFC devices */
	SKTCaptureProfileSelectCoupler=4,
};

/**
 @brief Configure a profile for the device (None, Acceptor, Initiator) 
*/
typedef NS_ENUM(NSInteger, SKTCaptureProfileConfig) 
{
	/** The device is in either acceptor or initiator mode, meaning not even discoverable */
	SKTCaptureProfileConfigNone=0,
	/** The device is discoverable and will accept any connection */
	SKTCaptureProfileConfigAcceptor=1,
	/** The device initiates a connection to the Bluetooth address specified in the Profile Configuration */
	SKTCaptureProfileConfigInitiator=2,
};

/**
 @brief Configuration masks for selecting the notifications the device should send to the host 
*/
typedef NS_OPTIONS(NSInteger, SKTCaptureNotifications) 
{
	/** The device sends a notification when the trigger button is pressed */
	SKTCaptureNotificationsTriggerButtonPress=1,
	/** The device sends a notification when the trigger button is released */
	SKTCaptureNotificationsTriggerButtonRelease=2,
	/** The device sends a notification when the power button is pressed */
	SKTCaptureNotificationsPowerButtonPress=4,
	/** The device sends a notification when the power button is released */
	SKTCaptureNotificationsPowerButtonRelease=8,
	/** The device sends a notification when the power state changes (battery to AC or vice-versa) (not supported on all device) */
	SKTCaptureNotificationsPowerState=16,
	/** The device sends a notification when the battery level changed (not supported on all device) */
	SKTCaptureNotificationsBatteryLevelChange=32,
};

/**
 @brief Identifies the timers used in the device, (trigger lock, disconnected, connected) 
*/
typedef NS_ENUM(NSInteger, SKTCaptureTimer) 
{
	/** The trigger button stays ineffective for the specified amount of time  or until the device receives a data confirmation command. */
	SKTCaptureTimerAutoLock=1,
	/** This timer specifies the amount of time the device stays on while it is not connected to any host. */
	SKTCaptureTimerPowerOffDisconnected=2,
	/** This timer specifies the amount of time the device stays on while it is connected to a host. */
	SKTCaptureTimerPowerOffConnected=4,
};

/**
 @brief Identifies the data format the device should send the data to the host 
*/
typedef NS_ENUM(NSInteger, SKTCaptureDataFormat) 
{
	/** The device sends the data without any protocol overhead */
	SKTCaptureDataFormatRaw=0,
	/** The device sends the data embedded in a protocol packet (default) */
	SKTCaptureDataFormatPacket=1,
	/** The device sends only the RFID tag ID, (valid only for D600 NFC devices) */
	SKTCaptureDataFormatIdOnly=2,
	/** The device sends the tag type and RFID tag ID, (valid only for D600 NFC devices) */
	SKTCaptureDataFormatTagTypeAndId=10,
	/** The device sends only the tag data, (valid only for D600 NFC devices) */
	SKTCaptureDataFormatDataOnly=4,
	/** The device sends the tag type and the tag data, (valid only for D600 NFC devices) */
	SKTCaptureDataFormatTagTypeAndData=12,
};

/**
 @brief defines the operational mode of the device 
*/
typedef NS_ENUM(NSInteger, SKTCaptureTriggerMode) 
{
	/** The device triggers a read only by pressing the trigger button */
	SKTCaptureTriggerModeLocalOnly=1,
	/** The device triggers a read by pressing the trigger button or by receiving the trigger command */
	SKTCaptureTriggerModeRemoteAndLocal=2,
	/** the device waits for the host to unlock the trigger */
	SKTCaptureTriggerModeAutoLock=3,
	/** the device locks and unlocks the trigger locally (default) */
	SKTCaptureTriggerModeNormalLock=4,
	/** The device triggers a read automatically without user intervention */
	SKTCaptureTriggerModePresentation=5,
};

/**
 @brief defines the reason as of how the device connects to the host 
*/
typedef NS_ENUM(NSInteger, SKTCaptureConnectReason) 
{
	/** The device connects to the host from unknown reason */
	SKTCaptureConnectReasonUnknown=0,
	/** The device connects to the host just after power on */
	SKTCaptureConnectReasonPowerOn=1,
	/** The device connects to the host by reading the host address from a barcode */
	SKTCaptureConnectReasonBarcode=2,
	/** The device connects to the host by user action (usually a press on the trigger button) */
	SKTCaptureConnectReasonUserAction=3,
	/** The device connects to the host from a change of the host address in the profile configuration */
	SKTCaptureConnectReasonHostChange=4,
	/** The device connects to the host after a retry (device coming back to the radio range) */
	SKTCaptureConnectReasonRetry=5,
};

/**
 @brief The start up role SPP defines the start up role when using the SPP profile. 
*/
typedef NS_ENUM(NSInteger, SKTCaptureStartUpRoleSpp) 
{
	/** The device returns to acceptor mode, not initiating a connection to a host. */
	SKTCaptureStartUpRoleSppAcceptor=0,
	/** The device uses the last role configuration upon startup. */
	SKTCaptureStartUpRoleSppLastRole=1,
};

/**
 @brief The connect beep configuration allows to turn off or on the connection beep when the scanner connects 
*/
typedef NS_ENUM(NSInteger, SKTCaptureConnectBeepConfig) 
{
	/** The device won't beep upon connection to a host. */
	SKTCaptureConnectBeepConfigNoBeep=0,
	/** The device beeps when connecting to the host. */
	SKTCaptureConnectBeepConfigBeep=1,
};

/**
 @brief The stand configuration defines the operational mode of the device when used with a stand. 
*/
typedef NS_ENUM(NSInteger, SKTCaptureStandConfig) 
{
	/** Disabled the stand config property and sets the scanner as it is intended */
	SKTCaptureStandConfigDisabled=0,
	/** Mobile mode Works like today existing firmware Engine is always in   trigger mode Engine hibernate enabled */
	SKTCaptureStandConfigMobileMode=1,
	/** Stand mode Engine always in presentation mode Engine hibernate  disabled Scanner turns on immediately Power timers disabled Connection  retries forever */
	SKTCaptureStandConfigStandMode=2,
	/** Detect mode On stand engine in presentation mode On stand engine  hibernate disabled On stand charging led state not show On stand  scanner turns on immediately On stand power timers disabled On stand  connection retries forever Off stand engine in level mode Off stand  battery led state reported Off stand engine hibernate enabled Off stand  power off timers running Off stand connection retries halt after max  count */
	SKTCaptureStandConfigDetectMode=3,
	/** Auto mode On stand engine in presentation mode On stand engine hibernate  disabled On stand charging led state not show On stand scanner turns on  immediately On stand power timers disabled On stand connection retries  forever Off stand does nothing, engine remains in presentation mode Off  stand trigger press causes engine to enter level mode Engine in level  mode battery led state reported Engine in level mode hibernate enabled  Engine in level mode power off timers running Engine in level mode  connection retries halt after max count */
	SKTCaptureStandConfigAutoMode=4,
};

/**
 @brief The mask to apply for each button that is pressed 
*/
typedef NS_OPTIONS(UInt8, SKTCaptureButtonsState) 
{
	/** The left button is pressed. */
	SKTCaptureButtonsStateLeft=0x01,
	/** The right button is pressed. */
	SKTCaptureButtonsStateRight=0x02,
	/** The middle button is pressed. */
	SKTCaptureButtonsStateMiddle=0x04,
	/** The power button is pressed. */
	SKTCaptureButtonsStatePower=0x08,
	/** The Ring is detached from the wrist unit. */
	SKTCaptureButtonsStateRingDetach=0x16,
};

/**
 @brief The mask to apply for each theme 
*/
typedef NS_ENUM(NSInteger, SKTCaptureThemeSelection) 
{
	/** No theme. */
	SKTCaptureThemeSelectionNone=0,
	/** The Health theme. */
	SKTCaptureThemeSelectionHealth=1,
	/** The Access theme. */
	SKTCaptureThemeSelectionAccess=2,
	/** The Value theme. */
	SKTCaptureThemeSelectionValue=3,
	/** The Membership theme. */
	SKTCaptureThemeSelectionMembership=4,
};

/**
 @brief Mask for the Theme selection property. It applies the theme selection on the given device(s) set with the mask 
*/
typedef NS_OPTIONS(UInt8, SKTCaptureThemeSelectionMask) 
{
	/** Mask applied on the Default device */
	SKTCaptureThemeSelectionMaskDefault=0x01,
	/** Mask applied on the Nfc device */
	SKTCaptureThemeSelectionMaskNfc=0x02,
	/** Mask applied on the Default and Nfc devices */
	SKTCaptureThemeSelectionMaskDefaultNfc=0x03,
	/** Mask applied on the Barcode device */
	SKTCaptureThemeSelectionMaskBarcode=0x04,
	/** Mask applied on the Default and Barcode devices */
	SKTCaptureThemeSelectionMaskDefaultBarcode=0x05,
	/** Mask applied on the Nfc and Barcode devices */
	SKTCaptureThemeSelectionMaskNfcBarcode=0x06,
	/** Mask applied on the Default, Nfc and Barcode devices */
	SKTCaptureThemeSelectionMaskAll=0x07,
};

/**
 @brief Define the Lasso experience 
*/
typedef NS_ENUM(NSInteger, SKTCaptureLassoDeviceStatus) 
{
	/** Disable Lasso */
	SKTCaptureLassoDeviceStatusDisable=0,
	/** Enable Lasso */
	SKTCaptureLassoDeviceStatusEnable=1,
};


/**
 @class SKTCaptureProperty

 @brief define a Capture Property composed by a Property ID, a Property Type and
 an eventual property parameter of the specified type.

 */
@interface SKTCaptureProperty : NSObject

/**
 @brief get or set the property ID
 */
@property SKTCapturePropertyID ID;

/**
 @brief get or set the type of the property parameter
 */
@property SKTCapturePropertyType Type;

/**
 @brief property array of byte parameter
 */
@property (nullable, nonatomic, strong) NSData* ArrayValue;

/**
 @brief property string parameter
 */
@property (nullable, nonatomic, strong) NSString* StringValue;

/**
 @brief property byte value parameter
 */
@property int8_t ByteValue;

/**
 @brief property unsigned long integer parameter
 */
@property unsigned long ULongValue;

/**
 @brief property version parameter
 */
@property (nullable, nonatomic, strong) SKTCaptureVersion* Version;

/**
 @brief property data source parameter
 */
@property (nullable, nonatomic, strong) SKTCaptureDataSource* DataSource;

/**
 @brief property user context
 */
@property (nullable) void *Context;

/**
 @brief property pointer to object parameter
 */
@property (nullable, retain) NSObject *Object;

/**
 @brief initialize the property object
 */
-(instancetype _Nonnull ) init;

@end

#endif /* SktCapturePropertyIds_h */

