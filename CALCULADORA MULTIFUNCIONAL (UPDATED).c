#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define PI 3.141592653589793238462643383279502884L
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");   // Windows
#else
    system("clear"); // Linux / macOS
#endif
}
long double degradoaradian(long double x)
{
    return x*(PI/180.0L);
}
typedef struct {
    long double numero; // campo numerico
    char *texto;        // string dinamico
} Datos;

void poblarstruct(Datos *d, long double valor, int opcion, int subcaso) 
{
    d->numero = valor; // guardar el numero

    if (opcion == 1) {
        // Opcion 1: string de largo fijo
        d->texto = malloc(21 * sizeof(char)); // 20 chars + '\0'
        if (d->texto == NULL) {
            printf("Error al reservar memoria\n");
            exit(1);
        }
        switch (subcaso)
        {
            case (1)
            case (2)
            case (3)
        }
        strcpy(d->texto, "Cadena fija de prueba");
    } else if (opcion == 2) {
        // Opcion 2: leer linea completa hasta Enter
        char buffer[1024];
        printf("Ingrese una linea: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0'; // quitar salto de linea
            d->texto = malloc(strlen(buffer) + 1);
            if (d->texto == NULL) {
                printf("Error al reservar memoria\n");
                exit(1);
            }
            strcpy(d->texto, buffer);
        } else {
            d->texto = NULL;
        }
    } else {
        d->texto = NULL;
    }
}

int eleccion(int p)
{
    int x;
    scanf("%d",&x);
    if (x<=0 || x>p)
    {
        return 0;
    }
    return x;
}


void cineodina()
{
    int cinedina,tipodesis,opcion,fins,casoeje,subcaso,caido;
    long double vcero,xfin,xinicio,yfin,yinicio,ymax,vfinal,angin,angf,omega,alfa,acelers,tiempo,tiempomax,vresultante,vinicioy,vfinaly,viniciox,vfinalx;
    printf("Quiere trabajar con (1) Cinematica\n(2) Dinamica\n");
    cinedina=eleccion(2);
    if (cinedina==0)
    {
        printf("Ingrese valor valido, por favor\n");
        cineodina();
    }
    else if (cinedina==1)
    {
        printf("Es su caso: (1) Caida Libre\n (2) Movimiento Rectilineo Uniforme\n(3) Movimiento Rectilineo Uniformemente Acelerado\n(4) Movimiento Vertical con lanzamiento hacia arriba\n(5) Movimiento Parabolico (Proyectil)\n");
        printf("(6) Movimiento Circular Uniforme\n(7) Movimiento Circular Uniformemente Acelerado\n");
        opcion=eleccion(6);
        printf("Respecto a la velocidad y aceleracion en el sistema es:\n (1) De velocidad constante\n(2) De aceleracion constante\n");
        tipodesis=eleccion(2);
        if (opcion==0 || tipodesis==0)
        {
            printf("Ingrese valor valido, por favor vuelva a ingresar su caso\n");
            cineodina();
        }
        switch(opcion)
        {
            case (1):
              printf("\nReconoce distancia(s), tiempo o velocidad(es)?\n(1.Si)\n(2) Solo algunas(3.No)\n");
              fins=eleccion(2);
              if (fins==0)
              {
                printf("Ingrese un valor valido la proxima\n");
              }
              acelers=9.8;
              else if(fins==1)
              {
                printf("Es el eje:\n(1) En X\n(2) En Y\n(3) Ambos (tiene el vector resultante)\n");
                casoeje=eleccion(3);
                if (casoeje==1)
                {
                    printf("Conoce..\n(1) La distancia final\n(2) La distancia inicial");
                    subcaso=eleccion(2);
                    if (subcaso==0)
                    {
                        printf("Ingrese un valor valido la proxima\n");
                    }
                    printf("\nIngresa el tiempo (segundos): "); scanf("%lf", &tiempo);
                    printf("\nIngresa la velocidad cero (m/s): "); scanf("%lf", &vcero);
                    else if(subcaso==1)
                    {
                        printf("\nIngresa la distancia final (en metros): "); scanf("%lf", &xfin);
                        xinicio=xfin-(vcero*tiempo);
                        printf("\nEn el eje X su distancia inicial es %.2lf\n",xinicio);
                    }
                    else
                    {
                        printf("Ingresa la distancia inicial (en metros): "); scanf("%lf", &xinicio);
                        xfin=xinicio-(vcero*tiempo);
                        printf("\nBasado en tus datos, la distancia final es %.2lf\n",xfin);
                    }
                }
                else if(casoeje==2)
                {
                    printf("La velocidad que tiene es...\n(1) Velocidad inicial\n(2) Velocidad final\n");
                    subcaso=eleccion(2);
                    if (subcaso==0)
                    {
                        printf("Ingrese un valor valido la proxima\n");
                    }
                    printf("La altura que tiene es...\n(1) La altura final\n(2) La altura inicial\n");
                    caido=eleccion(2);
                    if (caido==0)
                    {
                        printf("Ingrese un valor valido la proxima\n");
                    }
                    printf("\nIngresa el tiempo: "); scanf("%lf", &tiempo);
                    else if(subcaso==1 && caido==1)
                    {
                        printf("\nIngresa la velocidad inicial: "); scanf("%lf", &vcero);
                        printf("\nIngresa la altura final (en metros): "); scanf("%lf", &yfin);
                        yinicio=yfin+(acelers*1/2)*powl(tiempo,2)-vcero*tiempo;
                        vfinal=vcero-(acelers*tiempo);
                        printf("La velocidad final es de %.2lf m/s",vfinal);
                        printf("La posicion inicial es de %.2lf metros",yinicio);
                    }
                    else if (subcaso==1 && caido==2)
                    {
                        printf("\nIngresa la velocidad inicial: "); scanf("%lf", &vcero);
                        printf("\nIngresa la altura inicial: "); scanf("%lf", &yinicio);
                        yfin=yinicio+vcero*tiempo-(1/2)*acelers*powl(tiempo,2);
                        vfinal=vcero-acelers*tiempo;
                        printf("La velocidad final es de %.2lf m/s\n",vfinal);
                        printf("La posicion final es de %.2lf metros\n",yfin);
                    }
                    else if (subcaso==2 && subcaso==1)
                    {
                        printf("\nIngresa la velocidad final: "); scanf("%lf", &vfinal);
                        printf("\nIngresa la altura final: "); scanf("%lf", &yfin);
                        vcero=vfinal-acelers*tiempo;
                        yinicio=yfin-vcero*tiempo+(1/2*(acelers))*powl(tiempo,2);
                        printf("La velocidad inicial es : %.2lf",vcero);
                        printf("La altura inicial es : %.2lf",yinicio);
                    }
                    else
                    {
                        printf("\nIngresa la velocidad final: "); scanf("%lf", &vfinal);
                        printf("\nIngresa la altura inicial: "); scanf("%lf", &yinicio);
                        vcero=vfinal-acelers*tiempo;
                        yfin=yinicio+vcero*tiempo-(1/2)*acelers*powl(tiempo,2);
                        printf("La velocidad inicial es : %.2lf",vcero);
                        printf("La altura inicial es : %.2lf",yinicio);
                    }
                }
                else if (casoeje==3)
                {
                    printf("\nIngresa el tiempo (segundos) que toma en llegar al suelo: "); scanf("%lf", &tiempo);
                    printf("\nIngresa la magnitud de la velocidad inicial: "); scanf("%lf", &vresultante);
                    printf("\nIngrese el angulo con la horizontal: "); scanf("%lf", &angin);
                    viniciox=cosl(degradoaradian(angin))*vresultante;
                    vinicioy=sinl(degradoaradian(angin))*vresultante;
                    printf("\nConoce..\n(1) La altura inicial\n(2)Altura final\n(3) La distancia final (en x)\n");
                    subcaso=eleccion(3);
                    if (subcaso==0)
                    {
                        printf("Ingrese un valor valido la proxima\n");
                    }
                    else if(subcaso==1)
                    {
                        printf("\nIngrese la altura inicial: "); scanf("%lf", &yinicio);
                        yfin=yinicio+vinicioy*tiempo-(0.5)*acelers*powl(tiempo,2);
                        xfin=viniciox*tiempo;
                        vfinalx=viniciox;
                        vfinaly=vinicioy+acelers*tiempo;
                        tiempomax=vinicioy/acelers;
                        if (tiempomax<0) 
                        {
                            tiempomax*=-1;
                        }
                        ymax=yinicio+(pow(vinicioy,2)/2*acelers);
                        printf("Recorrio %.2lf metros en eje X y esta en %.2f de altura respecto a su posicion inicial, todo esto en %.2lf segundos",xfin,yfin,tiempo);
                        if (ymax>0)
                        {
                            printf("\nSe demoro %.2lf segundos en llegar a la altura maxima osea %.2lf metros sobre su punto inicial",tiempo,ymax);
                            break;
                        }
                        printf("\nSe demoro %.2lf segundos en llegar a la altura maxima osea %.2lf metros bajo su punto inicial",tiempo,ymax);
                        break;

                    }
                    else if(subcaso==2)
                    {
                        printf("\nIngrese la altura final: "); scanf("%lf", &ymax);
                        yinicio=yfinal-vinicioy*tiempo-(0.5)*acelers*pow(tiempo,2);
                        vfinaly=vinicioy+acelers*tiempo;
                        xfin=viniciox*tiempo;
                        tiempomax=vinicioy/acelers;
                        if (tiempomax<0)
                        {
                            tiempomax*=-1;
                        }
                        ymax=yinicio+(pow(vinicioy,2)/2*acelers);


                    }
                    else
                    {
                        printf("\nIngrese la distancia recorrida en X: "); scanf("%lf", &xfin);
                        tiempo=xfin/viniciox;
                        vfinaly=vinicioy+acelers*tiempo;
                        yinicio
                    }
                    
                }
              }
              else if(fins==3)
              {

              }
              else
              {

              }
              break;
            case (2):
              if (tipodesis==1)
              else
              {
    
              }
            case (3):
              if (tipodesis==1)
              else
              {

              }
            case (4):
              if (tipodesis==1)
              {

              }
              else
              {

              } 
            case (5):
              if (tipodesis==1)
              {

              }
              else
              {

              }
            case (6):
            
              if (tipodesis==1)
              {

              }
              else
              {

              }
            case (7):
            
              if (tipodesis==1)
              {

              }
              else
              {

              }
            default:
              break;
        }
    }
    else
    {
        printf("Es su caso:\n(1) Caida Libre\n(2) Equilibrio Estatico\n(3) Movimiento circular\n(4)Movimiento con aceleracion constante");
        opcion=eleccion(4);
        printf("Respecto a la velocidad y aceleracion en el sistema es:\n (1) De velocidad constante\n(2) De aceleracion constante\n");
        tipodesis=eleccion(2);

    }

}
void mensajestipicos(int h)
{
    switch (h)
    {
        case (1):
          printf("Error al reservar memoria\n");
          exit(EXIT_FAILURE);
        default:
          break;
        
    }
}
void matrizovec()
{
    while (1)
    {
        char decision,tipodat,espec=0;
        int esp,largo,ancho;
        printf("Va a poblar (llenar) una (M) )matriz o un (V) vector?: ");
        scanf("%c",&decision);
        decision=toupper(decision);
        switch (decision)
        {
            case ('M'):
              
            
              printf("Conoce el largo de su matriz? (1.Si) (2.No): ");
              scanf("%d",&esp);
              if (d==1)
              {
                printf("Ingrese la cantidad de filas de su matriz: ");
                scanf("%d",&largo);
                printf("Ingrese la cantidad de columnas de su matriz: ");
                scanf("%d",&ancho);
                printf("Son sus datos \n(1) Numeros reales\n(2) Numeros enteros\n(3) Strings/Lineas de texto:");
                scanf("%d",&tipodat);
                switch (tipodat)
                {
                    case (1):
                      float matriz[largo][ancho];
                      for (int i=0;i<largo;i++)
                      {
                          for (int j=0;j<ancho;j++)
                          {
                              printf("\nIngrese el elemento [%d][%d]: ",i+1,j+1);
                              scanf("%f",&matriz[i][j]);
                          }
                      }
                      break;
                    case (2):
                      int matriz[largo][ancho];
                      for (int i=0;i<largo;i++)
                      {
                          for (int j=0;j<ancho;j++)
                          {
                              printf("\nIngrese el elemento [%d][%d]: ",i+1,j+1);
                              scanf("%d",&matriz[i][j]);
                          }
                      }
                      printf("Representacion Grafica de su matriz:\n")
                      for (int w=0;w<largo;w++)
                      {
                        printf("| ");
                        for (int k=0;k<ancho;k++)
                        {
                            printf("%d",matriz[w][j]]);
                        }
                        printf(" |");
                      }
                    case (3):
                      getchar();
                      char ***mat = (char ***)malloc(largo * sizeof(char **))
                      if (mat==NULL)
                      {
                          mensajestipicos(1);
                      }
                      for (int i = 0; i < filas; i++) 
                      {
                          mat[i] = (char **)malloc(cols * sizeof(char *));
                          if (mat[i] == NULL) 
                          {
                              mensajestipicos(1);
                          }
                          for (int j=0;j<ancho;j++)
                          {
                              char buffer[1024];
                              printf("Ingresa string [%d][%d]: ", i, j);
                              fgets(buffer, sizeof(buffer), stdin);
                              buffer[strcspn(buffer, "\n")] = '\0';
                              mat[i][j] = (char *)malloc(strlen(buffer) + 1);
                              if (mat[i][j]==NULL)
                              {
                                  mensajestipicos(1);
                              }
                              strcpy(mat[i][j], buffer);
                              espec=1;
                          }
                            
                      }
                          printf("Representacion Grafica de su matriz:\n"); 
                          for (int j=0;j<largo;j++)
                          {
                              printf("| ");
                              for (int m=0;m<ancho;m++)
                              {
                                  printf("%s",matriz[j][m]);
                                  free (matriz[j][m]);
                              }
                              printf(" |\n");
                          }
                }
              }
              else if(d==2)
              {
                 printf("Remitase a trabajar con una matriz de tamaño establecido y vuelva a intentarlo");
                 matrizovec();
                 break;
              }
              else
              {
                 printf("Ingrese valor valido porfavor\n");
              }
              break;
            
            case ('V'):
              espec=1;
              printf("Conoce el largo de su vector? (1.Si) (2.No): ");
              scanf("%d",&esp);
              if (d==1)
              {
                  printf("Ingrese la cantidad de elementos del vector (el largo): ");
                  scanf("%d",&largo);
                  getchar();
                  char **vector=(char**)malloc(n*sizeof(char*));
                  if (vector==NULL)
                  {
                      mensajestipicos(1);
                  }
                  char buffer[1024];
                  for (int i=0;i<largo;i++)
                  {
                      
                      printf("Ingresa string [%d]: ", i);
                      fgets(buffer, sizeof(buffer), stdin);
                      buffer[strcspn(buffer, "\n")] = '\0';
                      vector[i] = (char *)malloc(strlen(buffer) + 1);
                      if (vector[i]==NULL)
                      {
                          mensajestipicos(1);
                      }
                      strcpy(vector[i], buffer);
                  }
                  printf("\nTU VECTOR ES : [")
                  for (int s=0;s<largo;s++)
                  {
                      printf("%s ",vector[s]);
                      free ()
                  }
              }
              else if(d==2)
              {
                  printf("Remitase a tener un vector de tamaño definido,vuelva a intentarlo");
                  matrizovec();
                  break;
              }
            default:
              printf("CARACTER NO VALIDO, VUELVA A INTENTARLO\n");
              matrizovec();
              break;
        }
    }
}
void definconicas()
{
    int toma;
    long double x,y,h,k,a,b,r,extremoh1,extremoh2,extremov1,extremov2,c;
    printf("Con que conicas desea trabajar?\n");
    printf("(1) Circunferencia\n(2) Elipse\n");
    scanf("%d",&toma);
    printf("Ingrese su punto H: ");
    scanf("%Lf",&h);
    printf("Ingrese su punto K: ");
    scanf("%Lf",&k);
    switch (toma)
    {
        case (1):
          printf("Ingrese el radio: ");
          scanf("%Lf",&r);
          printf("Los puntos extremos horizontales son (%Lf,%Lf) y (%Lf,%Lf)\n",h+r,k,h-r,k);
          printf("Los puntos extremos verticales son (%Lf,%Lf) y (%Lf,%Lf)\n",h,k+r,h,k-r);
          break;
        case (2):
          printf("Ingrese el valor de A: ");
          scanf("%Lf",&a);
          printf("\nIngrese el valor de B: ");
          scanf("%Lf",&b);
          if (a>b)
          {
              printf("Los vertices de su elipse son (%Lf,%Lf) y (%Lf,%Lf)\n",h+a,k,h-a,k);
              printf("Los covertices de su elipse son (%Lf,%Lf) y (%Lf,%Lf)\n",h,k+b,h,k-b);
              c=sqrt(powl(a,2)-powl(b,2));
              printf("Los focos de su elipse son (%Lf,%Lf) y (%Lf,%Lf)\n",h+c,k,h-c,k);
          }
          else if (a==b)
          {
              printf("Dado los valores de a y b, su elipse se convierte en circuneferencia\n")
              printf("Para este caso especifico a=b=r\n");
              definconicas();
              break;
          }
          else if(a<b)
          {
              printf("Los vertices de su elipse son (%Lf,%Lf) y (%Lf,%Lf)\n",h,k+b,h,k-b);
              printf("Los covertices de su elipse son (%Lf,%Lf) y (%Lf,%Lf)\n",h+a,k,h-a,k);
              c=sqrt(powl(b,2)-powl(a,2));
              printf("Los focos de su elipse son (%Lf,%Lf) y (%Lf,%Lf)\n",h,k+c,h,k-c);
          }
          break;
        default:
          printf("Ingrese una opcion valida, vuelva a intentarlo\n");
          definconicas();
          break;
    }
    
}
void regresl()
{

}
void tendisp()
{

}
void calculofalt(char a, char v)
{
    long double x,y,z,w,k,ps,norma,angulo,pe;
    printf("\nIngrese el valor de la componente %c: ",a);
    scanf("%Lf",&x);
    printf("Ahora ingrese el angulo en %c (en grados): ",a);
    scanf("%Lf",&y);
    printf("\nIngrese el valor de la componente %c: ",v);
    scanf("%Lf",&w);
    printf("\nAhora ingrese el angulo en %c (en grados): ",v);
    scanf("%Lf",&k);
    if (x/(cosl(w))==y/(cosl(k)))
    {
        pe=sqrt(1-powl(cos(w),2)-powl(cos(k),2));
        z=(x/cosl(w))*pe;
    }
    else
    {
        z=0;
        ps=0;
        pe=0;
    }
    norma=sqrt(powl(x,2)+powl(y,2)+powl(z,2));
    printf("\nLa norma del vector es %.2Lf\n",norma);
    if (pe!=0)
    {
        ps=acosl(z/norma);
    }
    printf("El angulo de la tercera componente es %.2Lf\n",ps);
}
void ingresacuadratica(int entrada)
{
    long double a,b,c,interior,x1,x2;
    printf("A continuacion ingrese los elementos requeridos (con su respectivo signo)\n");
    printf("Ingrese el coeficiente junto a su X cuadrado: ");
    scanf("%Lf",&a);
    printf("Ingrese el coeficiente junto a su X: ");
    scanf("%Lf",&b);
    printf("Ingrese el coeficiente independiente: ");
    scanf("%Lf",&c);
    if (entrada==2)
    {
        desarrollacuadratica(a,b,c);
    }
    else
    {
        interior=powl(b,2)-4*a*c;
        if (interior<0)
        {
            printf("No hay soluciones reales\n");
        }
        else
        {
            x1=(-b+sqrt(interior))/(2*a);
            x2=(-b-sqrt(interior))/(2*a);
            printf("Los valores de su X son %.2Lf y %.2Lf\n", x1,x2);
        }
    }
}
void desarollacuadratica(long double coefa, long double coefb, long double coefc)
{
    long double x,result;
    printf("Ingrese ahora el valor de su X : ");
    scanf("%f",&x);
    result=coefa*powl(x,2)+coefb*x+coefc;
    printf("\nEl resultado de su funcion cuadratica es %.2Lf\n",result);
}
void vector()
{
    int eleccion,caso;
    long double ang1,ang2,ang3,x,y,z,norma;
    char falta;
    printf("Es su vector (1) 2D o es (2) 3D?: \n");
    eleccion=eleccion(2);
    printf("\n");
    if (eleccion==0)
    {
        printf("Ingrese una opcion valida\n");
        vector();
    }
    else if (eleccion==1)
    {
        printf("Reconoces: \n(1)Magnitud en eje x/y\n (2) Una sola magnitud con su angulo\n");
        scanf("%d",&caso);
    }
    else if(eleccion==2)
    {
        printf("Reconoces :\n (1) Magnitud eje x,y,z\n(2) Dos magnitudes y dos angulos\n");
        while (1)
        {
            scanf("%d",&caso);
            switch (caso)
            {
                case (1):
                    printf("Ingrese el valor de la componente X: ");
                    scanf("%Lf",&x);
                    printf("\nIngrese el valor de la componente Y: ");
                    scanf("%Lf",&y);
                    printf("\nIngrese el valor de la componente Z: ");
                    scanf("%Lf",&z);
                    norma=sqrt(powl(x,2)+powl(y,2)+powl(z,2));
                    ang1=acosl(x/norma);
                    ang2=acosl(y/norma);
                    ang3=acosl(z/norma);
                    printf("La norma del vector es %Lf",norma);
                    printf("El angulo del vector en X: %Lf\n",ang1);
                    printf("El angulo del vector en Y: %Lf\n",ang2);
                    printf("El angulo del vector en Z: %Lf\n",ang3);
                case (2):
                    printf("Es su componente faltante X,Y o Z?: ");
                    while (1)
                    {
                        scanf("%c",&falta);
                        falta=toupper(falta);
                        switch (falta)
                        {
                            case ('X'):
                                calculofalt('Y','Z');
                                break;
                            case ('Y'):
                                calculofalt('X','Z');
                                break;
                            case ('Z'):
                                calculofalt('X','Y');
                                break;
                            default:
                                printf("Ingrese caracter valido x,y o z. Por favor");
                                break;
                        }
                        if (falta=='X' || falta=='Y' || falta=='Z')
                        {
                            break;
                        }
                    }
                default:
                    printf("Porfavor ingrese un tipo de caso valido (1) o (2) como se señala\n");
                    break;
            }
            if (caso==1 || caso==2)
            {
                break;
            }
        }
    }
}
int main()
{
    int opcion;
    int letra;
    while (1)
    {
        printf("Que operacion desea realizar?\n"); 
        printf("(1) Desarrollar ecuacion cuadratica\n") 
        printf("(2) Resolver ecuacion\n"); 
        printf("(3) Calculo de Vector (su norma y direccion)\n"); 
        printf("(4) Calculo Fisico de Cinematica/Dinamica\n"); //2 casos generales (1.1 y 1.2) 4 datos. ()
        printf("(5) Matrices/Vectores\n"); //2 casos generales. (1) Da X*Y datos (2) Da X datos 
        printf("(6) Definir Puntos en Plano de Conicas\n");//2 casos generales. (1) Da 11 datos (2) Da 16 datos
        printf("(7) Regresion Lineal Simple\n"); //Caso unico. 2 datos
        printf("(8) Medidas de Tendencia/Dispersion\n "); //Caso unico. 6 datos
        opcion=eleccion(8);
        if (opcion==1 || opcion==2)
        {
            ingresacuadratica(opcion);
        }
        switch (opcion)
        {
            case (3):
              
              vector();
              break;

            case (4):
              cineodina();
              break;

            case (5):
              matrizovec();
              break;
            case (6):
              definconicas();
              break;
        
            case (7):
              regresl();
            case (8):
              tendisp();
            default:
              printf("OPCION INVALIDA\n");
              break;
        lol;
        }
        printf("Desea hacer otra operacion (1. Si // 2. No): ");
        scanf("%d",&letra);
        printf("\n");
        if (letra==2)
        {
            printf("Adios :)\n");
            break;
        }
    }
    return 0;
}
