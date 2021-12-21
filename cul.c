#include <stdio.h>

#define INPUT_FILE_DIR "in.txt"
#define OUTPUT_FILE_DIR "out.txt"
#define character_number 26

int main()
{
	FILE *fp_in = fopen(INPUT_FILE_DIR, "r");
	FILE *fp_out = fopen(OUTPUT_FILE_DIR, "w");

	char c = ' ';
	int i = 0;
	int total = 0;
	int counter[character_number];
	int check = 0;
	for (i = 0; i < character_number; i++)
		counter[i] = 0;

	while (c != EOF)
	{
		c = fgetc(fp_in);
		if (c >= 'a' && c <= 'z')
		{
			total++;
			counter[c - 'a']++;
		}
	}

	fprintf(fp_out, "total:\t\t%d\n", total);
	for (i = 0; i < character_number; i++)
		check += counter[i];
	fprintf(fp_out, "check_number:\t%d\n", check);

	c = 'a';
	fprintf(fp_out, "char :\tnumber :\t\tfrequency(%%) :\tchar :\tnumber :\t\tfrequency(%%) :\n");
	for (i = 0; i < character_number / 2; i++)
	{
		for (int j = 0; j < 2; j++)
			fprintf(fp_out, "%c\t%d\t\t%.4lf\t\t", c++, counter[i * 2 + j], counter[i * 2 + j] * 100.0 / total);
		fprintf(fp_out, "\n");
	}

	return 0;
}
