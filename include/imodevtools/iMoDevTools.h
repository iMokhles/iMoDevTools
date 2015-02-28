//
// iMoDevTools.h
// iMoDevTools
//
// Created by Mokhlas Hussein (@iMokhles) on 8 Sept 2014
// Licensed under a GNU GPL v 2.0
// Copyright 2014-2015 Mokhlas Hussein (@iMokhles). All rights reserved.
//

#import <unistd.h>
#import <stdlib.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <MediaPlayer/MediaPlayer.h>
#import <CoreFoundation/CoreFoundation.h>
#import <AppSupport/CPDistributedMessagingCenter.h>
#import <AssetsLibrary/AssetsLibrary.h>

@protocol iMoDevToolsFilesBrowserDelegate <NSObject>
- (void)didSelectFile:(NSString *)path;
- (BOOL)shouldDeleteFileAtPath:(NSString *)path;
@optional
- (void)didLoadDirectory:(NSString *)path;
- (void)fileBrowserDidCancelled;
@end

@interface iMoDevTools: NSObject <UIPopoverPresentationControllerDelegate> {
	CPDistributedMessagingCenter *center;
	__unsafe_unretained id <iMoDevToolsFilesBrowserDelegate> _delegate;
}
@property (nonatomic, assign) id <iMoDevToolsFilesBrowserDelegate> delegate;
@property (nonatomic, strong) UIViewController *selfRootViewController;
// @property (nonatomic, strong) UIImage *lastTakenImage; // cannot get it to work well :(
@property (nonatomic, strong) NSString *lastImagePath; // retreive the path is the best way i got for now.
+ (id)sharedInstance;

- (NSString *)temporaryFile;
- (void)moveFile:(NSString *)file1 toFile:(NSString *)file2;
- (void)copyFile:(NSString *)file1 toFile:(NSString *)file2;
- (void)symlinkFile:(NSString *)file1 toFile:(NSString *)file2;
- (void)deleteFile:(NSString *)file;
- (NSDictionary *)attributesOfFile:(NSString *)file;
- (NSArray *)contentsOfDirectory:(NSString *)dir;
- (void)chmodFile:(NSString *)file mode:(mode_t)mode;
- (BOOL)fileExists:(NSString *)file;
- (BOOL)fileIsDirectory:(NSString *)file;
- (void)createDirectory:(NSString *)dir;
- (NSString *)deviceUDIDValue;
- (NSString *)deviceSysName;
- (NSString *)deviceSysVersion;
- (NSString *)deviceHardware;
- (void)shareFileAtPath:(NSString *)path;
- (void)shareText:(NSString *)text;
- (void)openImoFileBrowser;
- (void)exportMp3FileFromMPMediaItems:(MPMediaItemCollection *)mediaItemCollection toFolder:(NSString *)folderName;
- (void)getLastImage;
@end
