#pragma once
#include "System.hpp"
#include "GL\glew.h"
#include <memory>

namespace SWE {

				class Graphics :public System
				{
				public:
								//Magical singletern code
								  static Graphics* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<Graphics> instance(new Graphics());
            return instance.get();
        }
								~Graphics();
																//Initialize the system
								void Initialize(void) override;

							//All systems are updated every frame
								void Update(float dt) override;

								//All systems need a virtual destructor to their desturctors called

				private:
								Graphics();
								GLuint CreateShader(GLenum Shadertype, const char * fileName);


								GLuint program;
								GLuint VAO;

				};

}