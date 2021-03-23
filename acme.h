//nome: David Belizario Rodrigues � prontu�rio: gu3011631 � Turma: ADS2�SEM.

//nome: Felipe Saldanha de Souza � prontu�rio: gu3011801 � Turma: ADS2�SEM.

typedef struct funcionario{
   int ID;
   char Nome[120];
   char Endereco[200];
   int Idade;
   float Salario;
   char Cargo[60];
}FUNC;

//Aqui � declarado o struct que ir� armazenar os valores inseridos em varios locais do codigo.
//O struct funcionario conta com 6 campos que ser�o utilizados por todo o codigo.

typedef struct elemento* Lista;

//Aqui � feito uma struct elemento com typedef de Lista para servir como ponteiro que entrar� nas opera��es da lista ligada.

Lista *criaLista();

void apagaLista(Lista *li);

int listaVazia(Lista *li);

int insere_ordenado_lista(Lista *li, FUNC fc);

int remove_lista(Lista *li, int Id);

int consulta_lista_ID(Lista *li, int Id, FUNC *funci);

int listar_ordenado_ID(Lista *li);

int listar_amplitude_salario(Lista *li, float salarioMin, float salarioMax);

int alterar_lista_ID(Lista *li, int Id, FUNC *funcA, int Op);

//Declara��es previas de todas as fun��es no "acme.c".
