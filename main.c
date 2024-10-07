#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lista.h"

#define ALTURA 20
#define LARGURA 50

LISTA cobrinha;
NO maca;

int recorde;

char sentido = 'e';
// 'e' => esqueda
// 'd' => direita
// 'c' => cima
// 'b' => baixo

char cenario[ALTURA + 1][LARGURA + 1];

void tela_inicial();
void gerar_cenario();
void gerar_maca();
void imprimir_cenario();
void game_over();
void mover_cobrinha(char movimento);
void ler_recorde();
void salvar_recorde();

void start();


int main(void) {

  system("clear");
  
  printf("\n");
  printf("               ████████████████      \n");
  printf("            ████  ██░░░░██  ██▒▒████   \n");
  printf("          ██      ██░░██      ██▒▒▒▒██   \n");
  printf("        ██      ██░░░░██        ██▒▒██   \n");
  printf("      ██      ████░░████        ██▒▒██   \n");
  printf("      ██    ██████░░██████      ██▒▒▒▒██ \n");
  printf("      ██    ██████░░██████      ██▒▒▒▒██ \n");
  printf("      ██    ████░░░░██████      ██▒▒▒▒██ \n");
  printf("      ██      ██░░░░████      ██▒▒▒▒▒▒██ \n");
  printf("      ████████░░░░░░██      ██▒▒▒▒▒▒▒▒██ \n");
  printf("      ██▒▒▒▒▒▒░░░░░░░░██████▒▒▒▒▒▒▒▒▒▒██ \n");
  printf("        ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██\n");
  printf("          ████████████████████▒▒▒▒▒▒██\n");
  printf("       ▒▒▒▒▒▒▒▒██▒▒▒▒▒▒▒▒▒▒▒██\n");
  printf("       ▒▒▒▒▒▒▒▒  ████▒▒▒▒▒▒▒██\n");
  printf("   ▒▒▒▒▒▒▒▒▒▒    ██    ▒▒▒▒▒▒████████\n");
  printf(" ▒▒▒▒▒▒▒▒▒▒    ██░░░░░░░░▒▒▒▒████▒▒▒▒▒▒██\n");
  printf("▒▒▒▒▒▒▒▒        ██        ▒▒▒▒██▒▒▒▒▒▒▒▒██\n");
  printf("▒▒▒▒▒▒▒▒        ██░░░░░░░░▒▒▒▒██▒▒▒▒▒▒▒▒▓▓███\n");
  printf("  ▒▒▒▒░░          ██░░░░░░▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▒█████\n");
  printf("  ░░░░            ██░░░░░░▒▒░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n");
  printf("                  ██░░░░░░▒▒▒▒▒▒▒▒██  ██  ▒▒▒▒▒▒▒▒██\n");
  printf("                    ██░░░░░░▒▒▒▒██      ██  ▒▒████\n");
  printf("                      ██████████        ██████\n\n");
  
  printf("         Câmara Secreta Productions Present           \n");
  printf("              Por Matheus Nascimento                  ");   
  
  char enter[12];
  //void start();
  fgets(enter, 12, stdin);
  system("clear");
  
  NO no1 = {10,21}, no2 = {10,22};
  
  criar(&cobrinha,12);
  inserir(&cobrinha, no1);
  inserir(&cobrinha, no2);

  char comando;

  gerar_cenario();
  gerar_maca();
  
  
  printf("\n");
  tela_inicial();
  //scanf(" %c", &comando);
  fgets(enter, 12, stdin);
  system("clear");

  ler_recorde();

  //Loop do jogo
  while(1){
    
    gerar_cenario();
    imprimir_cenario();
    printf("   ----------------           ------------------\n");
    printf("     Recorde: %d                Pontuação: %d\n", recorde, cobrinha.pos - 2);
    printf("   ----------------           ------------------\n");

    //printf("\n");

    do{
      printf("Digite o sentido que deseja andar: ");
      scanf(" %c", &comando);
    } while ((comando != 'a') && (comando != 'w') && (comando != 's') && (comando != 'd') && (comando != 'S'));
    

    //Saida voluntária do jogo
    if (comando == 'S'){
      game_over();
      printf("                  Você desistiu!\n");
      printf("\n");
      printf("                   Pontuação: %d\n", cobrinha.pos - 2);
      break;
    }
    
    if (comando == 'a'){
      if (sentido == 'd'){
        for (int i = 0; i < tamanho(&cobrinha); i++)
          cobrinha.arr[i].y++;
      } else
          mover_cobrinha(comando);
    } else if (comando == 'w'){
      if (sentido == 'b'){
        for (int i = 0; i < tamanho(&cobrinha); i++)
          cobrinha.arr[i].x++;
      } else
          mover_cobrinha(comando);
    }
    else if (comando == 's'){
      if (sentido == 'c'){
        for (int i = 0; i < tamanho(&cobrinha); i++)
          cobrinha.arr[i].x--;
      } else 
          mover_cobrinha(comando);
    } else {
      if (sentido == 'e'){
        for (int i = 0; i < tamanho(&cobrinha); i++)
          cobrinha.arr[i].y--;
      } else 
          mover_cobrinha(comando);
    }

    if (cenario[cobrinha.arr[0].x][cobrinha.arr[0].y] == '@'){
      gerar_maca();
      if (sentido == 'e'){
        NO no = {cobrinha.arr[cobrinha.pos - 1].x, cobrinha.arr[cobrinha.pos - 1].y + 1};
        inserir_v2(&cobrinha,no);
      } else if (sentido == 'c'){
        NO no = {cobrinha.arr[cobrinha.pos - 1].x + 1, cobrinha.arr[cobrinha.pos - 1].y};
        inserir_v2(&cobrinha,no);
      } else if (sentido == 'd'){
        NO no = {cobrinha.arr[cobrinha.pos - 1].x, cobrinha.arr[cobrinha.pos - 1].y - 1};
        inserir_v2(&cobrinha,no);
      } else {
        NO no = {cobrinha.arr[cobrinha.pos - 1].x - 1, cobrinha.arr[cobrinha.pos - 1].y};
        inserir_v2(&cobrinha,no);
      }
    } else if (cenario[cobrinha.arr[0].x][cobrinha.arr[0].y] == 'o'){
      game_over();
      printf("          Você devorou seu próprio corpo!\n");
      printf("\n");
      printf("                   Pontuação: %d\n", cobrinha.pos - 2);
      break;
    } else if (cenario[cobrinha.arr[0].x][cobrinha.arr[0].y] == '#'){
      game_over();
      printf("           Você devorou arame farpado!\n");
      printf("\n");
      printf("                  Pontuação: %d\n", cobrinha.pos - 2);
      break;
    }
    
    printf("\n");
    system("clear");
  }

  salvar_recorde();
  
  return 0;
}

//Funções do jogo

void tela_inicial(){
  printf("          ┏┳         ┓    ┏┓  ┓   •  ┓    \n");
  printf("           ┃┏┓┏┓┏┓  ┏┫┏┓  ┃ ┏┓┣┓┏┓┓┏┓┣┓┏┓\n");
  printf("          ┗┛┗┛┗┫┗┛  ┗┻┗┻  ┗┛┗┛┗┛┛ ┗┛┗┛┗┗┻\n");
  printf("               ┛                         \n");
  printf("   Bem vindo ao jogo que você já sabe como funciona.\n");
  printf("Seu objetivo é comer as maçãs para pontuar e evitar \n");
  printf("devorar as cercas ou o seu próprio corpo. Para mover\n");
  printf("a cobrinha use os caracteres 'a', 'w', 's' e 'd', se\n");
  printf("digitar outra letra será pedido que digite novamente\n");
  printf("até que informe um movimento válido. O jogo pode ser\n");
  printf("interrompido a qualquer momento com a letra 'S'.\n");
  printf("                                          ____\n");
  printf("                                         / . .\\ \n");
  printf("        Digite enter para começar        \\  ---<\n");
  printf("                                          \\  /\n");
  printf("                                __________/ /\n");
  printf("                             -=:___________/\n");
}

void gerar_cenario(){
  //Coloca o cenário
  for (int i = 0; i < ALTURA; i++)
    for (int j = 0; j < LARGURA; j++){
      if ((i == 0) || (j == 0))
        cenario[i][j] = '#';
      else if ((i == ALTURA - 1) || (j == LARGURA - 1))
        cenario[i][j] = '#';
      else
        cenario[i][j] = ' ';
    }

  //Coloca a cobrinha
  cenario[cobrinha.arr[0].x][cobrinha.arr[0].y] = 'O';
  for (int i = 1; i < tamanho(&cobrinha); i++)
    cenario[cobrinha.arr[i].x][cobrinha.arr[i].y] = 'o';

  //Colocar maça
  cenario[maca.x][maca.y] = '@';
}

void gerar_maca(){
  srand(time(NULL));
  do {
    maca.x = rand()%ALTURA;
    maca.y = rand()%LARGURA;
  } while(cenario[maca.x][maca.y] != ' ');
}

void imprimir_cenario(){
  //Font Name: tmplr
  printf("\n");
  printf("           ┏┳         ┓    ┏┓  ┓   •  ┓    \n");
  printf("            ┃┏┓┏┓┏┓  ┏┫┏┓  ┃ ┏┓┣┓┏┓┓┏┓┣┓┏┓\n");
  printf("           ┗┛┗┛┗┫┗┛  ┗┻┗┻  ┗┛┗┛┗┛┛ ┗┛┗┛┗┗┻\n");
  printf("                ┛                         \n");
  int j;
  for (int i = 0; i < ALTURA; i++){
    printf(" ");
    for (j = 0; j < LARGURA - 1; j++)
      printf("%c",cenario[i][j]);
    printf("%c\n",cenario[i][j]);
  }
}

void game_over(){
  system("clear");
  imprimir_cenario();
  printf("                ┏┓         ┏┓      ╻\n");
  printf("                ┃┓┏┓┏┳┓┏┓  ┃┃┓┏┏┓┏┓┃\n");
  printf("                ┗┛┗┻┛┗┗┗   ┗┛┗┛┗ ┛ •\n");
}

void mover_cobrinha(char movimento){
  for (int i = tamanho(&cobrinha) - 1; i > 0; i--){
    cobrinha.arr[i].x = cobrinha.arr[i - 1].x;
    cobrinha.arr[i].y = cobrinha.arr[i - 1].y;
  }
  if (movimento == 'a'){
    cobrinha.arr[0].y--;
    sentido = 'e';
  } else if (movimento == 'd'){
    cobrinha.arr[0].y++;
    sentido = 'd';
  } else if (movimento == 'w'){
    cobrinha.arr[0].x--;
    sentido = 'c';
  } else if (movimento == 's'){
    cobrinha.arr[0].x++;
    sentido = 'b';
  }
}

void ler_recorde(){
  FILE *file;
  int i = 0;
  char c, valor[12];
  
  if ((file = fopen("recorde.txt", "r")) != NULL){
    while ((c = fgetc(file)) != EOF)
      valor[i++] = c;
    valor[i] = '\0';
  }
  
  recorde = atoi(valor);
  fclose(file);
}

void salvar_recorde(){
  if(cobrinha.pos - 2 > recorde){
    FILE *file;
    if ((file = fopen("recorde.txt", "w")) != NULL){
      fprintf(file, "%d", cobrinha.pos - 2);
      printf("     Parabéns!! Você estabeleceu um novo recorde!\n");
    }
    fclose(file);
  }
}
