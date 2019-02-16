# Easy Platform Test (ept)
A simple header file for detecting the target operating system,
APIs, endianness, address size; as well as the compiler being used for
the build.

To use, just include `etg.h` somewhere, the license is included in the
header, so you can just add it anywhere in your project, no need to
copy the license file around.  All macros are defined to `(1)` if the
feature is present, otherwise are not defined.

## Operating System
Operating systems are defined as `IS_*` where `*` is the operating
system name.  Here's a list of operating systems that can be detected
and their respective macros defined.  Note that some operating systems
might define more than one of these, for example OSx and MacOS both
define `IS_APPLE` while MacOS also defines `IS_MACOS` and iOS defines
`IS_IOS`.

| Operating System       | Macros Defined                                      |
|------------------------|-----------------------------------------------------|
| Linux                  | `IS_LINUX`, `IS_UNIX`, `IS_POSIX`                   |
| Android                | `IS_LINUX`, `IS_UNIX`, `IS_POSIX`, `IS_ANDROID`     |
| Windows                | `IS_WINDOWS`, `IS_WINDOWS_32BIT|IS_WINDOWS_64BIT`   |
| MacOS                  | `IS_APPLE`, `IS_MACOS`, `IS_UNIX`                   |
| iOS                    | `IS_APPLE`, `IS_IOS`, `IS_UNIX`                     |
| Akaros                 | `IS_AKAROS`                                         |
| Fushsia                | `IS_FUSHSIA`                                        |
| AsmJS                  | `IS_WEB`, `IS_WEB_ASMJS`                            |
| WebAsm                 | `IS_WEB`, `IS_WEB_WASM`                             |
| BeOs                   | `IS_BEOS`                                           |
| Haiku                  | `IS_HAIKU`, `IS_BEOS`                               |
| BSD                    | `IS_BSD`, `IS_UNIX`, `IS_POSIX`                     |
| Solaris                | `IS_SOLARIS`, `IS_UNIX`, `IS_POSIX`, `IS_POSIX_CERT`|
| Cygwin                 | Windows Macros + `IS_CYGWIN`                        |
| GNU Hurd               | `IS_HURD`, `IS_UNIX`, `IS_POSIX`                    |
| Sun OS                 | `IS_SUNOS`, `IS_UNIX`, `IS_POSIX`                   |
| Minix                  | `IS_MINIX`, `IS_UNIX`, `IS_POSIX`                   |
| DOS                    | `IS_DOS`                                            |
| Plan9                  | `IS_PLAN9`                                          |
| Lynx                   | `IS_LYNX`, `IS_UNIX`, `IS_POSIX`, `IS_POSIX_CERT`   |
| Nucleus                | `IS_NUCLEUS`, `IS_UNIX`, `IS_POSIX`                 |
| AIX                    | `IS_AIX`, `IS_UNIX`, `IS_POSIX`, `IS_POSIX_CERT`    |
| HP-UX                  | `IS_HPUX`, `IS_UNIX`, `IS_POSIX`, `IS_POSIX_CERT`   |
| QNX                    | `IS_QNX`, `IS_UNIX`, `IS_POSIX`, `IS_POSIX_CERT`    |

Note that the `IS_UNIX` macro is based on the `__unix__` macro being
defined at compilation time; so some of these operating systems may
be Unix-like without my being aware of it, and thus my define the macro
even though I didn't list it here.  Also Windows targets will define
either `IS_WINDOWS_32BIT` _or_ `IS_WINDOWS_64BIT` depending on their
version of windows, the 64 bit version will not define both macros.

Also the `IS_POSIX` macro is defined for platforms that are loosely
compliant with the POSIX standard, while that and `IS_POSIX_CERT` is
defined for those that are certified as compliant.

## Endianness
The header defines both `HAS_LE_INT` and `HAS_BE_INT` to a constant
expression that resolves to `(1)` or `(0)` depending on the endianness
of the target platform. Also defined is a static variable, which is
used to perform the endianness test.  Some compilers may complain
about the unused variable, if you find this to be the case with
your compiler then submit an issue, and I'll add the proper pragmas.

## Char Size
The `HAS_8BIT_CHAR` macro is defined to a constant expression that
resolves to `(1)` if the platform's `char` type has a size of 8 bits
and `(0)` otherwise.

## Address Size
These depend on the `HAS_8BIT_CHAR` macro, so all address size testing
macros will resolve to `(0)` if this is false.  Otherwise the
`HAS_*_ADDR` macros are defined to expressions that resolve to `(1)` if
their platform's `void*` type has the repective bit width; the
following macros are defined:

* `HAS_8BIT_ADDR`
* `HAS_16BIT_ADDR`
* `HAS_24BIT_ADDR`
* `HAS_32BIT_ADDR`
* `HAS_64BIT_ADDR`

