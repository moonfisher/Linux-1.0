/*
 *  linux/fs/filesystems.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 *
 *  table of configured filesystems
 */

#include "linux/config.h"
#include "linux/fs.h"
#include "linux/minix_fs.h"
#ifdef CONFIG_XIA_FS
#include "linux/xia_fs.h"
#endif
#include "linux/proc_fs.h"
#include "linux/ext2_fs.h"
#include "linux/ext_fs.h"
#include "linux/msdos_fs.h"
#include "linux/nfs_fs.h"
#ifdef CONFIG_ISO9660_FS
#include "linux/iso_fs.h"
#endif
#ifdef CONFIG_HPFS_FS
#include "linux/hpfs_fs.h"
#endif
#ifdef CONFIG_SYSV_FS
#include "linux/sysv_fs.h"
#endif

struct file_system_type file_systems[] =
    {
        {minix_read_super, "minix", 1},
        {ext_read_super, "ext", 1},
        {ext2_read_super, "ext2", 1},
#ifdef CONFIG_XIA_FS
        {xiafs_read_super, "xiafs", 1},
#endif
        {msdos_read_super, "msdos", 1},
        {proc_read_super, "proc", 0},
        {nfs_read_super, "nfs", 0},
#ifdef CONFIG_ISO9660_FS
        {isofs_read_super, "iso9660", 1},
#endif
#ifdef CONFIG_SYSV_FS
        {sysv_read_super, "xenix", 1},
        {sysv_read_super, "sysv", 1},
        {sysv_read_super, "coherent", 1},
#endif
#ifdef CONFIG_HPFS_FS
        {hpfs_read_super, "hpfs", 1},
#endif
        {NULL, NULL, 0}};
