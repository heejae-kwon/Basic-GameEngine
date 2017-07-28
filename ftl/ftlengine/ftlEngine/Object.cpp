/*
Obejct.cpp
HeeJae Kwon
*/
#include "Object.hpp"

using namespace SWE;

Object::Object() : transform(nullptr), controller(nullptr)
{
}

Object::~Object()
{
}

void Object::Initialize()
{
				//pCompVec
				if (transform) {
								transform->Initialize();
				}
				if (controller) {
								controller->Initialize();
				}
}

//Signal the object 
void Object::Destroy()
{
}

bool Object::AddComponent(Component* pComponent)
{
				//Add component and return true if success
				ComponentType type= pComponent->GetType();
				if (type > CT_INVALID && type < CT_NUM_COMPONENTS) {
								pComponent->SetOwner(this);
				}
				switch (pComponent->GetType())
				{
				case CT_TRANSFORM: { transform = static_cast<Transform*>(pComponent); return true; }break;
				case CT_CONTROLLER: { controller = static_cast<Controller*>(pComponent); return true; }break;
				default:
								break;
				}
				return false; //if failed
}

Component* Object::GetComponent(ComponentType type)
{
				switch (type)
				{
				case CT_TRANSFORM: {
								return transform;
				}break;
				case CT_CONTROLLER: {
								return controller;
				}break;	
				}

				return nullptr;
}
