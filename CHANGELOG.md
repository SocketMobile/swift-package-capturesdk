# Change Log
This file tracks released versions with the changes made to this project.

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