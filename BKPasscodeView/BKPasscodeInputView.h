//
//  BKPasscodeInputView.h
//  BKPasscodeViewDemo
//
//  Created by Byungkook Jang on 2014. 4. 20..
//  Copyright (c) 2014년 Byungkook Jang. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "BKPasscodeField.h"

typedef enum : NSUInteger {
    BKPasscodeInputViewNumericPasscodeStyle,
    BKPasscodeInputViewNormalPasscodeStyle,
} BKPasscodeInputViewPasscodeStyle;


@protocol BKPasscodeInputViewDelegate;


@interface BKPasscodeInputView : UIView <UITextFieldDelegate, BKPasscodeFieldDelegate, NSCopying>

@property (nonatomic, weak) id<BKPasscodeInputViewDelegate> delegate;

@property (nonatomic) BKPasscodeInputViewPasscodeStyle  passcodeStyle;
@property (nonatomic) UIKeyboardType                    keyboardType;
@property (nonatomic) NSUInteger                        maximumLength;

@property (nonatomic, strong) NSString                  *title;
@property (nonatomic, strong) NSString                  *message;
@property (nonatomic, strong) NSString                  *errorMessage;
@property (nonatomic, getter = isEnabled) BOOL          enabled;
@property (nonatomic, strong) NSString                  *passcode;

@property (nonatomic, strong, readonly) UIControl       *passcodeField;

@property (nonatomic, strong) UIFont                    *titleFont;
@property (nonatomic, strong) UIColor                   *titleColor;
@property (nonatomic, strong) UIFont                    *messageFont;
@property (nonatomic, strong) UIColor                   *messageColor;
@property (nonatomic, strong) UIFont                    *errorMessageFont;
@property (nonatomic, strong) UIColor                   *errorMessageColor;

// You can override these methods to customize message label appearance.
+ (void)configureTitleLabel:(UILabel *)aLabel;
+ (void)configureMessageLabel:(UILabel *)aLabel;
+ (void)configureErrorMessageLabel:(UILabel *)aLabel;


// Customize vertical placement of elements by changing this value
// Default value is 0.5f, thus the passscodeFields is centered in height
-(CGFloat)passcodeFieldVerticalPlacement;

@end


@protocol BKPasscodeInputViewDelegate <NSObject>

/**
 * Tells the delegate that maximum length of passcode is entered or user tapped Done button in the keyboard (in case of BKPasscodeInputViewNormalPasscodeStyle).
 */
- (void)passcodeInputViewDidFinish:(BKPasscodeInputView *)aInputView;

@end
