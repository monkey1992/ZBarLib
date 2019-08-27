# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        iconv

        # Sets the library as a shared library.
        STATIC

        # Provides a relative path to your source file(s).
        libiconv/iconv.c
        )

add_library( # Sets the name of the library.
        zbar

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        convert.c
        decoder.c
        error.c
        image.c
        img_scanner.c

        refcnt.c
        scanner.c
        symbol.c
        video.c
        window.c

        qrcode/bch15_5.c
        qrcode/binarize.c
        qrcode/isaac.c
        qrcode/qrdec.c
        qrcode/qrdectxt.c
        qrcode/rs.c
        qrcode/util.c

        processor/null.c
        video/null.c
        window/null.c

        decoder/qr_finder.c
        decoder/code128.c
        decoder/code39.c
        decoder/code93.c
        decoder/codabar.c
        decoder/ean.c
        decoder/databar.c
        decoder/i25.c

        android_zbar.c

        libiconv/iconv.c
        )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        zbar

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
        ${iconv}
        )

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -s")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")