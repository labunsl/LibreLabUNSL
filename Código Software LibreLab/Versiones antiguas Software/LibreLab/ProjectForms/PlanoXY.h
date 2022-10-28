#pragma once

#include <vector>

using namespace System::Drawing;

typedef struct Est1{
	float time;
	float data;
} Muestra;

typedef struct EstGrafica {
	bool flagActiva;
	bool flagVisible;
	float tiempoUlt;
	int periodo;
	int colorPun;
	int colorLin;
	int colorBar;
} Grafica;

typedef struct EstZoom {
	int selIniX;
	int selIniY;
	int selFinX;
	int selFinY;
	bool flagAutoAju;
} Zoom;

class PlanoXY{

private:
	int gMargX = 5, gMargY = 5, gMinX = 0, gMinY = 0, gMaxX = 800, gMaxY = 600;
	int espX = 10, espY = 20, tamBarra = 8;
	float factor = 10, porcVacioSup = 0.2, datoMax=0,tiempoUlt;

	int grillaX = 10, grillaY = 10;
	int tamMuestra = 5;

	Point regIni, regFin, rangoIni, rangoFin;
	bool regActivado;

	bool flagPuntos,flagLineas,flagGrilla,flagAutoAjuste, flagBarras;
	bool selMuestro;
	Point selIni, selFin;

	std::vector<Muestra> vecMuestras1,vecMuestras2;
	std::vector<Grafica> vecGraficas;
	std::vector<Zoom> vecZoom;

	int estS1, estS2;

	void limpiarDatos() {
		rangoIni.X = -2;
		rangoIni.Y = -2;
		rangoFin.X = 32;
		rangoFin.Y = 32;
		tiempoUlt = 0;
	}

	int getTamVecMuestras(int posGra) {
		int tam = -1;
		switch (posGra) {
		case 1: tam = vecMuestras1.size(); break;
		case 2: tam = vecMuestras2.size(); break;
		}
		return tam;
	}
	Muestra getMuestra(int posGra, int posMuestra) {
		Muestra muestra;
		muestra.time = 0;
		muestra.data = 0;
		switch (posGra) {
		case 1: {
			if (posMuestra < vecMuestras1.size()) {
				muestra = vecMuestras1.at(posMuestra);
			}			
			break; 
		}
		case 2: {
			if (posMuestra < vecMuestras2.size()) {
				muestra = vecMuestras2.at(posMuestra);
			}
			break; 
		}
		}
		return muestra;
	}
	void cargarGrafica(bool flagActiva, bool flagVisible, int colorPun, int colorLin, int colorBar) {
		Grafica nuevaGrafica;
		nuevaGrafica.flagActiva = flagActiva;
		nuevaGrafica.flagVisible = flagVisible;
		nuevaGrafica.tiempoUlt = 0;
		nuevaGrafica.periodo = 1000;
		nuevaGrafica.colorPun = colorPun;
		nuevaGrafica.colorLin = colorLin;
		nuevaGrafica.colorBar = colorBar;
		vecGraficas.push_back(nuevaGrafica);
	}
	Color obtenerColor(int col) {
		switch (col) {
		case 1: return Color::Red; break;
		case 2: return Color::DarkRed; break;
		case 3: return Color::LightCoral; break;
		case 4: return Color::Blue; break;
		case 5: return Color::DarkBlue; break;
		case 6: return Color::LightBlue; break;
		default: return Color::Black; break;
		}
	}

public:
	PlanoXY() {
		limpiarDatos();

		regIni.X = 0;
		regIni.Y = 0;
		regFin.X = gMaxX;
		regFin.Y = gMaxY;

		flagPuntos = true;
		flagLineas = true;
		flagGrilla = true;
		flagAutoAjuste = true;
		flagBarras = false;

		selMuestro = false;

		cargarGrafica(true, true,1,2,3);
		cargarGrafica(true, true,4,5,6);
		tiempoUlt = 0;

		estS1 = 0;
		estS2 = 0;
	};
	~PlanoXY() {};

	void agregarMuestra(int posGra, float nuevoDato) {

		Muestra puntoActual;
		switch (posGra) {
		case 1: 
			if ((vecMuestras1.size() == 0) && (vecMuestras2.size() != 0)) {
				vecGraficas[0].tiempoUlt = vecGraficas[1].tiempoUlt - (vecGraficas[0].periodo * 0.001);
			}
			puntoActual.time = vecGraficas[0].tiempoUlt + (vecGraficas[0].periodo * 0.001);
			puntoActual.data = nuevoDato;
			vecMuestras1.push_back(puntoActual); 
			printf("1	planoXY->agregarMuestra(%d,%f);\n", puntoActual.time, puntoActual.data);

			vecGraficas[0].tiempoUlt = puntoActual.time;

			break; 
		case 2:
			if ((vecMuestras2.size() == 0) && (vecMuestras1.size() != 0)) {
				vecGraficas[1].tiempoUlt = vecGraficas[0].tiempoUlt - (vecGraficas[1].periodo * 0.001);
			}
			puntoActual.time = vecGraficas[1].tiempoUlt + (vecGraficas[1].periodo * 0.001);
			puntoActual.data = nuevoDato;
			vecMuestras2.push_back(puntoActual);
			printf("2	planoXY->agregarMuestra(%d,%f);\n", puntoActual.time, puntoActual.data);

			vecGraficas[1].tiempoUlt = puntoActual.time;

			break; 		
		}
		

		if (flagAutoAjuste) {
			if (rangoFin.X < puntoActual.time) {
				rangoFin.X += 20;
				//printf("	rangoFin.X += 20; %d\n", rangoFin.X);
			}
			if (rangoFin.Y < puntoActual.data) {
				rangoFin.Y += 20;
			}
		}
	}

	void borrarRegistros() {
		vecMuestras1.clear();
		vecMuestras2.clear();
		rangoIni.X = -2;
		rangoIni.Y = -2;
		rangoFin.X = 32;
		rangoFin.Y = 32;
		for (int g = 0; g < vecGraficas.size(); g++) {
			vecGraficas[g].tiempoUlt = 0;
		}
	}

	void alejarZoom() {
		printf("	alejarZoom\n");
		if (1 <= vecZoom.size()) {
			Zoom zoom = vecZoom.at(vecZoom.size()-1);
			rangoIni.X = zoom.selIniX;
			rangoIni.Y = zoom.selIniY;
			rangoFin.X = zoom.selFinX;
			rangoFin.Y = zoom.selFinY;
			flagAutoAjuste = zoom.flagAutoAju;
			vecZoom.pop_back();
			printf("	alejarZoom %d\n", vecZoom.size());
		}		
	}

	void acercarRegion(Point clicIni, Point clicFin) {
		// calculo por porcentajes de la pantalla donde fueron los clics

		//printf("	acercarRegion %d %d %d %d\n", clicIni.X, clicIni.Y, clicFin.X, clicFin.Y);
		printf("acercarRegion\n");
		Zoom zoomUlt;
		zoomUlt.selIniX = rangoIni.X;
		zoomUlt.selIniY = rangoIni.Y;
		zoomUlt.selFinX = rangoFin.X;
		zoomUlt.selFinY = rangoFin.Y;
		zoomUlt.flagAutoAju = flagAutoAjuste;
		vecZoom.push_back(zoomUlt);

		flagAutoAjuste = false;

		//regActivado = true;
		Point tamPlano(gMaxX, gMaxY);

		PointF porIni, porFin;
		porIni.X = clicIni.X / (float)tamPlano.X;
		porIni.Y = (tamPlano.Y - clicIni.Y) / (float)tamPlano.Y;
		porFin.X = clicFin.X / (float)tamPlano.X;
		porFin.Y = (tamPlano.Y - clicFin.Y) / (float)tamPlano.Y;

		printf("	porcentajes x[%.2f,%.2f] y[%.2f,%.2f]\n", porIni.X, porFin.X, porIni.Y, porFin.Y);

		int difX = rangoFin.X - rangoIni.X;
		int difY = rangoFin.Y - rangoIni.Y;

		Point rangoInicioAux;
		rangoInicioAux.X = rangoIni.X;
		rangoInicioAux.Y = rangoIni.Y;

		rangoIni.X = ((float)difX * porIni.X) + rangoInicioAux.X;
		rangoIni.Y = ((float)difY * porIni.Y) + rangoInicioAux.Y;
		rangoFin.X = ((float)difX * porFin.X) + rangoInicioAux.X;
		rangoFin.Y = ((float)difY * porFin.Y) + rangoInicioAux.Y;

		printf("	nuevo rango x[%d,%d] y[%d,%d]\n", rangoIni.X, rangoFin.X, rangoIni.Y, rangoFin.Y);

		//printf("	acercarRegion %d\n", regActivado);
		//flagDeboRedibujar = true;

	}

	Point getPixel(Point puntoEnGrafica, int offsetX=0, int offsetY=0) {
		Point posPixel;
		PointF ubiPorcentaje;
		ubiPorcentaje.X = (puntoEnGrafica.X - rangoIni.X) / (float)(rangoFin.X - rangoIni.X);
		ubiPorcentaje.Y = (1.0f - (puntoEnGrafica.Y - rangoIni.Y) / (float)(rangoFin.Y - rangoIni.Y));
		posPixel.X = (ubiPorcentaje.X * gMaxX) + offsetX;
		posPixel.Y = (ubiPorcentaje.Y * gMaxY) + offsetY;
		return posPixel;
	}
	PointF getPixelDesdeGraficaF(PointF puntoEnGrafica, int offsetX = 0, int offsetY = 0) {
		PointF posPixel;
		PointF ubiPorcentaje;
		ubiPorcentaje.X = (puntoEnGrafica.X - rangoIni.X) / (float)(rangoFin.X - rangoIni.X);
		ubiPorcentaje.Y = (1.0f - (puntoEnGrafica.Y - rangoIni.Y) / (float)(rangoFin.Y - rangoIni.Y));
		posPixel.X = (ubiPorcentaje.X * gMaxX) + offsetX;
		posPixel.Y = (ubiPorcentaje.Y * gMaxY) + offsetY;
		return posPixel;
	}



	void dibujarOptimo(Graphics^ graficador) {

		// pinto recuadro
		SolidBrush^ pincelBlanco = gcnew SolidBrush(Color::White);


		graficador->Clear(Color::White);
		//graficador->FillRectangle(pincelBlanco, 0, 0, 650, 490);
		graficador->DrawRectangle(System::Drawing::Pens::Black, gMargX + gMinX, gMargY + gMinY, gMaxX - gMinX, gMaxY - gMinY);

		// Muestro Grilla	
		if (flagGrilla) {
			for (int i = rangoIni.Y; i < rangoFin.Y; i++) {
				int umbral = 10000;
				while (rangoFin.Y - rangoIni.Y < umbral) {
					umbral *= 0.1;
				}
				if (i % umbral == 0) {
					graficador->DrawLine(System::Drawing::Pens::LightGray, getPixel(Point(rangoIni.X, i), gMargX, 0), getPixel(Point(rangoFin.X, i), gMargX, 0));
				}
			}
			for (int i = rangoIni.X; i < rangoFin.X; i++) {
				int umbral = 10000;
				while (rangoFin.X - rangoIni.X < umbral) {
					umbral *= 0.1;
				}
				if (i % umbral == 0) {
					graficador->DrawLine(System::Drawing::Pens::LightGray, getPixel(Point(i, rangoIni.Y), 0, gMargY), getPixel(Point(i, rangoFin.Y), 0, gMargY));
				}
			}
		}

		// Muestro Valores en ejes
		FontFamily^ fntFamily = gcnew FontFamily(L"Times New Roman");
		System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(fntFamily, 10.00F, FontStyle::Regular);
		int corrida = 6;
		for (int i = rangoIni.Y; i <= rangoFin.Y; i++) {
			int umbral = 10000;
			while (rangoFin.Y - rangoIni.Y < umbral) {
				umbral *= 0.1;
			}
			if (i % umbral == 0) {
				graficador->DrawString(i.ToString(), fntWrite, Brushes::Black, getPixel(Point(rangoIni.X, i), 5, -15));
			}
		}
		for (int i = rangoIni.X; i <= rangoFin.X; i++) {
			int umbral = 10000;
			while (rangoFin.X - rangoIni.X < umbral) {
				umbral *= 0.1;
			}
			if (i % umbral == 0) {
				graficador->DrawString(i.ToString(), fntWrite, Brushes::Black, getPixel(Point(i, rangoIni.Y), 0, -10));
			}

		}




		// pinto lineas en el rango
		int entIniX, entFinX;
		float floIniY, floFinY;
		entIniX = (int)rangoIni.X;
		entFinX = ((int)rangoFin.X) + 1;
		floIniY = rangoIni.Y;
		floFinY = rangoFin.Y;

		//printf("Draw %d,%d\n", entIniX, entFinX);

		for (int g = 1; g < vecGraficas.size()+1; g++) {
			Grafica graficaActual = vecGraficas.at(g-1);
			if (graficaActual.flagVisible) {
				


				if (flagBarras) {
					SolidBrush^ myBrush = gcnew SolidBrush(obtenerColor(graficaActual.colorBar));
					for (int i = 0; i < getTamVecMuestras(g); i++) {
						Muestra muestraActual = getMuestra(g, i);
						if ((entIniX <= muestraActual.time) && (muestraActual.time <= entFinX)) { // si esta en el rango X
							if ((floIniY <= muestraActual.data) && (muestraActual.data <= floFinY)) { // si esta en el rango Y
								PointF posMuestra = getPixelDesdeGraficaF(PointF(muestraActual.time, muestraActual.data));
								PointF posMuestraSombra = getPixelDesdeGraficaF(PointF(muestraActual.time, rangoIni.Y), 0, gMargY);
								graficador->FillRectangle(myBrush, (int)posMuestra.X - (tamMuestra / 2), (int)posMuestra.Y, tamMuestra, (int)posMuestraSombra.Y - (int)posMuestra.Y);
							}
							else if (floFinY < muestraActual.data) {
								PointF posMuestra = getPixelDesdeGraficaF(PointF(muestraActual.time, muestraActual.data));
								PointF posMuestraSombra = getPixelDesdeGraficaF(PointF(muestraActual.time, rangoIni.Y), 0, gMargY);
								graficador->FillRectangle(myBrush, (int)posMuestra.X - (tamMuestra / 2), (int)posMuestra.Y, tamMuestra, (int)posMuestraSombra.Y - (int)posMuestra.Y);
							}
						}
					}

					//printf("Draw\n");
				}
				if (flagLineas) {
					PointF pixAnt(0, 0);
					Muestra muestraAnterior;
					bool flagPerteneceUlt = false;
					for (int i = 0; i < getTamVecMuestras(g); i++) {

						Muestra muestraAct = getMuestra(g, i);
						PointF pixMuestraAct = getPixelDesdeGraficaF(PointF(muestraAct.time, muestraAct.data));

						if (((entIniX - 1 <= muestraAct.time) && (muestraAct.time <= entFinX + 1)) // si esta en el rango X
							&& ((floIniY <= muestraAct.data) && (muestraAct.data <= floFinY))) { // si esta en el rango Y
								
							/*if (!flagPerteneceUlt) {
								// dibujo linea con muestra anterior
								graficador->DrawLine(System::Drawing::Pens::Green, pixAnt, pixMuestraAct);
								printf("	DrawLine1 %.2f %.2f %.2f %.2f\n", pixAnt.X, pixAnt.Y, pixMuestraAct.X, pixMuestraAct.Y);
							}
							else {
								graficador->DrawLine(System::Drawing::Pens::Black, pixAnt, pixMuestraAct);
							}		*/
							if ((pixAnt.X != 0) || (pixAnt.Y != 0)) {
								graficador->DrawLine(System::Drawing::Pens::Black, pixAnt, pixMuestraAct);
							}

							flagPerteneceUlt = true;
						}
						else {
							if (flagPerteneceUlt) {
								// dibujo linea con muestra posterior
								graficador->DrawLine(System::Drawing::Pens::Black, pixAnt, pixMuestraAct);
								//printf("	DrawLine2 %.2f %.2f %.2f %.2f\n", pixAnt.X, pixAnt.Y, pixMuestraAct.X, pixMuestraAct.Y);
							}

							flagPerteneceUlt = false;
						}

						muestraAnterior.time = muestraAct.time;
						muestraAnterior.data = muestraAct.data;

						pixAnt = getPixelDesdeGraficaF(PointF(muestraAnterior.time, muestraAnterior.data));
					}
				}
				if (flagPuntos) {
					SolidBrush^ myBrush = gcnew SolidBrush(obtenerColor(graficaActual.colorPun));
					for (int i = 0; i < getTamVecMuestras(g); i++) {
						Muestra muestraActual = getMuestra(g, i);
						if ((entIniX <= muestraActual.time) && (muestraActual.time <= entFinX)) { // si esta en el rango X
							if ((floIniY <= muestraActual.data) && (muestraActual.data <= floFinY)) { // si esta en el rango Y
								PointF posMuestra = getPixelDesdeGraficaF(PointF(muestraActual.time, muestraActual.data));
								graficador->FillRectangle(myBrush, (int)posMuestra.X - (tamMuestra / 2), (int)posMuestra.Y - (tamMuestra / 2), tamMuestra, tamMuestra);

							}
						}
					}
				}



			}
		}

		

		if (selMuestro) {
			graficador->DrawRectangle(System::Drawing::Pens::Black, selIni.X, selIni.Y, selFin.X - selIni.X, selFin.Y - selIni.Y);
		}

	}

	void verPuntos(bool val) {
		flagPuntos = val;
	}
	void verLineas(bool val) {
		flagLineas = val;
	}
	void verGrilla(bool val) {
		flagGrilla = val;
	}
	void setAutoAjuste(bool val) {
		flagAutoAjuste = val;
	}
	void setBarras(bool val) {
		flagBarras = val;
	}
	void seleccionar(bool muestro, Point puntoA, Point puntoB) {
		selMuestro = muestro;
		selIni = puntoA;
		selFin = puntoB;
	}
	int* getPeriodo(int grafica) {
		return &vecGraficas[grafica].periodo;
	}
	int* getEstadoS1() {
		return &estS1;
	}
	int* getEstadoS2() {
		return &estS2;
	}

	// datos para archivos
	int getS1CantMuestras() {
		return vecMuestras1.size();
	}
	int getS2CantMuestras() {
		return vecMuestras2.size();
	}
	Muestra getMuestraS1(int pos) {
		return vecMuestras1[pos];
	}
	Muestra getMuestraS2(int pos) {
		return vecMuestras2[pos];
	}
	

};

