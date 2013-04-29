//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Func�on creacion esfera
	void mediaEsfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Func�on creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Func�on creacion cilindro
	void medioCilindro(float radio, float altura, int resolucion, GLuint text);	//Func�on creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Func�on creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Func�on creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prismae (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prismar (float altura, float largo, float profundidad, GLuint text1,GLuint text2);//Func�on creacion prisma
	void prismarec (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void prismaHum (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	void prismaU (float altura, float largo, float profundidad, GLuint text, float textHOR, float textVER);//Func�on creacion prisma
	void pizza (GLuint text, GLuint text2);
	void pizza1 (float altura, float largo, float profundidad, GLuint text);
	void pizza2 (GLuint text, GLuint text2);
	void prismab (float altura, float largo, float profundidad, GLuint text1,GLuint text2,GLuint text3,GLuint text4);  //Funcion creacion prisma
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void prismabc (float altura, float largo, float profundidad, GLuint text1,GLuint text2,GLuint text3,GLuint text4,GLuint text5);//Func�on creacion prisma
	void prismamultitext (float altura, float largo, float profundidad, float textH, float textV, GLuint text1,GLuint text2,GLuint text3,GLuint text4,GLuint text5);//Func�on creacion prisma
	void prismamultitext2 (float altura, float largo, float profundidad, float textH, float textV, GLuint text1,GLuint text2,GLuint text3,GLuint text4,GLuint text5);//Func�on creacion prisma
	void prismamultitext3 (float altura, float largo, float profundidad, float textH, float textV, GLuint text1,GLuint text2,GLuint text3,GLuint text4,GLuint text5);//Func�on creacion prisma
	void prismamultitext4 (float altura, float largo, float profundidad, float textH, float textV, GLuint text1,GLuint text2,GLuint text3,GLuint text4,GLuint text5);//Func�on creacion prisma
	void prismal (float altura, float largo, float profundidad, GLuint text1,GLuint text2);//Func�on creacion prisma
	void prismal2 (float altura, float largo, float profundidad, GLuint text1,GLuint text2);//Func�on creacion prisma
    void prismar1 (float altura, float largo, float profundidad, GLuint text);//Func�on creacion prisma
	

	
	void triangul(float largo,float altura, float profundidad,GLuint text, GLuint text2) ;
	void prismaPiso (float altura, float largo, float profundidad, GLuint text);
	
	//void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text );
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);

};
