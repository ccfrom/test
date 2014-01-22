/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _UPDATER_UPDATER_H_
#define _UPDATER_UPDATER_H_

#include <stdio.h>
#include "minzip/Zip.h"

#ifdef HAVE_SELINUX
#include <selinux/selinux.h>
#include <selinux/label.h>
#else
struct selabel_handle;
#endif

typedef struct {
    FILE* cmd_pipe;
    ZipArchive* package_zip;
    int version;
} UpdaterInfo;

extern struct selabel_handle *sehandle;

typedef struct {
    const char* mount_point;  // eg. "/cache".  must live in the root directory.

    const char* fs_type;      // "yaffs2" or "ext4" or "vfat"

    const char* device;       // MTD partition name if fs_type == "yaffs"
                              // block device if fs_type == "ext4" or "vfat"

    const char* device2;      // alternative device to try if fs_type
                              // == "ext4" or "vfat" and mounting
                              // 'device' fails

    long long length;         // (ext4 partition only) when
                              // formatting, size to use for the
                              // partition.  0 or negative number
                              // means to format all but the last
                              // (that much).
} Volume;

struct bootloader_message {
    char command[32];
    char status[32];
    char recovery[1024];
};

#endif
