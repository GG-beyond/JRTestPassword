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

  s.source       = { :git => "https://github.com/GG-beyond/JRTestPassword.git", :tag => "0.0.2" }


  s.source_files  = "JRTestPassword/WBLoginSDK/*.{h,m,entitlements}"
  s.subspec 'WBLoginSDK' do |ss|

	ss.subspec 'Dependence' do |sss|

		sss.subspec 'ZMSDK' do |ssss|
			ssss.source_files= "JRTestPassword/WBLoginSDK/Dependence/ZMSDK/*"
		end		
	end
  end



end
