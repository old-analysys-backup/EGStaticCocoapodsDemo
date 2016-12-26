#
#  Be sure to run `pod spec lint EGStaticCocoapodsDemo.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "EGStaticCocoapodsDemo"
  s.version      = "1.0"
  s.summary      = "易观方舟SDK，具体使用方法请参考官方文档：http://dev.analysys.cn/static/html/frontView/doc/sdk.html#ios-h"
  s.homepage     = "https://github.com/analysys/EGStaticCocoapodsDemo"
  s.license      = "MIT"
  s.author       = { "analysys" => "zhiku@analysys.com.cn" }
  s.platform     = :ios, "5.0"
  s.source       = { :git => "https://github.com/analysys/EGStaticCocoapodsDemo.git", :tag => s.version }
  s.source_files = "Classes/*.{h,m}"
  s.ios.vendored_libraries = "Classes/*.a"
	s.requires_arc = true
end
