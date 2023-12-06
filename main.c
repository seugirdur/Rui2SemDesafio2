#include <stdio.h>

struct Consulta {
    char medico[50];
    char celular[15];
    char data_consulta[20];
};

void entradaDados(FILE *arquivo);
void listaTodosDados(FILE *arquivo);
void pesquisarMedico(FILE *arquivo);
void pesquisarNomePorCelular(FILE *arquivo);
void pesquisarDataConsulta(FILE *arquivo);
void alteraDados(FILE *arquivo);
void excluiDados(FILE *arquivo);

int main() {
    FILE *arquivo;
    arquivo = fopen("dados_consulta.txt", "r+");

    if (arquivo == NULL) {
        arquivo = fopen("dados_consulta.txt", "w+");
        if (arquivo == NULL) {
            printf("Erro ao criar ou abrir o arquivo de dados da consulta.\n");
            return 1;
        }
    }

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Entrada de dados\n");
        printf("2. Lista todos os dados\n");
        printf("3. Pesquisar um medico pelo nome completo\n");
        printf("4. Pesquisar um celular pelo nome completo\n");
        printf("5. Pesquisar pela data da consulta\n");
        printf("6. Alterar dados (pesquisa pelo nome completo)\n");
        printf("7. Excluir dados (pesquisa pelo nome completo)\n");
        printf("8. Saida\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                entradaDados(arquivo);
                break;
            case 2:
                listaTodosDados(arquivo);
                break;
            case 3:
                pesquisarMedico(arquivo);
                break;
            case 4:
                pesquisarNomePorCelular(arquivo);
                break;
            case 5:
                pesquisarDataConsulta(arquivo);
                break;
            case 6:
                alteraDados(arquivo);
                break;
            case 7:
                excluiDados(arquivo);
                break;
            case 8:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    fclose(arquivo);

    return 0;
}

void entradaDados(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_END);

    struct Consulta consulta;
    printf("\nEntrada de dados:\n");
    printf("Medico: ");
    scanf("%s", consulta.medico);
    printf("Celular: ");
    scanf("%s", consulta.celular);
    printf("Data da consulta: ");
    scanf("%s", consulta.data_consulta);

    fwrite(&consulta, sizeof(struct Consulta), 1, arquivo);

    printf("Dados inseridos com sucesso.\n");
}

void listaTodosDados(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Consulta consulta;

    printf("\nLista de todos os dados:\n");

    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo) == 1) {
        printf("\nMedico: %s\n", consulta.medico);
        printf("Celular: %s\n", consulta.celular);
        printf("Data da consulta: %s\n", consulta.data_consulta);
    }
}

void pesquisarMedico(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Consulta consulta;
    char medico[50];

    printf("\nDigite o nome do medico para pesquisar: ");
    scanf("%s", medico);

    int encontrado = 0;

    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo) == 1) {
        int i;
        for (i = 0; consulta.medico[i] != '\0' && medico[i] != '\0'; ++i) {
            if (consulta.medico[i] != medico[i]) {
                break;
            }
        }

        if (consulta.medico[i] == '\0' && medico[i] == '\0') {
            printf("\nMedico encontrado:\n");
            printf("Medico: %s\n", consulta.medico);
            printf("Celular: %s\n", consulta.celular);
            printf("Data da consulta: %s\n", consulta.data_consulta);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Medico nao encontrado.\n");
    }
}

void pesquisarNomePorCelular(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Consulta consulta;
    char celular[15];

    printf("\nDigite o celular para pesquisar: ");
    scanf("%s", celular);

    int encontrado = 0;

    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo) == 1) {
        int i;
        for (i = 0; consulta.celular[i] != '\0' && celular[i] != '\0'; ++i) {
            if (consulta.celular[i] != celular[i]) {
                break;
            }
        }

        if (consulta.celular[i] == '\0' && celular[i] == '\0') {
            printf("\nNome encontrado com base no celular:\n");
            printf("Medico: %s\n", consulta.medico);
            printf("Celular: %s\n", consulta.celular);
            printf("Data da consulta: %s\n", consulta.data_consulta);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nome nao encontrado com base no celular.\n");
    }
}


void pesquisarDataConsulta(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Consulta consulta;
    char data[20];

    printf("\nDigite a data da consulta para pesquisar: ");
    scanf("%s", data);

    int encontrado = 0;

    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo) == 1) {
        int i;
        for (i = 0; consulta.data_consulta[i] != '\0' && data[i] != '\0'; ++i) {
            if (consulta.data_consulta[i] != data[i]) {
                break;
            }
        }

        if (consulta.data_consulta[i] == '\0' && data[i] == '\0') {
            printf("\nConsulta encontrada:\n");
            printf("Medico: %s\n", consulta.medico);
            printf("Celular: %s\n", consulta.celular);
            printf("Data da consulta: %s\n", consulta.data_consulta);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Consulta nao encontrada.\n");
    }
}

void alteraDados(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Consulta consulta;
    char medico[50];

    printf("\nDigite o nome do medico para alterar: ");
    scanf("%s", medico);

    int encontrado = 0;

    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo) == 1) {
        int i;
        for (i = 0; consulta.medico[i] != '\0' && medico[i] != '\0'; ++i) {
            if (consulta.medico[i] != medico[i]) {
                break;
            }
        }

        if (consulta.medico[i] == '\0' && medico[i] == '\0') {
            encontrado = 1;
            printf("\nAlterando os dados:\n");
            printf("Novo Medico: ");
            scanf("%s", consulta.medico);
            printf("Novo Celular: ");
            scanf("%s", consulta.celular);
            printf("Nova Data da consulta: ");
            scanf("%s", consulta.data_consulta);

            fseek(arquivo, -sizeof(struct Consulta), SEEK_CUR);
            fwrite(&consulta, sizeof(struct Consulta), 1, arquivo);
            printf("Dados alterados com sucesso.\n");

            break;
        }
    }

    if (!encontrado) {
        printf("Medico nao encontrado.\n");
    }
}

void excluiDados(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_SET);

    struct Consulta consulta;
    char medico[50];

    printf("\nDigite o nome do medico para excluir: ");
    scanf("%s", medico);

    int encontrado = 0;

    while (fread(&consulta, sizeof(struct Consulta), 1, arquivo) == 1) {
        int i;
        for (i = 0; consulta.medico[i] != '\0' && medico[i] != '\0'; ++i) {
            if (consulta.medico[i] != medico[i]) {
                break;
            }
        }

        if (consulta.medico[i] == '\0' && medico[i] == '\0') {
            encontrado = 1;


            consulta.medico[0] = '\0';
            consulta.celular[0] = '\0';
            consulta.data_consulta[0] = '\0';

            fseek(arquivo, -sizeof(struct Consulta), SEEK_CUR);
            fwrite(&consulta, sizeof(struct Consulta), 1, arquivo);
            printf("Dados excluídos com sucesso.\n");

            break;
        }
    }

    if (!encontrado) {
        printf("Medico nao encontrado.\n");
    }
}