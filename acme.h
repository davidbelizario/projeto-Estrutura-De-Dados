//nome: David Belizario Rodrigues – prontuário: gu3011631 – Turma: ADS2ºSEM.

//nome: Felipe Saldanha de Souza – prontuário: gu3011801 – Turma: ADS2ºSEM.

typedef struct funcionario{
   int ID;
   char Nome[120];
   char Endereco[200];
   int Idade;
   float Salario;
   char Cargo[60];
}FUNC;

//Aqui é declarado o struct que irá armazenar os valores inseridos em varios locais do codigo.
//O struct funcionario conta com 6 campos que serão utilizados por todo o codigo.

typedef struct elemento* Lista;

//Aqui é feito uma struct elemento com typedef de Lista para servir como ponteiro que entrará nas operações da lista ligada.

Lista *criaLista();

void apagaLista(Lista *li);

int listaVazia(Lista *li);

int insere_ordenado_lista(Lista *li, FUNC fc);

int remove_lista(Lista *li, int Id);

int consulta_lista_ID(Lista *li, int Id, FUNC *funci);

int listar_ordenado_ID(Lista *li);

int listar_amplitude_salario(Lista *li, float salarioMin, float salarioMax);

int alterar_lista_ID(Lista *li, int Id, FUNC *funcA, int Op);

//Declarações previas de todas as funções no "acme.c".
