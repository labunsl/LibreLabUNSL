#pragma once

#include <vector>

using namespace System::Drawing;

typedef struct Est1{
	float time;
	float data;
} Muestra;

typedef struct EstGrafica {
	int idSensor;
	char nombre[50];
	int tipoMue; // 1:periodico 0:manual
	int periodo;
	int estado; // 0inactivo 1:activo

	bool flagActiva;
	bool flagVisible;
	bool flagHuboCambio;

	float tiempoUlt;
	
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
	int gMargX = 5, gMargY = 5, gMinX = 0, gMinY = 0, gMaxX = 1356 * 0.5f, gMaxY = 758 * 0.5f;
	int espX = 10, espY = 20, tamBarra = 8;
	float factor = 10, porcVacioSup = 0.2, datoMax=0,tiempoUlt;

	int grillaX = 10, grillaY = 10;
	int tamMuestra = 5;

	Point rangoIniG1, rangoFinG1;
	Point rangoIniG2, rangoFinG2;

	bool flagPuntos,flagLineas,flagGrilla,flagAutoAjuste, flagBarras;
	bool selMuestro;
	Point selIni, selFin;

	std::vector<Muestra> vecMuestras1,vecMuestras2;
	std::vector<Grafica> vecGraficas;
	std::vector<Zoom> vecZoomG1, vecZoomG2;

	int estS1, estS2;

	void limpiarDatos() {
		rangoIniG1.X = -2;
		rangoIniG1.Y = -2;
		rangoFinG1.X = 32;
		rangoFinG1.Y = 32;
		rangoIniG2.X = -2;
		rangoIniG2.Y = -2;
		rangoFinG2.X = 32;
		rangoFinG2.Y = 32;
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
		nuevaGrafica.estado = 0;
		
		nuevaGrafica.colorPun = colorPun;
		nuevaGrafica.colorLin = colorLin;
		nuevaGrafica.colorBar = colorBar;

		nuevaGrafica.idSensor = -1; // ningun sensor
		strcpy(nuevaGrafica.nombre, "Ninguno");
		nuevaGrafica.tipoMue = 0;
		nuevaGrafica.periodo = 1000;

		nuevaGrafica.flagHuboCambio = false;

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
			if (flagAutoAjuste) {
				while (rangoFinG1.X < puntoActual.time) {
					rangoFinG1.X += 20;
				}
				while (rangoFinG1.Y < puntoActual.data) {
					rangoFinG1.Y += puntoActual.data * 0.4f;
				}
			}
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
			if (flagAutoAjuste) {
				while (rangoFinG2.X < puntoActual.time) {
					rangoFinG2.X += 20;
				}
				while (rangoFinG2.Y < puntoActual.data) {
					rangoFinG2.Y += puntoActual.data * 0.4f;
				}
			}
			break; 		
		}
	}

	void borrarRegistros() {
		vecMuestras1.clear();
		vecMuestras2.clear();
		rangoIniG1.X = -2;
		rangoIniG1.Y = -2;
		rangoFinG1.X = 32;
		rangoFinG1.Y = 32;
		rangoIniG2.X = -2;
		rangoIniG2.Y = -2;
		rangoFinG2.X = 32;
		rangoFinG2.Y = 32;
		for (int g = 0; g < vecGraficas.size(); g++) {
			vecGraficas[g].tiempoUlt = 0;
		}
	}

	void alejarZoomG1G2() {
		printf("	alejarZoom\n");
		if (1 <= vecZoomG1.size()) {
			Zoom zoom = vecZoomG1.at(vecZoomG1.size()-1);
			rangoIniG1.X = zoom.selIniX;
			rangoIniG1.Y = zoom.selIniY;
			rangoFinG1.X = zoom.selFinX;
			rangoFinG1.Y = zoom.selFinY;
			flagAutoAjuste = zoom.flagAutoAju;
			vecZoomG1.pop_back();
			printf("	G1 vecZoom %d\n", vecZoomG1.size());
		}	
		if (1 <= vecZoomG2.size()) {
			Zoom zoom = vecZoomG2.at(vecZoomG2.size() - 1);
			rangoIniG2.X = zoom.selIniX;
			rangoIniG2.Y = zoom.selIniY;
			rangoFinG2.X = zoom.selFinX;
			rangoFinG2.Y = zoom.selFinY;
			flagAutoAjuste = zoom.flagAutoAju;
			vecZoomG2.pop_back();
			printf("	G2 vecZoom %d\n", vecZoomG2.size());
		}
	}

	void acercarRegion(Point clicIni, Point clicFin) {
		// calculo por porcentajes de la pantalla donde fueron los clics

		//printf("	acercarRegion %d %d %d %d\n", clicIni.X, clicIni.Y, clicFin.X, clicFin.Y);
		printf("acercarRegion\n");
		Zoom zoomUlt;
		zoomUlt.selIniX = rangoIniG1.X;
		zoomUlt.selIniY = rangoIniG1.Y;
		zoomUlt.selFinX = rangoFinG1.X;
		zoomUlt.selFinY = rangoFinG1.Y;
		zoomUlt.flagAutoAju = flagAutoAjuste;
		vecZoomG1.push_back(zoomUlt);

		flagAutoAjuste = false;

		//regActivado = true;
		Point tamPlano(gMaxX+(gMargX*2), gMaxY+(gMargY*2));

		PointF porIni, porFin;
		porIni.X = clicIni.X / (float)tamPlano.X;
		porIni.Y = (tamPlano.Y - clicIni.Y) / (float)tamPlano.Y;
		porFin.X = clicFin.X / (float)tamPlano.X;
		porFin.Y = (tamPlano.Y - clicFin.Y) / (float)tamPlano.Y;

		//printf("	porcentajes x[%.2f,%.2f] y[%.2f,%.2f]\n", porIni.X, porFin.X, porIni.Y, porFin.Y);

		int difX = rangoFinG1.X - rangoIniG1.X;
		int difY = rangoFinG1.Y - rangoIniG1.Y;

		Point rangoInicioAux;
		rangoInicioAux.X = rangoIniG1.X;
		rangoInicioAux.Y = rangoIniG1.Y;

		rangoIniG1.X = ((float)difX * porIni.X) + rangoInicioAux.X;
		rangoIniG1.Y = ((float)difY * porIni.Y) + rangoInicioAux.Y;
		rangoFinG1.X = ((float)difX * porFin.X) + rangoInicioAux.X;
		rangoFinG1.Y = ((float)difY * porFin.Y) + rangoInicioAux.Y;

		//printf("	nuevo rango x[%d,%d] y[%d,%d]\n", rangoIni.X, rangoFin.X, rangoIni.Y, rangoFin.Y);

		//printf("	acercarRegion %d\n", regActivado);
		//flagDeboRedibujar = true;

	}

	void acercarRegionPorcentajesX(float porI, float porF) {

		printf(" acercarRegionPorcentajesX	porI:%f porF:%f\n", porI, porF);
		Zoom zoomUlt;
		Point clicI, clicF, rangoInicioAux;;
		float tamX;

		// G1
		zoomUlt.selIniX = rangoIniG1.X;
		zoomUlt.selIniY = rangoIniG1.Y;
		zoomUlt.selFinX = rangoFinG1.X;
		zoomUlt.selFinY = rangoFinG1.Y;
		zoomUlt.flagAutoAju = flagAutoAjuste;
		vecZoomG1.push_back(zoomUlt);

		clicI.X = rangoIniG1.X;
		clicI.Y = rangoIniG1.Y;
		clicF.X = rangoFinG1.X;
		clicF.Y = rangoFinG1.Y;

		tamX = rangoFinG1.X - rangoIniG1.X;
		
		rangoInicioAux.X = rangoIniG1.X;
		rangoInicioAux.Y = rangoIniG1.Y;
		rangoIniG1.X = rangoInicioAux.X + (int)(tamX * porI);
		rangoFinG1.X = rangoInicioAux.X + (int)(tamX * porF);



		// G2
		zoomUlt.selIniX = rangoIniG2.X;
		zoomUlt.selIniY = rangoIniG2.Y;
		zoomUlt.selFinX = rangoFinG2.X;
		zoomUlt.selFinY = rangoFinG2.Y;
		zoomUlt.flagAutoAju = flagAutoAjuste;
		vecZoomG2.push_back(zoomUlt);

		clicI.X = rangoIniG2.X;
		clicI.Y = rangoIniG2.Y;
		clicF.X = rangoFinG2.X;
		clicF.Y = rangoFinG2.Y;

		tamX = rangoFinG2.X - rangoIniG2.X;

		rangoInicioAux.X = rangoIniG2.X;
		rangoInicioAux.Y = rangoIniG2.Y;
		rangoIniG2.X = rangoInicioAux.X + (int)(tamX * porI);
		rangoFinG2.X = rangoInicioAux.X + (int)(tamX * porF);

		flagAutoAjuste = false;

		//printf(" region: %d %f = %d\n", rangoIni.X, tamX * porI, rangoIni.X + (int)(tamX * porI));
		

		//acercarRegion(clicI, clicF);


	}

	Point getPixel(int g, Point puntoEnGrafica, int offsetX=0, int offsetY=0) {
		Point rangoIni, rangoFin;
		switch (g) {
		case 1:
			rangoIni = rangoIniG1;
			rangoFin = rangoFinG1;
			break;
		case 2:
			rangoIni = rangoIniG2;
			rangoFin = rangoFinG2;
			break;
		}
		Point posPixel;
		PointF ubiPorcentaje;
		ubiPorcentaje.X = (puntoEnGrafica.X - rangoIni.X) / (float)(rangoFin.X - rangoIni.X);
		ubiPorcentaje.Y = (1.0f - (puntoEnGrafica.Y - rangoIni.Y) / (float)(rangoFin.Y - rangoIni.Y));
		posPixel.X = (ubiPorcentaje.X * gMaxX) + offsetX;
		posPixel.Y = (ubiPorcentaje.Y * gMaxY) + offsetY;
		return posPixel;
	}
	PointF getPixelDesdeGraficaF(int g, PointF puntoEnGrafica, int offsetX = 0, int offsetY = 0) {
		Point rangoIni, rangoFin;
		switch (g) {
		case 1:
			rangoIni = rangoIniG1;
			rangoFin = rangoFinG1;
			break;
		case 2:
			rangoIni = rangoIniG2;
			rangoFin = rangoFinG2;
			break;
		}
		PointF posPixel;
		PointF ubiPorcentaje;
		ubiPorcentaje.X = (puntoEnGrafica.X - rangoIni.X) / (float)(rangoFin.X - rangoIni.X);
		ubiPorcentaje.Y = (1.0f - (puntoEnGrafica.Y - rangoIni.Y) / (float)(rangoFin.Y - rangoIni.Y));
		posPixel.X = (ubiPorcentaje.X * gMaxX) + offsetX;
		posPixel.Y = (ubiPorcentaje.Y * gMaxY) + offsetY;
		return posPixel;
	}



	void dibujarOptimo(Graphics^ graficador, int g) {

		Point rangoIni, rangoFin;
		switch (g) {
		case 1:
			rangoIni = rangoIniG1;
			rangoFin = rangoFinG1;
			break;
		case 2:
			rangoIni = rangoIniG2;
			rangoFin = rangoFinG2;
			break;
		}

		// pinto recuadro
		SolidBrush^ pincelBlanco = gcnew SolidBrush(Color::White);

		graficador->Clear(Color::White);
		graficador->FillRectangle(pincelBlanco, 0, 0, gMaxX, gMaxY);
		graficador->DrawRectangle(System::Drawing::Pens::Black, gMargX + gMinX, gMargY + gMinY, gMaxX - gMinX, gMaxY - gMinY);

		// Muestro Grilla	
		if (flagGrilla) {
			for (int i = rangoIni.Y; i < rangoFin.Y; i++) {
				int umbral = 10000;
				while (rangoFin.Y - rangoIni.Y < umbral + (umbral * 0.5f)) {
					umbral *= 0.1;
				}
				if (i % umbral == 0) {
					graficador->DrawLine(System::Drawing::Pens::LightGray, getPixel(g,Point(rangoIni.X, i), gMargX, 0), getPixel(g,Point(rangoFin.X, i), gMargX, 0));
				}
			}
			for (int i = rangoIni.X; i < rangoFin.X; i++) {
				int umbral = 10000;
				while (rangoFin.X - rangoIni.X < umbral + (umbral * 0.5f)) {
					umbral *= 0.1;
				}
				if (i % umbral == 0) {
					graficador->DrawLine(System::Drawing::Pens::LightGray, getPixel(g,Point(i, rangoIni.Y), 0, gMargY), getPixel(g,Point(i, rangoFin.Y), 0, gMargY));
				}
			}
		}

		// Muestro Valores en ejes
		FontFamily^ fntFamily = gcnew FontFamily(L"Times New Roman");
		System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(fntFamily, 10.00F, FontStyle::Regular);
		int corrida = 6;
		for (int i = rangoIni.Y; i <= rangoFin.Y; i++) {
			int umbral = 10000;
			while (rangoFin.Y - rangoIni.Y < umbral + (umbral * 0.5f)) {
				umbral *= 0.1;
			}
			if (i % umbral == 0) {
				graficador->DrawString(i.ToString(), fntWrite, Brushes::Black, getPixel(g,Point(rangoIni.X, i), 5, -15));
			}
		}
		for (int i = rangoIni.X; i <= rangoFin.X; i++) {
			int umbral = 10000;
			while (rangoFin.X - rangoIni.X < umbral + (umbral * 0.5f)) {
				umbral *= 0.1;
			}
			if (i % umbral == 0) {
				graficador->DrawString(i.ToString(), fntWrite, Brushes::Black, getPixel(g, Point(i, rangoIni.Y), 0, -10));
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

		//for (int g = 1; g < vecGraficas.size()+1; g++) {
			Grafica graficaActual = vecGraficas.at(g-1);
			if (graficaActual.flagVisible) {
				


				if (flagBarras) {
					SolidBrush^ myBrush = gcnew SolidBrush(obtenerColor(graficaActual.colorBar));
					for (int i = 0; i < getTamVecMuestras(g); i++) {
						Muestra muestraActual = getMuestra(g, i);
						if ((entIniX <= muestraActual.time) && (muestraActual.time <= entFinX)) { // si esta en el rango X
							if ((floIniY <= muestraActual.data) && (muestraActual.data <= floFinY)) { // si esta en el rango Y
								PointF posMuestra = getPixelDesdeGraficaF(g, PointF(muestraActual.time, muestraActual.data));
								PointF posMuestraSombra = getPixelDesdeGraficaF(g, PointF(muestraActual.time, rangoIni.Y), 0, gMargY);
								graficador->FillRectangle(myBrush, (int)posMuestra.X - (tamMuestra / 2), (int)posMuestra.Y, tamMuestra, (int)posMuestraSombra.Y - (int)posMuestra.Y);
							}
							else if (floFinY < muestraActual.data) {
								PointF posMuestra = getPixelDesdeGraficaF(g, PointF(muestraActual.time, muestraActual.data));
								PointF posMuestraSombra = getPixelDesdeGraficaF(g, PointF(muestraActual.time, rangoIni.Y), 0, gMargY);
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
						PointF pixMuestraAct = getPixelDesdeGraficaF(g, PointF(muestraAct.time, muestraAct.data));

						if (((entIniX - 1 <= muestraAct.time) && (muestraAct.time <= entFinX + 1)) // si esta en el rango X
							&& ((floIniY <= muestraAct.data) && (muestraAct.data <= floFinY))) { // si esta en el rango Y
								
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

						pixAnt = getPixelDesdeGraficaF(g, PointF(muestraAnterior.time, muestraAnterior.data));
					}
				}
				if (flagPuntos) {
					SolidBrush^ myBrush = gcnew SolidBrush(obtenerColor(graficaActual.colorPun));
					for (int i = 0; i < getTamVecMuestras(g); i++) {
						Muestra muestraActual = getMuestra(g, i);
						if ((entIniX <= muestraActual.time) && (muestraActual.time <= entFinX)) { // si esta en el rango X
							if ((floIniY <= muestraActual.data) && (muestraActual.data <= floFinY)) { // si esta en el rango Y
								PointF posMuestra = getPixelDesdeGraficaF(g, PointF(muestraActual.time, muestraActual.data));
								graficador->FillRectangle(myBrush, (int)posMuestra.X - (tamMuestra / 2), (int)posMuestra.Y - (tamMuestra / 2), tamMuestra, tamMuestra);

							}
						}
					}
				}



			}
		//}

		

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
	int getIdSensor(int grafica) {
		return vecGraficas[grafica].idSensor; // este
	}
	int getTipoMue(int grafica) {
		return vecGraficas[grafica].tipoMue;
	}
	int getPeriodo(int grafica) {
		return vecGraficas[grafica].periodo;
	}
	int* getEstadoS1() {
		return &estS1;
	}
	int* getEstadoS2() {
		return &estS2;
	}
	int getEstado(int grafica) {
		return vecGraficas[grafica].estado;
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
	
	void setResolucion(int x, int y) {
		gMaxX = x - (gMargX * 2);
		gMaxY = y - (gMargY * 2);
	}

	std::vector<float> getVecTiempos(int g) {
		std::vector<float> vecRetorno;
		for (int t = 0; t < getTamVecMuestras(g); t++) {
			vecRetorno.push_back(getMuestra(g,t).time);
		}
		return vecRetorno;
	}
	std::vector<float> getVecDatos(int g) {
		std::vector<float> vecRetorno;
		for (int t = 0; t < getTamVecMuestras(g); t++) {
			vecRetorno.push_back(getMuestra(g, t).data);
		}
		return vecRetorno;
	}
	float getUltimoTiempo(int numGrafica) {
		return getMuestra(numGrafica, getTamVecMuestras(numGrafica)-1).time;
	}

	void setIdSen(int grafica, int nuevoId) {
		vecGraficas[grafica].idSensor = nuevoId;
	}
	void setTipoMue(int grafica, int nuevoTipo) {
		vecGraficas[grafica].tipoMue = nuevoTipo;
	}
	void setPeriodo(int grafica, int nuevoPeriodo) {
		//printf("setPeriodo %d", nuevoPeriodo);
		vecGraficas[grafica].periodo = nuevoPeriodo;
	}
	void setCambioSensor(int grafica, bool val) {
		vecGraficas[grafica].flagHuboCambio = val;
	}
	void setEstado(int grafica, int estado) {
		vecGraficas[grafica].periodo = estado;
	}

	bool getCambioSensor(int grafica) {
		return vecGraficas[grafica].flagHuboCambio;
	}
	void mostrarConfSensor(int grafica) {
		printf("	Sensor %d\n", grafica);
		printf("	Id %d\n", getIdSensor(grafica));
		printf("	Tipo Mue %d\n", getTipoMue(grafica));
		printf("	Periodo %d\n", getPeriodo(grafica));

	}
};

