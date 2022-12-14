// Axel Giuseppe Flores Aranda
// CU: 181218

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include <shader_s.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 1000;
const unsigned int SCR_HEIGHT = 1000;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
// Rojo
const char* fragmentShader1Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.7f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";
// Azul
const char* fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.1f, 0.5f, 1.0f, 1.0f);\n"
"}\n\0";
// Cafe
const char* fragmentShader3Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.55f, 0.21f, 0.0f, 1.0f);\n"
"}\n\0";
// Azul oscuro
const char* fragmentShader4Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.1f, 0.3f, 0.8f, 1.0f); \n"
"}\n\0";
// Negro
const char* fragmentShader5Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f); \n"
"}\n\0";
// Verde fuerte
const char* fragmentShader6Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.2f, 0.5f, 0.1f, 1.0f); \n"
"}\n\0";
// Verde claro
const char* fragmentShader7Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.3f, 0.65f, 0.25f, 1.0f); \n"
"}\n\0";
// Cyan oscuro
const char* fragmentShader8Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.3f, 0.4f, 1.0f);\n"
"}\n\0";
// Cyan
const char* fragmentShader9Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.8f, 0.8f, 1.0f);\n"
"}\n\0";

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Tarea 2 // Axel Giuseppe Flores Aranda // CU:181218", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    Shader ourShader("4.1.texture.vs", "4.1.texture.fs");

    // we skipped compile log checks this time for readability (if you do encounter issues, add the compile-checks! see previous code samples)
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader3 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader4 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader5 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader6 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader7 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader8 = glCreateShader(GL_FRAGMENT_SHADER);
    unsigned int fragmentShader9 = glCreateShader(GL_FRAGMENT_SHADER); // Poly
    unsigned int fragmentShader10 = glCreateShader(GL_FRAGMENT_SHADER); // Cuad1
    unsigned int fragmentShader11 = glCreateShader(GL_FRAGMENT_SHADER); // Cuad2
    //unsigned int fragmentShader12 = glCreateShader(GL_FRAGMENT_SHADER); // Cuad3
    unsigned int fragmentShader13 = glCreateShader(GL_FRAGMENT_SHADER); // Fan1
    unsigned int fragmentShader14 = glCreateShader(GL_FRAGMENT_SHADER); // Fan2
    unsigned int fragmentShader15 = glCreateShader(GL_FRAGMENT_SHADER); // Fan3
    unsigned int fragmentShader16 = glCreateShader(GL_FRAGMENT_SHADER); // Fan4
    unsigned int fragmentShader17 = glCreateShader(GL_FRAGMENT_SHADER); // Fan5
    unsigned int fragmentShader18 = glCreateShader(GL_FRAGMENT_SHADER); // Fan6
    unsigned int fragmentShader19 = glCreateShader(GL_FRAGMENT_SHADER); // Fan7
    unsigned int fragmentShader20 = glCreateShader(GL_FRAGMENT_SHADER); // Fan8
    unsigned int fragmentShader21 = glCreateShader(GL_FRAGMENT_SHADER); // Fan9
    unsigned int fragmentShader22 = glCreateShader(GL_FRAGMENT_SHADER); // Fan10
    unsigned int fragmentShader23 = glCreateShader(GL_FRAGMENT_SHADER); // Fan11
    unsigned int fragmentShader24 = glCreateShader(GL_FRAGMENT_SHADER); // Fan12
    unsigned int fragmentShader25 = glCreateShader(GL_FRAGMENT_SHADER); // Fan13
    unsigned int fragmentShader26 = glCreateShader(GL_FRAGMENT_SHADER); // Fan14
    unsigned int fragmentShader27 = glCreateShader(GL_FRAGMENT_SHADER); // Fan15
    unsigned int fragmentShader28 = glCreateShader(GL_FRAGMENT_SHADER); // Fan16
    unsigned int fragmentShader29 = glCreateShader(GL_FRAGMENT_SHADER); // Circ1
    unsigned int fragmentShader30 = glCreateShader(GL_FRAGMENT_SHADER); // Circ2
    unsigned int fragmentShader31 = glCreateShader(GL_FRAGMENT_SHADER); // Circ3
    unsigned int fragmentShader32 = glCreateShader(GL_FRAGMENT_SHADER); // Circ4
    unsigned int fragmentShader33 = glCreateShader(GL_FRAGMENT_SHADER); // Circ5
    unsigned int fragmentShader34 = glCreateShader(GL_FRAGMENT_SHADER); // Circ6
    unsigned int fragmentShader35 = glCreateShader(GL_FRAGMENT_SHADER); // Circ7
    unsigned int fragmentShader36 = glCreateShader(GL_FRAGMENT_SHADER); // Circ8
    unsigned int fragmentShader37 = glCreateShader(GL_FRAGMENT_SHADER); // Circ9
    unsigned int fragmentShader38 = glCreateShader(GL_FRAGMENT_SHADER); // Circ10
    unsigned int fragmentShader39 = glCreateShader(GL_FRAGMENT_SHADER); // Circ11
    unsigned int fragmentShader40 = glCreateShader(GL_FRAGMENT_SHADER); // Circ12
    unsigned int fragmentShader41 = glCreateShader(GL_FRAGMENT_SHADER); // Circ13
    unsigned int fragmentShader42 = glCreateShader(GL_FRAGMENT_SHADER); // Circ14
    unsigned int fragmentShader43 = glCreateShader(GL_FRAGMENT_SHADER); // Circ15
    unsigned int fragmentShader44 = glCreateShader(GL_FRAGMENT_SHADER); // Circ16

    unsigned int shaderProgram1 = glCreateProgram();
    unsigned int shaderProgram2 = glCreateProgram();
    unsigned int shaderProgram3 = glCreateProgram();
    unsigned int shaderProgram4 = glCreateProgram();
    unsigned int shaderProgram5 = glCreateProgram();
    unsigned int shaderProgram6 = glCreateProgram();
    unsigned int shaderProgram7 = glCreateProgram();
    unsigned int shaderProgram8 = glCreateProgram();
    unsigned int shaderProgram9 = glCreateProgram(); // Poly
    unsigned int shaderProgram10 = glCreateProgram(); // Cuad1
    unsigned int shaderProgram11 = glCreateProgram(); // Cuad2
    //unsigned int shaderProgram12 = glCreateProgram(); // Cuad3
    unsigned int shaderProgram13 = glCreateProgram(); // Fan1
    unsigned int shaderProgram14 = glCreateProgram(); // Fan2
    unsigned int shaderProgram15 = glCreateProgram(); // Fan3
    unsigned int shaderProgram16 = glCreateProgram(); // Fan4
    unsigned int shaderProgram17 = glCreateProgram(); // Fan5
    unsigned int shaderProgram18 = glCreateProgram(); // Fan6
    unsigned int shaderProgram19 = glCreateProgram(); // Fan7
    unsigned int shaderProgram20 = glCreateProgram(); // Fan8
    unsigned int shaderProgram21 = glCreateProgram(); // Fan9
    unsigned int shaderProgram22 = glCreateProgram(); // Fan10
    unsigned int shaderProgram23 = glCreateProgram(); // Fan11
    unsigned int shaderProgram24 = glCreateProgram(); // Fan12
    unsigned int shaderProgram25 = glCreateProgram(); // Fan13
    unsigned int shaderProgram26 = glCreateProgram(); // Fan14
    unsigned int shaderProgram27 = glCreateProgram(); // Fan15
    unsigned int shaderProgram28 = glCreateProgram(); // Fan16
    unsigned int shaderProgram29 = glCreateProgram(); // Circ1
    unsigned int shaderProgram30 = glCreateProgram(); // Circ2
    unsigned int shaderProgram31 = glCreateProgram(); // Circ3
    unsigned int shaderProgram32 = glCreateProgram(); // Circ4
    unsigned int shaderProgram33 = glCreateProgram(); // Circ5
    unsigned int shaderProgram34 = glCreateProgram(); // Circ6
    unsigned int shaderProgram35 = glCreateProgram(); // Circ7
    unsigned int shaderProgram36 = glCreateProgram(); // Circ8
    unsigned int shaderProgram37 = glCreateProgram(); // Circ9
    unsigned int shaderProgram38 = glCreateProgram(); // Circ10
    unsigned int shaderProgram39 = glCreateProgram(); // Circ11
    unsigned int shaderProgram40 = glCreateProgram(); // Circ12
    unsigned int shaderProgram41 = glCreateProgram(); // Circ13
    unsigned int shaderProgram42 = glCreateProgram(); // Circ14
    unsigned int shaderProgram43 = glCreateProgram(); // Circ15
    unsigned int shaderProgram44 = glCreateProgram(); // Circ16

    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glShaderSource(fragmentShader1, 1, &fragmentShader1Source, NULL);
    glCompileShader(fragmentShader1);
    glShaderSource(fragmentShader2, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShader2);
    glShaderSource(fragmentShader3, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShader3);
    glShaderSource(fragmentShader4, 1, &fragmentShader1Source, NULL);
    glCompileShader(fragmentShader4);
    glShaderSource(fragmentShader5, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShader5);
    glShaderSource(fragmentShader6, 1, &fragmentShader1Source, NULL);
    glCompileShader(fragmentShader6);
    glShaderSource(fragmentShader7, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShader7);
    glShaderSource(fragmentShader8, 1, &fragmentShader1Source, NULL);
    glCompileShader(fragmentShader8);

    //Poly
    glShaderSource(fragmentShader9, 1, &fragmentShader3Source, NULL);
    glCompileShader(fragmentShader9);
    //Cuad1
    glShaderSource(fragmentShader10, 1, &fragmentShader4Source, NULL);
    glCompileShader(fragmentShader10);
    //Cuad2
    glShaderSource(fragmentShader11, 1, &fragmentShader4Source, NULL);
    glCompileShader(fragmentShader11);
    //Cuad3
    /*glShaderSource(fragmentShader12, 1, &fragmentShader5Source, NULL);
    glCompileShader(fragmentShader12);*/
    //Fan1
    glShaderSource(fragmentShader13, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader13);
    //Fan2
    glShaderSource(fragmentShader14, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader14);
    //Fan3
    glShaderSource(fragmentShader15, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader15);
    //Fan4
    glShaderSource(fragmentShader16, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader16);
    //Fan5
    glShaderSource(fragmentShader17, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader17);
    //Fan6
    glShaderSource(fragmentShader18, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader18);
    //Fan7
    glShaderSource(fragmentShader19, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader19);
    //Fan8
    glShaderSource(fragmentShader20, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader20);
    //Fan9
    glShaderSource(fragmentShader21, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader21);
    //Fan10
    glShaderSource(fragmentShader22, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader22);
    //Fan11
    glShaderSource(fragmentShader23, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader23);
    //Fan12
    glShaderSource(fragmentShader24, 1, &fragmentShader6Source, NULL);
    glCompileShader(fragmentShader24);
    //Fan13
    glShaderSource(fragmentShader25, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader25);
    //Fan14
    glShaderSource(fragmentShader26, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader26);
    //Fan15
    glShaderSource(fragmentShader27, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader27);
    //Fan16
    glShaderSource(fragmentShader28, 1, &fragmentShader7Source, NULL);
    glCompileShader(fragmentShader28);
    //Circ1
    glShaderSource(fragmentShader29, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader29);
    //Circ2
    glShaderSource(fragmentShader30, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader30);
    //Circ3
    glShaderSource(fragmentShader31, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader31);
    //Circ4
    glShaderSource(fragmentShader32, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader32);
    //Circ5
    glShaderSource(fragmentShader33, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader33);
    //Circ6
    glShaderSource(fragmentShader34, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader34);
    //Circ7
    glShaderSource(fragmentShader35, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader35);
    //Circ8
    glShaderSource(fragmentShader36, 1, &fragmentShader8Source, NULL);
    glCompileShader(fragmentShader36);
    //Circ9 <----Segundos grupo de semicirculos
    glShaderSource(fragmentShader37, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader37);
    //Circ10
    glShaderSource(fragmentShader38, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader38);
    //Circ11
    glShaderSource(fragmentShader39, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader39);
    //Circ12
    glShaderSource(fragmentShader40, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader40);
    //Circ13
    glShaderSource(fragmentShader41, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader41);
    //Circ14
    glShaderSource(fragmentShader42, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader42);
    //Circ15
    glShaderSource(fragmentShader43, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader43);
    //Circ16
    glShaderSource(fragmentShader44, 1, &fragmentShader9Source, NULL);
    glCompileShader(fragmentShader44);

    // Link de los objetos
    glAttachShader(shaderProgram1, vertexShader);
    glAttachShader(shaderProgram1, fragmentShader1);
    glLinkProgram(shaderProgram1);

    glAttachShader(shaderProgram2, vertexShader);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);

    glAttachShader(shaderProgram3, vertexShader);
    glAttachShader(shaderProgram3, fragmentShader3);
    glLinkProgram(shaderProgram3);

    glAttachShader(shaderProgram4, vertexShader);
    glAttachShader(shaderProgram4, fragmentShader4);
    glLinkProgram(shaderProgram4);

    glAttachShader(shaderProgram5, vertexShader);
    glAttachShader(shaderProgram5, fragmentShader5);
    glLinkProgram(shaderProgram5);

    glAttachShader(shaderProgram6, vertexShader);
    glAttachShader(shaderProgram6, fragmentShader6);
    glLinkProgram(shaderProgram6);

    glAttachShader(shaderProgram7, vertexShader);
    glAttachShader(shaderProgram7, fragmentShader7);
    glLinkProgram(shaderProgram7);

    glAttachShader(shaderProgram8, vertexShader);
    glAttachShader(shaderProgram8, fragmentShader8);
    glLinkProgram(shaderProgram8);

    //Poly
    glAttachShader(shaderProgram9, vertexShader);
    glAttachShader(shaderProgram9, fragmentShader9);
    glLinkProgram(shaderProgram9);
    //Cuad1
    glAttachShader(shaderProgram10, vertexShader);
    glAttachShader(shaderProgram10, fragmentShader10);
    glLinkProgram(shaderProgram10);
    //Cuad2
    glAttachShader(shaderProgram11, vertexShader);
    glAttachShader(shaderProgram11, fragmentShader11);
    glLinkProgram(shaderProgram11);
    //Cuad3
    //glAttachShader(shaderProgram12, vertexShader);
    //glAttachShader(shaderProgram12, fragmentShader12);
    //glLinkProgram(shaderProgram12);
    //Fan1
    glAttachShader(shaderProgram13, vertexShader);
    glAttachShader(shaderProgram13, fragmentShader13);
    glLinkProgram(shaderProgram13);
    //Fan2
    glAttachShader(shaderProgram14, vertexShader);
    glAttachShader(shaderProgram14, fragmentShader14);
    glLinkProgram(shaderProgram14);
    //Fan3
    glAttachShader(shaderProgram15, vertexShader);
    glAttachShader(shaderProgram15, fragmentShader15);
    glLinkProgram(shaderProgram15);
    //Fan4
    glAttachShader(shaderProgram16, vertexShader);
    glAttachShader(shaderProgram16, fragmentShader16);
    glLinkProgram(shaderProgram16);
    //Fan5
    glAttachShader(shaderProgram17, vertexShader);
    glAttachShader(shaderProgram17, fragmentShader17);
    glLinkProgram(shaderProgram17);
    //Fan6
    glAttachShader(shaderProgram18, vertexShader);
    glAttachShader(shaderProgram18, fragmentShader18);
    glLinkProgram(shaderProgram18);
    //Fan7
    glAttachShader(shaderProgram19, vertexShader);
    glAttachShader(shaderProgram19, fragmentShader19);
    glLinkProgram(shaderProgram19);
    //Fan8
    glAttachShader(shaderProgram20, vertexShader);
    glAttachShader(shaderProgram20, fragmentShader20);
    glLinkProgram(shaderProgram20);
    //Fan9
    glAttachShader(shaderProgram21, vertexShader);
    glAttachShader(shaderProgram21, fragmentShader21);
    glLinkProgram(shaderProgram21);
    //Fan10
    glAttachShader(shaderProgram22, vertexShader);
    glAttachShader(shaderProgram22, fragmentShader22);
    glLinkProgram(shaderProgram22);
    //Fan11
    glAttachShader(shaderProgram23, vertexShader);
    glAttachShader(shaderProgram23, fragmentShader23);
    glLinkProgram(shaderProgram23);
    //Fan12
    glAttachShader(shaderProgram24, vertexShader);
    glAttachShader(shaderProgram24, fragmentShader24);
    glLinkProgram(shaderProgram24);
    //Fan13
    glAttachShader(shaderProgram25, vertexShader);
    glAttachShader(shaderProgram25, fragmentShader25);
    glLinkProgram(shaderProgram25);
    //Fan14
    glAttachShader(shaderProgram26, vertexShader);
    glAttachShader(shaderProgram26, fragmentShader26);
    glLinkProgram(shaderProgram26);
    //Fan15
    glAttachShader(shaderProgram27, vertexShader);
    glAttachShader(shaderProgram27, fragmentShader27);
    glLinkProgram(shaderProgram27);
    //Fan16
    glAttachShader(shaderProgram28, vertexShader);
    glAttachShader(shaderProgram28, fragmentShader28);
    glLinkProgram(shaderProgram28);
    //Circ1
    glAttachShader(shaderProgram29, vertexShader);
    glAttachShader(shaderProgram29, fragmentShader29);
    glLinkProgram(shaderProgram29);
    //Circ2
    glAttachShader(shaderProgram30, vertexShader);
    glAttachShader(shaderProgram30, fragmentShader30);
    glLinkProgram(shaderProgram30);
    //Circ3
    glAttachShader(shaderProgram31, vertexShader);
    glAttachShader(shaderProgram31, fragmentShader31);
    glLinkProgram(shaderProgram31);
    //Circ4
    glAttachShader(shaderProgram32, vertexShader);
    glAttachShader(shaderProgram32, fragmentShader32);
    glLinkProgram(shaderProgram32);
    //Circ5
    glAttachShader(shaderProgram33, vertexShader);
    glAttachShader(shaderProgram33, fragmentShader33);
    glLinkProgram(shaderProgram33);
    //Circ6
    glAttachShader(shaderProgram34, vertexShader);
    glAttachShader(shaderProgram34, fragmentShader34);
    glLinkProgram(shaderProgram34);
    //Circ7
    glAttachShader(shaderProgram35, vertexShader);
    glAttachShader(shaderProgram35, fragmentShader35);
    glLinkProgram(shaderProgram35);
    //Circ8
    glAttachShader(shaderProgram36, vertexShader);
    glAttachShader(shaderProgram36, fragmentShader36);
    glLinkProgram(shaderProgram36);
    //Circ9
    glAttachShader(shaderProgram37, vertexShader);
    glAttachShader(shaderProgram37, fragmentShader37);
    glLinkProgram(shaderProgram37);
    //Circ10
    glAttachShader(shaderProgram38, vertexShader);
    glAttachShader(shaderProgram38, fragmentShader38);
    glLinkProgram(shaderProgram38);
    //Circ11
    glAttachShader(shaderProgram39, vertexShader);
    glAttachShader(shaderProgram39, fragmentShader39);
    glLinkProgram(shaderProgram39);
    //Circ12
    glAttachShader(shaderProgram40, vertexShader);
    glAttachShader(shaderProgram40, fragmentShader40);
    glLinkProgram(shaderProgram40);
    //Circ13
    glAttachShader(shaderProgram41, vertexShader);
    glAttachShader(shaderProgram41, fragmentShader41);
    glLinkProgram(shaderProgram41);
    //Circ14
    glAttachShader(shaderProgram42, vertexShader);
    glAttachShader(shaderProgram42, fragmentShader42);
    glLinkProgram(shaderProgram42);
    //Circ15
    glAttachShader(shaderProgram43, vertexShader);
    glAttachShader(shaderProgram43, fragmentShader43);
    glLinkProgram(shaderProgram43);
    //Circ16
    glAttachShader(shaderProgram44, vertexShader);
    glAttachShader(shaderProgram44, fragmentShader44);
    glLinkProgram(shaderProgram44);

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    // Triangulos de las esquinas
    float Tri1[] = {
        -1.0f, 1.0f, 0.0f, //esquina
        -0.7f, 1.0f, 0.0f, //up
        -0.7f, 0.7f, 0.0f //down
    };
    float Tri2[] = {
        -1.0f, 1.0f, 0.0f, //esquina
        -1.0f, 0.7f, 0.0f, //left
        -0.7f, 0.7f, 0.0f  //right
    };
    float Tri3[] = {
        1.0f, 1.0f, 0.0f, //esquina
        0.7f, 1.0f, 0.0f, //up
        0.7f, 0.7f, 0.0f //down
    };
    float Tri4[] = {
        1.0f, 1.0f, 0.0f, //esquina
        1.0f, 0.7f, 0.0f, //right
        0.7f, 0.7f, 0.0f  //left
    };
    float Tri5[] = {
        1.0f, -1.0f, 0.0f, //esquina
        1.0f, -0.7f, 0.0f, //right
        0.7f, -0.7f, 0.0f //left
    };
    float Tri6[] = {
        1.0f, -1.0f, 0.0f, //esquina
        0.7f, -1.0f, 0.0f, //down
        0.7f, -0.7f, 0.0f //up
    };
    float Tri7[] = {
        -1.0f, -1.0f, 0.0f, //esquina
        -0.7f, -1.0f, 0.0f, //down
        -0.7f, -0.7f, 0.0f //up
    };
    float Tri8[] = {
        -1.0f, -1.0f, 0.0f, //esquina
        -1.0f, -0.7f, 0.0f, //right
        -0.7f, -0.7f, 0.0f //left
    };
    //Poligono central 
    float Poly[] = {
        0.0f, 1.0f, 0.0f, //up
        0.7f, 0.7f, 0.0f, //esqC2
        1.0f, 0.0f, 0.0f, //right
        0.7f, -0.7f, 0.0f, //esqC3
        0.0f, -1.0f, 0.0f, //down
        -0.7f, -0.7f, 0.0f, //esqC4
        -1.0f, 0.0f, 0.0f, //left
        -0.7f, 0.7f, 0.0f //esqC1
    };
    unsigned int indicespoly[] = {
        0, 1, 4,  // triangulo 1
        1, 5, 2,  // triangulo 2
        2, 6, 3,  // triangulo 3 
        3, 7, 4,  // triangulo 4
        4, 0, 5,  // triangulo 5
        5, 1, 6,  // triangulo 6
        6, 2, 7,  // triangulo 7
        7, 3, 0  // triangulo 8
    };
    //Cuadrados en forma de cruz centrales
    float Cuad1[] = {
        -0.35f, 0.7f, 0.0f,  //esq1
        0.35f, 0.7, 0.0f,  //esq2
        0.35f, -0.7, 0.0f,  //esq3
        -0.35f, -0.7, 0.0f  //esq4
    };
    unsigned int indicescuad1[] = {
        0, 1, 3,  // triangulo 1
        1, 2, 3  // triangulo 2
    };
    float Cuad2[] = {
        -0.7f, 0.35f, 0.0f,  //esq1
        0.7f, 0.35, 0.0f,  //esq2
        0.7f, -0.35, 0.0f,  //esq3
        -0.7f, -0.35, 0.0f  //esq4
    };
    unsigned int indicescuad2[] = {
        0, 1, 3,  // triangulo 1
        1, 2, 3  // triangulo 2
    };
    // Para las hojas las voy a hacer con fans (aban?cos) para darles la curvatura = forma de hoja
    float Fan1[] = {
        -0.35f, 0.35f, 0.0f,  //centro de fan1
        -0.7f, 0.7f, 0.0f,  //esq
        -0.68f, 0.5f, 0.0f,
        -0.65f, 0.4f, 0.0f,
        -0.6f, 0.3f, 0.0f,
        -0.5f, 0.2f, 0.0f,
        -0.35f, 0.1f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan2[] = {
        0.35f, 0.35f, 0.0f,  //centro de fan2
        0.7f, 0.7f, 0.0f,  //esq
        0.68f, 0.5f, 0.0f,
        0.65f, 0.4f, 0.0f,
        0.6f, 0.3f, 0.0f,
        0.5f, 0.2f, 0.0f,
        0.35f, 0.1f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan3[] = {
        0.35f, -0.35f, 0.0f,  //centro de fan3
        0.7f, -0.7f, 0.0f,  //esq
        0.68f, -0.5f, 0.0f,
        0.65f, -0.4f, 0.0f,
        0.6f, -0.3f, 0.0f,
        0.5f, -0.2f, 0.0f,
        0.35f, -0.1f, 0.0f,
        0.0f, -0.0f, 0.0f  //centro
    };
    float Fan4[] = {
        -0.35f, -0.35f, 0.0f,  //centro de fan4
        -0.7f, -0.7f, 0.0f,  //esq
        -0.68f, -0.5f, 0.0f,
        -0.65f, -0.4f, 0.0f,
        -0.6f, -0.3f, 0.0f,
        -0.5f, -0.2f, 0.0f,
        -0.35f, -0.1f, 0.0f,
        -0.0f, -0.0f, 0.0f  //centro
    };
    float Fan5[] = {
        0.35f, -0.35f, 0.0f,  //centro de fan5
        0.7f, -0.7f, 0.0f,  //esq
        0.5f, -0.68f, 0.0f,
        0.4f, -0.65f, 0.0f,
        0.3f, -0.6f, 0.0f,
        0.2f, -0.5f, 0.0f,
        0.1f, -0.35f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan6[] = {
        0.35f, 0.35f, 0.0f,  //centro de fan6
        0.7f, 0.7f, 0.0f,  //esq
        0.5f, 0.68f, 0.0f,
        0.4f, 0.65f, 0.0f,
        0.3f, 0.6f, 0.0f,
        0.2f, 0.5f, 0.0f,
        0.1f, 0.35f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan7[] = {
        -0.35f, 0.35f, 0.0f,  //centro de fan3
        -0.7f, 0.7f, 0.0f,  //esq
        -0.5f, 0.68f, 0.0f,
        -0.4f, 0.65f, 0.0f,
        -0.3f, 0.6f, 0.0f,
        -0.2f, 0.5f, 0.0f,
        -0.1f, 0.35f, 0.0f,
        0.0f, -0.0f, 0.0f  //centro
    };
    float Fan8[] = {
        -0.35f, -0.35f, 0.0f,  //centro de fan8
        -0.7f, -0.7f, 0.0f,  //esq
        -0.5f, -0.68f, 0.0f,
        -0.4f, -0.65f, 0.0f,
        -0.3f, -0.6f, 0.0f,
        -0.2f, -0.5f, 0.0f,
        -0.1f, -0.35f, 0.0f,
        -0.0f, -0.0f, 0.0f  //centro
    };
    float Fan9[] = {
        0.0f, 0.5f, 0.0f,  //centro de fan9
        0.0f, 1.0f, 0.0f,  //esq
        -0.16f, 0.8f, 0.0f,
        -0.18f, 0.75f, 0.0f,
        -0.2f, 0.6f, 0.0f,
        -0.17f, 0.4f, 0.0f,
        -0.15f, 0.3f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan10[] = {
        0.0f, -0.5f, 0.0f,  //centro de fan10
        0.0f, -1.0f, 0.0f,  //esq
        0.16f, -0.8f, 0.0f,
        0.18f, -0.75f, 0.0f,
        0.2f, -0.6f, 0.0f,
        0.17f, -0.4f, 0.0f,
        0.15f, -0.3f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan11[] = {
        0.5f, 0.0f, 0.0f,  //centro de fan11
        1.0f, 0.0f, 0.0f,  //esq
        0.8f, 0.16f, 0.0f,
        0.75f, 0.18f, 0.0f,
        0.6f, 0.2f, 0.0f,
        0.4f, 0.17f, 0.0f,
        0.3f, 0.15f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan12[] = {
        -0.5f, 0.0f, 0.0f,  //centro de fan12
        -1.0f, 0.0f, 0.0f,  //esq
        -0.8f, -0.16f, 0.0f,
        -0.75f, -0.18f, 0.0f,
        -0.6f, -0.2f, 0.0f,
        -0.4f, -0.17f, 0.0f,
        -0.3f, -0.15f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan13[] = {
        0.0f, 0.5f, 0.0f,  //centro de fan13
        0.0f, 1.0f, 0.0f,  //esq
        0.16f, 0.8f, 0.0f,
        0.18f, 0.75f, 0.0f,
        0.2f, 0.6f, 0.0f,
        0.17f, 0.4f, 0.0f,
        0.15f, 0.3f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan14[] = {
        0.5f, 0.0f, 0.0f,  //centro de fan14
        1.0f, 0.0f, 0.0f,  //esq
        0.8f, -0.16f, 0.0f,
        0.75f, -0.18f, 0.0f,
        0.6f, -0.2f, 0.0f,
        0.4f, -0.17f, 0.0f,
        0.3f, -0.15f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan15[] = {
        0.0f, -0.5f, 0.0f,  //centro de fan15
        0.0f, -1.0f, 0.0f,  //esq
        -0.16f, -0.8f, 0.0f,
        -0.18f, -0.75f, 0.0f,
        -0.2f, -0.6f, 0.0f,
        -0.17f, -0.4f, 0.0f,
        -0.15f, -0.3f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    float Fan16[] = {
        -0.5f, 0.0f, 0.0f,  //centro de fan16
        -1.0f, 0.0f, 0.0f,  //esq
        -0.8f, 0.16f, 0.0f,
        -0.75f, 0.18f, 0.0f,
        -0.6f, 0.2f, 0.0f,
        -0.4f, 0.17f, 0.0f,
        -0.3f, 0.15f, 0.0f,
        0.0f, 0.0f, 0.0f  //centro
    };
    // Antes se usaba para generar un cuadrado negro en el centro siguiendo la pieza de arte tal cual
    //float Cuad3[] = {
    //    -0.3f, 0.3f, 0.0f,  //esq1
    //    0.3f, 0.3f, 0.0f,  //esq2
    //    0.3f, -0.3f, 0.0f,  //esq3
    //    -0.3f, -0.3f, 0.0f  //esq4
    //};
    //unsigned int indicescuad3[] = {
    //    0, 1, 3,  // triangulo 1
    //    1, 2, 3  // triangulo 2
    //};
    float Cuad3[] = {
        // positions          // colors           // texture coords
         0.3f,  0.3f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.3f, -0.3f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.3f, -0.3f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.3f,  0.3f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };
    unsigned int indicescuad3[] = {
        0, 1, 3,  // triangulo 1
        1, 2, 3  // triangulo 2
    };
    //Los distintos circulos centrales, aunque me refiera a los vectores como "Circ" cada vector representa un semicirculo
    float Circ1[] = {
        0.2f, 0.2f, 0.0f, //centro de fan 
        0.1f, 0.1f, 0.0f,
        0.067f, 0.15f, 0.0f,
        0.06f, 0.2f, 0.0f,
        0.067f, 0.25f, 0.0f,
        0.1f, 0.3f, 0.0f,
        0.15f, 0.332f, 0.0f,
        0.2f, 0.341f, 0.0f,
        0.25f, 0.332f, 0.0f,
        0.3f, 0.3f, 0.0f
    };
    float Circ2[] = {
        0.2f, 0.2f, 0.0f, //centro de fan 
        0.1f, 0.1f, 0.0f,
        0.15f, 0.067f, 0.0f,
        0.2f, 0.06f, 0.0f,
        0.25f, 0.067f, 0.0f,
        0.3f, 0.1f, 0.0f,
        0.332f, 0.15f, 0.0f,
        0.341f, 0.2f, 0.0f,
        0.332f, 0.25f, 0.0f,
        0.3f, 0.3f, 0.0f
    };
    float Circ3[] = {
        0.2f, -0.2f, 0.0f, //centro de fan 
        0.1f, -0.1f, 0.0f,
        0.067f, -0.15f, 0.0f,
        0.06f, -0.2f, 0.0f,
        0.067f, -0.25f, 0.0f,
        0.1f, -0.3f, 0.0f,
        0.15f, -0.332f, 0.0f,
        0.2f, -0.341f, 0.0f,
        0.25f, -0.332f, 0.0f,
        0.3f, -0.3f, 0.0f
    };
    float Circ4[] = {
        0.2f, -0.2f, 0.0f, //centro de fan 
        0.1f, -0.1f, 0.0f,
        0.15f, -0.067f, 0.0f,
        0.2f, -0.06f, 0.0f,
        0.25f, -0.067f, 0.0f,
        0.3f, -0.1f, 0.0f,
        0.332f, -0.15f, 0.0f,
        0.341f, -0.2f, 0.0f,
        0.332f, -0.25f, 0.0f,
        0.3f, -0.3f, 0.0f
    };
    float Circ5[] = {
        -0.2f, -0.2f, 0.0f, //centro de fan 
        -0.1f, -0.1f, 0.0f,
        -0.067f, -0.15f, 0.0f,
        -0.06f, -0.2f, 0.0f,
        -0.067f, -0.25f, 0.0f,
        -0.1f, -0.3f, 0.0f,
        -0.15f, -0.332f, 0.0f,
        -0.2f, -0.341f, 0.0f,
        -0.25f, -0.332f, 0.0f,
        -0.3f, -0.3f, 0.0f
    };
    float Circ6[] = {
        -0.2f, -0.2f, 0.0f, //centro de fan 
        -0.1f, -0.1f, 0.0f,
        -0.15f, -0.067f, 0.0f,
        -0.2f, -0.06f, 0.0f,
        -0.25f, -0.067f, 0.0f,
        -0.3f, -0.1f, 0.0f,
        -0.332f, -0.15f, 0.0f,
        -0.341f, -0.2f, 0.0f,
        -0.332f, -0.25f, 0.0f,
        -0.3f, -0.3f, 0.0f
    };
    float Circ7[] = {
        -0.2f, 0.2f, 0.0f, //centro de fan 
        -0.1f, 0.1f, 0.0f,
        -0.067f, 0.15f, 0.0f,
        -0.06f, 0.2f, 0.0f,
        -0.067f, 0.25f, 0.0f,
        -0.1f, 0.3f, 0.0f,
        -0.15f, 0.332f, 0.0f,
        -0.2f, 0.341f, 0.0f,
        -0.25f, 0.332f, 0.0f,
        -0.3f, 0.3f, 0.0f
    };
    float Circ8[] = {
        -0.2f, 0.2f, 0.0f, //centro de fan 
        -0.1f, 0.1f, 0.0f,
        -0.15f, 0.067f, 0.0f,
        -0.2f, 0.06f, 0.0f,
        -0.25f, 0.067f, 0.0f,
        -0.3f, 0.1f, 0.0f,
        -0.332f, 0.15f, 0.0f,
        -0.341f, 0.2f, 0.0f,
        -0.332f, 0.25f, 0.0f,
        -0.3f, 0.3f, 0.0f
    };
    float Circ9[] = { // Del Circ2 se realiza la tranformaci?n (X-0.2, Y+0.2) del centro 
        0.0f, 0.4f, 0.0f, //centro de fan 
        0.0f, 0.26f, 0.0f,
        0.05f, 0.267f, 0.0f,
        0.1f, 0.3f, 0.0f,
        0.132f, 0.35f, 0.0f,
        0.141f, 0.4f, 0.0f,
        0.132f, 0.45f, 0.0f,
        0.1f, 0.5f, 0.0f,
        0.05f, 0.533f, 0.0f,
        0.0f, 0.54f, 0.0f
    };
    float Circ10[] = {
        0.0f, 0.4f, 0.0f, //centro de fan 
        0.0f, 0.26f, 0.0f,
        -0.05f, 0.267f, 0.0f,
        -0.1f, 0.3f, 0.0f,
        -0.132f, 0.35f, 0.0f,
        -0.141f, 0.4f, 0.0f,
        -0.132f, 0.45f, 0.0f,
        -0.1f, 0.5f, 0.0f,
        -0.05f, 0.533f, 0.0f,
        0.0f, 0.54f, 0.0f
    };
    float Circ11[] = {
        0.4f, 0.0f, 0.0f, //centro de fan 
        0.26f, 0.0f, 0.0f,
        0.267f, 0.05f, 0.0f,
        0.3f, 0.1f, 0.0f,
        0.35f, 0.132f, 0.0f,
        0.4f, 0.141f, 0.0f,
        0.45f, 0.132f, 0.0f,
        0.5f, 0.1f, 0.0f,
        0.533f, 0.05f, 0.0f,
        0.54f, 0.0f, 0.0f
    };
    float Circ12[] = {
        0.4f, 0.0f, 0.0f, //centro de fan 
        0.26f, 0.0f, 0.0f,
        0.267f, -0.05f, 0.0f,
        0.3f, -0.1f, 0.0f,
        0.35f, -0.132f, 0.0f,
        0.4f, -0.141f, 0.0f,
        0.45f, -0.132f, 0.0f,
        0.5f, -0.1f, 0.0f,
        0.533f, -0.05f, 0.0f,
        0.54f, 0.0f, 0.0f
    };
    float Circ13[] = { //
        0.0f, -0.4f, 0.0f, //centro de fan 
        0.0f, -0.26f, 0.0f,
        -0.05f, -0.267f, 0.0f,
        -0.1f, -0.3f, 0.0f,
        -0.132f, -0.35f, 0.0f,
        -0.141f, -0.4f, 0.0f,
        -0.132f, -0.45f, 0.0f,
        -0.1f, -0.5f, 0.0f,
        -0.05f, -0.533f, 0.0f,
        -0.0f, -0.54f, 0.0f
    };
    float Circ14[] = {
        0.0f, -0.4f, 0.0f, //centro de fan 
        0.0f, -0.26f, 0.0f,
        0.05f, -0.267f, 0.0f,
        0.1f, -0.3f, 0.0f,
        0.132f, -0.35f, 0.0f,
        0.141f, -0.4f, 0.0f,
        0.132f, -0.45f, 0.0f,
        0.1f, -0.5f, 0.0f,
        0.05f, -0.533f, 0.0f,
        0.0f, -0.54f, 0.0f
    };
    float Circ15[] = {
        -0.4f, 0.0f, 0.0f, //centro de fan 
        -0.26f, 0.0f, 0.0f,
        -0.267f, -0.05f, 0.0f,
        -0.3f, -0.1f, 0.0f,
        -0.35f, -0.132f, 0.0f,
        -0.4f, -0.141f, 0.0f,
        -0.45f, -0.132f, 0.0f,
        -0.5f, -0.1f, 0.0f,
        -0.533f, -0.05f, 0.0f,
        -0.54f, 0.0f, 0.0f
    };
    float Circ16[] = {
        -0.4f, 0.0f, 0.0f, //centro de fan 
        -0.26f, 0.0f, 0.0f,
        -0.267f, 0.05f, 0.0f,
        -0.3f, 0.1f, 0.0f,
        -0.35f, 0.132f, 0.0f,
        -0.4f, 0.141f, 0.0f,
        -0.45f, 0.132f, 0.0f,
        -0.5f, 0.1f, 0.0f,
        -0.533f, 0.05f, 0.0f,
        -0.54f, 0.0f, 0.0f
    };

    unsigned int VBOs[100], VAOs[100], EBO[100];
    glGenVertexArrays(100, VAOs); // we can also generate multiple VAOs or buffers at the same time
    glGenBuffers(100, VBOs);
    glGenBuffers(100, EBO);
    // first triangle setup
    // --------------------
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri1), Tri1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	// Vertex attributes stay the same
    glEnableVertexAttribArray(0);
    // glBindVertexArray(0); // no need to unbind at all as we directly bind a different VAO the next few lines
    // second triangle setup
    // ---------------------
    glBindVertexArray(VAOs[1]);	// note that we bind to a different VAO now
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	// and a different VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri2), Tri2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
    glEnableVertexAttribArray(0);
    // glBindVertexArray(0); // not really necessary as well, but beware of calls that could affect VAOs while this one is bound (like binding element buffer objects, or enabling/disabling vertex attributes)

    glBindVertexArray(VAOs[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri3), Tri3, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[3]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri4), Tri4, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[4]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri5), Tri5, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[5]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[5]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri6), Tri6, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[6]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[6]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri7), Tri7, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAOs[7]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[7]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Tri8), Tri8, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Poly
    glBindVertexArray(VAOs[8]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[8]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Poly), Poly, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicespoly), indicespoly, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Cuad1
    glBindVertexArray(VAOs[9]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[9]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Cuad1), Cuad1, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicescuad1), indicescuad1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Cuad2
    glBindVertexArray(VAOs[10]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[10]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Cuad2), Cuad2, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicescuad2), indicescuad2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Cuad3 - negro
    glBindVertexArray(VAOs[11]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[11]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Cuad3), Cuad3, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicescuad3), indicescuad3, GL_STATIC_DRAW);
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    // load and create a texture 
    // -------------------------
    unsigned int texture;
    // texture
    // ---------
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.

    // The FileSystem::getPath(...)
    unsigned char* data = stbi_load("C:/Users/axelg/Documents/AXEL/ITAM/Graficas/Images/portal.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    ourShader.use(); // don't forget to activate/use the shader before setting uniforms!
    // either set it manually like so:
    glUniform1i(glGetUniformLocation(ourShader.ID, "texture"), 1);

    // Fan1
    glBindVertexArray(VAOs[12]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[12]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan1), Fan1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan2
    glBindVertexArray(VAOs[13]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[13]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan2), Fan2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan3
    glBindVertexArray(VAOs[14]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[14]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan3), Fan3, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan4
    glBindVertexArray(VAOs[15]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[15]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan4), Fan4, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan5
    glBindVertexArray(VAOs[16]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[16]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan5), Fan5, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan6
    glBindVertexArray(VAOs[17]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[17]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan6), Fan6, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan7
    glBindVertexArray(VAOs[18]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[18]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan7), Fan7, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan8
    glBindVertexArray(VAOs[19]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[19]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan8), Fan8, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan9
    glBindVertexArray(VAOs[20]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[20]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan9), Fan9, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan10
    glBindVertexArray(VAOs[21]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[21]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan10), Fan10, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan11
    glBindVertexArray(VAOs[22]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[22]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan11), Fan11, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan12
    glBindVertexArray(VAOs[23]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[23]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan12), Fan12, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan13
    glBindVertexArray(VAOs[24]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[24]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan13), Fan13, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan14
    glBindVertexArray(VAOs[25]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[25]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan14), Fan14, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan15
    glBindVertexArray(VAOs[26]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[26]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan15), Fan15, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Fan16
    glBindVertexArray(VAOs[27]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[27]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Fan16), Fan16, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ1
    glBindVertexArray(VAOs[28]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[28]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ1), Circ1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ2
    glBindVertexArray(VAOs[29]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[29]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ2), Circ2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ3
    glBindVertexArray(VAOs[30]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[30]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ3), Circ3, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ4
    glBindVertexArray(VAOs[31]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[31]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ4), Circ4, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ5
    glBindVertexArray(VAOs[32]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[32]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ5), Circ5, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ6
    glBindVertexArray(VAOs[33]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[33]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ6), Circ6, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ7
    glBindVertexArray(VAOs[34]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[34]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ7), Circ7, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ8
    glBindVertexArray(VAOs[35]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[35]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ8), Circ8, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ9
    glBindVertexArray(VAOs[36]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[36]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ9), Circ9, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ10
    glBindVertexArray(VAOs[37]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[37]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ10), Circ10, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ11
    glBindVertexArray(VAOs[38]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[38]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ11), Circ11, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ12
    glBindVertexArray(VAOs[39]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[39]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ12), Circ12, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ13
    glBindVertexArray(VAOs[40]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[40]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ13), Circ13, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ14
    glBindVertexArray(VAOs[41]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[41]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ14), Circ14, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ15
    glBindVertexArray(VAOs[42]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[42]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ15), Circ15, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    // Circ16
    glBindVertexArray(VAOs[43]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[43]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Circ16), Circ16, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(1.0f, 0.9f, 0.1f, 1.0f); //Fondo amarillo
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram1);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram2);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram3);
        glBindVertexArray(VAOs[2]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram4);
        glBindVertexArray(VAOs[3]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram5);
        glBindVertexArray(VAOs[4]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram6);
        glBindVertexArray(VAOs[5]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram7);
        glBindVertexArray(VAOs[6]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUseProgram(shaderProgram8);
        glBindVertexArray(VAOs[7]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Poly
        glUseProgram(shaderProgram9);
        glBindVertexArray(VAOs[8]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);

        // Cuad1
        glUseProgram(shaderProgram10);
        glBindVertexArray(VAOs[9]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Cuad2
        glUseProgram(shaderProgram11);
        glBindVertexArray(VAOs[10]);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Fan1
        glUseProgram(shaderProgram13);
        glBindVertexArray(VAOs[12]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan2
        glUseProgram(shaderProgram14);
        glBindVertexArray(VAOs[13]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan3
        glUseProgram(shaderProgram15);
        glBindVertexArray(VAOs[14]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan4
        glUseProgram(shaderProgram16);
        glBindVertexArray(VAOs[15]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan5
        glUseProgram(shaderProgram17);
        glBindVertexArray(VAOs[16]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan6
        glUseProgram(shaderProgram18);
        glBindVertexArray(VAOs[17]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan7
        glUseProgram(shaderProgram19);
        glBindVertexArray(VAOs[18]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan8
        glUseProgram(shaderProgram20);
        glBindVertexArray(VAOs[19]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan9
        glUseProgram(shaderProgram21);
        glBindVertexArray(VAOs[20]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan10
        glUseProgram(shaderProgram22);
        glBindVertexArray(VAOs[21]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan11
        glUseProgram(shaderProgram23);
        glBindVertexArray(VAOs[22]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan12
        glUseProgram(shaderProgram24);
        glBindVertexArray(VAOs[23]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan13
        glUseProgram(shaderProgram25);
        glBindVertexArray(VAOs[24]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan14
        glUseProgram(shaderProgram26);
        glBindVertexArray(VAOs[25]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan15
        glUseProgram(shaderProgram27);
        glBindVertexArray(VAOs[26]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Fan16
        glUseProgram(shaderProgram28);
        glBindVertexArray(VAOs[27]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 8);

        // Cuad3 - negro (uso de texturas)
        ourShader.use();
        //glUseProgram(shaderProgram12);
        glBindVertexArray(VAOs[11]);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Circ1
        glUseProgram(shaderProgram29);
        glBindVertexArray(VAOs[28]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ2
        glUseProgram(shaderProgram30);
        glBindVertexArray(VAOs[29]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ3
        glUseProgram(shaderProgram31);
        glBindVertexArray(VAOs[30]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ4
        glUseProgram(shaderProgram32);
        glBindVertexArray(VAOs[31]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ5
        glUseProgram(shaderProgram33);
        glBindVertexArray(VAOs[32]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ6
        glUseProgram(shaderProgram34);
        glBindVertexArray(VAOs[33]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ7
        glUseProgram(shaderProgram35);
        glBindVertexArray(VAOs[34]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ8
        glUseProgram(shaderProgram36);
        glBindVertexArray(VAOs[35]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ9
        glUseProgram(shaderProgram37);
        glBindVertexArray(VAOs[36]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ10
        glUseProgram(shaderProgram38);
        glBindVertexArray(VAOs[37]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ11
        glUseProgram(shaderProgram39);
        glBindVertexArray(VAOs[38]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ12
        glUseProgram(shaderProgram40);
        glBindVertexArray(VAOs[39]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ13
        glUseProgram(shaderProgram41);
        glBindVertexArray(VAOs[40]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ14
        glUseProgram(shaderProgram42);
        glBindVertexArray(VAOs[41]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ15
        glUseProgram(shaderProgram43);
        glBindVertexArray(VAOs[42]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // Circ16
        glUseProgram(shaderProgram44);
        glBindVertexArray(VAOs[43]);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 10);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);
    glDeleteBuffers(2, EBO);
    glDeleteProgram(shaderProgram1);
    glDeleteProgram(shaderProgram2);
    glDeleteProgram(shaderProgram3);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}