#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>


void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float leNumero() {
    float le;
    int retorno_scanf;

    while (1) {
        retorno_scanf = scanf("%f", &le);

        if (retorno_scanf == 1) {
            limpaBuffer();
            return le;
        }

        printf("Erro: Voce nao digitou um numero valido.\n");
        limpaBuffer(); 
        printf("\n");
    }
}

int leSequencia() {
    int le;
    int retorno_scanf;
    
    while (1) {
        retorno_scanf = scanf("%d", &le);
        if (retorno_scanf == 1) {
             limpaBuffer();
             if (le <= 2 && le >= 0) {
                 return le;
             }
        }
        printf("Erro: Voce nao digitou um numero valido.\n");
        limpaBuffer(); 
        printf("\n");
    }
}

void leString(char *buffer, int tam) {
    if (fgets(buffer, tam, stdin) != NULL) {
        size_t ln = strlen(buffer);
        if (ln > 0 && buffer[ln - 1] == '\n') {
            buffer[ln - 1] = '\0';
        }
    }
}	

void ex01() {
    double x, raiz_x, pot_x, res;
    printf("Nesse exercicio sera calculado o valor de f(x)=√x+(x/2)+x²\n\n");
    printf("Digite um numero inteiro valido para x: ");
    x = leNumero();
    raiz_x = sqrt(x);
    pot_x = pow(x, 2.0);
    res = raiz_x + (x / 2.0) + pot_x;
    printf("O valor do calculo foi  %.2lf\n", res);
}

void ex02() {
    int x, y;
    printf("Nesse exercicio sera invertido o valor das variaveis \n\n");
    printf("Digite um numero inteiro valido: ");
    x = (int)leNumero();
    printf("Digite um numero inteiro valido: ");
    y = (int)leNumero();
    x += y;
    y = x - y;
    x -= y;
    printf("A inversao ficou %d %d\n", x, y);
}

void ex03() {
    float L[3], s, sl[3], A, as;
    int i, c = 1;
    char t[50];
    printf("Nesse exercicio sera pedido os valore dos lados e depois mostrado a are e seu tipo de triangulo\n");
    do {
        for (i = 0; i < 3; i++) {
            
            printf("Digite o valor do lado %d: ", i + 1);
            L[i] = leNumero();
        }
        printf("--------------------------------\n");

        if ((L[0] + L[1]) <= L[2] || (L[0] + L[2]) <= L[1] || (L[1] + L[2]) <= L[0]) {
            printf("Os lados informados nao formam um triangulo, digite novamente.\n");
            printf("--------------------------------\n");
        } else {
            c = 0;
        }
    } while (c == 1);

    s = (L[0] + L[1] + L[2]) / 2.0;
    as = s;
    for (i = 0; i < 3; i++) {
        sl[i] = s - L[i];
        as *= sl[i];
    }
    A = sqrt(as);


    if (L[0] == L[1] && L[1] == L[2]) {
        strcpy(t, "equilatero");
    } else if (L[0] == L[1] || L[1] == L[2] || L[0] == L[2]) {
        strcpy(t, "isoceles");
    } else {
        strcpy(t, "escaleno");
    }

    printf("O triangulo e do tipo %s com %.4f de area.\n", t, A);
}

void ex04() {
    char tip[10], vol[10];
    float c, f, tem;
    printf("Conversor de temperatura\n\n");
    
    printf("Digite a temperatura: ");
    tem = leNumero();
    
    printf("Qual o tipo de temperatura?\nDigite F para Fahrenheit e C para Celsius: ");
    leString(tip, sizeof(tip));

    if (strcmp(tip, "f") == 0 || strcmp(tip, "F") == 0) {
        c = (tem - 32.0) * 5.0 / 9.0;
        printf("A temperatura em Celsius e %.2f\n", c);         
    } 
    else if (strcmp(tip, "c") == 0 || strcmp(tip, "C") == 0) {
        f = (tem * 9.0) / 5.0 + 32.0;
        printf("A temperatura em Fahrenheit e %.2f\n", f); 
    }    
     
}

void ex05() {
    
    int j, i, c, l, dias, dia, r, di, dj, ni, nj, estado_atual;
    int mundo[50][50], proximo[50][50];
    r=1;
    printf("Descricao: Programa de simulacao de interacoes humano/zumbi em uma grade 2D com condicoes de contorno toroidais. A cada dia iteracao, o estado de cada posicao e atualizado com base nos seus 8 vizinhos do dia anterior.\n Regras:\n - Humano 1 com >= 1 vizinho Zumbi 2 -> Torna-se Zumbi 2\n - Zumbi 2 com >= 2 vizinhos Humanos 1 -> Morre, fica Vazio 0\n- Zumbi 2 com 0 vizinhos Humanos 1 -> Morre de fome, fica Vazio 0\n- Vazio 0 com exatamente 2 vizinhos Humanos 1 -> Nasce Humano 1\n- Caso contrario -> Permanece no estado atual.\n\n");
    do {
        printf("Digite o numero de linhas e colunas:\n");
        l = leNumero();
        c = leNumero();
        if (l < 2 || c < 2) {
            printf("digite um numero maior que 1:\n\n");
        } else {
            r=0;
        }
    }while (r==1);
    r = 1;
    do {
        printf("Digite o numero de dias:\n");
        dias = leNumero();
        if (dias == 0) {
            printf("digite um numero maior que 0:\n\n");
        } else {
            r=0;
        }
    }while (r==1);
    printf("Digite os valores entre 0 a 2:\n");
    for (i=0; i < l; i++ ) {
        for (j=0; j < c; j++) {
            mundo[i][j] = leSequencia(); 
        }    
    }
    for (dia = 0; dia<=dias; dia++){
        
        printf("\nDia %d\n\n", dia);    
        for (i=0; i < l; i++ ) {
            for (j=0; j < c; j++) {
                printf("%d%s", mundo[i][j], (j == c - 1) ? "" : " ");
            }  
            printf("\n");
        } 
        if (dia == dias) {
            break;
        }  
        for (i = 0; i < l; i++) {
            for (j = 0; j < c; j++) {
                int humano = 0;
                int zumbi = 0;
    
                for (di = -1; di <= 1; di++) {
                    for (dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue; 
                        
                        ni = (i + di + l) % l;
                        nj = (j + dj + c) % c;
    
                        if (mundo[ni][nj] == 1) {
                            humano++;
                        } else if (mundo[ni][nj] == 2) {
                            zumbi++;
                        }                                  
                    } 
                }
                estado_atual = mundo[i][j];
    
                if (estado_atual == 1) {
                    if (zumbi >= 1) {
                        proximo[i][j] = 2;
                    } else {
                        proximo[i][j] = 1;
                    }                                    
                } else if (estado_atual == 2) {
                    if (humano >= 2 || humano == 0) {
                        proximo[i][j] = 0;    
                    } else {
                        proximo[i][j] = 2;
                    }                                     
                } else {
                    if (humano ==2) {
                        proximo[i][j] = 1;    
                    } else {
                        proximo[i][j] = 0; 
                    }
                }
            }              
        }
        for (i=0; i < l; i++ ) {
            for (j=0; j < c; j++) {
                mundo[i][j] = proximo[i][j];
            }    
        }              
    }
}


void menu() {
    int input;
    printf("--------------------------------\n");
    do {
        printf("Escolha o exercicio (1 a 5) ou 0 para encerrar: ");
        input = (int)leNumero();
        printf("--------------------------------\n");
    
        switch (input) {
            case 0:
                printf("Programa encerrado.");
                break;
            case 1:
                ex01();
                break;
            case 2:
                ex02();
                break;
            case 3:
                ex03();
                break;
            case 4:
                ex04();
                break;
                case 5:
                ex05();
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (input != 0);       
}

int main() {
    char senha[51], confirmar_senha[51];
    int total_erros = 1; 

    while (total_erros > 0) {
        int tam, i;   
        total_erros = 0;
        int tem_oito_caracteres = 0;
        int tem_maiuscula = 0;
        int tem_minuscula = 0;
        int tem_numero = 0;
        int tem_simbolo = 0;

        printf("Crie uma senha: ");
        leString(senha, sizeof(senha));
        tam = strlen(senha);

        if (tam >= 8) {  
            tem_oito_caracteres = 1;         
        }    

        for (i = 0; i < tam; i++) {
            char c = senha[i];
            
            if (isupper((unsigned char)c)) {
                tem_maiuscula = 1;
            } else if (islower((unsigned char)c)) {
                tem_minuscula = 1;
            } else if (isdigit((unsigned char)c)) {
                tem_numero = 1;
            }

            if (c == '!' || c == '?' || c == '#' || c == '@' || c == '$') {
                tem_simbolo = 1;
            }
        }   

        if (!tem_oito_caracteres) {
            printf("A senha deve conter pelo menos 8 caracteres\n");
            total_erros++;
        }
        if (!tem_maiuscula) {
            printf("A senha deve conter pelo menos uma letra maiuscula\n");
            total_erros++;
        }
        if (!tem_minuscula) {
            printf("A senha deve conter pelo menos uma letra minuscula\n");
            total_erros++;
        }
        if (!tem_numero) {
            printf("A senha deve conter pelo menos um numero\n");
            total_erros++;
        }
        if (!tem_simbolo) {
            printf("A senha deve conter pelo menos um simbolo\n");
            total_erros++;
        }

        if (total_erros == 0) {
            printf("Senha cadastrada com sucesso!\n");
        }  
    }

    printf("--------------------------------\n");    for (int j = 4; j > 0; j--){
        printf("Digite sua senha novamente para confirmar: ");
        leString(confirmar_senha, sizeof(confirmar_senha));
        
        if (strcmp(confirmar_senha, senha) == 0) { 
            printf("Senha correta!\n");
            menu();
            break;
        } else {
            printf("Senha incorreta! Acesso negado.\n\n ");
            if (j == 1){
            printf("Voce excedeu o limite de tentativas.");
            break;
            }
            printf("Voce tem mais %d chances para acertar a senha \n", j - 1);
        }           
    }
    return 0;
}
