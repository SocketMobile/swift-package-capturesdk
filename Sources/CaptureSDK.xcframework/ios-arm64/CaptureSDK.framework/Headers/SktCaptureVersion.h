/**
  @file SktCaptureVersion.h

  @brief define a Capture property version argument

  @copyright © 2017 Socket Mobile, Inc.

*/

#ifndef SktCaptureVersion_h
#define SktCaptureVersion_h

/**
 @class SKTCaptureVersion
 @brief define a version
 */
@interface SKTCaptureVersion : NSObject
/** major version number (the first number) */
@property unsigned long Major;

/** middle verion number (the second number) */
@property unsigned long Middle;

/** minor version number (the third number) */
@property unsigned long Minor;

/** build number (the fourth number) */
@property unsigned long Build;

/** month the build has been done */
@property int Month;

/** day the build has been done */
@property int Day;

/** year the build has been done */
@property int Year;

/** hour the build has been done */
@property int Hour;

/** minute the build has been done */
@property int Minute;
@end

#endif /* SktCaptureVersion_h */
