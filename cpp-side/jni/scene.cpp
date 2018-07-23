#include "scene.h"
#include "utils.h"
#include "skybox.h"
#include "ground.h"
#include "vertexbuffer.h"
#include "shader.h"
#include "model.h"
#include "particlesystem.h"
glm::mat4 projectionMatrix, viewMatrix,modelMatrix;
glm::vec3 cameraPos(10.0f, 10.0f, 10.0f);
SkyBox skybox;
Ground ground;
Model model,niutou;
ParticleSystem ps;
void Init() {
	//glewInit();android or ios do not have glewInit
	viewMatrix = glm::lookAt(cameraPos, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f,1.0f,0.0f));
	skybox.Init("Res/");
	ground.Init();
	model.Init("Res/Sphere.obj");
	model.SetTexture("Res/earth.bmp");
	model.SetPosition(0.0f, 0.0f, 0.0f);
	niutou.Init("Res/niutou.obj");
	niutou.SetTexture("Res/niutou.bmp");
	niutou.mModelMatrix = glm::translate(-5.0f, 0.0f, 4.0f)*glm::scale(0.05f, 0.05f, 0.05f);
	ps.Init(0.0f, -10.0f, 0.0f);
}
void SetViewPortSize(float width, float height) {
	projectionMatrix = glm::perspective(60.0f, width / height, 0.1f, 1000.0f);
}
void Draw() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	float frameTime = GetFrameTime();
	skybox.Draw(cameraPos.x,cameraPos.y,cameraPos.z,viewMatrix, projectionMatrix);
	ground.Draw(viewMatrix, projectionMatrix);
	model.Draw(cameraPos.x, cameraPos.y, cameraPos.z, viewMatrix, projectionMatrix);
	niutou.Draw(cameraPos.x, cameraPos.y, cameraPos.z, viewMatrix, projectionMatrix);
	ps.Update(frameTime);
	ps.Draw(viewMatrix, projectionMatrix);
}