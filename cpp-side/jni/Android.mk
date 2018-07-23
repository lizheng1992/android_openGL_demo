LOCAL_PATH:=$(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE:=libmygles
LOCAL_SRC_FILES:=opengl.cpp utils.cpp vertexbuffer.cpp skybox.cpp \
		shader.cpp particlesystem.cpp model.cpp ground.cpp scene.cpp


LOCAL_LDLIBS:=-llog -lGLESv3 -landroid

include $(BUILD_SHARED_LIBRARY)