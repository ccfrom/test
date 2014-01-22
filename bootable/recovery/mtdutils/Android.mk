LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	mtdutils.c \
	mounts.c
ifeq ($(TARGET_ROCHCHIP_RECOVERY),true)
# TARGET_BOARD_PLATFORM is change from rockchip to rk29xx or rk30xx
# so force TARGET_BOARD_PLATFORM to be rockchip in recovery cpp file
LOCAL_CFLAGS += -DTARGET_BOARD_PLATFORM=rockchip
LOCAL_SRC_FILES += rk29.c
endif # TARGET_BOARD_PLATFORM == rockchip

LOCAL_MODULE := libmtdutils

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := flash_image.c
LOCAL_MODULE := flash_image
LOCAL_MODULE_TAGS := eng
LOCAL_STATIC_LIBRARIES := libmtdutils
LOCAL_SHARED_LIBRARIES := libcutils libc
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_SRC_FILES:= mkdosfs.c
LOCAL_STATIC_LIBRARIES := libcutils libc
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE:= mkdosfs
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT_SBIN)
include $(BUILD_EXECUTABLE)

