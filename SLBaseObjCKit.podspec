#
# Be sure to run `pod lib lint SLBaseObjCKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
    s.name             = 'SLBaseObjCKit'
    s.version          = '0.2.0'
    s.summary          = '项目的基本的配置'
    
    # This description is used to generate tags and improve search results.
    #   * Think: What does it do? Why did you write it? What is the focus?
    #   * Try to keep it short, snappy and to the point.
    #   * Write the description between the DESC delimiters below.
    #   * Finally, don't worry about the indent, CocoaPods strips it!
    
    s.description      = <<-DESC
    提供了项目部署所需的基本配置
    DESC
    
    s.homepage         = 'https://github.com/CoderSLZeng/SLBaseObjCKit'
    # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'CoderSLZeng' => '359297567@qq.com' }
    s.source           = { :git => 'https://github.com/CoderSLZeng/SLBaseObjCKit.git', :tag => s.version.to_s }
    # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
    
    s.ios.deployment_target = '8.0'
    
    # 导入二进制文件和非二进制文件判断
    if ENV['IS_BINARY']
        
        s.source_files = 'SLBaseObjCKit/Classes/**/*.h'
        s.public_header_files = 'SLBaseObjCKit/Classes/**/*.h'
        
        if ENV['IS_LIB'] # Use demo: IS_BINARY=1 IS_LIB=1 pod install
            
            # 打包 【.a】 文件命令行
            # pod package SLBaseObjCKit.podspec --library --exclude-deps --spec-sources='https://github.com/CoderSLZeng/SLBaseObjCKit.git,https://github.com/CocoaPods/Specs.git'
            
            s.ios.vendored_libraries = 'SLBaseObjCKit/Products/libSLBaseObjCKit.a'
            
            else # Use demo: IS_BINARY=1 pod install
            
            # 打包 【.framework】 文件命令行
            # pod package SLBaseObjCKit.podspec  --exclude-deps --spec-sources='https://github.com/CoderSLZeng/SLBaseObjCKit.git,https://github.com/CocoaPods/Specs.git'
            
            s.ios.vendored_frameworks = 'SLBaseObjCKit/Products/SLBaseObjCKit.framework'
            
        end
        
        else # Use demo: pod install
        # 导入资源文件
        # s.source_files = 'SLBaseObjCKit/Classes/**/*{.h,.m}'
        
        # 导入图片资源文件
        # s.resource_bundles = {
        #   'SLBaseObjCKit' => ['SLBaseObjCKit/Assets/*.png']
        # }
        
        # Subspec 子文件
        s.subspec 'Header' do |header|
            header.source_files = 'SLBaseObjCKit/Classes/Header/*.{h,m}'
        end
        
        s.subspec 'Const' do |const|
            const.source_files = 'SLBaseObjCKit/Classes/Const/*.{h,m}'
        end
        
        s.subspec 'Config' do |config|
            config.source_files = 'SLBaseObjCKit/Classes/Config/*.{h,m}'
            config.dependency 'MJExtension'
        end
        
    end
    
    # s.public_header_files = 'Pod/Classes/**/*.h'
    # s.frameworks = 'UIKit', 'MapKit'
    # s.dependency 'AFNetworking', '~> 2.3'
end
