//�ۺ���ǰʵ��Ĺ��ܣ���Ƽ��׿γ���Ϣ����ϵͳ���γ���Ϣ�����γ̺ţ��ؼ��֣����γ�����ѧ�ֵ���Ϣ����ƹ�����Ҫ����:����˵���ʵ�ּ�¼�Ĳ��롢�޸ġ�ɾ������ѯ������ȹ��ܡ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define MAXSIZE 20
//�γ���Ϣ ,���������������Ϣ,�����ν���ʦ 
typedef struct {
	int lessionId;//�γ̺� 
	char lessionName[50];//�γ�����
	int  credit;//ѧ��
}Information;
//˳���:��MAXSIZE��Information�����Լ�һ��������¼λ���ڳ��ȵ�length��� 
typedef struct{
	Information I[MAXSIZE];
	int length;//��¼���� 

}sqlist;

//��ȡ��ĵ�ǰ���� 
int len(sqlist head){
	return head.length;
}
//��ʼ����,���Ϊ0 
int create(sqlist &head){
	return head.length = 0;
}
//�жϱ��Ƿ�Ϊ�� 
bool is_empty(sqlist head){
	if(head.length==0)
	return true;  
	else
	return false;
} 
//���γ�id(�ؼ���)����,�����ض�Ӧ���±�length 
int search(sqlist head,int lessionId){
	int i; 
	for(i = 0; i<head.length; i++){
	if(head.I[i].lessionId == lessionId){
		//�Ѵ�ʱ��i����,i���������±�(�����������±�) 
		return i+1;
		}
	}//û���ҵ�����-1
	return -1;
}
//����������Ϣ ,�������Ϣ��Ҫ��������ĺ�������Ϣͬ��,���������÷� ���� ʹ��ָ�� 
void input(int &lessionId,char lessionName[],int &credit){
	
		printf("�γ̺�:\n");
		scanf("%d",&lessionId);
		printf("�γ�����:\n"); 
		scanf("%s",lessionName);
		printf("�γ�ѧ��:\n");
		scanf("%d",&credit);
}
//��ӿγ���Ϣ 
bool addInformation(sqlist &head,int lessionId,char lessionName[],int credit){
	int len = head.length;	
	//����input,����ʱ�ı���lessionid,lessionname,credit 
	input(lessionId,lessionName,credit);
	//�������ӵĿγ̺�(�ؼ���)�Ѿ�����,���ؼ� 
	if( ( search(head,lessionId) ) != -1) 
	{
		printf("�γ̺�%d�Ѵ���!�޷��ٴ����!\n",lessionId); 
		return false;
	}
	else{
	head.I[len].lessionId = lessionId;
	strcpy(head.I[len].lessionName,lessionName);
	head.I[len].credit = credit;
	head.length++;
	return true;	
}
} 

//�޸Ŀγ���Ϣ ,ֱ�Ӹ��ǹؼ���λ�õĶ�Ӧ��������Ϣֵ 
void modifyInformation(sqlist &head,int lessionId,char lessionName[],int credit){
	int len = lessionId;//�ؼ��� 
	input(lessionId,lessionName,credit);	
	//�������ӵĿγ̺�(�ؼ���)������,ִ��
	if(search(head,lessionId) != -1) 
	{
	head.I[len].lessionId = lessionId;
	strcpy(head.I[len].lessionName,lessionName);
	head.I[len].credit = credit;
}
else printf("������"); 
}

//ɾ���γ���Ϣ,���ǵ� 
int dele(sqlist &head,int lessionId){
	int i,j; 
	//��������˳��� 
	for(i = 0; i<head.length; i++)
	{
		//������ҵ� 
		if(head.I[i].lessionId == lessionId){
			//�� ������ҵ㿪ʼ ,����������ǰ�ƶ� 
			for(j = i; j<head.length;j++)
			{
					head.I[j]=head.I[j+1];
			}
			//ɾ����ϳ��ȼ���
			head.length = head.length--;
		}
	}
	return 0;
}
//
void DisNplayOne(sqlist head,int lessionId){
	//�ҵ�lessionId���±� 
	int location = search(head,lessionId); 
	if(location!=-1){
	
		printf("�γ̺�:%5d\n",head.I[location-1].lessionId);
		printf("�γ�����:%5s\n",head.I[location-1].lessionName);
		printf("�γ�ѧ��:%5d\n",head.I[location-1].credit);
		printf("\n");
	}
	else
	printf("�ÿγ�id������!\n");
}
void DisplayAll(sqlist head){
	int i;
	if(is_empty(head))
		printf("��\n");
	for(i=0; i<head.length; i++)
	{
		printf("�γ̺�:%5d\n",head.I[i].lessionId);
		printf("�γ�����:%5s\n",head.I[i].lessionName);
		printf("�γ�ѧ��:%5d\n",head.I[i].credit);
			printf("\n");
	}

}
void bobblesort(sqlist head)
{
    int i,j;
	Information temp;
	int exchange;
	for(i = 0;i<head.length;i++)
	{
		exchange = 0;
		for(j = head.length-1;j>i;j--)
		{
			if(head.I[j].lessionId<head.I[j-1].lessionId)
			{
				temp = head.I[j];
				head.I[j] = head.I[j-1];
				head.I[j-1] = temp;
				exchange = 1;
			}
			if(!exchange)
			break;
		}

	}	
	DisplayAll(head);
}

	void go_menu()
{
	printf("\n����������ء���\n");
	//system("pause");
	getch();
}
char menu()
{     
      //���ڿγ̹ؼ�id������,����ѡ������ĸ��ѡ��,�������һ�� 
   char code;
    system("cls");
   printf(" \n\t\t���׿γ���Ϣ����ϵͳ\n\n");
   printf("\t\ta.�˳�ϵͳ\n");
   printf("\t\tb.��ӿγ̵���Ϣ\n");
   printf("\t\tc.������пγ̵���Ϣ\n");
   printf("\t\td.�޸�ĳ�γ̵���Ϣ\n");
   printf("\t\te.����ĳ�γ̵���Ϣ\n");
   printf("\t\tf.ɾ��ĳ�γ�\n"); 
   printf("\t\tg.����\n"); 
   printf("\t\n");
   printf("��ѡ��(a~g):\n");
	   scanf("%c",&code);
   return code;   
}
int action(){
 int code;
	char lessionName[50]={0};
	int lessionId = 0;
	int credit = 0;
	sqlist head;
	create(head);
	printf("�����ɹ���") ;
while(1){
	 code = menu();
		switch(code)
		{
		case 'a':  
			exit (1) ;
				go_menu();
			break;
		break;	
		case 'b':
		addInformation(head,lessionId,lessionName,credit);	
			go_menu();
		break;
		case 'c':		
			DisplayAll(head);
				go_menu();
				break;
		case 'd':
			printf("�޸Ŀγ�:"); 
			modifyInformation(head,lessionId,lessionName,credit);
			go_menu();
			break;
		case 'e':
			printf("���Ҽ��ſγ�:");
			scanf("%d",&lessionId);
			//���Ҳ���� 
			DisNplayOne(head,lessionId);
				go_menu();
					break;
		case 'f':
			printf("ɾ�����ſγ�:");
			scanf("%d",&lessionId);
			//���Ҳ���� 
			dele(head,lessionId);
				go_menu();
					break;
					case 'g':
					printf("���γ�����\n");
					bobblesort(head);
				
					go_menu(); 
					break; 
		}	
}
}
int main(){
action();
return 0;
}

