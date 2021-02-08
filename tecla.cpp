/*tecla_node: Funcion kbhit implementada en ROS. Termina al presionar ESC.*/
#include <ros/ros.h>
#include <sstream>
#include <iostream>
//Librerías para la función kbhit
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
int kbhit(void){	//Función kbhit de windows implementada para Linux
  struct termios oldt, newt;
  int ch, oldf;
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
  return 0;
}

int main(int argc, char* argv[])
{
ros::init(argc, argv, "tecla_node");	//Inicializa el nodo
ros::NodeHandle nh;			//Crea el handle
ros::Rate r(2);				//Frecuencia de ejecucion de 2Hz
int tecla=0, cont=0;
while(tecla != 27)	//ESC
{
    printf("\n%d Presione ESC para terminar.\n",cont);
    if(kbhit()) { tecla = getchar(); }
    cont++;
    r.sleep();		//Espera hasta completar el loop rate
}
return 0;
}
