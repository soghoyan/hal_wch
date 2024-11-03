# CMakeLists.txt - WCH HAL
#
# Copyright (c) 2024 Armen Soghoyan <asoghoyan@yahoo.com>
#
# SPDX-License-Identifier: Apache-2.0

add_subdirectory_ifdef(CONFIG_HAS_WCH_HAL lib)
