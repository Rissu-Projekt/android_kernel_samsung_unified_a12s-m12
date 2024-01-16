# SPDX-License-Identifier: GPL-2.0
# Create dtb/dtbo for Galaxy A12s

# Build exynos Device Tree Blobs
dtb-y += exynos/exynos3830.dtb

$(info -- Target Device: [A127X])

dtbo-y += samsung/a12s/a12s_eur_open_w00_r00.dtbo
dtbo-y += samsung/a12s/a12s_eur_open_w00_r01.dtbo

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)
always    := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
