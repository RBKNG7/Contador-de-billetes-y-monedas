#include <stdio.h>
#define B 7
#define M 8
float de_cents_a_euros(int total)
{
    return total/100.0;
}

int total_cents(int monedas[], int valor[])
{
    int total = 0;
    for (int i = 0; i < M; i++) {
        total += monedas[i] * valor[i];
    }
    return total;
}

int total_euros(int billetes[],int valor[])
{
    int total = 0;
    for (int i = 0; i < B; i++) {
        total += billetes[i] * valor[i];
    }
    return total;
}

float monedas()
{
    int monedas[M];
    int valor[M] = {1, 2, 5, 10, 20, 50, 100, 200}; 
    float total;
    char *names[M] = {"1cent", "2cent", "5cent", "10cent", "20cent", "50cent", "1 euro", "2 euros"};

    for (int i = 0; i < M; i++) {
        printf("Monedas de %s: ", names[i]);
        scanf("%d", &monedas[i]);
    }
    total = de_cents_a_euros(total_cents(monedas, valor));
    printf("Hay un total de \033[33m%.2f€\033[0m en monedas \n", total);

    return total;
}

int billetes()
{
    int billetes[B], total;
    int valor[B] = {5, 10, 20, 50, 100, 200, 500};
    char *names[B] = {"5 euros", "10 euros", "20 euros", "50 euros", "100 euros", "200 euros", "500 euros"};
    
    for (int i = 0; i < B; i++) {
        printf("Billetes de %s: ", names[i]);
        scanf("%d", &billetes[i]);
    }
    total = total_euros(billetes, valor);
    printf("Hay un total de \033[32m%d€ en billetes\033[0m\n", total); 

    return total;
}

void billetes_y_monedas()
{
    printf("Hay un total de \033[32m%.2f€\033[0m\n", billetes() + monedas());
}

int main()
{
    unsigned int opcion;
    do{
        printf("¿Qué quieres contar?\n");
        printf("\t1: Monedas\n");
        printf("\t2: Billetes\n");
        printf("\t3: Billetes y monedas\n");
        printf("\t4: Salir\n");
        scanf("%d", &opcion);
        
        switch(opcion){
            case 1: monedas();
            break;
            case 2: billetes();
            break;
            case 3: billetes_y_monedas();
            break;
        }
    }while(opcion != 4);
    
    printf("\033[31mSaliendo...\033[0m\n");
    
    return 0;
}
