#include<stdio.h>
#define size 20

void TurnChange(char *ptr)
{
	/*
	���� ���� ǥ�õǴ� ���� �ٲٴ� �Լ�
	*/
	*ptr = (*ptr == 'O') ? 'X' : 'O';
}
void ShowPlate(char(*plate)[20])
{
	/*
	�������� �����ִ� �Լ�
	*/
	int x, y;
	printf("%-3c", plate[0][0]);		//�� ���
	for (x = 1; x < size; x++)
		printf("%-3d", x);				//1���� size(20) ������ ���ڷ� ���
	putchar('\n');

	for (y = 1; y < size; y++)			//1���� size(20) ������ 
	{
		printf("%-3d", plate[y][0]);    //���� �տ��� ���ڷ� ���
		for (x = 1; x < size; x++)		//1���� size(20) ������
		{
			printf("%-3c", plate[y][x]);//�ٵ��� ���
		}
		putchar('\n');
	}
}
int Win(char c)
{
	/*
	�̰��� �� ����ϴ� �Լ�
	*/
	printf("=======%c ��!======= \n",c);
	return 1;
}
int WinOrNot(char plate[][20], int y, int x)
{
	/*
	�̰���� ������ �Ǵ��ϴ� �Լ�
	*/
	int i, j;
	int trig = 0;

	for (i = x - 4; i <= x + 4; i++)  //���� �˻� (�ڿ��� 4ĭ~������ 4ĭ)
	{
		if (plate[y][x] == plate[y][i]) //ó�� ���۰� ���� ��ġ�� ���ٸ�
			trig++;						//Ʈ����++
		else							//�ٸ��ٸ�
			trig = 0;					//Ʈ���Ÿ� 0���� �ʱ�ȭ

		if (trig >= 5)					//�˻����� �� Ʈ���Ű� 5���� ũ�ٸ�
			return Win(plate[0][0]);	//Win() ����
	}
	trig = 0;							//Ʈ���� 0���� �ʱ�ȭ

	for (j = y - 4; j <= y + 4; j++) //���� �˻� (�ڿ��� 4ĭ~������ 4ĭ)
	{
		if (plate[y][x] == plate[j][x])	//ó�� ���۰� ���� ��ġ�� ���ٸ�
			trig++;						//Ʈ����++
		else							//�ٸ��ٸ�
			trig = 0;					//Ʈ���Ÿ� 0���� �ʱ�ȭ
		
		if (trig >= 5)					//�˻����� �� Ʈ���Ű� 5���� ũ�ٸ�
			return Win(plate[0][0]);	//Win() ����
	}
	trig = 0;							//Ʈ���� 0���� �ʱ�ȭ

	j = y - 4;							//�밢������ ���� ������, j�� �̸� �ʱ�ȭ
	for (i = x - 4; i <= x + 4; )  //������ �Ʒ� �밢��
	{
		
		if (plate[y][x] == plate[j][i])	//ó�� ���۰� ���� ��ġ�� ���ٸ�
			trig++;						//Ʈ����++
		else							//�ٸ��ٸ�
			trig = 0;					//Ʈ���� 0���� �ʱ�ȭ

		if ((i == 0) && (j == 0))		//��ǥ�� ���� ���� ǥ���ϴ� ��ǥ(������ ��)�� ���
			trig = 0;					//Ʈ���� �ʱ�ȭ

		if (trig >= 5)					//�˻����� �� Ʈ���Ű� 5���� ũ�ٸ�
			return Win(plate[0][0]);	//Win() ����
		j++;	
		i++;
	}
	trig = 0;							//Ʈ���� 0���� �ʱ�ȭ

	j = y - 4;							//�밢������ ���� ������, j�� �̸� �ʱ�ȭ
	for (i = x + 4; i >= x - 4; i--) //���� �Ʒ� �밢��
	{
		if (plate[y][x] == plate[j][i])	//ó�� ���۰� ���� ��ġ�� ���ٸ�
			trig++;						//Ʈ����++
		else							//�ٸ��ٸ�
			trig = 0;					//Ʈ���� 0���� �ʱ�ȭ

		if (trig >= 5)					//�˻����� �� Ʈ���Ű� 5���� ũ�ٸ�
			return Win(plate[0][0]);	//Win() ����
		j++;
	}
	return 0;
}
int main(void)
{
	char plate[20][20];					//������ �迭
	int x, y;
	
	for(x=1; x<size; x++)				//1���� 19���� 
		plate[0][x] = x;				//���� ���ٿ� 1~19 ������� ����
	for(y=1; y<size; y++)				//1���� 19����
		plate[y][0] = y;				//���� ���ʿ� 1~19 ������� ����
	for(x=1; x<size; x++)
		for(y=1; y<size; y++)
			plate[y][x] = '.';			//�������� �� .���� ä��

	plate[0][0] = 'O';					//���� O ���� ����

	while(1)
	{
		ShowPlate(plate);				//�������� ������

		printf("��ǥ? ");
		scanf("%d %d", &x, &y);			//��ǥ �Է�

		if(plate[y][x] != '.')			//��ǥ�� ������� ������
			printf("�߸��� ��ǥ �Է�, �� �Ѿ \n");//�Ѿ
		else							//���������
			plate[y][x] = plate[0][0];  //���� ����

		if( WinOrNot(plate, y, x) )		//���� ������ ��������
		{
			ShowPlate(plate);			//�ٵ����� �����ְ�
			return 0;					//����
		}
		TurnChange(&plate[0][0]);		//�� �ٲ�
	}
}