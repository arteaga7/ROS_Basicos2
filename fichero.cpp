/*fichero_node: Escribe el valor de un contador y el tiempo en un archivo.txt.*/
#include <ros/ros.h>
#include <sstream>
#include <iostream>

FILE *fpCd;     //puntero a fichero
int main(int argc, char* argv[])
{
ros::init(argc, argv, "fichero_node");  //Inicializa el nodo
ros::NodeHandle n;                      //Crea el handle
ros::Rate r(10);                        //Frecuencia de ejecucion de 2Hz
int cont = 0;
double t0,t;
//Abre/crea el archivo datos.txt en modo escrituta "w"
fpCd = fopen("/home/ant/ws/src/teclado/src/datos.txt","w");
printf("Iniciando...\n");
t0 = ros::Time::now().toSec();      //Tiempo en segundos
 while(ros::ok()){
 t = ros::Time::now().toSec()-t0;   //Tiempo actual
 printf("%.4f\t%d\n",t,cont);
 fprintf(fpCd,"%.4f\t%d\n",t,cont); //Guarda en fichero
 cont++;
 r.sleep();                         //Espera hasta completar el loop rate
 }
fclose(fpCd);                       //Cierra el fichero
return 0;
}
