#include"ggl.h"
#include"scene.h"
#include <sys/time.h>
AAssetManager*sAssetManager=nullptr;
unsigned char * LoadFileContent(const char*path,int & fileSize){
    unsigned char*fileContent=nullptr;
    AAsset*asset=AAssetManager_open(sAssetManager,path,AASSET_MODE_UNKNOWN);
    if(asset==nullptr){
        return nullptr;
    }
    fileSize=AAsset_getLength(asset);
    fileContent=new unsigned char[fileSize+1];
    AAsset_read(asset,fileContent,fileSize);
    fileContent[fileSize]='\0';
    AAsset_close(asset);
    return fileContent;
}
float GetFrameTime() {
	static unsigned long long lastTime = 0, timeCurrent = 0;
	timeval current;
	gettimeofday(&current,nullptr);
	timeCurrent=current.tv_sec*1000+current.tv_usec/1000;
	unsigned long long frameTime = lastTime == 0 ? 0 : timeCurrent - lastTime;
	lastTime = timeCurrent;
	return float(frameTime) / 1000.0f;
}
extern "C" JNIEXPORT void Java_cn_battlefire_gl_Native_InitAssetManager(JNIEnv*env,jobject obj,jobject assetManager){
    sAssetManager=AAssetManager_fromJava(env,assetManager);
}

extern "C" JNIEXPORT void Java_cn_battlefire_gl_Native_InitOpenGL(JNIEnv*env,jobject obj){
	Init();
}
extern "C" JNIEXPORT void Java_cn_battlefire_gl_Native_OnViewportChanged(JNIEnv*env,jobject obj,jfloat width,jfloat height){
	SetViewPortSize(width,height);
}
extern "C" JNIEXPORT void Java_cn_battlefire_gl_Native_RenderOneFrame(JNIEnv*env,jobject obj){
    Draw();
}