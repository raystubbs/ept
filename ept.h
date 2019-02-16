/* MIT License
 * 
 * Copyright (c) 2019 Ray Stubbs
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ept_h
#define ept_h

#if defined(_WIN32) || defined(_WIN64) || defined(__WINDOWS__)
    #define IS_WINDOWS (1)
    #ifdef _WIN64
        #define IS_WINDOWS_64BIT (1)
    #else
        #define IS_WINDOWS_32BIT (1)
    #endif
#endif

#if __linux__
    #define IS_LINUX (1)
#endif

#ifdef __ANDROID__
    #define IS_ANDROID (1)
#endif

#if __APPLE__ || __MACH__
    #define IS_APPLE (1)
    #if TARGET_OS_MAC || __MACH__
        #define IS_MACOS (1)
    #elif TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
        #define IS_IOS (1)
    #endif
#endif

#if __unix__ || IS_APPLE
    #define IS_UNIX (1)
#endif

#if __ros__
    #define IS_AKAROS (1)
#endif

#if __Fushsia__
    #define IS_FUSHSIA (1)
#endif

#if __asmjs__
    #define IS_WEB (1)
    #define IS_WEB_ASMJS (1)
#endif

#if __wasm__
    #define IS_WEB (1)
    #define IS_WEB_WASM (1)
#endif

#if __BEOS__
    #define IS_BEOS (1)
#endif

#if __FreeBSD__ || __NetBSD__ || __OpenBSD__ || __bsdi__ || __DragonFly__
    #define IS_BSD (1)
#endif

#ifdef __CYGWIN__
    #define IS_CYGWIN (1)
#endif

#ifdef __gnu__hurd__
    #define IS_HURD (1)
#endif

#if defined(sun) || defined(__sun)
    #if defined(__SVR4) || defined(__svr4__)
        #define IS_SOLARIS (1)
    #else
        #define IS_SUNOS (1)
    #endif
#endif

#ifdef __minix
    #define IS_MINIX (1)
#endif

#if defined(__DOS__) || defined(__MSDOS__) || defined(_MSDOS) || defined(MSDOS)
    #define IS_DOS (1)
#endif

#if defined(EPLAN9)
    #define IS_PLAN9 (1)
#endif

#if defined(__HAIKU__)
    #define IS_HAIKU (1)
#endif

#if defined(__Lynx__)
    #define IS_LYNX (1)
#endif

#if defined(__nucleus__)
    #define IS_NUCLEUS (1)
#endif

#if defined(_AIX) || defined(__TOS_AIX__)
    #define IS_AIX (1)
#endif

#if defined(_hpux) || defined(hpux) || defined(__hpux)
    #define IS_HPUX (1)
#endif

#if defined(__QNX__) || defined(__QNXNTO__)
    #define IS_QNX (1)
#endif


#if IS_LINUX || IS_APPLE || IS_BEOS || IS_BSD || IS_SUNOS || \
    IS_LYNX || IS_MINIX || IS_CYGWIN || IS_NUCLEUS || IS_HURD
    #define IS_POSIX (1)
#endif

#if IS_AIX || IS_HPUX || IS_SOLARIS || IS_QNX
    #define IS_POSIX (1)
    #define IS_POSIX_CERT (1)
#endif

#if IS_MACOS
    #define IS_POSIX (1)
    
    // TODO: Detect if version > 10.4, if so then defined IS_POSIX_CERT
#endif

#if defined(_MSC_VER)
    #define WITH_MSC (1)
#endif

#if defined(__GNUC__)
    #define WITH_GCC (1)
#endif

#if defined(__clang__)
    #define WITH_CLANG (1)
#endif

#if defined(__EMSCRIPTEN__)
    #define WITH_EMSCRIPTEN
#endif

#if defined(__MINGW32__) || defined(__MINGW64__)
    #define WITH_MINGW (1)
#endif

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

static int const EPT_ENDIAN_TEST = 1;

#pragma GCC diagnostic pop

#define HAS_LE_INT (((char*)&EPT_ENDIAN_TEST)[0] == 1)
#define HAS_BE_INT (((char*)&EPT_ENDIAN_TEST)[0] != 1)

#define HAS_8BIT_CHAR  ((char)1 << 8 == 0 && (char)1 << 7 == 128)

#define HAS_8BIT_ADDR  (HAS_8BIT_CHAR && sizeof(void*) == 1)
#define HAS_16BIT_ADDR (HAS_8BIT_CHAR && sizeof(void*) == 2)
#define HAS_24BIT_ADDR (HAS_8BIT_CHAR && sizeof(void*) == 3)
#define HAS_32BIT_ADDR (HAS_8BIT_CHAR && sizeof(void*) == 4)
#define HAS_64BIT_ADDR (HAS_8BIT_CHAR && sizeof(void*) == 8)

#if WITH_GCC || WITH_CLANG
    #define THREADVAR( T ) __thread T
#elif WITH_MSC
    #define THREADVAR( T ) __declspec( thread ) T
#elif defined(__thread)
    #define THREADVAR( T ) __thread T
#elif defined(thread_local)
    #define THREADVAR( T ) thread_local T
#endif

#endif
