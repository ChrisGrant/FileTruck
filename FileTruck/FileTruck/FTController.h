//
//  FTController.h
//  FileTruck
//
//  Created by Chris Grant on 12/03/2014.
//  Copyright (c) 2014 ScottLogic. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Private APIs we need to use to access the project file

@interface DVTFilePath : NSObject
@property (readonly) NSURL *fileURL;
@end

@interface IDEContainerItem : NSObject
@property (readonly) DVTFilePath *resolvedFilePath;
@end

@interface IDEFileReference : IDEContainerItem
@end

@interface IDENavigableItem : NSObject
@property (readonly) IDENavigableItem *parentItem;
@property (readonly) id representedObject;
@end

@interface IDEFileNavigableItem : IDENavigableItem
@property (readonly) NSURL *fileURL;
@end

@interface IDEStructureNavigator : NSObject
@property (retain) NSArray *objects;
@end

@interface IDENavigatorArea : NSObject
- (id)currentNavigator;
- (void)showNavigatorWithIdentifier:(id)identifier;
- (id)_currentExtensionIdentifier;
@end

@interface IDEWorkspaceTabController : NSObject
@property (readonly) IDENavigatorArea *navigatorArea;
@end

@interface IDEWorkspaceWindowController : NSObject
@property (readonly) IDEWorkspaceTabController *activeWorkspaceTabController;
@end

typedef void (^ProjectFileSubscriber)(NSArray *projects);

@interface FTController : NSObject

@property (nonatomic) BOOL monitorForChanges;

- (id)initWithBundle:(NSBundle *)plugin;

- (void)runScriptOnItem:(IDEFileNavigableItem *)item;

- (BOOL)isProjectMonitored:(IDEFileNavigableItem *)project;
- (void)monitorProject:(IDEFileNavigableItem *)project;
- (void)unmonitorProject:(IDEFileNavigableItem *)project;

- (void)addProjectFilesSubscriberBlock:(ProjectFileSubscriber)block;

@end
