LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cpp .cc

ifeq ($(TARGET_ARCH_ABI), armeabi-v7a)
    LOCAL_MODULE    := AimForTheCamera
else
    LOCAL_MODULE    := AimForTheCamera64
endif
#LOCAL_SRC_FILES :=  sdk/sdk.cpp main.cpp mod/logger.cpp mod/config.cpp

#FILE_LIST := $(wildcard $(LOCAL_PATH)/game_sa/*.cpp)
LOCAL_SRC_FILES := main.cpp mod/logger.cpp mod/config.cpp CCamera.cpp #sdk/Events.cpp

#LOCAL_SRC_FILES += $(patsubst $(LOCAL_PATH)/%, %, $(FILE_LIST)) 

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    LOCAL_CFLAGS += -mfloat-abi=softfp
endif

LOCAL_CFLAGS += -O2 -DNDEBUG -std=c++17

LOCAL_LDLIBS += -llog
include $(BUILD_SHARED_LIBRARY)