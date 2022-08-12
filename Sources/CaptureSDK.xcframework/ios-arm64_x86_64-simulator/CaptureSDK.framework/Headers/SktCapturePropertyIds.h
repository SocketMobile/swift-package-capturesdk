//
//  SktCapturePropertyIds.h
//  CaptureService
//
//  Copyright © 2017 Socket Mobile. All rights reserved.
//

#ifndef SktCapturePropertyIds_h
#define SktCapturePropertyIds_h



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
	SKTCapturePropertyIDButtonsStatusDevice = 65798,

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


};

#endif
