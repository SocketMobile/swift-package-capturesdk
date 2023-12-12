# Change Log
This file tracks released versions with the changes made to this project.

## DEPRECATION
  * SocketCam C860 is available through our [Developer Portal](https://www.socketmobile.com/developers/portal). For more information and how to access, please visit our page [about this new product](https://www.socketmobile.com/readers-accessories/product-families/socketcam).
  * Beyond SocketCam C860, we have introduced a new feature. SocketCam C820 and SocketCam C860 are available for developers as view controllers that can be adapted to the size and position required in their workflow, and not only as full screen.

## [Version 1.8.34](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.8.34)
### New
  * Minimum target deployment: iOS 12.0
  * CaptureSDK is [signed](https://developer.apple.com/videos/play/wwdc2023/10061/) and [contains the Privacy manifest file](https://developer.apple.com/videos/play/wwdc2023/10060/) as required by Apple from iOS17

### Improvements
  * N/A

### Bug fixes
  * Bluetooth Manager crashed should be now fixed

## [Version 1.7.11](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.7.11)
### New
  * N/A

### Improvements
  * N/A

### Bug fixes
  * The Special configuration flag added in version 1.7.9 was causing the Bluetooth Classic connection not starting. It's still possible to enable this flag (given on request through developer@socketmobile.com)

## [Version 1.7.9](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.7.9)
### New
  * N/A

### Improvements
  * N/A

### Bug fixes
  * Special configuration flag added to avoid launching the Bluetooth Low Energy Manager that might crash in certain cases (given on request through developer@socketmobile.com)

## [Version 1.7.5](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.7.5)
### New
  * Compatibility with the new device M930

### Improvements
  * Add a SocketCam section in the documentation

### Bug fixes
  * The stand/kiosk mode is now working properly (property SKTCaptureStandConfig)

## [Version 1.6.39](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.6.39)
### New
  * n/a

### Improvements
  * Add `getDeviceManagersList` to CaptureHelper Objective-C
  * Add Get/Set Property methods for CaptureHelperDeviceManager to CaptureHelper Objective-C  

### Bug fixes
  * Bluetooth connection on iPadOS 16.5 is retained by an application containing CaptureSDK. This issue is now fixed
  * Fix get battery level command for S550 and S370

## [Version 1.6.34](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.6.34)
### New
  * n/a

### Improvements
  * n/a

### Bug fixes
  * Fix warning due to SktCaptureProperty.h file still present even though it shouldn't in CaptureSDK/Headers directories

## [Version 1.6.33](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.6.33)
### New
  * n/a

### Improvements
  * n/a

### Bug fixes
  * Fix crash when the S370 is disconnecting

## [Version 1.6.30](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.6.30)
### New
  * Compatibility with the new combo device S370 that contains a NFC reader/writer and a Barcode scanner
  * Add trigger and themes selection properties to S550 and S370
  * Add the Power State characteristic to the D600

### Improvements
  * Some string and methods of CryptoSwift conflicting with developers's projects are now solved [#7](https://github.com/SocketMobile/swift-package-capturesdk/issues/7)

### Bug fixes
  * Some developers reported that the Bluetooth Low Energy manager crashes. It is now fixed
  * Fix crash when connecting to D600

## [Version 1.5.9](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.5.9)
### New
  * n/a

### Improvements
  * n/a

### Bug fixes
  * The Bluetooth Low Energy manager had a small issue discovering and connecting several devices after a reconnection/restart of those devices. It is now fixed and you should be able to restart devices and being reconnected again

## [Version 1.5.7](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.5.7)
### New
  * CaptureSDK is now build with Xcode 14, supporting iOS16

### Improvements
  * Bitcode has been disabled. If you need a version of CaptureSDK with Bitcode enabled, [please take the previous version 1.5.5](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.5.5)

### Bug fixes
  * n/a

## [Version 1.5.5](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.5.5)
### New
  * n/a

### Improvements
  * Bitcode has been enabled. Please note that from Xcode 14, it will no longer build bitcode by default. See [Xcode release notes](https://developer.apple.com/documentation/Xcode-Release-Notes/xcode-14-release-notes)

### Bug fixes
  * n/a

## [Version 1.5.2](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.5.2)
### New
  * Compatibility with the new devices S720/D720/S820
  * Battery level notification added for the S550

### Improvements
  * n/a

### Bug fixes
  * n/a

## [Version 1.4.61](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.4.61)
### New
  * You can close the connection to a Bluetooth Low Energy device with a new property ID: SKTCapturePropertyIDDisconnectDevice and value: SKTCaptureDisconnectMakeAvailable

### Improvements
  * n/a

### Bug fixes
  * n/a

## [Version 1.4.57](https://github.com/SocketMobile/swift-package-capturesdk/releases/tag/1.4.57)
### New
  * CaptureSDK is now a [Swift Package Manager](https://github.com/SocketMobile/swift-package-capturesdk) 🎉🎉🎉

### Improvements
  * n/a

### Bug fixes
  * n/a