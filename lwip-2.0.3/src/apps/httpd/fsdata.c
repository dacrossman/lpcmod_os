#include "lwip/apps/fs.h"
#include "lwip/def.h"
#include "fsdata.h"


#define file_NULL (struct fsdata_file *) NULL


#ifndef FS_FILE_FLAGS_HEADER_INCLUDED
#define FS_FILE_FLAGS_HEADER_INCLUDED 1
#endif
#ifndef FS_FILE_FLAGS_HEADER_PERSISTENT
#define FS_FILE_FLAGS_HEADER_PERSISTENT 0
#endif
/* FSDATA_FILE_ALIGNMENT: 0=off, 1=by variable, 2=by include */
#ifndef FSDATA_FILE_ALIGNMENT
#define FSDATA_FILE_ALIGNMENT 0
#endif
#ifndef FSDATA_ALIGN_PRE
#define FSDATA_ALIGN_PRE
#endif
#ifndef FSDATA_ALIGN_POST
#define FSDATA_ALIGN_POST
#endif
#if FSDATA_FILE_ALIGNMENT==2
#include "fsdata_alignment.h"
#endif
#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__404_html = 0;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__404_html[] FSDATA_ALIGN_POST = {
/* /404.html (10 chars) */
0x2f,0x34,0x30,0x34,0x2e,0x68,0x74,0x6d,0x6c,0x00,0x00,0x00,

/* raw file data (307 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x3e,0x0a,0x3c,0x68,0x65,0x61,0x64,0x3e,0x3c,0x74,0x69,
0x74,0x6c,0x65,0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x20,0x2d,0x20,
0x45,0x72,0x72,0x6f,0x72,0x20,0x34,0x30,0x34,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,0x62,0x6f,0x64,0x79,0x20,0x62,
0x67,0x63,0x6f,0x6c,0x6f,0x72,0x3d,0x22,0x77,0x68,0x69,0x74,0x65,0x22,0x20,0x74,
0x65,0x78,0x74,0x3d,0x22,0x62,0x6c,0x61,0x63,0x6b,0x22,0x3e,0x0a,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x74,0x61,0x62,0x6c,0x65,0x20,0x77,0x69,0x64,0x74,0x68,0x3d,0x22,
0x31,0x30,0x30,0x25,0x22,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x74,0x72,
0x20,0x76,0x61,0x6c,0x69,0x67,0x6e,0x3d,0x22,0x74,0x6f,0x70,0x22,0x3e,0x20,0x20,
0x0a,0x09,0x20,0x20,0x3c,0x68,0x31,0x3e,0x34,0x30,0x34,0x20,0x2d,0x20,0x50,0x61,
0x67,0x65,0x20,0x6e,0x6f,0x74,0x20,0x66,0x6f,0x75,0x6e,0x64,0x3c,0x2f,0x68,0x31,
0x3e,0x0a,0x09,0x20,0x20,0x3c,0x70,0x3e,0x0a,0x09,0x20,0x20,0x20,0x20,0x53,0x6f,
0x72,0x72,0x79,0x2c,0x20,0x74,0x68,0x65,0x20,0x70,0x61,0x67,0x65,0x20,0x79,0x6f,
0x75,0x20,0x61,0x72,0x65,0x20,0x72,0x65,0x71,0x75,0x65,0x73,0x74,0x69,0x6e,0x67,
0x20,0x77,0x61,0x73,0x20,0x6e,0x6f,0x74,0x20,0x66,0x6f,0x75,0x6e,0x64,0x20,0x6f,
0x6e,0x20,0x74,0x68,0x69,0x73,0x0a,0x09,0x20,0x20,0x20,0x20,0x73,0x65,0x72,0x76,
0x65,0x72,0x2e,0x20,0x0a,0x09,0x20,0x20,0x3c,0x2f,0x70,0x3e,0x0a,0x09,0x3c,0x2f,
0x74,0x72,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x2f,0x74,0x61,0x62,0x6c,
0x65,0x3e,0x0a,0x3c,0x2f,0x62,0x6f,0x64,0x79,0x3e,0x0a,0x3c,0x2f,0x68,0x74,0x6d,
0x6c,0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__failHDDLOCK_html = 1;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__failHDDLOCK_html[] FSDATA_ALIGN_POST = {
/* /failHDDLOCK.html (18 chars) */
0x2f,0x66,0x61,0x69,0x6c,0x48,0x44,0x44,0x4c,0x4f,0x43,0x4b,0x2e,0x68,0x74,0x6d,
0x6c,0x00,0x00,0x00,

/* raw file data (424 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x27,0x68,0x74,0x74,
0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,0x67,0x2f,0x31,
0x39,0x39,0x39,0x2f,0x78,0x68,0x74,0x6d,0x6c,0x27,0x20,0x3e,0x0a,0x20,0x20,0x3c,
0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,
0x46,0x6c,0x61,0x73,0x68,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,0x68,0x74,0x74,0x70,0x2d,0x65,0x71,0x75,
0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,
0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,
0x68,0x74,0x6d,0x6c,0x3b,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,0x43,
0x49,0x49,0x22,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,
0x42,0x4f,0x44,0x59,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,
0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x46,
0x46,0x30,0x30,0x30,0x30,0x22,0x3e,0x0a,0x3c,0x66,0x6f,0x6e,0x74,0x20,0x63,0x6f,
0x6c,0x6f,0x72,0x3d,0x22,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x20,
0x20,0x20,0x20,0x3c,0x68,0x32,0x3e,0x45,0x45,0x50,0x52,0x4f,0x4d,0x20,0x46,0x69,
0x6c,0x65,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x65,0x72,0x72,0x6f,0x72,0x2e,
0x2e,0x2e,0x3c,0x2f,0x68,0x32,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x62,0x3e,0x54,
0x68,0x65,0x20,0x66,0x69,0x6c,0x65,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x65,0x64,
0x20,0x69,0x73,0x20,0x6e,0x6f,0x74,0x20,0x32,0x35,0x36,0x20,0x62,0x79,0x74,0x65,
0x73,0x20,0x69,0x6e,0x20,0x73,0x69,0x7a,0x65,0x2e,0x20,0x52,0x65,0x66,0x75,0x73,
0x69,0x6e,0x67,0x20,0x74,0x6f,0x20,0x6c,0x6f,0x63,0x6b,0x2f,0x75,0x6e,0x6c,0x6f,
0x63,0x6b,0x20,0x48,0x44,0x44,0x2e,0x3c,0x2f,0x62,0x3e,0x20,0x0a,0x20,0x20,0x20,
0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x0a,0x20,0x20,0x20,0x20,0x47,0x6f,
0x20,0x62,0x61,0x63,0x6b,0x20,0x74,0x6f,0x20,0x72,0x65,0x74,0x72,0x79,0x2e,0x0a,
0x3c,0x2f,0x66,0x6f,0x6e,0x74,0x3e,0x0a,0x3c,0x2f,0x42,0x4f,0x44,0x59,0x3e,0x0a,
0x3c,0x2f,0x48,0x54,0x4d,0x4c,0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__okHDDLOCK_html = 2;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__okHDDLOCK_html[] FSDATA_ALIGN_POST = {
/* /okHDDLOCK.html (16 chars) */
0x2f,0x6f,0x6b,0x48,0x44,0x44,0x4c,0x4f,0x43,0x4b,0x2e,0x68,0x74,0x6d,0x6c,0x00,


/* raw file data (394 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x27,0x68,0x74,0x74,
0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,0x67,0x2f,0x31,
0x39,0x39,0x39,0x2f,0x78,0x68,0x74,0x6d,0x6c,0x27,0x20,0x3e,0x0a,0x20,0x20,0x3c,
0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,
0x46,0x6c,0x61,0x73,0x68,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,0x68,0x74,0x74,0x70,0x2d,0x65,0x71,0x75,
0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,
0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,
0x68,0x74,0x6d,0x6c,0x3b,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,0x43,
0x49,0x49,0x22,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,
0x42,0x4f,0x44,0x59,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,
0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x30,
0x31,0x32,0x46,0x35,0x33,0x22,0x3e,0x0a,0x3c,0x66,0x6f,0x6e,0x74,0x20,0x63,0x6f,
0x6c,0x6f,0x72,0x3d,0x22,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x68,0x32,0x3e,0x45,0x45,0x50,0x52,0x4f,
0x4d,0x20,0x66,0x69,0x6c,0x65,0x20,0x61,0x63,0x63,0x65,0x70,0x74,0x65,0x64,0x2e,
0x2e,0x2e,0x3c,0x2f,0x68,0x32,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x3c,0x62,0x72,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x62,0x3e,
0x52,0x65,0x74,0x75,0x72,0x6e,0x20,0x74,0x6f,0x20,0x58,0x62,0x6f,0x78,0x20,0x61,
0x6e,0x64,0x20,0x63,0x68,0x65,0x63,0x6b,0x20,0x69,0x66,0x20,0x79,0x6f,0x75,0x72,
0x20,0x48,0x44,0x44,0x20,0x6c,0x6f,0x63,0x6b,0x20,0x73,0x74,0x61,0x74,0x75,0x73,
0x20,0x68,0x61,0x73,0x20,0x63,0x68,0x61,0x6e,0x67,0x65,0x64,0x2e,0x3c,0x2f,0x62,
0x3e,0x0a,0x3c,0x2f,0x66,0x6f,0x6e,0x74,0x3e,0x0a,0x3c,0x2f,0x42,0x4f,0x44,0x59,
0x3e,0x0a,0x3c,0x2f,0x48,0x54,0x4d,0x4c,0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__main_html = 3;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__main_html[] FSDATA_ALIGN_POST = {
/* /main.html (11 chars) */
0x2f,0x6d,0x61,0x69,0x6e,0x2e,0x68,0x74,0x6d,0x6c,0x00,0x00,

/* raw file data (1227 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x27,0x68,0x74,0x74,
0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,0x67,0x2f,0x31,
0x39,0x39,0x39,0x2f,0x78,0x68,0x74,0x6d,0x6c,0x27,0x20,0x3e,0x0a,0x20,0x20,0x3c,
0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,
0x46,0x6c,0x61,0x73,0x68,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,0x68,0x74,0x74,0x70,0x2d,0x65,0x71,0x75,
0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,
0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,
0x68,0x74,0x6d,0x6c,0x3b,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,0x43,
0x49,0x49,0x22,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,
0x20,0x3c,0x62,0x6f,0x64,0x79,0x20,0x62,0x67,0x63,0x6f,0x6c,0x6f,0x72,0x3d,0x22,
0x23,0x30,0x31,0x32,0x46,0x35,0x33,0x22,0x20,0x74,0x65,0x78,0x74,0x3d,0x22,0x77,
0x68,0x69,0x74,0x65,0x22,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x44,0x49,0x56,0x20,
0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x46,0x46,
0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x09,0x09,0x55,0x73,0x65,0x20,0x74,0x68,0x65,
0x20,0x66,0x6f,0x72,0x6d,0x20,0x62,0x65,0x6c,0x6f,0x77,0x20,0x74,0x6f,0x20,0x75,
0x70,0x64,0x61,0x74,0x65,0x20,0x74,0x68,0x65,0x20,0x42,0x49,0x4f,0x53,0x20,0x6f,
0x66,0x20,0x79,0x6f,0x75,0x72,0x20,0x6d,0x6f,0x64,0x63,0x68,0x69,0x70,0x2e,0x20,
0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x3c,0x42,0x3e,0x57,0x41,0x52,0x4e,0x49,
0x4e,0x47,0x21,0x3c,0x2f,0x42,0x3e,0x20,0x0a,0x09,0x09,0x49,0x74,0x20,0x77,0x69,
0x6c,0x6c,0x20,0x75,0x73,0x65,0x20,0x74,0x68,0x65,0x20,0x66,0x69,0x6c,0x65,0x20,
0x79,0x6f,0x75,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x74,0x6f,0x20,0x72,0x65,
0x70,0x6c,0x61,0x63,0x65,0x20,0x74,0x68,0x65,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,
0x74,0x73,0x20,0x6f,0x66,0x20,0x79,0x6f,0x75,0x72,0x20,0x6d,0x6f,0x64,0x63,0x68,
0x69,0x70,0x2e,0x26,0x6e,0x62,0x73,0x70,0x3b,0x20,0x0a,0x09,0x09,0x4d,0x61,0x6b,
0x65,0x20,0x73,0x75,0x72,0x65,0x20,0x79,0x6f,0x75,0x20,0x75,0x70,0x6c,0x6f,0x61,
0x64,0x20,0x74,0x68,0x65,0x20,0x63,0x6f,0x72,0x72,0x65,0x63,0x74,0x20,0x73,0x69,
0x7a,0x65,0x20,0x42,0x49,0x4f,0x53,0x20,0x66,0x6f,0x72,0x20,0x79,0x6f,0x75,0x72,
0x20,0x6d,0x6f,0x64,0x63,0x68,0x69,0x70,0x21,0x20,0x28,0x57,0x69,0x6c,0x6c,0x20,
0x6d,0x69,0x72,0x72,0x6f,0x72,0x20,0x69,0x66,0x20,0x74,0x6f,0x6f,0x20,0x73,0x6d,
0x61,0x6c,0x6c,0x29,0x3c,0x62,0x72,0x3e,0x3c,0x42,0x3e,0x42,0x61,0x6e,0x6b,0x30,
0x20,0x3d,0x20,0x35,0x31,0x32,0x4b,0x42,0x3c,0x2f,0x42,0x3e,0x0a,0x09,0x09,0x3c,
0x62,0x72,0x3e,0x3c,0x42,0x3e,0x42,0x61,0x6e,0x6b,0x31,0x20,0x3d,0x20,0x32,0x35,
0x36,0x4b,0x42,0x3c,0x2f,0x42,0x3e,0x3c,0x62,0x72,0x3e,0x3c,0x42,0x3e,0x42,0x61,
0x6e,0x6b,0x32,0x28,0x4f,0x53,0x29,0x20,0x3d,0x20,0x32,0x35,0x36,0x4b,0x42,0x3c,
0x2f,0x42,0x3e,0x20,0x20,0x20,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x62,0x72,
0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x62,0x72,0x3e,0x0a,0x20,0x20,0x20,
0x20,0x3c,0x66,0x6f,0x72,0x6d,0x20,0x69,0x64,0x3d,0x22,0x62,0x69,0x6f,0x73,0x75,
0x70,0x22,0x20,0x6d,0x65,0x74,0x68,0x6f,0x64,0x3d,0x22,0x70,0x6f,0x73,0x74,0x22,
0x20,0x65,0x6e,0x63,0x74,0x79,0x70,0x65,0x3d,0x22,0x6d,0x75,0x6c,0x74,0x69,0x70,
0x61,0x72,0x74,0x2f,0x66,0x6f,0x72,0x6d,0x2d,0x64,0x61,0x74,0x61,0x22,0x20,0x61,
0x63,0x63,0x65,0x70,0x74,0x2d,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,
0x43,0x49,0x49,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x53,0x65,0x74,0x20,
0x42,0x49,0x4f,0x53,0x20,0x6e,0x61,0x6d,0x65,0x20,0x28,0x6d,0x61,0x78,0x20,0x32,
0x30,0x20,0x63,0x68,0x61,0x72,0x61,0x63,0x74,0x65,0x72,0x73,0x29,0x3a,0x3c,0x62,
0x72,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x69,0x6e,0x70,0x75,0x74,
0x20,0x74,0x79,0x70,0x65,0x3d,0x22,0x74,0x65,0x78,0x74,0x22,0x20,0x6e,0x61,0x6d,
0x65,0x3d,0x22,0x62,0x69,0x6f,0x73,0x6e,0x61,0x6d,0x65,0x22,0x3e,0x3c,0x62,0x72,
0x3e,0x0a,0x09,0x20,0x20,0x20,0x53,0x65,0x6c,0x65,0x63,0x74,0x20,0x42,0x49,0x4f,
0x53,0x20,0x46,0x69,0x6c,0x65,0x3a,0x3c,0x62,0x72,0x3e,0x0a,0x20,0x20,0x20,0x20,
0x20,0x20,0x20,0x20,0x3c,0x69,0x6e,0x70,0x75,0x74,0x20,0x74,0x79,0x70,0x65,0x3d,
0x22,0x66,0x69,0x6c,0x65,0x22,0x20,0x69,0x64,0x3d,0x22,0x66,0x69,0x6c,0x65,0x22,
0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x62,0x69,0x6f,0x73,0x62,0x69,0x6e,0x22,0x3e,
0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x69,0x6e,0x70,0x75,0x74,0x20,
0x74,0x79,0x70,0x65,0x3d,0x22,0x73,0x75,0x62,0x6d,0x69,0x74,0x22,0x20,0x76,0x61,
0x6c,0x75,0x65,0x3d,0x22,0x55,0x70,0x6c,0x6f,0x61,0x64,0x20,0x61,0x6e,0x64,0x20,
0x46,0x6c,0x61,0x73,0x68,0x22,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x2f,0x66,0x6f,
0x72,0x6d,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x62,0x6f,0x64,0x79,0x3e,0x0a,0x3c,0x2f,
0x68,0x74,0x6d,0x6c,0x3e,0x3c,0x73,0x70,0x61,0x6e,0x20,0x73,0x74,0x79,0x6c,0x65,
0x3d,0x22,0x6c,0x69,0x6e,0x65,0x2d,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x32,
0x30,0x70,0x78,0x3b,0x20,0x66,0x6f,0x6e,0x74,0x2d,0x66,0x61,0x6d,0x69,0x6c,0x79,
0x3a,0x20,0x56,0x65,0x72,0x64,0x61,0x6e,0x61,0x2c,0x20,0x41,0x72,0x69,0x61,0x6c,
0x2c,0x20,0x48,0x65,0x6c,0x76,0x65,0x74,0x69,0x63,0x61,0x2c,0x20,0x73,0x61,0x6e,
0x73,0x2d,0x73,0x65,0x72,0x69,0x66,0x3b,0x20,0x66,0x6f,0x6e,0x74,0x2d,0x73,0x69,
0x7a,0x65,0x3a,0x20,0x31,0x31,0x70,0x78,0x3b,0x20,0x62,0x61,0x63,0x6b,0x67,0x72,
0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x74,0x72,0x61,0x6e,
0x73,0x70,0x61,0x72,0x65,0x6e,0x74,0x3b,0x22,0x20,0x64,0x61,0x74,0x61,0x2d,0x6d,
0x63,0x65,0x2d,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x6c,0x69,0x6e,0x65,0x2d,0x68,
0x65,0x69,0x67,0x68,0x74,0x3a,0x20,0x32,0x30,0x70,0x78,0x3b,0x20,0x66,0x6f,0x6e,
0x74,0x2d,0x66,0x61,0x6d,0x69,0x6c,0x79,0x3a,0x20,0x56,0x65,0x72,0x64,0x61,0x6e,
0x61,0x2c,0x20,0x41,0x72,0x69,0x61,0x6c,0x2c,0x20,0x48,0x65,0x6c,0x76,0x65,0x74,
0x69,0x63,0x61,0x2c,0x20,0x73,0x61,0x6e,0x73,0x2d,0x73,0x65,0x72,0x69,0x66,0x3b,
0x20,0x66,0x6f,0x6e,0x74,0x2d,0x73,0x69,0x7a,0x65,0x3a,0x20,0x31,0x31,0x70,0x78,
0x3b,0x20,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,
0x6f,0x72,0x3a,0x20,0x74,0x72,0x61,0x6e,0x73,0x70,0x61,0x72,0x65,0x6e,0x74,0x3b,
0x22,0x3e,0x20,0x3c,0x2f,0x73,0x70,0x61,0x6e,0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__failEEPROM_html = 4;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__failEEPROM_html[] FSDATA_ALIGN_POST = {
/* /failEEPROM.html (17 chars) */
0x2f,0x66,0x61,0x69,0x6c,0x45,0x45,0x50,0x52,0x4f,0x4d,0x2e,0x68,0x74,0x6d,0x6c,
0x00,0x00,0x00,0x00,

/* raw file data (416 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x27,0x68,0x74,0x74,
0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,0x67,0x2f,0x31,
0x39,0x39,0x39,0x2f,0x78,0x68,0x74,0x6d,0x6c,0x27,0x20,0x3e,0x0a,0x20,0x20,0x3c,
0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,
0x46,0x6c,0x61,0x73,0x68,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,0x68,0x74,0x74,0x70,0x2d,0x65,0x71,0x75,
0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,
0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,
0x68,0x74,0x6d,0x6c,0x3b,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,0x43,
0x49,0x49,0x22,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,
0x42,0x4f,0x44,0x59,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,
0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x46,
0x46,0x30,0x30,0x30,0x30,0x22,0x3e,0x0a,0x3c,0x66,0x6f,0x6e,0x74,0x20,0x63,0x6f,
0x6c,0x6f,0x72,0x3d,0x22,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x20,
0x20,0x20,0x20,0x3c,0x68,0x32,0x3e,0x45,0x45,0x50,0x52,0x4f,0x4d,0x20,0x46,0x69,
0x6c,0x65,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x65,0x72,0x72,0x6f,0x72,0x2e,
0x2e,0x2e,0x3c,0x2f,0x68,0x32,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x62,0x3e,0x54,
0x68,0x65,0x20,0x66,0x69,0x6c,0x65,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x65,0x64,
0x20,0x69,0x73,0x20,0x6e,0x6f,0x74,0x20,0x32,0x35,0x36,0x20,0x62,0x79,0x74,0x65,
0x73,0x20,0x69,0x6e,0x20,0x73,0x69,0x7a,0x65,0x2e,0x20,0x52,0x65,0x66,0x75,0x73,
0x69,0x6e,0x67,0x20,0x74,0x6f,0x20,0x70,0x72,0x6f,0x67,0x72,0x61,0x6d,0x2e,0x3c,
0x2f,0x62,0x3e,0x20,0x0a,0x20,0x20,0x20,0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,
0x3e,0x0a,0x20,0x20,0x20,0x20,0x47,0x6f,0x20,0x62,0x61,0x63,0x6b,0x20,0x74,0x6f,
0x20,0x72,0x65,0x74,0x72,0x79,0x2e,0x0a,0x3c,0x2f,0x66,0x6f,0x6e,0x74,0x3e,0x0a,
0x3c,0x2f,0x42,0x4f,0x44,0x59,0x3e,0x0a,0x3c,0x2f,0x48,0x54,0x4d,0x4c,0x3e,0x0a,
};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__fail_html = 5;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__fail_html[] FSDATA_ALIGN_POST = {
/* /fail.html (11 chars) */
0x2f,0x66,0x61,0x69,0x6c,0x2e,0x68,0x74,0x6d,0x6c,0x00,0x00,

/* raw file data (434 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x27,0x68,0x74,0x74,
0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,0x67,0x2f,0x31,
0x39,0x39,0x39,0x2f,0x78,0x68,0x74,0x6d,0x6c,0x27,0x20,0x3e,0x0a,0x20,0x20,0x3c,
0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,
0x46,0x6c,0x61,0x73,0x68,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,0x68,0x74,0x74,0x70,0x2d,0x65,0x71,0x75,
0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,
0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,
0x68,0x74,0x6d,0x6c,0x3b,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,0x43,
0x49,0x49,0x22,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,
0x42,0x4f,0x44,0x59,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,
0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x46,
0x46,0x30,0x30,0x30,0x30,0x22,0x3e,0x0a,0x3c,0x66,0x6f,0x6e,0x74,0x20,0x63,0x6f,
0x6c,0x6f,0x72,0x3d,0x22,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x20,
0x20,0x20,0x20,0x3c,0x68,0x32,0x3e,0x42,0x49,0x4f,0x53,0x20,0x46,0x69,0x6c,0x65,
0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x65,0x72,0x72,0x6f,0x72,0x2e,0x2e,0x2e,
0x3c,0x2f,0x68,0x32,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x62,0x3e,0x54,0x68,0x65,
0x20,0x66,0x69,0x6c,0x65,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x65,0x64,0x20,0x69,
0x73,0x20,0x6e,0x6f,0x74,0x20,0x32,0x36,0x32,0x31,0x34,0x34,0x2c,0x20,0x35,0x32,
0x34,0x32,0x38,0x38,0x20,0x6f,0x72,0x20,0x31,0x30,0x34,0x38,0x35,0x37,0x36,0x20,
0x62,0x79,0x74,0x65,0x73,0x20,0x69,0x6e,0x20,0x73,0x69,0x7a,0x65,0x2e,0x20,0x52,
0x65,0x66,0x75,0x73,0x69,0x6e,0x67,0x20,0x74,0x6f,0x20,0x66,0x6c,0x61,0x73,0x68,
0x2e,0x3c,0x2f,0x62,0x3e,0x20,0x0a,0x20,0x20,0x20,0x20,0x3c,0x62,0x72,0x3e,0x3c,
0x62,0x72,0x3e,0x0a,0x20,0x20,0x20,0x20,0x47,0x6f,0x20,0x62,0x61,0x63,0x6b,0x20,
0x74,0x6f,0x20,0x72,0x65,0x74,0x72,0x79,0x2e,0x0a,0x3c,0x2f,0x66,0x6f,0x6e,0x74,
0x3e,0x0a,0x3c,0x2f,0x42,0x4f,0x44,0x59,0x3e,0x0a,0x3c,0x2f,0x48,0x54,0x4d,0x4c,
0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__okEEPROM_html = 6;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__okEEPROM_html[] FSDATA_ALIGN_POST = {
/* /okEEPROM.html (15 chars) */
0x2f,0x6f,0x6b,0x45,0x45,0x50,0x52,0x4f,0x4d,0x2e,0x68,0x74,0x6d,0x6c,0x00,0x00,

/* raw file data (409 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x27,0x68,0x74,0x74,
0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,0x67,0x2f,0x31,
0x39,0x39,0x39,0x2f,0x78,0x68,0x74,0x6d,0x6c,0x27,0x20,0x3e,0x0a,0x20,0x20,0x3c,
0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,
0x46,0x6c,0x61,0x73,0x68,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,0x68,0x74,0x74,0x70,0x2d,0x65,0x71,0x75,
0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,
0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,
0x68,0x74,0x6d,0x6c,0x3b,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,0x43,
0x49,0x49,0x22,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,
0x42,0x4f,0x44,0x59,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,
0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x30,
0x31,0x32,0x46,0x35,0x33,0x22,0x3e,0x0a,0x3c,0x66,0x6f,0x6e,0x74,0x20,0x63,0x6f,
0x6c,0x6f,0x72,0x3d,0x22,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x20,
0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x68,0x32,0x3e,0x45,0x45,0x50,0x52,0x4f,
0x4d,0x20,0x66,0x69,0x6c,0x65,0x20,0x61,0x63,0x63,0x65,0x70,0x74,0x65,0x64,0x2e,
0x2e,0x2e,0x3c,0x2f,0x68,0x32,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,
0x3c,0x62,0x72,0x3e,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x62,0x3e,
0x52,0x65,0x74,0x75,0x72,0x6e,0x20,0x74,0x6f,0x20,0x58,0x62,0x6f,0x78,0x20,0x61,
0x6e,0x64,0x20,0x73,0x65,0x6c,0x65,0x63,0x74,0x20,0x61,0x70,0x70,0x72,0x6f,0x70,
0x72,0x69,0x61,0x74,0x65,0x20,0x6f,0x70,0x74,0x69,0x6f,0x6e,0x20,0x74,0x6f,0x20,
0x73,0x61,0x76,0x65,0x20,0x63,0x68,0x61,0x6e,0x67,0x65,0x73,0x20,0x74,0x6f,0x20,
0x45,0x45,0x50,0x52,0x4f,0x4d,0x20,0x63,0x68,0x69,0x70,0x2e,0x3c,0x2f,0x62,0x3e,
0x0a,0x3c,0x2f,0x66,0x6f,0x6e,0x74,0x3e,0x0a,0x3c,0x2f,0x42,0x4f,0x44,0x59,0x3e,
0x0a,0x3c,0x2f,0x48,0x54,0x4d,0x4c,0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__mainHDDLOCK_html = 7;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__mainHDDLOCK_html[] FSDATA_ALIGN_POST = {
/* /mainHDDLOCK.html (18 chars) */
0x2f,0x6d,0x61,0x69,0x6e,0x48,0x44,0x44,0x4c,0x4f,0x43,0x4b,0x2e,0x68,0x74,0x6d,
0x6c,0x00,0x00,0x00,

/* raw file data (834 bytes) */
0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x48,0x54,0x4d,0x4c,0x20,0x50,
0x55,0x42,0x4c,0x49,0x43,0x20,0x22,0x2d,0x2f,0x2f,0x57,0x33,0x43,0x2f,0x2f,0x44,
0x54,0x44,0x20,0x48,0x54,0x4d,0x4c,0x20,0x34,0x2e,0x30,0x31,0x20,0x54,0x72,0x61,
0x6e,0x73,0x69,0x74,0x69,0x6f,0x6e,0x61,0x6c,0x2f,0x2f,0x45,0x4e,0x22,0x20,0x22,
0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,
0x67,0x2f,0x54,0x52,0x2f,0x68,0x74,0x6d,0x6c,0x34,0x2f,0x6c,0x6f,0x6f,0x73,0x65,
0x2e,0x64,0x74,0x64,0x22,0x3e,0x0a,0x3c,0x48,0x54,0x4d,0x4c,0x3e,0x0a,0x3c,0x48,
0x45,0x41,0x44,0x3e,0x0a,0x3c,0x54,0x49,0x54,0x4c,0x45,0x3e,0x58,0x42,0x6c,0x61,
0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,0x46,0x6c,0x61,0x73,0x68,
0x3c,0x2f,0x54,0x49,0x54,0x4c,0x45,0x3e,0x0a,0x3c,0x4d,0x45,0x54,0x41,0x20,0x68,
0x74,0x74,0x70,0x2d,0x65,0x71,0x75,0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,
0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,
0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,0x68,0x74,0x6d,0x6c,0x3b,0x20,0x63,0x68,0x61,
0x72,0x73,0x65,0x74,0x3d,0x69,0x73,0x6f,0x2d,0x38,0x38,0x35,0x39,0x2d,0x31,0x22,
0x3e,0x0a,0x3c,0x53,0x54,0x59,0x4c,0x45,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x74,
0x65,0x78,0x74,0x2f,0x63,0x73,0x73,0x22,0x20,0x4d,0x45,0x44,0x49,0x41,0x3d,0x73,
0x63,0x72,0x65,0x65,0x6e,0x3e,0x0a,0x0a,0x3c,0x2f,0x53,0x54,0x59,0x4c,0x45,0x3e,
0x0a,0x3c,0x2f,0x48,0x45,0x41,0x44,0x3e,0x0a,0x3c,0x42,0x4f,0x44,0x59,0x20,0x73,
0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,
0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x30,0x31,0x32,0x46,0x35,0x33,0x22,
0x3e,0x0a,0x0a,0x3c,0x44,0x49,0x56,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x63,
0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x55,
0x73,0x65,0x20,0x74,0x68,0x65,0x20,0x66,0x6f,0x72,0x6d,0x20,0x62,0x65,0x6c,0x6f,
0x77,0x20,0x74,0x6f,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x61,0x6e,0x20,0x45,
0x45,0x50,0x52,0x4f,0x4d,0x20,0x69,0x6d,0x61,0x67,0x65,0x20,0x74,0x6f,0x20,0x6c,
0x6f,0x63,0x6b,0x2f,0x75,0x6e,0x6c,0x6f,0x63,0x6b,0x20,0x79,0x6f,0x75,0x72,0x20,
0x48,0x44,0x44,0x2e,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x3c,0x42,0x3e,0x57,
0x41,0x52,0x4e,0x49,0x4e,0x47,0x21,0x3c,0x2f,0x42,0x3e,0x20,0x0a,0x49,0x74,0x20,
0x77,0x69,0x6c,0x6c,0x20,0x75,0x73,0x65,0x20,0x74,0x68,0x65,0x20,0x66,0x69,0x6c,
0x65,0x20,0x79,0x6f,0x75,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x74,0x6f,0x20,
0x74,0x72,0x79,0x20,0x61,0x6e,0x64,0x20,0x6c,0x6f,0x63,0x6b,0x20,0x6f,0x72,0x20,
0x75,0x6e,0x6c,0x6f,0x63,0x6b,0x20,0x79,0x6f,0x75,0x72,0x20,0x48,0x44,0x44,0x2e,
0x3c,0x70,0x3e,0x20,0x0a,0x4d,0x61,0x6b,0x65,0x20,0x73,0x75,0x72,0x65,0x20,0x79,
0x6f,0x75,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x74,0x68,0x65,0x20,0x63,0x6f,
0x72,0x72,0x65,0x63,0x74,0x20,0x66,0x69,0x6c,0x65,0x20,0x66,0x6f,0x72,0x20,0x79,
0x6f,0x75,0x72,0x20,0x48,0x44,0x44,0x21,0x3c,0x2f,0x70,0x3e,0x0a,0x3c,0x2f,0x44,
0x49,0x56,0x3e,0x0a,0x0a,0x3c,0x44,0x49,0x56,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,
0x22,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,
0x0a,0x3c,0x46,0x4f,0x52,0x4d,0x20,0x4d,0x45,0x54,0x48,0x4f,0x44,0x3d,0x22,0x50,
0x4f,0x53,0x54,0x22,0x20,0x45,0x4e,0x43,0x54,0x59,0x50,0x45,0x3d,0x22,0x6d,0x75,
0x6c,0x74,0x69,0x70,0x61,0x72,0x74,0x2f,0x66,0x6f,0x72,0x6d,0x2d,0x64,0x61,0x74,
0x61,0x22,0x20,0x41,0x43,0x54,0x49,0x4f,0x4e,0x3d,0x22,0x2f,0x30,0x22,0x3e,0x0a,
0x53,0x65,0x6c,0x65,0x63,0x74,0x20,0x45,0x45,0x50,0x52,0x4f,0x4d,0x20,0x46,0x69,
0x6c,0x65,0x3a,0x20,0x3c,0x49,0x4e,0x50,0x55,0x54,0x20,0x54,0x59,0x50,0x45,0x3d,
0x22,0x66,0x69,0x6c,0x65,0x22,0x20,0x4e,0x41,0x4d,0x45,0x3d,0x22,0x62,0x69,0x6f,
0x73,0x62,0x69,0x6e,0x22,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x63,0x6f,0x6c,
0x6f,0x72,0x3a,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x3c,0x49,0x4e,
0x50,0x55,0x54,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x73,0x75,0x62,0x6d,0x69,0x74,
0x22,0x20,0x56,0x41,0x4c,0x55,0x45,0x3d,0x22,0x55,0x70,0x6c,0x6f,0x61,0x64,0x20,
0x61,0x6e,0x64,0x20,0x4c,0x6f,0x63,0x6b,0x2f,0x55,0x6e,0x6c,0x6f,0x63,0x6b,0x22,
0x3e,0x0a,0x3c,0x2f,0x46,0x4f,0x52,0x4d,0x3e,0x0a,0x3c,0x2f,0x44,0x49,0x56,0x3e,
0x0a,0x0a,0x3c,0x2f,0x42,0x4f,0x44,0x59,0x3e,0x0a,0x3c,0x2f,0x48,0x54,0x4d,0x4c,
0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__mainEEPROM_html = 8;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__mainEEPROM_html[] FSDATA_ALIGN_POST = {
/* /mainEEPROM.html (17 chars) */
0x2f,0x6d,0x61,0x69,0x6e,0x45,0x45,0x50,0x52,0x4f,0x4d,0x2e,0x68,0x74,0x6d,0x6c,
0x00,0x00,0x00,0x00,

/* raw file data (818 bytes) */
0x3c,0x21,0x44,0x4f,0x43,0x54,0x59,0x50,0x45,0x20,0x48,0x54,0x4d,0x4c,0x20,0x50,
0x55,0x42,0x4c,0x49,0x43,0x20,0x22,0x2d,0x2f,0x2f,0x57,0x33,0x43,0x2f,0x2f,0x44,
0x54,0x44,0x20,0x48,0x54,0x4d,0x4c,0x20,0x34,0x2e,0x30,0x31,0x20,0x54,0x72,0x61,
0x6e,0x73,0x69,0x74,0x69,0x6f,0x6e,0x61,0x6c,0x2f,0x2f,0x45,0x4e,0x22,0x20,0x22,
0x68,0x74,0x74,0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,
0x67,0x2f,0x54,0x52,0x2f,0x68,0x74,0x6d,0x6c,0x34,0x2f,0x6c,0x6f,0x6f,0x73,0x65,
0x2e,0x64,0x74,0x64,0x22,0x3e,0x0a,0x3c,0x48,0x54,0x4d,0x4c,0x3e,0x0a,0x3c,0x48,
0x45,0x41,0x44,0x3e,0x0a,0x3c,0x54,0x49,0x54,0x4c,0x45,0x3e,0x58,0x42,0x6c,0x61,
0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,0x46,0x6c,0x61,0x73,0x68,
0x3c,0x2f,0x54,0x49,0x54,0x4c,0x45,0x3e,0x0a,0x3c,0x4d,0x45,0x54,0x41,0x20,0x68,
0x74,0x74,0x70,0x2d,0x65,0x71,0x75,0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,
0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,
0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,0x68,0x74,0x6d,0x6c,0x3b,0x20,0x63,0x68,0x61,
0x72,0x73,0x65,0x74,0x3d,0x69,0x73,0x6f,0x2d,0x38,0x38,0x35,0x39,0x2d,0x31,0x22,
0x3e,0x0a,0x3c,0x53,0x54,0x59,0x4c,0x45,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x74,
0x65,0x78,0x74,0x2f,0x63,0x73,0x73,0x22,0x20,0x4d,0x45,0x44,0x49,0x41,0x3d,0x73,
0x63,0x72,0x65,0x65,0x6e,0x3e,0x0a,0x0a,0x3c,0x2f,0x53,0x54,0x59,0x4c,0x45,0x3e,
0x0a,0x3c,0x2f,0x48,0x45,0x41,0x44,0x3e,0x0a,0x3c,0x42,0x4f,0x44,0x59,0x20,0x73,
0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,0x67,0x72,0x6f,0x75,0x6e,0x64,
0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x30,0x31,0x32,0x46,0x35,0x33,0x22,
0x3e,0x0a,0x0a,0x3c,0x44,0x49,0x56,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x63,
0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x55,
0x73,0x65,0x20,0x74,0x68,0x65,0x20,0x66,0x6f,0x72,0x6d,0x20,0x62,0x65,0x6c,0x6f,
0x77,0x20,0x74,0x6f,0x20,0x75,0x70,0x64,0x61,0x74,0x65,0x20,0x74,0x68,0x65,0x20,
0x45,0x45,0x50,0x52,0x4f,0x4d,0x20,0x6f,0x66,0x20,0x79,0x6f,0x75,0x72,0x20,0x58,
0x62,0x6f,0x78,0x2e,0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x3c,0x42,0x3e,
0x57,0x41,0x52,0x4e,0x49,0x4e,0x47,0x21,0x3c,0x2f,0x42,0x3e,0x20,0x0a,0x49,0x74,
0x20,0x77,0x69,0x6c,0x6c,0x20,0x75,0x73,0x65,0x20,0x74,0x68,0x65,0x20,0x66,0x69,
0x6c,0x65,0x20,0x79,0x6f,0x75,0x20,0x75,0x70,0x6c,0x6f,0x61,0x64,0x20,0x74,0x6f,
0x20,0x72,0x65,0x70,0x6c,0x61,0x63,0x65,0x20,0x74,0x68,0x65,0x20,0x63,0x6f,0x6e,
0x74,0x65,0x6e,0x74,0x73,0x20,0x6f,0x66,0x20,0x79,0x6f,0x75,0x72,0x20,0x58,0x62,
0x6f,0x78,0x20,0x45,0x45,0x50,0x52,0x4f,0x4d,0x2e,0x3c,0x70,0x3e,0x0a,0x4d,0x61,
0x6b,0x65,0x20,0x73,0x75,0x72,0x65,0x20,0x79,0x6f,0x75,0x20,0x75,0x70,0x6c,0x6f,
0x61,0x64,0x20,0x74,0x68,0x65,0x20,0x63,0x6f,0x72,0x72,0x65,0x63,0x74,0x20,0x66,
0x69,0x6c,0x65,0x20,0x66,0x6f,0x72,0x20,0x79,0x6f,0x75,0x72,0x20,0x58,0x62,0x6f,
0x78,0x21,0x0a,0x3c,0x2f,0x44,0x49,0x56,0x3e,0x0a,0x0a,0x3c,0x44,0x49,0x56,0x20,
0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x46,0x46,
0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x3c,0x46,0x4f,0x52,0x4d,0x20,0x4d,0x45,0x54,
0x48,0x4f,0x44,0x3d,0x22,0x50,0x4f,0x53,0x54,0x22,0x20,0x45,0x4e,0x43,0x54,0x59,
0x50,0x45,0x3d,0x22,0x6d,0x75,0x6c,0x74,0x69,0x70,0x61,0x72,0x74,0x2f,0x66,0x6f,
0x72,0x6d,0x2d,0x64,0x61,0x74,0x61,0x22,0x20,0x41,0x43,0x54,0x49,0x4f,0x4e,0x3d,
0x22,0x2f,0x30,0x22,0x3e,0x0a,0x53,0x65,0x6c,0x65,0x63,0x74,0x20,0x45,0x45,0x50,
0x52,0x4f,0x4d,0x20,0x46,0x69,0x6c,0x65,0x3a,0x20,0x3c,0x49,0x4e,0x50,0x55,0x54,
0x20,0x54,0x59,0x50,0x45,0x3d,0x22,0x66,0x69,0x6c,0x65,0x22,0x20,0x4e,0x41,0x4d,
0x45,0x3d,0x22,0x62,0x69,0x6f,0x73,0x62,0x69,0x6e,0x22,0x20,0x73,0x74,0x79,0x6c,
0x65,0x3d,0x22,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x23,0x46,0x46,0x46,0x46,0x46,0x46,
0x22,0x3e,0x0a,0x3c,0x49,0x4e,0x50,0x55,0x54,0x20,0x54,0x59,0x50,0x45,0x3d,0x22,
0x73,0x75,0x62,0x6d,0x69,0x74,0x22,0x20,0x56,0x41,0x4c,0x55,0x45,0x3d,0x22,0x55,
0x70,0x6c,0x6f,0x61,0x64,0x20,0x61,0x6e,0x64,0x20,0x46,0x6c,0x61,0x73,0x68,0x22,
0x3e,0x0a,0x3c,0x2f,0x46,0x4f,0x52,0x4d,0x3e,0x0a,0x3c,0x2f,0x44,0x49,0x56,0x3e,
0x0a,0x0a,0x3c,0x2f,0x42,0x4f,0x44,0x59,0x3e,0x0a,0x3c,0x2f,0x48,0x54,0x4d,0x4c,
0x3e,0x0a,};

#if FSDATA_FILE_ALIGNMENT==1
static const unsigned int dummy_align__ok_html = 9;
#endif
static const unsigned char FSDATA_ALIGN_PRE data__ok_html[] FSDATA_ALIGN_POST = {
/* /ok.html (9 chars) */
0x2f,0x6f,0x6b,0x2e,0x68,0x74,0x6d,0x6c,0x00,0x00,0x00,0x00,

/* raw file data (425 bytes) */
0x3c,0x68,0x74,0x6d,0x6c,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x27,0x68,0x74,0x74,
0x70,0x3a,0x2f,0x2f,0x77,0x77,0x77,0x2e,0x77,0x33,0x2e,0x6f,0x72,0x67,0x2f,0x31,
0x39,0x39,0x39,0x2f,0x78,0x68,0x74,0x6d,0x6c,0x27,0x20,0x3e,0x0a,0x20,0x20,0x3c,
0x68,0x65,0x61,0x64,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x74,0x69,0x74,0x6c,0x65,
0x3e,0x58,0x42,0x6c,0x61,0x73,0x74,0x20,0x4f,0x53,0x3a,0x20,0x4e,0x65,0x74,0x20,
0x46,0x6c,0x61,0x73,0x68,0x3c,0x2f,0x74,0x69,0x74,0x6c,0x65,0x3e,0x0a,0x20,0x20,
0x20,0x20,0x3c,0x6d,0x65,0x74,0x61,0x20,0x68,0x74,0x74,0x70,0x2d,0x65,0x71,0x75,
0x69,0x76,0x3d,0x22,0x43,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x2d,0x54,0x79,0x70,0x65,
0x22,0x20,0x63,0x6f,0x6e,0x74,0x65,0x6e,0x74,0x3d,0x22,0x74,0x65,0x78,0x74,0x2f,
0x68,0x74,0x6d,0x6c,0x3b,0x63,0x68,0x61,0x72,0x73,0x65,0x74,0x3d,0x41,0x53,0x43,
0x49,0x49,0x22,0x3e,0x0a,0x20,0x20,0x3c,0x2f,0x68,0x65,0x61,0x64,0x3e,0x0a,0x3c,
0x42,0x4f,0x44,0x59,0x20,0x73,0x74,0x79,0x6c,0x65,0x3d,0x22,0x62,0x61,0x63,0x6b,
0x67,0x72,0x6f,0x75,0x6e,0x64,0x2d,0x63,0x6f,0x6c,0x6f,0x72,0x3a,0x20,0x23,0x30,
0x31,0x32,0x46,0x35,0x33,0x22,0x3e,0x0a,0x3c,0x66,0x6f,0x6e,0x74,0x20,0x63,0x6f,
0x6c,0x6f,0x72,0x3d,0x22,0x23,0x46,0x46,0x46,0x46,0x46,0x46,0x22,0x3e,0x0a,0x20,
0x20,0x20,0x20,0x3c,0x68,0x32,0x3e,0x59,0x6f,0x75,0x72,0x20,0x42,0x49,0x4f,0x53,
0x20,0x69,0x73,0x20,0x62,0x65,0x69,0x6e,0x67,0x20,0x66,0x6c,0x61,0x73,0x68,0x65,
0x64,0x2e,0x2e,0x2e,0x3c,0x2f,0x68,0x32,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x62,
0x3e,0x44,0x6f,0x20,0x6e,0x6f,0x74,0x20,0x74,0x6f,0x75,0x63,0x68,0x20,0x74,0x68,
0x65,0x20,0x63,0x6f,0x6e,0x73,0x6f,0x6c,0x65,0x20,0x64,0x75,0x72,0x69,0x6e,0x67,
0x20,0x74,0x68,0x69,0x73,0x20,0x70,0x72,0x6f,0x63,0x65,0x73,0x73,0x21,0x3c,0x2f,
0x62,0x3e,0x0a,0x20,0x20,0x20,0x20,0x3c,0x62,0x72,0x3e,0x3c,0x62,0x72,0x3e,0x20,
0x0a,0x20,0x20,0x20,0x20,0x46,0x6c,0x61,0x73,0x68,0x69,0x6e,0x67,0x20,0x70,0x72,
0x6f,0x67,0x72,0x65,0x73,0x73,0x20,0x77,0x69,0x6c,0x6c,0x20,0x62,0x65,0x20,0x73,
0x68,0x6f,0x77,0x6e,0x20,0x6f,0x6e,0x20,0x79,0x6f,0x75,0x72,0x20,0x54,0x56,0x2e,
0x0a,0x3c,0x2f,0x66,0x6f,0x6e,0x74,0x3e,0x0a,0x3c,0x2f,0x42,0x4f,0x44,0x59,0x3e,
0x0a,0x3c,0x2f,0x48,0x54,0x4d,0x4c,0x3e,0x0a,};



const struct fsdata_file file__404_html[] = { {
file_NULL,
data__404_html,
data__404_html + 12,
sizeof(data__404_html) - 12,
0,
}};

const struct fsdata_file file__failHDDLOCK_html[] = { {
file__404_html,
data__failHDDLOCK_html,
data__failHDDLOCK_html + 20,
sizeof(data__failHDDLOCK_html) - 20,
0,
}};

const struct fsdata_file file__okHDDLOCK_html[] = { {
file__failHDDLOCK_html,
data__okHDDLOCK_html,
data__okHDDLOCK_html + 16,
sizeof(data__okHDDLOCK_html) - 16,
0,
}};

const struct fsdata_file file__main_html[] = { {
file__okHDDLOCK_html,
data__main_html,
data__main_html + 12,
sizeof(data__main_html) - 12,
0,
}};

const struct fsdata_file file__failEEPROM_html[] = { {
file__main_html,
data__failEEPROM_html,
data__failEEPROM_html + 20,
sizeof(data__failEEPROM_html) - 20,
0,
}};

const struct fsdata_file file__fail_html[] = { {
file__failEEPROM_html,
data__fail_html,
data__fail_html + 12,
sizeof(data__fail_html) - 12,
0,
}};

const struct fsdata_file file__okEEPROM_html[] = { {
file__fail_html,
data__okEEPROM_html,
data__okEEPROM_html + 16,
sizeof(data__okEEPROM_html) - 16,
0,
}};

const struct fsdata_file file__mainHDDLOCK_html[] = { {
file__okEEPROM_html,
data__mainHDDLOCK_html,
data__mainHDDLOCK_html + 20,
sizeof(data__mainHDDLOCK_html) - 20,
0,
}};

const struct fsdata_file file__mainEEPROM_html[] = { {
file__mainHDDLOCK_html,
data__mainEEPROM_html,
data__mainEEPROM_html + 20,
sizeof(data__mainEEPROM_html) - 20,
0,
}};

const struct fsdata_file file__ok_html[] = { {
file__mainEEPROM_html,
data__ok_html,
data__ok_html + 12,
sizeof(data__ok_html) - 12,
0,
}};

#define FS_ROOT file__ok_html
#define FS_NUMFILES 10

