/*****************************************************************************
 **
 ** CocoaMSX: MSX Emulator for Mac OS X
 ** http://www.cocoamsx.com
 ** Copyright (C) 2012-2013 Akop Karapetyan
 **
 ** This program is free software; you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 2 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program; if not, write to the Free Software
 ** Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 **
 ******************************************************************************
 */
#import <Cocoa/Cocoa.h>

#import "MGScopeBarDelegateProtocol.h"

@class CMEmulatorController;
@class CMJoyPortDevice;
@class CMMsxKeyLayout;
@class MGScopeBar;
@class CMKeyCaptureView;

@interface CMPreferenceController : NSWindowController<NSWindowDelegate, NSToolbarDelegate, NSTableViewDataSource, NSTableViewDelegate, NSOutlineViewDataSource, NSOutlineViewDelegate, MGScopeBarDelegate>
{
    CMEmulatorController *_emulator;
    BOOL _isSaturationEnabled;
    NSInteger _colorMode;
    NSMutableArray *_joystickPortPeripherals;
    CMJoyPortDevice *_joystickPort1Selection;
    CMJoyPortDevice *_joystickPort2Selection;
    
    NSInteger machineDisplayMode;
    
    IBOutlet NSButton *addMachineButton;
    IBOutlet NSButton *removeMachineButton;
    
    IBOutlet NSPopUpButton *joystickOneDevice;
    IBOutlet NSPopUpButton *joystickTwoDevice;
    
    IBOutlet NSToolbar *toolbar;
    
    IBOutlet NSTabView *preferenceCategoryTabView;
    IBOutlet NSTabView *joystickOneDeviceTabView;
    IBOutlet NSTabView *joystickTwoDeviceTabView;
    
    IBOutlet MGScopeBar *keyboardScopeBar;
    IBOutlet MGScopeBar *machineScopeBar;
    
    CMKeyCaptureView *keyCaptureView;
    
    IBOutlet NSTableView *systemTableView;
    IBOutlet NSTextField *activeSystemTextView;
    
    IBOutlet NSOutlineView *keyboardLayoutEditor;
    IBOutlet NSOutlineView *joystickOneLayoutEditor;
    IBOutlet NSOutlineView *joystickTwoLayoutEditor;
    
    IBOutlet NSSlider *brightnessSlider;
    IBOutlet NSSlider *contrastSlider;
    IBOutlet NSSlider *saturationSlider;
    IBOutlet NSSlider *gammaSlider;
    IBOutlet NSSlider *scanlineSlider;
    
    IBOutlet NSSlider *emulationSpeedSlider;
    
    NSMutableArray *keyCategories;
    NSMutableArray *joystickOneCategories;
    NSMutableArray *joystickTwoCategories;
    NSMutableArray *installedMachines;
    NSMutableArray *availableMachines;
    NSMutableArray *allMachines;
    
    NSArray *virtualEmulationSpeedRange;
    
    NSInteger selectedKeyboardRegion;
    NSInteger selectedKeyboardShiftState;
}

@property (nonatomic, retain) CMEmulatorController *emulator;

@property (nonatomic, assign) BOOL isSaturationEnabled;
@property (nonatomic, assign) NSInteger colorMode;

@property (nonatomic, retain) NSMutableArray *joystickPortPeripherals;
@property (nonatomic, retain) CMJoyPortDevice *joystickPort1Selection;
@property (nonatomic, retain) CMJoyPortDevice *joystickPort2Selection;

- (id)initWithEmulator:(CMEmulatorController *)emulator;

- (IBAction)tabChanged:(id)sender;
- (IBAction)joystickDeviceChanged:(id)sender;
- (IBAction)revertVideoClicked:(id)sender;
- (IBAction)revertKeyboardClicked:(id)sender;
- (IBAction)revertJoystickOneClicked:(id)sender;
- (IBAction)revertJoystickTwoClicked:(id)sender;

- (IBAction)showMachinesInFinder:(id)sender;
- (IBAction)removeMachineConfiguration:(id)sender;

- (IBAction)performColdRebootClicked:(id)sender;

- (IBAction)emulationSpeedSliderMoved:(id)sender;

@end
