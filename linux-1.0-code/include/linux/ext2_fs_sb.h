/*
 *  linux/include/linux/ext2_fs_sb.h
 *
 *  Copyright (C) 1992, 1993, 1994  Remy Card (card@masi.ibp.fr)
 *                                  Laboratoire MASI - Institut Blaise Pascal
 *                                  Universite Pierre et Marie Curie (Paris VI)
 *
 *  from
 *
 *  linux/include/linux/minix_fs_sb.h
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 */

#ifndef _LINUX_EXT2_FS_SB
#define _LINUX_EXT2_FS_SB

#define EXT2_MAX_GROUP_DESC	8
#define EXT2_MAX_GROUP_LOADED	8

/*
 * second extended-fs super-block data in memory
 */
struct ext2_sb_info
{
    unsigned long s_frag_size;	/* Size of a fragment in bytes */
    unsigned long s_frags_per_block;/* Number of fragments per block */
    unsigned long s_inodes_per_block;/* Number of inodes per block */
    unsigned long s_frags_per_group;/* Number of fragments in a group */
    unsigned long s_blocks_per_group;/* Number of blocks in a group */
    unsigned long s_inodes_per_group;/* Number of inodes in a group */
    unsigned long s_itb_per_group;	/* Number of inode table blocks per group */
    unsigned long s_desc_per_block;	/* Number of group descriptors per block */
    unsigned long s_groups_count;	/* Number of groups in the fs */
    struct buffer_head *s_sbh;	/* Buffer containing the super block */
    struct ext2_super_block *s_es;	/* Pointer to the super block in the buffer */
    struct buffer_head *s_group_desc[EXT2_MAX_GROUP_DESC];
    unsigned short s_loaded_inode_bitmaps;
    unsigned short s_loaded_block_bitmaps;
    unsigned long s_inode_bitmap_number[EXT2_MAX_GROUP_LOADED];
    struct buffer_head *s_inode_bitmap[EXT2_MAX_GROUP_LOADED];
    unsigned long s_block_bitmap_number[EXT2_MAX_GROUP_LOADED];
    struct buffer_head *s_block_bitmap[EXT2_MAX_GROUP_LOADED];
    int s_rename_lock;
    struct wait_queue *s_rename_wait;
    unsigned long  s_mount_opt;
    unsigned short s_mount_state;
};

#endif	/* _LINUX_EXT2_FS_SB */
