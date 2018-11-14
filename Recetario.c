//
//  Proyecto Final: Recetario de cocina
//
//  Creado por Emilio Padilla Miranda y Angel Gael Molina Sanchez el 6/22/18.
//  Copyright © 2018 AlimentaTEC. Todos los derechos reservados.
//  Guia de estilo usada http://www.gnu.org/prep/standards/standards.pdf

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define ESC 27

//Procedimiento que muestra el menu inicial
void menu_recetas (char nombre [30])
{
    printf("\n\n¿Deseas ver nuestro recetario %s?, ¿Agregar una receta? ó ¿Generar una comida completa? \n", nombre);
    puts("1.- Ver recetario");
    puts("2.- Referencias");
    puts("3.- Agregar una nueva receta al recetario");
    puts("4.- Salir");
}

//Procedimiento que imprime las opciones disponibles
void opciones_recetario()
{
    printf("\n\n1. Abre el recetario\n");
    puts("2. Elegir receta");
    puts("3. Volver al menu inicial");
}

//Imprime el menu del recetario
void menu_recetario()
{
    puts("1.- Entradas");
    puts("2.- Plato fuerte");
    puts("3.- Postre");
    puts("4.- Volver al menu incial");
}

//Imprime el menu del plato fuerte
void menu_plato_fuerte()
{
    puts("1.- Pollo");
    puts("2.- Res");
    puts("3.- Volver al menu inicial");
}

void despliega_entradas ()
{
    //Abrir el archivo
    FILE * archivo = fopen("./Recetario/Entradas/Index_Entradas", "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo))
        {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}

void despliega_referencias ()
{
    //Abrir el archivo
    FILE * archivo = fopen("./Recetario/Referencias/Referencias", "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo))
        {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}

void despliega_postres ()
{
    //Abrir el archivo
    FILE * archivo = fopen("./Recetario/Postres/Index_Postres", "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo)) {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}


void despliega_pollo ()
{
    //Abrir el archivo
    FILE * archivo = fopen("./Recetario/Plato_fuerte/Pollo/Index_Pollo", "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo)) {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}


void despliega_res ()
{
    //Abrir el archivo
    FILE * archivo = fopen("./Recetario/Plato_fuerte/Res/Index_Res", "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo)) {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}

void agregar_receta (char nombre_receta [200], char nombre[30])
{
    //Inicializa las strings que se usaran para concatenar y que el usuario solo ingrese el nombre
    char ruta [400];
    char platillo[400];
    
    //Concatena la ruta para ingresarla en el fopen
    strcpy(ruta, "./Recetario/Recetas_personales/");
    strcpy(platillo, nombre_receta);
    strcat(ruta, platillo);
    
    
    // Abrir archivo
    FILE * receta_nueva = fopen(ruta, "w");
    
    //Escribe la fecha en el documento
    time_t ahora;
    time(&ahora);
    fprintf(receta_nueva, "Esta receta se creo el %s\n", ctime(&ahora));
    
    // Escribe el nombre de la receta al principio del archivo
    fputs(nombre_receta, receta_nueva);
    fputs("\n\n", receta_nueva);
    
    //Muesra las instrucciones
    printf("Ingresa la receta a continuacion, presiona Enter despues de ingresar cada linea para que esta sea guardada %s, el programa dejara de grabar la receta en el archivo cuando presiones ESC\n", nombre);
    char texto_receta[5000];
    gets(texto_receta);
    
    // Ciclo que copia el mensaje de registro_bit en nueva_cadena hasta que se presione ESC (ASCII = 27), una vez presionado, termina de grabar el mensaje en la nueva cadena
    char ch;
    do
    {
        //Realiza el proceso de escritura en el archivo
        puts("Continua escribiendo");
        char texto_receta_en_archivo[5000];
        gets(texto_receta_en_archivo);
        fprintf(receta_nueva, "%s\n", texto_receta_en_archivo);
        ch = getchar();
    }
    while(ch != ESC);
    
    //Cuando termina de guardar la receta sale este anuncio
    puts("¡Receta guardada con exito!");
    
    // Cerrar el archivo
    fclose(receta_nueva);
}

void recetas_entradas (char entrada[200])
{
    //Inicializa las strings que se usaran para concatenar y que el usuario solo ingrese el nombre
    char ruta [400];
    char platillo[400];
    
    //Concatena la ruta para ingresarla en el fopen
    strcpy(ruta, "./Recetario/Entradas/");
    strcpy(platillo, entrada);
    strcat(ruta, platillo);
    
    //Abrir el archivo
    FILE * archivo = fopen(ruta, "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo))
        {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}

void recetas_pollo (char pollo[200])
{
    //Inicializa las strings que se usaran para concatenar y que el usuario solo ingrese el nombre
    char ruta [400];
    char platillo[400];
    
    //Concatena la ruta para ingresarla en el fopen
    strcpy(ruta, "./Recetario/Plato_fuerte/Pollo/");
    strcpy(platillo, pollo);
    strcat(ruta, platillo);
    
    //Abrir el archivo
    FILE * archivo = fopen(ruta, "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo))
        {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}

void recetas_res (char res[200])
{
    //Inicializa las strings que se usaran para concatenar y que el usuario solo ingrese el nombre
    char ruta [400];
    char platillo[400];
    
    //Concatena la ruta para ingresarla en el fopen
    strcpy(ruta, "./Recetario/Plato_fuerte/Res/");
    strcpy(platillo, res);
    strcat(ruta, platillo);
    
    //Abrir el archivo
    FILE * archivo = fopen(ruta, "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo))
        {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}

void recetas_postres (char postre[200])
{
    //Inicializa las strings que se usaran para concatenar y que el usuario solo ingrese el nombre
    char ruta [400];
    char platillo[400];
    
    //Concatena la ruta para ingresarla en el fopen
    strcpy(ruta, "./Recetario/Postres/");
    strcpy(platillo, postre);
    strcat(ruta, platillo);
    
    //Abrir el archivo
    FILE * archivo = fopen(ruta, "r");
    
    //Validar que el archivo existe
    if (archivo == NULL)
    {
        printf("ERROR: el archivo no existe.\n\n");
    }
    else
    {
        char letra;
        //Mientras que el archivo no llegue a su fin
        while(!feof(archivo))
        {
            //Imprimir el caracter
            printf("%c", letra);
            //Leer un caracter
            fscanf(archivo, "%c", &letra);
        }
        //Cerrar el archivo
        fclose(archivo);
    }
}



//Funcion principal del programa
int main()
{
    //Muestra las instrucciones del programa y lo que se puede hacer con el
    puts("BIENVENIDO COCINERO!\n");
    puts("Este programa funciona como un buscador de recetas dependiendo de lo que estes buscando implementar para tu comida, o en su defecto, de un menu completo.");
    //Pide el nombre del usuario
    puts("Cual es tu nombre?");
    //Se inicializa el string para obtener el nombre
    char nombre [30];
    //Se obtiene el nombre
    scanf("%s%*c",nombre);
    //Se inicializa la cadena que ayudara para las escritura de recetas
    char receta_nueva [200];
    //Se incicializa la variable para el cambio del menu inicial
    int recetas = 0;
    do
    {
        //Se llama al procedimiento que imprime el menu
        menu_recetas(nombre);
        //Se pide la opcion deseada
        scanf("%i%*c", &recetas);
        //Se usa un switch para el menu y cambiar entre las distintas opciones
        switch (recetas)
        {
            case 1:
                puts("Bienvenido al recetario");
                //Se llama al procedimiento que despliega el menu del recetario
                menu_recetario();
                puts("Por favor elige una opcion del menu");
                //Se inicializa la variable responsable de cambiar el switch del recetario
                int recetario = 0;
                //Se pide al usuario la opcion
                scanf("%i%*c", &recetario);
                //Se llama al switch
                switch (recetario)
                {
                    case 1:
                        //Imprime el nombre del menu espera dos segundos e imprime la bienvenida
                        puts("Entradas");
                        sleep(2);
                        puts("Bienvenido a las entradas, por favor elige una opcion");
                        //Inicializacion de la variable que cambiara en el switch
                        int entradas = 0;
                        //Se hace un ciclo Do-While para que continue ejecutandose
                        do
                        {
                        //Llama al procedimiento que imprime el menu
                        opciones_recetario();
                        //Pide la variable que guardara para cambiar en el switch
                        scanf("%i%*c", &entradas);
                        //El switch cambia el menu
                        switch (entradas)
                        {
                            case 1:
                                //Imprime el aviso y llama a la funcion que muestra las recetas
                                puts("Estas son las recetas disponibles");
                                despliega_entradas();
                                break;
                                
                            case 2:
                                //Llama al procedimiento que imprime la receta
                                puts("Ingresa el nombre de la receta que desear ver");
                                gets(receta_nueva);
                                recetas_entradas(receta_nueva);
                                break;
                                
                            case 3:
                                //Vuelve al menu inicial despues de 2 segundos
                                puts("Regresando al menu inicial...");
                                sleep(2);
                                break;
                                
                            default:
                                //Si no se ingresa un valor correcto regresa al mismo menu
                                puts("No es una opcion correcta, vuelve a intentarlo");
                                sleep(2);
                                break;
                        }
                        }
                        //Mientras el valor de entradas sea diferente de 3 se seguira ejecutando
                        while (entradas != 3);
                        break;
                        
                    case 2:
                        //Imprime el nombre del menu espera dos segundos e imprime la bienvenida
                        puts("Plato fuerte");
                        sleep(2);
                        puts("Bienvenido a los platos fuertes, por favor elige una opcion");
                        //Inicializacion de la variable que cambiara en el switch
                        int plato_fuerte = 0;
                        //Se hace un ciclo Do-While para que continue ejecutandose
                        do
                        {
                        //Llama al procedimiento que imprime el menu
                        menu_plato_fuerte();
                        //Se guarda el valor dentro de la variable correspondiente
                        scanf("%i%*c", &plato_fuerte);
                        //El switch cambia el menu
                        switch (plato_fuerte)
                        {
                            case 1:
                                //Imprime el nombre del menu espera dos segundos e imprime la bienvenida
                                puts("Pollo");
                                sleep(2);
                                puts("Bienvenido a las recetas de pollo, por favor elige una opcion");
                                //Inicializacion de la variable que cambiara en el switch
                                int pollo = 0;
                                //Se hace un ciclo Do-While para que continue ejecutandose
                                do
                                {
                                    //Llama al procedimiento que imprime el menu
                                    opciones_recetario();
                                    //Se guarda el valor dentro de la variable correspondiente
                                    scanf("%i%*c", &pollo);
                                    //El switch cambia el menu
                                    switch (pollo)
                                    {
                                        case 1:
                                            //Imprime el aviso y llama a la funcion que muestra las recetas
                                            puts("Estas son las recetas disponibles");
                                            despliega_pollo();
                                            break;
                                            
                                        case 2:
                                            //Llama al procedimiento que imprime la receta
                                            puts("Ingresa el nombre de la receta que desear ver");
                                            gets(receta_nueva);
                                            recetas_pollo(receta_nueva);
                                            break;
                                            
                                        case 3:
                                            //Vuelve al menu inicial despues de 2 segundos
                                            puts("Regresando al menu inicial...");
                                            sleep(2);
                                            break;
                                            
                                        default:
                                            //Si no se ingresa un valor correcto regresa al mismo menu
                                            puts("No es una opcion correcta, vuelve a intentarlo");
                                            sleep(2);
                                            break;
                                    }
                                }
                                //Mientras el valor de pollo sea diferente de 3 se seguira ejecutando
                                while (pollo != 3);
                                break;
                                
                            case 2:
                                //Imprime el nombre del menu espera dos segundos e imprime la bienvenida
                                puts("Res");
                                sleep(2);
                                //Inicializacion de la variable que cambiara en el switch
                                puts("Bienvenido a las recetas de res, por favor elige una opcion");
                                int res = 0;
                                //Se hace un ciclo Do-While para que continue ejecutandose
                                do
                                {
                                    //Llama al procedimiento que imprime el menu
                                    opciones_recetario();
                                    //Pide la variable que guardara para cambiar en el switch
                                    scanf("%i%*c", &res);
                                    //El switch cambia el menu
                                    switch (res)
                                    {
                                        case 1:
                                            //Imprime el aviso y llama a la funcion que muestra las recetas
                                            puts("Estas son las recetas disponibles");
                                            despliega_res();
                                            break;
                                            
                                        case 2:
                                            //Llama al procedimiento que imprime la receta
                                            puts("Ingresa el nombre de la receta que desear ver");
                                            gets(receta_nueva);
                                            recetas_res(receta_nueva);
                                            break;
                                            
                                        case 3:
                                            //Vuelve al menu inicial despues de 2 segundos
                                            puts("Regresando al menu inicial...");
                                            sleep(2);
                                            break;
                                            
                                        default:
                                            //Si no se ingresa un valor correcto regresa al mismo menu
                                            puts("No es una opcion correcta, vuelve a intentarlo");
                                            sleep(2);
                                            break;
                                    }
                                }
                                //Mientras el valor de res sea diferente de 3 se seguira ejecutando
                                while (res != 3);
                                break;
                                
                            case 3:
                                //Vuelve al menu inicial despues de 2 segundos
                                puts("Regresando al menu inicial...");
                                sleep(2);
                                break;
                                
                            default:
                                //Si no se ingresa un valor valido dentro del switch vuelve a ejecutar el menu despues de dos segundos
                                puts("No es una opcion correcta, vuelve a intentarlo");
                                sleep(2);
                                break;
                        }
                        }
                        //Mientras el valor de plato_fuerte sea diferente de 4 se seguira ejecutando
                        while (plato_fuerte != 4);
                        break;
                        
                    case 3:
                        //Imprime el nombre del menu espera dos segundos e imprime la bienvenida
                        puts("Postres");
                        sleep(2);
                        puts("Bienvenido a los postres, elige una opcion.");
                        //Inicializacion de la variable que cambiara en el switch
                        int postres = 0;
                        //Se hace un ciclo Do-While para que continue ejecutandose
                        do
                        {
                        //Llama al procedimiento que imprime el menu
                        opciones_recetario();
                        //Pide la variable que guardara para cambiar en el switch
                        scanf("%i%*c", &postres);
                        //El switch cambia el menu
                        switch (postres)
                        {
                            case 1:
                                //Imprime el aviso y llama a la funcion que muestra las recetas
                                puts("Estas son las recetas disponibles");
                                despliega_postres();
                                break;
                                
                            case 2:
                                //Llama al procedimiento que imprime la receta
                                puts("Ingresa el nombre de la receta que desear ver");
                                gets(receta_nueva);
                                recetas_postres(receta_nueva);
                                break;
                                
                            case 3:
                                //Vuelve al menu inicial despues de 2 segundos
                                puts("Regresando al menu inicial...");
                                sleep(2);
                                break;
                                
                            default:
                                //Si no se ingresa un valor correcto regresa al mismo menu
                                puts("No es una opcion correcta, vuelve a intentarlo");
                                sleep(2);
                                break;
                        }
                        }
                        //Mientras el valor de postres sea diferente de 3 se seguira ejecutando
                        while (postres != 3);
                        break;
                        
                    case 4:
                        //Vuelve al menu inicial despues de 2 segundos
                        puts("Regresando al menu inicial...");
                        sleep(2);
                        break;
                        
                    default:
                        //Si no es un valor correcto regresa al menu despues de dos segundos
                        puts("No es una opcion correcta, vuelve a intentarlo");
                        sleep(2);
                        break;
                }
                break;
            case 2:
                //Llama al procedimiento que muestra las referencias
                puts("Nuestras referencias para las recetas las puedes encontar en:");
                despliega_referencias();
                break;
                
            case 3:
                //Llama al procedimiento que escribe la receta que el usuario desea
                printf("Escribe el nombre de tu receta \n%s\n", nombre);
                //Pide el nombre de la receta
                gets(receta_nueva);
                //Llama al procedimiento para crear la nueva receta
                agregar_receta(receta_nueva, nombre);
                break;
                
            case 4:
                //Sale del programa despues de dos segundos
                puts("Buen provecho...");
                sleep(2);
                break;
                
            default:
                //Si no es un valor correcto regresa al menu despues de dos segundos
                puts("No es una opcion correcta, vuelve a intentarlo");
                sleep(2);
                break;
        }
    //Mientras el valor de recetas sea diferente de 4 se seguira ejecutando
    } while(recetas != 4);
}
