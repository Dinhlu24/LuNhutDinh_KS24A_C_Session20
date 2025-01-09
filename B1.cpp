#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxSize 100

typedef struct{
	int code;
	char name[30];
	char author[20];
	double price;
}thuVien;

void refresh();
void input(thuVien arr[],int *size);
void showLibary(thuVien arr[],int size);
void addByIndex(thuVien arr[],int *size);
void deleteByCode(thuVien arr[],int *size);
void updateByCode(thuVien arr[],int size);
void sortByPrice(thuVien arr[],int size,char status);
void findByName(thuVien arr[],int size);

int main(){
	system("color 3");
	thuVien arr[maxSize]={
		{123,"Dac nhan tam","Dale Carnegie",55},
		{142,"Mindset","Carol S.Dweck",120},
		{192,"Toi da sinh ra mot lan nua","OOPSY",69},
		{133,"Why we sleep","Matthew Walker",150},
		{102,"Thinking, Fast And Slow","Daniel Kahneman",170}
	};
	int choice,size=5;
	do{
		printf("-*-*-*-*-*-*-*-*MENU-*-*-*-*-*-*-*-*-\n");
		printf("1. Nhap so luong va thong tin sach\n");
		printf("2. Hien thi thong tin sach\n");
		printf("3. Them sach vao vi tri\n");
		printf("4. Xoa sach theo ma sach\n");
		printf("5. Cap nhat thong tin sach theo ma sach\n");
		printf("6. Sap xep sach theo gia (tang,giam)\n");
		printf("7. Tim kiem sach theo ten sach\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");	scanf("%d",&choice);	fflush(stdin);
		switch(choice){
			case 1://Nhap so luong va thong tin sach
				input(arr,&size);
				break;
			case 2://Hien thi thong tin sach
				showLibary(arr,size);
				break;
			case 3://Them sach vao vi tri
				addByIndex(arr,&size);
				break;
			case 4://Xoa sach theo ma sach
				deleteByCode(arr,&size);
				break;
			case 5://Cap nhat thong tin sach theo ma sach
				updateByCode(arr,size);
				break;
			case 6://Sap xep sach theo gia (tang,giam)
				{
					char c;
					printf("a. Sap xep tang theo gia tien\n");
					printf("b. Sap xep giam theo gia tien\n");
					printf("Lua chon cua ban: ");	scanf("%c",&c);	fflush(stdin);
					switch(c){
						case 'a':	case 'b':
							sortByPrice(arr,size,c);
							break;
						default:
							printf("Lua chon cua ban khong hop le");
					}
				}
				break;
			case 7://Tim kiem sach theo ten sach
				findByName(arr,size);
				break;
			case 8:// Thoat
				printf("Chuong trinh ket thuc !!!");
				break;
			default:
				printf("Lua chon cua ban khong hop le vui long chon lai !!!");
		}
		printf("\n\n");
		refresh();
	}while(choice != 8);
}

void refresh(){
	printf("(An phim ENTER de tiep tuc !!!)\n\n");	getchar();
	system("cls");
}

void input(thuVien arr[],int *size){
	if(*size == maxSize){
		printf("So luong sach da day khong the them!!!");
		return;
	}
	
	int tmp=*size; // de luu bien size trong truong hop size > 0
	
	printf("Moi nhap vao so luong sach ban muon them vao (1 > %d): ",maxSize-*size);	scanf("%d",size);	fflush(stdin);
	
	if(*size < 1 || *size + tmp > maxSize){
		printf("So luong sach nhap vao khong hop le !!!");
		*size = tmp; // neu so luong sach vuot muc 100 thi gan lai cho gia tri sach ban dau
		return;
	}
	
	for(int i=(*size == 0)?0:tmp;i<*size + tmp;i++){ // neu so luong sach = 0 thi bat dau them sach tu dau mang neu ko thi bat dau them tu vi tri cuoi cung
		printf("Ma sach %d: ",i+1);	scanf("%d",&arr[i].code);	fflush(stdin);
		printf("Ten sach %d: ",i+1);	gets(arr[i].name);
		printf("Tac gia %d: ",i+1);	gets(arr[i].author);
		printf("Gia tien %d: ",i+1);	scanf("%lf",&arr[i].price);	fflush(stdin);
	}
	*size+=tmp;
	
	printf("Them sach thanh cong !!!");
}

void showLibary(thuVien arr[],int size){
	if(size == 0){
		printf("Thu vien dang trong vui long nhap vao truoc khi thuc hien thao tac");
		return;
	}
	
	printf("%40s\n","THU VIEN");
	printf("%-75s\n","-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
	printf("| %-5s%-10s%-30s%-20s%-10s |\n","STT","Ma sach","Ten sach","Tac gia","Gia tien");
	printf("%-75s\n","-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
	for(int i=0;i<size;i++){
		printf("| %-5d%-10d%-30s%-20s%-10.3lf |\n",i+1,arr[i].code,arr[i].name,arr[i].author,arr[i].price);
		printf("%-75s\n","_______________________________________________________________________________");
	}
}

void addByIndex(thuVien arr[],int *size){
	int addIndex;
	thuVien newbook;
	printf("Moi nhap vao vi tri muon them trong danh sach: ");	scanf("%d",&addIndex);	fflush(stdin);
	printf("Ma sach: ");	scanf("%d",&newbook.code);	fflush(stdin);
	printf("Ten sach: ");	gets(newbook.name);
	printf("Tac gia: ");	gets(newbook.author);
	printf("Gia tien: ");	scanf("%lf",&newbook.price);	fflush(stdin);
	
	if(addIndex < 1){
		addIndex = 1;
	}
	else if(addIndex >= *size){
		addIndex = *size;
		arr[addIndex] = newbook;
		printf("Da them xong !!!");
		(*size)++;
		return;
	}
	
	for(int i=*size-1;i>=addIndex-1;i--){
		arr[i+1] = arr[i];
	}
	arr[addIndex-1] = newbook;
	(*size)++;
	printf("Da them xong !!!");
}

void deleteByCode(thuVien arr[],int *size){
	if(size == 0){
		printf("Thu vien dang trong vui long nhap vao truoc khi thuc hien thao tac");
		return;
	}
	
	if(*size == 0){
		printf("Danh sach ban dang trong khong the xoa");
		return;
	}
	
	int c;
	printf("Moi nhap vao ma sach can xoa: ");	scanf("%d",&c);	fflush(stdin);
	
	for(int i=0;i<*size;i++){
		if(arr[i].code == c){
			(*size)--;
			for(int j=i;j<*size;j++){
				arr[j] = arr[j+1];
			}
			printf("Da xoa thanh cong !!!");
			return;
		}
	}
	
	printf("Ma sach ban can tim khong ton tai !!!");
}

void updateByCode(thuVien arr[],int size){
	if(size == 0){
		printf("Thu vien dang trong vui long nhap vao truoc khi thuc hien thao tac");
		return;
	}
	
	int c;
	printf("Moi nhap vao ma sach can cap nhat: ");	scanf("%d",&c);	fflush(stdin);
	
	for(int i=0;i<size;i++){
		if(arr[i].code == c){
			printf("Ten sach moi: ");	gets(arr[i].name);
			printf("Tac gia moi: ");	gets(arr[i].author);
			printf("Gia tien moi: ");	scanf("%lf",&arr[i].price);	fflush(stdin);
			printf("Cap nhat thanh cong !!!");
			return;
		}
	}
	
	printf("Ma sach ban nhap khong ton tai !!!");
}

void sortByPrice(thuVien arr[], int size, char status) {
	if(size == 0){
		printf("Thu vien dang trong vui long nhap vao truoc khi thuc hien thao tac");
		return;
	}
	
    for (int i = 1; i < size; i++){
        int index = i - 1;
        thuVien bookPlus = arr[i];
        if (status == 'a'){ // Sap xep tang dan
            while (index >= 0 && arr[index].price > bookPlus.price) {
                arr[index + 1] = arr[index];
                index--;
            }
        }
		else{ // Sap xep giam dan
            while (index >= 0 && arr[index].price < bookPlus.price){
                arr[index + 1] = arr[index];
                index--;
            }
    	}
    	arr[index + 1] = bookPlus;
    }
    printf("Da sap xep xong !!!\n");
}

void findByName(thuVien arr[],int size){
	if(size == 0){
		printf("Thu vien dang trong vui long nhap vao truoc khi thuc hien thao tac");
		return;
	}
	
	char findName[30];
	printf("Moi nhap vao ten sach can tim: ");	gets(findName);
	
	for(int i=0;i<size;i++){
		if(strcmp(arr[i].name,findName) == 0){
			printf("Sach ban can tim co trong thu vien !!!\n");
			printf("Day la thong tin sach ma ban can tim\n");
			printf("| %-5s%-10s%-30s%-20s%-10s |\n","STT","Ma sach","Ten sach","Tac gia","Gia tien");
			printf("%-75s\n","-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-");
			printf("| %-5d%-10d%-30s%-20s%-10.3lf |",i+1,arr[i].code,arr[i].name,arr[i].author,arr[i].price);
			return;
		}
	}
	
	printf("Sach ban can tim khong co trong thu vien !!!");
}
