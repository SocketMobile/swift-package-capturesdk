// swift-tools-version:5.6

/*
 * CaptureSDK Swift Package for iOS
 */

import PackageDescription

let package = Package(
    name: "CaptureSDK",
    platforms: [
        .iOS(.v12)
    ],
    products: [
        .library(
            name: "CaptureSDK",
            targets: [
                "CaptureSDK"
            ]
        )
    ],
    targets: [
        .binaryTarget(
            name: "CaptureSDK",
            path: "Sources/CaptureSDK.xcframework"
        )
    ]
)
