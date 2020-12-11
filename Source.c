#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
//по-хорошему бы еще глобальные перенести в локальные...
int num = 0; //Индекс элемента в массиве words
int len = 0;
char* words; //Массив символов(содержит найденные симметричные слова) 
//int bb;
int yy;
void addLetter(char );
int main() {
	int g,z,r,kol=0,kol1=0,po=0,status=0,end1,vv,cc,bb,er;
	int w, n1, i, j, k, n, m ;
	char **str,*xx;
	printf("Vvedite kol-vo matric:\n");
	scanf_s("%d",&n1);
	fflush(stdin);
	printf("Vvedite kol-vo strok v matrice:\n");
	scanf_s("%d", &n);
	fflush(stdin);
	printf("Vvedite kol-vo stolbcov v matrice:\n");
	scanf_s("%d", &m);
	fflush(stdin);
	printf("Vvedite razmer stroki:\n");
	scanf_s("%d", &k);
    fflush(stdin);
	k+=2;
	yy = k;
	getchar();
	fflush(stdin);
	for (w = 1; w <=n1; w++) {//для движения по матрицам
		str = (char**)malloc(n * sizeof(char*));//для создания двумерной динамической матрицы
		if (!(str = (char**)malloc(n * sizeof(char*))))
			return 0;
		g = w;
		printf("Vvod %d matrici:\n",w);
		for (i = 0; i < n; i++) {
			str[i] = (char*)malloc(m * sizeof(char));
			if (!(str[i] = (char*)malloc(m * sizeof(char)))) {
				free(str[i]);
				free(str);
				return 0;
			}
			for (j = 0; j < m; j++) {
				xx = &str[i][j];//присваиваю указателю адрес элемента(и так много раз)
				xx = (char*)malloc(k * sizeof(char));//делаю динамический массив по этому указателю
				if (!(xx = (char*)malloc(k * sizeof(char)))) {
					free(xx);
					return 0;
				}
				//getchar();
				fgets(xx,k,stdin);//ввожу строку для этого элемента матрицы(указателя)
				//getchar();
				fflush(stdin);
				z = 0;
				while(xx[z]!='\0'&&xx[z]!='\n') {
					if (xx[z] == ' ') {//если пробел-избавляюсь от пробелов до буквы
						while (xx[z] == ' ') {
							kol1++;
							z++;
							if (xx[z] == '\0')
								break;
						}
					}
					if (xx[z] != ' '&&xx[z]!='\0'&&xx[z]!='\n') {//нашел букву-поехали считать сколько их в слове
						r = z;
						bb = r;
						er = bb;
						while (xx[z] != ' '&&xx[z]!='\0'&&xx[z]!='\n') {//сколько букв??
							kol++;
							z++;
						}

						if (kol > 2) {//интересуюсь словами большими чем 3 буквы

							if (kol>2&&kol % 2 == 0) {//условие для слов с четеным количеством букв
								end1 = r + kol - 1;//конец слова
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}										
									if (xx[r] == xx[end1]) {//проверка соотвествующих букв 
										r++;//сдвигаю с левого края слова
										end1--;//сдвиг с правого края слова
										if (r + 1 == end1 && xx[r] == xx[end1]) {//если по индексу и по значению уже граница и значения равны-подтверждение нужного слова
											if (status == 0) { //Копируем слово циклом в другой массив(words) и выводим его 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);

												}
												addLetter(' '); //Добавляем пробел в массив words для читаемости 
											}
											po++;
											status = 0;
											kol = 0;
											break;
										}
									}
								}
							}


							if (kol>2&&kol % 2 != 0) {//для нечетных слов
								end1 = r + kol - 1;
								vv = kol / 2;//нахожу середину слова (с округлением)
								cc = r;
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}
									if (xx[r] == xx[end1]) {
										if (kol == 3) {
											if (status == 0) { //Копируем слово циклом в другой массив(words) и выводим его 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //Добавляем пробел в массив words для читаемости 
											}
											kol = 0;
											po++;
											break;
										}
										r++;
										end1--;
										if (r + 1 ==cc+vv  && xx[r] == xx[end1]) {//провека по индексу приблизились к середине слова плюс равность индексов(например 3 и 5)
											if (status == 0) { //Копируем слово циклом в другой массив(words) и выводим его 
												for (bb; bb <=er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //Добавляем пробел в массив words для читаемости 
											}
											po++;
											status = 0;
											kol = 0;
											break;
										}
									}
								}
							}
							kol = 0;
						}
						kol = 0;
					}
				}
			}	
		}
	}
	//printf("po==%d",po); для кол-ва таких слов
	printf("\nYour arrange is- \n ");
	for (int t = 0; t <len; ++t) {
		printf("%c", words[t]);
	}
	return 0;
}
void addLetter(char sym) { //Функция для добавления символа в массив words 
	words = (char*)realloc(words, ++len * sizeof(char));//len всегда увеличивается на 1 так как добавляю по 1 букве с цикла в int main
	if (!words) {
		free(words);
		return 0;
	}

	//char* tmp = (char*)realloc(words, ++len * sizeof(char));
	/*if (tmp) {
		words = tmp; //Увеличиваем размер массива words 
		free(tmp);
	}
	else {
		printf("Realloc error");
		free(tmp);
		
	}*/
	words[num] = sym;
	num++;

}
/*Дано n1 матриц. Размер матрицы n*m. Каждый элемент матрицы – строка знаков длинной k. Слова в предложении разделены одним или несколькими пробелами.
Определить в каждом предложении количество слов, которые справа и слева читаются одинаково и записать их в массив.
*/





/*
Вариант Арсения-
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 

char* words; //Массив символов(содержит найденные симметричные слова) 
char** sentences;
int num = 0; //Индекс элемента в массиве words 
int len = 0; //Длина массива words (45 - самое большое слово в английском алфавите, но это не точно.. 
int* sizeOfsentence;
int status = 1; //Статус симметрии 
int sizeOfword = 0; //Кол-во букв в слове 
int countOfsentences = 0; //Кол-во предложений 
int countOfwords = 0; //Кол-во симметричных слов 
// Текст для отладки тенет овыф выа ывалж ыар sefsdkj fdjlksjdf ds d 2323 9ir023r0 fj9fJH 0E0(EFJ)(ef0E*)F(^F*&DT FG D*S&FDS&*D 3333 #$$# Дед А Б В ЛОЛ 

int isAlpha(unsigned char);
void addLetter(char);
void shutDown();

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "RU");
	words = (char*)calloc(len, sizeof(char));

	printf("Enter count of sentences:");
	scanf_s("%d", &countOfsentences);
	rewind(stdin);
	sizeOfsentence = (int*)calloc(countOfsentences, sizeof(int));
	sentences = (char**)calloc(countOfsentences, sizeof(char*));

	for (int s = 0; s < countOfsentences; ++s) {
		printf("Enter size of sentence %d:", s + 1);
		scanf_s("%d", &sizeOfsentence[s]);
		rewind(stdin);

		sentences[s] = (char*)calloc(++sizeOfsentence[s], sizeof(char));
		printf("Enter sentence:");
		fgets(sentences[s], sizeOfsentence[s], stdin);
		rewind(stdin);

		for (int z = 0; z < sizeOfsentence[s]; ++z) {
			sizeOfword = 0;
			status = 1; //Сброс значений по умолчанию 

			if (isAlpha(sentences[s][z])) { //Если буква, то считаем размер слова 
				if (z == 0) { //Страшные проверки 
					for (int i = z; i < sizeOfsentence[s]; ++i) {
						if (!isAlpha(sentences[s][i])) break;
						sizeOfword++;
					}
					if (sizeOfword <= sizeOfsentence[s] - 2) {
						if (sentences[s][z + sizeOfword] != ' ') {
							continue;
						}
					}
				}
				else {
					if (sentences[s][z - 1] == ' ') {
						for (int i = z; i < sizeOfsentence[s]; ++i) {
							if (!isAlpha(sentences[s][i])) break;
							sizeOfword++;
						}
					}
					if (sentences[s][z - 1] == ' ' && sentences[s][z + sizeOfword] != ' ') {
						if (sentences[s][z + sizeOfword] != '\n' && (z + sizeOfword < sizeOfsentence[s] - 1)) {
							continue;
						}
					}
				}
			}
			if (sizeOfword > 0) {
				int j = z + sizeOfword - 1; //Последняя буква в слове 
				for (int i = z; i < z + sizeOfword; ++i) { //Проверка на симметричность 
					if (sentences[s][i] != sentences[s][j] && (int)sentences[s][i] + 32 != (int)sentences[s][j] && (int)sentences[s][i] != (int)sentences[s][j] + 32) { //Проверка для заглавных 
						status = 0;
						break;
					}
					j--;
				}
				z += sizeOfword; //Главный цикл(идёт по предложению) пропускает проверенное слово 

				if (status) { //Копируем слово циклом в другой массив(words) и выводим его 
					printf("( ");
					for (int i = z - sizeOfword; i < z; ++i) {
						addLetter(sentences[s][i]);
						printf("%c", sentences[s][i]);
					}
					addLetter(' '); //Добавляем пробел в массив words для читаемости 
					countOfwords++; //Добавляем +1 к кол-ву симметричных слов 
					printf(" ) - Слово симметрично\n");
				}
				else {
					printf("Слово не симметрично\n");
				}
			}
		}
	}

	printf("\nМассив симметричных слов во всех предложениях - ( ");
	for (int i = 0; i < len; ++i) {
		printf("%c", words[i]);
	}
	printf(") - Количество: %d", countOfwords);

	shutDown();
	return 0;
}

int isAlpha(unsigned char sym) { //Функция для проверки на русские и английские буквы 
	if (((int)sym >= 65 && (int)sym <= 90) || ((int)sym >= 97 && (int)sym <= 122)) return 1;
	if (((int)sym >= 192 && (int)sym <= 255)) return 1;
	return 0;
}

void addLetter(char sym) { //Функция для добавления символа в массив words 
	char* tmp = (char*)realloc(words, ++len * sizeof(char));
	if (tmp) {
		words = tmp; //Увеличиваем размер массива words 
		free(tmp);
	}
	else {
		printf("Realloc error");
		free(tmp);
		shutDown();
	}
	words[num] = sym;
	num++;

}

void shutDown() { //Освобождение памяти (вынесена в функцию для экстренного завершения программы в случае ошибок выделения памяти) 
	free(words);
	free(sizeOfsentence);
	for (int i = 0; i < countOfsentences; ++i) {
		free(sentences[i]);
	}
	free(sentences);
}*/

