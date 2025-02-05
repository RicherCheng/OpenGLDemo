#include "gameobject.h"
void GameObject::add(GameObject* child){
    child->parent = this;
}
void GameObject::draw(float time){
	return;
}

glm::mat4 GameObject::getModelMat(GameObject* root){
    GameObject* p = root;
    if (p->parent == NULL){
        return glm::rotate(glm::scale(glm::translate(glm::mat4(), p->local_position), p->scale_rate), p->quaternion.w, p->quaternion.axis());
    }

    return glm::rotate(glm::scale(glm::translate(getModelMat(p->parent), p->local_position), p->scale_rate), p->quaternion.w, p->quaternion.axis());
}

mymathlib::Mat4 GameObject::getModelMat1(GameObject* root){
	GameObject* p = root;
	if (p->parent == NULL){
		return mymathlib::rotate(mymathlib::scale(mymathlib::translate(mymathlib::Mat4(), p->local_position), p->scale_rate), p->quaternion);
	}

	return mymathlib::rotate(mymathlib::scale(mymathlib::translate(p->getModelMat1(p->parent), p->local_position), p->scale_rate), p->quaternion);
}

void GameObject::setPosition(glm::vec3 pos){
    local_position = pos;
}

glm::vec3 GameObject::getPosition(){
    return local_position;
}

void GameObject::setScale(glm::vec3 rate){
    scale_rate = rate;
}

glm::vec3 GameObject::getScale(){
    return scale_rate;
}

void GameObject::setQuaternion(Quat quat){
    quaternion = quat;
}

Quat GameObject::getQuaternion(){
    return quaternion;
}

Type GameObject::getType(){
	return type;
}

glm::vec3 GameObject::getWorldPosition(){
	glm::mat4 model_mat = getModelMat(this);
	return glm::vec3(model_mat[3][0], model_mat[3][1], model_mat[3][2]);
}