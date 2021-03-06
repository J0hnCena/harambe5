#pragma once

#include <irrlicht.h>
#include <string>

class Entity {
public:
  Entity(irr::IrrlichtDevice* dev, const std::string& mediaPath, irr::core::vector3df position, irr::core::vector3df rotation, irr::scene::IMeshSceneNode* map);
  virtual void initialize() = 0;
  virtual void update(float delta) = 0;
  virtual void addCollision();
  void rotateTowardsPosition(irr::core::vector3df target);
protected:
  std::string path;
  const static float speed = 1.0;
  
  irr::core::vector3df pos;
  irr::core::vector3df rot;
  
  irr::IrrlichtDevice* device;
  irr::scene::ISceneManager* manager;
  irr::video::IVideoDriver* driver;
  irr::scene::IAnimatedMesh* mesh;
  irr::scene::IMeshSceneNode* mapNode;
  irr::scene::IAnimatedMeshSceneNode* entityNode;
};