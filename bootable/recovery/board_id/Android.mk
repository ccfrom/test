LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PREBUILT_LIBS :=libboard_id_recovery.a

include $(BUILD_MULTI_PREBUILT)

