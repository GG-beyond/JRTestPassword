#
#  Be sure to run `pod spec lint JRTestPassword.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  

  s.name         = "JRTestPassword"
  s.version      = "0.0.1"
  s.summary      = "A of JRTestPassword."

  
  s.description  = <<-DESC
		skjdhfajskofh a
                   DESC

  s.homepage     = "https://github.com/GG-beyond/JRTestPassword"


  s.license      = "MIT"

  s.author             = { "xiezhenfeng" => "xiezhenfeng@58ganji.com" }
  

   s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/GG-beyond/JRTestPassword.git", :tag => "0.0.5" }

  s.source_files  = "JRTestPassword/WBLoginSDK/*.{h,m,entitlements}"

  s.ios.vendored_frameworks = 'JRTestPassword/WBLoginSDK/Dependence/**/*.framework' 
  s.resources = "JRTestPassword/WBLoginSDK/Dependence/**/*.bundle"

  s.frameworks = "UIKit", "Foundation","Photos","StoreKit","SystemConfiguration","MobileCoreServices","WebKit","CoreMotion","CoreMedia","AudioToolbox","CoreTelephony","AVFoundation","GLKit","Accelerate","ImageIO","AdSupport"


  s.libraries = "z.1.2.8", "z", "c++","icucore","sqlite3","sqlite3.0"
  s.subspec 'WBLoginSDK' do |ss|

	
	ss.subspec 'Dependence' do |sss|

		sss.subspec 'WeiboSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/WeiboSDK/*"
		end
		sss.subspec 'AliPay' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/AliPay/*"
		end
		sss.subspec 'GateWaySDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/GateWaySDK/*"
		end
		sss.subspec 'ISDSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/ISDSDK/*"
		end
		sss.subspec 'Pay58' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/Pay58/*"
		end
		sss.subspec 'QQSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/QQSDK/*"
		end
		sss.subspec 'SSL' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/SSL/*"
		end
		sss.subspec 'TencentSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/TencentSDK/*"

		end
		sss.subspec 'WBPassportSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/WBPassportSDK/*"
		end
		sss.subspec 'WeChatSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/WeChatSDK/*"
		end
		sss.subspec 'ZMSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/ZMSDK/*"
		end

			
	end

  end



end
