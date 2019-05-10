From: <Saved by Blink>
Snapshot-Content-Location: https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
Subject: 
Date: Tue, 6 May 2019 20:14:50 -0000
MIME-Version: 1.0
Content-Type: multipart/related;
	type="text/html";
	boundary="----MultipartBoundary--h9CxAyqN20e1UcmCjgKU8HxqXGaYBnLk43I7nmffTg----"

------MultipartBoundary--h9CxAyqN20e1UcmCjgKU8HxqXGaYBnLk43I7nmffTg----
Content-Type: text/html
Content-ID: <frame-308-ce33953a-dde8-42e6-b63a-607d764175ce@mhtml.blink>
Content-Transfer-Encoding: quoted-printable
Content-Location: https://raw.githubusercontent.com/nothings/stb/master/stb_image.h

<html><head><meta http-equiv=3D"Content-Type" content=3D"text/html; charset=
=3DUTF-8"></head><body><pre style=3D"word-wrap: break-word; white-space: pr=
e-wrap;">/* stb_image - v2.22 - public domain image loader - http://nothing=
s.org/stb
                                  no warranty implied; use at your own risk

   Do this:
      #define STB_IMAGE_IMPLEMENTATION
   before you include this file in *one* C or C++ file to create the implem=
entation.

   // i.e. it should look like this:
   #include ...
   #include ...
   #include ...
   #define STB_IMAGE_IMPLEMENTATION
   #include "stb_image.h"

   You can #define STBI_ASSERT(x) before the #include to avoid using assert=
.h.
   And #define STBI_MALLOC, STBI_REALLOC, and STBI_FREE to avoid using mall=
oc,realloc,free


   QUICK NOTES:
      Primarily of interest to game developers and other people who can
          avoid problematic images and only need the trivial interface

      JPEG baseline &amp; progressive (12 bpc/arithmetic not supported, sam=
e as stock IJG lib)
      PNG 1/2/4/8/16-bit-per-channel

      TGA (not sure what subset, if a subset)
      BMP non-1bpp, non-RLE
      PSD (composited view only, no extra channels, 8/16 bit-per-channel)

      GIF (*comp always reports as 4-channel)
      HDR (radiance rgbE format)
      PIC (Softimage PIC)
      PNM (PPM and PGM binary only)

      Animated GIF still needs a proper API, but here's one way to do it:
          http://gist.github.com/urraka/685d9a6340b26b830d49

      - decode from memory or through FILE (define STBI_NO_STDIO to remove =
code)
      - decode from arbitrary I/O callbacks
      - SIMD acceleration on x86/x64 (SSE2) and ARM (NEON)

   Full documentation under "DOCUMENTATION" below.


LICENSE

  See end of file for license information.

RECENT REVISION HISTORY:

      2.22  (2019-03-04) gif fixes, fix warnings
      2.21  (2019-02-25) fix typo in comment
      2.20  (2019-02-07) support utf8 filenames in Windows; fix warnings an=
d platform ifdefs=20
      2.19  (2018-02-11) fix warning
      2.18  (2018-01-30) fix warnings
      2.17  (2018-01-29) bugfix, 1-bit BMP, 16-bitness query, fix warnings
      2.16  (2017-07-23) all functions have 16-bit variants; optimizations;=
 bugfixes
      2.15  (2017-03-18) fix png-1,2,4; all Imagenet JPGs; no runtime SSE d=
etection on GCC
      2.14  (2017-03-03) remove deprecated STBI_JPEG_OLD; fixes for Imagene=
t JPGs
      2.13  (2016-12-04) experimental 16-bit API, only for PNG so far; fixe=
s
      2.12  (2016-04-02) fix typo in 2.11 PSD fix that caused crashes
      2.11  (2016-04-02) 16-bit PNGS; enable SSE2 in non-gcc x64
                         RGB-format JPEG; remove white matting in PSD;
                         allocate large structures on the stack;
                         correct channel count for PNG &amp; BMP
      2.10  (2016-01-22) avoid warning introduced in 2.09
      2.09  (2016-01-16) 16-bit TGA; comments in PNM files; STBI_REALLOC_SI=
ZED

   See end of file for full revision history.


 =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D    Contributors    =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D

 Image formats                          Extensions, features
    Sean Barrett (jpeg, png, bmp)          Jetro Lauha (stbi_info)
    Nicolas Schulz (hdr, psd)              Martin "SpartanJ" Golini (stbi_i=
nfo)
    Jonathan Dummer (tga)                  James "moose2000" Brown (iPhone =
PNG)
    Jean-Marc Lienher (gif)                Ben "Disch" Wenger (io callbacks=
)
    Tom Seddon (pic)                       Omar Cornut (1/2/4-bit PNG)
    Thatcher Ulrich (psd)                  Nicolas Guillemot (vertical flip=
)
    Ken Miller (pgm, ppm)                  Richard Mitton (16-bit PSD)
    github:urraka (animated gif)           Junggon Kim (PNM comments)
    Christopher Forseth (animated gif)     Daniel Gibson (16-bit TGA)
                                           socks-the-fox (16-bit PNG)
                                           Jeremy Sawicki (handle all Image=
Net JPGs)
 Optimizations &amp; bugfixes                  Mikhail Morozov (1-bit BMP)
    Fabian "ryg" Giesen                    Anael Seghezzi (is-16-bit query)
    Arseny Kapoulkine
    John-Mark Allen
    Carmelo J Fdez-Aguera

 Bug &amp; warning fixes
    Marc LeBlanc            David Woo          Guillaume George   Martins M=
ozeiko
    Christpher Lloyd        Jerry Jansson      Joseph Thomson     Phil Jord=
an
    Dave Moore              Roy Eltham         Hayaki Saito       Nathan Re=
ed
    Won Chun                Luke Graham        Johan Duparc       Nick Veri=
gakis
    the Horde3D community   Thomas Ruf         Ronny Chevalier    github:rl=
yeh
    Janez Zemva             John Bartholomew   Michal Cichon      github:ro=
migrou
    Jonathan Blow           Ken Hamada         Tero Hanninen      github:sv=
dijk
    Laurent Gomila          Cort Stratton      Sergio Gonzalez    github:sn=
agar
    Aruelien Pocheville     Thibault Reuille   Cass Everitt       github:Ze=
lex
    Ryamond Barbiero        Paul Du Bois       Engin Manap        github:gr=
im210
    Aldo Culquicondor       Philipp Wiesemann  Dale Weiler        github:sa=
mmyhw
    Oriol Ferrer Mesia      Josh Tobin         Matthew Gregan     github:ph=
prus
    Julian Raschke          Gregory Mullen     Baldur Karlsson    github:po=
ppolopoppo
    Christian Floisand      Kevin Schmidt      JR Smith           github:da=
realshinji
    Blazej Dariusz Roszkowski                                     github:Mi=
chaelangel007
*/

#ifndef STBI_INCLUDE_STB_IMAGE_H
#define STBI_INCLUDE_STB_IMAGE_H

// DOCUMENTATION
//
// Limitations:
//    - no 12-bit-per-channel JPEG
//    - no JPEGs with arithmetic coding
//    - GIF always returns *comp=3D4
//
// Basic usage (see HDR discussion below for HDR usage):
//    int x,y,n;
//    unsigned char *data =3D stbi_load(filename, &amp;x, &amp;y, &amp;n, 0=
);
//    // ... process data if not NULL ...
//    // ... x =3D width, y =3D height, n =3D # 8-bit components per pixel =
...
//    // ... replace '0' with '1'..'4' to force that many components per pi=
xel
//    // ... but 'n' will always be the number that it would have been if y=
ou said 0
//    stbi_image_free(data)
//
// Standard parameters:
//    int *x                 -- outputs image width in pixels
//    int *y                 -- outputs image height in pixels
//    int *channels_in_file  -- outputs # of image components in image file
//    int desired_channels   -- if non-zero, # of image components requeste=
d in result
//
// The return value from an image loader is an 'unsigned char *' which poin=
ts
// to the pixel data, or NULL on an allocation failure or if the image is
// corrupt or invalid. The pixel data consists of *y scanlines of *x pixels=
,
// with each pixel consisting of N interleaved 8-bit components; the first
// pixel pointed to is top-left-most in the image. There is no padding betw=
een
// image scanlines or between pixels, regardless of format. The number of
// components N is 'desired_channels' if desired_channels is non-zero, or
// *channels_in_file otherwise. If desired_channels is non-zero,
// *channels_in_file has the number of components that _would_ have been
// output otherwise. E.g. if you set desired_channels to 4, you will always
// get RGBA output, but you can check *channels_in_file to see if it's triv=
ially
// opaque because e.g. there were only 3 channels in the source image.
//
// An output image with N components has the following components interleav=
ed
// in this order in each pixel:
//
//     N=3D#comp     components
//       1           grey
//       2           grey, alpha
//       3           red, green, blue
//       4           red, green, blue, alpha
//
// If image loading fails for any reason, the return value will be NULL,
// and *x, *y, *channels_in_file will be unchanged. The function
// stbi_failure_reason() can be queried for an extremely brief, end-user
// unfriendly explanation of why the load failed. Define STBI_NO_FAILURE_ST=
RINGS
// to avoid compiling these strings at all, and STBI_FAILURE_USERMSG to get=
 slightly
// more user-friendly ones.
//
// Paletted PNG, BMP, GIF, and PIC images are automatically depalettized.
//
// =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D
//
// UNICODE:
//
//   If compiling for Windows and you wish to use Unicode filenames, compil=
e
//   with
//       #define STBI_WINDOWS_UTF8
//   and pass utf8-encoded filenames. Call stbi_convert_wchar_to_utf8 to co=
nvert
//   Windows wchar_t filenames to utf8.
//
// =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D
//
// Philosophy
//
// stb libraries are designed with the following priorities:
//
//    1. easy to use
//    2. easy to maintain
//    3. good performance
//
// Sometimes I let "good performance" creep up in priority over "easy to ma=
intain",
// and for best performance I may provide less-easy-to-use APIs that give h=
igher
// performance, in addition to the easy-to-use ones. Nevertheless, it's imp=
ortant
// to keep in mind that from the standpoint of you, a client of this librar=
y,
// all you care about is #1 and #3, and stb libraries DO NOT emphasize #3 a=
bove all.
//
// Some secondary priorities arise directly from the first two, some of whi=
ch
// provide more explicit reasons why performance can't be emphasized.
//
//    - Portable ("ease of use")
//    - Small source code footprint ("easy to maintain")
//    - No dependencies ("ease of use")
//
// =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D
//
// I/O callbacks
//
// I/O callbacks allow you to read from arbitrary sources, like packaged
// files or some other source. Data read from callbacks are processed
// through a small internal buffer (currently 128 bytes) to try to reduce
// overhead.
//
// The three functions you must define are "read" (reads some bytes of data=
),
// "skip" (skips some bytes of data), "eof" (reports if the stream is at th=
e end).
//
// =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D
//
// SIMD support
//
// The JPEG decoder will try to automatically use SIMD kernels on x86 when
// supported by the compiler. For ARM Neon support, you must explicitly
// request it.
//
// (The old do-it-yourself SIMD API is no longer supported in the current
// code.)
//
// On x86, SSE2 will automatically be used when available based on a run-ti=
me
// test; if not, the generic C versions are used as a fall-back. On ARM tar=
gets,
// the typical path is to have separate builds for NEON and non-NEON device=
s
// (at least this is true for iOS and Android). Therefore, the NEON support=
 is
// toggled by a build flag: define STBI_NEON to get NEON loops.
//
// If for some reason you do not want to use any of SIMD code, or if
// you have issues compiling it, you can disable it entirely by
// defining STBI_NO_SIMD.
//
// =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D
//
// HDR image support   (disable by defining STBI_NO_HDR)
//
// stb_image supports loading HDR images in general, and currently the Radi=
ance
// .HDR file format specifically. You can still load any file through the e=
xisting
// interface; if you attempt to load an HDR file, it will be automatically =
remapped
// to LDR, assuming gamma 2.2 and an arbitrary scale factor defaulting to 1=
;
// both of these constants can be reconfigured through this interface:
//
//     stbi_hdr_to_ldr_gamma(2.2f);
//     stbi_hdr_to_ldr_scale(1.0f);
//
// (note, do not use _inverse_ constants; stbi_image will invert them
// appropriately).
//
// Additionally, there is a new, parallel interface for loading files as
// (linear) floats to preserve the full dynamic range:
//
//    float *data =3D stbi_loadf(filename, &amp;x, &amp;y, &amp;n, 0);
//
// If you load LDR images through this interface, those images will
// be promoted to floating point values, run through the inverse of
// constants corresponding to the above:
//
//     stbi_ldr_to_hdr_scale(1.0f);
//     stbi_ldr_to_hdr_gamma(2.2f);
//
// Finally, given a filename (or an open file or memory block--see header
// file for details) containing image data, you can query for the "most
// appropriate" interface to use (that is, whether the image is HDR or
// not), using:
//
//     stbi_is_hdr(char *filename);
//
// =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D
//
// iPhone PNG support:
//
// By default we convert iphone-formatted PNGs back to RGB, even though
// they are internally encoded differently. You can disable this conversion
// by calling stbi_convert_iphone_png_to_rgb(0), in which case
// you will always just get the native iphone "format" through (which
// is BGR stored in RGB).
//
// Call stbi_set_unpremultiply_on_load(1) as well to force a divide per
// pixel to remove any premultiplied alpha *only* if the image file explici=
tly
// says there's premultiplied data (currently only happens in iPhone images=
,
// and only if iPhone convert-to-rgb processing is on).
//
// =3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=3D=
=3D
//
// ADDITIONAL CONFIGURATION
//
//  - You can suppress implementation of any of the decoders to reduce
//    your code footprint by #defining one or more of the following
//    symbols before creating the implementation.
//
//        STBI_NO_JPEG
//        STBI_NO_PNG
//        STBI_NO_BMP
//        STBI_NO_PSD
//        STBI_NO_TGA
//        STBI_NO_GIF
//        STBI_NO_HDR
//        STBI_NO_PIC
//        STBI_NO_PNM   (.ppm and .pgm)
//
//  - You can request *only* certain decoders and suppress all other ones
//    (this will be more forward-compatible, as addition of new decoders
//    doesn't require you to disable them explicitly):
//
//        STBI_ONLY_JPEG
//        STBI_ONLY_PNG
//        STBI_ONLY_BMP
//        STBI_ONLY_PSD
//        STBI_ONLY_TGA
//        STBI_ONLY_GIF
//        STBI_ONLY_HDR
//        STBI_ONLY_PIC
//        STBI_ONLY_PNM   (.ppm and .pgm)
//
//   - If you use STBI_NO_PNG (or _ONLY_ without PNG), and you still
//     want the zlib decoder to be available, #define STBI_SUPPORT_ZLIB
//


#ifndef STBI_NO_STDIO
#include &lt;stdio.h&gt;
#endif // STBI_NO_STDIO

#define STBI_VERSION 1

enum
{
   STBI_default =3D 0, // only used for desired_channels

   STBI_grey       =3D 1,
   STBI_grey_alpha =3D 2,
   STBI_rgb        =3D 3,
   STBI_rgb_alpha  =3D 4
};

#include &lt;stdlib.h&gt;
typedef unsigned char stbi_uc;
typedef unsigned short stbi_us;

#ifdef __cplusplus
extern "C" {
#endif

#ifndef STBIDEF
#ifdef STB_IMAGE_STATIC
#define STBIDEF static
#else
#define STBIDEF extern
#endif
#endif

///////////////////////////////////////////////////////////////////////////=
///
//
// PRIMARY API - works on images of any type
//

//
// load image by filename, open file, or memory buffer
//

typedef struct
{
   int      (*read)  (void *user,char *data,int size);   // fill 'data' wit=
h 'size' bytes.  return number of bytes actually read
   void     (*skip)  (void *user,int n);                 // skip the next '=
n' bytes, or 'unget' the last -n bytes if negative
   int      (*eof)   (void *user);                       // returns nonzero=
 if we are at end of file/data
} stbi_io_callbacks;

////////////////////////////////////
//
// 8-bits-per-channel interface
//

STBIDEF stbi_uc *stbi_load_from_memory   (stbi_uc           const *buffer, =
int len   , int *x, int *y, int *channels_in_file, int desired_channels);
STBIDEF stbi_uc *stbi_load_from_callbacks(stbi_io_callbacks const *clbk  , =
void *user, int *x, int *y, int *channels_in_file, int desired_channels);

#ifndef STBI_NO_STDIO
STBIDEF stbi_uc *stbi_load            (char const *filename, int *x, int *y=
, int *channels_in_file, int desired_channels);
STBIDEF stbi_uc *stbi_load_from_file  (FILE *f, int *x, int *y, int *channe=
ls_in_file, int desired_channels);
// for stbi_load_from_file, file pointer is left pointing immediately after=
 image
#endif

#ifndef STBI_NO_GIF
STBIDEF stbi_uc *stbi_load_gif_from_memory(stbi_uc const *buffer, int len, =
int **delays, int *x, int *y, int *z, int *comp, int req_comp);
#endif

#ifdef STBI_WINDOWS_UTF8
STBIDEF int stbi_convert_wchar_to_utf8(char *buffer, size_t bufferlen, cons=
t wchar_t* input);
#endif

////////////////////////////////////
//
// 16-bits-per-channel interface
//

STBIDEF stbi_us *stbi_load_16_from_memory   (stbi_uc const *buffer, int len=
, int *x, int *y, int *channels_in_file, int desired_channels);
STBIDEF stbi_us *stbi_load_16_from_callbacks(stbi_io_callbacks const *clbk,=
 void *user, int *x, int *y, int *channels_in_file, int desired_channels);

#ifndef STBI_NO_STDIO
STBIDEF stbi_us *stbi_load_16          (char const *filename, int *x, int *=
y, int *channels_in_file, int desired_channels);
STBIDEF stbi_us *stbi_load_from_file_16(FILE *f, int *x, int *y, int *chann=
els_in_file, int desired_channels);
#endif

////////////////////////////////////
//
// float-per-channel interface
//
#ifndef STBI_NO_LINEAR
   STBIDEF float *stbi_loadf_from_memory     (stbi_uc const *buffer, int le=
n, int *x, int *y, int *channels_in_file, int desired_channels);
   STBIDEF float *stbi_loadf_from_callbacks  (stbi_io_callbacks const *clbk=
, void *user, int *x, int *y,  int *channels_in_file, int desired_channels)=
;

   #ifndef STBI_NO_STDIO
   STBIDEF float *stbi_loadf            (char const *filename, int *x, int =
*y, int *channels_in_file, int desired_channels);
   STBIDEF float *stbi_loadf_from_file  (FILE *f, int *x, int *y, int *chan=
nels_in_file, int desired_channels);
   #endif
#endif

#ifndef STBI_NO_HDR
   STBIDEF void   stbi_hdr_to_ldr_gamma(float gamma);
   STBIDEF void   stbi_hdr_to_ldr_scale(float scale);
#endif // STBI_NO_HDR

#ifndef STBI_NO_LINEAR
   STBIDEF void   stbi_ldr_to_hdr_gamma(float gamma);
   STBIDEF void   stbi_ldr_to_hdr_scale(float scale);
#endif // STBI_NO_LINEAR

// stbi_is_hdr is always defined, but always returns false if STBI_NO_HDR
STBIDEF int    stbi_is_hdr_from_callbacks(stbi_io_callbacks const *clbk, vo=
id *user);
STBIDEF int    stbi_is_hdr_from_memory(stbi_uc const *buffer, int len);
#ifndef STBI_NO_STDIO
STBIDEF int      stbi_is_hdr          (char const *filename);
STBIDEF int      stbi_is_hdr_from_file(FILE *f);
#endif // STBI_NO_STDIO


// get a VERY brief reason for failure
// NOT THREADSAFE
STBIDEF const char *stbi_failure_reason  (void);

// free the loaded image -- this is just free()
STBIDEF void     stbi_image_free      (void *retval_from_stbi_load);

// get image dimensions &amp; components without fully decoding
STBIDEF int      stbi_info_from_memory(stbi_uc const *buffer, int len, int =
*x, int *y, int *comp);
STBIDEF int      stbi_info_from_callbacks(stbi_io_callbacks const *clbk, vo=
id *user, int *x, int *y, int *comp);
STBIDEF int      stbi_is_16_bit_from_memory(stbi_uc const *buffer, int len)=
;
STBIDEF int      stbi_is_16_bit_from_callbacks(stbi_io_callbacks const *clb=
k, void *user);

#ifndef STBI_NO_STDIO
STBIDEF int      stbi_info               (char const *filename,     int *x,=
 int *y, int *comp);
STBIDEF int      stbi_info_from_file     (FILE *f,                  int *x,=
 int *y, int *comp);
STBIDEF int      stbi_is_16_bit          (char const *filename);
STBIDEF int      stbi_is_16_bit_from_file(FILE *f);
#endif



// for image formats that explicitly notate that they have premultiplied al=
pha,
// we just return the colors as stored in the file. set this flag to force
// unpremultiplication. results are undefined if the unpremultiply overflow=
.
STBIDEF void stbi_set_unpremultiply_on_load(int flag_true_if_should_unpremu=
ltiply);

// indicate whether we should process iphone images back to canonical forma=
t,
// or just pass them through "as-is"
STBIDEF void stbi_convert_iphone_png_to_rgb(int flag_true_if_should_convert=
);

// flip the image vertically, so the first pixel in the output array is the=
 bottom left
STBIDEF void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip)=
;

// ZLIB client - used by PNG, available for other purposes

STBIDEF char *stbi_zlib_decode_malloc_guesssize(const char *buffer, int len=
, int initial_size, int *outlen);
STBIDEF char *stbi_zlib_decode_malloc_guesssize_headerflag(const char *buff=
er, int len, int initial_size, int *outlen, int parse_header);
STBIDEF char *stbi_zlib_decode_malloc(const char *buffer, int len, int *out=
len);
STBIDEF int   stbi_zlib_decode_buffer(char *obuffer, int olen, const char *=
ibuffer, int ilen);

STBIDEF char *stbi_zlib_decode_noheader_malloc(const char *buffer, int len,=
 int *outlen);
STBIDEF int   stbi_zlib_decode_noheader_buffer(char *obuffer, int olen, con=
st char *ibuffer, int ilen);


#ifdef __cplusplus
}
#endif

//
//
////   end header file   //////////////////////////////////////////////////=
///
#endif // STBI_INCLUDE_STB_IMAGE_H

#ifdef STB_IMAGE_IMPLEMENTATION

#if defined(STBI_ONLY_JPEG) || defined(STBI_ONLY_PNG) || defined(STBI_ONLY_=
BMP) \
  || defined(STBI_ONLY_TGA) || defined(STBI_ONLY_GIF) || defined(STBI_ONLY_=
PSD) \
  || defined(STBI_ONLY_HDR) || defined(STBI_ONLY_PIC) || defined(STBI_ONLY_=
PNM) \
  || defined(STBI_ONLY_ZLIB)
   #ifndef STBI_ONLY_JPEG
   #define STBI_NO_JPEG
   #endif
   #ifndef STBI_ONLY_PNG
   #define STBI_NO_PNG
   #endif
   #ifndef STBI_ONLY_BMP
   #define STBI_NO_BMP
   #endif
   #ifndef STBI_ONLY_PSD
   #define STBI_NO_PSD
   #endif
   #ifndef STBI_ONLY_TGA
   #define STBI_NO_TGA
   #endif
   #ifndef STBI_ONLY_GIF
   #define STBI_NO_GIF
   #endif
   #ifndef STBI_ONLY_HDR
   #define STBI_NO_HDR
   #endif
   #ifndef STBI_ONLY_PIC
   #define STBI_NO_PIC
   #endif
   #ifndef STBI_ONLY_PNM
   #define STBI_NO_PNM
   #endif
#endif

#if defined(STBI_NO_PNG) &amp;&amp; !defined(STBI_SUPPORT_ZLIB) &amp;&amp; =
!defined(STBI_NO_ZLIB)
#define STBI_NO_ZLIB
#endif


#include &lt;stdarg.h&gt;
#include &lt;stddef.h&gt; // ptrdiff_t on osx
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#include &lt;limits.h&gt;

#if !defined(STBI_NO_LINEAR) || !defined(STBI_NO_HDR)
#include &lt;math.h&gt;  // ldexp, pow
#endif

#ifndef STBI_NO_STDIO
#include &lt;stdio.h&gt;
#endif

#ifndef STBI_ASSERT
#include &lt;assert.h&gt;
#define STBI_ASSERT(x) assert(x)
#endif

#ifdef __cplusplus
#define STBI_EXTERN extern "C"
#else
#define STBI_EXTERN extern
#endif


#ifndef _MSC_VER
   #ifdef __cplusplus
   #define stbi_inline inline
   #else
   #define stbi_inline
   #endif
#else
   #define stbi_inline __forceinline
#endif


#ifdef _MSC_VER
typedef unsigned short stbi__uint16;
typedef   signed short stbi__int16;
typedef unsigned int   stbi__uint32;
typedef   signed int   stbi__int32;
#else
#include &lt;stdint.h&gt;
typedef uint16_t stbi__uint16;
typedef int16_t  stbi__int16;
typedef uint32_t stbi__uint32;
typedef int32_t  stbi__int32;
#endif

// should produce compiler error if size is wrong
typedef unsigned char validate_uint32[sizeof(stbi__uint32)=3D=3D4 ? 1 : -1]=
;

#ifdef _MSC_VER
#define STBI_NOTUSED(v)  (void)(v)
#else
#define STBI_NOTUSED(v)  (void)sizeof(v)
#endif

#ifdef _MSC_VER
#define STBI_HAS_LROTL
#endif

#ifdef STBI_HAS_LROTL
   #define stbi_lrot(x,y)  _lrotl(x,y)
#else
   #define stbi_lrot(x,y)  (((x) &lt;&lt; (y)) | ((x) &gt;&gt; (32 - (y))))
#endif

#if defined(STBI_MALLOC) &amp;&amp; defined(STBI_FREE) &amp;&amp; (defined(=
STBI_REALLOC) || defined(STBI_REALLOC_SIZED))
// ok
#elif !defined(STBI_MALLOC) &amp;&amp; !defined(STBI_FREE) &amp;&amp; !defi=
ned(STBI_REALLOC) &amp;&amp; !defined(STBI_REALLOC_SIZED)
// ok
#else
#error "Must define all or none of STBI_MALLOC, STBI_FREE, and STBI_REALLOC=
 (or STBI_REALLOC_SIZED)."
#endif

#ifndef STBI_MALLOC
#define STBI_MALLOC(sz)           malloc(sz)
#define STBI_REALLOC(p,newsz)     realloc(p,newsz)
#define STBI_FREE(p)              free(p)
#endif

#ifndef STBI_REALLOC_SIZED
#define STBI_REALLOC_SIZED(p,oldsz,newsz) STBI_REALLOC(p,newsz)
#endif

// x86/x64 detection
#if defined(__x86_64__) || defined(_M_X64)
#define STBI__X64_TARGET
#elif defined(__i386) || defined(_M_IX86)
#define STBI__X86_TARGET
#endif

#if defined(__GNUC__) &amp;&amp; defined(STBI__X86_TARGET) &amp;&amp; !defi=
ned(__SSE2__) &amp;&amp; !defined(STBI_NO_SIMD)
// gcc doesn't support sse2 intrinsics unless you compile with -msse2,
// which in turn means it gets to use SSE2 everywhere. This is unfortunate,
// but previous attempts to provide the SSE2 functions with runtime
// detection caused numerous issues. The way architecture extensions are
// exposed in GCC/Clang is, sadly, not really suited for one-file libs.
// New behavior: if compiled with -msse2, we use SSE2 without any
// detection; if not, we don't use it at all.
#define STBI_NO_SIMD
#endif

#if defined(__MINGW32__) &amp;&amp; defined(STBI__X86_TARGET) &amp;&amp; !d=
efined(STBI_MINGW_ENABLE_SSE2) &amp;&amp; !defined(STBI_NO_SIMD)
// Note that __MINGW32__ doesn't actually mean 32-bit, so we have to avoid =
STBI__X64_TARGET
//
// 32-bit MinGW wants ESP to be 16-byte aligned, but this is not in the
// Windows ABI and VC++ as well as Windows DLLs don't maintain that invaria=
nt.
// As a result, enabling SSE2 on 32-bit MinGW is dangerous when not
// simultaneously enabling "-mstackrealign".
//
// See https://github.com/nothings/stb/issues/81 for more information.
//
// So default to no SSE2 on 32-bit MinGW. If you've read this far and added
// -mstackrealign to your build settings, feel free to #define STBI_MINGW_E=
NABLE_SSE2.
#define STBI_NO_SIMD
#endif

#if !defined(STBI_NO_SIMD) &amp;&amp; (defined(STBI__X86_TARGET) || defined=
(STBI__X64_TARGET))
#define STBI_SSE2
#include &lt;emmintrin.h&gt;

#ifdef _MSC_VER

#if _MSC_VER &gt;=3D 1400  // not VC6
#include &lt;intrin.h&gt; // __cpuid
static int stbi__cpuid3(void)
{
   int info[4];
   __cpuid(info,1);
   return info[3];
}
#else
static int stbi__cpuid3(void)
{
   int res;
   __asm {
      mov  eax,1
      cpuid
      mov  res,edx
   }
   return res;
}
#endif

#define STBI_SIMD_ALIGN(type, name) __declspec(align(16)) type name

#if !defined(STBI_NO_JPEG) &amp;&amp; defined(STBI_SSE2)
static int stbi__sse2_available(void)
{
   int info3 =3D stbi__cpuid3();
   return ((info3 &gt;&gt; 26) &amp; 1) !=3D 0;
}
#endif

#else // assume GCC-style if not VC++
#define STBI_SIMD_ALIGN(type, name) type name __attribute__((aligned(16)))

#if !defined(STBI_NO_JPEG) &amp;&amp; defined(STBI_SSE2)
static int stbi__sse2_available(void)
{
   // If we're even attempting to compile this on GCC/Clang, that means
   // -msse2 is on, which means the compiler is allowed to use SSE2
   // instructions at will, and so are we.
   return 1;
}
#endif

#endif
#endif

// ARM NEON
#if defined(STBI_NO_SIMD) &amp;&amp; defined(STBI_NEON)
#undef STBI_NEON
#endif

#ifdef STBI_NEON
#include &lt;arm_neon.h&gt;
// assume GCC or Clang on ARM targets
#define STBI_SIMD_ALIGN(type, name) type name __attribute__((aligned(16)))
#endif

#ifndef STBI_SIMD_ALIGN
#define STBI_SIMD_ALIGN(type, name) type name
#endif

///////////////////////////////////////////////
//
//  stbi__context struct and start_xxx functions

// stbi__context structure is our basic context used by all images, so it
// contains all the IO context, plus some basic image information
typedef struct
{
   stbi__uint32 img_x, img_y;
   int img_n, img_out_n;

   stbi_io_callbacks io;
   void *io_user_data;

   int read_from_callbacks;
   int buflen;
   stbi_uc buffer_start[128];

   stbi_uc *img_buffer, *img_buffer_end;
   stbi_uc *img_buffer_original, *img_buffer_original_end;
} stbi__context;


static void stbi__refill_buffer(stbi__context *s);

// initialize a memory-decode context
static void stbi__start_mem(stbi__context *s, stbi_uc const *buffer, int le=
n)
{
   s-&gt;io.read =3D NULL;
   s-&gt;read_from_callbacks =3D 0;
   s-&gt;img_buffer =3D s-&gt;img_buffer_original =3D (stbi_uc *) buffer;
   s-&gt;img_buffer_end =3D s-&gt;img_buffer_original_end =3D (stbi_uc *) b=
uffer+len;
}

// initialize a callback-based context
static void stbi__start_callbacks(stbi__context *s, stbi_io_callbacks *c, v=
oid *user)
{
   s-&gt;io =3D *c;
   s-&gt;io_user_data =3D user;
   s-&gt;buflen =3D sizeof(s-&gt;buffer_start);
   s-&gt;read_from_callbacks =3D 1;
   s-&gt;img_buffer_original =3D s-&gt;buffer_start;
   stbi__refill_buffer(s);
   s-&gt;img_buffer_original_end =3D s-&gt;img_buffer_end;
}

#ifndef STBI_NO_STDIO

static int stbi__stdio_read(void *user, char *data, int size)
{
   return (int) fread(data,1,size,(FILE*) user);
}

static void stbi__stdio_skip(void *user, int n)
{
   fseek((FILE*) user, n, SEEK_CUR);
}

static int stbi__stdio_eof(void *user)
{
   return feof((FILE*) user);
}

static stbi_io_callbacks stbi__stdio_callbacks =3D
{
   stbi__stdio_read,
   stbi__stdio_skip,
   stbi__stdio_eof,
};

static void stbi__start_file(stbi__context *s, FILE *f)
{
   stbi__start_callbacks(s, &amp;stbi__stdio_callbacks, (void *) f);
}

//static void stop_file(stbi__context *s) { }

#endif // !STBI_NO_STDIO

static void stbi__rewind(stbi__context *s)
{
   // conceptually rewind SHOULD rewind to the beginning of the stream,
   // but we just rewind to the beginning of the initial buffer, because
   // we only use it after doing 'test', which only ever looks at at most 9=
2 bytes
   s-&gt;img_buffer =3D s-&gt;img_buffer_original;
   s-&gt;img_buffer_end =3D s-&gt;img_buffer_original_end;
}

enum
{
   STBI_ORDER_RGB,
   STBI_ORDER_BGR
};

typedef struct
{
   int bits_per_channel;
   int num_channels;
   int channel_order;
} stbi__result_info;

#ifndef STBI_NO_JPEG
static int      stbi__jpeg_test(stbi__context *s);
static void    *stbi__jpeg_load(stbi__context *s, int *x, int *y, int *comp=
, int req_comp, stbi__result_info *ri);
static int      stbi__jpeg_info(stbi__context *s, int *x, int *y, int *comp=
);
#endif

#ifndef STBI_NO_PNG
static int      stbi__png_test(stbi__context *s);
static void    *stbi__png_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri);
static int      stbi__png_info(stbi__context *s, int *x, int *y, int *comp)=
;
static int      stbi__png_is16(stbi__context *s);
#endif

#ifndef STBI_NO_BMP
static int      stbi__bmp_test(stbi__context *s);
static void    *stbi__bmp_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri);
static int      stbi__bmp_info(stbi__context *s, int *x, int *y, int *comp)=
;
#endif

#ifndef STBI_NO_TGA
static int      stbi__tga_test(stbi__context *s);
static void    *stbi__tga_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri);
static int      stbi__tga_info(stbi__context *s, int *x, int *y, int *comp)=
;
#endif

#ifndef STBI_NO_PSD
static int      stbi__psd_test(stbi__context *s);
static void    *stbi__psd_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri, int bpc);
static int      stbi__psd_info(stbi__context *s, int *x, int *y, int *comp)=
;
static int      stbi__psd_is16(stbi__context *s);
#endif

#ifndef STBI_NO_HDR
static int      stbi__hdr_test(stbi__context *s);
static float   *stbi__hdr_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri);
static int      stbi__hdr_info(stbi__context *s, int *x, int *y, int *comp)=
;
#endif

#ifndef STBI_NO_PIC
static int      stbi__pic_test(stbi__context *s);
static void    *stbi__pic_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri);
static int      stbi__pic_info(stbi__context *s, int *x, int *y, int *comp)=
;
#endif

#ifndef STBI_NO_GIF
static int      stbi__gif_test(stbi__context *s);
static void    *stbi__gif_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri);
static void    *stbi__load_gif_main(stbi__context *s, int **delays, int *x,=
 int *y, int *z, int *comp, int req_comp);
static int      stbi__gif_info(stbi__context *s, int *x, int *y, int *comp)=
;
#endif

#ifndef STBI_NO_PNM
static int      stbi__pnm_test(stbi__context *s);
static void    *stbi__pnm_load(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp, stbi__result_info *ri);
static int      stbi__pnm_info(stbi__context *s, int *x, int *y, int *comp)=
;
#endif

// this is not threadsafe
static const char *stbi__g_failure_reason;

STBIDEF const char *stbi_failure_reason(void)
{
   return stbi__g_failure_reason;
}

static int stbi__err(const char *str)
{
   stbi__g_failure_reason =3D str;
   return 0;
}

static void *stbi__malloc(size_t size)
{
    return STBI_MALLOC(size);
}

// stb_image uses ints pervasively, including for offset calculations.
// therefore the largest decoded image size we can support with the
// current code, even on 64-bit targets, is INT_MAX. this is not a
// significant limitation for the intended use case.
//
// we do, however, need to make sure our size calculations don't
// overflow. hence a few helper functions for size calculations that
// multiply integers together, making sure that they're non-negative
// and no overflow occurs.

// return 1 if the sum is valid, 0 on overflow.
// negative terms are considered invalid.
static int stbi__addsizes_valid(int a, int b)
{
   if (b &lt; 0) return 0;
   // now 0 &lt;=3D b &lt;=3D INT_MAX, hence also
   // 0 &lt;=3D INT_MAX - b &lt;=3D INTMAX.
   // And "a + b &lt;=3D INT_MAX" (which might overflow) is the
   // same as a &lt;=3D INT_MAX - b (no overflow)
   return a &lt;=3D INT_MAX - b;
}

// returns 1 if the product is valid, 0 on overflow.
// negative factors are considered invalid.
static int stbi__mul2sizes_valid(int a, int b)
{
   if (a &lt; 0 || b &lt; 0) return 0;
   if (b =3D=3D 0) return 1; // mul-by-0 is always safe
   // portable way to check for no overflows in a*b
   return a &lt;=3D INT_MAX/b;
}

// returns 1 if "a*b + add" has no negative terms/factors and doesn't overf=
low
static int stbi__mad2sizes_valid(int a, int b, int add)
{
   return stbi__mul2sizes_valid(a, b) &amp;&amp; stbi__addsizes_valid(a*b, =
add);
}

// returns 1 if "a*b*c + add" has no negative terms/factors and doesn't ove=
rflow
static int stbi__mad3sizes_valid(int a, int b, int c, int add)
{
   return stbi__mul2sizes_valid(a, b) &amp;&amp; stbi__mul2sizes_valid(a*b,=
 c) &amp;&amp;
      stbi__addsizes_valid(a*b*c, add);
}

// returns 1 if "a*b*c*d + add" has no negative terms/factors and doesn't o=
verflow
#if !defined(STBI_NO_LINEAR) || !defined(STBI_NO_HDR)
static int stbi__mad4sizes_valid(int a, int b, int c, int d, int add)
{
   return stbi__mul2sizes_valid(a, b) &amp;&amp; stbi__mul2sizes_valid(a*b,=
 c) &amp;&amp;
      stbi__mul2sizes_valid(a*b*c, d) &amp;&amp; stbi__addsizes_valid(a*b*c=
*d, add);
}
#endif

// mallocs with size overflow checking
static void *stbi__malloc_mad2(int a, int b, int add)
{
   if (!stbi__mad2sizes_valid(a, b, add)) return NULL;
   return stbi__malloc(a*b + add);
}

static void *stbi__malloc_mad3(int a, int b, int c, int add)
{
   if (!stbi__mad3sizes_valid(a, b, c, add)) return NULL;
   return stbi__malloc(a*b*c + add);
}

#if !defined(STBI_NO_LINEAR) || !defined(STBI_NO_HDR)
static void *stbi__malloc_mad4(int a, int b, int c, int d, int add)
{
   if (!stbi__mad4sizes_valid(a, b, c, d, add)) return NULL;
   return stbi__malloc(a*b*c*d + add);
}
#endif

// stbi__err - error
// stbi__errpf - error returning pointer to float
// stbi__errpuc - error returning pointer to unsigned char

#ifdef STBI_NO_FAILURE_STRINGS
   #define stbi__err(x,y)  0
#elif defined(STBI_FAILURE_USERMSG)
   #define stbi__err(x,y)  stbi__err(y)
#else
   #define stbi__err(x,y)  stbi__err(x)
#endif

#define stbi__errpf(x,y)   ((float *)(size_t) (stbi__err(x,y)?NULL:NULL))
#define stbi__errpuc(x,y)  ((unsigned char *)(size_t) (stbi__err(x,y)?NULL:=
NULL))

STBIDEF void stbi_image_free(void *retval_from_stbi_load)
{
   STBI_FREE(retval_from_stbi_load);
}

#ifndef STBI_NO_LINEAR
static float   *stbi__ldr_to_hdr(stbi_uc *data, int x, int y, int comp);
#endif

#ifndef STBI_NO_HDR
static stbi_uc *stbi__hdr_to_ldr(float   *data, int x, int y, int comp);
#endif

static int stbi__vertically_flip_on_load =3D 0;

STBIDEF void stbi_set_flip_vertically_on_load(int flag_true_if_should_flip)
{
    stbi__vertically_flip_on_load =3D flag_true_if_should_flip;
}

static void *stbi__load_main(stbi__context *s, int *x, int *y, int *comp, i=
nt req_comp, stbi__result_info *ri, int bpc)
{
   memset(ri, 0, sizeof(*ri)); // make sure it's initialized if we add new =
fields
   ri-&gt;bits_per_channel =3D 8; // default is 8 so most paths don't have =
to be changed
   ri-&gt;channel_order =3D STBI_ORDER_RGB; // all current input &amp; outp=
ut are this, but this is here so we can add BGR order
   ri-&gt;num_channels =3D 0;

   #ifndef STBI_NO_JPEG
   if (stbi__jpeg_test(s)) return stbi__jpeg_load(s,x,y,comp,req_comp, ri);
   #endif
   #ifndef STBI_NO_PNG
   if (stbi__png_test(s))  return stbi__png_load(s,x,y,comp,req_comp, ri);
   #endif
   #ifndef STBI_NO_BMP
   if (stbi__bmp_test(s))  return stbi__bmp_load(s,x,y,comp,req_comp, ri);
   #endif
   #ifndef STBI_NO_GIF
   if (stbi__gif_test(s))  return stbi__gif_load(s,x,y,comp,req_comp, ri);
   #endif
   #ifndef STBI_NO_PSD
   if (stbi__psd_test(s))  return stbi__psd_load(s,x,y,comp,req_comp, ri, b=
pc);
   #endif
   #ifndef STBI_NO_PIC
   if (stbi__pic_test(s))  return stbi__pic_load(s,x,y,comp,req_comp, ri);
   #endif
   #ifndef STBI_NO_PNM
   if (stbi__pnm_test(s))  return stbi__pnm_load(s,x,y,comp,req_comp, ri);
   #endif

   #ifndef STBI_NO_HDR
   if (stbi__hdr_test(s)) {
      float *hdr =3D stbi__hdr_load(s, x,y,comp,req_comp, ri);
      return stbi__hdr_to_ldr(hdr, *x, *y, req_comp ? req_comp : *comp);
   }
   #endif

   #ifndef STBI_NO_TGA
   // test tga last because it's a crappy test!
   if (stbi__tga_test(s))
      return stbi__tga_load(s,x,y,comp,req_comp, ri);
   #endif

   return stbi__errpuc("unknown image type", "Image not of any known type, =
or corrupt");
}

static stbi_uc *stbi__convert_16_to_8(stbi__uint16 *orig, int w, int h, int=
 channels)
{
   int i;
   int img_len =3D w * h * channels;
   stbi_uc *reduced;

   reduced =3D (stbi_uc *) stbi__malloc(img_len);
   if (reduced =3D=3D NULL) return stbi__errpuc("outofmem", "Out of memory"=
);

   for (i =3D 0; i &lt; img_len; ++i)
      reduced[i] =3D (stbi_uc)((orig[i] &gt;&gt; 8) &amp; 0xFF); // top hal=
f of each byte is sufficient approx of 16-&gt;8 bit scaling

   STBI_FREE(orig);
   return reduced;
}

static stbi__uint16 *stbi__convert_8_to_16(stbi_uc *orig, int w, int h, int=
 channels)
{
   int i;
   int img_len =3D w * h * channels;
   stbi__uint16 *enlarged;

   enlarged =3D (stbi__uint16 *) stbi__malloc(img_len*2);
   if (enlarged =3D=3D NULL) return (stbi__uint16 *) stbi__errpuc("outofmem=
", "Out of memory");

   for (i =3D 0; i &lt; img_len; ++i)
      enlarged[i] =3D (stbi__uint16)((orig[i] &lt;&lt; 8) + orig[i]); // re=
plicate to high and low byte, maps 0-&gt;0, 255-&gt;0xffff

   STBI_FREE(orig);
   return enlarged;
}

static void stbi__vertical_flip(void *image, int w, int h, int bytes_per_pi=
xel)
{
   int row;
   size_t bytes_per_row =3D (size_t)w * bytes_per_pixel;
   stbi_uc temp[2048];
   stbi_uc *bytes =3D (stbi_uc *)image;

   for (row =3D 0; row &lt; (h&gt;&gt;1); row++) {
      stbi_uc *row0 =3D bytes + row*bytes_per_row;
      stbi_uc *row1 =3D bytes + (h - row - 1)*bytes_per_row;
      // swap row0 with row1
      size_t bytes_left =3D bytes_per_row;
      while (bytes_left) {
         size_t bytes_copy =3D (bytes_left &lt; sizeof(temp)) ? bytes_left =
: sizeof(temp);
         memcpy(temp, row0, bytes_copy);
         memcpy(row0, row1, bytes_copy);
         memcpy(row1, temp, bytes_copy);
         row0 +=3D bytes_copy;
         row1 +=3D bytes_copy;
         bytes_left -=3D bytes_copy;
      }
   }
}

#ifndef STBI_NO_GIF
static void stbi__vertical_flip_slices(void *image, int w, int h, int z, in=
t bytes_per_pixel)
{
   int slice;
   int slice_size =3D w * h * bytes_per_pixel;

   stbi_uc *bytes =3D (stbi_uc *)image;
   for (slice =3D 0; slice &lt; z; ++slice) {
      stbi__vertical_flip(bytes, w, h, bytes_per_pixel);=20
      bytes +=3D slice_size;=20
   }
}
#endif

static unsigned char *stbi__load_and_postprocess_8bit(stbi__context *s, int=
 *x, int *y, int *comp, int req_comp)
{
   stbi__result_info ri;
   void *result =3D stbi__load_main(s, x, y, comp, req_comp, &amp;ri, 8);

   if (result =3D=3D NULL)
      return NULL;

   if (ri.bits_per_channel !=3D 8) {
      STBI_ASSERT(ri.bits_per_channel =3D=3D 16);
      result =3D stbi__convert_16_to_8((stbi__uint16 *) result, *x, *y, req=
_comp =3D=3D 0 ? *comp : req_comp);
      ri.bits_per_channel =3D 8;
   }

   // @TODO: move stbi__convert_format to here

   if (stbi__vertically_flip_on_load) {
      int channels =3D req_comp ? req_comp : *comp;
      stbi__vertical_flip(result, *x, *y, channels * sizeof(stbi_uc));
   }

   return (unsigned char *) result;
}

static stbi__uint16 *stbi__load_and_postprocess_16bit(stbi__context *s, int=
 *x, int *y, int *comp, int req_comp)
{
   stbi__result_info ri;
   void *result =3D stbi__load_main(s, x, y, comp, req_comp, &amp;ri, 16);

   if (result =3D=3D NULL)
      return NULL;

   if (ri.bits_per_channel !=3D 16) {
      STBI_ASSERT(ri.bits_per_channel =3D=3D 8);
      result =3D stbi__convert_8_to_16((stbi_uc *) result, *x, *y, req_comp=
 =3D=3D 0 ? *comp : req_comp);
      ri.bits_per_channel =3D 16;
   }

   // @TODO: move stbi__convert_format16 to here
   // @TODO: special case RGB-to-Y (and RGBA-to-YA) for 8-bit-to-16-bit cas=
e to keep more precision

   if (stbi__vertically_flip_on_load) {
      int channels =3D req_comp ? req_comp : *comp;
      stbi__vertical_flip(result, *x, *y, channels * sizeof(stbi__uint16));
   }

   return (stbi__uint16 *) result;
}

#if !defined(STBI_NO_HDR) &amp;&amp; !defined(STBI_NO_LINEAR)
static void stbi__float_postprocess(float *result, int *x, int *y, int *com=
p, int req_comp)
{
   if (stbi__vertically_flip_on_load &amp;&amp; result !=3D NULL) {
      int channels =3D req_comp ? req_comp : *comp;
      stbi__vertical_flip(result, *x, *y, channels * sizeof(float));
   }
}
#endif

#ifndef STBI_NO_STDIO

#if defined(_MSC_VER) &amp;&amp; defined(STBI_WINDOWS_UTF8)
STBI_EXTERN __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigne=
d int cp, unsigned long flags, const char *str, int cbmb, wchar_t *widestr,=
 int cchwide);
STBI_EXTERN __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigne=
d int cp, unsigned long flags, const wchar_t *widestr, int cchwide, char *s=
tr, int cbmb, const char *defchar, int *used_default);
#endif

#if defined(_MSC_VER) &amp;&amp; defined(STBI_WINDOWS_UTF8)
STBIDEF int stbi_convert_wchar_to_utf8(char *buffer, size_t bufferlen, cons=
t wchar_t* input)
{
	return WideCharToMultiByte(65001 /* UTF8 */, 0, input, -1, buffer, (int) b=
ufferlen, NULL, NULL);
}
#endif

static FILE *stbi__fopen(char const *filename, char const *mode)
{
   FILE *f;
#if defined(_MSC_VER) &amp;&amp; defined(STBI_WINDOWS_UTF8)
   wchar_t wMode[64];
   wchar_t wFilename[1024];
	if (0 =3D=3D MultiByteToWideChar(65001 /* UTF8 */, 0, filename, -1, wFilen=
ame, sizeof(wFilename)))
      return 0;
=09
	if (0 =3D=3D MultiByteToWideChar(65001 /* UTF8 */, 0, mode, -1, wMode, siz=
eof(wMode)))
      return 0;

#if _MSC_VER &gt;=3D 1400
	if (0 !=3D _wfopen_s(&amp;f, wFilename, wMode))
		f =3D 0;
#else
   f =3D _wfopen(wFilename, wMode);
#endif

#elif defined(_MSC_VER) &amp;&amp; _MSC_VER &gt;=3D 1400
   if (0 !=3D fopen_s(&amp;f, filename, mode))
      f=3D0;
#else
   f =3D fopen(filename, mode);
#endif
   return f;
}


STBIDEF stbi_uc *stbi_load(char const *filename, int *x, int *y, int *comp,=
 int req_comp)
{
   FILE *f =3D stbi__fopen(filename, "rb");
   unsigned char *result;
   if (!f) return stbi__errpuc("can't fopen", "Unable to open file");
   result =3D stbi_load_from_file(f,x,y,comp,req_comp);
   fclose(f);
   return result;
}

STBIDEF stbi_uc *stbi_load_from_file(FILE *f, int *x, int *y, int *comp, in=
t req_comp)
{
   unsigned char *result;
   stbi__context s;
   stbi__start_file(&amp;s,f);
   result =3D stbi__load_and_postprocess_8bit(&amp;s,x,y,comp,req_comp);
   if (result) {
      // need to 'unget' all the characters in the IO buffer
      fseek(f, - (int) (s.img_buffer_end - s.img_buffer), SEEK_CUR);
   }
   return result;
}

STBIDEF stbi__uint16 *stbi_load_from_file_16(FILE *f, int *x, int *y, int *=
comp, int req_comp)
{
   stbi__uint16 *result;
   stbi__context s;
   stbi__start_file(&amp;s,f);
   result =3D stbi__load_and_postprocess_16bit(&amp;s,x,y,comp,req_comp);
   if (result) {
      // need to 'unget' all the characters in the IO buffer
      fseek(f, - (int) (s.img_buffer_end - s.img_buffer), SEEK_CUR);
   }
   return result;
}

STBIDEF stbi_us *stbi_load_16(char const *filename, int *x, int *y, int *co=
mp, int req_comp)
{
   FILE *f =3D stbi__fopen(filename, "rb");
   stbi__uint16 *result;
   if (!f) return (stbi_us *) stbi__errpuc("can't fopen", "Unable to open f=
ile");
   result =3D stbi_load_from_file_16(f,x,y,comp,req_comp);
   fclose(f);
   return result;
}


#endif //!STBI_NO_STDIO

STBIDEF stbi_us *stbi_load_16_from_memory(stbi_uc const *buffer, int len, i=
nt *x, int *y, int *channels_in_file, int desired_channels)
{
   stbi__context s;
   stbi__start_mem(&amp;s,buffer,len);
   return stbi__load_and_postprocess_16bit(&amp;s,x,y,channels_in_file,desi=
red_channels);
}

STBIDEF stbi_us *stbi_load_16_from_callbacks(stbi_io_callbacks const *clbk,=
 void *user, int *x, int *y, int *channels_in_file, int desired_channels)
{
   stbi__context s;
   stbi__start_callbacks(&amp;s, (stbi_io_callbacks *)clbk, user);
   return stbi__load_and_postprocess_16bit(&amp;s,x,y,channels_in_file,desi=
red_channels);
}

STBIDEF stbi_uc *stbi_load_from_memory(stbi_uc const *buffer, int len, int =
*x, int *y, int *comp, int req_comp)
{
   stbi__context s;
   stbi__start_mem(&amp;s,buffer,len);
   return stbi__load_and_postprocess_8bit(&amp;s,x,y,comp,req_comp);
}

STBIDEF stbi_uc *stbi_load_from_callbacks(stbi_io_callbacks const *clbk, vo=
id *user, int *x, int *y, int *comp, int req_comp)
{
   stbi__context s;
   stbi__start_callbacks(&amp;s, (stbi_io_callbacks *) clbk, user);
   return stbi__load_and_postprocess_8bit(&amp;s,x,y,comp,req_comp);
}

#ifndef STBI_NO_GIF
STBIDEF stbi_uc *stbi_load_gif_from_memory(stbi_uc const *buffer, int len, =
int **delays, int *x, int *y, int *z, int *comp, int req_comp)
{
   unsigned char *result;
   stbi__context s;=20
   stbi__start_mem(&amp;s,buffer,len);=20
  =20
   result =3D (unsigned char*) stbi__load_gif_main(&amp;s, delays, x, y, z,=
 comp, req_comp);
   if (stbi__vertically_flip_on_load) {
      stbi__vertical_flip_slices( result, *x, *y, *z, *comp );=20
   }

   return result;=20
}
#endif

#ifndef STBI_NO_LINEAR
static float *stbi__loadf_main(stbi__context *s, int *x, int *y, int *comp,=
 int req_comp)
{
   unsigned char *data;
   #ifndef STBI_NO_HDR
   if (stbi__hdr_test(s)) {
      stbi__result_info ri;
      float *hdr_data =3D stbi__hdr_load(s,x,y,comp,req_comp, &amp;ri);
      if (hdr_data)
         stbi__float_postprocess(hdr_data,x,y,comp,req_comp);
      return hdr_data;
   }
   #endif
   data =3D stbi__load_and_postprocess_8bit(s, x, y, comp, req_comp);
   if (data)
      return stbi__ldr_to_hdr(data, *x, *y, req_comp ? req_comp : *comp);
   return stbi__errpf("unknown image type", "Image not of any known type, o=
r corrupt");
}

STBIDEF float *stbi_loadf_from_memory(stbi_uc const *buffer, int len, int *=
x, int *y, int *comp, int req_comp)
{
   stbi__context s;
   stbi__start_mem(&amp;s,buffer,len);
   return stbi__loadf_main(&amp;s,x,y,comp,req_comp);
}

STBIDEF float *stbi_loadf_from_callbacks(stbi_io_callbacks const *clbk, voi=
d *user, int *x, int *y, int *comp, int req_comp)
{
   stbi__context s;
   stbi__start_callbacks(&amp;s, (stbi_io_callbacks *) clbk, user);
   return stbi__loadf_main(&amp;s,x,y,comp,req_comp);
}

#ifndef STBI_NO_STDIO
STBIDEF float *stbi_loadf(char const *filename, int *x, int *y, int *comp, =
int req_comp)
{
   float *result;
   FILE *f =3D stbi__fopen(filename, "rb");
   if (!f) return stbi__errpf("can't fopen", "Unable to open file");
   result =3D stbi_loadf_from_file(f,x,y,comp,req_comp);
   fclose(f);
   return result;
}

STBIDEF float *stbi_loadf_from_file(FILE *f, int *x, int *y, int *comp, int=
 req_comp)
{
   stbi__context s;
   stbi__start_file(&amp;s,f);
   return stbi__loadf_main(&amp;s,x,y,comp,req_comp);
}
#endif // !STBI_NO_STDIO

#endif // !STBI_NO_LINEAR

// these is-hdr-or-not is defined independent of whether STBI_NO_LINEAR is
// defined, for API simplicity; if STBI_NO_LINEAR is defined, it always
// reports false!

STBIDEF int stbi_is_hdr_from_memory(stbi_uc const *buffer, int len)
{
   #ifndef STBI_NO_HDR
   stbi__context s;
   stbi__start_mem(&amp;s,buffer,len);
   return stbi__hdr_test(&amp;s);
   #else
   STBI_NOTUSED(buffer);
   STBI_NOTUSED(len);
   return 0;
   #endif
}

#ifndef STBI_NO_STDIO
STBIDEF int      stbi_is_hdr          (char const *filename)
{
   FILE *f =3D stbi__fopen(filename, "rb");
   int result=3D0;
   if (f) {
      result =3D stbi_is_hdr_from_file(f);
      fclose(f);
   }
   return result;
}

STBIDEF int stbi_is_hdr_from_file(FILE *f)
{
   #ifndef STBI_NO_HDR
   long pos =3D ftell(f);
   int res;
   stbi__context s;
   stbi__start_file(&amp;s,f);
   res =3D stbi__hdr_test(&amp;s);
   fseek(f, pos, SEEK_SET);
   return res;
   #else
   STBI_NOTUSED(f);
   return 0;
   #endif
}
#endif // !STBI_NO_STDIO

STBIDEF int      stbi_is_hdr_from_callbacks(stbi_io_callbacks const *clbk, =
void *user)
{
   #ifndef STBI_NO_HDR
   stbi__context s;
   stbi__start_callbacks(&amp;s, (stbi_io_callbacks *) clbk, user);
   return stbi__hdr_test(&amp;s);
   #else
   STBI_NOTUSED(clbk);
   STBI_NOTUSED(user);
   return 0;
   #endif
}

#ifndef STBI_NO_LINEAR
static float stbi__l2h_gamma=3D2.2f, stbi__l2h_scale=3D1.0f;

STBIDEF void   stbi_ldr_to_hdr_gamma(float gamma) { stbi__l2h_gamma =3D gam=
ma; }
STBIDEF void   stbi_ldr_to_hdr_scale(float scale) { stbi__l2h_scale =3D sca=
le; }
#endif

static float stbi__h2l_gamma_i=3D1.0f/2.2f, stbi__h2l_scale_i=3D1.0f;

STBIDEF void   stbi_hdr_to_ldr_gamma(float gamma) { stbi__h2l_gamma_i =3D 1=
/gamma; }
STBIDEF void   stbi_hdr_to_ldr_scale(float scale) { stbi__h2l_scale_i =3D 1=
/scale; }


///////////////////////////////////////////////////////////////////////////=
///
//
// Common code used by all image loaders
//

enum
{
   STBI__SCAN_load=3D0,
   STBI__SCAN_type,
   STBI__SCAN_header
};

static void stbi__refill_buffer(stbi__context *s)
{
   int n =3D (s-&gt;io.read)(s-&gt;io_user_data,(char*)s-&gt;buffer_start,s=
-&gt;buflen);
   if (n =3D=3D 0) {
      // at end of file, treat same as if from memory, but need to handle c=
ase
      // where s-&gt;img_buffer isn't pointing to safe memory, e.g. 0-byte =
file
      s-&gt;read_from_callbacks =3D 0;
      s-&gt;img_buffer =3D s-&gt;buffer_start;
      s-&gt;img_buffer_end =3D s-&gt;buffer_start+1;
      *s-&gt;img_buffer =3D 0;
   } else {
      s-&gt;img_buffer =3D s-&gt;buffer_start;
      s-&gt;img_buffer_end =3D s-&gt;buffer_start + n;
   }
}

stbi_inline static stbi_uc stbi__get8(stbi__context *s)
{
   if (s-&gt;img_buffer &lt; s-&gt;img_buffer_end)
      return *s-&gt;img_buffer++;
   if (s-&gt;read_from_callbacks) {
      stbi__refill_buffer(s);
      return *s-&gt;img_buffer++;
   }
   return 0;
}

stbi_inline static int stbi__at_eof(stbi__context *s)
{
   if (s-&gt;io.read) {
      if (!(s-&gt;io.eof)(s-&gt;io_user_data)) return 0;
      // if feof() is true, check if buffer =3D end
      // special case: we've only got the special 0 character at the end
      if (s-&gt;read_from_callbacks =3D=3D 0) return 1;
   }

   return s-&gt;img_buffer &gt;=3D s-&gt;img_buffer_end;
}

static void stbi__skip(stbi__context *s, int n)
{
   if (n &lt; 0) {
      s-&gt;img_buffer =3D s-&gt;img_buffer_end;
      return;
   }
   if (s-&gt;io.read) {
      int blen =3D (int) (s-&gt;img_buffer_end - s-&gt;img_buffer);
      if (blen &lt; n) {
         s-&gt;img_buffer =3D s-&gt;img_buffer_end;
         (s-&gt;io.skip)(s-&gt;io_user_data, n - blen);
         return;
      }
   }
   s-&gt;img_buffer +=3D n;
}

static int stbi__getn(stbi__context *s, stbi_uc *buffer, int n)
{
   if (s-&gt;io.read) {
      int blen =3D (int) (s-&gt;img_buffer_end - s-&gt;img_buffer);
      if (blen &lt; n) {
         int res, count;

         memcpy(buffer, s-&gt;img_buffer, blen);

         count =3D (s-&gt;io.read)(s-&gt;io_user_data, (char*) buffer + ble=
n, n - blen);
         res =3D (count =3D=3D (n-blen));
         s-&gt;img_buffer =3D s-&gt;img_buffer_end;
         return res;
      }
   }

   if (s-&gt;img_buffer+n &lt;=3D s-&gt;img_buffer_end) {
      memcpy(buffer, s-&gt;img_buffer, n);
      s-&gt;img_buffer +=3D n;
      return 1;
   } else
      return 0;
}

static int stbi__get16be(stbi__context *s)
{
   int z =3D stbi__get8(s);
   return (z &lt;&lt; 8) + stbi__get8(s);
}

static stbi__uint32 stbi__get32be(stbi__context *s)
{
   stbi__uint32 z =3D stbi__get16be(s);
   return (z &lt;&lt; 16) + stbi__get16be(s);
}

#if defined(STBI_NO_BMP) &amp;&amp; defined(STBI_NO_TGA) &amp;&amp; defined=
(STBI_NO_GIF)
// nothing
#else
static int stbi__get16le(stbi__context *s)
{
   int z =3D stbi__get8(s);
   return z + (stbi__get8(s) &lt;&lt; 8);
}
#endif

#ifndef STBI_NO_BMP
static stbi__uint32 stbi__get32le(stbi__context *s)
{
   stbi__uint32 z =3D stbi__get16le(s);
   return z + (stbi__get16le(s) &lt;&lt; 16);
}
#endif

#define STBI__BYTECAST(x)  ((stbi_uc) ((x) &amp; 255))  // truncate int to =
byte without warnings


///////////////////////////////////////////////////////////////////////////=
///
//
//  generic converter from built-in img_n to req_comp
//    individual types do this automatically as much as possible (e.g. jpeg
//    does all cases internally since it needs to colorspace convert anyway=
,
//    and it never has alpha, so very few cases ). png can automatically
//    interleave an alpha=3D255 channel, but falls back to this for other c=
ases
//
//  assume data buffer is malloced, so malloc a new one and free that one
//  only failure mode is malloc failing

static stbi_uc stbi__compute_y(int r, int g, int b)
{
   return (stbi_uc) (((r*77) + (g*150) +  (29*b)) &gt;&gt; 8);
}

static unsigned char *stbi__convert_format(unsigned char *data, int img_n, =
int req_comp, unsigned int x, unsigned int y)
{
   int i,j;
   unsigned char *good;

   if (req_comp =3D=3D img_n) return data;
   STBI_ASSERT(req_comp &gt;=3D 1 &amp;&amp; req_comp &lt;=3D 4);

   good =3D (unsigned char *) stbi__malloc_mad3(req_comp, x, y, 0);
   if (good =3D=3D NULL) {
      STBI_FREE(data);
      return stbi__errpuc("outofmem", "Out of memory");
   }

   for (j=3D0; j &lt; (int) y; ++j) {
      unsigned char *src  =3D data + j * x * img_n   ;
      unsigned char *dest =3D good + j * x * req_comp;

      #define STBI__COMBO(a,b)  ((a)*8+(b))
      #define STBI__CASE(a,b)   case STBI__COMBO(a,b): for(i=3Dx-1; i &gt;=
=3D 0; --i, src +=3D a, dest +=3D b)
      // convert source image with img_n components to one with req_comp co=
mponents;
      // avoid switch per pixel, so use switch per scanline and massive mac=
ros
      switch (STBI__COMBO(img_n, req_comp)) {
         STBI__CASE(1,2) { dest[0]=3Dsrc[0]; dest[1]=3D255;                =
                     } break;
         STBI__CASE(1,3) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0];           =
                       } break;
         STBI__CASE(1,4) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0]; dest[3]=3D=
255;                     } break;
         STBI__CASE(2,1) { dest[0]=3Dsrc[0];                               =
                   } break;
         STBI__CASE(2,3) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0];           =
                       } break;
         STBI__CASE(2,4) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0]; dest[3]=3D=
src[1];                  } break;
         STBI__CASE(3,4) { dest[0]=3Dsrc[0];dest[1]=3Dsrc[1];dest[2]=3Dsrc[=
2];dest[3]=3D255;        } break;
         STBI__CASE(3,1) { dest[0]=3Dstbi__compute_y(src[0],src[1],src[2]);=
                   } break;
         STBI__CASE(3,2) { dest[0]=3Dstbi__compute_y(src[0],src[1],src[2]);=
 dest[1] =3D 255;    } break;
         STBI__CASE(4,1) { dest[0]=3Dstbi__compute_y(src[0],src[1],src[2]);=
                   } break;
         STBI__CASE(4,2) { dest[0]=3Dstbi__compute_y(src[0],src[1],src[2]);=
 dest[1] =3D src[3]; } break;
         STBI__CASE(4,3) { dest[0]=3Dsrc[0];dest[1]=3Dsrc[1];dest[2]=3Dsrc[=
2];                    } break;
         default: STBI_ASSERT(0);
      }
      #undef STBI__CASE
   }

   STBI_FREE(data);
   return good;
}

static stbi__uint16 stbi__compute_y_16(int r, int g, int b)
{
   return (stbi__uint16) (((r*77) + (g*150) +  (29*b)) &gt;&gt; 8);
}

static stbi__uint16 *stbi__convert_format16(stbi__uint16 *data, int img_n, =
int req_comp, unsigned int x, unsigned int y)
{
   int i,j;
   stbi__uint16 *good;

   if (req_comp =3D=3D img_n) return data;
   STBI_ASSERT(req_comp &gt;=3D 1 &amp;&amp; req_comp &lt;=3D 4);

   good =3D (stbi__uint16 *) stbi__malloc(req_comp * x * y * 2);
   if (good =3D=3D NULL) {
      STBI_FREE(data);
      return (stbi__uint16 *) stbi__errpuc("outofmem", "Out of memory");
   }

   for (j=3D0; j &lt; (int) y; ++j) {
      stbi__uint16 *src  =3D data + j * x * img_n   ;
      stbi__uint16 *dest =3D good + j * x * req_comp;

      #define STBI__COMBO(a,b)  ((a)*8+(b))
      #define STBI__CASE(a,b)   case STBI__COMBO(a,b): for(i=3Dx-1; i &gt;=
=3D 0; --i, src +=3D a, dest +=3D b)
      // convert source image with img_n components to one with req_comp co=
mponents;
      // avoid switch per pixel, so use switch per scanline and massive mac=
ros
      switch (STBI__COMBO(img_n, req_comp)) {
         STBI__CASE(1,2) { dest[0]=3Dsrc[0]; dest[1]=3D0xffff;             =
                        } break;
         STBI__CASE(1,3) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0];           =
                          } break;
         STBI__CASE(1,4) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0]; dest[3]=3D=
0xffff;                     } break;
         STBI__CASE(2,1) { dest[0]=3Dsrc[0];                               =
                      } break;
         STBI__CASE(2,3) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0];           =
                          } break;
         STBI__CASE(2,4) { dest[0]=3Ddest[1]=3Ddest[2]=3Dsrc[0]; dest[3]=3D=
src[1];                     } break;
         STBI__CASE(3,4) { dest[0]=3Dsrc[0];dest[1]=3Dsrc[1];dest[2]=3Dsrc[=
2];dest[3]=3D0xffff;        } break;
         STBI__CASE(3,1) { dest[0]=3Dstbi__compute_y_16(src[0],src[1],src[2=
]);                   } break;
         STBI__CASE(3,2) { dest[0]=3Dstbi__compute_y_16(src[0],src[1],src[2=
]); dest[1] =3D 0xffff; } break;
         STBI__CASE(4,1) { dest[0]=3Dstbi__compute_y_16(src[0],src[1],src[2=
]);                   } break;
         STBI__CASE(4,2) { dest[0]=3Dstbi__compute_y_16(src[0],src[1],src[2=
]); dest[1] =3D src[3]; } break;
         STBI__CASE(4,3) { dest[0]=3Dsrc[0];dest[1]=3Dsrc[1];dest[2]=3Dsrc[=
2];                       } break;
         default: STBI_ASSERT(0);
      }
      #undef STBI__CASE
   }

   STBI_FREE(data);
   return good;
}

#ifndef STBI_NO_LINEAR
static float   *stbi__ldr_to_hdr(stbi_uc *data, int x, int y, int comp)
{
   int i,k,n;
   float *output;
   if (!data) return NULL;
   output =3D (float *) stbi__malloc_mad4(x, y, comp, sizeof(float), 0);
   if (output =3D=3D NULL) { STBI_FREE(data); return stbi__errpf("outofmem"=
, "Out of memory"); }
   // compute number of non-alpha components
   if (comp &amp; 1) n =3D comp; else n =3D comp-1;
   for (i=3D0; i &lt; x*y; ++i) {
      for (k=3D0; k &lt; n; ++k) {
         output[i*comp + k] =3D (float) (pow(data[i*comp+k]/255.0f, stbi__l=
2h_gamma) * stbi__l2h_scale);
      }
   }
   if (n &lt; comp) {
      for (i=3D0; i &lt; x*y; ++i) {
         output[i*comp + n] =3D data[i*comp + n]/255.0f;
      }
   }
   STBI_FREE(data);
   return output;
}
#endif

#ifndef STBI_NO_HDR
#define stbi__float2int(x)   ((int) (x))
static stbi_uc *stbi__hdr_to_ldr(float   *data, int x, int y, int comp)
{
   int i,k,n;
   stbi_uc *output;
   if (!data) return NULL;
   output =3D (stbi_uc *) stbi__malloc_mad3(x, y, comp, 0);
   if (output =3D=3D NULL) { STBI_FREE(data); return stbi__errpuc("outofmem=
", "Out of memory"); }
   // compute number of non-alpha components
   if (comp &amp; 1) n =3D comp; else n =3D comp-1;
   for (i=3D0; i &lt; x*y; ++i) {
      for (k=3D0; k &lt; n; ++k) {
         float z =3D (float) pow(data[i*comp+k]*stbi__h2l_scale_i, stbi__h2=
l_gamma_i) * 255 + 0.5f;
         if (z &lt; 0) z =3D 0;
         if (z &gt; 255) z =3D 255;
         output[i*comp + k] =3D (stbi_uc) stbi__float2int(z);
      }
      if (k &lt; comp) {
         float z =3D data[i*comp+k] * 255 + 0.5f;
         if (z &lt; 0) z =3D 0;
         if (z &gt; 255) z =3D 255;
         output[i*comp + k] =3D (stbi_uc) stbi__float2int(z);
      }
   }
   STBI_FREE(data);
   return output;
}
#endif

///////////////////////////////////////////////////////////////////////////=
///
//
//  "baseline" JPEG/JFIF decoder
//
//    simple implementation
//      - doesn't support delayed output of y-dimension
//      - simple interface (only one output format: 8-bit interleaved RGB)
//      - doesn't try to recover corrupt jpegs
//      - doesn't allow partial loading, loading multiple at once
//      - still fast on x86 (copying globals into locals doesn't help x86)
//      - allocates lots of intermediate memory (full size of all component=
s)
//        - non-interleaved case requires this anyway
//        - allows good upsampling (see next)
//    high-quality
//      - upsampled channels are bilinearly interpolated, even across block=
s
//      - quality integer IDCT derived from IJG's 'slow'
//    performance
//      - fast huffman; reasonable integer IDCT
//      - some SIMD kernels for common paths on targets with SSE2/NEON
//      - uses a lot of intermediate memory, could cache poorly

#ifndef STBI_NO_JPEG

// huffman decoding acceleration
#define FAST_BITS   9  // larger handles more cases; smaller stomps less ca=
che

typedef struct
{
   stbi_uc  fast[1 &lt;&lt; FAST_BITS];
   // weirdly, repacking this into AoS is a 10% speed loss, instead of a wi=
n
   stbi__uint16 code[256];
   stbi_uc  values[256];
   stbi_uc  size[257];
   unsigned int maxcode[18];
   int    delta[17];   // old 'firstsymbol' - old 'firstcode'
} stbi__huffman;

typedef struct
{
   stbi__context *s;
   stbi__huffman huff_dc[4];
   stbi__huffman huff_ac[4];
   stbi__uint16 dequant[4][64];
   stbi__int16 fast_ac[4][1 &lt;&lt; FAST_BITS];

// sizes for components, interleaved MCUs
   int img_h_max, img_v_max;
   int img_mcu_x, img_mcu_y;
   int img_mcu_w, img_mcu_h;

// definition of jpeg image component
   struct
   {
      int id;
      int h,v;
      int tq;
      int hd,ha;
      int dc_pred;

      int x,y,w2,h2;
      stbi_uc *data;
      void *raw_data, *raw_coeff;
      stbi_uc *linebuf;
      short   *coeff;   // progressive only
      int      coeff_w, coeff_h; // number of 8x8 coefficient blocks
   } img_comp[4];

   stbi__uint32   code_buffer; // jpeg entropy-coded buffer
   int            code_bits;   // number of valid bits
   unsigned char  marker;      // marker seen while filling entropy buffer
   int            nomore;      // flag if we saw a marker so must stop

   int            progressive;
   int            spec_start;
   int            spec_end;
   int            succ_high;
   int            succ_low;
   int            eob_run;
   int            jfif;
   int            app14_color_transform; // Adobe APP14 tag
   int            rgb;

   int scan_n, order[4];
   int restart_interval, todo;

// kernels
   void (*idct_block_kernel)(stbi_uc *out, int out_stride, short data[64]);
   void (*YCbCr_to_RGB_kernel)(stbi_uc *out, const stbi_uc *y, const stbi_u=
c *pcb, const stbi_uc *pcr, int count, int step);
   stbi_uc *(*resample_row_hv_2_kernel)(stbi_uc *out, stbi_uc *in_near, stb=
i_uc *in_far, int w, int hs);
} stbi__jpeg;

static int stbi__build_huffman(stbi__huffman *h, int *count)
{
   int i,j,k=3D0;
   unsigned int code;
   // build size list for each symbol (from JPEG spec)
   for (i=3D0; i &lt; 16; ++i)
      for (j=3D0; j &lt; count[i]; ++j)
         h-&gt;size[k++] =3D (stbi_uc) (i+1);
   h-&gt;size[k] =3D 0;

   // compute actual symbols (from jpeg spec)
   code =3D 0;
   k =3D 0;
   for(j=3D1; j &lt;=3D 16; ++j) {
      // compute delta to add to code to compute symbol id
      h-&gt;delta[j] =3D k - code;
      if (h-&gt;size[k] =3D=3D j) {
         while (h-&gt;size[k] =3D=3D j)
            h-&gt;code[k++] =3D (stbi__uint16) (code++);
         if (code-1 &gt;=3D (1u &lt;&lt; j)) return stbi__err("bad code len=
gths","Corrupt JPEG");
      }
      // compute largest code + 1 for this size, preshifted as needed later
      h-&gt;maxcode[j] =3D code &lt;&lt; (16-j);
      code &lt;&lt;=3D 1;
   }
   h-&gt;maxcode[j] =3D 0xffffffff;

   // build non-spec acceleration table; 255 is flag for not-accelerated
   memset(h-&gt;fast, 255, 1 &lt;&lt; FAST_BITS);
   for (i=3D0; i &lt; k; ++i) {
      int s =3D h-&gt;size[i];
      if (s &lt;=3D FAST_BITS) {
         int c =3D h-&gt;code[i] &lt;&lt; (FAST_BITS-s);
         int m =3D 1 &lt;&lt; (FAST_BITS-s);
         for (j=3D0; j &lt; m; ++j) {
            h-&gt;fast[c+j] =3D (stbi_uc) i;
         }
      }
   }
   return 1;
}

// build a table that decodes both magnitude and value of small ACs in
// one go.
static void stbi__build_fast_ac(stbi__int16 *fast_ac, stbi__huffman *h)
{
   int i;
   for (i=3D0; i &lt; (1 &lt;&lt; FAST_BITS); ++i) {
      stbi_uc fast =3D h-&gt;fast[i];
      fast_ac[i] =3D 0;
      if (fast &lt; 255) {
         int rs =3D h-&gt;values[fast];
         int run =3D (rs &gt;&gt; 4) &amp; 15;
         int magbits =3D rs &amp; 15;
         int len =3D h-&gt;size[fast];

         if (magbits &amp;&amp; len + magbits &lt;=3D FAST_BITS) {
            // magnitude code followed by receive_extend code
            int k =3D ((i &lt;&lt; len) &amp; ((1 &lt;&lt; FAST_BITS) - 1))=
 &gt;&gt; (FAST_BITS - magbits);
            int m =3D 1 &lt;&lt; (magbits - 1);
            if (k &lt; m) k +=3D (~0U &lt;&lt; magbits) + 1;
            // if the result is small enough, we can fit it in fast_ac tabl=
e
            if (k &gt;=3D -128 &amp;&amp; k &lt;=3D 127)
               fast_ac[i] =3D (stbi__int16) ((k * 256) + (run * 16) + (len =
+ magbits));
         }
      }
   }
}

static void stbi__grow_buffer_unsafe(stbi__jpeg *j)
{
   do {
      unsigned int b =3D j-&gt;nomore ? 0 : stbi__get8(j-&gt;s);
      if (b =3D=3D 0xff) {
         int c =3D stbi__get8(j-&gt;s);
         while (c =3D=3D 0xff) c =3D stbi__get8(j-&gt;s); // consume fill b=
ytes
         if (c !=3D 0) {
            j-&gt;marker =3D (unsigned char) c;
            j-&gt;nomore =3D 1;
            return;
         }
      }
      j-&gt;code_buffer |=3D b &lt;&lt; (24 - j-&gt;code_bits);
      j-&gt;code_bits +=3D 8;
   } while (j-&gt;code_bits &lt;=3D 24);
}

// (1 &lt;&lt; n) - 1
static const stbi__uint32 stbi__bmask[17]=3D{0,1,3,7,15,31,63,127,255,511,1=
023,2047,4095,8191,16383,32767,65535};

// decode a jpeg huffman value from the bitstream
stbi_inline static int stbi__jpeg_huff_decode(stbi__jpeg *j, stbi__huffman =
*h)
{
   unsigned int temp;
   int c,k;

   if (j-&gt;code_bits &lt; 16) stbi__grow_buffer_unsafe(j);

   // look at the top FAST_BITS and determine what symbol ID it is,
   // if the code is &lt;=3D FAST_BITS
   c =3D (j-&gt;code_buffer &gt;&gt; (32 - FAST_BITS)) &amp; ((1 &lt;&lt; F=
AST_BITS)-1);
   k =3D h-&gt;fast[c];
   if (k &lt; 255) {
      int s =3D h-&gt;size[k];
      if (s &gt; j-&gt;code_bits)
         return -1;
      j-&gt;code_buffer &lt;&lt;=3D s;
      j-&gt;code_bits -=3D s;
      return h-&gt;values[k];
   }

   // naive test is to shift the code_buffer down so k bits are
   // valid, then test against maxcode. To speed this up, we've
   // preshifted maxcode left so that it has (16-k) 0s at the
   // end; in other words, regardless of the number of bits, it
   // wants to be compared against something shifted to have 16;
   // that way we don't need to shift inside the loop.
   temp =3D j-&gt;code_buffer &gt;&gt; 16;
   for (k=3DFAST_BITS+1 ; ; ++k)
      if (temp &lt; h-&gt;maxcode[k])
         break;
   if (k =3D=3D 17) {
      // error! code not found
      j-&gt;code_bits -=3D 16;
      return -1;
   }

   if (k &gt; j-&gt;code_bits)
      return -1;

   // convert the huffman code to the symbol id
   c =3D ((j-&gt;code_buffer &gt;&gt; (32 - k)) &amp; stbi__bmask[k]) + h-&=
gt;delta[k];
   STBI_ASSERT((((j-&gt;code_buffer) &gt;&gt; (32 - h-&gt;size[c])) &amp; s=
tbi__bmask[h-&gt;size[c]]) =3D=3D h-&gt;code[c]);

   // convert the id to a symbol
   j-&gt;code_bits -=3D k;
   j-&gt;code_buffer &lt;&lt;=3D k;
   return h-&gt;values[c];
}

// bias[n] =3D (-1&lt;&lt;n) + 1
static const int stbi__jbias[16] =3D {0,-1,-3,-7,-15,-31,-63,-127,-255,-511=
,-1023,-2047,-4095,-8191,-16383,-32767};

// combined JPEG 'receive' and JPEG 'extend', since baseline
// always extends everything it receives.
stbi_inline static int stbi__extend_receive(stbi__jpeg *j, int n)
{
   unsigned int k;
   int sgn;
   if (j-&gt;code_bits &lt; n) stbi__grow_buffer_unsafe(j);

   sgn =3D (stbi__int32)j-&gt;code_buffer &gt;&gt; 31; // sign bit is alway=
s in MSB
   k =3D stbi_lrot(j-&gt;code_buffer, n);
   STBI_ASSERT(n &gt;=3D 0 &amp;&amp; n &lt; (int) (sizeof(stbi__bmask)/siz=
eof(*stbi__bmask)));
   j-&gt;code_buffer =3D k &amp; ~stbi__bmask[n];
   k &amp;=3D stbi__bmask[n];
   j-&gt;code_bits -=3D n;
   return k + (stbi__jbias[n] &amp; ~sgn);
}

// get some unsigned bits
stbi_inline static int stbi__jpeg_get_bits(stbi__jpeg *j, int n)
{
   unsigned int k;
   if (j-&gt;code_bits &lt; n) stbi__grow_buffer_unsafe(j);
   k =3D stbi_lrot(j-&gt;code_buffer, n);
   j-&gt;code_buffer =3D k &amp; ~stbi__bmask[n];
   k &amp;=3D stbi__bmask[n];
   j-&gt;code_bits -=3D n;
   return k;
}

stbi_inline static int stbi__jpeg_get_bit(stbi__jpeg *j)
{
   unsigned int k;
   if (j-&gt;code_bits &lt; 1) stbi__grow_buffer_unsafe(j);
   k =3D j-&gt;code_buffer;
   j-&gt;code_buffer &lt;&lt;=3D 1;
   --j-&gt;code_bits;
   return k &amp; 0x80000000;
}

// given a value that's at position X in the zigzag stream,
// where does it appear in the 8x8 matrix coded as row-major?
static const stbi_uc stbi__jpeg_dezigzag[64+15] =3D
{
    0,  1,  8, 16,  9,  2,  3, 10,
   17, 24, 32, 25, 18, 11,  4,  5,
   12, 19, 26, 33, 40, 48, 41, 34,
   27, 20, 13,  6,  7, 14, 21, 28,
   35, 42, 49, 56, 57, 50, 43, 36,
   29, 22, 15, 23, 30, 37, 44, 51,
   58, 59, 52, 45, 38, 31, 39, 46,
   53, 60, 61, 54, 47, 55, 62, 63,
   // let corrupt input sample past end
   63, 63, 63, 63, 63, 63, 63, 63,
   63, 63, 63, 63, 63, 63, 63
};

// decode one 64-entry block--
static int stbi__jpeg_decode_block(stbi__jpeg *j, short data[64], stbi__huf=
fman *hdc, stbi__huffman *hac, stbi__int16 *fac, int b, stbi__uint16 *dequa=
nt)
{
   int diff,dc,k;
   int t;

   if (j-&gt;code_bits &lt; 16) stbi__grow_buffer_unsafe(j);
   t =3D stbi__jpeg_huff_decode(j, hdc);
   if (t &lt; 0) return stbi__err("bad huffman code","Corrupt JPEG");

   // 0 all the ac values now so we can do it 32-bits at a time
   memset(data,0,64*sizeof(data[0]));

   diff =3D t ? stbi__extend_receive(j, t) : 0;
   dc =3D j-&gt;img_comp[b].dc_pred + diff;
   j-&gt;img_comp[b].dc_pred =3D dc;
   data[0] =3D (short) (dc * dequant[0]);

   // decode AC components, see JPEG spec
   k =3D 1;
   do {
      unsigned int zig;
      int c,r,s;
      if (j-&gt;code_bits &lt; 16) stbi__grow_buffer_unsafe(j);
      c =3D (j-&gt;code_buffer &gt;&gt; (32 - FAST_BITS)) &amp; ((1 &lt;&lt=
; FAST_BITS)-1);
      r =3D fac[c];
      if (r) { // fast-AC path
         k +=3D (r &gt;&gt; 4) &amp; 15; // run
         s =3D r &amp; 15; // combined length
         j-&gt;code_buffer &lt;&lt;=3D s;
         j-&gt;code_bits -=3D s;
         // decode into unzigzag'd location
         zig =3D stbi__jpeg_dezigzag[k++];
         data[zig] =3D (short) ((r &gt;&gt; 8) * dequant[zig]);
      } else {
         int rs =3D stbi__jpeg_huff_decode(j, hac);
         if (rs &lt; 0) return stbi__err("bad huffman code","Corrupt JPEG")=
;
         s =3D rs &amp; 15;
         r =3D rs &gt;&gt; 4;
         if (s =3D=3D 0) {
            if (rs !=3D 0xf0) break; // end block
            k +=3D 16;
         } else {
            k +=3D r;
            // decode into unzigzag'd location
            zig =3D stbi__jpeg_dezigzag[k++];
            data[zig] =3D (short) (stbi__extend_receive(j,s) * dequant[zig]=
);
         }
      }
   } while (k &lt; 64);
   return 1;
}

static int stbi__jpeg_decode_block_prog_dc(stbi__jpeg *j, short data[64], s=
tbi__huffman *hdc, int b)
{
   int diff,dc;
   int t;
   if (j-&gt;spec_end !=3D 0) return stbi__err("can't merge dc and ac", "Co=
rrupt JPEG");

   if (j-&gt;code_bits &lt; 16) stbi__grow_buffer_unsafe(j);

   if (j-&gt;succ_high =3D=3D 0) {
      // first scan for DC coefficient, must be first
      memset(data,0,64*sizeof(data[0])); // 0 all the ac values now
      t =3D stbi__jpeg_huff_decode(j, hdc);
      diff =3D t ? stbi__extend_receive(j, t) : 0;

      dc =3D j-&gt;img_comp[b].dc_pred + diff;
      j-&gt;img_comp[b].dc_pred =3D dc;
      data[0] =3D (short) (dc &lt;&lt; j-&gt;succ_low);
   } else {
      // refinement scan for DC coefficient
      if (stbi__jpeg_get_bit(j))
         data[0] +=3D (short) (1 &lt;&lt; j-&gt;succ_low);
   }
   return 1;
}

// @OPTIMIZE: store non-zigzagged during the decode passes,
// and only de-zigzag when dequantizing
static int stbi__jpeg_decode_block_prog_ac(stbi__jpeg *j, short data[64], s=
tbi__huffman *hac, stbi__int16 *fac)
{
   int k;
   if (j-&gt;spec_start =3D=3D 0) return stbi__err("can't merge dc and ac",=
 "Corrupt JPEG");

   if (j-&gt;succ_high =3D=3D 0) {
      int shift =3D j-&gt;succ_low;

      if (j-&gt;eob_run) {
         --j-&gt;eob_run;
         return 1;
      }

      k =3D j-&gt;spec_start;
      do {
         unsigned int zig;
         int c,r,s;
         if (j-&gt;code_bits &lt; 16) stbi__grow_buffer_unsafe(j);
         c =3D (j-&gt;code_buffer &gt;&gt; (32 - FAST_BITS)) &amp; ((1 &lt;=
&lt; FAST_BITS)-1);
         r =3D fac[c];
         if (r) { // fast-AC path
            k +=3D (r &gt;&gt; 4) &amp; 15; // run
            s =3D r &amp; 15; // combined length
            j-&gt;code_buffer &lt;&lt;=3D s;
            j-&gt;code_bits -=3D s;
            zig =3D stbi__jpeg_dezigzag[k++];
            data[zig] =3D (short) ((r &gt;&gt; 8) &lt;&lt; shift);
         } else {
            int rs =3D stbi__jpeg_huff_decode(j, hac);
            if (rs &lt; 0) return stbi__err("bad huffman code","Corrupt JPE=
G");
            s =3D rs &amp; 15;
            r =3D rs &gt;&gt; 4;
            if (s =3D=3D 0) {
               if (r &lt; 15) {
                  j-&gt;eob_run =3D (1 &lt;&lt; r);
                  if (r)
                     j-&gt;eob_run +=3D stbi__jpeg_get_bits(j, r);
                  --j-&gt;eob_run;
                  break;
               }
               k +=3D 16;
            } else {
               k +=3D r;
               zig =3D stbi__jpeg_dezigzag[k++];
               data[zig] =3D (short) (stbi__extend_receive(j,s) &lt;&lt; sh=
ift);
            }
         }
      } while (k &lt;=3D j-&gt;spec_end);
   } else {
      // refinement scan for these AC coefficients

      short bit =3D (short) (1 &lt;&lt; j-&gt;succ_low);

      if (j-&gt;eob_run) {
         --j-&gt;eob_run;
         for (k =3D j-&gt;spec_start; k &lt;=3D j-&gt;spec_end; ++k) {
            short *p =3D &amp;data[stbi__jpeg_dezigzag[k]];
            if (*p !=3D 0)
               if (stbi__jpeg_get_bit(j))
                  if ((*p &amp; bit)=3D=3D0) {
                     if (*p &gt; 0)
                        *p +=3D bit;
                     else
                        *p -=3D bit;
                  }
         }
      } else {
         k =3D j-&gt;spec_start;
         do {
            int r,s;
            int rs =3D stbi__jpeg_huff_decode(j, hac); // @OPTIMIZE see if =
we can use the fast path here, advance-by-r is so slow, eh
            if (rs &lt; 0) return stbi__err("bad huffman code","Corrupt JPE=
G");
            s =3D rs &amp; 15;
            r =3D rs &gt;&gt; 4;
            if (s =3D=3D 0) {
               if (r &lt; 15) {
                  j-&gt;eob_run =3D (1 &lt;&lt; r) - 1;
                  if (r)
                     j-&gt;eob_run +=3D stbi__jpeg_get_bits(j, r);
                  r =3D 64; // force end of block
               } else {
                  // r=3D15 s=3D0 should write 16 0s, so we just do
                  // a run of 15 0s and then write s (which is 0),
                  // so we don't have to do anything special here
               }
            } else {
               if (s !=3D 1) return stbi__err("bad huffman code", "Corrupt =
JPEG");
               // sign bit
               if (stbi__jpeg_get_bit(j))
                  s =3D bit;
               else
                  s =3D -bit;
            }

            // advance by r
            while (k &lt;=3D j-&gt;spec_end) {
               short *p =3D &amp;data[stbi__jpeg_dezigzag[k++]];
               if (*p !=3D 0) {
                  if (stbi__jpeg_get_bit(j))
                     if ((*p &amp; bit)=3D=3D0) {
                        if (*p &gt; 0)
                           *p +=3D bit;
                        else
                           *p -=3D bit;
                     }
               } else {
                  if (r =3D=3D 0) {
                     *p =3D (short) s;
                     break;
                  }
                  --r;
               }
            }
         } while (k &lt;=3D j-&gt;spec_end);
      }
   }
   return 1;
}

// take a -128..127 value and stbi__clamp it and convert to 0..255
stbi_inline static stbi_uc stbi__clamp(int x)
{
   // trick to use a single test to catch both cases
   if ((unsigned int) x &gt; 255) {
      if (x &lt; 0) return 0;
      if (x &gt; 255) return 255;
   }
   return (stbi_uc) x;
}

#define stbi__f2f(x)  ((int) (((x) * 4096 + 0.5)))
#define stbi__fsh(x)  ((x) * 4096)

// derived from jidctint -- DCT_ISLOW
#define STBI__IDCT_1D(s0,s1,s2,s3,s4,s5,s6,s7) \
   int t0,t1,t2,t3,p1,p2,p3,p4,p5,x0,x1,x2,x3; \
   p2 =3D s2;                                    \
   p3 =3D s6;                                    \
   p1 =3D (p2+p3) * stbi__f2f(0.5411961f);       \
   t2 =3D p1 + p3*stbi__f2f(-1.847759065f);      \
   t3 =3D p1 + p2*stbi__f2f( 0.765366865f);      \
   p2 =3D s0;                                    \
   p3 =3D s4;                                    \
   t0 =3D stbi__fsh(p2+p3);                      \
   t1 =3D stbi__fsh(p2-p3);                      \
   x0 =3D t0+t3;                                 \
   x3 =3D t0-t3;                                 \
   x1 =3D t1+t2;                                 \
   x2 =3D t1-t2;                                 \
   t0 =3D s7;                                    \
   t1 =3D s5;                                    \
   t2 =3D s3;                                    \
   t3 =3D s1;                                    \
   p3 =3D t0+t2;                                 \
   p4 =3D t1+t3;                                 \
   p1 =3D t0+t3;                                 \
   p2 =3D t1+t2;                                 \
   p5 =3D (p3+p4)*stbi__f2f( 1.175875602f);      \
   t0 =3D t0*stbi__f2f( 0.298631336f);           \
   t1 =3D t1*stbi__f2f( 2.053119869f);           \
   t2 =3D t2*stbi__f2f( 3.072711026f);           \
   t3 =3D t3*stbi__f2f( 1.501321110f);           \
   p1 =3D p5 + p1*stbi__f2f(-0.899976223f);      \
   p2 =3D p5 + p2*stbi__f2f(-2.562915447f);      \
   p3 =3D p3*stbi__f2f(-1.961570560f);           \
   p4 =3D p4*stbi__f2f(-0.390180644f);           \
   t3 +=3D p1+p4;                                \
   t2 +=3D p2+p3;                                \
   t1 +=3D p2+p4;                                \
   t0 +=3D p1+p3;

static void stbi__idct_block(stbi_uc *out, int out_stride, short data[64])
{
   int i,val[64],*v=3Dval;
   stbi_uc *o;
   short *d =3D data;

   // columns
   for (i=3D0; i &lt; 8; ++i,++d, ++v) {
      // if all zeroes, shortcut -- this avoids dequantizing 0s and IDCTing
      if (d[ 8]=3D=3D0 &amp;&amp; d[16]=3D=3D0 &amp;&amp; d[24]=3D=3D0 &amp=
;&amp; d[32]=3D=3D0
           &amp;&amp; d[40]=3D=3D0 &amp;&amp; d[48]=3D=3D0 &amp;&amp; d[56]=
=3D=3D0) {
         //    no shortcut                 0     seconds
         //    (1|2|3|4|5|6|7)=3D=3D0          0     seconds
         //    all separate               -0.047 seconds
         //    1 &amp;&amp; 2|3 &amp;&amp; 4|5 &amp;&amp; 6|7:    -0.047 se=
conds
         int dcterm =3D d[0]*4;
         v[0] =3D v[8] =3D v[16] =3D v[24] =3D v[32] =3D v[40] =3D v[48] =
=3D v[56] =3D dcterm;
      } else {
         STBI__IDCT_1D(d[ 0],d[ 8],d[16],d[24],d[32],d[40],d[48],d[56])
         // constants scaled things up by 1&lt;&lt;12; let's bring them bac=
k
         // down, but keep 2 extra bits of precision
         x0 +=3D 512; x1 +=3D 512; x2 +=3D 512; x3 +=3D 512;
         v[ 0] =3D (x0+t3) &gt;&gt; 10;
         v[56] =3D (x0-t3) &gt;&gt; 10;
         v[ 8] =3D (x1+t2) &gt;&gt; 10;
         v[48] =3D (x1-t2) &gt;&gt; 10;
         v[16] =3D (x2+t1) &gt;&gt; 10;
         v[40] =3D (x2-t1) &gt;&gt; 10;
         v[24] =3D (x3+t0) &gt;&gt; 10;
         v[32] =3D (x3-t0) &gt;&gt; 10;
      }
   }

   for (i=3D0, v=3Dval, o=3Dout; i &lt; 8; ++i,v+=3D8,o+=3Dout_stride) {
      // no fast case since the first 1D IDCT spread components out
      STBI__IDCT_1D(v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7])
      // constants scaled things up by 1&lt;&lt;12, plus we had 1&lt;&lt;2 =
from first
      // loop, plus horizontal and vertical each scale by sqrt(8) so togeth=
er
      // we've got an extra 1&lt;&lt;3, so 1&lt;&lt;17 total we need to rem=
ove.
      // so we want to round that, which means adding 0.5 * 1&lt;&lt;17,
      // aka 65536. Also, we'll end up with -128 to 127 that we want
      // to encode as 0..255 by adding 128, so we'll add that before the sh=
ift
      x0 +=3D 65536 + (128&lt;&lt;17);
      x1 +=3D 65536 + (128&lt;&lt;17);
      x2 +=3D 65536 + (128&lt;&lt;17);
      x3 +=3D 65536 + (128&lt;&lt;17);
      // tried computing the shifts into temps, or'ing the temps to see
      // if any were out of range, but that was slower
      o[0] =3D stbi__clamp((x0+t3) &gt;&gt; 17);
      o[7] =3D stbi__clamp((x0-t3) &gt;&gt; 17);
      o[1] =3D stbi__clamp((x1+t2) &gt;&gt; 17);
      o[6] =3D stbi__clamp((x1-t2) &gt;&gt; 17);
      o[2] =3D stbi__clamp((x2+t1) &gt;&gt; 17);
      o[5] =3D stbi__clamp((x2-t1) &gt;&gt; 17);
      o[3] =3D stbi__clamp((x3+t0) &gt;&gt; 17);
      o[4] =3D stbi__clamp((x3-t0) &gt;&gt; 17);
   }
}

#ifdef STBI_SSE2
// sse2 integer IDCT. not the fastest possible implementation but it
// produces bit-identical results to the generic C version so it's
// fully "transparent".
static void stbi__idct_simd(stbi_uc *out, int out_stride, short data[64])
{
   // This is constructed to match our regular (generic) integer IDCT exact=
ly.
   __m128i row0, row1, row2, row3, row4, row5, row6, row7;
   __m128i tmp;

   // dot product constant: even elems=3Dx, odd elems=3Dy
   #define dct_const(x,y)  _mm_setr_epi16((x),(y),(x),(y),(x),(y),(x),(y))

   // out(0) =3D c0[even]*x + c0[odd]*y   (c0, x, y 16-bit, out 32-bit)
   // out(1) =3D c1[even]*x + c1[odd]*y
   #define dct_rot(out0,out1, x,y,c0,c1) \
      __m128i c0##lo =3D _mm_unpacklo_epi16((x),(y)); \
      __m128i c0##hi =3D _mm_unpackhi_epi16((x),(y)); \
      __m128i out0##_l =3D _mm_madd_epi16(c0##lo, c0); \
      __m128i out0##_h =3D _mm_madd_epi16(c0##hi, c0); \
      __m128i out1##_l =3D _mm_madd_epi16(c0##lo, c1); \
      __m128i out1##_h =3D _mm_madd_epi16(c0##hi, c1)

   // out =3D in &lt;&lt; 12  (in 16-bit, out 32-bit)
   #define dct_widen(out, in) \
      __m128i out##_l =3D _mm_srai_epi32(_mm_unpacklo_epi16(_mm_setzero_si1=
28(), (in)), 4); \
      __m128i out##_h =3D _mm_srai_epi32(_mm_unpackhi_epi16(_mm_setzero_si1=
28(), (in)), 4)

   // wide add
   #define dct_wadd(out, a, b) \
      __m128i out##_l =3D _mm_add_epi32(a##_l, b##_l); \
      __m128i out##_h =3D _mm_add_epi32(a##_h, b##_h)

   // wide sub
   #define dct_wsub(out, a, b) \
      __m128i out##_l =3D _mm_sub_epi32(a##_l, b##_l); \
      __m128i out##_h =3D _mm_sub_epi32(a##_h, b##_h)

   // butterfly a/b, add bias, then shift by "s" and pack
   #define dct_bfly32o(out0, out1, a,b,bias,s) \
      { \
         __m128i abiased_l =3D _mm_add_epi32(a##_l, bias); \
         __m128i abiased_h =3D _mm_add_epi32(a##_h, bias); \
         dct_wadd(sum, abiased, b); \
         dct_wsub(dif, abiased, b); \
         out0 =3D _mm_packs_epi32(_mm_srai_epi32(sum_l, s), _mm_srai_epi32(=
sum_h, s)); \
         out1 =3D _mm_packs_epi32(_mm_srai_epi32(dif_l, s), _mm_srai_epi32(=
dif_h, s)); \
      }

   // 8-bit interleave step (for transposes)
   #define dct_interleave8(a, b) \
      tmp =3D a; \
      a =3D _mm_unpacklo_epi8(a, b); \
      b =3D _mm_unpackhi_epi8(tmp, b)

   // 16-bit interleave step (for transposes)
   #define dct_interleave16(a, b) \
      tmp =3D a; \
      a =3D _mm_unpacklo_epi16(a, b); \
      b =3D _mm_unpackhi_epi16(tmp, b)

   #define dct_pass(bias,shift) \
      { \
         /* even part */ \
         dct_rot(t2e,t3e, row2,row6, rot0_0,rot0_1); \
         __m128i sum04 =3D _mm_add_epi16(row0, row4); \
         __m128i dif04 =3D _mm_sub_epi16(row0, row4); \
         dct_widen(t0e, sum04); \
         dct_widen(t1e, dif04); \
         dct_wadd(x0, t0e, t3e); \
         dct_wsub(x3, t0e, t3e); \
         dct_wadd(x1, t1e, t2e); \
         dct_wsub(x2, t1e, t2e); \
         /* odd part */ \
         dct_rot(y0o,y2o, row7,row3, rot2_0,rot2_1); \
         dct_rot(y1o,y3o, row5,row1, rot3_0,rot3_1); \
         __m128i sum17 =3D _mm_add_epi16(row1, row7); \
         __m128i sum35 =3D _mm_add_epi16(row3, row5); \
         dct_rot(y4o,y5o, sum17,sum35, rot1_0,rot1_1); \
         dct_wadd(x4, y0o, y4o); \
         dct_wadd(x5, y1o, y5o); \
         dct_wadd(x6, y2o, y5o); \
         dct_wadd(x7, y3o, y4o); \
         dct_bfly32o(row0,row7, x0,x7,bias,shift); \
         dct_bfly32o(row1,row6, x1,x6,bias,shift); \
         dct_bfly32o(row2,row5, x2,x5,bias,shift); \
         dct_bfly32o(row3,row4, x3,x4,bias,shift); \
      }

   __m128i rot0_0 =3D dct_const(stbi__f2f(0.5411961f), stbi__f2f(0.5411961f=
) + stbi__f2f(-1.847759065f));
   __m128i rot0_1 =3D dct_const(stbi__f2f(0.5411961f) + stbi__f2f( 0.765366=
865f), stbi__f2f(0.5411961f));
   __m128i rot1_0 =3D dct_const(stbi__f2f(1.175875602f) + stbi__f2f(-0.8999=
76223f), stbi__f2f(1.175875602f));
   __m128i rot1_1 =3D dct_const(stbi__f2f(1.175875602f), stbi__f2f(1.175875=
602f) + stbi__f2f(-2.562915447f));
   __m128i rot2_0 =3D dct_const(stbi__f2f(-1.961570560f) + stbi__f2f( 0.298=
631336f), stbi__f2f(-1.961570560f));
   __m128i rot2_1 =3D dct_const(stbi__f2f(-1.961570560f), stbi__f2f(-1.9615=
70560f) + stbi__f2f( 3.072711026f));
   __m128i rot3_0 =3D dct_const(stbi__f2f(-0.390180644f) + stbi__f2f( 2.053=
119869f), stbi__f2f(-0.390180644f));
   __m128i rot3_1 =3D dct_const(stbi__f2f(-0.390180644f), stbi__f2f(-0.3901=
80644f) + stbi__f2f( 1.501321110f));

   // rounding biases in column/row passes, see stbi__idct_block for explan=
ation.
   __m128i bias_0 =3D _mm_set1_epi32(512);
   __m128i bias_1 =3D _mm_set1_epi32(65536 + (128&lt;&lt;17));

   // load
   row0 =3D _mm_load_si128((const __m128i *) (data + 0*8));
   row1 =3D _mm_load_si128((const __m128i *) (data + 1*8));
   row2 =3D _mm_load_si128((const __m128i *) (data + 2*8));
   row3 =3D _mm_load_si128((const __m128i *) (data + 3*8));
   row4 =3D _mm_load_si128((const __m128i *) (data + 4*8));
   row5 =3D _mm_load_si128((const __m128i *) (data + 5*8));
   row6 =3D _mm_load_si128((const __m128i *) (data + 6*8));
   row7 =3D _mm_load_si128((const __m128i *) (data + 7*8));

   // column pass
   dct_pass(bias_0, 10);

   {
      // 16bit 8x8 transpose pass 1
      dct_interleave16(row0, row4);
      dct_interleave16(row1, row5);
      dct_interleave16(row2, row6);
      dct_interleave16(row3, row7);

      // transpose pass 2
      dct_interleave16(row0, row2);
      dct_interleave16(row1, row3);
      dct_interleave16(row4, row6);
      dct_interleave16(row5, row7);

      // transpose pass 3
      dct_interleave16(row0, row1);
      dct_interleave16(row2, row3);
      dct_interleave16(row4, row5);
      dct_interleave16(row6, row7);
   }

   // row pass
   dct_pass(bias_1, 17);

   {
      // pack
      __m128i p0 =3D _mm_packus_epi16(row0, row1); // a0a1a2a3...a7b0b1b2b3=
...b7
      __m128i p1 =3D _mm_packus_epi16(row2, row3);
      __m128i p2 =3D _mm_packus_epi16(row4, row5);
      __m128i p3 =3D _mm_packus_epi16(row6, row7);

      // 8bit 8x8 transpose pass 1
      dct_interleave8(p0, p2); // a0e0a1e1...
      dct_interleave8(p1, p3); // c0g0c1g1...

      // transpose pass 2
      dct_interleave8(p0, p1); // a0c0e0g0...
      dct_interleave8(p2, p3); // b0d0f0h0...

      // transpose pass 3
      dct_interleave8(p0, p2); // a0b0c0d0...
      dct_interleave8(p1, p3); // a4b4c4d4...

      // store
      _mm_storel_epi64((__m128i *) out, p0); out +=3D out_stride;
      _mm_storel_epi64((__m128i *) out, _mm_shuffle_epi32(p0, 0x4e)); out +=
=3D out_stride;
      _mm_storel_epi64((__m128i *) out, p2); out +=3D out_stride;
      _mm_storel_epi64((__m128i *) out, _mm_shuffle_epi32(p2, 0x4e)); out +=
=3D out_stride;
      _mm_storel_epi64((__m128i *) out, p1); out +=3D out_stride;
      _mm_storel_epi64((__m128i *) out, _mm_shuffle_epi32(p1, 0x4e)); out +=
=3D out_stride;
      _mm_storel_epi64((__m128i *) out, p3); out +=3D out_stride;
      _mm_storel_epi64((__m128i *) out, _mm_shuffle_epi32(p3, 0x4e));
   }

#undef dct_const
#undef dct_rot
#undef dct_widen
#undef dct_wadd
#undef dct_wsub
#undef dct_bfly32o
#undef dct_interleave8
#undef dct_interleave16
#undef dct_pass
}

#endif // STBI_SSE2

#ifdef STBI_NEON

// NEON integer IDCT. should produce bit-identical
// results to the generic C version.
static void stbi__idct_simd(stbi_uc *out, int out_stride, short data[64])
{
   int16x8_t row0, row1, row2, row3, row4, row5, row6, row7;

   int16x4_t rot0_0 =3D vdup_n_s16(stbi__f2f(0.5411961f));
   int16x4_t rot0_1 =3D vdup_n_s16(stbi__f2f(-1.847759065f));
   int16x4_t rot0_2 =3D vdup_n_s16(stbi__f2f( 0.765366865f));
   int16x4_t rot1_0 =3D vdup_n_s16(stbi__f2f( 1.175875602f));
   int16x4_t rot1_1 =3D vdup_n_s16(stbi__f2f(-0.899976223f));
   int16x4_t rot1_2 =3D vdup_n_s16(stbi__f2f(-2.562915447f));
   int16x4_t rot2_0 =3D vdup_n_s16(stbi__f2f(-1.961570560f));
   int16x4_t rot2_1 =3D vdup_n_s16(stbi__f2f(-0.390180644f));
   int16x4_t rot3_0 =3D vdup_n_s16(stbi__f2f( 0.298631336f));
   int16x4_t rot3_1 =3D vdup_n_s16(stbi__f2f( 2.053119869f));
   int16x4_t rot3_2 =3D vdup_n_s16(stbi__f2f( 3.072711026f));
   int16x4_t rot3_3 =3D vdup_n_s16(stbi__f2f( 1.501321110f));

#define dct_long_mul(out, inq, coeff) \
   int32x4_t out##_l =3D vmull_s16(vget_low_s16(inq), coeff); \
   int32x4_t out##_h =3D vmull_s16(vget_high_s16(inq), coeff)

#define dct_long_mac(out, acc, inq, coeff) \
   int32x4_t out##_l =3D vmlal_s16(acc##_l, vget_low_s16(inq), coeff); \
   int32x4_t out##_h =3D vmlal_s16(acc##_h, vget_high_s16(inq), coeff)

#define dct_widen(out, inq) \
   int32x4_t out##_l =3D vshll_n_s16(vget_low_s16(inq), 12); \
   int32x4_t out##_h =3D vshll_n_s16(vget_high_s16(inq), 12)

// wide add
#define dct_wadd(out, a, b) \
   int32x4_t out##_l =3D vaddq_s32(a##_l, b##_l); \
   int32x4_t out##_h =3D vaddq_s32(a##_h, b##_h)

// wide sub
#define dct_wsub(out, a, b) \
   int32x4_t out##_l =3D vsubq_s32(a##_l, b##_l); \
   int32x4_t out##_h =3D vsubq_s32(a##_h, b##_h)

// butterfly a/b, then shift using "shiftop" by "s" and pack
#define dct_bfly32o(out0,out1, a,b,shiftop,s) \
   { \
      dct_wadd(sum, a, b); \
      dct_wsub(dif, a, b); \
      out0 =3D vcombine_s16(shiftop(sum_l, s), shiftop(sum_h, s)); \
      out1 =3D vcombine_s16(shiftop(dif_l, s), shiftop(dif_h, s)); \
   }

#define dct_pass(shiftop, shift) \
   { \
      /* even part */ \
      int16x8_t sum26 =3D vaddq_s16(row2, row6); \
      dct_long_mul(p1e, sum26, rot0_0); \
      dct_long_mac(t2e, p1e, row6, rot0_1); \
      dct_long_mac(t3e, p1e, row2, rot0_2); \
      int16x8_t sum04 =3D vaddq_s16(row0, row4); \
      int16x8_t dif04 =3D vsubq_s16(row0, row4); \
      dct_widen(t0e, sum04); \
      dct_widen(t1e, dif04); \
      dct_wadd(x0, t0e, t3e); \
      dct_wsub(x3, t0e, t3e); \
      dct_wadd(x1, t1e, t2e); \
      dct_wsub(x2, t1e, t2e); \
      /* odd part */ \
      int16x8_t sum15 =3D vaddq_s16(row1, row5); \
      int16x8_t sum17 =3D vaddq_s16(row1, row7); \
      int16x8_t sum35 =3D vaddq_s16(row3, row5); \
      int16x8_t sum37 =3D vaddq_s16(row3, row7); \
      int16x8_t sumodd =3D vaddq_s16(sum17, sum35); \
      dct_long_mul(p5o, sumodd, rot1_0); \
      dct_long_mac(p1o, p5o, sum17, rot1_1); \
      dct_long_mac(p2o, p5o, sum35, rot1_2); \
      dct_long_mul(p3o, sum37, rot2_0); \
      dct_long_mul(p4o, sum15, rot2_1); \
      dct_wadd(sump13o, p1o, p3o); \
      dct_wadd(sump24o, p2o, p4o); \
      dct_wadd(sump23o, p2o, p3o); \
      dct_wadd(sump14o, p1o, p4o); \
      dct_long_mac(x4, sump13o, row7, rot3_0); \
      dct_long_mac(x5, sump24o, row5, rot3_1); \
      dct_long_mac(x6, sump23o, row3, rot3_2); \
      dct_long_mac(x7, sump14o, row1, rot3_3); \
      dct_bfly32o(row0,row7, x0,x7,shiftop,shift); \
      dct_bfly32o(row1,row6, x1,x6,shiftop,shift); \
      dct_bfly32o(row2,row5, x2,x5,shiftop,shift); \
      dct_bfly32o(row3,row4, x3,x4,shiftop,shift); \
   }

   // load
   row0 =3D vld1q_s16(data + 0*8);
   row1 =3D vld1q_s16(data + 1*8);
   row2 =3D vld1q_s16(data + 2*8);
   row3 =3D vld1q_s16(data + 3*8);
   row4 =3D vld1q_s16(data + 4*8);
   row5 =3D vld1q_s16(data + 5*8);
   row6 =3D vld1q_s16(data + 6*8);
   row7 =3D vld1q_s16(data + 7*8);

   // add DC bias
   row0 =3D vaddq_s16(row0, vsetq_lane_s16(1024, vdupq_n_s16(0), 0));

   // column pass
   dct_pass(vrshrn_n_s32, 10);

   // 16bit 8x8 transpose
   {
// these three map to a single VTRN.16, VTRN.32, and VSWP, respectively.
// whether compilers actually get this is another story, sadly.
#define dct_trn16(x, y) { int16x8x2_t t =3D vtrnq_s16(x, y); x =3D t.val[0]=
; y =3D t.val[1]; }
#define dct_trn32(x, y) { int32x4x2_t t =3D vtrnq_s32(vreinterpretq_s32_s16=
(x), vreinterpretq_s32_s16(y)); x =3D vreinterpretq_s16_s32(t.val[0]); y =
=3D vreinterpretq_s16_s32(t.val[1]); }
#define dct_trn64(x, y) { int16x8_t x0 =3D x; int16x8_t y0 =3D y; x =3D vco=
mbine_s16(vget_low_s16(x0), vget_low_s16(y0)); y =3D vcombine_s16(vget_high=
_s16(x0), vget_high_s16(y0)); }

      // pass 1
      dct_trn16(row0, row1); // a0b0a2b2a4b4a6b6
      dct_trn16(row2, row3);
      dct_trn16(row4, row5);
      dct_trn16(row6, row7);

      // pass 2
      dct_trn32(row0, row2); // a0b0c0d0a4b4c4d4
      dct_trn32(row1, row3);
      dct_trn32(row4, row6);
      dct_trn32(row5, row7);

      // pass 3
      dct_trn64(row0, row4); // a0b0c0d0e0f0g0h0
      dct_trn64(row1, row5);
      dct_trn64(row2, row6);
      dct_trn64(row3, row7);

#undef dct_trn16
#undef dct_trn32
#undef dct_trn64
   }

   // row pass
   // vrshrn_n_s32 only supports shifts up to 16, we need
   // 17. so do a non-rounding shift of 16 first then follow
   // up with a rounding shift by 1.
   dct_pass(vshrn_n_s32, 16);

   {
      // pack and round
      uint8x8_t p0 =3D vqrshrun_n_s16(row0, 1);
      uint8x8_t p1 =3D vqrshrun_n_s16(row1, 1);
      uint8x8_t p2 =3D vqrshrun_n_s16(row2, 1);
      uint8x8_t p3 =3D vqrshrun_n_s16(row3, 1);
      uint8x8_t p4 =3D vqrshrun_n_s16(row4, 1);
      uint8x8_t p5 =3D vqrshrun_n_s16(row5, 1);
      uint8x8_t p6 =3D vqrshrun_n_s16(row6, 1);
      uint8x8_t p7 =3D vqrshrun_n_s16(row7, 1);

      // again, these can translate into one instruction, but often don't.
#define dct_trn8_8(x, y) { uint8x8x2_t t =3D vtrn_u8(x, y); x =3D t.val[0];=
 y =3D t.val[1]; }
#define dct_trn8_16(x, y) { uint16x4x2_t t =3D vtrn_u16(vreinterpret_u16_u8=
(x), vreinterpret_u16_u8(y)); x =3D vreinterpret_u8_u16(t.val[0]); y =3D vr=
einterpret_u8_u16(t.val[1]); }
#define dct_trn8_32(x, y) { uint32x2x2_t t =3D vtrn_u32(vreinterpret_u32_u8=
(x), vreinterpret_u32_u8(y)); x =3D vreinterpret_u8_u32(t.val[0]); y =3D vr=
einterpret_u8_u32(t.val[1]); }

      // sadly can't use interleaved stores here since we only write
      // 8 bytes to each scan line!

      // 8x8 8-bit transpose pass 1
      dct_trn8_8(p0, p1);
      dct_trn8_8(p2, p3);
      dct_trn8_8(p4, p5);
      dct_trn8_8(p6, p7);

      // pass 2
      dct_trn8_16(p0, p2);
      dct_trn8_16(p1, p3);
      dct_trn8_16(p4, p6);
      dct_trn8_16(p5, p7);

      // pass 3
      dct_trn8_32(p0, p4);
      dct_trn8_32(p1, p5);
      dct_trn8_32(p2, p6);
      dct_trn8_32(p3, p7);

      // store
      vst1_u8(out, p0); out +=3D out_stride;
      vst1_u8(out, p1); out +=3D out_stride;
      vst1_u8(out, p2); out +=3D out_stride;
      vst1_u8(out, p3); out +=3D out_stride;
      vst1_u8(out, p4); out +=3D out_stride;
      vst1_u8(out, p5); out +=3D out_stride;
      vst1_u8(out, p6); out +=3D out_stride;
      vst1_u8(out, p7);

#undef dct_trn8_8
#undef dct_trn8_16
#undef dct_trn8_32
   }

#undef dct_long_mul
#undef dct_long_mac
#undef dct_widen
#undef dct_wadd
#undef dct_wsub
#undef dct_bfly32o
#undef dct_pass
}

#endif // STBI_NEON

#define STBI__MARKER_none  0xff
// if there's a pending marker from the entropy stream, return that
// otherwise, fetch from the stream and get a marker. if there's no
// marker, return 0xff, which is never a valid marker value
static stbi_uc stbi__get_marker(stbi__jpeg *j)
{
   stbi_uc x;
   if (j-&gt;marker !=3D STBI__MARKER_none) { x =3D j-&gt;marker; j-&gt;mar=
ker =3D STBI__MARKER_none; return x; }
   x =3D stbi__get8(j-&gt;s);
   if (x !=3D 0xff) return STBI__MARKER_none;
   while (x =3D=3D 0xff)
      x =3D stbi__get8(j-&gt;s); // consume repeated 0xff fill bytes
   return x;
}

// in each scan, we'll have scan_n components, and the order
// of the components is specified by order[]
#define STBI__RESTART(x)     ((x) &gt;=3D 0xd0 &amp;&amp; (x) &lt;=3D 0xd7)

// after a restart interval, stbi__jpeg_reset the entropy decoder and
// the dc prediction
static void stbi__jpeg_reset(stbi__jpeg *j)
{
   j-&gt;code_bits =3D 0;
   j-&gt;code_buffer =3D 0;
   j-&gt;nomore =3D 0;
   j-&gt;img_comp[0].dc_pred =3D j-&gt;img_comp[1].dc_pred =3D j-&gt;img_co=
mp[2].dc_pred =3D j-&gt;img_comp[3].dc_pred =3D 0;
   j-&gt;marker =3D STBI__MARKER_none;
   j-&gt;todo =3D j-&gt;restart_interval ? j-&gt;restart_interval : 0x7ffff=
fff;
   j-&gt;eob_run =3D 0;
   // no more than 1&lt;&lt;31 MCUs if no restart_interal? that's plenty sa=
fe,
   // since we don't even allow 1&lt;&lt;30 pixels
}

static int stbi__parse_entropy_coded_data(stbi__jpeg *z)
{
   stbi__jpeg_reset(z);
   if (!z-&gt;progressive) {
      if (z-&gt;scan_n =3D=3D 1) {
         int i,j;
         STBI_SIMD_ALIGN(short, data[64]);
         int n =3D z-&gt;order[0];
         // non-interleaved data, we just need to process one block at a ti=
me,
         // in trivial scanline order
         // number of blocks to do just depends on how many actual "pixels"=
 this
         // component has, independent of interleaved MCU blocking and such
         int w =3D (z-&gt;img_comp[n].x+7) &gt;&gt; 3;
         int h =3D (z-&gt;img_comp[n].y+7) &gt;&gt; 3;
         for (j=3D0; j &lt; h; ++j) {
            for (i=3D0; i &lt; w; ++i) {
               int ha =3D z-&gt;img_comp[n].ha;
               if (!stbi__jpeg_decode_block(z, data, z-&gt;huff_dc+z-&gt;im=
g_comp[n].hd, z-&gt;huff_ac+ha, z-&gt;fast_ac[ha], n, z-&gt;dequant[z-&gt;i=
mg_comp[n].tq])) return 0;
               z-&gt;idct_block_kernel(z-&gt;img_comp[n].data+z-&gt;img_com=
p[n].w2*j*8+i*8, z-&gt;img_comp[n].w2, data);
               // every data block is an MCU, so countdown the restart inte=
rval
               if (--z-&gt;todo &lt;=3D 0) {
                  if (z-&gt;code_bits &lt; 24) stbi__grow_buffer_unsafe(z);
                  // if it's NOT a restart, then just bail, so we get corru=
pt data
                  // rather than no data
                  if (!STBI__RESTART(z-&gt;marker)) return 1;
                  stbi__jpeg_reset(z);
               }
            }
         }
         return 1;
      } else { // interleaved
         int i,j,k,x,y;
         STBI_SIMD_ALIGN(short, data[64]);
         for (j=3D0; j &lt; z-&gt;img_mcu_y; ++j) {
            for (i=3D0; i &lt; z-&gt;img_mcu_x; ++i) {
               // scan an interleaved mcu... process scan_n components in o=
rder
               for (k=3D0; k &lt; z-&gt;scan_n; ++k) {
                  int n =3D z-&gt;order[k];
                  // scan out an mcu's worth of this component; that's just=
 determined
                  // by the basic H and V specified for the component
                  for (y=3D0; y &lt; z-&gt;img_comp[n].v; ++y) {
                     for (x=3D0; x &lt; z-&gt;img_comp[n].h; ++x) {
                        int x2 =3D (i*z-&gt;img_comp[n].h + x)*8;
                        int y2 =3D (j*z-&gt;img_comp[n].v + y)*8;
                        int ha =3D z-&gt;img_comp[n].ha;
                        if (!stbi__jpeg_decode_block(z, data, z-&gt;huff_dc=
+z-&gt;img_comp[n].hd, z-&gt;huff_ac+ha, z-&gt;fast_ac[ha], n, z-&gt;dequan=
t[z-&gt;img_comp[n].tq])) return 0;
                        z-&gt;idct_block_kernel(z-&gt;img_comp[n].data+z-&g=
t;img_comp[n].w2*y2+x2, z-&gt;img_comp[n].w2, data);
                     }
                  }
               }
               // after all interleaved components, that's an interleaved M=
CU,
               // so now count down the restart interval
               if (--z-&gt;todo &lt;=3D 0) {
                  if (z-&gt;code_bits &lt; 24) stbi__grow_buffer_unsafe(z);
                  if (!STBI__RESTART(z-&gt;marker)) return 1;
                  stbi__jpeg_reset(z);
               }
            }
         }
         return 1;
      }
   } else {
      if (z-&gt;scan_n =3D=3D 1) {
         int i,j;
         int n =3D z-&gt;order[0];
         // non-interleaved data, we just need to process one block at a ti=
me,
         // in trivial scanline order
         // number of blocks to do just depends on how many actual "pixels"=
 this
         // component has, independent of interleaved MCU blocking and such
         int w =3D (z-&gt;img_comp[n].x+7) &gt;&gt; 3;
         int h =3D (z-&gt;img_comp[n].y+7) &gt;&gt; 3;
         for (j=3D0; j &lt; h; ++j) {
            for (i=3D0; i &lt; w; ++i) {
               short *data =3D z-&gt;img_comp[n].coeff + 64 * (i + j * z-&g=
t;img_comp[n].coeff_w);
               if (z-&gt;spec_start =3D=3D 0) {
                  if (!stbi__jpeg_decode_block_prog_dc(z, data, &amp;z-&gt;=
huff_dc[z-&gt;img_comp[n].hd], n))
                     return 0;
               } else {
                  int ha =3D z-&gt;img_comp[n].ha;
                  if (!stbi__jpeg_decode_block_prog_ac(z, data, &amp;z-&gt;=
huff_ac[ha], z-&gt;fast_ac[ha]))
                     return 0;
               }
               // every data block is an MCU, so countdown the restart inte=
rval
               if (--z-&gt;todo &lt;=3D 0) {
                  if (z-&gt;code_bits &lt; 24) stbi__grow_buffer_unsafe(z);
                  if (!STBI__RESTART(z-&gt;marker)) return 1;
                  stbi__jpeg_reset(z);
               }
            }
         }
         return 1;
      } else { // interleaved
         int i,j,k,x,y;
         for (j=3D0; j &lt; z-&gt;img_mcu_y; ++j) {
            for (i=3D0; i &lt; z-&gt;img_mcu_x; ++i) {
               // scan an interleaved mcu... process scan_n components in o=
rder
               for (k=3D0; k &lt; z-&gt;scan_n; ++k) {
                  int n =3D z-&gt;order[k];
                  // scan out an mcu's worth of this component; that's just=
 determined
                  // by the basic H and V specified for the component
                  for (y=3D0; y &lt; z-&gt;img_comp[n].v; ++y) {
                     for (x=3D0; x &lt; z-&gt;img_comp[n].h; ++x) {
                        int x2 =3D (i*z-&gt;img_comp[n].h + x);
                        int y2 =3D (j*z-&gt;img_comp[n].v + y);
                        short *data =3D z-&gt;img_comp[n].coeff + 64 * (x2 =
+ y2 * z-&gt;img_comp[n].coeff_w);
                        if (!stbi__jpeg_decode_block_prog_dc(z, data, &amp;=
z-&gt;huff_dc[z-&gt;img_comp[n].hd], n))
                           return 0;
                     }
                  }
               }
               // after all interleaved components, that's an interleaved M=
CU,
               // so now count down the restart interval
               if (--z-&gt;todo &lt;=3D 0) {
                  if (z-&gt;code_bits &lt; 24) stbi__grow_buffer_unsafe(z);
                  if (!STBI__RESTART(z-&gt;marker)) return 1;
                  stbi__jpeg_reset(z);
               }
            }
         }
         return 1;
      }
   }
}

static void stbi__jpeg_dequantize(short *data, stbi__uint16 *dequant)
{
   int i;
   for (i=3D0; i &lt; 64; ++i)
      data[i] *=3D dequant[i];
}

static void stbi__jpeg_finish(stbi__jpeg *z)
{
   if (z-&gt;progressive) {
      // dequantize and idct the data
      int i,j,n;
      for (n=3D0; n &lt; z-&gt;s-&gt;img_n; ++n) {
         int w =3D (z-&gt;img_comp[n].x+7) &gt;&gt; 3;
         int h =3D (z-&gt;img_comp[n].y+7) &gt;&gt; 3;
         for (j=3D0; j &lt; h; ++j) {
            for (i=3D0; i &lt; w; ++i) {
               short *data =3D z-&gt;img_comp[n].coeff + 64 * (i + j * z-&g=
t;img_comp[n].coeff_w);
               stbi__jpeg_dequantize(data, z-&gt;dequant[z-&gt;img_comp[n].=
tq]);
               z-&gt;idct_block_kernel(z-&gt;img_comp[n].data+z-&gt;img_com=
p[n].w2*j*8+i*8, z-&gt;img_comp[n].w2, data);
            }
         }
      }
   }
}

static int stbi__process_marker(stbi__jpeg *z, int m)
{
   int L;
   switch (m) {
      case STBI__MARKER_none: // no marker found
         return stbi__err("expected marker","Corrupt JPEG");

      case 0xDD: // DRI - specify restart interval
         if (stbi__get16be(z-&gt;s) !=3D 4) return stbi__err("bad DRI len",=
"Corrupt JPEG");
         z-&gt;restart_interval =3D stbi__get16be(z-&gt;s);
         return 1;

      case 0xDB: // DQT - define quantization table
         L =3D stbi__get16be(z-&gt;s)-2;
         while (L &gt; 0) {
            int q =3D stbi__get8(z-&gt;s);
            int p =3D q &gt;&gt; 4, sixteen =3D (p !=3D 0);
            int t =3D q &amp; 15,i;
            if (p !=3D 0 &amp;&amp; p !=3D 1) return stbi__err("bad DQT typ=
e","Corrupt JPEG");
            if (t &gt; 3) return stbi__err("bad DQT table","Corrupt JPEG");

            for (i=3D0; i &lt; 64; ++i)
               z-&gt;dequant[t][stbi__jpeg_dezigzag[i]] =3D (stbi__uint16)(=
sixteen ? stbi__get16be(z-&gt;s) : stbi__get8(z-&gt;s));
            L -=3D (sixteen ? 129 : 65);
         }
         return L=3D=3D0;

      case 0xC4: // DHT - define huffman table
         L =3D stbi__get16be(z-&gt;s)-2;
         while (L &gt; 0) {
            stbi_uc *v;
            int sizes[16],i,n=3D0;
            int q =3D stbi__get8(z-&gt;s);
            int tc =3D q &gt;&gt; 4;
            int th =3D q &amp; 15;
            if (tc &gt; 1 || th &gt; 3) return stbi__err("bad DHT header","=
Corrupt JPEG");
            for (i=3D0; i &lt; 16; ++i) {
               sizes[i] =3D stbi__get8(z-&gt;s);
               n +=3D sizes[i];
            }
            L -=3D 17;
            if (tc =3D=3D 0) {
               if (!stbi__build_huffman(z-&gt;huff_dc+th, sizes)) return 0;
               v =3D z-&gt;huff_dc[th].values;
            } else {
               if (!stbi__build_huffman(z-&gt;huff_ac+th, sizes)) return 0;
               v =3D z-&gt;huff_ac[th].values;
            }
            for (i=3D0; i &lt; n; ++i)
               v[i] =3D stbi__get8(z-&gt;s);
            if (tc !=3D 0)
               stbi__build_fast_ac(z-&gt;fast_ac[th], z-&gt;huff_ac + th);
            L -=3D n;
         }
         return L=3D=3D0;
   }

   // check for comment block or APP blocks
   if ((m &gt;=3D 0xE0 &amp;&amp; m &lt;=3D 0xEF) || m =3D=3D 0xFE) {
      L =3D stbi__get16be(z-&gt;s);
      if (L &lt; 2) {
         if (m =3D=3D 0xFE)
            return stbi__err("bad COM len","Corrupt JPEG");
         else
            return stbi__err("bad APP len","Corrupt JPEG");
      }
      L -=3D 2;

      if (m =3D=3D 0xE0 &amp;&amp; L &gt;=3D 5) { // JFIF APP0 segment
         static const unsigned char tag[5] =3D {'J','F','I','F','\0'};
         int ok =3D 1;
         int i;
         for (i=3D0; i &lt; 5; ++i)
            if (stbi__get8(z-&gt;s) !=3D tag[i])
               ok =3D 0;
         L -=3D 5;
         if (ok)
            z-&gt;jfif =3D 1;
      } else if (m =3D=3D 0xEE &amp;&amp; L &gt;=3D 12) { // Adobe APP14 se=
gment
         static const unsigned char tag[6] =3D {'A','d','o','b','e','\0'};
         int ok =3D 1;
         int i;
         for (i=3D0; i &lt; 6; ++i)
            if (stbi__get8(z-&gt;s) !=3D tag[i])
               ok =3D 0;
         L -=3D 6;
         if (ok) {
            stbi__get8(z-&gt;s); // version
            stbi__get16be(z-&gt;s); // flags0
            stbi__get16be(z-&gt;s); // flags1
            z-&gt;app14_color_transform =3D stbi__get8(z-&gt;s); // color t=
ransform
            L -=3D 6;
         }
      }

      stbi__skip(z-&gt;s, L);
      return 1;
   }

   return stbi__err("unknown marker","Corrupt JPEG");
}

// after we see SOS
static int stbi__process_scan_header(stbi__jpeg *z)
{
   int i;
   int Ls =3D stbi__get16be(z-&gt;s);
   z-&gt;scan_n =3D stbi__get8(z-&gt;s);
   if (z-&gt;scan_n &lt; 1 || z-&gt;scan_n &gt; 4 || z-&gt;scan_n &gt; (int=
) z-&gt;s-&gt;img_n) return stbi__err("bad SOS component count","Corrupt JP=
EG");
   if (Ls !=3D 6+2*z-&gt;scan_n) return stbi__err("bad SOS len","Corrupt JP=
EG");
   for (i=3D0; i &lt; z-&gt;scan_n; ++i) {
      int id =3D stbi__get8(z-&gt;s), which;
      int q =3D stbi__get8(z-&gt;s);
      for (which =3D 0; which &lt; z-&gt;s-&gt;img_n; ++which)
         if (z-&gt;img_comp[which].id =3D=3D id)
            break;
      if (which =3D=3D z-&gt;s-&gt;img_n) return 0; // no match
      z-&gt;img_comp[which].hd =3D q &gt;&gt; 4;   if (z-&gt;img_comp[which=
].hd &gt; 3) return stbi__err("bad DC huff","Corrupt JPEG");
      z-&gt;img_comp[which].ha =3D q &amp; 15;   if (z-&gt;img_comp[which].=
ha &gt; 3) return stbi__err("bad AC huff","Corrupt JPEG");
      z-&gt;order[i] =3D which;
   }

   {
      int aa;
      z-&gt;spec_start =3D stbi__get8(z-&gt;s);
      z-&gt;spec_end   =3D stbi__get8(z-&gt;s); // should be 63, but might =
be 0
      aa =3D stbi__get8(z-&gt;s);
      z-&gt;succ_high =3D (aa &gt;&gt; 4);
      z-&gt;succ_low  =3D (aa &amp; 15);
      if (z-&gt;progressive) {
         if (z-&gt;spec_start &gt; 63 || z-&gt;spec_end &gt; 63  || z-&gt;s=
pec_start &gt; z-&gt;spec_end || z-&gt;succ_high &gt; 13 || z-&gt;succ_low =
&gt; 13)
            return stbi__err("bad SOS", "Corrupt JPEG");
      } else {
         if (z-&gt;spec_start !=3D 0) return stbi__err("bad SOS","Corrupt J=
PEG");
         if (z-&gt;succ_high !=3D 0 || z-&gt;succ_low !=3D 0) return stbi__=
err("bad SOS","Corrupt JPEG");
         z-&gt;spec_end =3D 63;
      }
   }

   return 1;
}

static int stbi__free_jpeg_components(stbi__jpeg *z, int ncomp, int why)
{
   int i;
   for (i=3D0; i &lt; ncomp; ++i) {
      if (z-&gt;img_comp[i].raw_data) {
         STBI_FREE(z-&gt;img_comp[i].raw_data);
         z-&gt;img_comp[i].raw_data =3D NULL;
         z-&gt;img_comp[i].data =3D NULL;
      }
      if (z-&gt;img_comp[i].raw_coeff) {
         STBI_FREE(z-&gt;img_comp[i].raw_coeff);
         z-&gt;img_comp[i].raw_coeff =3D 0;
         z-&gt;img_comp[i].coeff =3D 0;
      }
      if (z-&gt;img_comp[i].linebuf) {
         STBI_FREE(z-&gt;img_comp[i].linebuf);
         z-&gt;img_comp[i].linebuf =3D NULL;
      }
   }
   return why;
}

static int stbi__process_frame_header(stbi__jpeg *z, int scan)
{
   stbi__context *s =3D z-&gt;s;
   int Lf,p,i,q, h_max=3D1,v_max=3D1,c;
   Lf =3D stbi__get16be(s);         if (Lf &lt; 11) return stbi__err("bad S=
OF len","Corrupt JPEG"); // JPEG
   p  =3D stbi__get8(s);            if (p !=3D 8) return stbi__err("only 8-=
bit","JPEG format not supported: 8-bit only"); // JPEG baseline
   s-&gt;img_y =3D stbi__get16be(s);   if (s-&gt;img_y =3D=3D 0) return stb=
i__err("no header height", "JPEG format not supported: delayed height"); //=
 Legal, but we don't handle it--but neither does IJG
   s-&gt;img_x =3D stbi__get16be(s);   if (s-&gt;img_x =3D=3D 0) return stb=
i__err("0 width","Corrupt JPEG"); // JPEG requires
   c =3D stbi__get8(s);
   if (c !=3D 3 &amp;&amp; c !=3D 1 &amp;&amp; c !=3D 4) return stbi__err("=
bad component count","Corrupt JPEG");
   s-&gt;img_n =3D c;
   for (i=3D0; i &lt; c; ++i) {
      z-&gt;img_comp[i].data =3D NULL;
      z-&gt;img_comp[i].linebuf =3D NULL;
   }

   if (Lf !=3D 8+3*s-&gt;img_n) return stbi__err("bad SOF len","Corrupt JPE=
G");

   z-&gt;rgb =3D 0;
   for (i=3D0; i &lt; s-&gt;img_n; ++i) {
      static const unsigned char rgb[3] =3D { 'R', 'G', 'B' };
      z-&gt;img_comp[i].id =3D stbi__get8(s);
      if (s-&gt;img_n =3D=3D 3 &amp;&amp; z-&gt;img_comp[i].id =3D=3D rgb[i=
])
         ++z-&gt;rgb;
      q =3D stbi__get8(s);
      z-&gt;img_comp[i].h =3D (q &gt;&gt; 4);  if (!z-&gt;img_comp[i].h || =
z-&gt;img_comp[i].h &gt; 4) return stbi__err("bad H","Corrupt JPEG");
      z-&gt;img_comp[i].v =3D q &amp; 15;    if (!z-&gt;img_comp[i].v || z-=
&gt;img_comp[i].v &gt; 4) return stbi__err("bad V","Corrupt JPEG");
      z-&gt;img_comp[i].tq =3D stbi__get8(s);  if (z-&gt;img_comp[i].tq &gt=
; 3) return stbi__err("bad TQ","Corrupt JPEG");
   }

   if (scan !=3D STBI__SCAN_load) return 1;

   if (!stbi__mad3sizes_valid(s-&gt;img_x, s-&gt;img_y, s-&gt;img_n, 0)) re=
turn stbi__err("too large", "Image too large to decode");

   for (i=3D0; i &lt; s-&gt;img_n; ++i) {
      if (z-&gt;img_comp[i].h &gt; h_max) h_max =3D z-&gt;img_comp[i].h;
      if (z-&gt;img_comp[i].v &gt; v_max) v_max =3D z-&gt;img_comp[i].v;
   }

   // compute interleaved mcu info
   z-&gt;img_h_max =3D h_max;
   z-&gt;img_v_max =3D v_max;
   z-&gt;img_mcu_w =3D h_max * 8;
   z-&gt;img_mcu_h =3D v_max * 8;
   // these sizes can't be more than 17 bits
   z-&gt;img_mcu_x =3D (s-&gt;img_x + z-&gt;img_mcu_w-1) / z-&gt;img_mcu_w;
   z-&gt;img_mcu_y =3D (s-&gt;img_y + z-&gt;img_mcu_h-1) / z-&gt;img_mcu_h;

   for (i=3D0; i &lt; s-&gt;img_n; ++i) {
      // number of effective pixels (e.g. for non-interleaved MCU)
      z-&gt;img_comp[i].x =3D (s-&gt;img_x * z-&gt;img_comp[i].h + h_max-1)=
 / h_max;
      z-&gt;img_comp[i].y =3D (s-&gt;img_y * z-&gt;img_comp[i].v + v_max-1)=
 / v_max;
      // to simplify generation, we'll allocate enough memory to decode
      // the bogus oversized data from using interleaved MCUs and their
      // big blocks (e.g. a 16x16 iMCU on an image of width 33); we won't
      // discard the extra data until colorspace conversion
      //
      // img_mcu_x, img_mcu_y: &lt;=3D17 bits; comp[i].h and .v are &lt;=3D=
4 (checked earlier)
      // so these muls can't overflow with 32-bit ints (which we require)
      z-&gt;img_comp[i].w2 =3D z-&gt;img_mcu_x * z-&gt;img_comp[i].h * 8;
      z-&gt;img_comp[i].h2 =3D z-&gt;img_mcu_y * z-&gt;img_comp[i].v * 8;
      z-&gt;img_comp[i].coeff =3D 0;
      z-&gt;img_comp[i].raw_coeff =3D 0;
      z-&gt;img_comp[i].linebuf =3D NULL;
      z-&gt;img_comp[i].raw_data =3D stbi__malloc_mad2(z-&gt;img_comp[i].w2=
, z-&gt;img_comp[i].h2, 15);
      if (z-&gt;img_comp[i].raw_data =3D=3D NULL)
         return stbi__free_jpeg_components(z, i+1, stbi__err("outofmem", "O=
ut of memory"));
      // align blocks for idct using mmx/sse
      z-&gt;img_comp[i].data =3D (stbi_uc*) (((size_t) z-&gt;img_comp[i].ra=
w_data + 15) &amp; ~15);
      if (z-&gt;progressive) {
         // w2, h2 are multiples of 8 (see above)
         z-&gt;img_comp[i].coeff_w =3D z-&gt;img_comp[i].w2 / 8;
         z-&gt;img_comp[i].coeff_h =3D z-&gt;img_comp[i].h2 / 8;
         z-&gt;img_comp[i].raw_coeff =3D stbi__malloc_mad3(z-&gt;img_comp[i=
].w2, z-&gt;img_comp[i].h2, sizeof(short), 15);
         if (z-&gt;img_comp[i].raw_coeff =3D=3D NULL)
            return stbi__free_jpeg_components(z, i+1, stbi__err("outofmem",=
 "Out of memory"));
         z-&gt;img_comp[i].coeff =3D (short*) (((size_t) z-&gt;img_comp[i].=
raw_coeff + 15) &amp; ~15);
      }
   }

   return 1;
}

// use comparisons since in some cases we handle more than one case (e.g. S=
OF)
#define stbi__DNL(x)         ((x) =3D=3D 0xdc)
#define stbi__SOI(x)         ((x) =3D=3D 0xd8)
#define stbi__EOI(x)         ((x) =3D=3D 0xd9)
#define stbi__SOF(x)         ((x) =3D=3D 0xc0 || (x) =3D=3D 0xc1 || (x) =3D=
=3D 0xc2)
#define stbi__SOS(x)         ((x) =3D=3D 0xda)

#define stbi__SOF_progressive(x)   ((x) =3D=3D 0xc2)

static int stbi__decode_jpeg_header(stbi__jpeg *z, int scan)
{
   int m;
   z-&gt;jfif =3D 0;
   z-&gt;app14_color_transform =3D -1; // valid values are 0,1,2
   z-&gt;marker =3D STBI__MARKER_none; // initialize cached marker to empty
   m =3D stbi__get_marker(z);
   if (!stbi__SOI(m)) return stbi__err("no SOI","Corrupt JPEG");
   if (scan =3D=3D STBI__SCAN_type) return 1;
   m =3D stbi__get_marker(z);
   while (!stbi__SOF(m)) {
      if (!stbi__process_marker(z,m)) return 0;
      m =3D stbi__get_marker(z);
      while (m =3D=3D STBI__MARKER_none) {
         // some files have extra padding after their blocks, so ok, we'll =
scan
         if (stbi__at_eof(z-&gt;s)) return stbi__err("no SOF", "Corrupt JPE=
G");
         m =3D stbi__get_marker(z);
      }
   }
   z-&gt;progressive =3D stbi__SOF_progressive(m);
   if (!stbi__process_frame_header(z, scan)) return 0;
   return 1;
}

// decode image to YCbCr format
static int stbi__decode_jpeg_image(stbi__jpeg *j)
{
   int m;
   for (m =3D 0; m &lt; 4; m++) {
      j-&gt;img_comp[m].raw_data =3D NULL;
      j-&gt;img_comp[m].raw_coeff =3D NULL;
   }
   j-&gt;restart_interval =3D 0;
   if (!stbi__decode_jpeg_header(j, STBI__SCAN_load)) return 0;
   m =3D stbi__get_marker(j);
   while (!stbi__EOI(m)) {
      if (stbi__SOS(m)) {
         if (!stbi__process_scan_header(j)) return 0;
         if (!stbi__parse_entropy_coded_data(j)) return 0;
         if (j-&gt;marker =3D=3D STBI__MARKER_none ) {
            // handle 0s at the end of image data from IP Kamera 9060
            while (!stbi__at_eof(j-&gt;s)) {
               int x =3D stbi__get8(j-&gt;s);
               if (x =3D=3D 255) {
                  j-&gt;marker =3D stbi__get8(j-&gt;s);
                  break;
               }
            }
            // if we reach eof without hitting a marker, stbi__get_marker()=
 below will fail and we'll eventually return 0
         }
      } else if (stbi__DNL(m)) {
         int Ld =3D stbi__get16be(j-&gt;s);
         stbi__uint32 NL =3D stbi__get16be(j-&gt;s);
         if (Ld !=3D 4) return stbi__err("bad DNL len", "Corrupt JPEG");
         if (NL !=3D j-&gt;s-&gt;img_y) return stbi__err("bad DNL height", =
"Corrupt JPEG");
      } else {
         if (!stbi__process_marker(j, m)) return 0;
      }
      m =3D stbi__get_marker(j);
   }
   if (j-&gt;progressive)
      stbi__jpeg_finish(j);
   return 1;
}

// static jfif-centered resampling (across block boundaries)

typedef stbi_uc *(*resample_row_func)(stbi_uc *out, stbi_uc *in0, stbi_uc *=
in1,
                                    int w, int hs);

#define stbi__div4(x) ((stbi_uc) ((x) &gt;&gt; 2))

static stbi_uc *resample_row_1(stbi_uc *out, stbi_uc *in_near, stbi_uc *in_=
far, int w, int hs)
{
   STBI_NOTUSED(out);
   STBI_NOTUSED(in_far);
   STBI_NOTUSED(w);
   STBI_NOTUSED(hs);
   return in_near;
}

static stbi_uc* stbi__resample_row_v_2(stbi_uc *out, stbi_uc *in_near, stbi=
_uc *in_far, int w, int hs)
{
   // need to generate two samples vertically for every one in input
   int i;
   STBI_NOTUSED(hs);
   for (i=3D0; i &lt; w; ++i)
      out[i] =3D stbi__div4(3*in_near[i] + in_far[i] + 2);
   return out;
}

static stbi_uc*  stbi__resample_row_h_2(stbi_uc *out, stbi_uc *in_near, stb=
i_uc *in_far, int w, int hs)
{
   // need to generate two samples horizontally for every one in input
   int i;
   stbi_uc *input =3D in_near;

   if (w =3D=3D 1) {
      // if only one sample, can't do any interpolation
      out[0] =3D out[1] =3D input[0];
      return out;
   }

   out[0] =3D input[0];
   out[1] =3D stbi__div4(input[0]*3 + input[1] + 2);
   for (i=3D1; i &lt; w-1; ++i) {
      int n =3D 3*input[i]+2;
      out[i*2+0] =3D stbi__div4(n+input[i-1]);
      out[i*2+1] =3D stbi__div4(n+input[i+1]);
   }
   out[i*2+0] =3D stbi__div4(input[w-2]*3 + input[w-1] + 2);
   out[i*2+1] =3D input[w-1];

   STBI_NOTUSED(in_far);
   STBI_NOTUSED(hs);

   return out;
}

#define stbi__div16(x) ((stbi_uc) ((x) &gt;&gt; 4))

static stbi_uc *stbi__resample_row_hv_2(stbi_uc *out, stbi_uc *in_near, stb=
i_uc *in_far, int w, int hs)
{
   // need to generate 2x2 samples for every one in input
   int i,t0,t1;
   if (w =3D=3D 1) {
      out[0] =3D out[1] =3D stbi__div4(3*in_near[0] + in_far[0] + 2);
      return out;
   }

   t1 =3D 3*in_near[0] + in_far[0];
   out[0] =3D stbi__div4(t1+2);
   for (i=3D1; i &lt; w; ++i) {
      t0 =3D t1;
      t1 =3D 3*in_near[i]+in_far[i];
      out[i*2-1] =3D stbi__div16(3*t0 + t1 + 8);
      out[i*2  ] =3D stbi__div16(3*t1 + t0 + 8);
   }
   out[w*2-1] =3D stbi__div4(t1+2);

   STBI_NOTUSED(hs);

   return out;
}

#if defined(STBI_SSE2) || defined(STBI_NEON)
static stbi_uc *stbi__resample_row_hv_2_simd(stbi_uc *out, stbi_uc *in_near=
, stbi_uc *in_far, int w, int hs)
{
   // need to generate 2x2 samples for every one in input
   int i=3D0,t0,t1;

   if (w =3D=3D 1) {
      out[0] =3D out[1] =3D stbi__div4(3*in_near[0] + in_far[0] + 2);
      return out;
   }

   t1 =3D 3*in_near[0] + in_far[0];
   // process groups of 8 pixels for as long as we can.
   // note we can't handle the last pixel in a row in this loop
   // because we need to handle the filter boundary conditions.
   for (; i &lt; ((w-1) &amp; ~7); i +=3D 8) {
#if defined(STBI_SSE2)
      // load and perform the vertical filtering pass
      // this uses 3*x + y =3D 4*x + (y - x)
      __m128i zero  =3D _mm_setzero_si128();
      __m128i farb  =3D _mm_loadl_epi64((__m128i *) (in_far + i));
      __m128i nearb =3D _mm_loadl_epi64((__m128i *) (in_near + i));
      __m128i farw  =3D _mm_unpacklo_epi8(farb, zero);
      __m128i nearw =3D _mm_unpacklo_epi8(nearb, zero);
      __m128i diff  =3D _mm_sub_epi16(farw, nearw);
      __m128i nears =3D _mm_slli_epi16(nearw, 2);
      __m128i curr  =3D _mm_add_epi16(nears, diff); // current row

      // horizontal filter works the same based on shifted vers of current
      // row. "prev" is current row shifted right by 1 pixel; we need to
      // insert the previous pixel value (from t1).
      // "next" is current row shifted left by 1 pixel, with first pixel
      // of next block of 8 pixels added in.
      __m128i prv0 =3D _mm_slli_si128(curr, 2);
      __m128i nxt0 =3D _mm_srli_si128(curr, 2);
      __m128i prev =3D _mm_insert_epi16(prv0, t1, 0);
      __m128i next =3D _mm_insert_epi16(nxt0, 3*in_near[i+8] + in_far[i+8],=
 7);

      // horizontal filter, polyphase implementation since it's convenient:
      // even pixels =3D 3*cur + prev =3D cur*4 + (prev - cur)
      // odd  pixels =3D 3*cur + next =3D cur*4 + (next - cur)
      // note the shared term.
      __m128i bias  =3D _mm_set1_epi16(8);
      __m128i curs =3D _mm_slli_epi16(curr, 2);
      __m128i prvd =3D _mm_sub_epi16(prev, curr);
      __m128i nxtd =3D _mm_sub_epi16(next, curr);
      __m128i curb =3D _mm_add_epi16(curs, bias);
      __m128i even =3D _mm_add_epi16(prvd, curb);
      __m128i odd  =3D _mm_add_epi16(nxtd, curb);

      // interleave even and odd pixels, then undo scaling.
      __m128i int0 =3D _mm_unpacklo_epi16(even, odd);
      __m128i int1 =3D _mm_unpackhi_epi16(even, odd);
      __m128i de0  =3D _mm_srli_epi16(int0, 4);
      __m128i de1  =3D _mm_srli_epi16(int1, 4);

      // pack and write output
      __m128i outv =3D _mm_packus_epi16(de0, de1);
      _mm_storeu_si128((__m128i *) (out + i*2), outv);
#elif defined(STBI_NEON)
      // load and perform the vertical filtering pass
      // this uses 3*x + y =3D 4*x + (y - x)
      uint8x8_t farb  =3D vld1_u8(in_far + i);
      uint8x8_t nearb =3D vld1_u8(in_near + i);
      int16x8_t diff  =3D vreinterpretq_s16_u16(vsubl_u8(farb, nearb));
      int16x8_t nears =3D vreinterpretq_s16_u16(vshll_n_u8(nearb, 2));
      int16x8_t curr  =3D vaddq_s16(nears, diff); // current row

      // horizontal filter works the same based on shifted vers of current
      // row. "prev" is current row shifted right by 1 pixel; we need to
      // insert the previous pixel value (from t1).
      // "next" is current row shifted left by 1 pixel, with first pixel
      // of next block of 8 pixels added in.
      int16x8_t prv0 =3D vextq_s16(curr, curr, 7);
      int16x8_t nxt0 =3D vextq_s16(curr, curr, 1);
      int16x8_t prev =3D vsetq_lane_s16(t1, prv0, 0);
      int16x8_t next =3D vsetq_lane_s16(3*in_near[i+8] + in_far[i+8], nxt0,=
 7);

      // horizontal filter, polyphase implementation since it's convenient:
      // even pixels =3D 3*cur + prev =3D cur*4 + (prev - cur)
      // odd  pixels =3D 3*cur + next =3D cur*4 + (next - cur)
      // note the shared term.
      int16x8_t curs =3D vshlq_n_s16(curr, 2);
      int16x8_t prvd =3D vsubq_s16(prev, curr);
      int16x8_t nxtd =3D vsubq_s16(next, curr);
      int16x8_t even =3D vaddq_s16(curs, prvd);
      int16x8_t odd  =3D vaddq_s16(curs, nxtd);

      // undo scaling and round, then store with even/odd phases interleave=
d
      uint8x8x2_t o;
      o.val[0] =3D vqrshrun_n_s16(even, 4);
      o.val[1] =3D vqrshrun_n_s16(odd,  4);
      vst2_u8(out + i*2, o);
#endif

      // "previous" value for next iter
      t1 =3D 3*in_near[i+7] + in_far[i+7];
   }

   t0 =3D t1;
   t1 =3D 3*in_near[i] + in_far[i];
   out[i*2] =3D stbi__div16(3*t1 + t0 + 8);

   for (++i; i &lt; w; ++i) {
      t0 =3D t1;
      t1 =3D 3*in_near[i]+in_far[i];
      out[i*2-1] =3D stbi__div16(3*t0 + t1 + 8);
      out[i*2  ] =3D stbi__div16(3*t1 + t0 + 8);
   }
   out[w*2-1] =3D stbi__div4(t1+2);

   STBI_NOTUSED(hs);

   return out;
}
#endif

static stbi_uc *stbi__resample_row_generic(stbi_uc *out, stbi_uc *in_near, =
stbi_uc *in_far, int w, int hs)
{
   // resample with nearest-neighbor
   int i,j;
   STBI_NOTUSED(in_far);
   for (i=3D0; i &lt; w; ++i)
      for (j=3D0; j &lt; hs; ++j)
         out[i*hs+j] =3D in_near[i];
   return out;
}

// this is a reduced-precision calculation of YCbCr-to-RGB introduced
// to make sure the code produces the same results in both SIMD and scalar
#define stbi__float2fixed(x)  (((int) ((x) * 4096.0f + 0.5f)) &lt;&lt; 8)
static void stbi__YCbCr_to_RGB_row(stbi_uc *out, const stbi_uc *y, const st=
bi_uc *pcb, const stbi_uc *pcr, int count, int step)
{
   int i;
   for (i=3D0; i &lt; count; ++i) {
      int y_fixed =3D (y[i] &lt;&lt; 20) + (1&lt;&lt;19); // rounding
      int r,g,b;
      int cr =3D pcr[i] - 128;
      int cb =3D pcb[i] - 128;
      r =3D y_fixed +  cr* stbi__float2fixed(1.40200f);
      g =3D y_fixed + (cr*-stbi__float2fixed(0.71414f)) + ((cb*-stbi__float=
2fixed(0.34414f)) &amp; 0xffff0000);
      b =3D y_fixed                                     +   cb* stbi__float=
2fixed(1.77200f);
      r &gt;&gt;=3D 20;
      g &gt;&gt;=3D 20;
      b &gt;&gt;=3D 20;
      if ((unsigned) r &gt; 255) { if (r &lt; 0) r =3D 0; else r =3D 255; }
      if ((unsigned) g &gt; 255) { if (g &lt; 0) g =3D 0; else g =3D 255; }
      if ((unsigned) b &gt; 255) { if (b &lt; 0) b =3D 0; else b =3D 255; }
      out[0] =3D (stbi_uc)r;
      out[1] =3D (stbi_uc)g;
      out[2] =3D (stbi_uc)b;
      out[3] =3D 255;
      out +=3D step;
   }
}

#if defined(STBI_SSE2) || defined(STBI_NEON)
static void stbi__YCbCr_to_RGB_simd(stbi_uc *out, stbi_uc const *y, stbi_uc=
 const *pcb, stbi_uc const *pcr, int count, int step)
{
   int i =3D 0;

#ifdef STBI_SSE2
   // step =3D=3D 3 is pretty ugly on the final interleave, and i'm not con=
vinced
   // it's useful in practice (you wouldn't use it for textures, for exampl=
e).
   // so just accelerate step =3D=3D 4 case.
   if (step =3D=3D 4) {
      // this is a fairly straightforward implementation and not super-opti=
mized.
      __m128i signflip  =3D _mm_set1_epi8(-0x80);
      __m128i cr_const0 =3D _mm_set1_epi16(   (short) ( 1.40200f*4096.0f+0.=
5f));
      __m128i cr_const1 =3D _mm_set1_epi16( - (short) ( 0.71414f*4096.0f+0.=
5f));
      __m128i cb_const0 =3D _mm_set1_epi16( - (short) ( 0.34414f*4096.0f+0.=
5f));
      __m128i cb_const1 =3D _mm_set1_epi16(   (short) ( 1.77200f*4096.0f+0.=
5f));
      __m128i y_bias =3D _mm_set1_epi8((char) (unsigned char) 128);
      __m128i xw =3D _mm_set1_epi16(255); // alpha channel

      for (; i+7 &lt; count; i +=3D 8) {
         // load
         __m128i y_bytes =3D _mm_loadl_epi64((__m128i *) (y+i));
         __m128i cr_bytes =3D _mm_loadl_epi64((__m128i *) (pcr+i));
         __m128i cb_bytes =3D _mm_loadl_epi64((__m128i *) (pcb+i));
         __m128i cr_biased =3D _mm_xor_si128(cr_bytes, signflip); // -128
         __m128i cb_biased =3D _mm_xor_si128(cb_bytes, signflip); // -128

         // unpack to short (and left-shift cr, cb by 8)
         __m128i yw  =3D _mm_unpacklo_epi8(y_bias, y_bytes);
         __m128i crw =3D _mm_unpacklo_epi8(_mm_setzero_si128(), cr_biased);
         __m128i cbw =3D _mm_unpacklo_epi8(_mm_setzero_si128(), cb_biased);

         // color transform
         __m128i yws =3D _mm_srli_epi16(yw, 4);
         __m128i cr0 =3D _mm_mulhi_epi16(cr_const0, crw);
         __m128i cb0 =3D _mm_mulhi_epi16(cb_const0, cbw);
         __m128i cb1 =3D _mm_mulhi_epi16(cbw, cb_const1);
         __m128i cr1 =3D _mm_mulhi_epi16(crw, cr_const1);
         __m128i rws =3D _mm_add_epi16(cr0, yws);
         __m128i gwt =3D _mm_add_epi16(cb0, yws);
         __m128i bws =3D _mm_add_epi16(yws, cb1);
         __m128i gws =3D _mm_add_epi16(gwt, cr1);

         // descale
         __m128i rw =3D _mm_srai_epi16(rws, 4);
         __m128i bw =3D _mm_srai_epi16(bws, 4);
         __m128i gw =3D _mm_srai_epi16(gws, 4);

         // back to byte, set up for transpose
         __m128i brb =3D _mm_packus_epi16(rw, bw);
         __m128i gxb =3D _mm_packus_epi16(gw, xw);

         // transpose to interleave channels
         __m128i t0 =3D _mm_unpacklo_epi8(brb, gxb);
         __m128i t1 =3D _mm_unpackhi_epi8(brb, gxb);
         __m128i o0 =3D _mm_unpacklo_epi16(t0, t1);
         __m128i o1 =3D _mm_unpackhi_epi16(t0, t1);

         // store
         _mm_storeu_si128((__m128i *) (out + 0), o0);
         _mm_storeu_si128((__m128i *) (out + 16), o1);
         out +=3D 32;
      }
   }
#endif

#ifdef STBI_NEON
   // in this version, step=3D3 support would be easy to add. but is there =
demand?
   if (step =3D=3D 4) {
      // this is a fairly straightforward implementation and not super-opti=
mized.
      uint8x8_t signflip =3D vdup_n_u8(0x80);
      int16x8_t cr_const0 =3D vdupq_n_s16(   (short) ( 1.40200f*4096.0f+0.5=
f));
      int16x8_t cr_const1 =3D vdupq_n_s16( - (short) ( 0.71414f*4096.0f+0.5=
f));
      int16x8_t cb_const0 =3D vdupq_n_s16( - (short) ( 0.34414f*4096.0f+0.5=
f));
      int16x8_t cb_const1 =3D vdupq_n_s16(   (short) ( 1.77200f*4096.0f+0.5=
f));

      for (; i+7 &lt; count; i +=3D 8) {
         // load
         uint8x8_t y_bytes  =3D vld1_u8(y + i);
         uint8x8_t cr_bytes =3D vld1_u8(pcr + i);
         uint8x8_t cb_bytes =3D vld1_u8(pcb + i);
         int8x8_t cr_biased =3D vreinterpret_s8_u8(vsub_u8(cr_bytes, signfl=
ip));
         int8x8_t cb_biased =3D vreinterpret_s8_u8(vsub_u8(cb_bytes, signfl=
ip));

         // expand to s16
         int16x8_t yws =3D vreinterpretq_s16_u16(vshll_n_u8(y_bytes, 4));
         int16x8_t crw =3D vshll_n_s8(cr_biased, 7);
         int16x8_t cbw =3D vshll_n_s8(cb_biased, 7);

         // color transform
         int16x8_t cr0 =3D vqdmulhq_s16(crw, cr_const0);
         int16x8_t cb0 =3D vqdmulhq_s16(cbw, cb_const0);
         int16x8_t cr1 =3D vqdmulhq_s16(crw, cr_const1);
         int16x8_t cb1 =3D vqdmulhq_s16(cbw, cb_const1);
         int16x8_t rws =3D vaddq_s16(yws, cr0);
         int16x8_t gws =3D vaddq_s16(vaddq_s16(yws, cb0), cr1);
         int16x8_t bws =3D vaddq_s16(yws, cb1);

         // undo scaling, round, convert to byte
         uint8x8x4_t o;
         o.val[0] =3D vqrshrun_n_s16(rws, 4);
         o.val[1] =3D vqrshrun_n_s16(gws, 4);
         o.val[2] =3D vqrshrun_n_s16(bws, 4);
         o.val[3] =3D vdup_n_u8(255);

         // store, interleaving r/g/b/a
         vst4_u8(out, o);
         out +=3D 8*4;
      }
   }
#endif

   for (; i &lt; count; ++i) {
      int y_fixed =3D (y[i] &lt;&lt; 20) + (1&lt;&lt;19); // rounding
      int r,g,b;
      int cr =3D pcr[i] - 128;
      int cb =3D pcb[i] - 128;
      r =3D y_fixed + cr* stbi__float2fixed(1.40200f);
      g =3D y_fixed + cr*-stbi__float2fixed(0.71414f) + ((cb*-stbi__float2f=
ixed(0.34414f)) &amp; 0xffff0000);
      b =3D y_fixed                                   +   cb* stbi__float2f=
ixed(1.77200f);
      r &gt;&gt;=3D 20;
      g &gt;&gt;=3D 20;
      b &gt;&gt;=3D 20;
      if ((unsigned) r &gt; 255) { if (r &lt; 0) r =3D 0; else r =3D 255; }
      if ((unsigned) g &gt; 255) { if (g &lt; 0) g =3D 0; else g =3D 255; }
      if ((unsigned) b &gt; 255) { if (b &lt; 0) b =3D 0; else b =3D 255; }
      out[0] =3D (stbi_uc)r;
      out[1] =3D (stbi_uc)g;
      out[2] =3D (stbi_uc)b;
      out[3] =3D 255;
      out +=3D step;
   }
}
#endif

// set up the kernels
static void stbi__setup_jpeg(stbi__jpeg *j)
{
   j-&gt;idct_block_kernel =3D stbi__idct_block;
   j-&gt;YCbCr_to_RGB_kernel =3D stbi__YCbCr_to_RGB_row;
   j-&gt;resample_row_hv_2_kernel =3D stbi__resample_row_hv_2;

#ifdef STBI_SSE2
   if (stbi__sse2_available()) {
      j-&gt;idct_block_kernel =3D stbi__idct_simd;
      j-&gt;YCbCr_to_RGB_kernel =3D stbi__YCbCr_to_RGB_simd;
      j-&gt;resample_row_hv_2_kernel =3D stbi__resample_row_hv_2_simd;
   }
#endif

#ifdef STBI_NEON
   j-&gt;idct_block_kernel =3D stbi__idct_simd;
   j-&gt;YCbCr_to_RGB_kernel =3D stbi__YCbCr_to_RGB_simd;
   j-&gt;resample_row_hv_2_kernel =3D stbi__resample_row_hv_2_simd;
#endif
}

// clean up the temporary component buffers
static void stbi__cleanup_jpeg(stbi__jpeg *j)
{
   stbi__free_jpeg_components(j, j-&gt;s-&gt;img_n, 0);
}

typedef struct
{
   resample_row_func resample;
   stbi_uc *line0,*line1;
   int hs,vs;   // expansion factor in each axis
   int w_lores; // horizontal pixels pre-expansion
   int ystep;   // how far through vertical expansion we are
   int ypos;    // which pre-expansion row we're on
} stbi__resample;

// fast 0..255 * 0..255 =3D&gt; 0..255 rounded multiplication
static stbi_uc stbi__blinn_8x8(stbi_uc x, stbi_uc y)
{
   unsigned int t =3D x*y + 128;
   return (stbi_uc) ((t + (t &gt;&gt;8)) &gt;&gt; 8);
}

static stbi_uc *load_jpeg_image(stbi__jpeg *z, int *out_x, int *out_y, int =
*comp, int req_comp)
{
   int n, decode_n, is_rgb;
   z-&gt;s-&gt;img_n =3D 0; // make stbi__cleanup_jpeg safe

   // validate req_comp
   if (req_comp &lt; 0 || req_comp &gt; 4) return stbi__errpuc("bad req_com=
p", "Internal error");

   // load a jpeg image from whichever source, but leave in YCbCr format
   if (!stbi__decode_jpeg_image(z)) { stbi__cleanup_jpeg(z); return NULL; }

   // determine actual number of components to generate
   n =3D req_comp ? req_comp : z-&gt;s-&gt;img_n &gt;=3D 3 ? 3 : 1;

   is_rgb =3D z-&gt;s-&gt;img_n =3D=3D 3 &amp;&amp; (z-&gt;rgb =3D=3D 3 || =
(z-&gt;app14_color_transform =3D=3D 0 &amp;&amp; !z-&gt;jfif));

   if (z-&gt;s-&gt;img_n =3D=3D 3 &amp;&amp; n &lt; 3 &amp;&amp; !is_rgb)
      decode_n =3D 1;
   else
      decode_n =3D z-&gt;s-&gt;img_n;

   // resample and color-convert
   {
      int k;
      unsigned int i,j;
      stbi_uc *output;
      stbi_uc *coutput[4] =3D { NULL, NULL, NULL, NULL };

      stbi__resample res_comp[4];

      for (k=3D0; k &lt; decode_n; ++k) {
         stbi__resample *r =3D &amp;res_comp[k];

         // allocate line buffer big enough for upsampling off the edges
         // with upsample factor of 4
         z-&gt;img_comp[k].linebuf =3D (stbi_uc *) stbi__malloc(z-&gt;s-&gt=
;img_x + 3);
         if (!z-&gt;img_comp[k].linebuf) { stbi__cleanup_jpeg(z); return st=
bi__errpuc("outofmem", "Out of memory"); }

         r-&gt;hs      =3D z-&gt;img_h_max / z-&gt;img_comp[k].h;
         r-&gt;vs      =3D z-&gt;img_v_max / z-&gt;img_comp[k].v;
         r-&gt;ystep   =3D r-&gt;vs &gt;&gt; 1;
         r-&gt;w_lores =3D (z-&gt;s-&gt;img_x + r-&gt;hs-1) / r-&gt;hs;
         r-&gt;ypos    =3D 0;
         r-&gt;line0   =3D r-&gt;line1 =3D z-&gt;img_comp[k].data;

         if      (r-&gt;hs =3D=3D 1 &amp;&amp; r-&gt;vs =3D=3D 1) r-&gt;res=
ample =3D resample_row_1;
         else if (r-&gt;hs =3D=3D 1 &amp;&amp; r-&gt;vs =3D=3D 2) r-&gt;res=
ample =3D stbi__resample_row_v_2;
         else if (r-&gt;hs =3D=3D 2 &amp;&amp; r-&gt;vs =3D=3D 1) r-&gt;res=
ample =3D stbi__resample_row_h_2;
         else if (r-&gt;hs =3D=3D 2 &amp;&amp; r-&gt;vs =3D=3D 2) r-&gt;res=
ample =3D z-&gt;resample_row_hv_2_kernel;
         else                               r-&gt;resample =3D stbi__resamp=
le_row_generic;
      }

      // can't error after this so, this is safe
      output =3D (stbi_uc *) stbi__malloc_mad3(n, z-&gt;s-&gt;img_x, z-&gt;=
s-&gt;img_y, 1);
      if (!output) { stbi__cleanup_jpeg(z); return stbi__errpuc("outofmem",=
 "Out of memory"); }

      // now go ahead and resample
      for (j=3D0; j &lt; z-&gt;s-&gt;img_y; ++j) {
         stbi_uc *out =3D output + n * z-&gt;s-&gt;img_x * j;
         for (k=3D0; k &lt; decode_n; ++k) {
            stbi__resample *r =3D &amp;res_comp[k];
            int y_bot =3D r-&gt;ystep &gt;=3D (r-&gt;vs &gt;&gt; 1);
            coutput[k] =3D r-&gt;resample(z-&gt;img_comp[k].linebuf,
                                     y_bot ? r-&gt;line1 : r-&gt;line0,
                                     y_bot ? r-&gt;line0 : r-&gt;line1,
                                     r-&gt;w_lores, r-&gt;hs);
            if (++r-&gt;ystep &gt;=3D r-&gt;vs) {
               r-&gt;ystep =3D 0;
               r-&gt;line0 =3D r-&gt;line1;
               if (++r-&gt;ypos &lt; z-&gt;img_comp[k].y)
                  r-&gt;line1 +=3D z-&gt;img_comp[k].w2;
            }
         }
         if (n &gt;=3D 3) {
            stbi_uc *y =3D coutput[0];
            if (z-&gt;s-&gt;img_n =3D=3D 3) {
               if (is_rgb) {
                  for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) {
                     out[0] =3D y[i];
                     out[1] =3D coutput[1][i];
                     out[2] =3D coutput[2][i];
                     out[3] =3D 255;
                     out +=3D n;
                  }
               } else {
                  z-&gt;YCbCr_to_RGB_kernel(out, y, coutput[1], coutput[2],=
 z-&gt;s-&gt;img_x, n);
               }
            } else if (z-&gt;s-&gt;img_n =3D=3D 4) {
               if (z-&gt;app14_color_transform =3D=3D 0) { // CMYK
                  for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) {
                     stbi_uc m =3D coutput[3][i];
                     out[0] =3D stbi__blinn_8x8(coutput[0][i], m);
                     out[1] =3D stbi__blinn_8x8(coutput[1][i], m);
                     out[2] =3D stbi__blinn_8x8(coutput[2][i], m);
                     out[3] =3D 255;
                     out +=3D n;
                  }
               } else if (z-&gt;app14_color_transform =3D=3D 2) { // YCCK
                  z-&gt;YCbCr_to_RGB_kernel(out, y, coutput[1], coutput[2],=
 z-&gt;s-&gt;img_x, n);
                  for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) {
                     stbi_uc m =3D coutput[3][i];
                     out[0] =3D stbi__blinn_8x8(255 - out[0], m);
                     out[1] =3D stbi__blinn_8x8(255 - out[1], m);
                     out[2] =3D stbi__blinn_8x8(255 - out[2], m);
                     out +=3D n;
                  }
               } else { // YCbCr + alpha?  Ignore the fourth channel for no=
w
                  z-&gt;YCbCr_to_RGB_kernel(out, y, coutput[1], coutput[2],=
 z-&gt;s-&gt;img_x, n);
               }
            } else
               for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) {
                  out[0] =3D out[1] =3D out[2] =3D y[i];
                  out[3] =3D 255; // not used if n=3D=3D3
                  out +=3D n;
               }
         } else {
            if (is_rgb) {
               if (n =3D=3D 1)
                  for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i)
                     *out++ =3D stbi__compute_y(coutput[0][i], coutput[1][i=
], coutput[2][i]);
               else {
                  for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i, out +=3D 2) {
                     out[0] =3D stbi__compute_y(coutput[0][i], coutput[1][i=
], coutput[2][i]);
                     out[1] =3D 255;
                  }
               }
            } else if (z-&gt;s-&gt;img_n =3D=3D 4 &amp;&amp; z-&gt;app14_co=
lor_transform =3D=3D 0) {
               for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) {
                  stbi_uc m =3D coutput[3][i];
                  stbi_uc r =3D stbi__blinn_8x8(coutput[0][i], m);
                  stbi_uc g =3D stbi__blinn_8x8(coutput[1][i], m);
                  stbi_uc b =3D stbi__blinn_8x8(coutput[2][i], m);
                  out[0] =3D stbi__compute_y(r, g, b);
                  out[1] =3D 255;
                  out +=3D n;
               }
            } else if (z-&gt;s-&gt;img_n =3D=3D 4 &amp;&amp; z-&gt;app14_co=
lor_transform =3D=3D 2) {
               for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) {
                  out[0] =3D stbi__blinn_8x8(255 - coutput[0][i], coutput[3=
][i]);
                  out[1] =3D 255;
                  out +=3D n;
               }
            } else {
               stbi_uc *y =3D coutput[0];
               if (n =3D=3D 1)
                  for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) out[i] =3D y[i=
];
               else
                  for (i=3D0; i &lt; z-&gt;s-&gt;img_x; ++i) { *out++ =3D y=
[i]; *out++ =3D 255; }
            }
         }
      }
      stbi__cleanup_jpeg(z);
      *out_x =3D z-&gt;s-&gt;img_x;
      *out_y =3D z-&gt;s-&gt;img_y;
      if (comp) *comp =3D z-&gt;s-&gt;img_n &gt;=3D 3 ? 3 : 1; // report or=
iginal components, not output
      return output;
   }
}

static void *stbi__jpeg_load(stbi__context *s, int *x, int *y, int *comp, i=
nt req_comp, stbi__result_info *ri)
{
   unsigned char* result;
   stbi__jpeg* j =3D (stbi__jpeg*) stbi__malloc(sizeof(stbi__jpeg));
   STBI_NOTUSED(ri);
   j-&gt;s =3D s;
   stbi__setup_jpeg(j);
   result =3D load_jpeg_image(j, x,y,comp,req_comp);
   STBI_FREE(j);
   return result;
}

static int stbi__jpeg_test(stbi__context *s)
{
   int r;
   stbi__jpeg* j =3D (stbi__jpeg*)stbi__malloc(sizeof(stbi__jpeg));
   j-&gt;s =3D s;
   stbi__setup_jpeg(j);
   r =3D stbi__decode_jpeg_header(j, STBI__SCAN_type);
   stbi__rewind(s);
   STBI_FREE(j);
   return r;
}

static int stbi__jpeg_info_raw(stbi__jpeg *j, int *x, int *y, int *comp)
{
   if (!stbi__decode_jpeg_header(j, STBI__SCAN_header)) {
      stbi__rewind( j-&gt;s );
      return 0;
   }
   if (x) *x =3D j-&gt;s-&gt;img_x;
   if (y) *y =3D j-&gt;s-&gt;img_y;
   if (comp) *comp =3D j-&gt;s-&gt;img_n &gt;=3D 3 ? 3 : 1;
   return 1;
}

static int stbi__jpeg_info(stbi__context *s, int *x, int *y, int *comp)
{
   int result;
   stbi__jpeg* j =3D (stbi__jpeg*) (stbi__malloc(sizeof(stbi__jpeg)));
   j-&gt;s =3D s;
   result =3D stbi__jpeg_info_raw(j, x, y, comp);
   STBI_FREE(j);
   return result;
}
#endif

// public domain zlib decode    v0.2  Sean Barrett 2006-11-18
//    simple implementation
//      - all input must be provided in an upfront buffer
//      - all output is written to a single output buffer (can malloc/reall=
oc)
//    performance
//      - fast huffman

#ifndef STBI_NO_ZLIB

// fast-way is faster to check than jpeg huffman, but slow way is slower
#define STBI__ZFAST_BITS  9 // accelerate all cases in default tables
#define STBI__ZFAST_MASK  ((1 &lt;&lt; STBI__ZFAST_BITS) - 1)

// zlib-style huffman encoding
// (jpegs packs from left, zlib from right, so can't share code)
typedef struct
{
   stbi__uint16 fast[1 &lt;&lt; STBI__ZFAST_BITS];
   stbi__uint16 firstcode[16];
   int maxcode[17];
   stbi__uint16 firstsymbol[16];
   stbi_uc  size[288];
   stbi__uint16 value[288];
} stbi__zhuffman;

stbi_inline static int stbi__bitreverse16(int n)
{
  n =3D ((n &amp; 0xAAAA) &gt;&gt;  1) | ((n &amp; 0x5555) &lt;&lt; 1);
  n =3D ((n &amp; 0xCCCC) &gt;&gt;  2) | ((n &amp; 0x3333) &lt;&lt; 2);
  n =3D ((n &amp; 0xF0F0) &gt;&gt;  4) | ((n &amp; 0x0F0F) &lt;&lt; 4);
  n =3D ((n &amp; 0xFF00) &gt;&gt;  8) | ((n &amp; 0x00FF) &lt;&lt; 8);
  return n;
}

stbi_inline static int stbi__bit_reverse(int v, int bits)
{
   STBI_ASSERT(bits &lt;=3D 16);
   // to bit reverse n bits, reverse 16 and shift
   // e.g. 11 bits, bit reverse and shift away 5
   return stbi__bitreverse16(v) &gt;&gt; (16-bits);
}

static int stbi__zbuild_huffman(stbi__zhuffman *z, const stbi_uc *sizelist,=
 int num)
{
   int i,k=3D0;
   int code, next_code[16], sizes[17];

   // DEFLATE spec for generating codes
   memset(sizes, 0, sizeof(sizes));
   memset(z-&gt;fast, 0, sizeof(z-&gt;fast));
   for (i=3D0; i &lt; num; ++i)
      ++sizes[sizelist[i]];
   sizes[0] =3D 0;
   for (i=3D1; i &lt; 16; ++i)
      if (sizes[i] &gt; (1 &lt;&lt; i))
         return stbi__err("bad sizes", "Corrupt PNG");
   code =3D 0;
   for (i=3D1; i &lt; 16; ++i) {
      next_code[i] =3D code;
      z-&gt;firstcode[i] =3D (stbi__uint16) code;
      z-&gt;firstsymbol[i] =3D (stbi__uint16) k;
      code =3D (code + sizes[i]);
      if (sizes[i])
         if (code-1 &gt;=3D (1 &lt;&lt; i)) return stbi__err("bad codelengt=
hs","Corrupt PNG");
      z-&gt;maxcode[i] =3D code &lt;&lt; (16-i); // preshift for inner loop
      code &lt;&lt;=3D 1;
      k +=3D sizes[i];
   }
   z-&gt;maxcode[16] =3D 0x10000; // sentinel
   for (i=3D0; i &lt; num; ++i) {
      int s =3D sizelist[i];
      if (s) {
         int c =3D next_code[s] - z-&gt;firstcode[s] + z-&gt;firstsymbol[s]=
;
         stbi__uint16 fastv =3D (stbi__uint16) ((s &lt;&lt; 9) | i);
         z-&gt;size [c] =3D (stbi_uc     ) s;
         z-&gt;value[c] =3D (stbi__uint16) i;
         if (s &lt;=3D STBI__ZFAST_BITS) {
            int j =3D stbi__bit_reverse(next_code[s],s);
            while (j &lt; (1 &lt;&lt; STBI__ZFAST_BITS)) {
               z-&gt;fast[j] =3D fastv;
               j +=3D (1 &lt;&lt; s);
            }
         }
         ++next_code[s];
      }
   }
   return 1;
}

// zlib-from-memory implementation for PNG reading
//    because PNG allows splitting the zlib stream arbitrarily,
//    and it's annoying structurally to have PNG call ZLIB call PNG,
//    we require PNG read all the IDATs and combine them into a single
//    memory buffer

typedef struct
{
   stbi_uc *zbuffer, *zbuffer_end;
   int num_bits;
   stbi__uint32 code_buffer;

   char *zout;
   char *zout_start;
   char *zout_end;
   int   z_expandable;

   stbi__zhuffman z_length, z_distance;
} stbi__zbuf;

stbi_inline static stbi_uc stbi__zget8(stbi__zbuf *z)
{
   if (z-&gt;zbuffer &gt;=3D z-&gt;zbuffer_end) return 0;
   return *z-&gt;zbuffer++;
}

static void stbi__fill_bits(stbi__zbuf *z)
{
   do {
      STBI_ASSERT(z-&gt;code_buffer &lt; (1U &lt;&lt; z-&gt;num_bits));
      z-&gt;code_buffer |=3D (unsigned int) stbi__zget8(z) &lt;&lt; z-&gt;n=
um_bits;
      z-&gt;num_bits +=3D 8;
   } while (z-&gt;num_bits &lt;=3D 24);
}

stbi_inline static unsigned int stbi__zreceive(stbi__zbuf *z, int n)
{
   unsigned int k;
   if (z-&gt;num_bits &lt; n) stbi__fill_bits(z);
   k =3D z-&gt;code_buffer &amp; ((1 &lt;&lt; n) - 1);
   z-&gt;code_buffer &gt;&gt;=3D n;
   z-&gt;num_bits -=3D n;
   return k;
}

static int stbi__zhuffman_decode_slowpath(stbi__zbuf *a, stbi__zhuffman *z)
{
   int b,s,k;
   // not resolved by fast table, so compute it the slow way
   // use jpeg approach, which requires MSbits at top
   k =3D stbi__bit_reverse(a-&gt;code_buffer, 16);
   for (s=3DSTBI__ZFAST_BITS+1; ; ++s)
      if (k &lt; z-&gt;maxcode[s])
         break;
   if (s =3D=3D 16) return -1; // invalid code!
   // code size is s, so:
   b =3D (k &gt;&gt; (16-s)) - z-&gt;firstcode[s] + z-&gt;firstsymbol[s];
   STBI_ASSERT(z-&gt;size[b] =3D=3D s);
   a-&gt;code_buffer &gt;&gt;=3D s;
   a-&gt;num_bits -=3D s;
   return z-&gt;value[b];
}

stbi_inline static int stbi__zhuffman_decode(stbi__zbuf *a, stbi__zhuffman =
*z)
{
   int b,s;
   if (a-&gt;num_bits &lt; 16) stbi__fill_bits(a);
   b =3D z-&gt;fast[a-&gt;code_buffer &amp; STBI__ZFAST_MASK];
   if (b) {
      s =3D b &gt;&gt; 9;
      a-&gt;code_buffer &gt;&gt;=3D s;
      a-&gt;num_bits -=3D s;
      return b &amp; 511;
   }
   return stbi__zhuffman_decode_slowpath(a, z);
}

static int stbi__zexpand(stbi__zbuf *z, char *zout, int n)  // need to make=
 room for n bytes
{
   char *q;
   int cur, limit, old_limit;
   z-&gt;zout =3D zout;
   if (!z-&gt;z_expandable) return stbi__err("output buffer limit","Corrupt=
 PNG");
   cur   =3D (int) (z-&gt;zout     - z-&gt;zout_start);
   limit =3D old_limit =3D (int) (z-&gt;zout_end - z-&gt;zout_start);
   while (cur + n &gt; limit)
      limit *=3D 2;
   q =3D (char *) STBI_REALLOC_SIZED(z-&gt;zout_start, old_limit, limit);
   STBI_NOTUSED(old_limit);
   if (q =3D=3D NULL) return stbi__err("outofmem", "Out of memory");
   z-&gt;zout_start =3D q;
   z-&gt;zout       =3D q + cur;
   z-&gt;zout_end   =3D q + limit;
   return 1;
}

static const int stbi__zlength_base[31] =3D {
   3,4,5,6,7,8,9,10,11,13,
   15,17,19,23,27,31,35,43,51,59,
   67,83,99,115,131,163,195,227,258,0,0 };

static const int stbi__zlength_extra[31]=3D
{ 0,0,0,0,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,0,0,0 };

static const int stbi__zdist_base[32] =3D { 1,2,3,4,5,7,9,13,17,25,33,49,65=
,97,129,193,
257,385,513,769,1025,1537,2049,3073,4097,6145,8193,12289,16385,24577,0,0};

static const int stbi__zdist_extra[32] =3D
{ 0,0,0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13};

static int stbi__parse_huffman_block(stbi__zbuf *a)
{
   char *zout =3D a-&gt;zout;
   for(;;) {
      int z =3D stbi__zhuffman_decode(a, &amp;a-&gt;z_length);
      if (z &lt; 256) {
         if (z &lt; 0) return stbi__err("bad huffman code","Corrupt PNG"); =
// error in huffman codes
         if (zout &gt;=3D a-&gt;zout_end) {
            if (!stbi__zexpand(a, zout, 1)) return 0;
            zout =3D a-&gt;zout;
         }
         *zout++ =3D (char) z;
      } else {
         stbi_uc *p;
         int len,dist;
         if (z =3D=3D 256) {
            a-&gt;zout =3D zout;
            return 1;
         }
         z -=3D 257;
         len =3D stbi__zlength_base[z];
         if (stbi__zlength_extra[z]) len +=3D stbi__zreceive(a, stbi__zleng=
th_extra[z]);
         z =3D stbi__zhuffman_decode(a, &amp;a-&gt;z_distance);
         if (z &lt; 0) return stbi__err("bad huffman code","Corrupt PNG");
         dist =3D stbi__zdist_base[z];
         if (stbi__zdist_extra[z]) dist +=3D stbi__zreceive(a, stbi__zdist_=
extra[z]);
         if (zout - a-&gt;zout_start &lt; dist) return stbi__err("bad dist"=
,"Corrupt PNG");
         if (zout + len &gt; a-&gt;zout_end) {
            if (!stbi__zexpand(a, zout, len)) return 0;
            zout =3D a-&gt;zout;
         }
         p =3D (stbi_uc *) (zout - dist);
         if (dist =3D=3D 1) { // run of one byte; common in images.
            stbi_uc v =3D *p;
            if (len) { do *zout++ =3D v; while (--len); }
         } else {
            if (len) { do *zout++ =3D *p++; while (--len); }
         }
      }
   }
}

static int stbi__compute_huffman_codes(stbi__zbuf *a)
{
   static const stbi_uc length_dezigzag[19] =3D { 16,17,18,0,8,7,9,6,10,5,1=
1,4,12,3,13,2,14,1,15 };
   stbi__zhuffman z_codelength;
   stbi_uc lencodes[286+32+137];//padding for maximum single op
   stbi_uc codelength_sizes[19];
   int i,n;

   int hlit  =3D stbi__zreceive(a,5) + 257;
   int hdist =3D stbi__zreceive(a,5) + 1;
   int hclen =3D stbi__zreceive(a,4) + 4;
   int ntot  =3D hlit + hdist;

   memset(codelength_sizes, 0, sizeof(codelength_sizes));
   for (i=3D0; i &lt; hclen; ++i) {
      int s =3D stbi__zreceive(a,3);
      codelength_sizes[length_dezigzag[i]] =3D (stbi_uc) s;
   }
   if (!stbi__zbuild_huffman(&amp;z_codelength, codelength_sizes, 19)) retu=
rn 0;

   n =3D 0;
   while (n &lt; ntot) {
      int c =3D stbi__zhuffman_decode(a, &amp;z_codelength);
      if (c &lt; 0 || c &gt;=3D 19) return stbi__err("bad codelengths", "Co=
rrupt PNG");
      if (c &lt; 16)
         lencodes[n++] =3D (stbi_uc) c;
      else {
         stbi_uc fill =3D 0;
         if (c =3D=3D 16) {
            c =3D stbi__zreceive(a,2)+3;
            if (n =3D=3D 0) return stbi__err("bad codelengths", "Corrupt PN=
G");
            fill =3D lencodes[n-1];
         } else if (c =3D=3D 17)
            c =3D stbi__zreceive(a,3)+3;
         else {
            STBI_ASSERT(c =3D=3D 18);
            c =3D stbi__zreceive(a,7)+11;
         }
         if (ntot - n &lt; c) return stbi__err("bad codelengths", "Corrupt =
PNG");
         memset(lencodes+n, fill, c);
         n +=3D c;
      }
   }
   if (n !=3D ntot) return stbi__err("bad codelengths","Corrupt PNG");
   if (!stbi__zbuild_huffman(&amp;a-&gt;z_length, lencodes, hlit)) return 0=
;
   if (!stbi__zbuild_huffman(&amp;a-&gt;z_distance, lencodes+hlit, hdist)) =
return 0;
   return 1;
}

static int stbi__parse_uncompressed_block(stbi__zbuf *a)
{
   stbi_uc header[4];
   int len,nlen,k;
   if (a-&gt;num_bits &amp; 7)
      stbi__zreceive(a, a-&gt;num_bits &amp; 7); // discard
   // drain the bit-packed data into header
   k =3D 0;
   while (a-&gt;num_bits &gt; 0) {
      header[k++] =3D (stbi_uc) (a-&gt;code_buffer &amp; 255); // suppress =
MSVC run-time check
      a-&gt;code_buffer &gt;&gt;=3D 8;
      a-&gt;num_bits -=3D 8;
   }
   STBI_ASSERT(a-&gt;num_bits =3D=3D 0);
   // now fill header the normal way
   while (k &lt; 4)
      header[k++] =3D stbi__zget8(a);
   len  =3D header[1] * 256 + header[0];
   nlen =3D header[3] * 256 + header[2];
   if (nlen !=3D (len ^ 0xffff)) return stbi__err("zlib corrupt","Corrupt P=
NG");
   if (a-&gt;zbuffer + len &gt; a-&gt;zbuffer_end) return stbi__err("read p=
ast buffer","Corrupt PNG");
   if (a-&gt;zout + len &gt; a-&gt;zout_end)
      if (!stbi__zexpand(a, a-&gt;zout, len)) return 0;
   memcpy(a-&gt;zout, a-&gt;zbuffer, len);
   a-&gt;zbuffer +=3D len;
   a-&gt;zout +=3D len;
   return 1;
}

static int stbi__parse_zlib_header(stbi__zbuf *a)
{
   int cmf   =3D stbi__zget8(a);
   int cm    =3D cmf &amp; 15;
   /* int cinfo =3D cmf &gt;&gt; 4; */
   int flg   =3D stbi__zget8(a);
   if ((cmf*256+flg) % 31 !=3D 0) return stbi__err("bad zlib header","Corru=
pt PNG"); // zlib spec
   if (flg &amp; 32) return stbi__err("no preset dict","Corrupt PNG"); // p=
reset dictionary not allowed in png
   if (cm !=3D 8) return stbi__err("bad compression","Corrupt PNG"); // DEF=
LATE required for png
   // window =3D 1 &lt;&lt; (8 + cinfo)... but who cares, we fully buffer o=
utput
   return 1;
}

static const stbi_uc stbi__zdefault_length[288] =3D
{
   8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
   8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
   8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
   8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8, 8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
   8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8, 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
   9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
   9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
   9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9, 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,
   7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7, 7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8
};
static const stbi_uc stbi__zdefault_distance[32] =3D
{
   5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5
};
/*
Init algorithm:
{
   int i;   // use &lt;=3D to match clearly with spec
   for (i=3D0; i &lt;=3D 143; ++i)     stbi__zdefault_length[i]   =3D 8;
   for (   ; i &lt;=3D 255; ++i)     stbi__zdefault_length[i]   =3D 9;
   for (   ; i &lt;=3D 279; ++i)     stbi__zdefault_length[i]   =3D 7;
   for (   ; i &lt;=3D 287; ++i)     stbi__zdefault_length[i]   =3D 8;

   for (i=3D0; i &lt;=3D  31; ++i)     stbi__zdefault_distance[i] =3D 5;
}
*/

static int stbi__parse_zlib(stbi__zbuf *a, int parse_header)
{
   int final, type;
   if (parse_header)
      if (!stbi__parse_zlib_header(a)) return 0;
   a-&gt;num_bits =3D 0;
   a-&gt;code_buffer =3D 0;
   do {
      final =3D stbi__zreceive(a,1);
      type =3D stbi__zreceive(a,2);
      if (type =3D=3D 0) {
         if (!stbi__parse_uncompressed_block(a)) return 0;
      } else if (type =3D=3D 3) {
         return 0;
      } else {
         if (type =3D=3D 1) {
            // use fixed code lengths
            if (!stbi__zbuild_huffman(&amp;a-&gt;z_length  , stbi__zdefault=
_length  , 288)) return 0;
            if (!stbi__zbuild_huffman(&amp;a-&gt;z_distance, stbi__zdefault=
_distance,  32)) return 0;
         } else {
            if (!stbi__compute_huffman_codes(a)) return 0;
         }
         if (!stbi__parse_huffman_block(a)) return 0;
      }
   } while (!final);
   return 1;
}

static int stbi__do_zlib(stbi__zbuf *a, char *obuf, int olen, int exp, int =
parse_header)
{
   a-&gt;zout_start =3D obuf;
   a-&gt;zout       =3D obuf;
   a-&gt;zout_end   =3D obuf + olen;
   a-&gt;z_expandable =3D exp;

   return stbi__parse_zlib(a, parse_header);
}

STBIDEF char *stbi_zlib_decode_malloc_guesssize(const char *buffer, int len=
, int initial_size, int *outlen)
{
   stbi__zbuf a;
   char *p =3D (char *) stbi__malloc(initial_size);
   if (p =3D=3D NULL) return NULL;
   a.zbuffer =3D (stbi_uc *) buffer;
   a.zbuffer_end =3D (stbi_uc *) buffer + len;
   if (stbi__do_zlib(&amp;a, p, initial_size, 1, 1)) {
      if (outlen) *outlen =3D (int) (a.zout - a.zout_start);
      return a.zout_start;
   } else {
      STBI_FREE(a.zout_start);
      return NULL;
   }
}

STBIDEF char *stbi_zlib_decode_malloc(char const *buffer, int len, int *out=
len)
{
   return stbi_zlib_decode_malloc_guesssize(buffer, len, 16384, outlen);
}

STBIDEF char *stbi_zlib_decode_malloc_guesssize_headerflag(const char *buff=
er, int len, int initial_size, int *outlen, int parse_header)
{
   stbi__zbuf a;
   char *p =3D (char *) stbi__malloc(initial_size);
   if (p =3D=3D NULL) return NULL;
   a.zbuffer =3D (stbi_uc *) buffer;
   a.zbuffer_end =3D (stbi_uc *) buffer + len;
   if (stbi__do_zlib(&amp;a, p, initial_size, 1, parse_header)) {
      if (outlen) *outlen =3D (int) (a.zout - a.zout_start);
      return a.zout_start;
   } else {
      STBI_FREE(a.zout_start);
      return NULL;
   }
}

STBIDEF int stbi_zlib_decode_buffer(char *obuffer, int olen, char const *ib=
uffer, int ilen)
{
   stbi__zbuf a;
   a.zbuffer =3D (stbi_uc *) ibuffer;
   a.zbuffer_end =3D (stbi_uc *) ibuffer + ilen;
   if (stbi__do_zlib(&amp;a, obuffer, olen, 0, 1))
      return (int) (a.zout - a.zout_start);
   else
      return -1;
}

STBIDEF char *stbi_zlib_decode_noheader_malloc(char const *buffer, int len,=
 int *outlen)
{
   stbi__zbuf a;
   char *p =3D (char *) stbi__malloc(16384);
   if (p =3D=3D NULL) return NULL;
   a.zbuffer =3D (stbi_uc *) buffer;
   a.zbuffer_end =3D (stbi_uc *) buffer+len;
   if (stbi__do_zlib(&amp;a, p, 16384, 1, 0)) {
      if (outlen) *outlen =3D (int) (a.zout - a.zout_start);
      return a.zout_start;
   } else {
      STBI_FREE(a.zout_start);
      return NULL;
   }
}

STBIDEF int stbi_zlib_decode_noheader_buffer(char *obuffer, int olen, const=
 char *ibuffer, int ilen)
{
   stbi__zbuf a;
   a.zbuffer =3D (stbi_uc *) ibuffer;
   a.zbuffer_end =3D (stbi_uc *) ibuffer + ilen;
   if (stbi__do_zlib(&amp;a, obuffer, olen, 0, 0))
      return (int) (a.zout - a.zout_start);
   else
      return -1;
}
#endif

// public domain "baseline" PNG decoder   v0.10  Sean Barrett 2006-11-18
//    simple implementation
//      - only 8-bit samples
//      - no CRC checking
//      - allocates lots of intermediate memory
//        - avoids problem of streaming data between subsystems
//        - avoids explicit window management
//    performance
//      - uses stb_zlib, a PD zlib implementation with fast huffman decodin=
g

#ifndef STBI_NO_PNG
typedef struct
{
   stbi__uint32 length;
   stbi__uint32 type;
} stbi__pngchunk;

static stbi__pngchunk stbi__get_chunk_header(stbi__context *s)
{
   stbi__pngchunk c;
   c.length =3D stbi__get32be(s);
   c.type   =3D stbi__get32be(s);
   return c;
}

static int stbi__check_png_header(stbi__context *s)
{
   static const stbi_uc png_sig[8] =3D { 137,80,78,71,13,10,26,10 };
   int i;
   for (i=3D0; i &lt; 8; ++i)
      if (stbi__get8(s) !=3D png_sig[i]) return stbi__err("bad png sig","No=
t a PNG");
   return 1;
}

typedef struct
{
   stbi__context *s;
   stbi_uc *idata, *expanded, *out;
   int depth;
} stbi__png;


enum {
   STBI__F_none=3D0,
   STBI__F_sub=3D1,
   STBI__F_up=3D2,
   STBI__F_avg=3D3,
   STBI__F_paeth=3D4,
   // synthetic filters used for first scanline to avoid needing a dummy ro=
w of 0s
   STBI__F_avg_first,
   STBI__F_paeth_first
};

static stbi_uc first_row_filter[5] =3D
{
   STBI__F_none,
   STBI__F_sub,
   STBI__F_none,
   STBI__F_avg_first,
   STBI__F_paeth_first
};

static int stbi__paeth(int a, int b, int c)
{
   int p =3D a + b - c;
   int pa =3D abs(p-a);
   int pb =3D abs(p-b);
   int pc =3D abs(p-c);
   if (pa &lt;=3D pb &amp;&amp; pa &lt;=3D pc) return a;
   if (pb &lt;=3D pc) return b;
   return c;
}

static const stbi_uc stbi__depth_scale_table[9] =3D { 0, 0xff, 0x55, 0, 0x1=
1, 0,0,0, 0x01 };

// create the png data from post-deflated data
static int stbi__create_png_image_raw(stbi__png *a, stbi_uc *raw, stbi__uin=
t32 raw_len, int out_n, stbi__uint32 x, stbi__uint32 y, int depth, int colo=
r)
{
   int bytes =3D (depth =3D=3D 16? 2 : 1);
   stbi__context *s =3D a-&gt;s;
   stbi__uint32 i,j,stride =3D x*out_n*bytes;
   stbi__uint32 img_len, img_width_bytes;
   int k;
   int img_n =3D s-&gt;img_n; // copy it into a local for later

   int output_bytes =3D out_n*bytes;
   int filter_bytes =3D img_n*bytes;
   int width =3D x;

   STBI_ASSERT(out_n =3D=3D s-&gt;img_n || out_n =3D=3D s-&gt;img_n+1);
   a-&gt;out =3D (stbi_uc *) stbi__malloc_mad3(x, y, output_bytes, 0); // e=
xtra bytes to write off the end into
   if (!a-&gt;out) return stbi__err("outofmem", "Out of memory");

   if (!stbi__mad3sizes_valid(img_n, x, depth, 7)) return stbi__err("too la=
rge", "Corrupt PNG");
   img_width_bytes =3D (((img_n * x * depth) + 7) &gt;&gt; 3);
   img_len =3D (img_width_bytes + 1) * y;

   // we used to check for exact match between raw_len and img_len on non-i=
nterlaced PNGs,
   // but issue #276 reported a PNG in the wild that had extra data at the =
end (all zeros),
   // so just check for raw_len &lt; img_len always.
   if (raw_len &lt; img_len) return stbi__err("not enough pixels","Corrupt =
PNG");

   for (j=3D0; j &lt; y; ++j) {
      stbi_uc *cur =3D a-&gt;out + stride*j;
      stbi_uc *prior;
      int filter =3D *raw++;

      if (filter &gt; 4)
         return stbi__err("invalid filter","Corrupt PNG");

      if (depth &lt; 8) {
         STBI_ASSERT(img_width_bytes &lt;=3D x);
         cur +=3D x*out_n - img_width_bytes; // store output to the rightmo=
st img_len bytes, so we can decode in place
         filter_bytes =3D 1;
         width =3D img_width_bytes;
      }
      prior =3D cur - stride; // bugfix: need to compute this after 'cur +=
=3D' computation above

      // if first row, use special filter that doesn't sample previous row
      if (j =3D=3D 0) filter =3D first_row_filter[filter];

      // handle first byte explicitly
      for (k=3D0; k &lt; filter_bytes; ++k) {
         switch (filter) {
            case STBI__F_none       : cur[k] =3D raw[k]; break;
            case STBI__F_sub        : cur[k] =3D raw[k]; break;
            case STBI__F_up         : cur[k] =3D STBI__BYTECAST(raw[k] + pr=
ior[k]); break;
            case STBI__F_avg        : cur[k] =3D STBI__BYTECAST(raw[k] + (p=
rior[k]&gt;&gt;1)); break;
            case STBI__F_paeth      : cur[k] =3D STBI__BYTECAST(raw[k] + st=
bi__paeth(0,prior[k],0)); break;
            case STBI__F_avg_first  : cur[k] =3D raw[k]; break;
            case STBI__F_paeth_first: cur[k] =3D raw[k]; break;
         }
      }

      if (depth =3D=3D 8) {
         if (img_n !=3D out_n)
            cur[img_n] =3D 255; // first pixel
         raw +=3D img_n;
         cur +=3D out_n;
         prior +=3D out_n;
      } else if (depth =3D=3D 16) {
         if (img_n !=3D out_n) {
            cur[filter_bytes]   =3D 255; // first pixel top byte
            cur[filter_bytes+1] =3D 255; // first pixel bottom byte
         }
         raw +=3D filter_bytes;
         cur +=3D output_bytes;
         prior +=3D output_bytes;
      } else {
         raw +=3D 1;
         cur +=3D 1;
         prior +=3D 1;
      }

      // this is a little gross, so that we don't switch per-pixel or per-c=
omponent
      if (depth &lt; 8 || img_n =3D=3D out_n) {
         int nk =3D (width - 1)*filter_bytes;
         #define STBI__CASE(f) \
             case f:     \
                for (k=3D0; k &lt; nk; ++k)
         switch (filter) {
            // "none" filter turns into a memcpy here; make that explicit.
            case STBI__F_none:         memcpy(cur, raw, nk); break;
            STBI__CASE(STBI__F_sub)          { cur[k] =3D STBI__BYTECAST(ra=
w[k] + cur[k-filter_bytes]); } break;
            STBI__CASE(STBI__F_up)           { cur[k] =3D STBI__BYTECAST(ra=
w[k] + prior[k]); } break;
            STBI__CASE(STBI__F_avg)          { cur[k] =3D STBI__BYTECAST(ra=
w[k] + ((prior[k] + cur[k-filter_bytes])&gt;&gt;1)); } break;
            STBI__CASE(STBI__F_paeth)        { cur[k] =3D STBI__BYTECAST(ra=
w[k] + stbi__paeth(cur[k-filter_bytes],prior[k],prior[k-filter_bytes])); } =
break;
            STBI__CASE(STBI__F_avg_first)    { cur[k] =3D STBI__BYTECAST(ra=
w[k] + (cur[k-filter_bytes] &gt;&gt; 1)); } break;
            STBI__CASE(STBI__F_paeth_first)  { cur[k] =3D STBI__BYTECAST(ra=
w[k] + stbi__paeth(cur[k-filter_bytes],0,0)); } break;
         }
         #undef STBI__CASE
         raw +=3D nk;
      } else {
         STBI_ASSERT(img_n+1 =3D=3D out_n);
         #define STBI__CASE(f) \
             case f:     \
                for (i=3Dx-1; i &gt;=3D 1; --i, cur[filter_bytes]=3D255,raw=
+=3Dfilter_bytes,cur+=3Doutput_bytes,prior+=3Doutput_bytes) \
                   for (k=3D0; k &lt; filter_bytes; ++k)
         switch (filter) {
            STBI__CASE(STBI__F_none)         { cur[k] =3D raw[k]; } break;
            STBI__CASE(STBI__F_sub)          { cur[k] =3D STBI__BYTECAST(ra=
w[k] + cur[k- output_bytes]); } break;
            STBI__CASE(STBI__F_up)           { cur[k] =3D STBI__BYTECAST(ra=
w[k] + prior[k]); } break;
            STBI__CASE(STBI__F_avg)          { cur[k] =3D STBI__BYTECAST(ra=
w[k] + ((prior[k] + cur[k- output_bytes])&gt;&gt;1)); } break;
            STBI__CASE(STBI__F_paeth)        { cur[k] =3D STBI__BYTECAST(ra=
w[k] + stbi__paeth(cur[k- output_bytes],prior[k],prior[k- output_bytes])); =
} break;
            STBI__CASE(STBI__F_avg_first)    { cur[k] =3D STBI__BYTECAST(ra=
w[k] + (cur[k- output_bytes] &gt;&gt; 1)); } break;
            STBI__CASE(STBI__F_paeth_first)  { cur[k] =3D STBI__BYTECAST(ra=
w[k] + stbi__paeth(cur[k- output_bytes],0,0)); } break;
         }
         #undef STBI__CASE

         // the loop above sets the high byte of the pixels' alpha, but for
         // 16 bit png files we also need the low byte set. we'll do that h=
ere.
         if (depth =3D=3D 16) {
            cur =3D a-&gt;out + stride*j; // start at the beginning of the =
row again
            for (i=3D0; i &lt; x; ++i,cur+=3Doutput_bytes) {
               cur[filter_bytes+1] =3D 255;
            }
         }
      }
   }

   // we make a separate pass to expand bits to pixels; for performance,
   // this could run two scanlines behind the above code, so it won't
   // intefere with filtering but will still be in the cache.
   if (depth &lt; 8) {
      for (j=3D0; j &lt; y; ++j) {
         stbi_uc *cur =3D a-&gt;out + stride*j;
         stbi_uc *in  =3D a-&gt;out + stride*j + x*out_n - img_width_bytes;
         // unpack 1/2/4-bit into a 8-bit buffer. allows us to keep the com=
mon 8-bit path optimal at minimal cost for 1/2/4-bit
         // png guarante byte alignment, if width is not multiple of 8/4/2 =
we'll decode dummy trailing data that will be skipped in the later loop
         stbi_uc scale =3D (color =3D=3D 0) ? stbi__depth_scale_table[depth=
] : 1; // scale grayscale values to 0..255 range

         // note that the final byte might overshoot and write more data th=
an desired.
         // we can allocate enough data that this never writes out of memor=
y, but it
         // could also overwrite the next scanline. can it overwrite non-em=
pty data
         // on the next scanline? yes, consider 1-pixel-wide scanlines with=
 1-bit-per-pixel.
         // so we need to explicitly clamp the final ones

         if (depth =3D=3D 4) {
            for (k=3Dx*img_n; k &gt;=3D 2; k-=3D2, ++in) {
               *cur++ =3D scale * ((*in &gt;&gt; 4)       );
               *cur++ =3D scale * ((*in     ) &amp; 0x0f);
            }
            if (k &gt; 0) *cur++ =3D scale * ((*in &gt;&gt; 4)       );
         } else if (depth =3D=3D 2) {
            for (k=3Dx*img_n; k &gt;=3D 4; k-=3D4, ++in) {
               *cur++ =3D scale * ((*in &gt;&gt; 6)       );
               *cur++ =3D scale * ((*in &gt;&gt; 4) &amp; 0x03);
               *cur++ =3D scale * ((*in &gt;&gt; 2) &amp; 0x03);
               *cur++ =3D scale * ((*in     ) &amp; 0x03);
            }
            if (k &gt; 0) *cur++ =3D scale * ((*in &gt;&gt; 6)       );
            if (k &gt; 1) *cur++ =3D scale * ((*in &gt;&gt; 4) &amp; 0x03);
            if (k &gt; 2) *cur++ =3D scale * ((*in &gt;&gt; 2) &amp; 0x03);
         } else if (depth =3D=3D 1) {
            for (k=3Dx*img_n; k &gt;=3D 8; k-=3D8, ++in) {
               *cur++ =3D scale * ((*in &gt;&gt; 7)       );
               *cur++ =3D scale * ((*in &gt;&gt; 6) &amp; 0x01);
               *cur++ =3D scale * ((*in &gt;&gt; 5) &amp; 0x01);
               *cur++ =3D scale * ((*in &gt;&gt; 4) &amp; 0x01);
               *cur++ =3D scale * ((*in &gt;&gt; 3) &amp; 0x01);
               *cur++ =3D scale * ((*in &gt;&gt; 2) &amp; 0x01);
               *cur++ =3D scale * ((*in &gt;&gt; 1) &amp; 0x01);
               *cur++ =3D scale * ((*in     ) &amp; 0x01);
            }
            if (k &gt; 0) *cur++ =3D scale * ((*in &gt;&gt; 7)       );
            if (k &gt; 1) *cur++ =3D scale * ((*in &gt;&gt; 6) &amp; 0x01);
            if (k &gt; 2) *cur++ =3D scale * ((*in &gt;&gt; 5) &amp; 0x01);
            if (k &gt; 3) *cur++ =3D scale * ((*in &gt;&gt; 4) &amp; 0x01);
            if (k &gt; 4) *cur++ =3D scale * ((*in &gt;&gt; 3) &amp; 0x01);
            if (k &gt; 5) *cur++ =3D scale * ((*in &gt;&gt; 2) &amp; 0x01);
            if (k &gt; 6) *cur++ =3D scale * ((*in &gt;&gt; 1) &amp; 0x01);
         }
         if (img_n !=3D out_n) {
            int q;
            // insert alpha =3D 255
            cur =3D a-&gt;out + stride*j;
            if (img_n =3D=3D 1) {
               for (q=3Dx-1; q &gt;=3D 0; --q) {
                  cur[q*2+1] =3D 255;
                  cur[q*2+0] =3D cur[q];
               }
            } else {
               STBI_ASSERT(img_n =3D=3D 3);
               for (q=3Dx-1; q &gt;=3D 0; --q) {
                  cur[q*4+3] =3D 255;
                  cur[q*4+2] =3D cur[q*3+2];
                  cur[q*4+1] =3D cur[q*3+1];
                  cur[q*4+0] =3D cur[q*3+0];
               }
            }
         }
      }
   } else if (depth =3D=3D 16) {
      // force the image data from big-endian to platform-native.
      // this is done in a separate pass due to the decoding relying
      // on the data being untouched, but could probably be done
      // per-line during decode if care is taken.
      stbi_uc *cur =3D a-&gt;out;
      stbi__uint16 *cur16 =3D (stbi__uint16*)cur;

      for(i=3D0; i &lt; x*y*out_n; ++i,cur16++,cur+=3D2) {
         *cur16 =3D (cur[0] &lt;&lt; 8) | cur[1];
      }
   }

   return 1;
}

static int stbi__create_png_image(stbi__png *a, stbi_uc *image_data, stbi__=
uint32 image_data_len, int out_n, int depth, int color, int interlaced)
{
   int bytes =3D (depth =3D=3D 16 ? 2 : 1);
   int out_bytes =3D out_n * bytes;
   stbi_uc *final;
   int p;
   if (!interlaced)
      return stbi__create_png_image_raw(a, image_data, image_data_len, out_=
n, a-&gt;s-&gt;img_x, a-&gt;s-&gt;img_y, depth, color);

   // de-interlacing
   final =3D (stbi_uc *) stbi__malloc_mad3(a-&gt;s-&gt;img_x, a-&gt;s-&gt;i=
mg_y, out_bytes, 0);
   for (p=3D0; p &lt; 7; ++p) {
      int xorig[] =3D { 0,4,0,2,0,1,0 };
      int yorig[] =3D { 0,0,4,0,2,0,1 };
      int xspc[]  =3D { 8,8,4,4,2,2,1 };
      int yspc[]  =3D { 8,8,8,4,4,2,2 };
      int i,j,x,y;
      // pass1_x[4] =3D 0, pass1_x[5] =3D 1, pass1_x[12] =3D 1
      x =3D (a-&gt;s-&gt;img_x - xorig[p] + xspc[p]-1) / xspc[p];
      y =3D (a-&gt;s-&gt;img_y - yorig[p] + yspc[p]-1) / yspc[p];
      if (x &amp;&amp; y) {
         stbi__uint32 img_len =3D ((((a-&gt;s-&gt;img_n * x * depth) + 7) &=
gt;&gt; 3) + 1) * y;
         if (!stbi__create_png_image_raw(a, image_data, image_data_len, out=
_n, x, y, depth, color)) {
            STBI_FREE(final);
            return 0;
         }
         for (j=3D0; j &lt; y; ++j) {
            for (i=3D0; i &lt; x; ++i) {
               int out_y =3D j*yspc[p]+yorig[p];
               int out_x =3D i*xspc[p]+xorig[p];
               memcpy(final + out_y*a-&gt;s-&gt;img_x*out_bytes + out_x*out=
_bytes,
                      a-&gt;out + (j*x+i)*out_bytes, out_bytes);
            }
         }
         STBI_FREE(a-&gt;out);
         image_data +=3D img_len;
         image_data_len -=3D img_len;
      }
   }
   a-&gt;out =3D final;

   return 1;
}

static int stbi__compute_transparency(stbi__png *z, stbi_uc tc[3], int out_=
n)
{
   stbi__context *s =3D z-&gt;s;
   stbi__uint32 i, pixel_count =3D s-&gt;img_x * s-&gt;img_y;
   stbi_uc *p =3D z-&gt;out;

   // compute color-based transparency, assuming we've
   // already got 255 as the alpha value in the output
   STBI_ASSERT(out_n =3D=3D 2 || out_n =3D=3D 4);

   if (out_n =3D=3D 2) {
      for (i=3D0; i &lt; pixel_count; ++i) {
         p[1] =3D (p[0] =3D=3D tc[0] ? 0 : 255);
         p +=3D 2;
      }
   } else {
      for (i=3D0; i &lt; pixel_count; ++i) {
         if (p[0] =3D=3D tc[0] &amp;&amp; p[1] =3D=3D tc[1] &amp;&amp; p[2]=
 =3D=3D tc[2])
            p[3] =3D 0;
         p +=3D 4;
      }
   }
   return 1;
}

static int stbi__compute_transparency16(stbi__png *z, stbi__uint16 tc[3], i=
nt out_n)
{
   stbi__context *s =3D z-&gt;s;
   stbi__uint32 i, pixel_count =3D s-&gt;img_x * s-&gt;img_y;
   stbi__uint16 *p =3D (stbi__uint16*) z-&gt;out;

   // compute color-based transparency, assuming we've
   // already got 65535 as the alpha value in the output
   STBI_ASSERT(out_n =3D=3D 2 || out_n =3D=3D 4);

   if (out_n =3D=3D 2) {
      for (i =3D 0; i &lt; pixel_count; ++i) {
         p[1] =3D (p[0] =3D=3D tc[0] ? 0 : 65535);
         p +=3D 2;
      }
   } else {
      for (i =3D 0; i &lt; pixel_count; ++i) {
         if (p[0] =3D=3D tc[0] &amp;&amp; p[1] =3D=3D tc[1] &amp;&amp; p[2]=
 =3D=3D tc[2])
            p[3] =3D 0;
         p +=3D 4;
      }
   }
   return 1;
}

static int stbi__expand_png_palette(stbi__png *a, stbi_uc *palette, int len=
, int pal_img_n)
{
   stbi__uint32 i, pixel_count =3D a-&gt;s-&gt;img_x * a-&gt;s-&gt;img_y;
   stbi_uc *p, *temp_out, *orig =3D a-&gt;out;

   p =3D (stbi_uc *) stbi__malloc_mad2(pixel_count, pal_img_n, 0);
   if (p =3D=3D NULL) return stbi__err("outofmem", "Out of memory");

   // between here and free(out) below, exitting would leak
   temp_out =3D p;

   if (pal_img_n =3D=3D 3) {
      for (i=3D0; i &lt; pixel_count; ++i) {
         int n =3D orig[i]*4;
         p[0] =3D palette[n  ];
         p[1] =3D palette[n+1];
         p[2] =3D palette[n+2];
         p +=3D 3;
      }
   } else {
      for (i=3D0; i &lt; pixel_count; ++i) {
         int n =3D orig[i]*4;
         p[0] =3D palette[n  ];
         p[1] =3D palette[n+1];
         p[2] =3D palette[n+2];
         p[3] =3D palette[n+3];
         p +=3D 4;
      }
   }
   STBI_FREE(a-&gt;out);
   a-&gt;out =3D temp_out;

   STBI_NOTUSED(len);

   return 1;
}

static int stbi__unpremultiply_on_load =3D 0;
static int stbi__de_iphone_flag =3D 0;

STBIDEF void stbi_set_unpremultiply_on_load(int flag_true_if_should_unpremu=
ltiply)
{
   stbi__unpremultiply_on_load =3D flag_true_if_should_unpremultiply;
}

STBIDEF void stbi_convert_iphone_png_to_rgb(int flag_true_if_should_convert=
)
{
   stbi__de_iphone_flag =3D flag_true_if_should_convert;
}

static void stbi__de_iphone(stbi__png *z)
{
   stbi__context *s =3D z-&gt;s;
   stbi__uint32 i, pixel_count =3D s-&gt;img_x * s-&gt;img_y;
   stbi_uc *p =3D z-&gt;out;

   if (s-&gt;img_out_n =3D=3D 3) {  // convert bgr to rgb
      for (i=3D0; i &lt; pixel_count; ++i) {
         stbi_uc t =3D p[0];
         p[0] =3D p[2];
         p[2] =3D t;
         p +=3D 3;
      }
   } else {
      STBI_ASSERT(s-&gt;img_out_n =3D=3D 4);
      if (stbi__unpremultiply_on_load) {
         // convert bgr to rgb and unpremultiply
         for (i=3D0; i &lt; pixel_count; ++i) {
            stbi_uc a =3D p[3];
            stbi_uc t =3D p[0];
            if (a) {
               stbi_uc half =3D a / 2;
               p[0] =3D (p[2] * 255 + half) / a;
               p[1] =3D (p[1] * 255 + half) / a;
               p[2] =3D ( t   * 255 + half) / a;
            } else {
               p[0] =3D p[2];
               p[2] =3D t;
            }
            p +=3D 4;
         }
      } else {
         // convert bgr to rgb
         for (i=3D0; i &lt; pixel_count; ++i) {
            stbi_uc t =3D p[0];
            p[0] =3D p[2];
            p[2] =3D t;
            p +=3D 4;
         }
      }
   }
}

#define STBI__PNG_TYPE(a,b,c,d)  (((unsigned) (a) &lt;&lt; 24) + ((unsigned=
) (b) &lt;&lt; 16) + ((unsigned) (c) &lt;&lt; 8) + (unsigned) (d))

static int stbi__parse_png_file(stbi__png *z, int scan, int req_comp)
{
   stbi_uc palette[1024], pal_img_n=3D0;
   stbi_uc has_trans=3D0, tc[3]=3D{0};
   stbi__uint16 tc16[3];
   stbi__uint32 ioff=3D0, idata_limit=3D0, i, pal_len=3D0;
   int first=3D1,k,interlace=3D0, color=3D0, is_iphone=3D0;
   stbi__context *s =3D z-&gt;s;

   z-&gt;expanded =3D NULL;
   z-&gt;idata =3D NULL;
   z-&gt;out =3D NULL;

   if (!stbi__check_png_header(s)) return 0;

   if (scan =3D=3D STBI__SCAN_type) return 1;

   for (;;) {
      stbi__pngchunk c =3D stbi__get_chunk_header(s);
      switch (c.type) {
         case STBI__PNG_TYPE('C','g','B','I'):
            is_iphone =3D 1;
            stbi__skip(s, c.length);
            break;
         case STBI__PNG_TYPE('I','H','D','R'): {
            int comp,filter;
            if (!first) return stbi__err("multiple IHDR","Corrupt PNG");
            first =3D 0;
            if (c.length !=3D 13) return stbi__err("bad IHDR len","Corrupt =
PNG");
            s-&gt;img_x =3D stbi__get32be(s); if (s-&gt;img_x &gt; (1 &lt;&=
lt; 24)) return stbi__err("too large","Very large image (corrupt?)");
            s-&gt;img_y =3D stbi__get32be(s); if (s-&gt;img_y &gt; (1 &lt;&=
lt; 24)) return stbi__err("too large","Very large image (corrupt?)");
            z-&gt;depth =3D stbi__get8(s);  if (z-&gt;depth !=3D 1 &amp;&am=
p; z-&gt;depth !=3D 2 &amp;&amp; z-&gt;depth !=3D 4 &amp;&amp; z-&gt;depth =
!=3D 8 &amp;&amp; z-&gt;depth !=3D 16)  return stbi__err("1/2/4/8/16-bit on=
ly","PNG not supported: 1/2/4/8/16-bit only");
            color =3D stbi__get8(s);  if (color &gt; 6)         return stbi=
__err("bad ctype","Corrupt PNG");
            if (color =3D=3D 3 &amp;&amp; z-&gt;depth =3D=3D 16)           =
       return stbi__err("bad ctype","Corrupt PNG");
            if (color =3D=3D 3) pal_img_n =3D 3; else if (color &amp; 1) re=
turn stbi__err("bad ctype","Corrupt PNG");
            comp  =3D stbi__get8(s);  if (comp) return stbi__err("bad comp =
method","Corrupt PNG");
            filter=3D stbi__get8(s);  if (filter) return stbi__err("bad fil=
ter method","Corrupt PNG");
            interlace =3D stbi__get8(s); if (interlace&gt;1) return stbi__e=
rr("bad interlace method","Corrupt PNG");
            if (!s-&gt;img_x || !s-&gt;img_y) return stbi__err("0-pixel ima=
ge","Corrupt PNG");
            if (!pal_img_n) {
               s-&gt;img_n =3D (color &amp; 2 ? 3 : 1) + (color &amp; 4 ? 1=
 : 0);
               if ((1 &lt;&lt; 30) / s-&gt;img_x / s-&gt;img_n &lt; s-&gt;i=
mg_y) return stbi__err("too large", "Image too large to decode");
               if (scan =3D=3D STBI__SCAN_header) return 1;
            } else {
               // if paletted, then pal_n is our final components, and
               // img_n is # components to decompress/filter.
               s-&gt;img_n =3D 1;
               if ((1 &lt;&lt; 30) / s-&gt;img_x / 4 &lt; s-&gt;img_y) retu=
rn stbi__err("too large","Corrupt PNG");
               // if SCAN_header, have to scan to see if we have a tRNS
            }
            break;
         }

         case STBI__PNG_TYPE('P','L','T','E'):  {
            if (first) return stbi__err("first not IHDR", "Corrupt PNG");
            if (c.length &gt; 256*3) return stbi__err("invalid PLTE","Corru=
pt PNG");
            pal_len =3D c.length / 3;
            if (pal_len * 3 !=3D c.length) return stbi__err("invalid PLTE",=
"Corrupt PNG");
            for (i=3D0; i &lt; pal_len; ++i) {
               palette[i*4+0] =3D stbi__get8(s);
               palette[i*4+1] =3D stbi__get8(s);
               palette[i*4+2] =3D stbi__get8(s);
               palette[i*4+3] =3D 255;
            }
            break;
         }

         case STBI__PNG_TYPE('t','R','N','S'): {
            if (first) return stbi__err("first not IHDR", "Corrupt PNG");
            if (z-&gt;idata) return stbi__err("tRNS after IDAT","Corrupt PN=
G");
            if (pal_img_n) {
               if (scan =3D=3D STBI__SCAN_header) { s-&gt;img_n =3D 4; retu=
rn 1; }
               if (pal_len =3D=3D 0) return stbi__err("tRNS before PLTE","C=
orrupt PNG");
               if (c.length &gt; pal_len) return stbi__err("bad tRNS len","=
Corrupt PNG");
               pal_img_n =3D 4;
               for (i=3D0; i &lt; c.length; ++i)
                  palette[i*4+3] =3D stbi__get8(s);
            } else {
               if (!(s-&gt;img_n &amp; 1)) return stbi__err("tRNS with alph=
a","Corrupt PNG");
               if (c.length !=3D (stbi__uint32) s-&gt;img_n*2) return stbi_=
_err("bad tRNS len","Corrupt PNG");
               has_trans =3D 1;
               if (z-&gt;depth =3D=3D 16) {
                  for (k =3D 0; k &lt; s-&gt;img_n; ++k) tc16[k] =3D (stbi_=
_uint16)stbi__get16be(s); // copy the values as-is
               } else {
                  for (k =3D 0; k &lt; s-&gt;img_n; ++k) tc[k] =3D (stbi_uc=
)(stbi__get16be(s) &amp; 255) * stbi__depth_scale_table[z-&gt;depth]; // no=
n 8-bit images will be larger
               }
            }
            break;
         }

         case STBI__PNG_TYPE('I','D','A','T'): {
            if (first) return stbi__err("first not IHDR", "Corrupt PNG");
            if (pal_img_n &amp;&amp; !pal_len) return stbi__err("no PLTE","=
Corrupt PNG");
            if (scan =3D=3D STBI__SCAN_header) { s-&gt;img_n =3D pal_img_n;=
 return 1; }
            if ((int)(ioff + c.length) &lt; (int)ioff) return 0;
            if (ioff + c.length &gt; idata_limit) {
               stbi__uint32 idata_limit_old =3D idata_limit;
               stbi_uc *p;
               if (idata_limit =3D=3D 0) idata_limit =3D c.length &gt; 4096=
 ? c.length : 4096;
               while (ioff + c.length &gt; idata_limit)
                  idata_limit *=3D 2;
               STBI_NOTUSED(idata_limit_old);
               p =3D (stbi_uc *) STBI_REALLOC_SIZED(z-&gt;idata, idata_limi=
t_old, idata_limit); if (p =3D=3D NULL) return stbi__err("outofmem", "Out o=
f memory");
               z-&gt;idata =3D p;
            }
            if (!stbi__getn(s, z-&gt;idata+ioff,c.length)) return stbi__err=
("outofdata","Corrupt PNG");
            ioff +=3D c.length;
            break;
         }

         case STBI__PNG_TYPE('I','E','N','D'): {
            stbi__uint32 raw_len, bpl;
            if (first) return stbi__err("first not IHDR", "Corrupt PNG");
            if (scan !=3D STBI__SCAN_load) return 1;
            if (z-&gt;idata =3D=3D NULL) return stbi__err("no IDAT","Corrup=
t PNG");
            // initial guess for decoded data size to avoid unnecessary rea=
llocs
            bpl =3D (s-&gt;img_x * z-&gt;depth + 7) / 8; // bytes per line,=
 per component
            raw_len =3D bpl * s-&gt;img_y * s-&gt;img_n /* pixels */ + s-&g=
t;img_y /* filter mode per row */;
            z-&gt;expanded =3D (stbi_uc *) stbi_zlib_decode_malloc_guesssiz=
e_headerflag((char *) z-&gt;idata, ioff, raw_len, (int *) &amp;raw_len, !is=
_iphone);
            if (z-&gt;expanded =3D=3D NULL) return 0; // zlib should set er=
ror
            STBI_FREE(z-&gt;idata); z-&gt;idata =3D NULL;
            if ((req_comp =3D=3D s-&gt;img_n+1 &amp;&amp; req_comp !=3D 3 &=
amp;&amp; !pal_img_n) || has_trans)
               s-&gt;img_out_n =3D s-&gt;img_n+1;
            else
               s-&gt;img_out_n =3D s-&gt;img_n;
            if (!stbi__create_png_image(z, z-&gt;expanded, raw_len, s-&gt;i=
mg_out_n, z-&gt;depth, color, interlace)) return 0;
            if (has_trans) {
               if (z-&gt;depth =3D=3D 16) {
                  if (!stbi__compute_transparency16(z, tc16, s-&gt;img_out_=
n)) return 0;
               } else {
                  if (!stbi__compute_transparency(z, tc, s-&gt;img_out_n)) =
return 0;
               }
            }
            if (is_iphone &amp;&amp; stbi__de_iphone_flag &amp;&amp; s-&gt;=
img_out_n &gt; 2)
               stbi__de_iphone(z);
            if (pal_img_n) {
               // pal_img_n =3D=3D 3 or 4
               s-&gt;img_n =3D pal_img_n; // record the actual colors we ha=
d
               s-&gt;img_out_n =3D pal_img_n;
               if (req_comp &gt;=3D 3) s-&gt;img_out_n =3D req_comp;
               if (!stbi__expand_png_palette(z, palette, pal_len, s-&gt;img=
_out_n))
                  return 0;
            } else if (has_trans) {
               // non-paletted image with tRNS -&gt; source image has (cons=
tant) alpha
               ++s-&gt;img_n;
            }
            STBI_FREE(z-&gt;expanded); z-&gt;expanded =3D NULL;
            return 1;
         }

         default:
            // if critical, fail
            if (first) return stbi__err("first not IHDR", "Corrupt PNG");
            if ((c.type &amp; (1 &lt;&lt; 29)) =3D=3D 0) {
               #ifndef STBI_NO_FAILURE_STRINGS
               // not threadsafe
               static char invalid_chunk[] =3D "XXXX PNG chunk not known";
               invalid_chunk[0] =3D STBI__BYTECAST(c.type &gt;&gt; 24);
               invalid_chunk[1] =3D STBI__BYTECAST(c.type &gt;&gt; 16);
               invalid_chunk[2] =3D STBI__BYTECAST(c.type &gt;&gt;  8);
               invalid_chunk[3] =3D STBI__BYTECAST(c.type &gt;&gt;  0);
               #endif
               return stbi__err(invalid_chunk, "PNG not supported: unknown =
PNG chunk type");
            }
            stbi__skip(s, c.length);
            break;
      }
      // end of PNG chunk, read and skip CRC
      stbi__get32be(s);
   }
}

static void *stbi__do_png(stbi__png *p, int *x, int *y, int *n, int req_com=
p, stbi__result_info *ri)
{
   void *result=3DNULL;
   if (req_comp &lt; 0 || req_comp &gt; 4) return stbi__errpuc("bad req_com=
p", "Internal error");
   if (stbi__parse_png_file(p, STBI__SCAN_load, req_comp)) {
      if (p-&gt;depth &lt; 8)
         ri-&gt;bits_per_channel =3D 8;
      else
         ri-&gt;bits_per_channel =3D p-&gt;depth;
      result =3D p-&gt;out;
      p-&gt;out =3D NULL;
      if (req_comp &amp;&amp; req_comp !=3D p-&gt;s-&gt;img_out_n) {
         if (ri-&gt;bits_per_channel =3D=3D 8)
            result =3D stbi__convert_format((unsigned char *) result, p-&gt=
;s-&gt;img_out_n, req_comp, p-&gt;s-&gt;img_x, p-&gt;s-&gt;img_y);
         else
            result =3D stbi__convert_format16((stbi__uint16 *) result, p-&g=
t;s-&gt;img_out_n, req_comp, p-&gt;s-&gt;img_x, p-&gt;s-&gt;img_y);
         p-&gt;s-&gt;img_out_n =3D req_comp;
         if (result =3D=3D NULL) return result;
      }
      *x =3D p-&gt;s-&gt;img_x;
      *y =3D p-&gt;s-&gt;img_y;
      if (n) *n =3D p-&gt;s-&gt;img_n;
   }
   STBI_FREE(p-&gt;out);      p-&gt;out      =3D NULL;
   STBI_FREE(p-&gt;expanded); p-&gt;expanded =3D NULL;
   STBI_FREE(p-&gt;idata);    p-&gt;idata    =3D NULL;

   return result;
}

static void *stbi__png_load(stbi__context *s, int *x, int *y, int *comp, in=
t req_comp, stbi__result_info *ri)
{
   stbi__png p;
   p.s =3D s;
   return stbi__do_png(&amp;p, x,y,comp,req_comp, ri);
}

static int stbi__png_test(stbi__context *s)
{
   int r;
   r =3D stbi__check_png_header(s);
   stbi__rewind(s);
   return r;
}

static int stbi__png_info_raw(stbi__png *p, int *x, int *y, int *comp)
{
   if (!stbi__parse_png_file(p, STBI__SCAN_header, 0)) {
      stbi__rewind( p-&gt;s );
      return 0;
   }
   if (x) *x =3D p-&gt;s-&gt;img_x;
   if (y) *y =3D p-&gt;s-&gt;img_y;
   if (comp) *comp =3D p-&gt;s-&gt;img_n;
   return 1;
}

static int stbi__png_info(stbi__context *s, int *x, int *y, int *comp)
{
   stbi__png p;
   p.s =3D s;
   return stbi__png_info_raw(&amp;p, x, y, comp);
}

static int stbi__png_is16(stbi__context *s)
{
   stbi__png p;
   p.s =3D s;
   if (!stbi__png_info_raw(&amp;p, NULL, NULL, NULL))
	   return 0;
   if (p.depth !=3D 16) {
      stbi__rewind(p.s);
      return 0;
   }
   return 1;
}
#endif

// Microsoft/Windows BMP image

#ifndef STBI_NO_BMP
static int stbi__bmp_test_raw(stbi__context *s)
{
   int r;
   int sz;
   if (stbi__get8(s) !=3D 'B') return 0;
   if (stbi__get8(s) !=3D 'M') return 0;
   stbi__get32le(s); // discard filesize
   stbi__get16le(s); // discard reserved
   stbi__get16le(s); // discard reserved
   stbi__get32le(s); // discard data offset
   sz =3D stbi__get32le(s);
   r =3D (sz =3D=3D 12 || sz =3D=3D 40 || sz =3D=3D 56 || sz =3D=3D 108 || =
sz =3D=3D 124);
   return r;
}

static int stbi__bmp_test(stbi__context *s)
{
   int r =3D stbi__bmp_test_raw(s);
   stbi__rewind(s);
   return r;
}


// returns 0..31 for the highest set bit
static int stbi__high_bit(unsigned int z)
{
   int n=3D0;
   if (z =3D=3D 0) return -1;
   if (z &gt;=3D 0x10000) { n +=3D 16; z &gt;&gt;=3D 16; }
   if (z &gt;=3D 0x00100) { n +=3D  8; z &gt;&gt;=3D  8; }
   if (z &gt;=3D 0x00010) { n +=3D  4; z &gt;&gt;=3D  4; }
   if (z &gt;=3D 0x00004) { n +=3D  2; z &gt;&gt;=3D  2; }
   if (z &gt;=3D 0x00002) { n +=3D  1; z &gt;&gt;=3D  1; }
   return n;
}

static int stbi__bitcount(unsigned int a)
{
   a =3D (a &amp; 0x55555555) + ((a &gt;&gt;  1) &amp; 0x55555555); // max =
2
   a =3D (a &amp; 0x33333333) + ((a &gt;&gt;  2) &amp; 0x33333333); // max =
4
   a =3D (a + (a &gt;&gt; 4)) &amp; 0x0f0f0f0f; // max 8 per 4, now 8 bits
   a =3D (a + (a &gt;&gt; 8)); // max 16 per 8 bits
   a =3D (a + (a &gt;&gt; 16)); // max 32 per 8 bits
   return a &amp; 0xff;
}

// extract an arbitrarily-aligned N-bit value (N=3Dbits)
// from v, and then make it 8-bits long and fractionally
// extend it to full full range.
static int stbi__shiftsigned(unsigned int v, int shift, int bits)
{
   static unsigned int mul_table[9] =3D {
      0,
      0xff/*0b11111111*/, 0x55/*0b01010101*/, 0x49/*0b01001001*/, 0x11/*0b0=
0010001*/,
      0x21/*0b00100001*/, 0x41/*0b01000001*/, 0x81/*0b10000001*/, 0x01/*0b0=
0000001*/,
   };
   static unsigned int shift_table[9] =3D {
      0, 0,0,1,0,2,4,6,0,
   };
   if (shift &lt; 0)
      v &lt;&lt;=3D -shift;
   else
      v &gt;&gt;=3D shift;
   STBI_ASSERT(v &gt;=3D 0 &amp;&amp; v &lt; 256);
   v &gt;&gt;=3D (8-bits);
   STBI_ASSERT(bits &gt;=3D 0 &amp;&amp; bits &lt;=3D 8);
   return (int) ((unsigned) v * mul_table[bits]) &gt;&gt; shift_table[bits]=
;
}

typedef struct
{
   int bpp, offset, hsz;
   unsigned int mr,mg,mb,ma, all_a;
} stbi__bmp_data;

static void *stbi__bmp_parse_header(stbi__context *s, stbi__bmp_data *info)
{
   int hsz;
   if (stbi__get8(s) !=3D 'B' || stbi__get8(s) !=3D 'M') return stbi__errpu=
c("not BMP", "Corrupt BMP");
   stbi__get32le(s); // discard filesize
   stbi__get16le(s); // discard reserved
   stbi__get16le(s); // discard reserved
   info-&gt;offset =3D stbi__get32le(s);
   info-&gt;hsz =3D hsz =3D stbi__get32le(s);
   info-&gt;mr =3D info-&gt;mg =3D info-&gt;mb =3D info-&gt;ma =3D 0;

   if (hsz !=3D 12 &amp;&amp; hsz !=3D 40 &amp;&amp; hsz !=3D 56 &amp;&amp;=
 hsz !=3D 108 &amp;&amp; hsz !=3D 124) return stbi__errpuc("unknown BMP", "=
BMP type not supported: unknown");
   if (hsz =3D=3D 12) {
      s-&gt;img_x =3D stbi__get16le(s);
      s-&gt;img_y =3D stbi__get16le(s);
   } else {
      s-&gt;img_x =3D stbi__get32le(s);
      s-&gt;img_y =3D stbi__get32le(s);
   }
   if (stbi__get16le(s) !=3D 1) return stbi__errpuc("bad BMP", "bad BMP");
   info-&gt;bpp =3D stbi__get16le(s);
   if (hsz !=3D 12) {
      int compress =3D stbi__get32le(s);
      if (compress =3D=3D 1 || compress =3D=3D 2) return stbi__errpuc("BMP =
RLE", "BMP type not supported: RLE");
      stbi__get32le(s); // discard sizeof
      stbi__get32le(s); // discard hres
      stbi__get32le(s); // discard vres
      stbi__get32le(s); // discard colorsused
      stbi__get32le(s); // discard max important
      if (hsz =3D=3D 40 || hsz =3D=3D 56) {
         if (hsz =3D=3D 56) {
            stbi__get32le(s);
            stbi__get32le(s);
            stbi__get32le(s);
            stbi__get32le(s);
         }
         if (info-&gt;bpp =3D=3D 16 || info-&gt;bpp =3D=3D 32) {
            if (compress =3D=3D 0) {
               if (info-&gt;bpp =3D=3D 32) {
                  info-&gt;mr =3D 0xffu &lt;&lt; 16;
                  info-&gt;mg =3D 0xffu &lt;&lt;  8;
                  info-&gt;mb =3D 0xffu &lt;&lt;  0;
                  info-&gt;ma =3D 0xffu &lt;&lt; 24;
                  info-&gt;all_a =3D 0; // if all_a is 0 at end, then we lo=
aded alpha channel but it was all 0
               } else {
                  info-&gt;mr =3D 31u &lt;&lt; 10;
                  info-&gt;mg =3D 31u &lt;&lt;  5;
                  info-&gt;mb =3D 31u &lt;&lt;  0;
               }
            } else if (compress =3D=3D 3) {
               info-&gt;mr =3D stbi__get32le(s);
               info-&gt;mg =3D stbi__get32le(s);
               info-&gt;mb =3D stbi__get32le(s);
               // not documented, but generated by photoshop and handled by=
 mspaint
               if (info-&gt;mr =3D=3D info-&gt;mg &amp;&amp; info-&gt;mg =
=3D=3D info-&gt;mb) {
                  // ?!?!?
                  return stbi__errpuc("bad BMP", "bad BMP");
               }
            } else
               return stbi__errpuc("bad BMP", "bad BMP");
         }
      } else {
         int i;
         if (hsz !=3D 108 &amp;&amp; hsz !=3D 124)
            return stbi__errpuc("bad BMP", "bad BMP");
         info-&gt;mr =3D stbi__get32le(s);
         info-&gt;mg =3D stbi__get32le(s);
         info-&gt;mb =3D stbi__get32le(s);
         info-&gt;ma =3D stbi__get32le(s);
         stbi__get32le(s); // discard color space
         for (i=3D0; i &lt; 12; ++i)
            stbi__get32le(s); // discard color space parameters
         if (hsz =3D=3D 124) {
            stbi__get32le(s); // discard rendering intent
            stbi__get32le(s); // discard offset of profile data
            stbi__get32le(s); // discard size of profile data
            stbi__get32le(s); // discard reserved
         }
      }
   }
   return (void *) 1;
}


static void *stbi__bmp_load(stbi__context *s, int *x, int *y, int *comp, in=
t req_comp, stbi__result_info *ri)
{
   stbi_uc *out;
   unsigned int mr=3D0,mg=3D0,mb=3D0,ma=3D0, all_a;
   stbi_uc pal[256][4];
   int psize=3D0,i,j,width;
   int flip_vertically, pad, target;
   stbi__bmp_data info;
   STBI_NOTUSED(ri);

   info.all_a =3D 255;
   if (stbi__bmp_parse_header(s, &amp;info) =3D=3D NULL)
      return NULL; // error code already set

   flip_vertically =3D ((int) s-&gt;img_y) &gt; 0;
   s-&gt;img_y =3D abs((int) s-&gt;img_y);

   mr =3D info.mr;
   mg =3D info.mg;
   mb =3D info.mb;
   ma =3D info.ma;
   all_a =3D info.all_a;

   if (info.hsz =3D=3D 12) {
      if (info.bpp &lt; 24)
         psize =3D (info.offset - 14 - 24) / 3;
   } else {
      if (info.bpp &lt; 16)
         psize =3D (info.offset - 14 - info.hsz) &gt;&gt; 2;
   }

   s-&gt;img_n =3D ma ? 4 : 3;
   if (req_comp &amp;&amp; req_comp &gt;=3D 3) // we can directly decode 3 =
or 4
      target =3D req_comp;
   else
      target =3D s-&gt;img_n; // if they want monochrome, we'll post-conver=
t

   // sanity-check size
   if (!stbi__mad3sizes_valid(target, s-&gt;img_x, s-&gt;img_y, 0))
      return stbi__errpuc("too large", "Corrupt BMP");

   out =3D (stbi_uc *) stbi__malloc_mad3(target, s-&gt;img_x, s-&gt;img_y, =
0);
   if (!out) return stbi__errpuc("outofmem", "Out of memory");
   if (info.bpp &lt; 16) {
      int z=3D0;
      if (psize =3D=3D 0 || psize &gt; 256) { STBI_FREE(out); return stbi__=
errpuc("invalid", "Corrupt BMP"); }
      for (i=3D0; i &lt; psize; ++i) {
         pal[i][2] =3D stbi__get8(s);
         pal[i][1] =3D stbi__get8(s);
         pal[i][0] =3D stbi__get8(s);
         if (info.hsz !=3D 12) stbi__get8(s);
         pal[i][3] =3D 255;
      }
      stbi__skip(s, info.offset - 14 - info.hsz - psize * (info.hsz =3D=3D =
12 ? 3 : 4));
      if (info.bpp =3D=3D 1) width =3D (s-&gt;img_x + 7) &gt;&gt; 3;
      else if (info.bpp =3D=3D 4) width =3D (s-&gt;img_x + 1) &gt;&gt; 1;
      else if (info.bpp =3D=3D 8) width =3D s-&gt;img_x;
      else { STBI_FREE(out); return stbi__errpuc("bad bpp", "Corrupt BMP");=
 }
      pad =3D (-width)&amp;3;
      if (info.bpp =3D=3D 1) {
         for (j=3D0; j &lt; (int) s-&gt;img_y; ++j) {
            int bit_offset =3D 7, v =3D stbi__get8(s);
            for (i=3D0; i &lt; (int) s-&gt;img_x; ++i) {
               int color =3D (v&gt;&gt;bit_offset)&amp;0x1;
               out[z++] =3D pal[color][0];
               out[z++] =3D pal[color][1];
               out[z++] =3D pal[color][2];
               if (target =3D=3D 4) out[z++] =3D 255;
               if (i+1 =3D=3D (int) s-&gt;img_x) break;
               if((--bit_offset) &lt; 0) {
                  bit_offset =3D 7;
                  v =3D stbi__get8(s);
               }
            }
            stbi__skip(s, pad);
         }
      } else {
         for (j=3D0; j &lt; (int) s-&gt;img_y; ++j) {
            for (i=3D0; i &lt; (int) s-&gt;img_x; i +=3D 2) {
               int v=3Dstbi__get8(s),v2=3D0;
               if (info.bpp =3D=3D 4) {
                  v2 =3D v &amp; 15;
                  v &gt;&gt;=3D 4;
               }
               out[z++] =3D pal[v][0];
               out[z++] =3D pal[v][1];
               out[z++] =3D pal[v][2];
               if (target =3D=3D 4) out[z++] =3D 255;
               if (i+1 =3D=3D (int) s-&gt;img_x) break;
               v =3D (info.bpp =3D=3D 8) ? stbi__get8(s) : v2;
               out[z++] =3D pal[v][0];
               out[z++] =3D pal[v][1];
               out[z++] =3D pal[v][2];
               if (target =3D=3D 4) out[z++] =3D 255;
            }
            stbi__skip(s, pad);
         }
      }
   } else {
      int rshift=3D0,gshift=3D0,bshift=3D0,ashift=3D0,rcount=3D0,gcount=3D0=
,bcount=3D0,acount=3D0;
      int z =3D 0;
      int easy=3D0;
      stbi__skip(s, info.offset - 14 - info.hsz);
      if (info.bpp =3D=3D 24) width =3D 3 * s-&gt;img_x;
      else if (info.bpp =3D=3D 16) width =3D 2*s-&gt;img_x;
      else /* bpp =3D 32 and pad =3D 0 */ width=3D0;
      pad =3D (-width) &amp; 3;
      if (info.bpp =3D=3D 24) {
         easy =3D 1;
      } else if (info.bpp =3D=3D 32) {
         if (mb =3D=3D 0xff &amp;&amp; mg =3D=3D 0xff00 &amp;&amp; mr =3D=
=3D 0x00ff0000 &amp;&amp; ma =3D=3D 0xff000000)
            easy =3D 2;
      }
      if (!easy) {
         if (!mr || !mg || !mb) { STBI_FREE(out); return stbi__errpuc("bad =
masks", "Corrupt BMP"); }
         // right shift amt to put high bit in position #7
         rshift =3D stbi__high_bit(mr)-7; rcount =3D stbi__bitcount(mr);
         gshift =3D stbi__high_bit(mg)-7; gcount =3D stbi__bitcount(mg);
         bshift =3D stbi__high_bit(mb)-7; bcount =3D stbi__bitcount(mb);
         ashift =3D stbi__high_bit(ma)-7; acount =3D stbi__bitcount(ma);
      }
      for (j=3D0; j &lt; (int) s-&gt;img_y; ++j) {
         if (easy) {
            for (i=3D0; i &lt; (int) s-&gt;img_x; ++i) {
               unsigned char a;
               out[z+2] =3D stbi__get8(s);
               out[z+1] =3D stbi__get8(s);
               out[z+0] =3D stbi__get8(s);
               z +=3D 3;
               a =3D (easy =3D=3D 2 ? stbi__get8(s) : 255);
               all_a |=3D a;
               if (target =3D=3D 4) out[z++] =3D a;
            }
         } else {
            int bpp =3D info.bpp;
            for (i=3D0; i &lt; (int) s-&gt;img_x; ++i) {
               stbi__uint32 v =3D (bpp =3D=3D 16 ? (stbi__uint32) stbi__get=
16le(s) : stbi__get32le(s));
               unsigned int a;
               out[z++] =3D STBI__BYTECAST(stbi__shiftsigned(v &amp; mr, rs=
hift, rcount));
               out[z++] =3D STBI__BYTECAST(stbi__shiftsigned(v &amp; mg, gs=
hift, gcount));
               out[z++] =3D STBI__BYTECAST(stbi__shiftsigned(v &amp; mb, bs=
hift, bcount));
               a =3D (ma ? stbi__shiftsigned(v &amp; ma, ashift, acount) : =
255);
               all_a |=3D a;
               if (target =3D=3D 4) out[z++] =3D STBI__BYTECAST(a);
            }
         }
         stbi__skip(s, pad);
      }
   }

   // if alpha channel is all 0s, replace with all 255s
   if (target =3D=3D 4 &amp;&amp; all_a =3D=3D 0)
      for (i=3D4*s-&gt;img_x*s-&gt;img_y-1; i &gt;=3D 0; i -=3D 4)
         out[i] =3D 255;

   if (flip_vertically) {
      stbi_uc t;
      for (j=3D0; j &lt; (int) s-&gt;img_y&gt;&gt;1; ++j) {
         stbi_uc *p1 =3D out +      j     *s-&gt;img_x*target;
         stbi_uc *p2 =3D out + (s-&gt;img_y-1-j)*s-&gt;img_x*target;
         for (i=3D0; i &lt; (int) s-&gt;img_x*target; ++i) {
            t =3D p1[i]; p1[i] =3D p2[i]; p2[i] =3D t;
         }
      }
   }

   if (req_comp &amp;&amp; req_comp !=3D target) {
      out =3D stbi__convert_format(out, target, req_comp, s-&gt;img_x, s-&g=
t;img_y);
      if (out =3D=3D NULL) return out; // stbi__convert_format frees input =
on failure
   }

   *x =3D s-&gt;img_x;
   *y =3D s-&gt;img_y;
   if (comp) *comp =3D s-&gt;img_n;
   return out;
}
#endif

// Targa Truevision - TGA
// by Jonathan Dummer
#ifndef STBI_NO_TGA
// returns STBI_rgb or whatever, 0 on error
static int stbi__tga_get_comp(int bits_per_pixel, int is_grey, int* is_rgb1=
6)
{
   // only RGB or RGBA (incl. 16bit) or grey allowed
   if (is_rgb16) *is_rgb16 =3D 0;
   switch(bits_per_pixel) {
      case 8:  return STBI_grey;
      case 16: if(is_grey) return STBI_grey_alpha;
               // fallthrough
      case 15: if(is_rgb16) *is_rgb16 =3D 1;
               return STBI_rgb;
      case 24: // fallthrough
      case 32: return bits_per_pixel/8;
      default: return 0;
   }
}

static int stbi__tga_info(stbi__context *s, int *x, int *y, int *comp)
{
    int tga_w, tga_h, tga_comp, tga_image_type, tga_bits_per_pixel, tga_col=
ormap_bpp;
    int sz, tga_colormap_type;
    stbi__get8(s);                   // discard Offset
    tga_colormap_type =3D stbi__get8(s); // colormap type
    if( tga_colormap_type &gt; 1 ) {
        stbi__rewind(s);
        return 0;      // only RGB or indexed allowed
    }
    tga_image_type =3D stbi__get8(s); // image type
    if ( tga_colormap_type =3D=3D 1 ) { // colormapped (paletted) image
        if (tga_image_type !=3D 1 &amp;&amp; tga_image_type !=3D 9) {
            stbi__rewind(s);
            return 0;
        }
        stbi__skip(s,4);       // skip index of first colormap entry and nu=
mber of entries
        sz =3D stbi__get8(s);    //   check bits per palette color entry
        if ( (sz !=3D 8) &amp;&amp; (sz !=3D 15) &amp;&amp; (sz !=3D 16) &a=
mp;&amp; (sz !=3D 24) &amp;&amp; (sz !=3D 32) ) {
            stbi__rewind(s);
            return 0;
        }
        stbi__skip(s,4);       // skip image x and y origin
        tga_colormap_bpp =3D sz;
    } else { // "normal" image w/o colormap - only RGB or grey allowed, +/-=
 RLE
        if ( (tga_image_type !=3D 2) &amp;&amp; (tga_image_type !=3D 3) &am=
p;&amp; (tga_image_type !=3D 10) &amp;&amp; (tga_image_type !=3D 11) ) {
            stbi__rewind(s);
            return 0; // only RGB or grey allowed, +/- RLE
        }
        stbi__skip(s,9); // skip colormap specification and image x/y origi=
n
        tga_colormap_bpp =3D 0;
    }
    tga_w =3D stbi__get16le(s);
    if( tga_w &lt; 1 ) {
        stbi__rewind(s);
        return 0;   // test width
    }
    tga_h =3D stbi__get16le(s);
    if( tga_h &lt; 1 ) {
        stbi__rewind(s);
        return 0;   // test height
    }
    tga_bits_per_pixel =3D stbi__get8(s); // bits per pixel
    stbi__get8(s); // ignore alpha bits
    if (tga_colormap_bpp !=3D 0) {
        if((tga_bits_per_pixel !=3D 8) &amp;&amp; (tga_bits_per_pixel !=3D =
16)) {
            // when using a colormap, tga_bits_per_pixel is the size of the=
 indexes
            // I don't think anything but 8 or 16bit indexes makes sense
            stbi__rewind(s);
            return 0;
        }
        tga_comp =3D stbi__tga_get_comp(tga_colormap_bpp, 0, NULL);
    } else {
        tga_comp =3D stbi__tga_get_comp(tga_bits_per_pixel, (tga_image_type=
 =3D=3D 3) || (tga_image_type =3D=3D 11), NULL);
    }
    if(!tga_comp) {
      stbi__rewind(s);
      return 0;
    }
    if (x) *x =3D tga_w;
    if (y) *y =3D tga_h;
    if (comp) *comp =3D tga_comp;
    return 1;                   // seems to have passed everything
}

static int stbi__tga_test(stbi__context *s)
{
   int res =3D 0;
   int sz, tga_color_type;
   stbi__get8(s);      //   discard Offset
   tga_color_type =3D stbi__get8(s);   //   color type
   if ( tga_color_type &gt; 1 ) goto errorEnd;   //   only RGB or indexed a=
llowed
   sz =3D stbi__get8(s);   //   image type
   if ( tga_color_type =3D=3D 1 ) { // colormapped (paletted) image
      if (sz !=3D 1 &amp;&amp; sz !=3D 9) goto errorEnd; // colortype 1 dem=
ands image type 1 or 9
      stbi__skip(s,4);       // skip index of first colormap entry and numb=
er of entries
      sz =3D stbi__get8(s);    //   check bits per palette color entry
      if ( (sz !=3D 8) &amp;&amp; (sz !=3D 15) &amp;&amp; (sz !=3D 16) &amp=
;&amp; (sz !=3D 24) &amp;&amp; (sz !=3D 32) ) goto errorEnd;
      stbi__skip(s,4);       // skip image x and y origin
   } else { // "normal" image w/o colormap
      if ( (sz !=3D 2) &amp;&amp; (sz !=3D 3) &amp;&amp; (sz !=3D 10) &amp;=
&amp; (sz !=3D 11) ) goto errorEnd; // only RGB or grey allowed, +/- RLE
      stbi__skip(s,9); // skip colormap specification and image x/y origin
   }
   if ( stbi__get16le(s) &lt; 1 ) goto errorEnd;      //   test width
   if ( stbi__get16le(s) &lt; 1 ) goto errorEnd;      //   test height
   sz =3D stbi__get8(s);   //   bits per pixel
   if ( (tga_color_type =3D=3D 1) &amp;&amp; (sz !=3D 8) &amp;&amp; (sz !=
=3D 16) ) goto errorEnd; // for colormapped images, bpp is size of an index
   if ( (sz !=3D 8) &amp;&amp; (sz !=3D 15) &amp;&amp; (sz !=3D 16) &amp;&a=
mp; (sz !=3D 24) &amp;&amp; (sz !=3D 32) ) goto errorEnd;

   res =3D 1; // if we got this far, everything's good and we can return 1 =
instead of 0

errorEnd:
   stbi__rewind(s);
   return res;
}

// read 16bit value and convert to 24bit RGB
static void stbi__tga_read_rgb16(stbi__context *s, stbi_uc* out)
{
   stbi__uint16 px =3D (stbi__uint16)stbi__get16le(s);
   stbi__uint16 fiveBitMask =3D 31;
   // we have 3 channels with 5bits each
   int r =3D (px &gt;&gt; 10) &amp; fiveBitMask;
   int g =3D (px &gt;&gt; 5) &amp; fiveBitMask;
   int b =3D px &amp; fiveBitMask;
   // Note that this saves the data in RGB(A) order, so it doesn't need to =
be swapped later
   out[0] =3D (stbi_uc)((r * 255)/31);
   out[1] =3D (stbi_uc)((g * 255)/31);
   out[2] =3D (stbi_uc)((b * 255)/31);

   // some people claim that the most significant bit might be used for alp=
ha
   // (possibly if an alpha-bit is set in the "image descriptor byte")
   // but that only made 16bit test images completely translucent..
   // so let's treat all 15 and 16bit TGAs as RGB with no alpha.
}

static void *stbi__tga_load(stbi__context *s, int *x, int *y, int *comp, in=
t req_comp, stbi__result_info *ri)
{
   //   read in the TGA header stuff
   int tga_offset =3D stbi__get8(s);
   int tga_indexed =3D stbi__get8(s);
   int tga_image_type =3D stbi__get8(s);
   int tga_is_RLE =3D 0;
   int tga_palette_start =3D stbi__get16le(s);
   int tga_palette_len =3D stbi__get16le(s);
   int tga_palette_bits =3D stbi__get8(s);
   int tga_x_origin =3D stbi__get16le(s);
   int tga_y_origin =3D stbi__get16le(s);
   int tga_width =3D stbi__get16le(s);
   int tga_height =3D stbi__get16le(s);
   int tga_bits_per_pixel =3D stbi__get8(s);
   int tga_comp, tga_rgb16=3D0;
   int tga_inverted =3D stbi__get8(s);
   // int tga_alpha_bits =3D tga_inverted &amp; 15; // the 4 lowest bits - =
unused (useless?)
   //   image data
   unsigned char *tga_data;
   unsigned char *tga_palette =3D NULL;
   int i, j;
   unsigned char raw_data[4] =3D {0};
   int RLE_count =3D 0;
   int RLE_repeating =3D 0;
   int read_next_pixel =3D 1;
   STBI_NOTUSED(ri);

   //   do a tiny bit of precessing
   if ( tga_image_type &gt;=3D 8 )
   {
      tga_image_type -=3D 8;
      tga_is_RLE =3D 1;
   }
   tga_inverted =3D 1 - ((tga_inverted &gt;&gt; 5) &amp; 1);

   //   If I'm paletted, then I'll use the number of bits from the palette
   if ( tga_indexed ) tga_comp =3D stbi__tga_get_comp(tga_palette_bits, 0, =
&amp;tga_rgb16);
   else tga_comp =3D stbi__tga_get_comp(tga_bits_per_pixel, (tga_image_type=
 =3D=3D 3), &amp;tga_rgb16);

   if(!tga_comp) // shouldn't really happen, stbi__tga_test() should have e=
nsured basic consistency
      return stbi__errpuc("bad format", "Can't find out TGA pixelformat");

   //   tga info
   *x =3D tga_width;
   *y =3D tga_height;
   if (comp) *comp =3D tga_comp;

   if (!stbi__mad3sizes_valid(tga_width, tga_height, tga_comp, 0))
      return stbi__errpuc("too large", "Corrupt TGA");

   tga_data =3D (unsigned char*)stbi__malloc_mad3(tga_width, tga_height, tg=
a_comp, 0);
   if (!tga_data) return stbi__errpuc("outofmem", "Out of memory");

   // skip to the data's starting position (offset usually =3D 0)
   stbi__skip(s, tga_offset );

   if ( !tga_indexed &amp;&amp; !tga_is_RLE &amp;&amp; !tga_rgb16 ) {
      for (i=3D0; i &lt; tga_height; ++i) {
         int row =3D tga_inverted ? tga_height -i - 1 : i;
         stbi_uc *tga_row =3D tga_data + row*tga_width*tga_comp;
         stbi__getn(s, tga_row, tga_width * tga_comp);
      }
   } else  {
      //   do I need to load a palette?
      if ( tga_indexed)
      {
         //   any data to skip? (offset usually =3D 0)
         stbi__skip(s, tga_palette_start );
         //   load the palette
         tga_palette =3D (unsigned char*)stbi__malloc_mad2(tga_palette_len,=
 tga_comp, 0);
         if (!tga_palette) {
            STBI_FREE(tga_data);
            return stbi__errpuc("outofmem", "Out of memory");
         }
         if (tga_rgb16) {
            stbi_uc *pal_entry =3D tga_palette;
            STBI_ASSERT(tga_comp =3D=3D STBI_rgb);
            for (i=3D0; i &lt; tga_palette_len; ++i) {
               stbi__tga_read_rgb16(s, pal_entry);
               pal_entry +=3D tga_comp;
            }
         } else if (!stbi__getn(s, tga_palette, tga_palette_len * tga_comp)=
) {
               STBI_FREE(tga_data);
               STBI_FREE(tga_palette);
               return stbi__errpuc("bad palette", "Corrupt TGA");
         }
      }
      //   load the data
      for (i=3D0; i &lt; tga_width * tga_height; ++i)
      {
         //   if I'm in RLE mode, do I need to get a RLE stbi__pngchunk?
         if ( tga_is_RLE )
         {
            if ( RLE_count =3D=3D 0 )
            {
               //   yep, get the next byte as a RLE command
               int RLE_cmd =3D stbi__get8(s);
               RLE_count =3D 1 + (RLE_cmd &amp; 127);
               RLE_repeating =3D RLE_cmd &gt;&gt; 7;
               read_next_pixel =3D 1;
            } else if ( !RLE_repeating )
            {
               read_next_pixel =3D 1;
            }
         } else
         {
            read_next_pixel =3D 1;
         }
         //   OK, if I need to read a pixel, do it now
         if ( read_next_pixel )
         {
            //   load however much data we did have
            if ( tga_indexed )
            {
               // read in index, then perform the lookup
               int pal_idx =3D (tga_bits_per_pixel =3D=3D 8) ? stbi__get8(s=
) : stbi__get16le(s);
               if ( pal_idx &gt;=3D tga_palette_len ) {
                  // invalid index
                  pal_idx =3D 0;
               }
               pal_idx *=3D tga_comp;
               for (j =3D 0; j &lt; tga_comp; ++j) {
                  raw_data[j] =3D tga_palette[pal_idx+j];
               }
            } else if(tga_rgb16) {
               STBI_ASSERT(tga_comp =3D=3D STBI_rgb);
               stbi__tga_read_rgb16(s, raw_data);
            } else {
               //   read in the data raw
               for (j =3D 0; j &lt; tga_comp; ++j) {
                  raw_data[j] =3D stbi__get8(s);
               }
            }
            //   clear the reading flag for the next pixel
            read_next_pixel =3D 0;
         } // end of reading a pixel

         // copy data
         for (j =3D 0; j &lt; tga_comp; ++j)
           tga_data[i*tga_comp+j] =3D raw_data[j];

         //   in case we're in RLE mode, keep counting down
         --RLE_count;
      }
      //   do I need to invert the image?
      if ( tga_inverted )
      {
         for (j =3D 0; j*2 &lt; tga_height; ++j)
         {
            int index1 =3D j * tga_width * tga_comp;
            int index2 =3D (tga_height - 1 - j) * tga_width * tga_comp;
            for (i =3D tga_width * tga_comp; i &gt; 0; --i)
            {
               unsigned char temp =3D tga_data[index1];
               tga_data[index1] =3D tga_data[index2];
               tga_data[index2] =3D temp;
               ++index1;
               ++index2;
            }
         }
      }
      //   clear my palette, if I had one
      if ( tga_palette !=3D NULL )
      {
         STBI_FREE( tga_palette );
      }
   }

   // swap RGB - if the source data was RGB16, it already is in the right o=
rder
   if (tga_comp &gt;=3D 3 &amp;&amp; !tga_rgb16)
   {
      unsigned char* tga_pixel =3D tga_data;
      for (i=3D0; i &lt; tga_width * tga_height; ++i)
      {
         unsigned char temp =3D tga_pixel[0];
         tga_pixel[0] =3D tga_pixel[2];
         tga_pixel[2] =3D temp;
         tga_pixel +=3D tga_comp;
      }
   }

   // convert to target component count
   if (req_comp &amp;&amp; req_comp !=3D tga_comp)
      tga_data =3D stbi__convert_format(tga_data, tga_comp, req_comp, tga_w=
idth, tga_height);

   //   the things I do to get rid of an error message, and yet keep
   //   Microsoft's C compilers happy... [8^(
   tga_palette_start =3D tga_palette_len =3D tga_palette_bits =3D
         tga_x_origin =3D tga_y_origin =3D 0;
   //   OK, done
   return tga_data;
}
#endif

// ************************************************************************=
*************************
// Photoshop PSD loader -- PD by Thatcher Ulrich, integration by Nicolas Sc=
hulz, tweaked by STB

#ifndef STBI_NO_PSD
static int stbi__psd_test(stbi__context *s)
{
   int r =3D (stbi__get32be(s) =3D=3D 0x38425053);
   stbi__rewind(s);
   return r;
}

static int stbi__psd_decode_rle(stbi__context *s, stbi_uc *p, int pixelCoun=
t)
{
   int count, nleft, len;

   count =3D 0;
   while ((nleft =3D pixelCount - count) &gt; 0) {
      len =3D stbi__get8(s);
      if (len =3D=3D 128) {
         // No-op.
      } else if (len &lt; 128) {
         // Copy next len+1 bytes literally.
         len++;
         if (len &gt; nleft) return 0; // corrupt data
         count +=3D len;
         while (len) {
            *p =3D stbi__get8(s);
            p +=3D 4;
            len--;
         }
      } else if (len &gt; 128) {
         stbi_uc   val;
         // Next -len+1 bytes in the dest are replicated from next source b=
yte.
         // (Interpret len as a negative 8-bit int.)
         len =3D 257 - len;
         if (len &gt; nleft) return 0; // corrupt data
         val =3D stbi__get8(s);
         count +=3D len;
         while (len) {
            *p =3D val;
            p +=3D 4;
            len--;
         }
      }
   }

   return 1;
}

static void *stbi__psd_load(stbi__context *s, int *x, int *y, int *comp, in=
t req_comp, stbi__result_info *ri, int bpc)
{
   int pixelCount;
   int channelCount, compression;
   int channel, i;
   int bitdepth;
   int w,h;
   stbi_uc *out;
   STBI_NOTUSED(ri);

   // Check identifier
   if (stbi__get32be(s) !=3D 0x38425053)   // "8BPS"
      return stbi__errpuc("not PSD", "Corrupt PSD image");

   // Check file type version.
   if (stbi__get16be(s) !=3D 1)
      return stbi__errpuc("wrong version", "Unsupported version of PSD imag=
e");

   // Skip 6 reserved bytes.
   stbi__skip(s, 6 );

   // Read the number of channels (R, G, B, A, etc).
   channelCount =3D stbi__get16be(s);
   if (channelCount &lt; 0 || channelCount &gt; 16)
      return stbi__errpuc("wrong channel count", "Unsupported number of cha=
nnels in PSD image");

   // Read the rows and columns of the image.
   h =3D stbi__get32be(s);
   w =3D stbi__get32be(s);

   // Make sure the depth is 8 bits.
   bitdepth =3D stbi__get16be(s);
   if (bitdepth !=3D 8 &amp;&amp; bitdepth !=3D 16)
      return stbi__errpuc("unsupported bit depth", "PSD bit depth is not 8 =
or 16 bit");

   // Make sure the color mode is RGB.
   // Valid options are:
   //   0: Bitmap
   //   1: Grayscale
   //   2: Indexed color
   //   3: RGB color
   //   4: CMYK color
   //   7: Multichannel
   //   8: Duotone
   //   9: Lab color
   if (stbi__get16be(s) !=3D 3)
      return stbi__errpuc("wrong color format", "PSD is not in RGB color fo=
rmat");

   // Skip the Mode Data.  (It's the palette for indexed color; other info =
for other modes.)
   stbi__skip(s,stbi__get32be(s) );

   // Skip the image resources.  (resolution, pen tool paths, etc)
   stbi__skip(s, stbi__get32be(s) );

   // Skip the reserved data.
   stbi__skip(s, stbi__get32be(s) );

   // Find out if the data is compressed.
   // Known values:
   //   0: no compression
   //   1: RLE compressed
   compression =3D stbi__get16be(s);
   if (compression &gt; 1)
      return stbi__errpuc("bad compression", "PSD has an unknown compressio=
n format");

   // Check size
   if (!stbi__mad3sizes_valid(4, w, h, 0))
      return stbi__errpuc("too large", "Corrupt PSD");

   // Create the destination image.

   if (!compression &amp;&amp; bitdepth =3D=3D 16 &amp;&amp; bpc =3D=3D 16)=
 {
      out =3D (stbi_uc *) stbi__malloc_mad3(8, w, h, 0);
      ri-&gt;bits_per_channel =3D 16;
   } else
      out =3D (stbi_uc *) stbi__malloc(4 * w*h);

   if (!out) return stbi__errpuc("outofmem", "Out of memory");
   pixelCount =3D w*h;

   // Initialize the data to zero.
   //memset( out, 0, pixelCount * 4 );

   // Finally, the image data.
   if (compression) {
      // RLE as used by .PSD and .TIFF
      // Loop until you get the number of unpacked bytes you are expecting:
      //     Read the next source byte into n.
      //     If n is between 0 and 127 inclusive, copy the next n+1 bytes l=
iterally.
      //     Else if n is between -127 and -1 inclusive, copy the next byte=
 -n+1 times.
      //     Else if n is 128, noop.
      // Endloop

      // The RLE-compressed data is preceded by a 2-byte data count for eac=
h row in the data,
      // which we're going to just skip.
      stbi__skip(s, h * channelCount * 2 );

      // Read the RLE data by channel.
      for (channel =3D 0; channel &lt; 4; channel++) {
         stbi_uc *p;

         p =3D out+channel;
         if (channel &gt;=3D channelCount) {
            // Fill this channel with default data.
            for (i =3D 0; i &lt; pixelCount; i++, p +=3D 4)
               *p =3D (channel =3D=3D 3 ? 255 : 0);
         } else {
            // Read the RLE data.
            if (!stbi__psd_decode_rle(s, p, pixelCount)) {
               STBI_FREE(out);
               return stbi__errpuc("corrupt", "bad RLE data");
            }
         }
      }

   } else {
      // We're at the raw image data.  It's each channel in order (Red, Gre=
en, Blue, Alpha, ...)
      // where each channel consists of an 8-bit (or 16-bit) value for each=
 pixel in the image.

      // Read the data by channel.
      for (channel =3D 0; channel &lt; 4; channel++) {
         if (channel &gt;=3D channelCount) {
            // Fill this channel with default data.
            if (bitdepth =3D=3D 16 &amp;&amp; bpc =3D=3D 16) {
               stbi__uint16 *q =3D ((stbi__uint16 *) out) + channel;
               stbi__uint16 val =3D channel =3D=3D 3 ? 65535 : 0;
               for (i =3D 0; i &lt; pixelCount; i++, q +=3D 4)
                  *q =3D val;
            } else {
               stbi_uc *p =3D out+channel;
               stbi_uc val =3D channel =3D=3D 3 ? 255 : 0;
               for (i =3D 0; i &lt; pixelCount; i++, p +=3D 4)
                  *p =3D val;
            }
         } else {
            if (ri-&gt;bits_per_channel =3D=3D 16) {    // output bpc
               stbi__uint16 *q =3D ((stbi__uint16 *) out) + channel;
               for (i =3D 0; i &lt; pixelCount; i++, q +=3D 4)
                  *q =3D (stbi__uint16) stbi__get16be(s);
            } else {
               stbi_uc *p =3D out+channel;
               if (bitdepth =3D=3D 16) {  // input bpc
                  for (i =3D 0; i &lt; pixelCount; i++, p +=3D 4)
                     *p =3D (stbi_uc) (stbi__get16be(s) &gt;&gt; 8);
               } else {
                  for (i =3D 0; i &lt; pixelCount; i++, p +=3D 4)
                     *p =3D stbi__get8(s);
               }
            }
         }
      }
   }

   // remove weird white matte from PSD
   if (channelCount &gt;=3D 4) {
      if (ri-&gt;bits_per_channel =3D=3D 16) {
         for (i=3D0; i &lt; w*h; ++i) {
            stbi__uint16 *pixel =3D (stbi__uint16 *) out + 4*i;
            if (pixel[3] !=3D 0 &amp;&amp; pixel[3] !=3D 65535) {
               float a =3D pixel[3] / 65535.0f;
               float ra =3D 1.0f / a;
               float inv_a =3D 65535.0f * (1 - ra);
               pixel[0] =3D (stbi__uint16) (pixel[0]*ra + inv_a);
               pixel[1] =3D (stbi__uint16) (pixel[1]*ra + inv_a);
               pixel[2] =3D (stbi__uint16) (pixel[2]*ra + inv_a);
            }
         }
      } else {
         for (i=3D0; i &lt; w*h; ++i) {
            unsigned char *pixel =3D out + 4*i;
            if (pixel[3] !=3D 0 &amp;&amp; pixel[3] !=3D 255) {
               float a =3D pixel[3] / 255.0f;
               float ra =3D 1.0f / a;
               float inv_a =3D 255.0f * (1 - ra);
               pixel[0] =3D (unsigned char) (pixel[0]*ra + inv_a);
               pixel[1] =3D (unsigned char) (pixel[1]*ra + inv_a);
               pixel[2] =3D (unsigned char) (pixel[2]*ra + inv_a);
            }
         }
      }
   }

   // convert to desired output format
   if (req_comp &amp;&amp; req_comp !=3D 4) {
      if (ri-&gt;bits_per_channel =3D=3D 16)
         out =3D (stbi_uc *) stbi__convert_format16((stbi__uint16 *) out, 4=
, req_comp, w, h);
      else
         out =3D stbi__convert_format(out, 4, req_comp, w, h);
      if (out =3D=3D NULL) return out; // stbi__convert_format frees input =
on failure
   }

   if (comp) *comp =3D 4;
   *y =3D h;
   *x =3D w;

   return out;
}
#endif

// ************************************************************************=
*************************
// Softimage PIC loader
// by Tom Seddon
//
// See http://softimage.wiki.softimage.com/index.php/INFO:_PIC_file_format
// See http://ozviz.wasp.uwa.edu.au/~pbourke/dataformats/softimagepic/

#ifndef STBI_NO_PIC
static int stbi__pic_is4(stbi__context *s,const char *str)
{
   int i;
   for (i=3D0; i&lt;4; ++i)
      if (stbi__get8(s) !=3D (stbi_uc)str[i])
         return 0;

   return 1;
}

static int stbi__pic_test_core(stbi__context *s)
{
   int i;

   if (!stbi__pic_is4(s,"\x53\x80\xF6\x34"))
      return 0;

   for(i=3D0;i&lt;84;++i)
      stbi__get8(s);

   if (!stbi__pic_is4(s,"PICT"))
      return 0;

   return 1;
}

typedef struct
{
   stbi_uc size,type,channel;
} stbi__pic_packet;

static stbi_uc *stbi__readval(stbi__context *s, int channel, stbi_uc *dest)
{
   int mask=3D0x80, i;

   for (i=3D0; i&lt;4; ++i, mask&gt;&gt;=3D1) {
      if (channel &amp; mask) {
         if (stbi__at_eof(s)) return stbi__errpuc("bad file","PIC file too =
short");
         dest[i]=3Dstbi__get8(s);
      }
   }

   return dest;
}

static void stbi__copyval(int channel,stbi_uc *dest,const stbi_uc *src)
{
   int mask=3D0x80,i;

   for (i=3D0;i&lt;4; ++i, mask&gt;&gt;=3D1)
      if (channel&amp;mask)
         dest[i]=3Dsrc[i];
}

static stbi_uc *stbi__pic_load_core(stbi__context *s,int width,int height,i=
nt *comp, stbi_uc *result)
{
   int act_comp=3D0,num_packets=3D0,y,chained;
   stbi__pic_packet packets[10];

   // this will (should...) cater for even some bizarre stuff like having d=
ata
    // for the same channel in multiple packets.
   do {
      stbi__pic_packet *packet;

      if (num_packets=3D=3Dsizeof(packets)/sizeof(packets[0]))
         return stbi__errpuc("bad format","too many packets");

      packet =3D &amp;packets[num_packets++];

      chained =3D stbi__get8(s);
      packet-&gt;size    =3D stbi__get8(s);
      packet-&gt;type    =3D stbi__get8(s);
      packet-&gt;channel =3D stbi__get8(s);

      act_comp |=3D packet-&gt;channel;

      if (stbi__at_eof(s))          return stbi__errpuc("bad file","file to=
o short (reading packets)");
      if (packet-&gt;size !=3D 8)  return stbi__errpuc("bad format","packet=
 isn't 8bpp");
   } while (chained);

   *comp =3D (act_comp &amp; 0x10 ? 4 : 3); // has alpha channel?

   for(y=3D0; y&lt;height; ++y) {
      int packet_idx;

      for(packet_idx=3D0; packet_idx &lt; num_packets; ++packet_idx) {
         stbi__pic_packet *packet =3D &amp;packets[packet_idx];
         stbi_uc *dest =3D result+y*width*4;

         switch (packet-&gt;type) {
            default:
               return stbi__errpuc("bad format","packet has bad compression=
 type");

            case 0: {//uncompressed
               int x;

               for(x=3D0;x&lt;width;++x, dest+=3D4)
                  if (!stbi__readval(s,packet-&gt;channel,dest))
                     return 0;
               break;
            }

            case 1://Pure RLE
               {
                  int left=3Dwidth, i;

                  while (left&gt;0) {
                     stbi_uc count,value[4];

                     count=3Dstbi__get8(s);
                     if (stbi__at_eof(s))   return stbi__errpuc("bad file",=
"file too short (pure read count)");

                     if (count &gt; left)
                        count =3D (stbi_uc) left;

                     if (!stbi__readval(s,packet-&gt;channel,value))  retur=
n 0;

                     for(i=3D0; i&lt;count; ++i,dest+=3D4)
                        stbi__copyval(packet-&gt;channel,dest,value);
                     left -=3D count;
                  }
               }
               break;

            case 2: {//Mixed RLE
               int left=3Dwidth;
               while (left&gt;0) {
                  int count =3D stbi__get8(s), i;
                  if (stbi__at_eof(s))  return stbi__errpuc("bad file","fil=
e too short (mixed read count)");

                  if (count &gt;=3D 128) { // Repeated
                     stbi_uc value[4];

                     if (count=3D=3D128)
                        count =3D stbi__get16be(s);
                     else
                        count -=3D 127;
                     if (count &gt; left)
                        return stbi__errpuc("bad file","scanline overrun");

                     if (!stbi__readval(s,packet-&gt;channel,value))
                        return 0;

                     for(i=3D0;i&lt;count;++i, dest +=3D 4)
                        stbi__copyval(packet-&gt;channel,dest,value);
                  } else { // Raw
                     ++count;
                     if (count&gt;left) return stbi__errpuc("bad file","sca=
nline overrun");

                     for(i=3D0;i&lt;count;++i, dest+=3D4)
                        if (!stbi__readval(s,packet-&gt;channel,dest))
                           return 0;
                  }
                  left-=3Dcount;
               }
               break;
            }
         }
      }
   }

   return result;
}

static void *stbi__pic_load(stbi__context *s,int *px,int *py,int *comp,int =
req_comp, stbi__result_info *ri)
{
   stbi_uc *result;
   int i, x,y, internal_comp;
   STBI_NOTUSED(ri);

   if (!comp) comp =3D &amp;internal_comp;

   for (i=3D0; i&lt;92; ++i)
      stbi__get8(s);

   x =3D stbi__get16be(s);
   y =3D stbi__get16be(s);
   if (stbi__at_eof(s))  return stbi__errpuc("bad file","file too short (pi=
c header)");
   if (!stbi__mad3sizes_valid(x, y, 4, 0)) return stbi__errpuc("too large",=
 "PIC image too large to decode");

   stbi__get32be(s); //skip `ratio'
   stbi__get16be(s); //skip `fields'
   stbi__get16be(s); //skip `pad'

   // intermediate buffer is RGBA
   result =3D (stbi_uc *) stbi__malloc_mad3(x, y, 4, 0);
   memset(result, 0xff, x*y*4);

   if (!stbi__pic_load_core(s,x,y,comp, result)) {
      STBI_FREE(result);
      result=3D0;
   }
   *px =3D x;
   *py =3D y;
   if (req_comp =3D=3D 0) req_comp =3D *comp;
   result=3Dstbi__convert_format(result,4,req_comp,x,y);

   return result;
}

static int stbi__pic_test(stbi__context *s)
{
   int r =3D stbi__pic_test_core(s);
   stbi__rewind(s);
   return r;
}
#endif

// ************************************************************************=
*************************
// GIF loader -- public domain by Jean-Marc Lienher -- simplified/shrunk by=
 stb

#ifndef STBI_NO_GIF
typedef struct
{
   stbi__int16 prefix;
   stbi_uc first;
   stbi_uc suffix;
} stbi__gif_lzw;

typedef struct
{
   int w,h;
   stbi_uc *out;                 // output buffer (always 4 components)
   stbi_uc *background;          // The current "background" as far as a gi=
f is concerned
   stbi_uc *history;=20
   int flags, bgindex, ratio, transparent, eflags;
   stbi_uc  pal[256][4];
   stbi_uc lpal[256][4];
   stbi__gif_lzw codes[8192];
   stbi_uc *color_table;
   int parse, step;
   int lflags;
   int start_x, start_y;
   int max_x, max_y;
   int cur_x, cur_y;
   int line_size;
   int delay;
} stbi__gif;

static int stbi__gif_test_raw(stbi__context *s)
{
   int sz;
   if (stbi__get8(s) !=3D 'G' || stbi__get8(s) !=3D 'I' || stbi__get8(s) !=
=3D 'F' || stbi__get8(s) !=3D '8') return 0;
   sz =3D stbi__get8(s);
   if (sz !=3D '9' &amp;&amp; sz !=3D '7') return 0;
   if (stbi__get8(s) !=3D 'a') return 0;
   return 1;
}

static int stbi__gif_test(stbi__context *s)
{
   int r =3D stbi__gif_test_raw(s);
   stbi__rewind(s);
   return r;
}

static void stbi__gif_parse_colortable(stbi__context *s, stbi_uc pal[256][4=
], int num_entries, int transp)
{
   int i;
   for (i=3D0; i &lt; num_entries; ++i) {
      pal[i][2] =3D stbi__get8(s);
      pal[i][1] =3D stbi__get8(s);
      pal[i][0] =3D stbi__get8(s);
      pal[i][3] =3D transp =3D=3D i ? 0 : 255;
   }
}

static int stbi__gif_header(stbi__context *s, stbi__gif *g, int *comp, int =
is_info)
{
   stbi_uc version;
   if (stbi__get8(s) !=3D 'G' || stbi__get8(s) !=3D 'I' || stbi__get8(s) !=
=3D 'F' || stbi__get8(s) !=3D '8')
      return stbi__err("not GIF", "Corrupt GIF");

   version =3D stbi__get8(s);
   if (version !=3D '7' &amp;&amp; version !=3D '9')    return stbi__err("n=
ot GIF", "Corrupt GIF");
   if (stbi__get8(s) !=3D 'a')                return stbi__err("not GIF", "=
Corrupt GIF");

   stbi__g_failure_reason =3D "";
   g-&gt;w =3D stbi__get16le(s);
   g-&gt;h =3D stbi__get16le(s);
   g-&gt;flags =3D stbi__get8(s);
   g-&gt;bgindex =3D stbi__get8(s);
   g-&gt;ratio =3D stbi__get8(s);
   g-&gt;transparent =3D -1;

   if (comp !=3D 0) *comp =3D 4;  // can't actually tell whether it's 3 or =
4 until we parse the comments

   if (is_info) return 1;

   if (g-&gt;flags &amp; 0x80)
      stbi__gif_parse_colortable(s,g-&gt;pal, 2 &lt;&lt; (g-&gt;flags &amp;=
 7), -1);

   return 1;
}

static int stbi__gif_info_raw(stbi__context *s, int *x, int *y, int *comp)
{
   stbi__gif* g =3D (stbi__gif*) stbi__malloc(sizeof(stbi__gif));
   if (!stbi__gif_header(s, g, comp, 1)) {
      STBI_FREE(g);
      stbi__rewind( s );
      return 0;
   }
   if (x) *x =3D g-&gt;w;
   if (y) *y =3D g-&gt;h;
   STBI_FREE(g);
   return 1;
}

static void stbi__out_gif_code(stbi__gif *g, stbi__uint16 code)
{
   stbi_uc *p, *c;
   int idx;=20

   // recurse to decode the prefixes, since the linked-list is backwards,
   // and working backwards through an interleaved image would be nasty
   if (g-&gt;codes[code].prefix &gt;=3D 0)
      stbi__out_gif_code(g, g-&gt;codes[code].prefix);

   if (g-&gt;cur_y &gt;=3D g-&gt;max_y) return;

   idx =3D g-&gt;cur_x + g-&gt;cur_y;=20
   p =3D &amp;g-&gt;out[idx];
   g-&gt;history[idx / 4] =3D 1; =20

   c =3D &amp;g-&gt;color_table[g-&gt;codes[code].suffix * 4];
   if (c[3] &gt; 128) { // don't render transparent pixels;=20
      p[0] =3D c[2];
      p[1] =3D c[1];
      p[2] =3D c[0];
      p[3] =3D c[3];
   }
   g-&gt;cur_x +=3D 4;

   if (g-&gt;cur_x &gt;=3D g-&gt;max_x) {
      g-&gt;cur_x =3D g-&gt;start_x;
      g-&gt;cur_y +=3D g-&gt;step;

      while (g-&gt;cur_y &gt;=3D g-&gt;max_y &amp;&amp; g-&gt;parse &gt; 0)=
 {
         g-&gt;step =3D (1 &lt;&lt; g-&gt;parse) * g-&gt;line_size;
         g-&gt;cur_y =3D g-&gt;start_y + (g-&gt;step &gt;&gt; 1);
         --g-&gt;parse;
      }
   }
}

static stbi_uc *stbi__process_gif_raster(stbi__context *s, stbi__gif *g)
{
   stbi_uc lzw_cs;
   stbi__int32 len, init_code;
   stbi__uint32 first;
   stbi__int32 codesize, codemask, avail, oldcode, bits, valid_bits, clear;
   stbi__gif_lzw *p;

   lzw_cs =3D stbi__get8(s);
   if (lzw_cs &gt; 12) return NULL;
   clear =3D 1 &lt;&lt; lzw_cs;
   first =3D 1;
   codesize =3D lzw_cs + 1;
   codemask =3D (1 &lt;&lt; codesize) - 1;
   bits =3D 0;
   valid_bits =3D 0;
   for (init_code =3D 0; init_code &lt; clear; init_code++) {
      g-&gt;codes[init_code].prefix =3D -1;
      g-&gt;codes[init_code].first =3D (stbi_uc) init_code;
      g-&gt;codes[init_code].suffix =3D (stbi_uc) init_code;
   }

   // support no starting clear code
   avail =3D clear+2;
   oldcode =3D -1;

   len =3D 0;
   for(;;) {
      if (valid_bits &lt; codesize) {
         if (len =3D=3D 0) {
            len =3D stbi__get8(s); // start new block
            if (len =3D=3D 0)
               return g-&gt;out;
         }
         --len;
         bits |=3D (stbi__int32) stbi__get8(s) &lt;&lt; valid_bits;
         valid_bits +=3D 8;
      } else {
         stbi__int32 code =3D bits &amp; codemask;
         bits &gt;&gt;=3D codesize;
         valid_bits -=3D codesize;
         // @OPTIMIZE: is there some way we can accelerate the non-clear pa=
th?
         if (code =3D=3D clear) {  // clear code
            codesize =3D lzw_cs + 1;
            codemask =3D (1 &lt;&lt; codesize) - 1;
            avail =3D clear + 2;
            oldcode =3D -1;
            first =3D 0;
         } else if (code =3D=3D clear + 1) { // end of stream code
            stbi__skip(s, len);
            while ((len =3D stbi__get8(s)) &gt; 0)
               stbi__skip(s,len);
            return g-&gt;out;
         } else if (code &lt;=3D avail) {
            if (first) {
               return stbi__errpuc("no clear code", "Corrupt GIF");
            }

            if (oldcode &gt;=3D 0) {
               p =3D &amp;g-&gt;codes[avail++];
               if (avail &gt; 8192) {
                  return stbi__errpuc("too many codes", "Corrupt GIF");
               }

               p-&gt;prefix =3D (stbi__int16) oldcode;
               p-&gt;first =3D g-&gt;codes[oldcode].first;
               p-&gt;suffix =3D (code =3D=3D avail) ? p-&gt;first : g-&gt;c=
odes[code].first;
            } else if (code =3D=3D avail)
               return stbi__errpuc("illegal code in raster", "Corrupt GIF")=
;

            stbi__out_gif_code(g, (stbi__uint16) code);

            if ((avail &amp; codemask) =3D=3D 0 &amp;&amp; avail &lt;=3D 0x=
0FFF) {
               codesize++;
               codemask =3D (1 &lt;&lt; codesize) - 1;
            }

            oldcode =3D code;
         } else {
            return stbi__errpuc("illegal code in raster", "Corrupt GIF");
         }
      }
   }
}

// this function is designed to support animated gifs, although stb_image d=
oesn't support it
// two back is the image from two frames ago, used for a very specific disp=
osal format
static stbi_uc *stbi__gif_load_next(stbi__context *s, stbi__gif *g, int *co=
mp, int req_comp, stbi_uc *two_back)
{
   int dispose;=20
   int first_frame;=20
   int pi;=20
   int pcount;=20
   STBI_NOTUSED(req_comp);

   // on first frame, any non-written pixels get the background colour (non=
-transparent)
   first_frame =3D 0;=20
   if (g-&gt;out =3D=3D 0) {
      if (!stbi__gif_header(s, g, comp,0)) return 0; // stbi__g_failure_rea=
son set by stbi__gif_header
      if (!stbi__mad3sizes_valid(4, g-&gt;w, g-&gt;h, 0))
         return stbi__errpuc("too large", "GIF image is too large");
      pcount =3D g-&gt;w * g-&gt;h;
      g-&gt;out =3D (stbi_uc *) stbi__malloc(4 * pcount);
      g-&gt;background =3D (stbi_uc *) stbi__malloc(4 * pcount);
      g-&gt;history =3D (stbi_uc *) stbi__malloc(pcount);
      if (!g-&gt;out || !g-&gt;background || !g-&gt;history)
         return stbi__errpuc("outofmem", "Out of memory");

      // image is treated as "transparent" at the start - ie, nothing overw=
rites the current background;=20
      // background colour is only used for pixels that are not rendered fi=
rst frame, after that "background"
      // color refers to the color that was there the previous frame.=20
      memset(g-&gt;out, 0x00, 4 * pcount);
      memset(g-&gt;background, 0x00, 4 * pcount); // state of the backgroun=
d (starts transparent)
      memset(g-&gt;history, 0x00, pcount);        // pixels that were affec=
ted previous frame
      first_frame =3D 1;=20
   } else {
      // second frame - how do we dispoase of the previous one?
      dispose =3D (g-&gt;eflags &amp; 0x1C) &gt;&gt; 2;=20
      pcount =3D g-&gt;w * g-&gt;h;=20

      if ((dispose =3D=3D 3) &amp;&amp; (two_back =3D=3D 0)) {
         dispose =3D 2; // if I don't have an image to revert back to, defa=
ult to the old background
      }

      if (dispose =3D=3D 3) { // use previous graphic
         for (pi =3D 0; pi &lt; pcount; ++pi) {
            if (g-&gt;history[pi]) {
               memcpy( &amp;g-&gt;out[pi * 4], &amp;two_back[pi * 4], 4 );=
=20
            }
         }
      } else if (dispose =3D=3D 2) {=20
         // restore what was changed last frame to background before that f=
rame;=20
         for (pi =3D 0; pi &lt; pcount; ++pi) {
            if (g-&gt;history[pi]) {
               memcpy( &amp;g-&gt;out[pi * 4], &amp;g-&gt;background[pi * 4=
], 4 );=20
            }
         }
      } else {
         // This is a non-disposal case eithe way, so just=20
         // leave the pixels as is, and they will become the new background
         // 1: do not dispose
         // 0:  not specified.
      }

      // background is what out is after the undoing of the previou frame;=
=20
      memcpy( g-&gt;background, g-&gt;out, 4 * g-&gt;w * g-&gt;h );=20
   }

   // clear my history;=20
   memset( g-&gt;history, 0x00, g-&gt;w * g-&gt;h );        // pixels that =
were affected previous frame

   for (;;) {
      int tag =3D stbi__get8(s);=20
      switch (tag) {
         case 0x2C: /* Image Descriptor */
         {
            stbi__int32 x, y, w, h;
            stbi_uc *o;

            x =3D stbi__get16le(s);
            y =3D stbi__get16le(s);
            w =3D stbi__get16le(s);
            h =3D stbi__get16le(s);
            if (((x + w) &gt; (g-&gt;w)) || ((y + h) &gt; (g-&gt;h)))
               return stbi__errpuc("bad Image Descriptor", "Corrupt GIF");

            g-&gt;line_size =3D g-&gt;w * 4;
            g-&gt;start_x =3D x * 4;
            g-&gt;start_y =3D y * g-&gt;line_size;
            g-&gt;max_x   =3D g-&gt;start_x + w * 4;
            g-&gt;max_y   =3D g-&gt;start_y + h * g-&gt;line_size;
            g-&gt;cur_x   =3D g-&gt;start_x;
            g-&gt;cur_y   =3D g-&gt;start_y;

            // if the width of the specified rectangle is 0, that means
            // we may not see *any* pixels or the image is malformed;
            // to make sure this is caught, move the current y down to
            // max_y (which is what out_gif_code checks).
            if (w =3D=3D 0)
               g-&gt;cur_y =3D g-&gt;max_y;

            g-&gt;lflags =3D stbi__get8(s);

            if (g-&gt;lflags &amp; 0x40) {
               g-&gt;step =3D 8 * g-&gt;line_size; // first interlaced spac=
ing
               g-&gt;parse =3D 3;
            } else {
               g-&gt;step =3D g-&gt;line_size;
               g-&gt;parse =3D 0;
            }

            if (g-&gt;lflags &amp; 0x80) {
               stbi__gif_parse_colortable(s,g-&gt;lpal, 2 &lt;&lt; (g-&gt;l=
flags &amp; 7), g-&gt;eflags &amp; 0x01 ? g-&gt;transparent : -1);
               g-&gt;color_table =3D (stbi_uc *) g-&gt;lpal;
            } else if (g-&gt;flags &amp; 0x80) {
               g-&gt;color_table =3D (stbi_uc *) g-&gt;pal;
            } else
               return stbi__errpuc("missing color table", "Corrupt GIF");  =
         =20
           =20
            o =3D stbi__process_gif_raster(s, g);
            if (!o) return NULL;

            // if this was the first frame,=20
            pcount =3D g-&gt;w * g-&gt;h;=20
            if (first_frame &amp;&amp; (g-&gt;bgindex &gt; 0)) {
               // if first frame, any pixel not drawn to gets the backgroun=
d color
               for (pi =3D 0; pi &lt; pcount; ++pi) {
                  if (g-&gt;history[pi] =3D=3D 0) {
                     g-&gt;pal[g-&gt;bgindex][3] =3D 255; // just in case i=
t was made transparent, undo that; It will be reset next frame if need be;=
=20
                     memcpy( &amp;g-&gt;out[pi * 4], &amp;g-&gt;pal[g-&gt;b=
gindex], 4 );=20
                  }
               }
            }

            return o;
         }

         case 0x21: // Comment Extension.
         {
            int len;
            int ext =3D stbi__get8(s);=20
            if (ext =3D=3D 0xF9) { // Graphic Control Extension.
               len =3D stbi__get8(s);
               if (len =3D=3D 4) {
                  g-&gt;eflags =3D stbi__get8(s);
                  g-&gt;delay =3D 10 * stbi__get16le(s); // delay - 1/100th=
 of a second, saving as 1/1000ths.

                  // unset old transparent
                  if (g-&gt;transparent &gt;=3D 0) {
                     g-&gt;pal[g-&gt;transparent][3] =3D 255;=20
                  }=20
                  if (g-&gt;eflags &amp; 0x01) {
                     g-&gt;transparent =3D stbi__get8(s);
                     if (g-&gt;transparent &gt;=3D 0) {
                        g-&gt;pal[g-&gt;transparent][3] =3D 0;=20
                     }
                  } else {
                     // don't need transparent
                     stbi__skip(s, 1);=20
                     g-&gt;transparent =3D -1;=20
                  }
               } else {
                  stbi__skip(s, len);
                  break;
               }
            }=20
            while ((len =3D stbi__get8(s)) !=3D 0) {
               stbi__skip(s, len);
            }
            break;
         }

         case 0x3B: // gif stream termination code
            return (stbi_uc *) s; // using '1' causes warning on some compi=
lers

         default:
            return stbi__errpuc("unknown code", "Corrupt GIF");
      }
   }
}

static void *stbi__load_gif_main(stbi__context *s, int **delays, int *x, in=
t *y, int *z, int *comp, int req_comp)
{
   if (stbi__gif_test(s)) {
      int layers =3D 0;=20
      stbi_uc *u =3D 0;
      stbi_uc *out =3D 0;
      stbi_uc *two_back =3D 0;=20
      stbi__gif g;
      int stride;=20
      memset(&amp;g, 0, sizeof(g));
      if (delays) {
         *delays =3D 0;=20
      }

      do {
         u =3D stbi__gif_load_next(s, &amp;g, comp, req_comp, two_back);
         if (u =3D=3D (stbi_uc *) s) u =3D 0;  // end of animated gif marke=
r

         if (u) {
            *x =3D g.w;
            *y =3D g.h;
            ++layers;=20
            stride =3D g.w * g.h * 4;=20
        =20
            if (out) {
               out =3D (stbi_uc*) STBI_REALLOC( out, layers * stride );=20
               if (delays) {
                  *delays =3D (int*) STBI_REALLOC( *delays, sizeof(int) * l=
ayers );=20
               }
            } else {
               out =3D (stbi_uc*)stbi__malloc( layers * stride );=20
               if (delays) {
                  *delays =3D (int*) stbi__malloc( layers * sizeof(int) );=
=20
               }
            }
            memcpy( out + ((layers - 1) * stride), u, stride );=20
            if (layers &gt;=3D 2) {
               two_back =3D out - 2 * stride;=20
            }

            if (delays) {
               (*delays)[layers - 1U] =3D g.delay;=20
            }
         }
      } while (u !=3D 0);=20

      // free temp buffer;=20
      STBI_FREE(g.out);=20
      STBI_FREE(g.history);=20
      STBI_FREE(g.background);=20

      // do the final conversion after loading everything;=20
      if (req_comp &amp;&amp; req_comp !=3D 4)
         out =3D stbi__convert_format(out, 4, req_comp, layers * g.w, g.h);

      *z =3D layers;=20
      return out;
   } else {
      return stbi__errpuc("not GIF", "Image was not as a gif type.");=20
   }
}

static void *stbi__gif_load(stbi__context *s, int *x, int *y, int *comp, in=
t req_comp, stbi__result_info *ri)
{
   stbi_uc *u =3D 0;
   stbi__gif g;
   memset(&amp;g, 0, sizeof(g));
   STBI_NOTUSED(ri);

   u =3D stbi__gif_load_next(s, &amp;g, comp, req_comp, 0);
   if (u =3D=3D (stbi_uc *) s) u =3D 0;  // end of animated gif marker
   if (u) {
      *x =3D g.w;
      *y =3D g.h;

      // moved conversion to after successful load so that the same
      // can be done for multiple frames.=20
      if (req_comp &amp;&amp; req_comp !=3D 4)
         u =3D stbi__convert_format(u, 4, req_comp, g.w, g.h);
   } else if (g.out) {
      // if there was an error and we allocated an image buffer, free it!
      STBI_FREE(g.out);
   }

   // free buffers needed for multiple frame loading;=20
   STBI_FREE(g.history);
   STBI_FREE(g.background);=20

   return u;
}

static int stbi__gif_info(stbi__context *s, int *x, int *y, int *comp)
{
   return stbi__gif_info_raw(s,x,y,comp);
}
#endif

// ************************************************************************=
*************************
// Radiance RGBE HDR loader
// originally by Nicolas Schulz
#ifndef STBI_NO_HDR
static int stbi__hdr_test_core(stbi__context *s, const char *signature)
{
   int i;
   for (i=3D0; signature[i]; ++i)
      if (stbi__get8(s) !=3D signature[i])
          return 0;
   stbi__rewind(s);
   return 1;
}

static int stbi__hdr_test(stbi__context* s)
{
   int r =3D stbi__hdr_test_core(s, "#?RADIANCE\n");
   stbi__rewind(s);
   if(!r) {
       r =3D stbi__hdr_test_core(s, "#?RGBE\n");
       stbi__rewind(s);
   }
   return r;
}

#define STBI__HDR_BUFLEN  1024
static char *stbi__hdr_gettoken(stbi__context *z, char *buffer)
{
   int len=3D0;
   char c =3D '\0';

   c =3D (char) stbi__get8(z);

   while (!stbi__at_eof(z) &amp;&amp; c !=3D '\n') {
      buffer[len++] =3D c;
      if (len =3D=3D STBI__HDR_BUFLEN-1) {
         // flush to end of line
         while (!stbi__at_eof(z) &amp;&amp; stbi__get8(z) !=3D '\n')
            ;
         break;
      }
      c =3D (char) stbi__get8(z);
   }

   buffer[len] =3D 0;
   return buffer;
}

static void stbi__hdr_convert(float *output, stbi_uc *input, int req_comp)
{
   if ( input[3] !=3D 0 ) {
      float f1;
      // Exponent
      f1 =3D (float) ldexp(1.0f, input[3] - (int)(128 + 8));
      if (req_comp &lt;=3D 2)
         output[0] =3D (input[0] + input[1] + input[2]) * f1 / 3;
      else {
         output[0] =3D input[0] * f1;
         output[1] =3D input[1] * f1;
         output[2] =3D input[2] * f1;
      }
      if (req_comp =3D=3D 2) output[1] =3D 1;
      if (req_comp =3D=3D 4) output[3] =3D 1;
   } else {
      switch (req_comp) {
         case 4: output[3] =3D 1; /* fallthrough */
         case 3: output[0] =3D output[1] =3D output[2] =3D 0;
                 break;
         case 2: output[1] =3D 1; /* fallthrough */
         case 1: output[0] =3D 0;
                 break;
      }
   }
}

static float *stbi__hdr_load(stbi__context *s, int *x, int *y, int *comp, i=
nt req_comp, stbi__result_info *ri)
{
   char buffer[STBI__HDR_BUFLEN];
   char *token;
   int valid =3D 0;
   int width, height;
   stbi_uc *scanline;
   float *hdr_data;
   int len;
   unsigned char count, value;
   int i, j, k, c1,c2, z;
   const char *headerToken;
   STBI_NOTUSED(ri);

   // Check identifier
   headerToken =3D stbi__hdr_gettoken(s,buffer);
   if (strcmp(headerToken, "#?RADIANCE") !=3D 0 &amp;&amp; strcmp(headerTok=
en, "#?RGBE") !=3D 0)
      return stbi__errpf("not HDR", "Corrupt HDR image");

   // Parse header
   for(;;) {
      token =3D stbi__hdr_gettoken(s,buffer);
      if (token[0] =3D=3D 0) break;
      if (strcmp(token, "FORMAT=3D32-bit_rle_rgbe") =3D=3D 0) valid =3D 1;
   }

   if (!valid)    return stbi__errpf("unsupported format", "Unsupported HDR=
 format");

   // Parse width and height
   // can't use sscanf() if we're not using stdio!
   token =3D stbi__hdr_gettoken(s,buffer);
   if (strncmp(token, "-Y ", 3))  return stbi__errpf("unsupported data layo=
ut", "Unsupported HDR format");
   token +=3D 3;
   height =3D (int) strtol(token, &amp;token, 10);
   while (*token =3D=3D ' ') ++token;
   if (strncmp(token, "+X ", 3))  return stbi__errpf("unsupported data layo=
ut", "Unsupported HDR format");
   token +=3D 3;
   width =3D (int) strtol(token, NULL, 10);

   *x =3D width;
   *y =3D height;

   if (comp) *comp =3D 3;
   if (req_comp =3D=3D 0) req_comp =3D 3;

   if (!stbi__mad4sizes_valid(width, height, req_comp, sizeof(float), 0))
      return stbi__errpf("too large", "HDR image is too large");

   // Read data
   hdr_data =3D (float *) stbi__malloc_mad4(width, height, req_comp, sizeof=
(float), 0);
   if (!hdr_data)
      return stbi__errpf("outofmem", "Out of memory");

   // Load image data
   // image data is stored as some number of sca
   if ( width &lt; 8 || width &gt;=3D 32768) {
      // Read flat data
      for (j=3D0; j &lt; height; ++j) {
         for (i=3D0; i &lt; width; ++i) {
            stbi_uc rgbe[4];
           main_decode_loop:
            stbi__getn(s, rgbe, 4);
            stbi__hdr_convert(hdr_data + j * width * req_comp + i * req_com=
p, rgbe, req_comp);
         }
      }
   } else {
      // Read RLE-encoded data
      scanline =3D NULL;

      for (j =3D 0; j &lt; height; ++j) {
         c1 =3D stbi__get8(s);
         c2 =3D stbi__get8(s);
         len =3D stbi__get8(s);
         if (c1 !=3D 2 || c2 !=3D 2 || (len &amp; 0x80)) {
            // not run-length encoded, so we have to actually use THIS data=
 as a decoded
            // pixel (note this can't be a valid pixel--one of RGB must be =
&gt;=3D 128)
            stbi_uc rgbe[4];
            rgbe[0] =3D (stbi_uc) c1;
            rgbe[1] =3D (stbi_uc) c2;
            rgbe[2] =3D (stbi_uc) len;
            rgbe[3] =3D (stbi_uc) stbi__get8(s);
            stbi__hdr_convert(hdr_data, rgbe, req_comp);
            i =3D 1;
            j =3D 0;
            STBI_FREE(scanline);
            goto main_decode_loop; // yes, this makes no sense
         }
         len &lt;&lt;=3D 8;
         len |=3D stbi__get8(s);
         if (len !=3D width) { STBI_FREE(hdr_data); STBI_FREE(scanline); re=
turn stbi__errpf("invalid decoded scanline length", "corrupt HDR"); }
         if (scanline =3D=3D NULL) {
            scanline =3D (stbi_uc *) stbi__malloc_mad2(width, 4, 0);
            if (!scanline) {
               STBI_FREE(hdr_data);
               return stbi__errpf("outofmem", "Out of memory");
            }
         }

         for (k =3D 0; k &lt; 4; ++k) {
            int nleft;
            i =3D 0;
            while ((nleft =3D width - i) &gt; 0) {
               count =3D stbi__get8(s);
               if (count &gt; 128) {
                  // Run
                  value =3D stbi__get8(s);
                  count -=3D 128;
                  if (count &gt; nleft) { STBI_FREE(hdr_data); STBI_FREE(sc=
anline); return stbi__errpf("corrupt", "bad RLE data in HDR"); }
                  for (z =3D 0; z &lt; count; ++z)
                     scanline[i++ * 4 + k] =3D value;
               } else {
                  // Dump
                  if (count &gt; nleft) { STBI_FREE(hdr_data); STBI_FREE(sc=
anline); return stbi__errpf("corrupt", "bad RLE data in HDR"); }
                  for (z =3D 0; z &lt; count; ++z)
                     scanline[i++ * 4 + k] =3D stbi__get8(s);
               }
            }
         }
         for (i=3D0; i &lt; width; ++i)
            stbi__hdr_convert(hdr_data+(j*width + i)*req_comp, scanline + i=
*4, req_comp);
      }
      if (scanline)
         STBI_FREE(scanline);
   }

   return hdr_data;
}

static int stbi__hdr_info(stbi__context *s, int *x, int *y, int *comp)
{
   char buffer[STBI__HDR_BUFLEN];
   char *token;
   int valid =3D 0;
   int dummy;

   if (!x) x =3D &amp;dummy;
   if (!y) y =3D &amp;dummy;
   if (!comp) comp =3D &amp;dummy;

   if (stbi__hdr_test(s) =3D=3D 0) {
       stbi__rewind( s );
       return 0;
   }

   for(;;) {
      token =3D stbi__hdr_gettoken(s,buffer);
      if (token[0] =3D=3D 0) break;
      if (strcmp(token, "FORMAT=3D32-bit_rle_rgbe") =3D=3D 0) valid =3D 1;
   }

   if (!valid) {
       stbi__rewind( s );
       return 0;
   }
   token =3D stbi__hdr_gettoken(s,buffer);
   if (strncmp(token, "-Y ", 3)) {
       stbi__rewind( s );
       return 0;
   }
   token +=3D 3;
   *y =3D (int) strtol(token, &amp;token, 10);
   while (*token =3D=3D ' ') ++token;
   if (strncmp(token, "+X ", 3)) {
       stbi__rewind( s );
       return 0;
   }
   token +=3D 3;
   *x =3D (int) strtol(token, NULL, 10);
   *comp =3D 3;
   return 1;
}
#endif // STBI_NO_HDR

#ifndef STBI_NO_BMP
static int stbi__bmp_info(stbi__context *s, int *x, int *y, int *comp)
{
   void *p;
   stbi__bmp_data info;

   info.all_a =3D 255;
   p =3D stbi__bmp_parse_header(s, &amp;info);
   stbi__rewind( s );
   if (p =3D=3D NULL)
      return 0;
   if (x) *x =3D s-&gt;img_x;
   if (y) *y =3D s-&gt;img_y;
   if (comp) *comp =3D info.ma ? 4 : 3;
   return 1;
}
#endif

#ifndef STBI_NO_PSD
static int stbi__psd_info(stbi__context *s, int *x, int *y, int *comp)
{
   int channelCount, dummy, depth;
   if (!x) x =3D &amp;dummy;
   if (!y) y =3D &amp;dummy;
   if (!comp) comp =3D &amp;dummy;
   if (stbi__get32be(s) !=3D 0x38425053) {
       stbi__rewind( s );
       return 0;
   }
   if (stbi__get16be(s) !=3D 1) {
       stbi__rewind( s );
       return 0;
   }
   stbi__skip(s, 6);
   channelCount =3D stbi__get16be(s);
   if (channelCount &lt; 0 || channelCount &gt; 16) {
       stbi__rewind( s );
       return 0;
   }
   *y =3D stbi__get32be(s);
   *x =3D stbi__get32be(s);
   depth =3D stbi__get16be(s);
   if (depth !=3D 8 &amp;&amp; depth !=3D 16) {
       stbi__rewind( s );
       return 0;
   }
   if (stbi__get16be(s) !=3D 3) {
       stbi__rewind( s );
       return 0;
   }
   *comp =3D 4;
   return 1;
}

static int stbi__psd_is16(stbi__context *s)
{
   int channelCount, depth;
   if (stbi__get32be(s) !=3D 0x38425053) {
       stbi__rewind( s );
       return 0;
   }
   if (stbi__get16be(s) !=3D 1) {
       stbi__rewind( s );
       return 0;
   }
   stbi__skip(s, 6);
   channelCount =3D stbi__get16be(s);
   if (channelCount &lt; 0 || channelCount &gt; 16) {
       stbi__rewind( s );
       return 0;
   }
   (void) stbi__get32be(s);
   (void) stbi__get32be(s);
   depth =3D stbi__get16be(s);
   if (depth !=3D 16) {
       stbi__rewind( s );
       return 0;
   }
   return 1;
}
#endif

#ifndef STBI_NO_PIC
static int stbi__pic_info(stbi__context *s, int *x, int *y, int *comp)
{
   int act_comp=3D0,num_packets=3D0,chained,dummy;
   stbi__pic_packet packets[10];

   if (!x) x =3D &amp;dummy;
   if (!y) y =3D &amp;dummy;
   if (!comp) comp =3D &amp;dummy;

   if (!stbi__pic_is4(s,"\x53\x80\xF6\x34")) {
      stbi__rewind(s);
      return 0;
   }

   stbi__skip(s, 88);

   *x =3D stbi__get16be(s);
   *y =3D stbi__get16be(s);
   if (stbi__at_eof(s)) {
      stbi__rewind( s);
      return 0;
   }
   if ( (*x) !=3D 0 &amp;&amp; (1 &lt;&lt; 28) / (*x) &lt; (*y)) {
      stbi__rewind( s );
      return 0;
   }

   stbi__skip(s, 8);

   do {
      stbi__pic_packet *packet;

      if (num_packets=3D=3Dsizeof(packets)/sizeof(packets[0]))
         return 0;

      packet =3D &amp;packets[num_packets++];
      chained =3D stbi__get8(s);
      packet-&gt;size    =3D stbi__get8(s);
      packet-&gt;type    =3D stbi__get8(s);
      packet-&gt;channel =3D stbi__get8(s);
      act_comp |=3D packet-&gt;channel;

      if (stbi__at_eof(s)) {
          stbi__rewind( s );
          return 0;
      }
      if (packet-&gt;size !=3D 8) {
          stbi__rewind( s );
          return 0;
      }
   } while (chained);

   *comp =3D (act_comp &amp; 0x10 ? 4 : 3);

   return 1;
}
#endif

// ************************************************************************=
*************************
// Portable Gray Map and Portable Pixel Map loader
// by Ken Miller
//
// PGM: http://netpbm.sourceforge.net/doc/pgm.html
// PPM: http://netpbm.sourceforge.net/doc/ppm.html
//
// Known limitations:
//    Does not support comments in the header section
//    Does not support ASCII image data (formats P2 and P3)
//    Does not support 16-bit-per-channel

#ifndef STBI_NO_PNM

static int      stbi__pnm_test(stbi__context *s)
{
   char p, t;
   p =3D (char) stbi__get8(s);
   t =3D (char) stbi__get8(s);
   if (p !=3D 'P' || (t !=3D '5' &amp;&amp; t !=3D '6')) {
       stbi__rewind( s );
       return 0;
   }
   return 1;
}

static void *stbi__pnm_load(stbi__context *s, int *x, int *y, int *comp, in=
t req_comp, stbi__result_info *ri)
{
   stbi_uc *out;
   STBI_NOTUSED(ri);

   if (!stbi__pnm_info(s, (int *)&amp;s-&gt;img_x, (int *)&amp;s-&gt;img_y,=
 (int *)&amp;s-&gt;img_n))
      return 0;

   *x =3D s-&gt;img_x;
   *y =3D s-&gt;img_y;
   if (comp) *comp =3D s-&gt;img_n;

   if (!stbi__mad3sizes_valid(s-&gt;img_n, s-&gt;img_x, s-&gt;img_y, 0))
      return stbi__errpuc("too large", "PNM too large");

   out =3D (stbi_uc *) stbi__malloc_mad3(s-&gt;img_n, s-&gt;img_x, s-&gt;im=
g_y, 0);
   if (!out) return stbi__errpuc("outofmem", "Out of memory");
   stbi__getn(s, out, s-&gt;img_n * s-&gt;img_x * s-&gt;img_y);

   if (req_comp &amp;&amp; req_comp !=3D s-&gt;img_n) {
      out =3D stbi__convert_format(out, s-&gt;img_n, req_comp, s-&gt;img_x,=
 s-&gt;img_y);
      if (out =3D=3D NULL) return out; // stbi__convert_format frees input =
on failure
   }
   return out;
}

static int      stbi__pnm_isspace(char c)
{
   return c =3D=3D ' ' || c =3D=3D '\t' || c =3D=3D '\n' || c =3D=3D '\v' |=
| c =3D=3D '\f' || c =3D=3D '\r';
}

static void     stbi__pnm_skip_whitespace(stbi__context *s, char *c)
{
   for (;;) {
      while (!stbi__at_eof(s) &amp;&amp; stbi__pnm_isspace(*c))
         *c =3D (char) stbi__get8(s);

      if (stbi__at_eof(s) || *c !=3D '#')
         break;

      while (!stbi__at_eof(s) &amp;&amp; *c !=3D '\n' &amp;&amp; *c !=3D '\=
r' )
         *c =3D (char) stbi__get8(s);
   }
}

static int      stbi__pnm_isdigit(char c)
{
   return c &gt;=3D '0' &amp;&amp; c &lt;=3D '9';
}

static int      stbi__pnm_getinteger(stbi__context *s, char *c)
{
   int value =3D 0;

   while (!stbi__at_eof(s) &amp;&amp; stbi__pnm_isdigit(*c)) {
      value =3D value*10 + (*c - '0');
      *c =3D (char) stbi__get8(s);
   }

   return value;
}

static int      stbi__pnm_info(stbi__context *s, int *x, int *y, int *comp)
{
   int maxv, dummy;
   char c, p, t;

   if (!x) x =3D &amp;dummy;
   if (!y) y =3D &amp;dummy;
   if (!comp) comp =3D &amp;dummy;

   stbi__rewind(s);

   // Get identifier
   p =3D (char) stbi__get8(s);
   t =3D (char) stbi__get8(s);
   if (p !=3D 'P' || (t !=3D '5' &amp;&amp; t !=3D '6')) {
       stbi__rewind(s);
       return 0;
   }

   *comp =3D (t =3D=3D '6') ? 3 : 1;  // '5' is 1-component .pgm; '6' is 3-=
component .ppm

   c =3D (char) stbi__get8(s);
   stbi__pnm_skip_whitespace(s, &amp;c);

   *x =3D stbi__pnm_getinteger(s, &amp;c); // read width
   stbi__pnm_skip_whitespace(s, &amp;c);

   *y =3D stbi__pnm_getinteger(s, &amp;c); // read height
   stbi__pnm_skip_whitespace(s, &amp;c);

   maxv =3D stbi__pnm_getinteger(s, &amp;c);  // read max value

   if (maxv &gt; 255)
      return stbi__err("max value &gt; 255", "PPM image not 8-bit");
   else
      return 1;
}
#endif

static int stbi__info_main(stbi__context *s, int *x, int *y, int *comp)
{
   #ifndef STBI_NO_JPEG
   if (stbi__jpeg_info(s, x, y, comp)) return 1;
   #endif

   #ifndef STBI_NO_PNG
   if (stbi__png_info(s, x, y, comp))  return 1;
   #endif

   #ifndef STBI_NO_GIF
   if (stbi__gif_info(s, x, y, comp))  return 1;
   #endif

   #ifndef STBI_NO_BMP
   if (stbi__bmp_info(s, x, y, comp))  return 1;
   #endif

   #ifndef STBI_NO_PSD
   if (stbi__psd_info(s, x, y, comp))  return 1;
   #endif

   #ifndef STBI_NO_PIC
   if (stbi__pic_info(s, x, y, comp))  return 1;
   #endif

   #ifndef STBI_NO_PNM
   if (stbi__pnm_info(s, x, y, comp))  return 1;
   #endif

   #ifndef STBI_NO_HDR
   if (stbi__hdr_info(s, x, y, comp))  return 1;
   #endif

   // test tga last because it's a crappy test!
   #ifndef STBI_NO_TGA
   if (stbi__tga_info(s, x, y, comp))
       return 1;
   #endif
   return stbi__err("unknown image type", "Image not of any known type, or =
corrupt");
}

static int stbi__is_16_main(stbi__context *s)
{
   #ifndef STBI_NO_PNG
   if (stbi__png_is16(s))  return 1;
   #endif

   #ifndef STBI_NO_PSD
   if (stbi__psd_is16(s))  return 1;
   #endif

   return 0;
}

#ifndef STBI_NO_STDIO
STBIDEF int stbi_info(char const *filename, int *x, int *y, int *comp)
{
    FILE *f =3D stbi__fopen(filename, "rb");
    int result;
    if (!f) return stbi__err("can't fopen", "Unable to open file");
    result =3D stbi_info_from_file(f, x, y, comp);
    fclose(f);
    return result;
}

STBIDEF int stbi_info_from_file(FILE *f, int *x, int *y, int *comp)
{
   int r;
   stbi__context s;
   long pos =3D ftell(f);
   stbi__start_file(&amp;s, f);
   r =3D stbi__info_main(&amp;s,x,y,comp);
   fseek(f,pos,SEEK_SET);
   return r;
}

STBIDEF int stbi_is_16_bit(char const *filename)
{
    FILE *f =3D stbi__fopen(filename, "rb");
    int result;
    if (!f) return stbi__err("can't fopen", "Unable to open file");
    result =3D stbi_is_16_bit_from_file(f);
    fclose(f);
    return result;
}

STBIDEF int stbi_is_16_bit_from_file(FILE *f)
{
   int r;
   stbi__context s;
   long pos =3D ftell(f);
   stbi__start_file(&amp;s, f);
   r =3D stbi__is_16_main(&amp;s);
   fseek(f,pos,SEEK_SET);
   return r;
}
#endif // !STBI_NO_STDIO

STBIDEF int stbi_info_from_memory(stbi_uc const *buffer, int len, int *x, i=
nt *y, int *comp)
{
   stbi__context s;
   stbi__start_mem(&amp;s,buffer,len);
   return stbi__info_main(&amp;s,x,y,comp);
}

STBIDEF int stbi_info_from_callbacks(stbi_io_callbacks const *c, void *user=
, int *x, int *y, int *comp)
{
   stbi__context s;
   stbi__start_callbacks(&amp;s, (stbi_io_callbacks *) c, user);
   return stbi__info_main(&amp;s,x,y,comp);
}

STBIDEF int stbi_is_16_bit_from_memory(stbi_uc const *buffer, int len)
{
   stbi__context s;
   stbi__start_mem(&amp;s,buffer,len);
   return stbi__is_16_main(&amp;s);
}

STBIDEF int stbi_is_16_bit_from_callbacks(stbi_io_callbacks const *c, void =
*user)
{
   stbi__context s;
   stbi__start_callbacks(&amp;s, (stbi_io_callbacks *) c, user);
   return stbi__is_16_main(&amp;s);
}

#endif // STB_IMAGE_IMPLEMENTATION

/*
   revision history:
      2.20  (2019-02-07) support utf8 filenames in Windows; fix warnings an=
d platform ifdefs=20
      2.19  (2018-02-11) fix warning
      2.18  (2018-01-30) fix warnings
      2.17  (2018-01-29) change sbti__shiftsigned to avoid clang -O2 bug
                         1-bit BMP
                         *_is_16_bit api
                         avoid warnings
      2.16  (2017-07-23) all functions have 16-bit variants;
                         STBI_NO_STDIO works again;
                         compilation fixes;
                         fix rounding in unpremultiply;
                         optimize vertical flip;
                         disable raw_len validation;
                         documentation fixes
      2.15  (2017-03-18) fix png-1,2,4 bug; now all Imagenet JPGs decode;
                         warning fixes; disable run-time SSE detection on g=
cc;
                         uniform handling of optional "return" values;
                         thread-safe initialization of zlib tables
      2.14  (2017-03-03) remove deprecated STBI_JPEG_OLD; fixes for Imagene=
t JPGs
      2.13  (2016-11-29) add 16-bit API, only supported for PNG right now
      2.12  (2016-04-02) fix typo in 2.11 PSD fix that caused crashes
      2.11  (2016-04-02) allocate large structures on the stack
                         remove white matting for transparent PSD
                         fix reported channel count for PNG &amp; BMP
                         re-enable SSE2 in non-gcc 64-bit
                         support RGB-formatted JPEG
                         read 16-bit PNGs (only as 8-bit)
      2.10  (2016-01-22) avoid warning introduced in 2.09 by STBI_REALLOC_S=
IZED
      2.09  (2016-01-16) allow comments in PNM files
                         16-bit-per-pixel TGA (not bit-per-component)
                         info() for TGA could break due to .hdr handling
                         info() for BMP to shares code instead of sloppy pa=
rse
                         can use STBI_REALLOC_SIZED if allocator doesn't su=
pport realloc
                         code cleanup
      2.08  (2015-09-13) fix to 2.07 cleanup, reading RGB PSD as RGBA
      2.07  (2015-09-13) fix compiler warnings
                         partial animated GIF support
                         limited 16-bpc PSD support
                         #ifdef unused functions
                         bug with &lt; 92 byte PIC,PNM,HDR,TGA
      2.06  (2015-04-19) fix bug where PSD returns wrong '*comp' value
      2.05  (2015-04-19) fix bug in progressive JPEG handling, fix warning
      2.04  (2015-04-15) try to re-enable SIMD on MinGW 64-bit
      2.03  (2015-04-12) extra corruption checking (mmozeiko)
                         stbi_set_flip_vertically_on_load (nguillemot)
                         fix NEON support; fix mingw support
      2.02  (2015-01-19) fix incorrect assert, fix warning
      2.01  (2015-01-17) fix various warnings; suppress SIMD on gcc 32-bit =
without -msse2
      2.00b (2014-12-25) fix STBI_MALLOC in progressive JPEG
      2.00  (2014-12-25) optimize JPG, including x86 SSE2 &amp; NEON SIMD (=
ryg)
                         progressive JPEG (stb)
                         PGM/PPM support (Ken Miller)
                         STBI_MALLOC,STBI_REALLOC,STBI_FREE
                         GIF bugfix -- seemingly never worked
                         STBI_NO_*, STBI_ONLY_*
      1.48  (2014-12-14) fix incorrectly-named assert()
      1.47  (2014-12-14) 1/2/4-bit PNG support, both direct and paletted (O=
mar Cornut &amp; stb)
                         optimize PNG (ryg)
                         fix bug in interlaced PNG with user-specified chan=
nel count (stb)
      1.46  (2014-08-26)
              fix broken tRNS chunk (colorkey-style transparency) in non-pa=
letted PNG
      1.45  (2014-08-16)
              fix MSVC-ARM internal compiler error by wrapping malloc
      1.44  (2014-08-07)
              various warning fixes from Ronny Chevalier
      1.43  (2014-07-15)
              fix MSVC-only compiler problem in code changed in 1.42
      1.42  (2014-07-09)
              don't define _CRT_SECURE_NO_WARNINGS (affects user code)
              fixes to stbi__cleanup_jpeg path
              added STBI_ASSERT to avoid requiring assert.h
      1.41  (2014-06-25)
              fix search&amp;replace from 1.36 that messed up comments/erro=
r messages
      1.40  (2014-06-22)
              fix gcc struct-initialization warning
      1.39  (2014-06-15)
              fix to TGA optimization when req_comp !=3D number of componen=
ts in TGA;
              fix to GIF loading because BMP wasn't rewinding (whoops, no G=
IFs in my test suite)
              add support for BMP version 5 (more ignored fields)
      1.38  (2014-06-06)
              suppress MSVC warnings on integer casts truncating values
              fix accidental rename of 'skip' field of I/O
      1.37  (2014-06-04)
              remove duplicate typedef
      1.36  (2014-06-03)
              convert to header file single-file library
              if de-iphone isn't set, load iphone images color-swapped inst=
ead of returning NULL
      1.35  (2014-05-27)
              various warnings
              fix broken STBI_SIMD path
              fix bug where stbi_load_from_file no longer left file pointer=
 in correct place
              fix broken non-easy path for 32-bit BMP (possibly never used)
              TGA optimization by Arseny Kapoulkine
      1.34  (unknown)
              use STBI_NOTUSED in stbi__resample_row_generic(), fix one mor=
e leak in tga failure case
      1.33  (2011-07-14)
              make stbi_is_hdr work in STBI_NO_HDR (as specified), minor co=
mpiler-friendly improvements
      1.32  (2011-07-13)
              support for "info" function for all supported filetypes (Spar=
tanJ)
      1.31  (2011-06-20)
              a few more leak fixes, bug in PNG handling (SpartanJ)
      1.30  (2011-06-11)
              added ability to load files via callbacks to accomidate custo=
m input streams (Ben Wenger)
              removed deprecated format-specific test/load functions
              removed support for installable file formats (stbi_loader) --=
 would have been broken for IO callbacks anyway
              error cases in bmp and tga give messages and don't leak (Raym=
ond Barbiero, grisha)
              fix inefficiency in decoding 32-bit BMP (David Woo)
      1.29  (2010-08-16)
              various warning fixes from Aurelien Pocheville
      1.28  (2010-08-01)
              fix bug in GIF palette transparency (SpartanJ)
      1.27  (2010-08-01)
              cast-to-stbi_uc to fix warnings
      1.26  (2010-07-24)
              fix bug in file buffering for PNG reported by SpartanJ
      1.25  (2010-07-17)
              refix trans_data warning (Won Chun)
      1.24  (2010-07-12)
              perf improvements reading from files on platforms with lock-h=
eavy fgetc()
              minor perf improvements for jpeg
              deprecated type-specific functions so we'll get feedback if t=
hey're needed
              attempt to fix trans_data warning (Won Chun)
      1.23    fixed bug in iPhone support
      1.22  (2010-07-10)
              removed image *writing* support
              stbi_info support from Jetro Lauha
              GIF support from Jean-Marc Lienher
              iPhone PNG-extensions from James Brown
              warning-fixes from Nicolas Schulz and Janez Zemva (i.stbi__er=
r. Janez (U+017D)emva)
      1.21    fix use of 'stbi_uc' in header (reported by jon blow)
      1.20    added support for Softimage PIC, by Tom Seddon
      1.19    bug in interlaced PNG corruption check (found by ryg)
      1.18  (2008-08-02)
              fix a threading bug (local mutable static)
      1.17    support interlaced PNG
      1.16    major bugfix - stbi__convert_format converted one too many pi=
xels
      1.15    initialize some fields for thread safety
      1.14    fix threadsafe conversion bug
              header-file-only version (#define STBI_HEADER_FILE_ONLY befor=
e including)
      1.13    threadsafe
      1.12    const qualifiers in the API
      1.11    Support installable IDCT, colorspace conversion routines
      1.10    Fixes for 64-bit (don't use "unsigned long")
              optimized upsampling by Fabian "ryg" Giesen
      1.09    Fix format-conversion for PSD code (bad global variables!)
      1.08    Thatcher Ulrich's PSD code integrated by Nicolas Schulz
      1.07    attempt to fix C++ warning/errors again
      1.06    attempt to fix C++ warning/errors again
      1.05    fix TGA loading to return correct *comp and use good luminanc=
e calc
      1.04    default float alpha is 1, not 255; use 'void *' for stbi_imag=
e_free
      1.03    bugfixes to STBI_NO_STDIO, STBI_NO_HDR
      1.02    support for (subset of) HDR files, float interface for prefer=
red access to them
      1.01    fix bug: possible bug in handling right-side up bmps... not s=
ure
              fix bug: the stbi__bmp_load() and stbi__tga_load() functions =
didn't work at all
      1.00    interface to zlib that skips zlib header
      0.99    correct handling of alpha in palette
      0.98    TGA loader by lonesock; dynamically add loaders (untested)
      0.97    jpeg errors on too large a file; also catch another malloc fa=
ilure
      0.96    fix detection of invalid v value - particleman@mollyrocket fo=
rum
      0.95    during header scan, seek to markers in case of padding
      0.94    STBI_NO_STDIO to disable stdio usage; rename all #defines the=
 same
      0.93    handle jpegtran output; verbose errors
      0.92    read 4,8,16,24,32-bit BMP files of several formats
      0.91    output 24-bit Windows 3.0 BMP files
      0.90    fix a few more warnings; bump version number to approach 1.0
      0.61    bugfixes due to Marc LeBlanc, Christopher Lloyd
      0.60    fix compiling as c++
      0.59    fix warnings: merge Dave Moore's -Wall fixes
      0.58    fix bug: zlib uncompressed mode len/nlen was wrong endian
      0.57    fix bug: jpg last huffman symbol before marker was &gt;9 bits=
 but less than 16 available
      0.56    fix bug: zlib uncompressed mode len vs. nlen
      0.55    fix bug: restart_interval not initialized to 0
      0.54    allow NULL for 'int *comp'
      0.53    fix bug in png 3-&gt;4; speedup png decoding
      0.52    png handles req_comp=3D3,4 directly; minor cleanup; jpeg comm=
ents
      0.51    obey req_comp requests, 1-component jpegs return as 1-compone=
nt,
              on 'test' only check type, not whether we support this varian=
t
      0.50  (2006-11-19)
              first released version
*/


/*
---------------------------------------------------------------------------=
---
This software is available under 2 licenses -- choose whichever you prefer.
---------------------------------------------------------------------------=
---
ALTERNATIVE A - MIT License
Copyright (c) 2017 Sean Barrett
Permission is hereby granted, free of charge, to any person obtaining a cop=
y of
this software and associated documentation files (the "Software"), to deal =
in
the Software without restriction, including without limitation the rights t=
o
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copi=
es
of the Software, and to permit persons to whom the Software is furnished to=
 do
so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in =
all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FRO=
M,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN T=
HE
SOFTWARE.
---------------------------------------------------------------------------=
---
ALTERNATIVE B - Public Domain (www.unlicense.org)
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or distribute =
this
software, either in source code form or as a compiled binary, for any purpo=
se,
commercial or non-commercial, and by any means.
In jurisdictions that recognize copyright laws, the author or authors of th=
is
software dedicate any and all copyright interest in the software to the pub=
lic
domain. We make this dedication for the benefit of the public at large and =
to
the detriment of our heirs and successors. We intend this dedication to be =
an
overt act of relinquishment in perpetuity of all present and future rights =
to
this software under copyright law.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTIO=
N
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
---------------------------------------------------------------------------=
---
*/
</pre></body><style>
html > ::-webkit-scrollbar { width: 0px; height: 0px; }</style></html>
------MultipartBoundary--h9CxAyqN20e1UcmCjgKU8HxqXGaYBnLk43I7nmffTg------
