# ********************************************************
# THIS REPOSITORY HAS BEEN MOVED BEHIND OUR [DEVELOPERS PORTAL](https://www.socketmobile.com/dev-portal/portal)
# BUT PLEASE WATCH 👁️‍🗨️ ALL ACTIVITY IT AS WE REPORT THE README AND CHANGELOG HERE. YOU'LL BE NOTIFIED WITH:
# - Bug fixes
# - OS version update
# - Support of new products
# ********************************************************


# iOS CaptureSDK - Swift Package Manager

The repository has been relocated within the Socket Mobile developer portal to enhance camera scanning capabilities with the SocketCam C860.

It employs a high-performance decoder capable of swiftly reading damaged barcodes in various lighting conditions.

The new SocketCam C860 is provided to developers at no cost and requires no additional coding efforts if the application includes a UI trigger button.

Activation of the C860 is left to the application's end user, who can enable its use by purchasing a subscription.

It's important to note that the free version of our camera-based scanner, the SocketCam C820, remains accessible.

Both the C860 and C820 utilize the same APIs as our physical scanner products, ensuring a seamless transition between a camera-based scanner and a physical barcode scanner.

More documentation can be found [here](https://docs.socketmobile.com/capture/ios/en/latest/ "CaptureSDK Documentation").

✳️: SocketCam C860 is available through our [Developer Portal](https://www.socketmobile.com/developers/portal). For more information and how to access, please visit our page [about this new product](https://www.socketmobile.com/readers-accessories/product-families/socketcam).

Beyond SocketCam C860, we have introduced a new feature. SocketCam C820 and SocketCam C860 are available for developers as view controllers that can be adapted to the size and position required in their workflow, and not only as full screen.

On 1st of July 2024, there won't be support for this repository and we will focus on CaptureSDK hosted through our developer portal.

## Devices compatibility and CaptureSDK versions

|       Devices                                          |          < 1.4         |          1.4           |          1.5          |          1.6          |         1.7          |         1.8          |
| :----------------------------------------------------: | :--------------------: | :--------------------: | :-------------------: | :-------------------: |:-------------------: |:-------------------: |
|   **SocketCam C820**                                   |          ❌            |           ✅           |           ✅           |           ✅          |           ✅          |           ✅         |
|   **S720/D720/S820**                                   |          ❌            |           ❌           |           ✅           |           ✅          |           ✅          |           ✅         |
|   **D600, S550, and all other barcode scanners**       |          ✅            |           ✅           |           ✅           |           ✅          |           ✅          |           ✅         |
|   **S370**                                             |          ❌            |           ❌           |           ❌           |           ✅          |           ✅          |           ✅         |
|   **M930**                                             |          ❌            |           ❌           |           ❌           |           ❌          |           ✅          |           ✅         |
|   **SocketCam C860**                                   |          ❌            |           ❌           |           ❌           |           ❌          |           ❌          |           ✳️         |

## SocketCam custom feature

With the new version of CaptureSDK available through our Developer Portal, you will be able to present SocketCam as you wish in a custom view, a popover and still in full screen. Now you decide where and when triggering and removing SocketCam view controller in your application's flow.
However, there's a minimal size of 250px x 250px to observe in order to display all SocketCam's UI elements.

BEFORE

![BEFORE](./docs/socketcam-fullscreen.jpeg)

AFTER

![AFTER](./docs/socketcam-custom.jpeg)

## Sample code

```swift
        let scanner = CaptureHelperDevice()

        scanner.setTrigger(.start, withCompletionHandler: { result, propertyObject in

            DispatchQueue.main.async {
                if let anObject = propertyObject?.object, let dic = anObject as? [String: Any], let objectType = dic["SKTObjectType"] as? String, objectType == "SKTSocketCamViewControllerType", let socketCamViewController = dic["SKTSocketCamViewController"] as? UIViewController {

                    ////
                    // Present the socketCamViewController in a popover or a subview or in full screen
                    ////
                }
            }
        
        })

        extension YourViewController: CaptureHelperDeviceDecodedDataDelegate {
    
            // This delegate is called each time a decoded data is read from a scanner or SocketCam
            func didReceiveDecodedData(_ decodedData: SKTCaptureDecodedData?, fromDevice device: CaptureHelperDevice, withResult result:SKTResult) {
                print("--->>> didReceiveDecodedData for device: \(device.deviceInfo.deviceType)")
                if result == .E_NOERROR {
                    let str = decodedData!.stringFromDecodedData()
                    print("Decoded Data \(String(describing: str))")
                    DispatchQueue.main.async {

                        ////
                        // When receiving your decoded data you can dismiss, hide, remove the SocketCam custom view controller
                        ////

                    }
                }
            }

        }
```
