#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<locale.h>
int num = 0; //������ �������� � ������� words
int len = 0;
char* words; //������ ��������(�������� ��������� ������������ �����) 
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
	for (w = 1; w <=n1; w++) {//��� �������� �� ��������
		str = (char**)malloc(n * sizeof(char*));//��� �������� ��������� ������������ �������
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
				xx = &str[i][j];//���������� ��������� ����� ��������(� ��� ����� ���)
				xx = (char*)malloc(k * sizeof(char));//����� ������������ ������ �� ����� ���������
				if (!(xx = (char*)malloc(k * sizeof(char)))) {
					free(xx);
					return 0;
				}
				getchar();
				fgets(xx,k,stdin);//����� ������ ��� ����� �������� �������(���������)
				//getchar();
				fflush(stdin);
				z = 0;
				while(xx[z]!='\0'&&xx[z]!='\n') {
					if (xx[z] == ' ') {//���� ������-���������� �� �������� �� �����
						while (xx[z] == ' ') {
							kol1++;
							z++;
							if (xx[z] == '\0')
								break;
						}
					}
					if (xx[z] != ' '&&xx[z]!='\0'&&xx[z]!='\n') {//����� �����-������� ������� ������� �� � �����
						r = z;
						bb = r;
						er = bb;
						while (xx[z] != ' '&&xx[z]!='\0'&&xx[z]!='\n') {//������� ����??
							kol++;
							z++;
						}

						if (kol > 2) {//����������� ������� �������� ��� 3 �����

							if (kol>2&&kol % 2 == 0) {//������� ��� ���� � ������� ����������� ����
								end1 = r + kol - 1;//����� �����
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}										
									if (xx[r] == xx[end1]) {//�������� �������������� ���� 
										r++;//������� � ������ ���� �����
										end1--;//����� � ������� ���� �����
										if (r + 1 == end1 && xx[r] == xx[end1]) {//���� �� ������� � �� �������� ��� ������� � �������� �����-������������� ������� �����
											if (status == 0) { //�������� ����� ������ � ������ ������(words) � ������� ��� 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);

												}
												addLetter(' '); //��������� ������ � ������ words ��� ���������� 
											}
											po++;
											status = 0;
											kol = 0;
											break;
										}
									}
								}
							}


							if (kol>2&&kol % 2 != 0) {//��� �������� ����
								end1 = r + kol - 1;
								vv = kol / 2;//������ �������� ����� (� �����������)
								cc = r;
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}
									if (xx[r] == xx[end1]) {
										if (kol == 3) {
											if (status == 0) { //�������� ����� ������ � ������ ������(words) � ������� ��� 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //��������� ������ � ������ words ��� ���������� 
											}
											kol = 0;
											po++;
											break;
										}
										r++;
										end1--;
										if (r + 1 ==cc+vv  && xx[r] == xx[end1]) {//������� �� ������� ������������ � �������� ����� ���� �������� ��������(�������� 3 � 5)
											if (status == 0) { //�������� ����� ������ � ������ ������(words) � ������� ��� 
												for (bb; bb <=er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //��������� ������ � ������ words ��� ���������� 
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
	//printf("po==%d",po); ��� ���-�� ����� ����
	printf("\nYour arrange is- \n ");
	for (int t = 0; t <len; ++t) {
		printf("%c", words[t]);
	}
	return 0;
}
void addLetter(char sym) { //������� ��� ���������� ������� � ������ words 
	words = (char*)realloc(words, ++len * sizeof(char));//len ������ ������������� �� 1 ��� ��� �������� �� 1 ����� � ����� � int main
	if (!words) {
		free(words);
		return 0;
	}

	//char* tmp = (char*)realloc(words, ++len * sizeof(char));
	/*if (tmp) {
		words = tmp; //����������� ������ ������� words 
		free(tmp);
	}
	else {
		printf("Realloc error");
		free(tmp);
		
	}*/
	words[num] = sym;
	num++;

}
/*���� n1 ������. ������ ������� n*m. ������ ������� ������� � ������ ������ ������� k. ����� � ����������� ��������� ����� ��� ����������� ���������.
���������� � ������ ����������� ���������� ����, ������� ������ � ����� �������� ��������� � �������� �� � ������.
*/





/*
������� �������-
#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 

char* words; //������ ��������(�������� ��������� ������������ �����) 
char** sentences;
int num = 0; //������ �������� � ������� words 
int len = 0; //����� ������� words (45 - ����� ������� ����� � ���������� ��������, �� ��� �� �����.. 
int* sizeOfsentence;
int status = 1; //������ ��������� 
int sizeOfword = 0; //���-�� ���� � ����� 
int countOfsentences = 0; //���-�� ����������� 
int countOfwords = 0; //���-�� ������������ ���� 
// ����� ��� ������� ����� ���� ��� ����� ��� sefsdkj fdjlksjdf ds d 2323 9ir023r0 fj9fJH 0E0(EFJ)(ef0E*)F(^F*&DT FG D*S&FDS&*D 3333 #$$# ��� � � � ��� 

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
			status = 1; //����� �������� �� ��������� 

			if (isAlpha(sentences[s][z])) { //���� �����, �� ������� ������ ����� 
				if (z == 0) { //�������� �������� 
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
				int j = z + sizeOfword - 1; //��������� ����� � ����� 
				for (int i = z; i < z + sizeOfword; ++i) { //�������� �� �������������� 
					if (sentences[s][i] != sentences[s][j] && (int)sentences[s][i] + 32 != (int)sentences[s][j] && (int)sentences[s][i] != (int)sentences[s][j] + 32) { //�������� ��� ��������� 
						status = 0;
						break;
					}
					j--;
				}
				z += sizeOfword; //������� ����(��� �� �����������) ���������� ����������� ����� 

				if (status) { //�������� ����� ������ � ������ ������(words) � ������� ��� 
					printf("( ");
					for (int i = z - sizeOfword; i < z; ++i) {
						addLetter(sentences[s][i]);
						printf("%c", sentences[s][i]);
					}
					addLetter(' '); //��������� ������ � ������ words ��� ���������� 
					countOfwords++; //��������� +1 � ���-�� ������������ ���� 
					printf(" ) - ����� �����������\n");
				}
				else {
					printf("����� �� �����������\n");
				}
			}
		}
	}

	printf("\n������ ������������ ���� �� ���� ������������ - ( ");
	for (int i = 0; i < len; ++i) {
		printf("%c", words[i]);
	}
	printf(") - ����������: %d", countOfwords);

	shutDown();
	return 0;
}

int isAlpha(unsigned char sym) { //������� ��� �������� �� ������� � ���������� ����� 
	if (((int)sym >= 65 && (int)sym <= 90) || ((int)sym >= 97 && (int)sym <= 122)) return 1;
	if (((int)sym >= 192 && (int)sym <= 255)) return 1;
	return 0;
}

void addLetter(char sym) { //������� ��� ���������� ������� � ������ words 
	char* tmp = (char*)realloc(words, ++len * sizeof(char));
	if (tmp) {
		words = tmp; //����������� ������ ������� words 
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

void shutDown() { //������������ ������ (�������� � ������� ��� ����������� ���������� ��������� � ������ ������ ��������� ������) 
	free(words);
	free(sizeOfsentence);
	for (int i = 0; i < countOfsentences; ++i) {
		free(sentences[i]);
	}
	free(sentences);
}*/
