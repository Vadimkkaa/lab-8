#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
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
	k++;
	yy = k;
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
				getchar();
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

