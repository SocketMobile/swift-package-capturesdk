// swift-tools-version:5.6

/*
 * CaptureSDK Swift Package for iOS
 */

import PackageDescription

let package = Package(
    name: "CaptureSDK",
    platforms: [
        .iOS(.v15)
    ],
    products: [
        .library(
            name: "CaptureSDK",
            targets: [
                "CaptureSDKFramework", "SwiftDecoderCaptureSDK"
            ]
        )
    ],
    dependencies: [
        .package(url: "https://github.com/SocketMobile/swift-package-swiftdecodersdk.git", exact: "6.4.0")
    ],
    targets: [
        .target(
            name: "CaptureSDKFramework",
            dependencies: ["CaptureSDKBinaryTarget"],
            path: "Sources/CaptureSDKDummy"
        ),
        .target(
            name: "SwiftDecoderCaptureSDK",
            dependencies: [
                .product(name: "SwiftDecoderSDK", package: "swift-package-swiftdecodersdk"),
            ],
            path: "Sources/SwiftDecoderDummy"
        ),
        .binaryTarget(
            name: "CaptureSDKBinaryTarget",
            path: "Sources/CaptureSDK.xcframework"
        )
    ]
)
