//#include <gl/gl.h>     // The GL Header File
//#include <windows.h>	//Solo para Windows
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>		// Descomentar para Linux
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>		// Solo para Windows

#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito

//NEW// Keyframes
float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;

#define MAX_FRAMES 5
typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;

int playIndex=0;


int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];




//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
CCamera objCamera; 

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int font=(int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/



GLUquadricObj *quadratic;				// Storage For Our Quadratic Objects ( NEW )

GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
//GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 0.5f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0f, 0.0f, 0.0f, 1.0f };				// Specular Light Values
GLfloat m_amb1[] = { 0.0f, 0.0f, 0.0f, 1.0f };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
CTexture arbol;	//arbol
CTexture esfe;	//esfe
CTexture tronco;	//tronco
CTexture derecho;
CTexture derecho1;
CTexture piedra;
CTexture columna1;
CTexture central;
CTexture pared;
CTexture plano1;
CTexture plano2;
CTexture plano3;
CTexture plano4;
CTexture plano5;
CTexture plano6;
CTexture techot;
CTexture techo1;
CTexture pilarc;
CTexture humanidades;
CTexture humanidades2;
CTexture columnah;
CTexture biciderecho;
CTexture comida;
CTexture gas;
CTexture corniza;
CTexture filos;
CTexture mural;
CTexture mural1;
CTexture muralbc;
CTexture muralbc1;
CTexture rectoriac;
CTexture rectoria;
CTexture pisor;
CTexture entrada;
CTexture entrada1;
CTexture paredislas;
CTexture paredislas2;
CTexture paredfi;
CTexture techofi;
CTexture techoalma;
CTexture basebiblio;
CTexture biblio;
CTexture techobiblio;
CTexture techolab;
CTexture bolaslab;
CTexture edifa;
CTexture parededif;
CTexture barabdalfi;
CTexture tapafi;
CTexture piedraplano; 
CTexture pastorectoria;
CTexture piedrabc;
CTexture piedrabc1;
CTexture piedram;   
CTexture columAudi;//
CTexture columTri;
CTexture prisiz;
CTexture pisorojo;
CTexture tree;
CTexture parteatras;
CTexture paredm;
CTexture pisoroj;
CTexture techohum;
CTexture derechoPos;
CTexture derechoPos1;
CTexture derechoPos2;
CTexture derechoPos3;
CTexture biciderecho1;
CTexture derechoC;
CTexture DGOSApiso;
CTexture DGOSA1;
CTexture DGOSAf1;
CTexture DGOSAf2;
CTexture DGOSAtienda;
CTexture DGOSAtienda1;
CTexture DGOSAarriba;
CTexture DGOSAescaleras;
CTexture libro;
CTexture flecha;
CTexture ArquitecturaPared1;
CTexture ArquitecturaPared2;
CTexture Arqui;
CTexture Bici1;
CTexture Bici2;
CTexture Bici3;
CTexture Bici4;
CTexture Bici5;
CTexture islas1;
CTexture islas2;
CTexture islas3;
CTexture islas4;
CTexture pisorojo1;
CTexture estaci;
CTexture bola;
CTexture torreArqui;
CTexture tree2;
CTexture nombres;
/*nuevas variable*/
CTexture pisor2;
CTexture pisor1;
CTexture puertad;
CTexture puertad1;
CTexture paredroja;
CTexture paredsalond;
CTexture crojo;
CTexture pab;
/*nuevas variable*/
/**********Animacion****************/

CTexture textCara;
CTexture textCamisa;
CTexture textPantalon;
CTexture textCamisa2;
CTexture textPantalon2;
CTexture textZapato;
//Figuras de 3D Studio
CModel arbusto;
CModel animal;
CModel perro;
CModel podadora;
CModel pruebax;
CModel hombrex;

/**********************************************/
//Elipco

bool caminarv = true;
float vX = 0.0;
float vZ = 0.0;
float rotvP = 0.0;
bool caminovA = true;
bool caminovB = false;
bool caminovC = false;
bool caminovD = false;
bool caminovE = false;
/*********************************************/
//ANIMACION AVE
float maX = 0.0;
float maZ = 0.0;
float rotAve = 0.0;
bool recorreA = true;
bool recorreB =false;
bool recorreC = false;
bool recorreD = false;
bool recorreE = false;
bool recorreF = false;
bool volar = true;

//perro

bool caminar = true;
float pX = 0.0;
float pZ = 0.0;
float rotCP = 0.0;
bool caminoA = true;
bool caminoB = false;
bool caminoC = false;
bool caminoD = false;
bool caminoE = false;

//podadora

float podaX = 0.0;
float podaZ = 0.0;
float rotP = 0.0;
bool avanzar = true;
bool cpA = true;
bool cpB = false;
bool cpC = false;
bool cpD = false;

/**************************************/

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
CFiguras fig7;
CFiguras fig8;
CFiguras salones;
CFiguras columna;
CFiguras torre;
CFiguras techo;
CFiguras prueba;
CFiguras cubos;
CFiguras pilar;
CFiguras jardinera;
CFiguras elevacion;
CFiguras escaleras;
CFiguras edificio;
CFiguras plano;
CFiguras letrero;


float colorR = 0.0;
float colorG = 0.0;
float colorB = 0.0;

/********************anima****************/
//animacion monito 2
float rotPiernas=0.0;
float rotRodillas=0.0;
bool hola= false;
bool camina1=false;
bool entra=false;
bool sentar=false;
float avX, avY, avZ, rotM;
/**********************************************/

			
void InitGL ( )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_AMBIENT, m_amb1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glEnable ( GL_COLOR_MATERIAL );   //DESCoMETAMOS
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
    //glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
    //glColor4f(1.0f, 1.0f, 1.0f, 0.5); 
    
    text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("logopumas.bmp");
	//text2.LoadBMP("hulkcara.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	derecho.LoadTGA("derecho.tga");
	derecho.BuildGLTexture();
	derecho.ReleaseImage();

	pared.LoadTGA("pared1.tga");
	pared.BuildGLTexture();
	pared.ReleaseImage();

	pisoroj.LoadTGA("pisoroj.tga");
	pisoroj.BuildGLTexture();
	pisoroj.ReleaseImage();

	paredm.LoadTGA("paredm.tga");
	paredm.BuildGLTexture();
	paredm.ReleaseImage();

	plano6.LoadTGA("plano6.tga");
	plano6.BuildGLTexture();
	plano6.ReleaseImage();

	plano1.LoadTGA("plano1.tga");
	plano1.BuildGLTexture();
	plano1.ReleaseImage();

	parteatras.LoadTGA("partedeatras.tga");
	parteatras.BuildGLTexture();
	parteatras.ReleaseImage();

	plano2.LoadTGA("plano2.tga");
	plano2.BuildGLTexture();
	plano2.ReleaseImage();

	plano3.LoadTGA("plano3.tga");
	plano3.BuildGLTexture();
	plano3.ReleaseImage();

	plano4.LoadTGA("plano4.tga");
	plano4.BuildGLTexture();
	plano4.ReleaseImage();

	plano5.LoadTGA("plano5.tga");
	plano5.BuildGLTexture();
	plano5.ReleaseImage();

	derecho1.LoadTGA("derecho1.tga");
	derecho1.BuildGLTexture();
	derecho1.ReleaseImage();

	piedra.LoadTGA("piedra.tga");
	piedra.BuildGLTexture();
	piedra.ReleaseImage();

	piedraplano.LoadTGA("piedraplano.tga");
	piedraplano.BuildGLTexture();
	piedraplano.ReleaseImage();

	piedrabc.LoadTGA("piedrabc.tga");
	piedrabc.BuildGLTexture();
	piedrabc.ReleaseImage();

	piedrabc1.LoadTGA("piedrabc1.tga");
	piedrabc1.BuildGLTexture();
	piedrabc1.ReleaseImage();

	piedram.LoadTGA("piedram.tga");
	piedram.BuildGLTexture();
	piedram.ReleaseImage();


	rectoriac.LoadTGA("rectoriac.tga");
	rectoriac.BuildGLTexture();
	rectoriac.ReleaseImage();

	rectoria.LoadTGA("rectoria.tga");
	rectoria.BuildGLTexture();
	rectoria.ReleaseImage();

	pisor.LoadTGA("pisoroj.tga");
	pisor.BuildGLTexture();
	pisor.ReleaseImage();

	pilarc.LoadTGA("pilar.tga");
	pilarc.BuildGLTexture();
	pilarc.ReleaseImage();

	central.LoadTGA("central.tga");
	central.BuildGLTexture();
	central.ReleaseImage();

	comida.LoadTGA("comida.tga");
	comida.BuildGLTexture();
	comida.ReleaseImage();

	corniza.LoadTGA("corniza.tga");
	corniza.BuildGLTexture();
	corniza.ReleaseImage();

	columna1.LoadTGA("columna1.tga");
	columna1.BuildGLTexture();
	columna1.ReleaseImage();

	text4.LoadTGA("city/pavimento.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("city/pasto01.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("city/casa01.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	arbol.LoadTGA("arbol.tga");
	arbol.BuildGLTexture();
	arbol.ReleaseImage();

	tronco.LoadTGA("tronco.tga");
	tronco.BuildGLTexture();
	tronco.ReleaseImage();

	techot.LoadTGA("techo.tga");
	techot.BuildGLTexture();
	techot.ReleaseImage();

	techo1.LoadTGA("techo1.tga");
	techo1.BuildGLTexture();
	techo1.ReleaseImage();

	esfe.LoadTGA("esfe.tga");
	esfe.BuildGLTexture();
	esfe.ReleaseImage();

	filos.LoadTGA("filos.tga");
	filos.BuildGLTexture();
	filos.ReleaseImage();

	gas.LoadTGA("gas.tga");
	gas.BuildGLTexture();
	gas.ReleaseImage();

	humanidades.LoadTGA("humanidades.tga");
	humanidades.BuildGLTexture();
	humanidades.ReleaseImage();

	humanidades2.LoadTGA("humanidades2.tga");
	humanidades2.BuildGLTexture();
	humanidades2.ReleaseImage();

	columnah.LoadTGA("columnah.tga");
	columnah.BuildGLTexture();
	columnah.ReleaseImage();

	mural.LoadTGA("mural.tga");
	mural.BuildGLTexture();
	mural.ReleaseImage();

	mural1.LoadTGA("mural1.tga");
	mural1.BuildGLTexture();
	mural1.ReleaseImage();

	entrada.LoadTGA("entrada.tga");
	entrada.BuildGLTexture();
	entrada.ReleaseImage();

	entrada.LoadTGA("entrada1.tga");
	entrada.BuildGLTexture();
	entrada.ReleaseImage();

	muralbc.LoadTGA("muralbc.tga");
	muralbc.BuildGLTexture();
	muralbc.ReleaseImage();

	muralbc1.LoadTGA("muralbc1.tga");
	muralbc1.BuildGLTexture();
	muralbc1.ReleaseImage();

	biciderecho.LoadTGA("biciderecho.tga");
	biciderecho.BuildGLTexture();
	biciderecho.ReleaseImage();

	paredislas.LoadTGA("paredislas.tga");
	paredislas.BuildGLTexture();
	paredislas.ReleaseImage();

	paredislas2.LoadTGA("paredislas2.tga");
	paredislas2.BuildGLTexture();
	paredislas2.ReleaseImage();

	paredfi.LoadTGA("paredfi.tga");
	paredfi.BuildGLTexture();
	paredfi.ReleaseImage();

	techofi.LoadTGA("techofi.tga");
	techofi.BuildGLTexture();
	techofi.ReleaseImage();

	techoalma.LoadTGA("techoalma.tga");
	techoalma.BuildGLTexture();
	techoalma.ReleaseImage();

	basebiblio.LoadTGA("basebiblio.tga");
	basebiblio.BuildGLTexture();
	basebiblio.ReleaseImage();

	biblio.LoadTGA("biblio.tga");
	biblio.BuildGLTexture();
	biblio.ReleaseImage();

	techobiblio.LoadTGA("techobiblio.tga");
	techobiblio.BuildGLTexture();
	techobiblio.ReleaseImage();

	techolab.LoadTGA("techolab.tga");
	techolab.BuildGLTexture();
	techolab.ReleaseImage();

	bolaslab.LoadTGA("bolaslab.tga");
	bolaslab.BuildGLTexture();
	bolaslab.ReleaseImage();

	edifa.LoadTGA("edifa.tga");
	edifa.BuildGLTexture();
	edifa.ReleaseImage();

	parededif.LoadTGA("parededicio.tga");
	parededif.BuildGLTexture();
	parededif.ReleaseImage();

	barabdalfi.LoadTGA("barabdalfi.tga");
	barabdalfi.BuildGLTexture();
	barabdalfi.ReleaseImage();

	tapafi.LoadTGA("tapafi.tga");
	tapafi.BuildGLTexture();
	tapafi.ReleaseImage();

	pastorectoria.LoadTGA("pastorectoria.tga");
	pastorectoria.BuildGLTexture();
	pastorectoria.ReleaseImage();

	columAudi.LoadTGA("marmol.tga");
	//text2.LoadBMP("hulkcara.bmp");
	columAudi.BuildGLTexture();
	columAudi.ReleaseImage();

	
	columTri.LoadTGA("colum.tga");
	columTri.BuildGLTexture();
	columTri.ReleaseImage();

	mural.LoadTGA("mural.tga");
	mural.BuildGLTexture();
	mural.ReleaseImage();

	prisiz.LoadTGA("pru.tga");
	prisiz.BuildGLTexture();
	prisiz.ReleaseImage();

	pisorojo.LoadTGA("pisoroj.tga");
	pisorojo.BuildGLTexture();
	pisorojo.ReleaseImage();

	tree.LoadTGA("tree01.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	techohum.LoadTGA("techohum.tga");
	techohum.BuildGLTexture();
	techohum.ReleaseImage();

	derechoPos.LoadTGA("derechoPos.tga");
	derechoPos.BuildGLTexture();
	derechoPos.ReleaseImage();

	derechoPos1.LoadTGA("derechoPos1.tga");
	derechoPos1.BuildGLTexture();
	derechoPos1.ReleaseImage();

	derechoPos2.LoadTGA("derechoPos2.tga");
	derechoPos2.BuildGLTexture();
	derechoPos2.ReleaseImage();

	derechoPos3.LoadTGA("derechoPos3.tga");
	derechoPos3.BuildGLTexture();
	derechoPos3.ReleaseImage();

	biciderecho1.LoadTGA("biciderecho1.tga");
	biciderecho1.BuildGLTexture();
	biciderecho1.ReleaseImage();

	derechoC.LoadTGA("derechoC.tga");
	derechoC.BuildGLTexture();
	derechoC.ReleaseImage();

	DGOSApiso.LoadTGA("DGOSApiso.tga");
	DGOSApiso.BuildGLTexture();
	DGOSApiso.ReleaseImage();

	DGOSA1.LoadTGA("DGOSA1.tga");
	DGOSA1.BuildGLTexture();
	DGOSA1.ReleaseImage();

	DGOSAf1.LoadTGA("DGOSAf1.tga");
	DGOSAf1.BuildGLTexture();
	DGOSAf1.ReleaseImage();

	DGOSAf2.LoadTGA("DGOSAf2.tga");
	DGOSAf2.BuildGLTexture();
	DGOSAf2.ReleaseImage();

	DGOSAtienda.LoadTGA("DGOSAtienda.tga");
	DGOSAtienda.BuildGLTexture();
	DGOSAtienda.ReleaseImage();

	DGOSAtienda1.LoadTGA("DGOSAtienda1.tga");
	DGOSAtienda1.BuildGLTexture();
	DGOSAtienda1.ReleaseImage();

	DGOSAarriba.LoadTGA("DGOSAarriba.tga");
	DGOSAarriba.BuildGLTexture();
	DGOSAarriba.ReleaseImage();

	DGOSAescaleras.LoadTGA("DGOSAescaleras.tga");
	DGOSAescaleras.BuildGLTexture();
	DGOSAescaleras.ReleaseImage();

	libro.LoadTGA("libros.tga");
	libro.BuildGLTexture();
	libro.ReleaseImage();

	flecha.LoadTGA("flecha.tga");
	flecha.BuildGLTexture();
	flecha.ReleaseImage();

	ArquitecturaPared1.LoadTGA("ArquitecturaPared1.tga");
	ArquitecturaPared1.BuildGLTexture();
	ArquitecturaPared1.ReleaseImage();

	ArquitecturaPared2.LoadTGA("ArquitecturaPared2.tga");
	ArquitecturaPared2.BuildGLTexture();
	ArquitecturaPared2.ReleaseImage();

	Arqui.LoadTGA("Arqui.tga");
	Arqui.BuildGLTexture();
	Arqui.ReleaseImage();

	Bici1.LoadTGA("Bici1.tga");
	Bici1.BuildGLTexture();
	Bici1.ReleaseImage();

	Bici2.LoadTGA("Bici2.tga");
	Bici2.BuildGLTexture();
	Bici2.ReleaseImage();

	Bici3.LoadTGA("Bici3.tga");
	Bici3.BuildGLTexture();
	Bici3.ReleaseImage();

	Bici4.LoadTGA("Bici4.tga");
	Bici4.BuildGLTexture();
	Bici4.ReleaseImage();

	Bici5.LoadTGA("Bici5.tga");
	Bici5.BuildGLTexture();
	Bici5.ReleaseImage();

	islas1.LoadTGA("islas1.tga");
	islas1.BuildGLTexture();
	islas1.ReleaseImage();

	islas2.LoadTGA("islas2.tga");
	islas2.BuildGLTexture();
	islas2.ReleaseImage();

	islas3.LoadTGA("islas3.tga");
	islas3.BuildGLTexture();
	islas3.ReleaseImage();

	islas4.LoadTGA("islas4.tga");
	islas4.BuildGLTexture();
	islas4.ReleaseImage();

	pisorojo1.LoadTGA("pisorojo.tga");
	pisorojo1.BuildGLTexture();
	pisorojo1.ReleaseImage();

	estaci.LoadTGA("estaci.tga");
	estaci.BuildGLTexture();
	estaci.ReleaseImage();

	bola.LoadTGA("bola.tga");
	bola.BuildGLTexture();
	bola.ReleaseImage();

	torreArqui.LoadTGA("torreArqui.tga");
	torreArqui.BuildGLTexture();
	torreArqui.ReleaseImage();

	tree2.LoadTGA("Tree2.tga");
	tree2.BuildGLTexture();
	tree2.ReleaseImage();

	nombres.LoadTGA("nombres.tga");
	nombres.BuildGLTexture();
	nombres.ReleaseImage();
	
	/******Animaciones************/
	textCara.LoadTGA("PROY/piel.tga");
	textCara.BuildGLTexture();
	textCara.ReleaseImage();

	textCamisa.LoadTGA("PROY/camisa.tga");
	textCamisa.BuildGLTexture();
	textCamisa.ReleaseImage();

	textPantalon.LoadTGA("PROY/pantalon.tga");
	textPantalon.BuildGLTexture();
	textPantalon.ReleaseImage();

	textZapato.LoadTGA("PROY/zapato.tga");
	textZapato.BuildGLTexture();
	textZapato.ReleaseImage();

	textCamisa2.LoadBMP("PROY/camisa2.bmp");
	textCamisa2.BuildGLTexture();
	textCamisa2.ReleaseImage();

	textPantalon2.LoadBMP("PROY/pana.bmp");
	textPantalon2.BuildGLTexture();
	textPantalon2.ReleaseImage();

	/****************Nuevas texturas*****************/
	pisor1.LoadTGA("pisor1.tga");
	pisor1.BuildGLTexture();
	pisor1.ReleaseImage();
		
	pisor2.LoadTGA("pisor2.tga");
	pisor2.BuildGLTexture();
	pisor2.ReleaseImage();

	puertad.LoadTGA("puertad.tga");
	puertad.BuildGLTexture();
	puertad.ReleaseImage();

	puertad1.LoadTGA("puertad1.tga");
	puertad1.BuildGLTexture();
	puertad1.ReleaseImage();

	paredroja.LoadTGA("paredroja.tga");
	paredroja.BuildGLTexture();
	paredroja.ReleaseImage();

	paredsalond.LoadTGA("paredsalond.tga");
	paredsalond.BuildGLTexture();
	paredsalond.ReleaseImage();

	crojo.LoadTGA("crojo.tga");
	crojo.BuildGLTexture();
	crojo.ReleaseImage();

	pab.LoadTGA("pab.tga");
	pab.BuildGLTexture();
	pab.ReleaseImage();
	pruebax._3dsLoad("MODELOS/pru1.3ds");
	//hombrex._3dsLoad("MODELOS/Sean.3DS");
	/****************Nuevas texturas*****************/

	arbusto._3dsLoad("MODELOS/tree02.3ds");
	animal._3dsLoad("MODELOS/eagle-adler.3DS");
	perro._3dsLoad("MODELOS/Dog N220808.3DS");
	podadora._3dsLoad("MODELOS/Lawn mower N221112.3DS");
			/*******************/




	quadratic=gluNewQuadric();			// Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(quadratic, GLU_SMOOTH);	// Create Smooth Normals ( NEW )
	gluQuadricTexture(quadratic, GL_TRUE);		// Create Texture Coords ( NEW )


	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);
	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;

	}
	//NEW//////////////////NEW//////////////////NEW//////////////////

}

void nombres1(){
	glPushMatrix();
		glTranslatef(0, 0, 22);
		fig3.prismamultitext4(0.1, 2, 2, 1, 1, 0, 0, 0 , 0, nombres.GLindex);
	glPopMatrix();
}
void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void escalerasfilosofia()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-40.0,-1.0,-22.0);
		escaleras.prisma(0.25,3.0,8.0,piedra.GLindex);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,8.0,piedra.GLindex);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,8.0,piedra.GLindex);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,8.0,piedra.GLindex);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,8.0,piedra.GLindex);
		glTranslatef(-1.0,0.5,0.0);
		escaleras.prisma(0.25,3.0,8.0,piedra.GLindex);
		glTranslatef(-1.0,0.5,0.0);
		escaleras.prisma(0.25,3.0,8.0,piedra.GLindex);
	glPopMatrix();
}

void escalerascentral()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-40.0,-1.0,-22.0);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,9.0,piedra.GLindex);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,9.0,piedra.GLindex);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,9.0,piedra.GLindex);
		glTranslatef(-0.5,0.5,0.0);
		escaleras.prisma(0.25,3.0,9.0,piedra.GLindex);
		glTranslatef(-1.0,0.5,0.0);
		escaleras.prisma(0.25,3.0,9.0,piedra.GLindex);
		glTranslatef(-1.0,0.5,0.0);
		escaleras.prisma(0.25,3.0,9.0,piedra.GLindex);
	glPopMatrix();
}

void Jardinera()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(10,0,-18);
		jardinera.prisma(0.5,4.0,3.0,piedra.GLindex);
	glPopMatrix();
}

void pasillo()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-48.0,5.0,-20.5);
		salones.prisma(0.125,8.0,4.0,techo1.GLindex);
	glPopMatrix();
}

void columnas()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-27.2,0.9,-18.5);
		columna.prisma(2.4,0.125,0.125,pilarc.GLindex);
	glPopMatrix();
}

void CuboDerecho1()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(18,5,-30);
		salones.prisma(7.0,13.0,10.0,derecho.GLindex);
	glPopMatrix();

}

void CuboDerecho2()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(9,5,-30);
		salones.prisma(7.0,5.0,10.0,derecho1.GLindex);
	glPopMatrix();

}

void PilaresDerecho()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glEnable(GL_TEXTURE_GEN_S);
		glEnable(GL_TEXTURE_GEN_T);
		glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_EYE_LINEAR);
		glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_EYE_LINEAR);
		glTranslatef(-23,-0.5,-27);
		pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPushMatrix();
				glTranslatef(2,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(4,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
				glTranslatef(.5,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
			glPushMatrix();
				glTranslatef(6,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(8,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(10,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
				glTranslatef(.5,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(12,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(14,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(16,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
				glTranslatef(.5,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(18,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(20,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(22,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
				glTranslatef(.5,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(24,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(26,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(28,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
				glTranslatef(.5,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(30,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(32,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(34,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
				glTranslatef(.5,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(36,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();

	glPushMatrix();
				glTranslatef(38,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(40,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
				glTranslatef(.5,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(42,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(44,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(46,0,0);
				pilar.cilindro(0.4, 3, 50, columna1.GLindex);
	glPopMatrix();
		glDisable(GL_TEXTURE_GEN_S);
		glDisable(GL_TEXTURE_GEN_T);
	glPopMatrix();
}

void DibujaPasto(){

	glPushMatrix();//PASTO
			glTranslatef(23.5,-0.1,13);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(0, 0, 5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(0, 0, 5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(0, 0, 5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(0, 0, -5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(0, 0, -5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(0, 0, -5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas2.GLindex);
			glTranslatef(0, 0, -5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(0, 0, -5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(0, 0, -5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(0, 0, -5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas3.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(0, 0, -4.5);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 4, 5, 5, 0, 0, 0, 0, islas1.GLindex);
			glTranslatef(0, 0, -4.5);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(-5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 5, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(0, 0, -5.5);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);
			glTranslatef(5, 0, 0);
			fig3.prismamultitext4(0.1, 5, 6, 5, 5, 0, 0, 0, 0, islas4.GLindex);

	glPopMatrix();

	glPushMatrix();
			glTranslatef(-4,-0.1,18);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(5,0,0);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,-5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(5,0,0);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(5,0,0);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,-5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(5,0,0);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
            glTranslatef(0,0,5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(3.5,0,0);
			fig3.prismamultitext4(0.1, 2, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,-5);
			fig3.prismamultitext4(0.1, 2, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(0,0,-5);
			fig3.prismamultitext4(0.1, 2, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(1.5,0,-5);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(5,0,0);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			glTranslatef(5,0,0);
			fig3.prismamultitext4(0.1, 5, 5, 1, 1, 0, 0, 0, 0, techolab.GLindex);
			//////////////////////////Inicia Estacionamiento//////////////////
			glTranslatef(-6.5,0,5);
			fig3.prismamultitext4(0.1, 8, 5, 1, 1, 0, 0, 0, 0, estaci.GLindex);
			glTranslatef(0,0,5);
			fig3.prismamultitext4(0.1, 8, 5, 1, 1, 0, 0, 0, 0, estaci.GLindex);
			glTranslatef(0,0,5);
			fig3.prismamultitext4(0.1, 8, 5, 1, 1, 0, 0, 0, 0, estaci.GLindex);

	glPopMatrix();

}

void comidaf()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-29,2,-20);
		salones.prisma(0.25,8.0,4.0,techo1.GLindex);//techo
		glTranslatef(0,-1.1,1.5);
		salones.prisma(2,1.5,2.0,comida.GLindex);
		glTranslatef(0,1.4,.75);
		salones.prisma(.75,0.75,0.5,gas.GLindex);
	glPopMatrix();
}

void planos()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-25,0,-35);
		plano.prisma(3.5,10,.1,plano1.GLindex);
		glTranslatef(10,0,0);
		plano.prisma(3.5,10,.1,plano2.GLindex);
		glTranslatef(7,0,0);
		plano.prisma(3.5,5,.1,plano3.GLindex);
		glTranslatef(7,0,0);
		plano.prisma(3.5,10,.1,plano4.GLindex);
		glTranslatef(7.25,0,0);
		plano.prisma(3.5,5,.1,plano5.GLindex);
		glTranslatef(10.5,0,0);
		plano.prisma(3.5,16,.1,plano6.GLindex);
	glPopMatrix();
}

void filosofia()
{
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(-39.5,2,-30);
	salones.prisma(8,20.0,10,filos.GLindex);//edificio
	glColor3f(1,1,1);
	glTranslatef(0,4.25,0);
	salones.prisma(0.5,20.0,10,corniza.GLindex);//techo
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(7,0,3);
	salones.prisma(2,2.0,2,0);//base bola
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//primera bola adelante
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(7,0,-2);
	salones.prisma(2,2.0,2,0);//base bola
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//primera bola atras
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(4,0,3);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//segunda bola adelante
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(4,0,-2);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//segunda bola atras
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(1,0,3);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//tercera bola adelante
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(1,0,-2);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//tercera bola atras
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(-2,0,3);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//cuarta bola adelante
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(-2,0,-2);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//cuarta bola atras
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(-5,0,3);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//quinta bola adelante
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,0,0);
	glTranslatef(-5,0,-2);
	salones.prisma(2,2.0,2,0);//base adelante
	glTranslatef(0,1,0);
	glColor3f(1,1,1);
	salones.esfera(1,6,6,0);//quinta bola atras
	glPopMatrix();
	glPopMatrix();
}

void DibujaPosgradoDerecho(){
	glPushMatrix(); //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(50, 2, -13);
		torre.prismamultitext(5, 25, 3.2, 1, 3, derechoPos3.GLindex, 0, derechoPos3.GLindex, derechoPos.GLindex, techolab.GLindex);
		glTranslatef(8.5, 0, -4.2);
		torre.prismamultitext(5, 8, 5.2, 1, 1, 0, 0, 0, derechoPos2.GLindex, techolab.GLindex);
	glPopMatrix();
}

void DibujaEdificioCDerecho(){ //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPushMatrix();
		glTranslatef(37, 2, -19);
		torre.prismamultitext(5,17,3.1,1,1, derechoPos1.GLindex, 0, derechoPos1.GLindex, derechoC.GLindex, techolab.GLindex);

		glTranslatef(0,0,-8);
		torre.prismamultitext(5, 17, 4.0, 1, 1, derechoPos1.GLindex, 0, derechoPos1.GLindex, derechoC.GLindex, techolab.GLindex);
	glPopMatrix();
}

void DibujaBiciPumaDerecho(){ //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPushMatrix();
		glTranslatef(26,1,-18.7);
		torre.prismamultitext(2, 3.5, 2, 1, 1, biciderecho1.GLindex, 0, biciderecho1.GLindex, biciderecho.GLindex, techolab.GLindex );
	glPopMatrix();
}

void DibujaBiciPumaIng(){ //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPushMatrix();
		glTranslatef(11,1,21.7);
		torre.prismamultitext(2, 3.5, 2, 1, 1, biciderecho1.GLindex, 0, biciderecho1.GLindex, biciderecho.GLindex, techolab.GLindex );
	glPopMatrix();
}

void auditorioDiseInd(){
	/*Cuadro.................................*/
glPushMatrix();
	glPushMatrix();
	
				glTranslatef(33,5.1,3);
				
				//glScalef(27.5,0.1,1);
				//glRotatef(90,0.0,1.0,0.0);
				//fig7.prisma(5,9,11,columAudi.GLindex);	
				fig7.prisma(5,9,11,columAudi.GLindex);
	glPopMatrix();
	//debajo auditorio 
		glPushMatrix();
	
				glTranslatef(33,1,2.5);
				
				//glScalef(27.5,0.1,1);
				//glRotatef(90,0.0,1.0,0.0);
				//fig7.prisma(5,9,11,columAudi.GLindex);
				//fig7.prisma(3,5,7,columAudi.GLindex);
				fig8.prismamultitext2(3, 5, 7, 10, 10, puertad1.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex);
	glPopMatrix();

	//Columan division auditorio y diseño 
		glPushMatrix();
	
				glTranslatef(33,1,10);
				fig8.prismamultitext2(4, 8, 0.6, 10, 10, paredroja.GLindex, paredroja.GLindex, paredroja.GLindex, paredroja.GLindex, paredroja.GLindex);
				
	glPopMatrix();
	//salones diseño industrial
		glPushMatrix();
	
				glTranslatef(35,1.1,16);
				fig7.prismamultitext2(2.5, 5,4, 1, 1, paredsalond.GLindex, paredsalond.GLindex, paredsalond.GLindex, puertad1.GLindex, paredsalond.GLindex);
	glPopMatrix();
	//salones 2
		glPushMatrix();
	
				glTranslatef(35,1.2,20);
				fig7.prismamultitext2(3, 5, 4, 1, 1, paredsalond.GLindex, paredsalond.GLindex, paredsalond.GLindex, paredsalond.GLindex, paredsalond.GLindex);
	glPopMatrix();
	//salones 3
		glPushMatrix();
	
				glTranslatef(35,1.2,24);
				fig7.prismamultitext2(3, 5, 4, 1, 1, paredsalond.GLindex, paredsalond.GLindex, paredsalond.GLindex, paredsalond.GLindex, paredsalond.GLindex);
	glPopMatrix();

	glPushMatrix();
				glTranslatef(33,5.1,-2.5);
				fig7.prisma(5,9,0.1,mural1.GLindex);			
	glPopMatrix();


	/*Cuadro te3cho..........................*/
	glPushMatrix();
				glTranslatef(33,7.6,3);
				glRotatef(5,1.0,0.0,0.0);
				fig7.prisma(1,9,11,columAudi.GLindex);			
	glPopMatrix();

	/*Cuadro contorno superiro..........................*/
	glPushMatrix();
				//glColor3f(0,0,0);
				glTranslatef(33,8.2,3);
				glRotatef(5,1.0,0.0,0.0);
				fig7.prisma(0.2,9,11,columTri.GLindex);			
	glPopMatrix();

		/*Cuadro Contorno inferior..........................*/
	glPushMatrix();
				glTranslatef(33,2.55,3);
				//glRotatef(5,1.0,0.0,0.0);
				fig7.prisma(0.2,9,11,columTri.GLindex);			
	glPopMatrix();
	/*Columna esquina 1.............................*/
	glPushMatrix();
				
				glTranslatef(29,0,-2);
				glRotatef(6,1.0,0.0,0.0);
				//glColor3f(0.5,0.7,1.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);	
	glPopMatrix();
	glPushMatrix();
				glTranslatef(29,0,-2.2);
				glRotatef(-5,1.0,0.0,0.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
				
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,.7,-2.1);
					fig7.prisma(1.5,0.15,0.3,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,2,-2.1);
					fig7.prisma(1.3,0.15,0.55,columTri.GLindex);
	glPopMatrix();
	/*--------------------------------------------------*/
	/*Columna esquina 2.............................*/
	glPushMatrix();
				
				glTranslatef(29,0,1.2);
				glRotatef(6,1.0,0.0,0.0);
				//glColor3f(0.5,0.7,1.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);	
	glPopMatrix();
	glPushMatrix();
				glTranslatef(29,0,1);
				glRotatef(-5,1.0,0.0,0.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
				
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,0.7,1.1);
					fig7.prisma(1.5,0.15,0.3,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,2,1.1);
					fig7.prisma(1.3,0.15,0.55,columTri.GLindex);
	glPopMatrix();
	/*--------------------------------------------------*/
	/*Columna esquina 3.............................*/
	glPushMatrix();
				
				glTranslatef(29,0,4.2);
				glRotatef(6,1.0,0.0,0.0);
				//glColor3f(0.5,0.7,1.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);	
	glPopMatrix();
	glPushMatrix();
				glTranslatef(29,0,4);
				glRotatef(-5,1.0,0.0,0.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
				
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,0.7,4.1);
					fig7.prisma(1.5,0.15,0.3,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,2,4.1);
					fig7.prisma(1.3,0.15,0.55,columTri.GLindex);
	glPopMatrix();
	/*--------------------------------------------------*/
	
		/*Columna esquina 4............................*/
	glPushMatrix();
				
				glTranslatef(29,0,7.2);
				glRotatef(6,1.0,0.0,0.0);
				//glColor3f(0.5,0.7,1.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);	
	glPopMatrix();
	glPushMatrix();
				glTranslatef(29,0,7);
				glRotatef(-5,1.0,0.0,0.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
				
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,0.7,7.1);
					fig7.prisma(1.5,0.15,0.3,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
					glTranslatef(29,2,7.1);
					fig7.prisma(1.3,0.15,0.55,columTri.GLindex);
	glPopMatrix();
	/*--------------------------------------------------*/
		/*Columna esquina -1.............................*/
	glPushMatrix();
				
				glTranslatef(31.25,0,-2);
				glRotatef(6,1.0,0.0,0.0);
				//glColor3f(0.5,0.7,1.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
				glTranslatef(31.25,0,-2.2);
				glRotatef(-5,1.0,0.0,0.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
				
	glPopMatrix();
	glPushMatrix();
					glTranslatef(31.25,0.7,-2.1);
					fig7.prisma(1.5,0.15,0.3,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
					glTranslatef(31.25,2,-2.1);
					fig7.prisma(1.3,0.15,0.55,columTri.GLindex);
	glPopMatrix();
		/*Columna esquina -2.............................*/
	glPushMatrix();
				
				glTranslatef(33.5,0,-2);
				glRotatef(6,1.0,0.0,0.0);
				//glColor3f(0.5,0.7,1.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);	
	glPopMatrix();
	glPushMatrix();
				glTranslatef(33.5,0,-2.2);
				glRotatef(-5,1.0,0.0,0.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
				
	glPopMatrix();
	glPushMatrix();
					glTranslatef(33.5,0.7,-2.1);
					fig7.prisma(1.5,0.15,0.3,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
					glTranslatef(33.5,2,-2.1);
					fig7.prisma(1.3,0.15,0.55,columTri.GLindex);
	glPopMatrix();

		/*Columna esquina -3.............................*/
	glPushMatrix();
				
				glTranslatef(35.75,0,-2);
				glRotatef(6,1.0,0.0,0.0);
				//glColor3f(0.5,0.7,1.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);	
	glPopMatrix();
	glPushMatrix();
				glTranslatef(35.75,0,-2.2);
				glRotatef(-5,1.0,0.0,0.0);
				fig7.cilindro(0.1,2.5,50,columTri.GLindex);
				
	glPopMatrix();
	glPushMatrix();
					glTranslatef(35.75,0.7,-2.1);
					fig7.prisma(1.5,0.15,0.3,columTri.GLindex);
	glPopMatrix();
	glPushMatrix();
					glTranslatef(35.75,2,-2.1);
					fig7.prisma(1.3,0.15,0.55,columTri.GLindex);
	glPopMatrix();

	/*Techo curva 1*/
	glPushMatrix();	//Techo 
		glTranslatef(29.7, 8, 8.5);
		glRotatef(-85, 1, 0,0);
		torre.cilindro(0.8, 11, 50,crojo.GLindex);
	glPopMatrix();

	/*Techo curva 2*/
	glPushMatrix();	//Techo 
		glTranslatef(31.7, 8, 8.5);
		glRotatef(-85, 1, 0,0);
		torre.cilindro(0.8, 11, 50, crojo.GLindex);
	glPopMatrix();

	/*Techo curva 3*/
	glPushMatrix();	//Techo 
		glTranslatef(33.7,8, 8.5);
		glRotatef(-85, 1, 0,0);
		torre.cilindro(0.8, 11, 50, crojo.GLindex);
	glPopMatrix();

	/*Techo curva 4*/
	glPushMatrix();	//Techo 
		glTranslatef(35.7,8, 8.5);
		glRotatef(-85, 1, 0,0);
		torre.cilindro(0.8, 11, 50, crojo.GLindex);
	glPopMatrix();
glPopMatrix();
}

void DisenoIndustrial(){
		
glPushMatrix();
	/*Cuadro.1................................*/
	glPushMatrix();
		/*prisma base izquierda*/
		glTranslatef(33,5.1,9);
		fig8.prisma(5,9,2,prisiz.GLindex);		
	glPopMatrix();
	/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,2.55,9);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,7.71,9);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/
	glPushMatrix();
		/*Triangulo Inferior*/
		glTranslatef(33,3,11);
		glRotatef(180,0,0,1);
		glRotatef(-90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();
		/*Triangulo Superior*/
		glTranslatef(33,8,11);
		//glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();

		/*Prisma base centro*/
		glTranslatef(33,5.5,11);
		fig7.prisma(4.3,9,2,prisiz.GLindex);		
	glPopMatrix();
	glPushMatrix();

	/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,8,11);
		glRotatef(-15,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,2.9,11);
		glRotatef(-18,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	/***************************/
	
		/*prisma base derecha*/
		glTranslatef(33,5.8,13);
		fig7.prisma(5,9,2,prisiz.GLindex);		
	glPopMatrix();
	glPushMatrix();
		glTranslatef(29,0,14.2);
		fig7.cilindro(0.2,3.5,50,columAudi.GLindex);
	glPopMatrix();
		/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,8.25,13);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,3.25,13);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/


	/*Cuadro 2................................*/
	glPushMatrix();
		/*prisma base izquierda*/
		glTranslatef(33,5.1,15);
		fig7.prisma(5,9,2,prisiz.GLindex);		
	glPopMatrix();

		/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,2.55,15);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,7.71,15);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/


	glPushMatrix();
		/*Triangulo Inferior*/
		glTranslatef(33,3,17);
		glRotatef(180,0,0,1);
		glRotatef(-90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();
		/*Triangulo Superior*/
		glTranslatef(33,8,17);
		//glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();
		/*Prisma base centro*/
		glTranslatef(33,5.5,17);
		fig7.prisma(4.3,9,2,prisiz.GLindex);		
	glPopMatrix();
	glPushMatrix();


	/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,8,17);
		glRotatef(-15,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,2.9,17);
		glRotatef(-18,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	/***************************/
		/*prisma base derecha*/
		glTranslatef(33,5.8,19);
		fig7.prisma(5,9,2,prisiz.GLindex);		
	glPopMatrix();
	glPushMatrix();
	
	/***************************/
		/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,8.25,19);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,3.25,19);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/

		/*Columna derecha*/
		glTranslatef(29,0,20.2);
		fig7.cilindro(0.2,3.5,50,columAudi.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*Columna centro*/
		glTranslatef(29,0,17.2);
		fig7.cilindro(0.2,3.5,50,columAudi.GLindex);		
	glPopMatrix();
	
	/*Cuadro 3................................*/
	glPushMatrix();
		/*prisma base izquierda*/
		glTranslatef(33,5.1,21);
		fig7.prisma(5,9,2,prisiz.GLindex);		
	glPopMatrix();
		/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,2.55,21);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,7.71,21);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/



	glPushMatrix();
		/*Triangulo Inferior*/
		glTranslatef(33,3,23);
		glRotatef(180,0,0,1);
		glRotatef(-90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();
		/*Triangulo Superior*/
		glTranslatef(33,8,23);
		//glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();
		/*Prisma base centro*/
		glTranslatef(33,5.5,23);
		fig7.prisma(4.3,9,2,prisiz.GLindex);		
	glPopMatrix();

		/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,8,23);
		glRotatef(-15,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,2.9,23);
		glRotatef(-18,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	/***************************/


	glPushMatrix();
		/*prisma base derecha*/
		glTranslatef(33,5.8,25);
		fig7.prisma(5,9,2,prisiz.GLindex);		
	glPopMatrix();

	/**************************/
	glPushMatrix();
		/*planitoinferiro*/
		glTranslatef(33,8.25,25);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		glTranslatef(33,3.25,25);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/
	glPushMatrix();
		/*Columna derecha*/
		glTranslatef(29,0,26.2);
		fig7.cilindro(0.2,3.5,50,columAudi.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*Columna centro*/
		glTranslatef(29,0,23.3);
		fig7.cilindro(0.2,3.5,50,columAudi.GLindex);		
	glPopMatrix();


	/*********Diseño  de vedad*******/
	glPushMatrix();
		glTranslatef(33,1,31);
		//fig7.prisma(3,9,17,piedra.GLindex);
		fig7.prismamultitext2(3, 9, 10, 10, 10, puertad1.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(33,5,31);
		//fig7.prisma(3,9,17,piedra.GLindex);
		fig7.prismamultitext2(5, 9, 10, 10, 10, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex);
	glPopMatrix();


	/***************/
	
	/*Cuadro 4................................*/
	/*glPushMatrix();
		/*prisma base izquierda*/
	/*	glTranslatef(33,5.1,27);
		fig7.prisma(5,9,2,prisiz.GLindex);		
		glPopMatrix();



			/**************************/
	/*glPushMatrix();
		/*planitoinferiro*/
		/*glTranslatef(33,2.55,27);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		/*glTranslatef(33,7.71,27);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/
	/*glPushMatrix();
		/*Triangulo Inferior*/
		/*glTranslatef(33,3,29);
		glRotatef(180,0,0,1);
		glRotatef(-90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();
		/*Triangulo Superior*/
		/*glTranslatef(33,8,29);
		//glRotatef(90,1,0,0);
		glRotatef(90,0,1,0);
		fig7.triangul(2,0.7,9,prisiz.GLindex,prisiz.GLindex);	
	glPopMatrix();
	glPushMatrix();
		/*Prisma base centro*/
		/*glTranslatef(33,5.5,29);
		fig7.prisma(4.3,9,2,prisiz.GLindex);		
	glPopMatrix();
		/**************************/
	/*glPushMatrix();
		/*planitoinferiro*/
	/*	glTranslatef(33,8,29);
		glRotatef(-15,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
		/*glTranslatef(33,2.9,29);
		glRotatef(-18,1,0,0);
		fig8.prisma(.2,9,2.3,columTri.GLindex);		
	glPopMatrix();
	/***************************/
	/*glPushMatrix();
		/*prisma base derecha*/
	/*	glTranslatef(33,5.8,31);
		fig7.prisma(5,9,2,prisiz.GLindex);		
	glPopMatrix();
	glPushMatrix();
	/**************************/
	/*glPushMatrix();
		/*planitoinferiro*/
	/*	glTranslatef(33,8.25,31);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*planitosupero*/
	/*	glTranslatef(33,3.25,31);
		fig8.prisma(.2,9,2,columTri.GLindex);		
	glPopMatrix();
	/***************************/
		/*Columna derecha*/
	/*	glTranslatef(29,0,32.2);
		fig7.cilindro(0.2,3.5,50,columAudi.GLindex);		
	glPopMatrix();
	glPushMatrix();
		/*Columna centro*/
		/*glTranslatef(29,0,29.2);
		fig7.cilindro(0.2,3.5,50,columAudi.GLindex);		
	glPopMatrix();
	*/



glPopMatrix();
}

void dibujaJardin(){

	//bardita
glPushMatrix(); 
		glTranslatef(5,0, -13.5);
		//glRotatef(90, 0, 1,0);
		//fig8.prisma(1,32, 0.2, piedra.GLindex);
		fig8.prismamultitext2(1, 32, 0.2, 20, 20, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex); 
	glPopMatrix();

	//subida priedra derechos
	glPushMatrix(); 
		glTranslatef(23,0, -16.5);
		fig8.prismamultitext2(0, 4, 10, 10, 10, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex); 
	glPopMatrix();

	//piedfra piso en parte enfresnte central
	glPushMatrix(); 
		glTranslatef(-32,0, 5);
		fig8.prismamultitext2(0, 16, 80, 5, 5, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex); 
	glPopMatrix();

	//Piso debajo derecho y filos
	glPushMatrix(); 
		glTranslatef(0,0, -31.5);
		//glRotatef(90, 0, 1,0);
		//fig8.prismaPiso(0,55, 15, piedra.GLindex);
		fig8.prismamultitext2(0, 55, 15, 10, 10, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex, piedra.GLindex); 
	glPopMatrix();

	//piso enfrente de auditori pasto

	glPushMatrix(); 
		glTranslatef(28,0, 1.5);
		fig8.prismamultitext2(0, 2, 15, 70, 70, text5.GLindex, text5.GLindex, text5.GLindex, text5.GLindex, text5.GLindex); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	//Piso debajo auditorio
	glPushMatrix(); 
		glTranslatef(34,0, 4);
		fig8.prismamultitext2(0, 10, 10, 90, 90, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();
	
	//Piso frete debajo mural auditori es paso
	glPushMatrix(); 
		glTranslatef(32,0,-4);
		fig8.prismamultitext2(0, 10, 6, 80, 80, text5.GLindex, text5.GLindex, text5.GLindex, text5.GLindex, text5.GLindex);
	glPopMatrix();

	//piso frente a auditorio parte de las iasla 
	glPushMatrix(); 
		glTranslatef(26.5,0, 1.5);
		fig8.prismamultitext2(0, 1.5, 17, 20, 10, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex);
	glPopMatrix();
	
	
	//piso frente a auditorio parte derecho
	glPushMatrix(); 
		glTranslatef(33,0,-15.5),
		fig8.prismamultitext2(0, 17, 17, 200, 200, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex);
	glPopMatrix();


	/*************Agregado*****************/
	//Piso debajo saloness diseñño
	glPushMatrix(); 
		glTranslatef(34.9,0, 16.5);
		fig8.prismamultitext2(0, 20, 16, 200,200, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex, pisor2.GLindex);
	glPopMatrix();

	//Piso estacionamiento igenieria
	glPushMatrix(); 
		//glTranslatef(27.9,0, 39.5);
		//fig8.prismamultitext2(0, 30, 30, 200,200, pab.GLindex, pab.GLindex, pab.GLindex, pab.GLindex, pab.GLindex);
	glPopMatrix();

}

void DibujaDisenio(){
	glPushMatrix();
		glTranslatef(0, 10, 0);
		glScalef(2,2,2);
		glRotatef(90, 0, 0, 1);
		fig3.pizza(0.0, 0.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 8, 0);
		fig3.prisma(2, 2, 2, 0);
	glPopMatrix();
}

void DibujaHumanidades(){

	//glPushMatrix(); //Edificio Central
	//	glTranslatef(48, 11, 1);
	//	torre.prismaHum(18.0, 6, 18.5, humanidades.GLindex);
	//glPopMatrix();

	glPushMatrix(); //Edificio Central Parte Baja
		glTranslatef(48, 5, 1);
		torre.prismaHum(6.0, 6, 18.5, humanidades.GLindex);
	glPopMatrix();

	glPushMatrix(); //Edificio Central Parte Central
		glTranslatef(48, 11, 1);
		torre.prismaHum(6.0, 6, 18.5, humanidades2.GLindex);
	glPopMatrix();

	glPushMatrix(); //Edificio Central Parte Alta
		glTranslatef(48, 17, 1);
		torre.prismaHum(6.0, 6, 18.5, humanidades.GLindex);
	glPopMatrix();

	glPushMatrix(); //Lado IZQ Edificio Central
		glTranslatef(48, 11, -8.5);
		//glColor3f(0,0,0);
		torre.prismamultitext2(18.0, 6, 0.5, 5, 5, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
		//fig3.prismamultitext(3.5, 16.2, 5, 5, 1, 0, techolab.GLindex, techolab.GLindex, techolab, techolab.GLindex); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix(); //Lado DER Edificio Central
		glTranslatef(48, 11, 10.5);
		//glColor3f(0,0,0);
		torre.prismamultitext2(18.0, 6, 0.5, 5, 5, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix(); //Tapa humanidades
		glTranslatef(48, 20.5, 1);
		//glColor3f(0,0,0);
		torre.prismamultitext2(1, 6, 19.5, 5, 5, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Techo 
		glTranslatef(48, 22, 2.5);
		torre.prismamultitext(3.0, 6.0, 10.0, 3, 3, columAudi.GLindex, techohum.GLindex, techohum.GLindex, techohum.GLindex , techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Techo Inclinado adorno
		glTranslatef(48, 23.48, -2.5);
		//glTranslatef(0,1.48,0);
		glRotatef(10, 1, 0,0);
		torre.prismamultitext2(0.8, 6, 3.4, 1, 2, 0, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);//(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Techo Inclinado parte baja
		glTranslatef(48, 22, -2.5);
		torre.prismamultitext2(3.1, 6.1, 3.5, 2, 2, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex);
	glPopMatrix();

	glPushMatrix();	//Adorno cilindro
		glTranslatef(51,23.5,6);
		glRotatef(90, 0, 0, 1);
		torre.cilindro(0.8, 5.5, 50, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Adorno cilindro
		glTranslatef(51,23.5,4.4);
		glRotatef(90, 0, 0, 1);
		torre.cilindro(0.8, 5.5, 50, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Adorno cilindro
		glTranslatef(51,23.5,2.8);
		glRotatef(90, 0, 0, 1);
		torre.cilindro(0.8, 5.5, 50, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Adorno cilindro
		glTranslatef(51,23.5,1.2);
		glRotatef(90, 0, 0, 1);
		torre.cilindro(0.8, 5.5, 50, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Adorno cilindro
		glTranslatef(51,23.5,-0.4);
		glRotatef(90, 0, 0, 1);
		torre.cilindro(0.8, 5.5, 50, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Columna Base Cilindro
		
		glTranslatef(46, 0, -8);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(4,0,0);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(0,0,3.5);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(-4,0,0);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(0,0,3.5);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(4,0,0);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(0,0,3.5);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(-4,0,0);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(0,0,3.5);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(4,0,0);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(0,0,3.5);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
		glTranslatef(-4,0,0);
		columna.cilindro(0.4, 2, 100, columAudi.GLindex);
	glPopMatrix();

	glPushMatrix(); //Columna Base PRISMA I
		glTranslatef(48, 1, -4.5);
		torre.prisma(2, 2, 5, derechoPos1.GLindex);
		glTranslatef(0, 0, 10.5);
		torre.prisma(2, 2, 5, derechoPos1.GLindex);
	glPopMatrix();
}

void DibujaDGOSA(){
	glPushMatrix();	//Base Larga DGOSA //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-8.45, 0.5, 22);
		fig3.prismamultitext3(0.5, 5, 23, 5, 15, 0, DGOSA1.GLindex, DGOSA1.GLindex, DGOSA1.GLindex, DGOSApiso.GLindex);
	glPopMatrix();

	glPushMatrix();	//Base Corta DGOSA //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-13.95, 0.5, 22);
		fig3.prismamultitext3(0.5, 6, 17, 5, 15, 0, DGOSA1.GLindex, DGOSA1.GLindex, DGOSA1.GLindex, DGOSApiso.GLindex);
	glPopMatrix();

	//glPushMatrix();	//Edificio DGOSA
	//	glTranslatef(-10.45, 2.5, 23);
	//	//glColor3f(0, 0, 0);
	//	fig3.prisma(3, 7, 17, 0);
	//glPopMatrix();

	glPushMatrix();	//Edificio DGOSA1 //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-8.7, 2.5, 18.5);
		//glColor3f(0, 0, 0);
		fig3.prismamultitext(3, 3.5, 8, 1, 1, 0, DGOSAtienda.GLindex, DGOSAf1.GLindex, 0, 0);
	glPopMatrix();

	glPushMatrix();	//Edificio DGOSA2 //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-12.2, 2.5, 18.5);
		//glColor3f(0, 0, 0);
		fig3.prismamultitext(3, 3.5, 8, 1, 1, 0, 0, DGOSAf2.GLindex, DGOSAarriba.GLindex, 0);
	glPopMatrix();

	glPushMatrix();	//Edificio DGOSA11 //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-8.7, 2.5, 26.5);
		//glColor3f(0, 0, 0);
		fig3.prismamultitext(3, 3.5, 8, 1, 1, 0, DGOSAtienda1.GLindex, 0, 0, 0);
	glPopMatrix();

	glPushMatrix();	//Edificio DGOSA21 //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-12.2, 2.5, 26.5);
		//glColor3f(0, 0, 0);
		fig3.prismamultitext(3, 3.5, 8, 1, 1, 0, 0, 0, DGOSAarriba.GLindex, 0);
	glPopMatrix();

	glPushMatrix();	//Techo DGOSA //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-11.95, 4.1, 23);
		//glColor3f(1, 0, 0);
		fig3.prismamultitext3(0.2, 10, 18.5, 3, 10, 0, DGOSA1.GLindex, DGOSA1.GLindex, DGOSA1.GLindex, techolab.GLindex );
	glPopMatrix();

	glPushMatrix();	//Edificio DGOSA parte superior //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-10, 5.1, 25);
		//glColor3f(1, 0, 0);
		fig3.prismamultitext(2, 5, 17, 1, 2, 0, DGOSAarriba.GLindex, DGOSAarriba.GLindex, DGOSAarriba.GLindex, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Rampa acceso DGOSA
		//glColor3f(1, 0, 0);
		glTranslatef(-14.9, 2.25, 21);
		glRotatef(-90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		fig3.pizza1(10,2,3.5, DGOSAescaleras.GLindex);
	glPopMatrix();

	glPushMatrix();	//Rampa lado de ingeniería
		//glColor3f(0, 0, 0);
		glTranslatef(0, 0, 18);
		glRotatef(-90, 1, 0, 0);
		fig3.pizza1(11.95,1.5,1,techolab.GLindex);
	glPopMatrix();
}

void DibujaArquitectura(){
	//glPushMatrix();	//Barda Arquitectura
	//	//glColor3f(0, 0, 0);
	//	glTranslatef(-23.25, 1.5, 27.5);
	//	fig3.prisma(4, 12.5, 0.5, 0);
	//glPopMatrix();

	glPushMatrix();	//Barda Arquitectura 1 //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		//glColor3f(0, 0, 0);
		glTranslatef(-26.375, 1.5, 27.5);
		fig3.prismamultitext(4, 6.25, 0.5, 1, 1, 0, 0, ArquitecturaPared1.GLindex, 0, DGOSApiso.GLindex);
	glPopMatrix();

	glPushMatrix();	//Barda Arquitectura 2
		//glColor3f(0, 0, 0);
		glTranslatef(-20.125, 1.5, 27.5);
		fig3.prismamultitext(4, 6.25, 0.5, 1, 1, 0, 0, ArquitecturaPared2.GLindex, 0, DGOSApiso.GLindex);
	glPopMatrix();

	glPushMatrix();	//Base Arquitectura
		//glColor3f(1, 0, 0);
		glTranslatef(-23.25, 1.5, 30.2);
		fig3.prisma(4, 12.5, 5, Arqui.GLindex);
	glPopMatrix();

	glPushMatrix();	//Base Explanada Arquitectura
		//glColor3f(1, 0, 1);
		glTranslatef(-23.25, 1.5, 36.45);
		fig3.prisma(4, 12.5, 15, Arqui.GLindex);
	glPopMatrix();

	glPushMatrix();	//barda rampa acceso Arquitectura
		//glColor3f(0, 1, 0);
		glTranslatef(-29.8, 2, 30);
		fig3.prisma(3.5, 0.6, 5.45, Arqui.GLindex);
	glPopMatrix();

	glPushMatrix();	//pasamanos rampa acceso Arquitectura
		//glColor3f(0, 0, 0);
		glTranslatef(-29.8, 3.75, 30);
		fig3.prisma(0.5, 0.6, 5.45, Arqui.GLindex);
	glPopMatrix();

	glPushMatrix();	//Rampa acceso Arquitectura I
		//glColor3f(1, 0, 1);
		glTranslatef(-29.8, 1.5, 18.78);
		glRotatef(-90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		fig3.pizza1(17,0.6,5,Arqui.GLindex);
	glPopMatrix();

	glPushMatrix();	//Rampa acceso Arquitectura II
		//glColor3f(1, 1, 0);
		glTranslatef(-34.50, 0.75, 18.78);
		glRotatef(-90, 1, 0, 0);
		glRotatef(90, 0, 0, 1);
		fig3.pizza1(17, 8.8, 4, Arqui.GLindex);  //Profundidad, largo, altura
	glPopMatrix();

	glPushMatrix();	//Explanada de arquitectura
		//glColor3f(1, 0, 1);
		glTranslatef(-34.50, 0.75, 36.88);
		fig3.prisma(4, 8.8, 20, Arqui.GLindex);  
	glPopMatrix();
}

void DibujaCamino(){

	//GLuint x = Bici1.GLindex;

			glPushMatrix();//Camino islas Norte derecha recto  ***********************************************
				//("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
				glTranslatef(10,0,-10.5);
				fig3.prismamultitext4(0.1, 27.5, 1, 8, 1, 0, 0, 0 , 0, Bici1.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas Norte derecho diagonal
				glTranslatef(24.5,0,-7.75);
				glRotatef(110,0.0,1.0,0.0);
				glScalef(6.5,0.1,1);
				fig3.prisma2(Bici2.GLindex, 0);
			glPopMatrix();//

			glPushMatrix();//Camino islas Norte izquierdo diagonal
				glTranslatef(-22.5,0,-6.5);
				glRotatef(210,0.0,1.0,0.0);
				glScalef(6.5,0.1,1);
				fig3.prisma2(Bici2.GLindex, 0);
			glPopMatrix();//

			glPushMatrix();//Camino islas vertical abajo
				glTranslatef(18.75,0,28);
				glRotatef(90,0.0,1.0,0.0);
				glScalef(21,0.1,1);
				fig3.prisma2(Bici3.GLindex, 0);
			glPopMatrix();//

			glPushMatrix();//Camino islas derecha vertical **********************************************
				glTranslatef(25.5,0,2.5);
				fig3.prismamultitext4(0.1, 1, 15, 1, 5, 0, 0, 0, 0, Bici3.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas derecha vertical pedacito
				glTranslatef(25.5,0,11.25);
				fig3.prismamultitext4(0.1, 1, 3, 1, 1, 0, 0, 0, 0, Bici2.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas Norte izquierda recto  ***********************************************
				glTranslatef(-13.75,0,-8);
				fig3.prismamultitext4(0.1, 12.5, 1, 5, 1, 0, 0, 0, 0, Bici1.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas Norte paralela Arriba
				glTranslatef(-6.3,0,-9.6);
				glRotatef(41,0.0,1.0,0.0);
				glScalef(4,0.1,0.3);
				fig3.prisma2(Bici4.GLindex,0);
			glPopMatrix();//

			glPushMatrix();//Camino islas Norte paralela recta 
				glTranslatef(-4.15,0,-10.85);
				fig3.prismamultitext4(0.1, 1.45, 0.3, 1, 1, 0, 0, 0, 0, Bici1.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas Norte paralela Abajo
				glTranslatef(-5.1,0,-8.9);
				glRotatef(41,0.0,1.0,0.0);
				glScalef(4,0.1,0.3);
				fig3.prisma2(Bici4.GLindex,0);
			glPopMatrix();//

			glPushMatrix();//Camino islas Norte paralela recta Abajo
				glTranslatef(-7.2,0,-7.65);
				fig3.prismamultitext4(0.1, 1.45, 0.3, 1, 1, 0, 0, 0, 0, Bici1.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas sur derecha recto ***********************************************
				glTranslatef(11.25,0,13);
				fig3.prismamultitext4(0.1, 12.5, 1, 5, 1, 0, 0, 0, 0, Bici1.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas sur derecha recto pedacito
				glTranslatef(20,0,13);
				fig3.prismamultitext4(0.1, 10, 1, 5, 1, 0, 0, 0, 0, Bici1.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas sur derecha diagonal
				glTranslatef(3.75,0,11);
				glRotatef(125,0.0,1.0,0.0);
				glScalef(5.5,0.1,1);
				fig3.prisma2(Bici4.GLindex,0);
			glPopMatrix();//

			glPushMatrix();//Camino islas sur izquierda recto  *********************************************
				glTranslatef(-5,0,9);
				fig3.prismamultitext4(0.1, 15, 1, 8, 1, 0, 0, 0, 0, Bici1.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas sur izquierda diagonal
				glTranslatef(-18.6,0,8.2);
				glRotatef(173,0.0,1.0,0.0);
				glScalef(13,0.1,1);
				fig3.prisma2(Bici3.GLindex,0);
			glPopMatrix();//

			glPushMatrix();//Camino islas izquierda vertical *****************************************
				glTranslatef(-25,0,-1.5);
				fig3.prismamultitext4(0.1, 1, 7.3, 1, 4, 0, 0, 0, 0, Bici3.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas izquierda vertical diagonal
				glTranslatef(-32.5,0,7.5);
				glRotatef(50,0.0,1.0,0.0);
				glScalef(6,0.1,1);
				fig3.prisma2(Bici3.GLindex,0);
			glPopMatrix();//

			glPushMatrix();//Camino islas izquierda vertical 
				glTranslatef(-34.5,0,22.1);
				fig3.prismamultitext4(0.1, 1, 25, 1, 4, 0, 0, 0, 0, Bici3.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas izquierda vertical pedacito para triangulo
				glTranslatef(-25,0,4);
				fig3.prismamultitext4(0.1, 1, 7, 1, 4, 0, 0, 0, 0, Bici3.GLindex);
			glPopMatrix();//

			glPushMatrix();//Camino islas izquierda Triangulo ariba
				glTranslatef(-27.8,0,3.5);
				glRotatef(30,0.0,1.0,0.0);
				glScalef(7,0.1,1);
				fig3.prisma2(Bici3.GLindex,0);
			glPopMatrix();//

			glPushMatrix();//Camino islas izquierda Triangulo abajo
				glTranslatef(-27.8,0,6.3);
				glRotatef(-20,0.0,1.0,0.0);
				glScalef(7,0.1,1);
				fig3.prisma2(Bici2.GLindex,0);
			glPopMatrix();//

			glPushMatrix();    //CurvaDoble Sur Izquierda
				glTranslatef(17.55,0,13.1);
				glRotatef(-20,0.0,1.0,0.0);

				glPushMatrix();
					glTranslatef(0.36,0,0.26);
					glRotatef(-47,0.0,1.0,0.0);
					glScalef(0.5,0.1,1.25);
					//glRotatef(-23,0.0,1.0,0.0);
					fig3.pizza(techolab.GLindex,Bici5.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.23,0,0.07);
					glRotatef(-25,0.0,1.0,0.0);
					glScalef(0.5,0.1,1.1);
					//glRotatef(-23,0.0,1.0,0.0);
					fig3.pizza(techolab.GLindex,Bici5.GLindex);
				glPopMatrix();

				glPushMatrix();                //**************************
					glTranslatef(0,0,0);       //**************************
					glScalef(0.5,0.1,1.05);       //**************************
					//glRotatef(45,0.0,1.0,0.0);//*************************
					fig3.pizza(techolab.GLindex,Bici5.GLindex);           //**************************
				glPopMatrix();                 //**************************

				glPushMatrix();
					glTranslatef(-0.24,0,0.02);
					glRotatef(25,0.0,1.0,0.0);
					glScalef(0.5,0.1,1);
					//glRotatef(23,0.0,1.0,0.0);
					fig3.pizza(techolab.GLindex,Bici5.GLindex);
				glPopMatrix();

			glPopMatrix();

			glPushMatrix();    //CurvaDoble Sur Derecha
				glTranslatef(20.8,0,13.14);
				glRotatef(65,0.0,1.0,0.0);
				glScalef(0.75,1,0.75);

				glPushMatrix();
					glTranslatef(0.36,0,0.26);
					glRotatef(-47,0.0,1.0,0.0);
					glScalef(0.5,0.1,1.25);
					//glRotatef(-23,0.0,1.0,0.0);
					fig3.pizza(techolab.GLindex,Bici5.GLindex);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.23,0,0.07);
					glRotatef(-25,0.0,1.0,0.0);
					glScalef(0.5,0.1,1.1);
					//glRotatef(-23,0.0,1.0,0.0);
					fig3.pizza(techolab.GLindex,Bici5.GLindex);
				glPopMatrix();

				glPushMatrix();                //**************************
					glTranslatef(0,0,0);       //**************************
					glScalef(0.5,0.1,1.05);       //**************************
					//glRotatef(45,0.0,1.0,0.0);//*************************
					fig3.pizza(techolab.GLindex,Bici5.GLindex);           //**************************
				glPopMatrix();                 //**************************

				glPushMatrix();
					glTranslatef(-0.24,0,0.02);
					glRotatef(25,0.0,1.0,0.0);
					glScalef(0.5,0.1,1);
					//glRotatef(23,0.0,1.0,0.0);
					fig3.pizza(techolab.GLindex,Bici5.GLindex);
				glPopMatrix();

			glPopMatrix();

			//////////////////////////////////////Curva Arriba Izquierda
			glPushMatrix();		

				glTranslatef(-22.8,0,-6.9);
				glRotatef(-150,0.0,1.0,0.0);
				glScalef(1,1,0.6);
		
				glPushMatrix();
					glTranslatef(0,-0.1,0);
					//glRotatef(-150,0.0,1.0,0.0);
					//glScalef(1,1,0.6);
					fig3.medioCilindro(3.25,0.1,20,Bici5.GLindex);
				glPopMatrix();

				glPushMatrix();
					//glTranslatef(0,0.1,0);
					//glRotatef(-150,0.0,1.0,0.0);
					//glScalef(1,1,0.6);
					fig3.medioCilindro(2,0.1,20,islas1.GLindex);
				glPopMatrix();				

			glPopMatrix();
			///////////////////////////////////////////////////////////////////////////////////

			/////////////////////////////////////Curva Ingenieria Izquierda
			glPushMatrix();		

				glTranslatef(17,0,16.3);
				glRotatef(120,0,1,0);
				glScalef(1,1,0.6);

				glPushMatrix();
					glTranslatef(0,-0.1,0);
					//glRotatef(-150,0.0,1.0,0.0);
					//glScalef(1,1,0.6);
					fig3.medioCilindro(3.25,0.1,20,Bici5.GLindex);
				glPopMatrix();

				glPushMatrix();
					//glTranslatef(0.5,0,0);
					//glRotatef(-150,0.0,1.0,0.0);
					//glScalef(1,1,0.6);
					fig3.medioCilindro(2,0.1,20,islas1.GLindex);
				glPopMatrix();				

			glPopMatrix();
			///////////////////////////////////////////////////////////////////////////////////

			/////////////////////////////////////Curva Ingenieria Derecha
			glPushMatrix();		

				glTranslatef(20.5,0,16.3);
				glRotatef(-120,0,1,0);
				glScalef(1,1,0.6);

				glPushMatrix();
					glTranslatef(0,-0.1,0);
					//glRotatef(-150,0.0,1.0,0.0);
					//glScalef(1,1,0.6);
					fig3.medioCilindro(3.25,0.1,20,Bici5.GLindex);
				glPopMatrix();

				glPushMatrix();
					//glTranslatef(-22.8,0,-6.9);
					//glRotatef(-150,0.0,1.0,0.0);
					//glScalef(1,1,0.6);
					fig3.medioCilindro(2,0.1,20,islas1.GLindex);
				glPopMatrix();				

			glPopMatrix();
			
			glPushMatrix(); //Camino2
				glTranslatef(-5,0.0,45.0);
				glScalef(10,0.1,2.5);
				glDisable(GL_LIGHTING);
				fig3.prisma2(Bici5.GLindex, 0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

}

void BibliotecaCentral()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-43,4.5,-8);
		edificio.prismab(4,8,8,central.GLindex,central.GLindex,parteatras.GLindex,corniza.GLindex);//caja de en medio
		glTranslatef(3.75,-1,7);
		edificio.prisma(2,.5,6,piedra.GLindex);//muro izquierdo
		glTranslatef(-3.75,0,2.75);
		edificio.prisma(2,8,.5,piedrabc1.GLindex);//muro central
		glTranslatef(-3.75,0,-3);
		edificio.prisma(2,.5,6,piedrabc.GLindex);//muro derecha
		glTranslatef(-1.75,2.75,-6.75);
		edificio.prisma(.5,3,8,techot.GLindex);//techo puerta
		glTranslatef(-3.5,-2,0);
		edificio.prismabc(4.5,4,8,central.GLindex,central.GLindex,paredm.GLindex,central.GLindex,central.GLindex);//caja izquierda
		glTranslatef(5.5,8,0);
		edificio.prismabc(12,8,6,muralbc1.GLindex,muralbc.GLindex,muralbc1.GLindex,muralbc.GLindex,corniza.GLindex);//parte de arriba
		glTranslatef(0,6,1.5);
		edificio.prisma(3,4,2,corniza.GLindex);//caja de arriba
		glTranslatef(7.25,-15.5,-8.5);
		edificio.prisma(.5,.5,6,piedra.GLindex);//jardinera
		glTranslatef(-7.5,0,0);
		edificio.prisma(.5,.5,6,piedra.GLindex);//jardinera
		glTranslatef(-3.5,0,0);
		edificio.prisma(.5,.5,6,piedra.GLindex);//jardinera
		glTranslatef(-3.5,0,0);
		edificio.prisma(.5,.5,6,piedra.GLindex);//jardinera
		glTranslatef(1.5,0,-2.75);
		glRotatef(90,0,1,0);
		edificio.prisma(.5,.5,3.5,piedra.GLindex);//jardinera
		glTranslatef(0,0,9.25);
		edificio.prisma(.5,.5,7.25,piedra.GLindex);//jardinera
		glTranslatef(-10,1.5,-5);
		edificio.prismabc(4,7,4,piedram.GLindex,entrada1.GLindex,piedra.GLindex,entrada.GLindex,corniza.GLindex);
	glPopMatrix();
}

void pasilloRectoria()
{
	glPushMatrix();
	glColor3f(1,1,1);
		glTranslatef(-64.0,6.6,-4.5);
		salones.prisma(0.125,4.0,35.0,techo1.GLindex);
	glPopMatrix();
}

void Rectoria()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glPushMatrix();
			glTranslatef(-63,3,3);
			elevacion.prisma(2,12,56,pisoroj.GLindex);
			glTranslatef(6.5,0,0);
			escaleras.prisma(0.25,3,55.5,piedra.GLindex);
			glTranslatef(-1,0.5,0);
			escaleras.prisma(0.25,3,55.5,piedra.GLindex);
		glPopMatrix();
		glTranslatef(-65,16.5,23);
		edificio.prisma(25,8,12,rectoria.GLindex);//caja central
		glTranslatef(-1,0,-6.5);
		edificio.prisma(28,2,1,rectoriac.GLindex);//barra lateral
		glTranslatef(0.5,13,2.5);
		edificio.prisma(2,3,4,corniza.GLindex);//caja del techo
		glColor3f(.5,.5,.5);
		glTranslatef(4.5,-18,4);
		edificio.prisma(5,1,7,mural.GLindex);//mural
	glPopMatrix();
}

void planoRectoria()
{
	glPushMatrix();
		glTranslatef(-39,0.5,21);
		glPushMatrix();
			glRotatef(90,0,1,0);
			elevacion.prisma(4,19.5,.005,piedraplano.GLindex);
		glPopMatrix();

		glTranslatef(-.25,2.25,0);
		edificio.prisma(.5,.5,19,piedra.GLindex);//jardinera
		glTranslatef(-2.75,0,-9.75);
		glPushMatrix();
			glRotatef(90,0,1,0);
			edificio.prisma(.5,.5,6,piedra.GLindex);//jardinera
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,0,19.5);
			glRotatef(90,0,1,0);
			edificio.prisma(.5,.5,6,piedra.GLindex);//jardinera
		glPopMatrix();
		glPushMatrix();
			glColor3f(1,1,1);
			glTranslatef(-8,0,4);
			elevacion.prismarec(.005,10,30.5,pastorectoria.GLindex);
		glPopMatrix();
	glPopMatrix();
}

void Elevacion()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-54,0.5,-8);
		elevacion.prismabc(4,30,20,piedra.GLindex,pared.GLindex,piedra.GLindex,0,piedra.GLindex);
	glPopMatrix();
}

void acompletarbase()
{
	glPushMatrix();
		glColor3f(1,1,1);
		glTranslatef(-56,0.5,6);
		elevacion.prisma(4,26,10,piedra.GLindex);//detras de escaleras centrales
		glTranslatef(-1.0,0,-27.5);
		elevacion.prisma(4,24.3,7,piedra.GLindex);//detras de las escaleras de filosofia
		glPopMatrix();
}

void DibujaMontañas(){
	//////////////////////////MONATAÑA SUR//////////////////////////

	glPushMatrix();
			glTranslatef(13.2,-0.5,5);
			glScalef(3,1,1.5);
			fig3.esfera(1,20,20, text5.GLindex);
		glPopMatrix();

	//glPushMatrix();
			//glTranslatef(8,1.5,1);
			//fig3.esfera(1,20,20,0);
		//glPopMatrix();
	
	glPushMatrix();
		//glTranslatef(15,-0.8,6.5);
		//glScalef(1,1,2);

		glPushMatrix();
			glTranslatef(6,-1,6.5);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); 
			glTranslatef(15,-1,6.5);
			glRotatef(90,0,0,1);
			fig3.cilindro(1.5,9,70,text5.GLindex);
		glPopMatrix();


		glPushMatrix();
			glTranslatef(15,-1,6.5);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();	

		glPushMatrix(); //RECTANGULO
			glTranslatef(10.5,0,6);
			glScalef(9,1,1.3);
			fig3.prisma2(text5.GLindex,text5.GLindex);
		glPopMatrix();
		
		glPushMatrix();//Empieza segundo cilindro
			glTranslatef(6,-1,5.5);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); 
			glTranslatef(15,-1,5.5);
			glRotatef(90,0,0,1);
			fig3.cilindro(1.5,9,70,text5.GLindex);
		glPopMatrix();


		glPushMatrix();
			glTranslatef(15,-1,5.5);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();	


		glPushMatrix(); //Cilindro pequeño
			glTranslatef(15,-1,5.5);
			glRotatef(90,1,0,0);
			fig3.cilindro(1.5,1,70,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //Cilindro pequeño 2
			glTranslatef(6,-1,5.5);
			glRotatef(90,1,0,0);
			fig3.cilindro(1.5,1,70,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //Bola extra
			glTranslatef(7,-1,7);
			glScalef(1.2,1,1.2);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(10,-1,7);
			glScalef(2,1,2);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();
		

	glPopMatrix();

	//////////////////////////MONATAÑA NORTE DERECHA//////////////////////////
	
	glPushMatrix(); //Medio circulo con tapa 1
		
		glTranslatef(19,-1.5,-6);
		glRotatef(-90,0,1,0);
		glScalef(2,1,3);

		glPushMatrix();
			glTranslatef(0,1,0);
			glRotatef(90,0.6,0,0);
			fig3.cilindro(1,0.09,50,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //MEDIA ESFERA
			glTranslatef(0,1,0);
			glScalef(1,1,0.7);
			glRotatef(180,1,0,0);
			fig3.mediaEsfera(1,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix(); //Medio circulo con tapa 2
		
		glTranslatef(15,-1.6,-7);
		glRotatef(-15,0,1,0);
		glScalef(2.5,1,2);

		glPushMatrix();
			glTranslatef(0,1,0);
			glRotatef(90,0.6,0,0);
			fig3.cilindro(1,1.5,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //MEDIA ESFERA
			glTranslatef(0,1,0);
			glScalef(1,1,0.7);
			glRotatef(180,1,0,0);
			fig3.mediaEsfera(1,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Medio circulo con tapa 3
		
		glTranslatef(11,-1.6,-6);
		glRotatef(45,0,1,0);
		glScalef(3,1,3.5);

		glPushMatrix();
			glTranslatef(0,1,0);
			glRotatef(90,0.6,0,0);
			fig3.cilindro(1,0.5,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //MEDIA ESFERA
			glTranslatef(0,1,0);
			glScalef(1,1,0.7);
			glRotatef(180,1,0,0);
			fig3.mediaEsfera(1,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Medio circulo con tapa 4
		
		glTranslatef(10.4,-1.6,-4);
		glRotatef(-70,0,1,0);
		glScalef(2,1,5);

		glPushMatrix();
			glTranslatef(0,1,0);
			glRotatef(-90,1,0,0);
			fig3.cilindro(1,0.91,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //MEDIA ESFERA
			glTranslatef(0,1,0);
			glScalef(1,1,0.7);
			glRotatef(0,1,0,0);
			fig3.mediaEsfera(1,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //Medio circulo con tapa 5
		
		glTranslatef(14,-1.6,-3.5);
		glRotatef(15,0,1,0);
		glScalef(4,1,3);

		glPushMatrix();
			glTranslatef(0,1,0);
			glRotatef(-90,1,0,0);
			fig3.cilindro(1,0.5,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //MEDIA ESFERA
			glTranslatef(0,1,0);
			glScalef(1,1,0.7);
			glRotatef(0,1,0,0);
			fig3.mediaEsfera(1,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();

	//glPushMatrix();  //CONO
	//	glTranslatef(13.2,0.35,-5.2);
	//	glRotatef(5,0,1,0);
	//	glScalef(1.6,1,0.9);
	//	fig3.cono(0.1,2.5,100,0);
	//glPopMatrix();

	//glPushMatrix(); // Camino con DOS ESFERAS
	//	glTranslatef(15,-1.65,-6);
	//	glRotatef(90,1,0,0);
	//	glRotatef(-10,0,0,1);
	//	glScalef(1.6,1,1);
	//	fig3.cilindro(2,2.3,100,0);
	//glPopMatrix();

	glPushMatrix(); //Cilindro
		glTranslatef(18.7,-1.5,-7);
		glRotatef(90,1,0,0);
		glRotatef(-5,0,0,1);
		//glScalef(1.5,1,1);
		fig3.cilindro(2,2,100,text5.GLindex);
	glPopMatrix();

	glPushMatrix(); //Esfera del cilindro 1
		glTranslatef(18.7,-1,-7);
		glScalef(1.2,1,0.8);
		fig3.esfera(1.5,20,20,text5.GLindex);
	glPopMatrix();

	glPushMatrix(); //Esfera del cilindro 2
		glTranslatef(18.85,-1,-5);
		glScalef(1.2,1,0.8);
		fig3.esfera(1.5,20,20,text5.GLindex);
	glPopMatrix();

	//glPushMatrix();  // RECTANGULO
	//	glTranslatef(13,0,-4.8);
	//	glRotatef(15,0,1,0);
	//	glScalef(4.5,0.78,3.2);
	//	fig3.prisma2(0,0);
	//glPopMatrix();

	//glPushMatrix(); //Cilindro modificado
	//	glTranslatef(13,-1.5,-5.8);
	//	glRotatef(90,1,0,0);
	//	glRotatef(-9,0,0,1);
	//	glScalef(3,1.1,1);
	//	fig3.cilindro(2,2,100,0);
	//glPopMatrix();


	//glPushMatrix();
	//	glTranslatef(19,-0.7,-6);
	//	glScalef(1.7,1,1);

	//	glPushMatrix();
	//		glTranslatef(-9,0,0);
	//		fig3.esfera(1.5,20,20,0);
	//	glPopMatrix();

	//	glPushMatrix(); 
	//		//glTranslatef(15,-0.7,6.5);
	//		glRotatef(90,0,0,1);
	//		fig3.cilindro(1.5,9,70,0);
	//	glPopMatrix();

	//	glPushMatrix();
	//		glTranslatef(0,0,0);
	//		fig3.esfera(1.5,20,20,0);
	//	glPopMatrix();
	//glPopMatrix();

	//////////////////////////MONATAÑA NORTE IZQUIERDA//////////////////////////
	
	glPushMatrix();
		glTranslatef(-5.5,-1.5,-3);
		glRotatef(90,0,1,0);
		glScalef(1,1,2);
		fig3.esfera(2,20,20,text5.GLindex);
	glPopMatrix();

	//glPushMatrix(); //Montaña del centro
	//	glTranslatef(-5,-1,-3);
	//	fig3.esfera(2,20,20,0);
	//glPopMatrix();

	glPushMatrix();  //Cilindro de la parte derecha
		glTranslatef(-3.5,-1.3,-4.8);
		glRotatef(90,0,1,0);
		glScalef(0.4,1,1);

		glPushMatrix();
			glTranslatef(-9,0,0);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); 
			//glTranslatef(15,-0.7,6.5);
			glRotatef(90,0,0,1);
			fig3.cilindro(1.5,9,70,text5.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,0,0);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();  //Cilindro Izquierda arriba
		glTranslatef(-9.5,-1.3,-4.5);
		glRotatef(165,0,1,0);
		glScalef(0.4,1,1);

		glPushMatrix();
			glTranslatef(-9,0,0);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); 
			//glTranslatef(15,-0.7,6.5);
			glRotatef(90,0,0,1);
			fig3.cilindro(1.5,9,70,text5.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,0,0);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();  //Cilindro Izquierda abajo
		glTranslatef(-9.7,-1.3,-1.5);
		glRotatef(210,0,1,0);
		glScalef(0.3,1,1.3);

		glPushMatrix();
			glTranslatef(-9,0,0);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); 
			//glTranslatef(15,-0.7,6.5);
			glRotatef(90,0,0,1);
			fig3.cilindro(1.5,9,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,0,0);
			fig3.esfera(1.5,20,20,text5.GLindex);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix(); //esfera complemento
		glTranslatef(-3,-0.8,-3);
		glScalef(1,1,3);
		fig3.esfera(1,20,20,text5.GLindex);
	glPopMatrix();

	glPushMatrix(); //esfera complemento 2
		glTranslatef(-8,-0.8,-1.5);
		glRotatef(-60,0,1,0);
		glScalef(1,1,2.5);
		fig3.esfera(1,20,20,text5.GLindex);
	glPopMatrix();

	//glPushMatrix();
		//glTranslatef(-3,-0.7,-3);
		//glScalef(0.75,1,1);

	//	glPushMatrix();
	//		glTranslatef(-9,0,0);
	//		fig3.esfera(1.5,20,20,0);
	//	glPopMatrix();

		//glPushMatrix(); 
		//	//glTranslatef(15,-0.7,6.5);
		//	glRotatef(90,0,0,1);
		//	fig3.cilindro(1.5,9,70,0);
		//glPopMatrix();

	//	glPushMatrix();
	//		glTranslatef(0,0,0);
	//		fig3.esfera(1.5,20,20,0);
	//	glPopMatrix();
	//glPopMatrix();

	///////////////////////////////////MONTAÑA COPERATIVA///////////////////////
	
	glPushMatrix();

		//glPushMatrix();
		//	//glTranslatef(6,-1,6.5);
		//	fig3.esfera(1.5,20,20,0);
		//glPopMatrix();

		glPushMatrix(); //cilindro
			glTranslatef(1,-0.5,13);
			glRotatef(90,0,0,1);
			fig3.cilindro(1,5,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //rectangulo
			glTranslatef(-1.5,0,13.5);
			glScalef(5,1,1);
			fig3.prisma2(text5.GLindex,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //cilindro 2 
			glTranslatef(1,-0.5,14);
			glRotatef(90,0,0,1);
			fig3.cilindro(1,5,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //esfera1 del cilindro 2
			glTranslatef(1,-0.5,14);
			fig3.esfera(1,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //esfera2 del cilindro 2
			glTranslatef(-4,-0.5,14);
			fig3.esfera(1,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //esfera1 del cilindro 1
			glTranslatef(1,-0.5,13);
			fig3.esfera(1,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //esfera2 del cilindro 1
			glTranslatef(-4,-0.5,13);
			fig3.esfera(1,20,20,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //Cilindro pequeño
			glTranslatef(1,-0.5,13);
			glRotatef(90,1,0,0);
			fig3.cilindro(1,1,100,text5.GLindex);
		glPopMatrix();

		glPushMatrix(); //Cilindro pequeño 2
			glTranslatef(-4,-0.5,13);
			glRotatef(90,1,0,0);
			fig3.cilindro(1,1,100,text5.GLindex);
		glPopMatrix();

		//glPushMatrix();
		//	//glTranslatef(15,-1,6.5);
		//	fig3.esfera(1.5,20,20,0);
		//glPopMatrix();	

		//glPushMatrix(); //RECTANGULO
		//	//glTranslatef(10.5,0,6);
		//	glScalef(9,1,1.3);
		//	fig3.prisma2(0,0);
		//glPopMatrix();
		//
		//glPushMatrix();//Empieza segundo cilindro
		//	//glTranslatef(6,-1,5.5);
		//	fig3.esfera(1.5,20,20,0);
		//glPopMatrix();

		//glPushMatrix(); 
		//	//glTranslatef(15,-1,5.5);
		//	glRotatef(90,0,0,1);
		//	fig3.cilindro(1.5,9,70,0);
		//glPopMatrix();


		//glPushMatrix();
		//	//glTranslatef(15,-1,5.5);
		//	fig3.esfera(1.5,20,20,0);
		//glPopMatrix();	


		//glPushMatrix(); //Cilindro pequeño
		//	//glTranslatef(15,-1,5.5);
		//	glRotatef(90,1,0,0);
		//	fig3.cilindro(1.5,1,70,0);
		//glPopMatrix();

		//glPushMatrix(); //Cilindro pequeño 2
		//	//glTranslatef(6,-1,5.5);
		//	glRotatef(90,1,0,0);
		//	fig3.cilindro(1.5,1,70,0);
		//glPopMatrix();

	glPopMatrix();


}

void DibujaBolas(float a,float b,float c,float ang){
	
	//glPushMatrix(); 
	//	glTranslatef(0,0,0);
	//	glScalef(0.2,0.2,0.2);

	//	glPushMatrix(); //MEDIA ESFERA
	//		glTranslatef(0,1,0.5);
	//		glScalef(1,1,0.7);
	//		fig3.mediaEsfera(1,20,20,0);
	//	glPopMatrix();

	//	glPushMatrix();
	//		glTranslatef(0,1,0.5);
	//		glRotatef(90,1,0,0);
	//		fig3.cilindro(1,0.09,50,0);
	//	glPopMatrix();

	//	glPushMatrix(); //CILINDRO Medio
	//		glTranslatef(0,1,0);
	//		glRotatef(90,0.6,0,0);
	//		fig3.cilindro(0.87,0.5,50,0);
	//	glPopMatrix();

	//	glPushMatrix();
	//		glTranslatef(0,1,0);
	//		glRotatef(90,0.6,0,0);
	//		fig3.cilindro(1,0.09,50,0);
	//	glPopMatrix();

	//	glPushMatrix(); //MEDIA ESFERA
	//		glTranslatef(0,1,0);
	//		glScalef(1,1,0.7);
	//		glRotatef(180,1,0,0);
	//		fig3.mediaEsfera(1,20,20,0);
	//	glPopMatrix();
	//glPopMatrix();

	glPushMatrix(); //// BOLA MONTAÑA SUR
		glTranslatef(a,b,c);
		glRotatef(ang,0,1,0);
		glScalef(0.2,0.2,0.2);

		glPushMatrix(); //MEDIA ESFERA
			glTranslatef(0,1,0.5);
			glScalef(1,1,0.7);
			fig3.mediaEsfera(1,20,20,bola.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,1,0.5);
			glRotatef(90,1,0,0);
			fig3.cilindro(1,0.09,50,bola.GLindex);
		glPopMatrix();

		glPushMatrix(); //CILINDRO Medio
			glTranslatef(0,1,0);
			glRotatef(90,0.6,0,0);
			fig3.cilindro(0.87,0.5,50,bola.GLindex);
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0,1,0);
			glRotatef(90,0.6,0,0);
			fig3.cilindro(1,0.09,50,bola.GLindex);
		glPopMatrix();

		glPushMatrix(); //MEDIA ESFERA
			glTranslatef(0,1,0);
			glScalef(1,1,0.7);
			glRotatef(180,1,0,0);
			fig3.mediaEsfera(1,20,20,bola.GLindex);
		glPopMatrix();
	glPopMatrix();

}

void DibujaPasilloIslas(){ //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPushMatrix();	//Pasillo
		glTranslatef(14, 3, 18);
		fig3.prismamultitext(0.3, 34, 3, 7, 7, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, techolab.GLindex );
	glPopMatrix();

	glPushMatrix();	//Columnas Pasillo
		glTranslatef(28, 0, 17);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, 2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, -2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, 2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, -2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-4, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, 2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, -2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, 2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, -2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, 2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, -2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(0, 0, 2);
		fig3.cilindro(0.15, 3, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 4, 50, columAudi.GLindex);
		glTranslatef(0, 0, -2);
		fig3.cilindro(0.15, 4, 50, columAudi.GLindex);
		glTranslatef(-2.5, 0, 0);
		fig3.cilindro(0.15, 4, 50, columAudi.GLindex);
		glTranslatef(0, 0, 2);
		fig3.cilindro(0.15, 4, 50, columAudi.GLindex);
		glTranslatef(-3, 0, 0);
		fig3.cilindro(0.15, 4, 50, columAudi.GLindex);
		glTranslatef(0, 0, -2);
		fig3.cilindro(0.15, 4, 50, columAudi.GLindex);
	glPopMatrix();

	glPushMatrix();	//Pasillo 2 //("Atras", "Derecha", "Enfrente", "Izquierda", "Arriba")
		glTranslatef(-3.5, 4, 18);
		fig3.prismamultitext(0.3, 7, 3, 3, 3, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, columAudi.GLindex, techolab.GLindex );
	glPopMatrix();

	/*glPushMatrix();
		glRotatef(-90, 1, 0, 0);
		fig3.pizza(0,0);
	glPopMatrix();*/
}

void DibujaIngenieria(){
	glPushMatrix();	//Pared Islas
		//glColor3f(1, 0, 0);
		glTranslatef(5.5, 1.5, 27);
		fig3.prismamultitext(3.5, 16.2, 5, 5, 1, 0, paredfi.GLindex, paredislas2.GLindex, paredislas2.GLindex, techoalma.GLindex); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Pared rumbo al anexo
		//glColor3f(1, 1, 1);
		glTranslatef(12.5, 1.5, 36.4);
		fig3.prismamultitext2(3.5, 2, 15, 3, 1, 0, paredfi.GLindex, 0, 0, techoalma.GLindex);
	glPopMatrix();

	glPushMatrix();	//Pared Rejas Islas
		glTranslatef(-4, 0.6, 24.75);
		fig3.prismamultitext(1.5, 3, 0.5, 2, 1, 0, 0, paredislas.GLindex, 0, 0);
	glPopMatrix();

	glPushMatrix();	//Pared Rejas Estacionamiento FI
		glTranslatef(-5.72, 0.6, 28.5);
		fig3.prismamultitext(1.5, 0.5, 8, 1, 1, 0, 0, paredislas.GLindex, 0, 0);
	glPopMatrix();

	glPushMatrix();	//Base de la Biblioteca
		glTranslatef(9.5, 3.59, 27);
		fig3.prismamultitext(0.7, 4, 5, 5, 1, 0, basebiblio.GLindex, basebiblio.GLindex, basebiblio.GLindex, 0); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Biblioteca ADJ
		glTranslatef(9.5, 5.5, 27);
		fig3.prismamultitext(3, 5, 7, 2, 1, 0, biblio.GLindex, biblio.GLindex, biblio.GLindex, techobiblio.GLindex);
	glPopMatrix();

	glPushMatrix();	//Base de Laboratorios
		//glColor3f(1, 0, 1);
		glTranslatef(2, 1.5, 33.5);
		fig3.prismamultitext(3.5, 14, 9, 3, 1, 0, 0, biblio.GLindex, 0, techobiblio.GLindex);
	glPopMatrix();

	glPushMatrix();	//Laboratorios
		//glColor3f(1, 0.5, 0);
		glTranslatef(2, 4.25, 31.5);
		fig3.prismamultitext2(2, 9, 4, 3, 3, basebiblio.GLindex, basebiblio.GLindex, basebiblio.GLindex, basebiblio.GLindex, 0);
	glPopMatrix();

	glPushMatrix();	//techo Laboratorios
		//glColor3f(0, 0, 0);
		glTranslatef(2, 5.425, 31.5);
		fig3.prismamultitext(0.5, 10.5, 5.5, 5, 0, techofi.GLindex, techofi.GLindex, techofi.GLindex, techofi.GLindex, techofi.GLindex);
	glPopMatrix();

	glPushMatrix();	//Cuadros techo de Laboratorios
		//glColor3f(1, 0.5, 0.5);
		glTranslatef(5, 5.625, 30.5);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(0, 0, 2);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(0, 0, -2);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(0, 0, 2);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(0, 0, -2);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
		glTranslatef(0, 0, 2);
		fig3.prismamultitext2(0.5, 1, 1, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Bolas techo de Laboratorios
		//glColor3f(1, 1, 1);
		glTranslatef(5, 5.625, 30.5);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(0, 0, 2);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(0, 0, -2);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(0, 0, 2);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(0, 0, -2);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(-1.5, 0, 0);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
		glTranslatef(0, 0, 2);
		fig3.esfera(0.5, 10, 10, bolaslab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Edificio A
		//glColor3f(0, 0, 1);
		glTranslatef(10.5, 14.1, 35);
		fig3.prismamultitext2(1.87, 2, 16, 4, 4, 0, parededif.GLindex, edifa.GLindex, edifa.GLindex, edifa.GLindex);	//(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Edificio A
		glTranslatef(10.5, 12.12, 35);
		fig3.prismamultitext2(2.1, 2, 16, 4, 4, 0, parededif.GLindex, edifa.GLindex, edifa.GLindex, edifa.GLindex);	//(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Edificio A
		glTranslatef(10.5, 10.1, 35);
		fig3.prismamultitext2(2.1, 2, 16, 4, 4, 0, parededif.GLindex, edifa.GLindex, edifa.GLindex, edifa.GLindex);	//(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Edificio A
		glTranslatef(10.5, 3.08, 35);
		fig3.prismamultitext2(8, 2, 16, 3, 3, 0, barabdalfi.GLindex, edifa.GLindex, edifa.GLindex, edifa.GLindex);	//(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Edificio A
		glTranslatef(10.5, 8.08, 35);
		fig3.prismamultitext2(2.1, 2, 16, 4, 4, 0, parededif.GLindex, edifa.GLindex, edifa.GLindex, edifa.GLindex);	//(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Techo Edificio A
		glTranslatef(10, 14.9, 35);
		fig3.prismamultitext2(0.3, 3, 16, 1, 1, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex, techolab.GLindex);
	glPopMatrix();

	glPushMatrix();	//Base Piso 4 Edificio A
		glTranslatef(10, 13.18, 35);
		fig3.prisma(0.3, 3, 15, 0);
	glPopMatrix();

	glPushMatrix();	//Varandal Piso 4 Edificio A
		glTranslatef(8.375, 13.355, 34.8);
		fig3.prismamultitext2(0.65, 0.25, 15, 1, 5, 0, 0, tapafi.GLindex, tapafi.GLindex, 0); //(0, "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Tapa Piso 4 Edificio A
		glTranslatef(9.5, 13.35, 27.42);
		fig3.prismamultitext(0.65, 2, 0.2, 1, 1, 0, 0, tapafi.GLindex, 0, 0); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Base Piso 3 Edificio A
		glTranslatef(10, 11.28, 35);
		fig3.prisma(0.3, 3, 15, 0);
	glPopMatrix();

	glPushMatrix();	//Varandal Piso 3 Edificio A
		glTranslatef(8.375, 11.455, 34.8);
		fig3.prismamultitext2(0.65, 0.25, 15, 1, 5, 0, 0, tapafi.GLindex, tapafi.GLindex, 0); //(0, "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Tapa Piso 3 Edificio A
		glTranslatef(9.5, 11.45, 27.42);
		fig3.prismamultitext(0.65, 2, 0.2, 1, 1, 0, 0, tapafi.GLindex, 0, 0); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Base Piso 2 Edificio A
		glTranslatef(10, 9.18, 35);
		fig3.prisma(0.3, 3, 15, 0);
	glPopMatrix();

	glPushMatrix();	//Varandal Piso 2 Edificio A
		glTranslatef(8.375, 9.355, 34.8);
		fig3.prismamultitext2(0.65, 0.25, 15, 1, 5, 0, 0, tapafi.GLindex, tapafi.GLindex, 0); //(0, "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Tapa Piso 2 Edificio A
		glTranslatef(9.5, 9.35, 27.42);
		fig3.prismamultitext(0.65, 2, 0.2, 1, 1, 0, 0, tapafi.GLindex, 0, 0); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Base Piso 1 Edificio A
		glTranslatef(10, 7.18, 35);
		fig3.prisma(0.3, 3, 15, 0);
	glPopMatrix();

	glPushMatrix();	//Varandal Piso 1 Edificio A
		glTranslatef(8.375, 7.355, 34.8);
		fig3.prismamultitext2(0.65, 0.25, 15, 1, 5, 0, 0, tapafi.GLindex, tapafi.GLindex, 0); //(0, "Derecha", "Enfrente", "Izquierda", "Arriba")
	glPopMatrix();

	glPushMatrix();	//Tapa Piso 4 Edificio A
		glTranslatef(9.5, 7.35, 27.42);
		fig3.prismamultitext(0.65, 2, 0.2, 1, 1, 0, 0, tapafi.GLindex, 0, 0); //(0, "Derecha", "Enfrente", "Derecha", "Arriba")
	glPopMatrix();
}

//*********************************Ojo funcion temporal Animacion*********************************/
void monito(float pierna, float rodilla, GLuint camisa, GLuint pantalon , GLuint zapato)
{
	glPushMatrix();//Pecho
		glScalef(0.5, 0.5, 0.5);
		fig7.prisma(2.0 ,2.0 ,1 ,camisa);

		glPushMatrix();//Cuello
			glTranslatef(0, 1.0, 0.0);
			fig7.cilindro(0.25, 0.25, 15, textCara.GLindex);
			glPushMatrix();//Cabeza
				glTranslatef(0, 1.0, 0);
				glEnable(GL_TEXTURE_GEN_S); 
				glEnable(GL_TEXTURE_GEN_T);
					glTexGeni(GL_S, GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP); 
					glTexGeni(GL_T, GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP); 
					fig7.esfera(0.75, 15, 15, textCara.GLindex);
				glDisable(GL_TEXTURE_GEN_S); 
				glDisable(GL_TEXTURE_GEN_T);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo derecho-->
			glTranslatef(1.25, 0.65, 0);
			glEnable(GL_TEXTURE_GEN_S); 
			glEnable(GL_TEXTURE_GEN_T);
			fig7.esfera(0.5, 12, 12, camisa);
			glDisable(GL_TEXTURE_GEN_S); 
			glDisable(GL_TEXTURE_GEN_T);
			glPushMatrix();
				glTranslatef(0.25, 0, 0);
				glRotatef(-65, 0, 1, 0); 
				//glRotatef(brazo, 0, 1,0); 
				//glRotatef(holas,0,0,1);
				glTranslatef(0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, camisa);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Brazo izquierd<--
			glTranslatef(-1.25, 0.65, 0);
			glEnable(GL_TEXTURE_GEN_S); 
			glEnable(GL_TEXTURE_GEN_T);
				fig7.esfera(0.5, 12, 12, camisa);
			glDisable(GL_TEXTURE_GEN_S); 
			glDisable(GL_TEXTURE_GEN_T);
			glPushMatrix();
				glTranslatef(-0.25, 0, 0);
				glRotatef(65, 0, 1, 0); 
				//glRotatef(brazoi, 0, 0, 1);
				glTranslatef(-0.75, 0, 0);
				fig7.prisma(0.7, 1.5, 0.7, camisa);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//Cintura
			glColor3f(0, 0, 1);
			glTranslatef(0, -1.5, 0);
			fig7.prisma(1, 2, 1, pantalon);

			glPushMatrix(); //Pie Derecho -->
				glTranslatef(0.75, -0.5, 0);
				glRotatef(pierna, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, pantalon);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(rodilla, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, pantalon);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, zapato);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();


			glPushMatrix(); //Pie Izquierdo -->
				glTranslatef(-0.75, -0.5, 0);
				glRotatef(pierna, 1, 0, 0);
				glTranslatef(0, -0.5, 0);
				fig7.prisma(1.0, 0.5, 1, pantalon);

				glPushMatrix();
					glTranslatef(0, -0.5, 0);
					glRotatef(rodilla, 1, 0, 0);
					glTranslatef(0, -0.75, 0);
					fig7.prisma(1.5, 0.5, 1, pantalon);

					glPushMatrix();
						glTranslatef(0, -0.75, 0.3);
						fig7.prisma(0.2, 1.2, 1.5, zapato);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
			
		glPopMatrix();

		glColor3f(1, 1, 1);
	glPopMatrix();
	
}

void animacion()
{
	int veces;

	letrero.text_izq-= 0.1;//animacion para el offset
	letrero.text_der-= 0.1;
	if(letrero.text_izq<-1)
		letrero.text_izq=0;
	if(letrero.text_der<0)
		letrero.text_der=1;
	glutPostRedisplay();

	//animacion del ave
	if(volar)
	{
		if(recorreA)
		{
			rotAve=0;
			maX +=1.5;
			if(maX>30)
			{
				recorreA = false;
				recorreB = true;
			}
		}
		if(recorreB)
		{
			rotAve = 90;
			maZ-=1.5;
			if(maZ<-30)
			{
				recorreB = false;
				recorreC = true;
				
			}
		}
		if(recorreC)
		{
			rotAve = 180;
			maX -=1.5;
			if(maX<-30)
			{
				recorreC = false;
				recorreD = true;
			}
		}
		if(recorreD)
		{
			rotAve = 270;
			maZ +=1.5;
			if(maZ>30)
			{
				recorreD = false;
				recorreE = true;
			}
		}
		if(recorreE)
		{
			rotAve = 45;
			maZ --;
			maX ++;
			if(maZ<-30)
			{
				recorreE = false;
				recorreF = true;
			}
		}
		if(recorreF)
		{
			rotAve = 225;
			maX --;
			maZ ++;
			if(maZ>30)
			{
				recorreF = false;
				recorreA = true;
			}
		}
		if(caminar)//animacion para el perro
	{
		if(caminoA)
		{
			rotCP=0;
			pX +=0.5;
			if(pX>10)
			{
				caminoA = false;
				caminoB = true;
			}
		}
		if(caminoB)
		{
			rotCP = 90;
			pZ-=0.5;
			if(pZ<-10)
			{
				caminoB = false;
				caminoC = true;
				
			}
		}
		if(caminoC)
		{
			rotCP = 180;
			pX -=0.5;
			if(pX<-10)
			{
				caminoC = false;
				caminoD = true;
			}
		}
		if(caminoD)
		{
			rotCP = 270;
			pZ +=0.5;
			if(pZ>10)
			{
				caminoD = false;
				caminoA = true;
			}
		}
	}

	if(avanzar)//podadora
	{
		if(cpA)
		{
			rotP=270;
			podaX +=0.1;
			if(podaX>4)
			{
				cpA = false;
				cpB = true;
			}
		}
		if(cpB)
		{
			rotP = 0;
			podaZ-=0.1;
			if(podaZ<-2)
			{
				cpB = false;
				cpC = true;
				
			}
		}
		if(cpC)
		{
			rotP = 90;
			podaX -=0.1;
			if(podaX<-4)
			{

				cpC = false;
				cpD = true;
			}
		}
		if(cpD)
		{
			rotP = 180;
			podaZ +=0.1;
			if(podaZ>2)
			{
				cpD = false;
				cpA = true;
			}
		}
	}
}

/*************Elicop********************/
	if(caminarv)//animacion para el perro
	{
		if(caminovA)
		{
			rotvP=0;
			vX +=0.5;
			if(vX>10)
			{
				caminovA = false;
				caminovB = true;
			}
		}
		if(caminovB)
		{
			rotvP = 180;
			vZ-=0.5;
			if(vZ<-10)
			{
				caminovB = false;
				caminovC = true;
				
			}
		}
		if(caminovC)
		{
			rotvP = 180;
			vX -=0.5;
			if(pX<-10)
			{
				caminovC = false;
				caminovD = true;
			}
		}
		if(caminovD)
		{
			rotvP = 270;
			vZ +=0.5;
			if(vZ>10)
			{
				caminovD = false;
				caminovA = true;
			}
		}
	}
	/**************Elicop+++++++++++++++++++*/
	
	
	//animacion monito
	if(hola){
		avX-=0.1;
		if(avX<-17){
			hola=false;
			camina1=true;

		}
	}		
	if(camina1){
		rotM=90;
		avZ+=0.1;
		if(avZ>10.0){
			camina1=false;
			entra=true;
		}
	}
	if(entra){
		rotM=360;
		avX-=0.1;
		if(avX<-31.5){
			entra=false;
			sentar=true;
		}
	}
	if(sentar){
		rotM=90;
		rotPiernas=-90;
		rotRodillas=90;
		avZ=9.5;
		avY=-3;
	}
	//Movimiento del monito

	if(play)
	{		
		
		if(	(abs(KeyFrame[playIndex+1].posX-posX))<0.1 &&
			(abs(KeyFrame[playIndex+1].posY-posY))<0.1 &&
			(abs(KeyFrame[playIndex+1].posZ-posZ))<0.1
			&&
			(abs(KeyFrame[playIndex+1].rotRodIzq-rotRodIzq))<0.1
			)
		{			
			playIndex++;			
			if(playIndex>FrameIndex-2)
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
		}
		else
		{
			KeyFrame[playIndex].incX=(KeyFrame[playIndex+1].posX-KeyFrame[playIndex].posX)/100;		//100 frames
			KeyFrame[playIndex].incY=(KeyFrame[playIndex+1].posY-KeyFrame[playIndex].posY)/100;		//100 frames
			KeyFrame[playIndex].incZ=(KeyFrame[playIndex+1].posZ-KeyFrame[playIndex].posZ)/100;		//100 frames
			posX+=KeyFrame[playIndex].incX;
			posY+=KeyFrame[playIndex].incY;
			posZ+=KeyFrame[playIndex].incZ;

			KeyFrame[playIndex].rotInc=(KeyFrame[playIndex+1].rotRodIzq-KeyFrame[playIndex].rotRodIzq)/100;		//100 frames
			KeyFrame[playIndex].giroMonitoInc=(KeyFrame[playIndex+1].giroMonito-KeyFrame[playIndex].giroMonito)/100;		//100 frames
			rotRodIzq+=KeyFrame[playIndex].rotInc;

		}
		
	}

	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {

//		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}

	glutPostRedisplay();
}

void libros()
{
	glPushMatrix();
		glTranslatef(-50,6.0,5);
		letrero.prismal(2.0,0.125,2.5,libro.GLindex,techo1.GLindex);//letrero superior
		glTranslatef(0,-1.5,0);
		letrero.prismal2(1.0,0.125,2.5,flecha.GLindex,techo1.GLindex);//letrero inferior flecha offset
		glTranslatef(0,-1.5,0);
		letrero.prisma(2.0,0.125,0.5,techo1.GLindex);//poste
	glPopMatrix();
}

//***********************************************************************************************


void arbol1()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0, 20.0, 0.0);
					glEnd();
				
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

void arbol2()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree2.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0, 20.0, 0.0);
					glEnd();
				
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

void torreArqui1(){
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On      //
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//
					glBindTexture(GL_TEXTURE_2D, torreArqui.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0, 20.0, 0.0);
					glEnd();
				
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-11,12.0,-14.0,(void *)font,"Proyecto Final");
			pintaTexto(-11,10.5,-14,(void *)font,"Ciudad Universitaria");
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);

	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 200.0, 200.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			

			
			DibujaBolas(15,0.5,5.3,0);
			DibujaBolas(3,0,6,10);
			DibujaBolas(18,0,7,20);
			DibujaBolas(9,0.4,8,30);
			DibujaBolas(-5,0.25,-4,40);
			DibujaBolas(-11,0,-6,50);
			DibujaBolas(0,0,5,60);
			DibujaBolas(-7,0,-6.5,70);
			DibujaBolas(16,0,4.5,80);
			DibujaBolas(-12,0,-4,90);
			DibujaBolas(1,0,3,100);
			DibujaBolas(-10,0,-3.5,110);
			DibujaBolas(2,0,-6,120);
			DibujaBolas(-14,0,3,130);
			DibujaBolas(17,0,4,140);
			DibujaBolas(-13,0,2,150);
			DibujaBolas(15.5,0.3,-7,160);
			DibujaBolas(-3.5,0,7.5,170);
			DibujaBolas(6.5,0,-4.5,180);
			DibujaBolas(-2.5,0,-7,50);
			DibujaBolas(10.5,0.4,8,10);
			DibujaBolas(11,0.4,-5,30);
			DibujaBolas(12.5,0.4,-6,40);
			DibujaBolas(13.5,0,3.5,10);
			DibujaBolas(18,0.4,-5,90);
			DibujaBolas(19,0.4,-7,120);

			/************Animacion*****************/
							/*glPushMatrix();
								glScalef(1.7f,1.7f,1.7f);
								glTranslatef( maX, 0.9f,maZ);
								glRotatef(180, 0.0f, 1.0f, 0.0f);
								glRotatef( 10, 1.0f, 0.0f, 0.0f);
								monito(0, 0,textCamisa.GLindex, textPantalon.GLindex, textZapato.GLindex);
							glPopMatrix();

						*/

						glPushMatrix();
							glDisable(GL_LIGHTING);
							glColor3f(0.25f,0.12f,0.12);
							glTranslatef(maX, 25.0f, maZ);
							glRotatef(rotAve, 0, 1, 0);
							glScalef( 0.10f, 0.09f, 0.10f);
							animal.GLrender(NULL,_SHADED,1.0);
							glEnable(GL_LIGHTING);
						glPopMatrix();

						glPushMatrix();//podadora
							glDisable(GL_LIGHTING);
							glTranslatef(-49.5,3,5.25);
							glColor3f(0.5f,1.f,0.5);
							glTranslatef(podaX, 0.0f, podaZ);
							glRotatef(rotP, 0, 1, 0);
							glScalef( 0.03f, 0.03f, 0.03f);
							podadora.GLrender(NULL,_SHADED,1.0);
							glEnable(GL_LIGHTING);
						glPopMatrix();

						glPushMatrix();//perro
							glDisable(GL_LIGHTING);
							glColor3f(0.25f,0.12f,0.12);
							glTranslatef(pX, 1.0f, pZ);
							glRotatef(rotCP, 0, 1, 0);
							glScalef( 0.00004f, 0.00004f, 0.00004f);
							perro.GLrender(NULL,_SHADED,1.0);
							glEnable(GL_LIGHTING);
						glPopMatrix();
						/*Eliiii*/
						glDisable(GL_LIGHTING);
							//glColor3f(0.0f,0.0f,0.0);
							glTranslatef(30.5,7,10.25);
							//glColor3f(0.0f,1.f,0.0);
							glTranslatef(vX, 10.0f, vZ);
							glRotatef(rotvP, 0, 1, 0);
							glScalef( 0.005f, 0.006f, 0.008f);
							pruebax.GLrender(NULL,_SHADED,1.0);
							glDisable(GL_LIGHTING);
						glPopMatrix();
						//arbol 1
					/*	glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef( 28.0f, 0.1f, 3.0f);
							glScalef( 0.06f, 0.05f, 0.02f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						// arbol2
						glPushMatrix();
							glColor3f(0.25f,0.12f,0.12);
							glTranslatef(28.0f, 0.1f, -2.0f);
							glScalef( 0.05f, 0.019f, 0.02f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						glPushMatrix();
						glColor3f(0.1f,0.22f,0.12);
							glTranslatef(28.0f, 0.1f, 0.0f);
							glScalef( 0.05f, 0.019f, 0.02f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						glPushMatrix();
						glColor3f(0.1f,0.22f,0.12);
							glTranslatef(28.0f, 0.1f, 5.0f);
							glScalef( 0.0f, 0.019f, 0.05f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						/*arbol 1 frente a derecho */
						/*glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(9.0f, 0.1f, -17.0f);
							glScalef( 0.02f, 0.049f, 0.02f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(11.0f, 0.1f, -19.0f);
							glScalef( 0.06f, 0.08f, 0.04f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();



						glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(0.0f, 0.1f, -18.0f);
							glScalef( 0.06f, 0.07f, 0.05f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(-10.0f, 0.1f, -18.0f);
							glScalef( 0.06f, 0.05f, 0.08f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						//montaña frente auditorio
						
						glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(15.0f, 0.1f, -7.0f);
							glScalef( 0.08f, 0.09f, 0.05f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(14.0f, 0.1f, -5.0f);
							glScalef( 0.03f, 0.06f, 0.05f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(11.0f, 0.1f, -4.0f);
							glScalef( 0.03f, 0.04f, 0.06f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

						glPushMatrix();
							glColor3f(0.1f,0.22f,0.12);
							glTranslatef(9.0f, 0.1f, -6.0f);
							glScalef( 0.03f, 0.04f, 0.06f);
							arbusto.GLrender(NULL,_SHADED,1.0);
						glPopMatrix();

					/*************Animacion************************/

			//arbol1();
			//torreArqui1();
			////////////////////////////////EMPIEZAN LOS ARBOLES/////////////////////

			glPushMatrix(); //Arboles de montaña sur
				glTranslatef(5,0,5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();


			glPushMatrix();
				glTranslatef(6.5,0.5,6.5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(8,0.5,6);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(9.5,0.2,4.5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(11,0.4,7);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(12.5,0.5,6);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14,0.1,7.5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(15,0.5,6);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();
			//*****************************************************

			glPushMatrix();  //Arboles de montaña norte derecha
				glTranslatef(8,0,-3);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(9,0,-8);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(10,0,-2);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(11,0.5,-6);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(12,0.5,-1);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(13,0.5,-5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14,0.5,-2.5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(15,0.5,-7);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();
			////////**********************************************
			glPushMatrix();  // Arboles de montaña norte izquierda
				glTranslatef(-2.5,0,-1);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-3.5,0.1,-4);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-5,0.5,-3);
				glScalef(0.2,0.3,0.2);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-6,0.2,-2);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-7,0.1,-3.5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-8,0.1,-1.5);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-9,0.1,-3.8);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			////////////////////////////////////////////////////////Arboles derecho
			glPushMatrix();
				glTranslatef(-18,0,-19);
				glScalef(0.15,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-16,0,-17);
				glScalef(0.20,0.20,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-11,0,-19);
				glScalef(0.20,0.20,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-10,0,-17);
				glScalef(0.10,0.10,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-6.5,0,-15);
				glScalef(0.10,0.10,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-1,0,-19);
				glScalef(0.10,0.20,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1,0,-17);
				glScalef(0.15,0.20,0.05);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(4,0,-14);
				glScalef(0.25,0.20,0.1);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(9,0,-19);
				glScalef(0.05,0.10,0.25);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(11,0,-17);
				glScalef(0.10,0.13,0.12);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(14,0,-16);
				glScalef(0.25,0.19,0.20);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(16,0,-14);
				glScalef(0.15,0.10,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(18,0,-19);
				glScalef(0.2,0.2,0.30);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(18,0,-17);
				glScalef(0.05,0.3,0.25);
				arbol1();
			glPopMatrix();
			////////////////////////////////Arboles DGOSA
			glPushMatrix();
				glTranslatef(-3,0,14);
				glScalef(0.05,0.3,0.3);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-1,0,15);
				glScalef(0.1,0.1,0.2);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1,0,13.5);
				glScalef(0.1,0.2,0.1);
				arbol1();
			glPopMatrix();

			/////////////////////////////Arboles Arqui

			glPushMatrix();
				glTranslatef(-19,3.5,29);
				glScalef(0.05,0.3,0.3);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-19.5,3.5,30);
				glScalef(0.15,0.25,0.2);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-20.5,3.5,29);
				glScalef(0.1,0.1,0.1);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-21,3.5,30);
				glScalef(0.05,0.15,0.15);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-22,3.5,29);
				glScalef(0.15,0.5,0.3);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-23,3.5,30);
				glScalef(0.20,0.1,0.25);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-24.5,3.5,29);
				glScalef(0.05,0.3,0.3);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-25.5,3.5,30);
				glScalef(0.15,0.2,0.2);
				arbol1();
			glPopMatrix();

			////////////////////////////////Arboles auditorio

			glPushMatrix();
				glTranslatef(28,0,-5);
				glScalef(0.15,0.2,0.2);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(30,0,-5);
				glScalef(0.05,0.3,0.3);
				arbol1();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(32,0,-5);
				glScalef(0.2,0.1,0.3);
				arbol1();
			glPopMatrix();
			/////////////////////////////////////TERMINAN ARBOLES/////////////////////////////

			DibujaPosgradoDerecho();
			DibujaEdificioCDerecho();
			DibujaBiciPumaDerecho();
			DibujaIngenieria();
			DibujaBiciPumaIng();
			DibujaPasilloIslas();
			DibujaDGOSA();
			DibujaArquitectura();
			auditorioDiseInd();
			DisenoIndustrial();
			dibujaJardin();
			DibujaCamino();
			DibujaPasto();
			DibujaMontañas();
			DibujaHumanidades();
			CuboDerecho1();//lado derecho pegado a humanidades
			CuboDerecho2();//primer patron amarillo
			glPushMatrix();
				glTranslatef(-18,0,0);
				CuboDerecho1();//cubo de en medio
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-18,0,0);
				CuboDerecho2();//segundo patron amarillo
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-36,0,0);
				CuboDerecho1();//cubo de la izquierda
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-36,0,0);
				CuboDerecho2();//Filosofia
			glPopMatrix();
			PilaresDerecho();
			glPushMatrix();
				glTranslatef(0,0,-5);
				PilaresDerecho();
			glPopMatrix();
			comidaf();
			filosofia();
			Jardinera();
			glPushMatrix();
				glTranslatef(-10,0,0);
				Jardinera();
				glTranslatef(-10,0,0);
				Jardinera();
			glPopMatrix();
			columnas();
			glPushMatrix();
				glTranslatef(0,0,-3);
				columnas();
				glTranslatef(-2,0,0);
				columnas();
				glTranslatef(-2,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
			glPopMatrix();
			Elevacion();
			acompletarbase();
			glPushMatrix();
				glTranslatef(0,0,29);
				Elevacion();
			glPopMatrix();
			escalerasfilosofia();
			glPushMatrix();
				glTranslatef(0,0,28.5);
				escalerascentral();
			glPopMatrix();
			pasillo();
			glPushMatrix();
				glTranslatef(-18,2.9,-0.5);
				columnas();
				glTranslatef(0,0,-3);
				columnas();
				glTranslatef(-2,0,3);
				columnas();
				glTranslatef(0,0,-3);
				columnas();
				glTranslatef(-2,0,3);
				columnas();
				glTranslatef(0,0,-3);
				columnas();
				glTranslatef(-2,0,3);
				columnas();
				glTranslatef(0,0,-3);
				columnas();
			glPopMatrix();
			Rectoria();
			BibliotecaCentral();
			pasilloRectoria();
			glPushMatrix();
				glTranslatef(-35,4.5,-2);
				columnas();
				glTranslatef(-3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(-3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(-3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(-3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(-3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(-3,0,0);
				columnas();
				glTranslatef(0,0,3);
				columnas();
				glTranslatef(3,0,0);
				columnas();
			glPopMatrix();
			planos();
			glPushMatrix();
				glTranslatef(-62,-1,2);
				DibujaBiciPumaDerecho();
			glPopMatrix();
			planoRectoria();
			glColor3f(1.0,1.0,1.0);
			libros();
			nombres1();

		glPopMatrix();


	glutSwapBuffers ( );

}
/************agrgadas animacion mono*******/
void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:
			if(FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n",FrameIndex);			
				/*KeyFrame[FrameIndex].ang1=ang1;
				KeyFrame[FrameIndex].ang2=ang2;
				KeyFrame[FrameIndex].ang3=ang3;
				KeyFrame[FrameIndex].ang4=ang4;*/

				KeyFrame[FrameIndex].posX=posX;
				KeyFrame[FrameIndex].posY=posY;
				KeyFrame[FrameIndex].posZ=posZ;

				KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
				
				FrameIndex++;
			}
		
			break;

		case 1:
			if(play==false && FrameIndex >1)
			{
				posX=KeyFrame[0].posX;
				posY=KeyFrame[0].posY;
				posZ=KeyFrame[0].posZ;

				rotRodIzq=KeyFrame[0].rotRodIzq;
				
				play=true;
				playIndex=0;
			}
			else
			{
				play=false;
			}
			break;
	}
}

void menu( int id)
{
	switch (id)
	{
		case 1:
			//g_fanimacion^= true; //Activamos/desactivamos la animacíon
			break;
	}
}

/*************fin anima mono************/
/*void animacion()
{
	fig3.text_izq-= 0.01;
	fig3.text_der-= 0.01;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;
	glutPostRedisplay();
}*/

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'r':		//
		case 'R':
			objCamera.UpDown_Camera(CAMERASPEED);
			break;

		case 'f':		//
		case 'F':
			objCamera.UpDown_Camera(-CAMERASPEED);
			break;
		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				printf("frameindex %d\n",FrameIndex);			
				
				KeyFrame[FrameIndex].posX=posX;
				KeyFrame[FrameIndex].posY=posY;
				KeyFrame[FrameIndex].posZ=posZ;

				KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
				
				FrameIndex++;
			}
			
			break;

		case 'l':						
		case 'L':
			if(play==false && (FrameIndex>1))
			{
				//ang1=KeyFrame[0].posX;
				//ang2=KeyFrame[0].posY;
				//ang3=KeyFrame[0].posZ;
				//ang4=KeyFrame[0].ang4;


				posX=KeyFrame[0].posX;
				posY=KeyFrame[0].posY;
				posZ=KeyFrame[0].posZ;

				rotRodIzq=KeyFrame[0].rotRodIzq;
				
				play=true;
				playIndex=0;
			}
			else
			{
				play=false;
			}
			break;

		case 'y':						
		case 'Y':
			posZ++;
			//printf("%f \n", posZ);
			break;

		case 'g':						
		case 'G':
			posX--;
			//printf("%f \n", posX);
			break;

		case 'h':						
		case 'H':
			posZ--;
			//printf("%f \n", posZ);
			break;

		case 'j':						
		case 'J':
			posX++;
			//printf("%f \n", posX);
			break;

		case 'b':						
			//camina = false;
			//printf("%f \n", rotRodIzq);
			break;

		case 'B':						
			//camina = true;
			break;

		case 'p':						
			break;

		case 'P':						
			break;

		case 'm':   //Movimientos de brazo
			break;

		case 'M':   //Movimientos de brazo
			break;

		case 'T':		//  
		case 't':
				volar=false;
			break;
		case 'n':		//  
		case 'N':
				volar=true;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 9"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
