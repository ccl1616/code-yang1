#include <stdio.h>
#define NQ 4
int q[NQ] = {0};

void place(int row);
int valid(int row, int col);
void display(void);

int main(void)
{
	place(0);
	return 0;
}

int valid(int row, int col)
{
    int i;
    for (i=0; i<=row-1; i++) {
        if (q[i] == col || q[i] == col-row+i || q[i] == col+row-i)
            return 0;
    }
    return 1;
}
void display(void)
{
	int i, j;
	for (i=0; i<NQ; i++) {
	    for (j=0; j<NQ; j++) {
	        if (q[i]==j) printf("O");
	        else printf("X");
	    }
	    printf("\n");
	}
	printf("\n");
}

void place(int row)
{
	int j;
	if (row == NQ) {
		display();
	} else {
		for (j=0; j<NQ; j++) {
			if (valid(row, j)) {
                q[row] = j;
                place(row+1);
			}
		}
	}
}
