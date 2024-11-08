#include <stdio.h>
#include <string.h>

typedef struct {
    char position[20];
    char name[20];
    float salary;
} Employee;

int main() {
    Employee employees[3];

    // Preencher os dados dos funcionários
    strcpy(employees[0].position, "Manager");
    strcpy(employees[0].name, "Johnathan Doe Johnson");
    employees[0].salary = 5000.0;

    strcpy(employees[1].position, "Staff Engineer");
    strcpy(employees[1].name, "Jane Smith");
    employees[1].salary = 6000.0;

    strcpy(employees[2].position, "Data Analysis Specialist");
    strcpy(employees[2].name, "Mike Johnson");
    employees[2].salary = 5500.0;

    // Gravar os registros em um arquivo binário
    FILE *file = fopen("fixed_size_records.bin", "wb");
    // Escrever em modo binário no arquivo com fwrite
    fwrite(employees, sizeof(Employee), 3, file);
    fclose(file);

    // Ler os registros do arquivo binário
    file = fopen("fixed_size_records.bin", "rb");

    // Ler em modo binário do arquivo com fread, imprimindo o que for lido, 
    // da maneira que foi escrito, sem separar por registros e campos
    while (fgetc(file) != EOF)
    {
        printf("%c", fgetc(file));
    }
    fclose(file);
    
    return 0;
}
