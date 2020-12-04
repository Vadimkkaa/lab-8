#include<stdio.h>
#include<malloc.h>
#include<ctype.h>
#include<locale.h>
int num = 0; //Èíäåêñ ýëåìåíòà â ìàññèâå words
int len = 0;
char* words; //Ìàññèâ ñèìâîëîâ(ñîäåðæèò íàéäåííûå ñèììåòðè÷íûå ñëîâà) 
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
	for (w = 1; w <=n1; w++) {//äëÿ äâèæåíèÿ ïî ìàòðèöàì
		str = (char**)malloc(n * sizeof(char*));//äëÿ ñîçäàíèÿ äâóìåðíîé äèíàìè÷åñêîé ìàòðèöû
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
				xx = &str[i][j];//ïðèñâàèâàþ óêàçàòåëþ àäðåñ ýëåìåíòà(è òàê ìíîãî ðàç)
				xx = (char*)malloc(k * sizeof(char));//äåëàþ äèíàìè÷åñêèé ìàññèâ ïî ýòîìó óêàçàòåëþ
				if (!(xx = (char*)malloc(k * sizeof(char)))) {
					free(xx);
					return 0;
				}
				getchar();
				fgets(xx,k,stdin);//ââîæó ñòðîêó äëÿ ýòîãî ýëåìåíòà ìàòðèöû(óêàçàòåëÿ)
				//getchar();
				fflush(stdin);
				z = 0;
				while(xx[z]!='\0'&&xx[z]!='\n') {
					if (xx[z] == ' ') {//åñëè ïðîáåë-èçáàâëÿþñü îò ïðîáåëîâ äî áóêâû
						while (xx[z] == ' ') {
							kol1++;
							z++;
							if (xx[z] == '\0')
								break;
						}
					}
					if (xx[z] != ' '&&xx[z]!='\0'&&xx[z]!='\n') {//íàøåë áóêâó-ïîåõàëè ñ÷èòàòü ñêîëüêî èõ â ñëîâå
						r = z;
						bb = r;
						er = bb;
						while (xx[z] != ' '&&xx[z]!='\0'&&xx[z]!='\n') {//ñêîëüêî áóêâ??
							kol++;
							z++;
						}

						if (kol > 2) {//èíòåðåñóþñü ñëîâàìè áîëüøèìè ÷åì 3 áóêâû

							if (kol>2&&kol % 2 == 0) {//óñëîâèå äëÿ ñëîâ ñ ÷åòåíûì êîëè÷åñòâîì áóêâ
								end1 = r + kol - 1;//êîíåö ñëîâà
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}										
									if (xx[r] == xx[end1]) {//ïðîâåðêà ñîîòâåñòâóþùèõ áóêâ 
										r++;//ñäâèãàþ ñ ëåâîãî êðàÿ ñëîâà
										end1--;//ñäâèã ñ ïðàâîãî êðàÿ ñëîâà
										if (r + 1 == end1 && xx[r] == xx[end1]) {//åñëè ïî èíäåêñó è ïî çíà÷åíèþ óæå ãðàíèöà è çíà÷åíèÿ ðàâíû-ïîäòâåðæäåíèå íóæíîãî ñëîâà
											if (status == 0) { //Êîïèðóåì ñëîâî öèêëîì â äðóãîé ìàññèâ(words) è âûâîäèì åãî 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);

												}
												addLetter(' '); //Äîáàâëÿåì ïðîáåë â ìàññèâ words äëÿ ÷èòàåìîñòè 
											}
											po++;
											status = 0;
											kol = 0;
											break;
										}
									}
								}
							}


							if (kol>2&&kol % 2 != 0) {//äëÿ íå÷åòíûõ ñëîâ
								end1 = r + kol - 1;
								vv = kol / 2;//íàõîæó ñåðåäèíó ñëîâà (ñ îêðóãëåíèåì)
								cc = r;
								while (status == 0) {
									if (xx[r] != xx[end1]) {
										kol = 0;
										break;
									}
									if (xx[r] == xx[end1]) {
										if (kol == 3) {
											if (status == 0) { //Êîïèðóåì ñëîâî öèêëîì â äðóãîé ìàññèâ(words) è âûâîäèì åãî 
												for (bb; bb <= er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //Äîáàâëÿåì ïðîáåë â ìàññèâ words äëÿ ÷èòàåìîñòè 
											}
											kol = 0;
											po++;
											break;
										}
										r++;
										end1--;
										if (r + 1 ==cc+vv  && xx[r] == xx[end1]) {//ïðîâåêà ïî èíäåêñó ïðèáëèçèëèñü ê ñåðåäèíå ñëîâà ïëþñ ðàâíîñòü èíäåêñîâ(íàïðèìåð 3 è 5)
											if (status == 0) { //Êîïèðóåì ñëîâî öèêëîì â äðóãîé ìàññèâ(words) è âûâîäèì åãî 
												for (bb; bb <=er + kol - 1; bb++) {
													addLetter(xx[bb]);
												}
												addLetter(' '); //Äîáàâëÿåì ïðîáåë â ìàññèâ words äëÿ ÷èòàåìîñòè 
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
	//printf("po==%d",po); äëÿ êîë-âà òàêèõ ñëîâ
	printf("\nYour arrange is- \n ");
	for (int t = 0; t <len; ++t) {
		printf("%c", words[t]);
	}
	return 0;
}
void addLetter(char sym) { //Ôóíêöèÿ äëÿ äîáàâëåíèÿ ñèìâîëà â ìàññèâ words 
	words = (char*)realloc(words, ++len * sizeof(char));//len âñåãäà óâåëè÷èâàåòñÿ íà 1 òàê êàê äîáàâëÿþ ïî 1 áóêâå ñ öèêëà â int main
	if (!words) {
		free(words);
		return 0;
	}

	//char* tmp = (char*)realloc(words, ++len * sizeof(char));
	/*if (tmp) {
		words = tmp; //Óâåëè÷èâàåì ðàçìåð ìàññèâà words 
		free(tmp);
	}
	else {
		printf("Realloc error");
		free(tmp);
		
	}*/
	words[num] = sym;
	num++;

}
/*Äàíî n1 ìàòðèö. Ðàçìåð ìàòðèöû n*m. Êàæäûé ýëåìåíò ìàòðèöû – ñòðîêà çíàêîâ äëèííîé k. Ñëîâà â ïðåäëîæåíèè ðàçäåëåíû îäíèì èëè íåñêîëüêèìè ïðîáåëàìè.
Îïðåäåëèòü â êàæäîì ïðåäëîæåíèè êîëè÷åñòâî ñëîâ, êîòîðûå ñïðàâà è ñëåâà ÷èòàþòñÿ îäèíàêîâî è çàïèñàòü èõ â ìàññèâ.
*/

