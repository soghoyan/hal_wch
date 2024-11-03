# CMakeLists.txt - WCH ISP Library
#
# Copyright (c) 2024 Armen Soghoyan <asoghoyan@yahoo.com>
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_SOC_CH56X)
    zephyr_include_directories(include/ch56x)
    zephyr_library_import(wchisp_lib ${CMAKE_CURRENT_SOURCE_DIR}/libISPEM569.a)
elseif(CONFIG_SOC_CH57X)
    zephyr_include_directories(include/ch5xx)
    zephyr_library_import(wchisp_lib ${CMAKE_CURRENT_SOURCE_DIR}/libISP573.a)
	zephyr_linker_sources(RAMFUNC_SECTION highcode.ld)
elseif(CONFIG_SOC_CH58X)
    zephyr_include_directories(include/ch5xx)
    zephyr_library_import(wchisp_lib ${CMAKE_CURRENT_SOURCE_DIR}/libISP583.a)
	zephyr_linker_sources(RAMFUNC_SECTION highcode.ld)
endif()
