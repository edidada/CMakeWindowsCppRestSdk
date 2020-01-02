# CMakeProject1

无法导入vcpkg中的lib

gtest导入失败

`vcpkg integrate install`

`vcpkg integrate remove`

`vcpkg integrate project`

4.5. 集成到CMake
最新的Visual Studio 2015和2017大力支持CMake工程，所以对cmake的支持当然不能少。在cmake中集成只要在cmake文件中加入下面这句话即可。

-DCMAKE_TOOLCHAIN_FILE="D:\vcpkg\scripts\buildsystems\vcpkg.cmake"

其中是指vcpkg实际所在目录。

4.6. 集成静态库
Vcpkg默认编译链接的是动态库，如果要链接静态库，目前还没有简便的方法。需要做如下操作

用文本方式打开vcxproj工程文件
在xml的段里面增加如下两句话即可
<VcpkgTriplet>x86-windows-static</VcpkgTriplet>
<VcpkgEnabled>true</VcpkgEnabled>
————————————————
版权声明：本文为CSDN博主「Achilles」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/cjmqas/article/details/79282847



cd "D:\visual studio 2015\Projects\CMakeProject1"
mkdir build
cd build
cmake ../ -DCMAKE_TOOLCHAIN_FILE="D:\vcpkg\scripts\buildsystems\vcpkg.cmake"



```

-- Building for: Visual Studio 15 2017
CMake Error at CMakeLists.txt:6 (project):
  Failed to run MSBuild command:

    MSBuild.exe

  to get the value of VCTargetsPath:

    用于 .NET Framework 的 Microsoft (R) 生成引擎版本 16.3.1+1def00d3d
    版权所有(C) Microsoft Corporation。保留所有权利。

    生成启动时间为 2019/12/20 19:29:45。
    节点 1 上的项目“D:\visual studio 2015\Projects\CMakeProject1\b\CMakeFiles\3.12.0\VCTargetsPath.vcxproj”(默认目标) 。
    D:\Program Files\Microsoft Visual Studio\2019\Professional\MSBuild\Microsoft\VC\v160\Microsoft.CppBuild.targets(379,5): error MSB8020: The build tools for Visual Studio 2017 (Platform Toolset = 'v141') cannot be found. To build using the v141 build tools, please install Visual Studio 2017 build tools.  Alternatively, you may upgrade to the current Visual Studio tools by selecting the Project menu or right-click the solution, and then selecting "Retarget solution". [D:\visual studio 2015\Projects\CMakeProject1\b\CMakeFiles\3.12.0\VCTargetsPath.vcxproj]
    已完成生成项目“D:\visual studio 2015\Projects\CMakeProject1\b\CMakeFiles\3.12.0\VCTargetsPath.vcxproj”(默认目标)的操作 - 失败。

    生成失败。

    “D:\visual studio 2015\Projects\CMakeProject1\b\CMakeFiles\3.12.0\VCTargetsPath.vcxproj”(默认目标) (1) ->
    (PrepareForBuild 目标) ->
      D:\Program Files\Microsoft Visual Studio\2019\Professional\MSBuild\Microsoft\VC\v160\Microsoft.CppBuild.targets(379,5): error MSB8020: The build tools for Visual Studio 2017 (Platform Toolset = 'v141') cannot be found. To build using the v141 build tools, please install Visual Studio 2017 build tools.  Alternatively, you may upgrade to the current Visual Studio tools by selecting the Project menu or right-click the solution, and then selecting "Retarget solution". [D:\visual studio 2015\Projects\CMakeProject1\b\CMakeFiles\3.12.0\VCTargetsPath.vcxproj]

        0 个警告
        1 个错误

    已用时间 00:00:00.35


  Exit code: 1



-- Configuring incomplete, errors occurred!
See also "D:/visual studio 2015/Projects/CMakeProject1/b/CMakeFiles/CMakeOutput.log".

```


vs 启动项


严重性	代码	说明	项目	文件	行	禁止显示状态	禁止显示状态
错误	MSB8020	无法找到 Visual Studio 2017 的生成工具(平台工具集 =“v141”)。若要使用 v141 生成工具进行生成，请安装 Visual Studio 2017 生成工具。或者，可以升级到当前 Visual Studio 工具，方式是通过选择“项目”菜单或右键单击该解决方案，然后选择“重定解决方案目标”。	D:\visual studio 2015\Projects\CMakeProject1\b\CMakeFiles\3.12.0\VCTargetsPath.vcxproj	D:\Program Files\Microsoft Visual Studio\2019\Professional\MSBuild\Microsoft\VC\v160\Microsoft.CppBuild.targets	379		


是由于没有安装v142工具集，其实v142对应的是VS2019，我的项目从另外一台电脑copy过来的，之前的编译器VS2019，现在是VS2017，所以报的这个错误。
v142–>VS2019
v141–>VS2017
v140–>VS2015
v120–>VS2013


<PlatformToolset>v141</PlatformToolset>

cmake 
cmake -version
cmake version 3.12.0


升级cmake版本到16(版本大于14)，命令行啊下运行，搞定



vs默认的编译文件是out文件夹，可以设置的
这里是out/build文件夹

新建类MyClass


### 如何写gtest单元测试用例

如何运行



 [使用Google Test库进行单元测试](https://chenxiaowei.gitbook.io/cmake-cookbook/4.0-chinese/4.3-chinese) 

 https://github.com/edidada/cmake-cookbook/tree/v1.0/chapter-04/recipe-03

 ### vcpkg
 
 `"CMAKE\CMake\bin\cmake.exe"  -G "Ninja"`

"cmd.exe" /c ""D:\PROGRAM FILES\MICROSOFT VISUAL STUDIO\2019\PROFESSIONAL\COMMON7\IDE\COMMONEXTENSIONS\MICROSOFT\CMAKE\CMake\bin\cmake.exe"  -G "Ninja" -DCMAKE_INSTALL_PREFIX:PATH="D:\visual studio 2015\Projects\CMakeProject1\out\install\x64-Debug" -DCMAKE_CXX_COMPILER:FILEPATH="D:/Program Files/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/14.23.28105/bin/HostX64/x64/cl.exe" -DCMAKE_C_COMPILER:FILEPATH="D:/Program Files/Microsoft Visual Studio/2019/Professional/VC/Tools/MSVC/14.23.28105/bin/HostX64/x64/cl.exe"  -DCMAKE_TOOLCHAIN_FILE="D:/vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE="Debug" -DCMAKE_MAKE_PROGRAM="D:\PROGRAM FILES\MICROSOFT VISUAL STUDIO\2019\PROFESSIONAL\COMMON7\IDE\COMMONEXTENSIONS\MICROSOFT\CMAKE\Ninja\ninja.exe" "D:\visual studio 2015\Projects\CMakeProject1" 2>&1"


.h文件

```cpp

#ifndef
#define
#endif

```


### cpprestsdk

https://microsoft.github.io/cpprestsdk/namespaces.html

例子
https://github.com/microsoft/cpprestsdk/tree/master/Release/samples



### cpp-netlib

https://cpp-netlib.org/0.13.0/index.html


严重性	代码	说明	项目	文件	行	禁止显示状态	禁止显示状态
错误		CMake Error at D:/vcpkg/scripts/buildsystems/vcpkg.cmake:263 (_find_package):
  Could not find a package configuration file provided by "cpp-netlib" with
  any of the following names:

    cpp-netlibConfig.cmake
    cpp-netlib-config.cmake

  Add the installation prefix of "cpp-netlib" to CMAKE_PREFIX_PATH or set
  "cpp-netlib_DIR" to a directory containing one of the above files.  If
  "cpp-netlib" provides a separate development package or SDK, be sure it has
  been installed.		D:/vcpkg/scripts/buildsystems/vcpkg.cmake	263		




  1> 工作目录: D:\visual studio 2015\Projects\CMakeProject1\out\build\x64-Debug
1> [CMake] CMake Error at D:/vcpkg/scripts/buildsystems/vcpkg.cmake:263 (_find_package):
1> [CMake]   Could not find a package configuration file provided by "cpp-netlib" with
1> [CMake]   any of the following names:
1> [CMake] 
1> [CMake]     cpp-netlibConfig.cmake
1> [CMake]     cpp-netlib-config.cmake
1> [CMake] 
1> [CMake]   Add the installation prefix of "cpp-netlib" to CMAKE_PREFIX_PATH or set
1> [CMake]   "cpp-netlib_DIR" to a directory containing one of the above files.  If
1> [CMake]   "cpp-netlib" provides a separate development package or SDK, be sure it has
1> [CMake]   been installed.
1> [CMake] Call Stack (most recent call first):
1> [CMake]   CMakeLists.txt:25 (find_package)
1> [CMake] -- Configuring incomplete, errors occurred!
1> [CMake] See also "D:/visual studio 2015/Projects/CMakeProject1/out/build/x64-Debug/CMakeFiles/CMakeOutput.log".


Poco缺少组件

cpp-netlib缺少什么，不晓得

[cpprestsdk应用实例](https://blog.csdn.net/guotianqing/article/details/102367570)

[cpprestsdk的使用注意问题](https://blog.csdn.net/hayaqi0504/article/details/82180528)
