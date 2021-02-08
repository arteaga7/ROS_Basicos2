/*timer_node: Realiza 2 tareas periodicas utilizando timers.*/
#include <ros/ros.h>
#include <sstream>
#include <iostream>
int cont1 = 1, cont2=1;

void timerCallback1(const ros::TimerEvent&){
printf("Timer1: %d\n",cont1);
cont1++;
}

void timerCallback2(const ros::TimerEvent&){
printf("\nTimer2: %d\n\n",cont2);
cont2++;
}

int main(int argc, char* argv[])
{
ros::init(argc, argv, "timer_node");  	//Inicializa el nodo
ros::NodeHandle n;                      //Crea el handle
ros::Timer timer1 = n.createTimer(ros::Duration(0.1), timerCallback1);
ros::Timer timer2 = n.createTimer(ros::Duration(0.5), timerCallback2);
//(periodo de ejecucion=0.1s, funcion de callback)
ros::spin();    //Espera por callbacks
return 0;
}
