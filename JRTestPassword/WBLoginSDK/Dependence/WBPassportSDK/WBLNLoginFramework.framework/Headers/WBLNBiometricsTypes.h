typedef NS_ENUM(NSUInteger, WBLNBiometricsEvaluateType) {
    WBLNBiometricsEvaluateTypeSuccess,
    WBLNBiometricsEvaluateTypeFailure,
    WBLNBiometricsEvaluateTypeNotEnrolled,
    WBLNBiometricsEvaluateTypeUserCancel,
    WBLNBiometricsEvaluateTypeUnKnownError,
    WBLNBiometricsEvaluateTypeLockout,
    WBLNBiometricsEvaluateTypeNotAvailable,
    WBLNBiometricsEvaluateTypeFaceIDNotAllow,
};
typedef NS_ENUM(NSUInteger, WBLNBiometryType) {
    WBLNBiometryTypeNone, 
    WBLNBiometryTypeTouchID,
    WBLNBiometryTypeFaceID, 
};
