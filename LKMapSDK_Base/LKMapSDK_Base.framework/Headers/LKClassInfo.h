
#import <Foundation/Foundation.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type encoding's type.
 */
typedef NS_OPTIONS(NSUInteger, LKEncodingType) {
    LKEncodingTypeMask       = 0xFF, ///< mask of type value
    LKEncodingTypeUnknown    = 0, ///< unknown
    LKEncodingTypeVoid       = 1, ///< void
    LKEncodingTypeBool       = 2, ///< bool
    LKEncodingTypeInt8       = 3, ///< char / BOOL
    LKEncodingTypeUInt8      = 4, ///< unsigned char
    LKEncodingTypeInt16      = 5, ///< short
    LKEncodingTypeUInt16     = 6, ///< unsigned short
    LKEncodingTypeInt32      = 7, ///< int
    LKEncodingTypeUInt32     = 8, ///< unsigned int
    LKEncodingTypeInt64      = 9, ///< long long
    LKEncodingTypeUInt64     = 10, ///< unsigned long long
    LKEncodingTypeFloat      = 11, ///< float
    LKEncodingTypeDouble     = 12, ///< double
    LKEncodingTypeLongDouble = 13, ///< long double
    LKEncodingTypeObject     = 14, ///< id
    LKEncodingTypeClass      = 15, ///< Class
    LKEncodingTypeSEL        = 16, ///< SEL
    LKEncodingTypeBlock      = 17, ///< block
    LKEncodingTypePointer    = 18, ///< void*
    LKEncodingTypeStruct     = 19, ///< struct
    LKEncodingTypeUnion      = 20, ///< union
    LKEncodingTypeCString    = 21, ///< char*
    LKEncodingTypeCArray     = 22, ///< char[10] (for example)
    
    LKEncodingTypeQualifierMask   = 0xFF00,   ///< mask of qualifier
    LKEncodingTypeQualifierConst  = 1 << 8,  ///< const
    LKEncodingTypeQualifierIn     = 1 << 9,  ///< in
    LKEncodingTypeQualifierInout  = 1 << 10, ///< inout
    LKEncodingTypeQualifierOut    = 1 << 11, ///< out
    LKEncodingTypeQualifierBycopy = 1 << 12, ///< bycopy
    LKEncodingTypeQualifierByref  = 1 << 13, ///< byref
    LKEncodingTypeQualifierOneway = 1 << 14, ///< oneway
    
    LKEncodingTypePropertyMask         = 0xFF0000, ///< mask of property
    LKEncodingTypePropertyReadonly     = 1 << 16, ///< readonly
    LKEncodingTypePropertyCopy         = 1 << 17, ///< copy
    LKEncodingTypePropertyRetain       = 1 << 18, ///< retain
    LKEncodingTypePropertyNonatomic    = 1 << 19, ///< nonatomic
    LKEncodingTypePropertyWeak         = 1 << 20, ///< weak
    LKEncodingTypePropertyCustomGetter = 1 << 21, ///< getter=
    LKEncodingTypePropertyCustomSetter = 1 << 22, ///< setter=
    LKEncodingTypePropertyDynamic      = 1 << 23, ///< @dynamic
};

/**
 Get the type from a Type-Encoding string.
 
 @discussion See also:
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtTypeEncodings.html
 https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ObjCRuntimeGuide/Articles/ocrtPropertyIntrospection.html
 
 @param typeEncoding  A Type-Encoding string.
 @return The encoding type.
 */
LKEncodingType LKEncodingGetType(const char *typeEncoding);


/**
 Instance variable information.
 */
@interface LKClassIvarInfo : NSObject
@property (nonatomic, assign, readonly) Ivar ivar;              ///< ivar opaque struct
@property (nonatomic, strong, readonly) NSString *name;         ///< Ivar's name
@property (nonatomic, assign, readonly) ptrdiff_t offset;       ///< Ivar's offset
@property (nonatomic, strong, readonly) NSString *typeEncoding; ///< Ivar's type encoding
@property (nonatomic, assign, readonly) LKEncodingType type;    ///< Ivar's type

/**
 Creates and returns an ivar info object.
 
 @param ivar ivar opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithIvar:(Ivar)ivar;
@end


/**
 Method information.
 */
@interface LKClassMethodInfo : NSObject
@property (nonatomic, assign, readonly) Method method;                  ///< method opaque struct
@property (nonatomic, strong, readonly) NSString *name;                 ///< method name
@property (nonatomic, assign, readonly) SEL sel;                        ///< method's selector
@property (nonatomic, assign, readonly) IMP imp;                        ///< method's implementation
@property (nonatomic, strong, readonly) NSString *typeEncoding;         ///< method's parameter and return types
@property (nonatomic, strong, readonly) NSString *returnTypeEncoding;   ///< return value's type
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *argumentTypeEncodings; ///< array of arguments' type

/**
 Creates and returns a method info object.
 
 @param method method opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithMethod:(Method)method;
@end


/**
 Property information.
 */
@interface LKClassPropertyInfo : NSObject
@property (nonatomic, assign, readonly) objc_property_t property; ///< property's opaque struct
@property (nonatomic, strong, readonly) NSString *name;           ///< property's name
@property (nonatomic, assign, readonly) LKEncodingType type;      ///< property's type
@property (nonatomic, strong, readonly) NSString *typeEncoding;   ///< property's encoding value
@property (nonatomic, strong, readonly) NSString *ivarName;       ///< property's ivar name
@property (nullable, nonatomic, assign, readonly) Class cls;      ///< may be nil
@property (nullable, nonatomic, strong, readonly) NSArray<NSString *> *protocols; ///< may nil
@property (nonatomic, assign, readonly) SEL getter;               ///< getter (nonnull)
@property (nonatomic, assign, readonly) SEL setter;               ///< setter (nonnull)

/**
 Creates and returns a property info object.
 
 @param property property opaque struct
 @return A new object, or nil if an error occurs.
 */
- (instancetype)initWithProperty:(objc_property_t)property;
@end


/**
 Class information for a class.
 */
@interface LKClassInfo : NSObject
@property (nonatomic, assign, readonly) Class cls; ///< class object
@property (nullable, nonatomic, assign, readonly) Class superCls; ///< super class object
@property (nullable, nonatomic, assign, readonly) Class metaCls;  ///< class's meta class object
@property (nonatomic, readonly) BOOL isMeta; ///< whether this class is meta class
@property (nonatomic, strong, readonly) NSString *name; ///< class name
@property (nullable, nonatomic, strong, readonly) LKClassInfo *superClassInfo; ///< super class's class info
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, LKClassIvarInfo *> *ivarInfos; ///< ivars
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, LKClassMethodInfo *> *methodInfos; ///< methods
@property (nullable, nonatomic, strong, readonly) NSDictionary<NSString *, LKClassPropertyInfo *> *propertyInfos; ///< properties

/**
 If the class is changed (for example: you add a method to this class with
 'class_addMethod()'), you should call this method to refresh the class info cache.
 
 After called this method, `needUpdate` will returns `YES`, and you should call 
 'classInfoWithClass' or 'classInfoWithClassName' to get the updated class info.
 */
- (void)setNeedUpdate;

/**
 If this method returns `YES`, you should stop using this instance and call
 `classInfoWithClass` or `classInfoWithClassName` to get the updated class info.
 
 @return Whether this class info need update.
 */
- (BOOL)needUpdate;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param cls A class.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClass:(Class)cls;

/**
 Get the class info of a specified Class.
 
 @discussion This method will cache the class info and super-class info
 at the first access to the Class. This method is thread-safe.
 
 @param className A class name.
 @return A class info, or nil if an error occurs.
 */
+ (nullable instancetype)classInfoWithClassName:(NSString *)className;

@end

NS_ASSUME_NONNULL_END
