
datos <- read.csv(file='/home/kiernan/Documents/GitHub/LibreLabUNSL/E1 Velocidad del sonido/Medidas/data.csv')

plot(datos$Distancia , datos$TOF)

#### PLOTS ####
# Distancia vs Vel Sonido, bruto
plot(datos$Distancia, datos$Distancia/datos$TOF)
# Distancia vs Vel Sonido
plot(datosClean$Distancia, datosClean$Distancia/datosClean$TOF)
mean(datosClean$Distancia/datosClean$TOF)
# Distancia vs TOF
plot(datosClean$Distancia, datosClean$TOF)


#### AJUSTE LINEAR ####
velSonidoRef=344.72
ajuste <- lm(datosClean$TOF - 1/velSonidoRef*datosClean$Distancia ~ 1)
ajuste$coefficients
ordenada <- ajuste$coefficients[[1]]

datosClean$TOF.corr <- datosClean$TOF-ajuste$coefficients[[1]]
plot(datosClean$Distancia, datosClean$Distancia/datosClean$TOF.corr)
mean(datosClean$Distancia/datosClean$TOF.corr)