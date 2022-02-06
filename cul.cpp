#include <stdio.h>

#define INPUT_FILE_DIR "in.txt"
#define OUTPUT_FILE_DIR "out.txt"
#define character_number 26

int counter[character_number];
int counter_comma;
int counter_stop;
int connection[character_number + 2][character_number + 2];
int main()
{
	FILE *fp_in = fopen(INPUT_FILE_DIR, "r");
	FILE *fp_out = fopen(OUTPUT_FILE_DIR, "w");

	char c = ' ';
	char past = '\0';
	char current = '\0';
	int i,j;
	int total, check, location, total2;
	total = check = total2 = 0;
	counter_comma = counter_stop = 0;
	for (i = 0; i < character_number; i++){
		counter[i] = 0;
	}
	for (i = 0; i < character_number + 2; i++){
		for (j = 0; j < character_number + 2; j++){
			connection[i][j] = 0;
		}
	}

	while (c != EOF){
		c = fgetc(fp_in);
		if (c >= 'a' && c <= 'z'){
			total++;
			counter[c - 'a'] ++;
			current = c;
			if (past >= 'a' && past <= 'z'){
				connection[past - 'a'][current - 'a']++;
			}else if (past == ','){
				connection[character_number][current - 'a']++;
			}else if (past == '.'){
				connection[character_number + 1][current - 'a']++;
			}
			past = current;
			current = '\0';
		}else if (c == ','){
			counter_comma++;
			current = c;
			if(past >= 'a' && past <= 'z'){
				connection[past - 'a'][character_number]++;
			}else if (past == ','){
				connection[character_number][character_number]++;
			}else if (past == '.'){
				connection[character_number + 1][character_number]++;
			}
			past = current;
			current = '\0';
		}else if (c == '.'){
			counter_stop++;
			current = c;
			if(past >= 'a' && past <= 'z'){
				connection[past - 'a'][character_number + 1]++;
			}else if (past == ','){
				connection[character_number][character_number + 1]++;
			}else if (past == '.'){
				connection[character_number + 1][character_number + 1]++;
			}
			past = current;
			current = '\0';
		}else if(c != ' '){
			current = '\0';
			past = '\0';
		}
	}

	fprintf(fp_out, "total:\t\t%d\n", total);
	for (i = 0; i < character_number; i++)
		check += counter[i];
	fprintf(fp_out, "check_number:\t\t%d\n", check);
	fprintf(fp_out, "counter_comma:\t\t%d\n", counter_comma);
	fprintf(fp_out, "counter_stop:\t\t%d\n", counter_stop);
	if(total == check){
		printf("Success!\n");
	}else{
		printf("Failed!\n");
		return 0;
	}

	c = 'a';
	fprintf(fp_out, "char :\tnumber :\tfrequency(%%) :\tchar :\tnumber :\tfrequency(%%) :\n");
	for (i = 0; i < character_number / 2; i++){
		for (j = 0; j < 2; j++){
			fprintf(fp_out, "%c\t%d\t%.4lf\t", c++, counter[i * 2 + j], counter[i * 2 + j] * 100.0 / total);
		}
		fprintf(fp_out, "\n");
	}

	fprintf(fp_out, "\n");
	fprintf(fp_out, "\n");

	for (i = 0; i < character_number; i++){
		for (j = 0; j < character_number; j++){
			total2 += connection[i][j];
		}
	}
	fprintf(fp_out, "total2:\t\t%d\n", total2);
	for (i = 0; i < character_number + 2; i++){
		for (j = 0; j < character_number + 2; j++){
			fprintf(fp_out, "%d\t", connection[i][j]);
		}
		fprintf(fp_out, "\n");
	}

	fclose(fp_in);
	fclose(fp_out);
	printf("Finished!\n");
	return 0;
}
