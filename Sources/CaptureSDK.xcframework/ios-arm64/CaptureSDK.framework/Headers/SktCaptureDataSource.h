/**
  @file SktCaptureDataSource.h
  @brief Define the Data Source object in Capture

  @copyright © 2017 Socket Mobile, Inc.

 */

#ifndef SktCaptureDataSource_h
#define SktCaptureDataSource_h

/**

 @brief idenfity a barcode symbology or a RFID/NFC Tag

 */
typedef NS_ENUM(NSInteger, SKTCaptureDataSourceID) {
	/**
	the data source ID is not specified or initialized
	*/
	SKTCaptureDataSourceIDNotSpecified = 0,

	/**
	the barcode symbology for Australia post
	*/
	SKTCaptureDataSourceIDSymbologyAustraliaPost = 1,

	/**
	the barcode symbology Aztec
	*/
	SKTCaptureDataSourceIDSymbologyAztec = 2,

	/**
	the barcode symbology Bookland EAN
	*/
	SKTCaptureDataSourceIDSymbologyBooklandEan = 3,

	/**
	the barcode symbology for British post
	*/
	SKTCaptureDataSourceIDSymbologyBritishPost = 4,

	/**
	the barcode symbology for Canada post
	*/
	SKTCaptureDataSourceIDSymbologyCanadaPost = 5,

	/**
	the barcode symbology Chinese 2 of 5
	*/
	SKTCaptureDataSourceIDSymbologyChinese2of5 = 6,

	/**
	the barcode symbology Codabar
	*/
	SKTCaptureDataSourceIDSymbologyCodabar = 7,

	/**
	the barcode symbology Codablock A
	*/
	SKTCaptureDataSourceIDSymbologyCodablockA = 8,

	/**
	the barcode symbology Codablock F
	*/
	SKTCaptureDataSourceIDSymbologyCodablockF = 9,

	/**
	the barcode symbology Code 11
	*/
	SKTCaptureDataSourceIDSymbologyCode11 = 10,

	/**
	the barcode symbology Code 39
	*/
	SKTCaptureDataSourceIDSymbologyCode39 = 11,

	/**
	the barcode symbology Code 39 Extended
	*/
	SKTCaptureDataSourceIDSymbologyCode39Extended = 12,

	/**
	the barcode symbology Code 39 Trioptic
	*/
	SKTCaptureDataSourceIDSymbologyCode39Trioptic = 13,

	/**
	the barcode symbology Code 93
	*/
	SKTCaptureDataSourceIDSymbologyCode93 = 14,

	/**
	the barcode symbology Code 128
	*/
	SKTCaptureDataSourceIDSymbologyCode128 = 15,

	/**
	the barcode symbology DataMatrix
	*/
	SKTCaptureDataSourceIDSymbologyDataMatrix = 16,

	/**
	the barcode symbology for Dutch post
	*/
	SKTCaptureDataSourceIDSymbologyDutchPost = 17,

	/**
	the barcode symbology EAN 8
	*/
	SKTCaptureDataSourceIDSymbologyEan8 = 18,

	/**
	the barcode symbology EAN 13
	*/
	SKTCaptureDataSourceIDSymbologyEan13 = 19,

	/**
	the barcode symbology EAN 128
	*/
	SKTCaptureDataSourceIDSymbologyEan128 = 20,

	/**
	the barcode symbology EAN 128 Irregular
	*/
	SKTCaptureDataSourceIDSymbologyEan128Irregular = 21,

	/**
	the barcode symbology EAN UCC Composite AB
	*/
	SKTCaptureDataSourceIDSymbologyEanUccCompositeAB = 22,

	/**
	the barcode symbology EAN UCC Composite C
	*/
	SKTCaptureDataSourceIDSymbologyEanUccCompositeC = 23,

	/**
	the barcode symbology GS1 Databar
	*/
	SKTCaptureDataSourceIDSymbologyGs1Databar = 24,

	/**
	the barcode symbology GS1 Databar Limited
	*/
	SKTCaptureDataSourceIDSymbologyGs1DatabarLimited = 25,

	/**
	the barcode symbology GS1 Databar Expanded
	*/
	SKTCaptureDataSourceIDSymbologyGs1DatabarExpanded = 26,

	/**
	the barcode symbology Interleaved 2 of 5
	*/
	SKTCaptureDataSourceIDSymbologyInterleaved2of5 = 27,

	/**
	the barcode symbology ISBT 128
	*/
	SKTCaptureDataSourceIDSymbologyIsbt128 = 28,

	/**
	the barcode symbology for Japan post
	*/
	SKTCaptureDataSourceIDSymbologyJapanPost = 29,

	/**
	the barcode symbology Matrix 2 of 5
	*/
	SKTCaptureDataSourceIDSymbologyMatrix2of5 = 30,

	/**
	the barcode symbology Maxi Code
	*/
	SKTCaptureDataSourceIDSymbologyMaxicode = 31,

	/**
	the barcode symbology MSI
	*/
	SKTCaptureDataSourceIDSymbologyMsi = 32,

	/**
	the barcode symbology PDF 417
	*/
	SKTCaptureDataSourceIDSymbologyPdf417 = 33,

	/**
	the barcode symbology PDF 417 Micro
	*/
	SKTCaptureDataSourceIDSymbologyPdf417Micro = 34,

	/**
	the barcode symbology Planet
	*/
	SKTCaptureDataSourceIDSymbologyPlanet = 35,

	/**
	the barcode symbology Plessey
	*/
	SKTCaptureDataSourceIDSymbologyPlessey = 36,

	/**
	the barcode symbology Postnet
	*/
	SKTCaptureDataSourceIDSymbologyPostnet = 37,

	/**
	the barcode symbology QR Code
	*/
	SKTCaptureDataSourceIDSymbologyQRCode = 38,

	/**
	the barcode symbology Standard 2 of 5
	*/
	SKTCaptureDataSourceIDSymbologyStandard2of5 = 39,

	/**
	the barcode symbology Telepen
	*/
	SKTCaptureDataSourceIDSymbologyTelepen = 40,

	/**
	the barcode symbology TLC 39
	*/
	SKTCaptureDataSourceIDSymbologyTlc39 = 41,

	/**
	the barcode symbology UPC A
	*/
	SKTCaptureDataSourceIDSymbologyUpcA = 42,

	/**
	the barcode symbology UPC E0
	*/
	SKTCaptureDataSourceIDSymbologyUpcE0 = 43,

	/**
	the barcode symbology UPC E1
	*/
	SKTCaptureDataSourceIDSymbologyUpcE1 = 44,

	/**
	the barcode symbology USPS Intelligent Mail
	*/
	SKTCaptureDataSourceIDSymbologyUspsIntelligentMail = 45,

	/**
	the barcode symbology Direct Part Marking
	*/
	SKTCaptureDataSourceIDSymbologyDirectPartMarking = 46,

	/**
	the barcode symbology Han Xin
	*/
	SKTCaptureDataSourceIDSymbologyHanXin = 47,

	/**
	the barcode symbology DotCode
	*/
	SKTCaptureDataSourceIDSymbologyDotCode = 48,

	/**
	the barcode symbology Digimarc
	*/
	SKTCaptureDataSourceIDSymbologyDigimarc = 49,

	/**
	the barcode symbology Korea Post
	*/
	SKTCaptureDataSourceIDSymbologyKoreaPost = 50,

	/**
	the last barcode symbology ID, not an actual barcode symbology
	*/
	SKTCaptureDataSourceIDLastSymbologyID = 51,

	/**
	the RFID Tag Type ISO 14443 A
	*/
	SKTCaptureDataSourceIDTagTypeISO14443TypeA = 256,

	/**
	the RFID Tag Type ISO 14443 B
	*/
	SKTCaptureDataSourceIDTagTypeISO14443TypeB = 257,

	/**
	the RFID Tag Type Felica
	*/
	SKTCaptureDataSourceIDTagTypeFelica = 258,

	/**
	the RFID Tag Type ISO 15693
	*/
	SKTCaptureDataSourceIDTagTypeISO15693 = 259,

	/**
	the RFID Tag Type NXPI Code 1
	*/
	SKTCaptureDataSourceIDTagTypeNXPICODE1 = 260,

	/**
	the RFID Tag Type Inside Secure Pico Tag
	*/
	SKTCaptureDataSourceIDTagTypeInsideSecurePicoTag = 261,

	/**
	the RFID Tag Type Innovision Topaz Jewel
	*/
	SKTCaptureDataSourceIDTagTypeInnovisionTopazJewel = 262,

	/**
	the RFID Tag Type Thin Film NFC Barcode
	*/
	SKTCaptureDataSourceIDTagTypeThinfilmNFCBarcode = 263,

	/**
	the RFID Tag Type ST Micro Electronics SR
	*/
	SKTCaptureDataSourceIDTagTypeSTMicroElectronicsSR = 264,

	/**
	the RFID Tag Type ASK CTS 256B or CTS 512B
	*/
	SKTCaptureDataSourceIDTagTypeASKCTS256BOrCTS512B = 265,

	/**
	the RFID Tag Type NFC Forum
	*/
	SKTCaptureDataSourceIDTagTypeNFCForum = 266,

	/**
	the RFID Tag Type Innovatron Radio Protocol
	*/
	SKTCaptureDataSourceIDTagTypeInnovatronRadioProtocol = 267,

	/**
	the last RFID tag type, not an actual tag type
	*/
	SKTCaptureDataSourceIDTagTypeLastTagType = 268,

};


/**

 @brief define the data source status

 */
typedef NS_ENUM(NSInteger, SKTCaptureDataSourceStatus) {
	/**
	the data source status is disabled
	*/
	SKTCaptureDataSourceStatusDisable = 0,

	/**
	the data source status is enabled
	*/
	SKTCaptureDataSourceStatusEnable = 1,

	/**
	the data source is not supported
	*/
	SKTCaptureDataSourceStatusNotSupported = 2,

};


/**

 @brief define the flag value of a data source structure

 */
typedef NS_OPTIONS(NSInteger, SKTCaptureDataSourceFlags) {
	/**
	the data source contains a status
	*/
	SKTCaptureDataSourceFlagsStatus = 1,

	/**
	the data source contains some parameters
	*/
	SKTCaptureDataSourceFlagsParam = 2,

};


/**
 @class SKTCaptureDataSource

 @brief define a data source which has an ID, a name and a status. The flag is set to
 status because for now that is the only parameter the data source can have
 */
@interface SKTCaptureDataSource : NSObject

/**
 Get or Set the Data Source ID
 */
@property SKTCaptureDataSourceID ID;

/**
 contain the data source name
 */
@property (nullable, nonatomic, strong) NSString* Name;

/**
 contain the data source status (enabled or disable or not supported)
 */
@property SKTCaptureDataSourceStatus Status;

/**
 contain the flag that defines the data source argument, today always set to status
 */
@property SKTCaptureDataSourceFlags Flags;
@end
#endif /* SktCaptureDataSource_h */

