#ifndef _LINUX_NFS_MOUNT_H
#define _LINUX_NFS_MOUNT_H

/*
 *  linux/include/linux/nfs_mount.h
 *
 *  Copyright (C) 1992  Rick Sladkey
 *
 *  structure passed from user-space to kernel-space during an nfs mount
 */

/*
 * WARNING!  Do not delete or change the order of these fields.  If
 * a new field is required then add it to the end.  The version field
 * tracks which fields are present.  This will ensure some measure of
 * mount-to-kernel version compatibilty.  Some of these aren't used yet
 * but here they are anyway.
 */

#define NFS_MOUNT_VERSION	1	/* current version */

struct nfs_mount_data
{
    int version;			/* 1 */
    int fd;				/* 1 */
    struct nfs_fh root;		/* 1 */
    int flags;			/* 1 */
    int rsize;			/* 1 */
    int wsize;			/* 1 */
    int timeo;			/* 1 */
    int retrans;			/* 1 */
    int acregmin;			/* 1 */
    int acregmax;			/* 1 */
    int acdirmin;			/* 1 */
    int acdirmax;			/* 1 */
    struct sockaddr_in addr;	/* 1 */
    char hostname[256];		/* 1 */
};

/* bits in the flags field */

#define NFS_MOUNT_SOFT		0x0001	/* 1 */
#define NFS_MOUNT_INTR		0x0002	/* 1 */
#define NFS_MOUNT_SECURE	0x0004	/* 1 */
#define NFS_MOUNT_POSIX		0x0008	/* 1 */
#define NFS_MOUNT_NOCTO		0x0010	/* 1 */
#define NFS_MOUNT_NOAC		0x0020	/* 1 */

#endif
