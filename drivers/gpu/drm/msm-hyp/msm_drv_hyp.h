/*
 * Copyright (C) 2013 Red Hat
 * Author: Rob Clark <robdclark@gmail.com>
 *
 * Copyright (c) 2017 The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __MSM_DRV_HYP_H__
#define __MSM_DRV_HYP_H__

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/list.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/sizes.h>
#include <linux/kthread.h>

#include <drm/drmP.h>

struct msm_file_private {
	/* currently we don't do anything useful with this.. but when
	 * per-context address spaces are supported we'd keep track of
	 * the context's page-tables here.
	 */
	int dummy;
};

enum msm_mdp_display_id {
	DISPLAY_ID_NONE,
	DISPLAY_ID_PRIMARY,
	DISPLAY_ID_SECONDARY,
	DISPLAY_ID_TERTIARY,
	DISPLAY_ID_QUATERNARY,
	DISPLAY_ID_MAX
};

struct msm_drm_private {
	struct msm_file_private *lastctx;
};

#define DBG(fmt, ...) DRM_DEBUG(fmt"\n", ##__VA_ARGS__)
#define VERB(fmt, ...) (if (0) DRM_DEBUG(fmt"\n", ##__VA_ARGS__))

static inline enum msm_mdp_display_id msm_get_display_id(
	const char *display_type)
{
	if (!display_type)
		return DISPLAY_ID_NONE;
	else if (!strcmp(display_type, "primary"))
		return DISPLAY_ID_PRIMARY;
	else if (!strcmp(display_type, "secondary"))
		return DISPLAY_ID_SECONDARY;
	else if (!strcmp(display_type, "tertiary"))
		return DISPLAY_ID_TERTIARY;
	else if (!strcmp(display_type, "quaternary"))
		return DISPLAY_ID_QUATERNARY;
	else
		return DISPLAY_ID_NONE;
};

/* for the generated headers: */
#define FIELD(val, name) (((val) & name ## __MASK) >> name ## __SHIFT)

/* for conditionally setting boolean flag(s): */
#define COND(bool, val) ((bool) ? (val) : 0)

#endif /* __MSM_DRV_HYP_H__ */
