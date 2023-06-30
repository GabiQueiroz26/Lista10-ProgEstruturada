#include <stdio.h>
#include <stdlib.h>

int main() {
	int colunas, linhas, vmax;
	int i, j, k, n;
    FILE *origem;
    FILE *destino;
    

	origem = fopen("gato.ppm", "r");
	destino = fopen("gatoVirado.ppm", "w");
    

    char buffer[250], tipo;
	fgets(buffer, 250, origem);
	tipo = buffer[1];
    fgets(buffer, 250, origem);
    fscanf(origem, "%d %d", &colunas, &linhas);
    fscanf(origem, "%d", &vmax);
    
    int matriz[linhas][colunas][3];
    
    if (tipo == '3') {
        for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            for (k = 0; k < 3; k++) {
            fscanf(origem, "%d", &matriz[i][j][k]);
            }
        }
        }
    } else if(tipo == 2) {
        for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            fscanf(origem, "%d", &n);
            for (k = 0; k < 3; k++) {
            matriz[i][j][k] = n;
            }
        }
        }
    }

    fprintf(destino, "P3\n");
    fprintf(destino, "#Feito por Gabriela\n");
    fprintf(destino, "%d %d\n", colunas, linhas);
    fprintf(destino, "%d\n", vmax);

    for(i = linhas -1; i >= 0; i--){
        for(j = 0 ; j < colunas; j++){
            for(k = 0; k < 3; k++){
                fprintf(destino, "%d ", matriz[i][j][k]);
            }
        }
        fprintf(destino, "\n");
    }

    fclose(origem);
    fclose(destino);

    return 0;
}
