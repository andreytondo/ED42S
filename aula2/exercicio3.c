/*
3. (Exercício extraído do livro SCHILDT, Herbert, C Completo e Total, 3ª edição). Identifique
qual é o problema do código:
void main(void) {
 int x, *p;
 x = 10;
 *p = x;
}

O ponteiro p não foi inicializado, logo, não aponta para lugar nenhum.
*/