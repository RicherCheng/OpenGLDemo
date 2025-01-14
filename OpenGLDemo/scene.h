/*
场景，包含了一些物体，shader，灯光的数组，封装了自己的渲染流程
*/
#ifndef SCENE_H
#define SCENE_H
#include<memory>
#include<vector>

#include"model.h"
#include"shader.h"
#include"camera.h"
#include"light.h"

class Scene{
public:
	Scene();
	~Scene();
    Camera camera;
    vector<Light> light_list;
    vector<Shader *> shader_list;
    vector<GameObject *> common_object_list;
    vector<GameObject *> transparent_object_list;
	vector<GameObject *> empty_object_list;
    void render(unsigned int src_width, unsigned int src_height, float time);
	void add(GameObject* go);
	void add(Shader* shader);
	void add(Light light);

};

#endif