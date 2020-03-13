#
# Be sure to run `pod lib lint LKMapSDK_Base.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LKMapSDK_Base'
  s.version          = '1.0.0'
  s.summary          = '箩筐地图iOS SDK（CocoaPods箩筐地图官方库），基础功能包'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
箩筐地图iOS SDK（CocoaPods箩筐地图官方库），基础功能包。提供基础功能。
                       DESC

  s.homepage         = 'https://lbs.luokuang.com'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'LuokuangLBS' => 'haofp@luokung.com' }
  s.source           = { :git => 'https://github.com/LuokuangLBS/LKMapSDK_Base.git', :tag => s.version.to_s }
  s.ios.deployment_target = '9.0'
  s.requires_arc = true
  s.frameworks = 'UIKit', 'CoreLocation'
  s.vendored_frameworks = 'LKMapSDK_Base/*.{framework}'
  s.libraries = 'c++'
end
