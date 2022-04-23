/******************************************************************************
Faça um programa que obtenha o dia da retirada e o dia da entrega de um livro de uma
biblioteca e em seguida calcule quantos N dias (N >= 0) o livro ficou emprestado. Caso o
livro tenha ficado emprestado por mais de 10 dias corridos, o programa deve calcular e exibir
a penalidade (suspensão do direito ao empréstimo por 3 dias úteis para cada dia de atraso,
ou seja, M dias úteis (M >=0)). Lembre-se de considerar que o livro pode ter sido retirado
e entregue em meses ou anos diferentes.
Requisitos da tela:
***************** Sistema de Empréstimo de Livros **********************
Data de retirada: XX/XX/XXXX
Data de entrega: YY/YY/YYYY
Situação: atrasado(a) por N dias.
Penalização: M dias úteis.
Retirada permitida a partir de: ZZ/ZZ/ZZZZ
**********************************************************************
*******************************************************************************/
#include <stdio.h>
#include <locale.h>
int bissexto(int ano);
int diasemprestados(int xd,int xm,int xa,int yd,int ym,int ya);
int dia_penalidade(int yd,int ym,int ya,int diasemprestados);
int mes_penalidade(int yd,int ym,int ya,int diasemprestados);
int ano_penalidade(int yd,int ym,int ya,int diasemprestados);
int confere_data(int dia,int mes, int ano);

int bissexto(int ano){
    if((ano%4==0) && ((ano%100!=0) || (ano%400==0))){return 1;}
    else{return 0;}
}
int diasemprestados(int xd,int xm,int xa,int yd,int ym,int ya){
    int cont;
    cont=0;
    while((xd!=yd&&xm!=ym&&xa!=ya)||(xd!=yd&&xm!=ym&&xa==ya)||(xd!=yd&&xm==ym&&xa==ya)||(xd!=yd||xm!=ym||xa!=ya)){
        
        xd+=1;
        if((xm==4||xm==11||xm==9||xm==6)&&xd==31){xd=1;xm+=1;}
        if((xm==1||xm==3||xm==5||xm==7||xm==8||xm==10)&&xd==32){xd=1;xm+=1;}
        if(xa%4==0 && (xa%100!=0 || xa%400==0) && xd==30 && xm==2){xd=1;xm+=1;}
        if((xa%4!=0 && (xa%100==0 || xa%400!=0) && xd==29 && xm==2)){xd=1;xm+=1;}
        if(xd==32&&xm==12){xd=1;xm=1;xa+=1;}
        
        cont+=1;
    }
    return cont;
}
int dia_penalidade(int yd,int ym,int ya,int diasemprestados){
    int dias;

    dias=3*(diasemprestados-10);
    
    while(dias>0){
        
        yd+=1;
        if((ym==4||ym==11||ym==9||ym==6)&&yd==31){yd=1;ym+=1;}
        if((ym==1||ym==3||ym==5||ym==7||ym==8||ym==10)&&yd==32){yd=1;ym+=1;}
        if(bissexto(ya)==1 && yd==30 && ym==2){yd=1;ym+=1;}
        if(bissexto(ya)==0 && yd==29 && ym==2){yd=1;ym+=1;}
        if(yd==32&&ym==12){yd=1;ym=1;ya+=1;}
        dias-=1;
    }
    return yd;
}
int mes_penalidade(int yd,int ym,int ya,int diasemprestados){
    int cont,dias;
    cont=0;
    dias=3*(diasemprestados-10);
    
    while(dias>0){
        
        yd+=1;
        dias-=1;
        if((ym==4||ym==11||ym==9||ym==6)&&yd==31){yd=1;ym+=1;}
        if((ym==1||ym==3||ym==5||ym==7||ym==8||ym==10)&&yd==32){yd=1;ym+=1;}
        if(bissexto(ya)==1 && yd==30 && ym==2){yd=1;ym+=1;}
        if(bissexto(ya)==0 && yd==29 && ym==2){yd=1;ym+=1;}
        if(yd==32&&ym==12){yd=1;ym=1;ya+=1;}
        
    }
    return ym;
}
int ano_penalidade(int yd,int ym,int ya,int diasemprestados){
    int cont,dias;
    cont=0;
    dias=3*(diasemprestados-10);
    
    while(dias>0){
        
        yd+=1;
        dias-=1;
        if((ym==4||ym==11||ym==9||ym==6)&&yd==31){yd=1;ym+=1;}
        if((ym==1||ym==3||ym==5||ym==7||ym==8||ym==10)&&yd==32){yd=1;ym+=1;}
        if(bissexto(ya)==1 && yd==30 && ym==2){yd=1;ym+=1;}
        if(bissexto(ya)==0 && yd==29 && ym==2){yd=1;ym+=1;}
        if(yd==32&&ym==12){yd=1;ym=1;ya+=1;}
        
    }
    return ya;
}
int confere_data(int dia,int mes, int ano){
    int x;
     if(dia>=32&&(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)){x=1;}
    else if(dia>=31&&(mes==4||mes==6||mes==9||mes==11)){x=1;}
    else if(bissexto(ano)==1 && dia>=30 && mes==2){x=1;}
    else if(bissexto(ano)==0 && dia>=29 && mes==2){x=1;}
    else if(dia<1 || mes<1||mes>12){x=1;}
    
     return x;
}
int imprimerelatorio(int xd,int xm,int xa,int yd,int ym,int ya,int g,int dp,int mp,int ap){
	setlocale(LC_ALL, "Portuguese");

    printf("\n          ************************ Sistema de Empréstimo de Livros **********************\n\n");
    printf("                    Data de retirada: %d/%d/%d\n",xd,xm,xa);
    printf("                    Data de entrega: %d/%d/%d\n",yd,ym,ya);
    printf("                    Situação: atrasado(a) por %d dias.\n",g);
    printf("                    Penalização: %d dias úteis.\n",3*g);
    printf("                    Retirada permitida a partir de: %d/%d/%d\n\n",dp,mp,ap);
    printf("          *******************************************************************************\n");

}


int main()
{
		setlocale(LC_ALL, "Portuguese");
    int xd,xm,xa,yd,ym,ya,de,dp,mp,ap,x,m,g;
    do{
    printf("\n                       Digite a data de retirada no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d",&xd,&xm,&xa);
   x=confere_data(xd,xm,xa);
   if(confere_data(xd,xm,xa)==1){printf("\n                        Opa!! Essa data não existe!!\n");}
    }while(x==1);

    do{
    printf("\n                       Digite a data de entrega no formato DD/MM/AAAA: ");
    scanf("%d/%d/%d",&yd,&ym,&ya);
    m=confere_data(yd,ym,ya);
    if(confere_data(yd,ym,ya)==1){printf("\n                        Opa!! Essa data não existe!!\n");}
    if(yd<xd&&ym==xm&&ya==xa){printf("\n                        Ei!!Parece que esse dia já passou.\n");m=1;}
    if((ym<xm&&ya==xa)||ya<xa){printf("\n                        Ei!!Parece que essa data já passou.\n");m=1;}
    }while(m==1);
    
    de=diasemprestados(xd,xm,xa,yd,ym,ya);
    if(de>10){g=de-10;}
    else{g=0;}
    if(de<=10){
        dp=yd;
        mp=ym;
        ap=ya;}
    else{
    dp=dia_penalidade(yd,ym,ya,de);
    mp=mes_penalidade(yd,ym,ya,de);
    ap=ano_penalidade(yd,ym,ya,de);
    }
    imprimerelatorio(xd,xm,xa,yd,ym,ya,g,dp,mp,ap);
    
   
    
    return 0;
}
