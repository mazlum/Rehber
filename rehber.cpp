#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct TelefonRehber {
       
       char ad[15] , soyad[15] , e_posta[15];
       char web[15] , adres[50];
       char tel1[11] , tel2[11] , tel3[11];
                     
}Rehber[1000];

//Fonksiyonlar
void menu();
void kayit_ekleme();
void dosya_oku();
int kayit_arama(char *aranan);
void kayit_duzeltme();
void dosyaya_yaz();
void kayit_listele();
void sirala();
void kayit_sil();
void kayit_kontrol();

//Public degiskenler
FILE *dosya;
int kSayi = 0 ;  //kisi sayisini tutar.

int main(){
    
    dosya_oku();    
    menu();
     
    system("pause");
    return 0;
}


// Rehber'den kayit silen fonksiyon
void kayit_sil(){
     
     char secim ,silinecek[15];
     struct TelefonRehber gecici;
     cout << "Silmek istediginiz kisinin adini giriniz: \n";
     cin >> silinecek;
     
     for(int i=0 ; i<kSayi; i++){
             if(strcmp(silinecek , Rehber[i].ad) == 0){
                     cout <<"Silinecek kisinin bilgileri \n";    
                     cout <<"Ad    : " <<Rehber[i].ad<<endl;    
                     cout <<"Soyad : " <<Rehber[i].soyad<<endl; 
                     cout <<"Ev Telefonu :" <<Rehber[i].tel1<<endl;
                     cout <<"is Telefonu :" <<Rehber[i].tel2<<endl;
                     cout <<"Cep Telefonu:" <<Rehber[i].tel3<<endl;
                     cout <<"Email       :" <<Rehber[i].e_posta<<endl;
                     cout <<"Web         :" <<Rehber[i].web<<endl;
                     cout <<"Adres       :"<<Rehber[i].adres<<endl; 
                     
                     cout <<"Silmek istediginizden emin misiniz? Evet ise 'e' tuşuna basınız. Hayır ise herhangi bir tuşa basınız.\n";
                     cin >> secim;
                     
                     if(secim == 'e' ){
                          gecici = Rehber[kSayi-1];
                          Rehber[kSayi-1] = Rehber[i];
                          Rehber[i] = gecici;  
                          kSayi--;
                          break;
                     }     
             }
     }
     dosyaya_yaz();
     menu();
}
//Rehberi listeleyen fonksiyon
void kayit_listele(){
     
     sirala();
     for(int i=0;i<kSayi;i++)
     {
             cout << Rehber[i].ad<<"\t";
             cout << Rehber[i].soyad<<"\t";
             cout << Rehber[i].tel1<< "\t";
             cout << Rehber[i].tel2<<"\t";
             cout << Rehber[i].tel3<<"\t";
             cout << Rehber[i].e_posta<<"\t";
             cout << Rehber[i].web<<"\t";
             cout << Rehber[i].adres<<endl;
     }
     menu();    
}

//Rehberi sıralayan fonksiyon
void sirala(){
     struct TelefonRehber gecici;
     for(int i=0 ; i<kSayi ; i++){
             for(int j=i;j<kSayi;j++){
             int sonuc = strcmp(Rehber[i].ad , Rehber[j].ad);
             /*2.cisi 1 den k�c�k */
                 if(sonuc > 0){
                          gecici = Rehber[j];
                          Rehber[j] = Rehber[i];
                          Rehber[i] = gecici;         
                 }       
             
             }
     }    
}

//Rehberdeki herhangi bir kayıtta değişiklik yaptıran fonksiyon
void kayit_duzeltme(){
     char aranan[100];
     cout<<"Aradiginiz kisinin adini giriniz: ";
     cin >>aranan;
     int kSirasi = kayit_arama(&aranan[0]);
     int secim  ;
     char devam;
     if( kSirasi == -1){
       cout <<"Aradiginiz kisi bulunamadi.\n"; 
       menu(); 
     }else{
       
      
       cout <<"G�ncellemek istediginiz kisi bilgileri\n";
           
       cout <<"1-Ad    : " <<Rehber[kSirasi].ad<<endl;    
       cout <<"2-Soyad : " <<Rehber[kSirasi].soyad<<endl; 
       cout <<"3-Ev Telefonu :" <<Rehber[kSirasi].tel1<<endl;
       cout <<"4-is Telefonu :" <<Rehber[kSirasi].tel2<<endl;
       cout <<"5-Cep Telefonu:" <<Rehber[kSirasi].tel3<<endl;
       cout <<"6-Email       :" <<Rehber[kSirasi].e_posta<<endl;
       cout <<"7-Web         :" <<Rehber[kSirasi].web<<endl;
       cout <<"8-Adres       :"<<Rehber[kSirasi].adres<<endl;      
      
       do{
       cout <<"G�ncellemek istdiginiz bilgiyi seciniz.\n";
       cin >>secim;
       
       
       switch(secim){
                case 1 :
                     cout <<"\n Yeni adi giriniz : ";
                     cin >>Rehber[kSirasi].ad;
                     break;
               case 2 :
                    cout <<"\nYeni soyadi giriniz : ";
                    cin >>Rehber[kSirasi].soyad;
                    break;
               case 3 :
                    cout <<"\nYeni Ev telefonunu giriniz : ";
                    cin >>Rehber[kSirasi].tel1;
                    break; 
               case 4 :
                    cout <<"\nYeni is telefonunu giriniz : ";
                    cin >>Rehber[kSirasi].tel2;
                    break; 
               case 5 :
                    cout <<"\nYeni Cep telefonunu giriniz : ";
                    cin >>Rehber[kSirasi].tel3;
                    break;
              case 6 :
                    cout <<"\nYeni Email giriniz : ";
                    cin >>Rehber[kSirasi].e_posta;
                    break;       
              case 7 :
                    cout <<"\nYeni web giriniz : ";
                    cin >>Rehber[kSirasi].web;
                    break; 
              case 8 :
                    cout <<"\nYeni adresi giriniz : ";
                    cin >>Rehber[kSirasi].adres;
                    break; 
              default :
                      menu();
                      break;             
       }
       
       cout <<"Guncellemeye devam etmek istiyor musunuz?\n";
       cin >>devam;
      }while(devam == 'e' || devam =='E');
      {
                dosyaya_yaz();
                menu();
                return;                
      }
     }
}

//Dosyaya yazdıran fonksiyon
void dosyaya_yaz(){
         //remove dosyayi silip yeniden olusturduk.. remove return donderdigi icin int degiskenine atama yaptik.
         int a =  remove("rehber.txt");
         dosya = fopen("rehber.txt","a");
         for(int i=0;i<kSayi;i++)
         {
              fprintf(dosya,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",Rehber[i].ad,Rehber[i].soyad,Rehber[i].tel1 , Rehber[i].tel2 , Rehber[i].tel3 ,Rehber[i].e_posta , Rehber[i].web ,Rehber[i].adres);
         }
         fclose(dosya);
     }

//İsme gore rehberde kayıt arayan fonksiyon
int  kayit_arama(char *aranan){
     
     for(int i=0 ; i<kSayi ; i++){
         
        if(strcmp(aranan , Rehber[i].ad) == 0){
              return i;           
        } 
     }
      return -1;  
}


//Dosyayı okuyarak her elemanı struct dizisine atar
void dosya_oku(){

dosya = fopen("rehber.txt","r");

while(fscanf(dosya,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",&Rehber[kSayi].ad,&Rehber[kSayi].soyad,&Rehber[kSayi].tel1 ,&Rehber[kSayi].tel2 ,&Rehber[kSayi].tel3 ,&Rehber[kSayi].e_posta ,&Rehber[kSayi].web ,&Rehber[kSayi].adres)!=EOF){
        kSayi++;
        }
fclose(dosya);

}

//Dosyaya kayıt ekleme islemi yapar
void kayit_ekleme(){
                    //Dosyay� a�
                dosya = fopen("rehber.txt","a");
                char tus;
                    
                do{
                             cout <<"Ad               ....  :";
                             cin>>Rehber[kSayi].ad;
                             cout<<"\n";
                             
                             if(kayit_arama(&Rehber[kSayi].ad[0]) != -1){
                                cout<<"Bu isimde bir kayit bulunmaktadir. Baska bir isim giriniz"<<endl;
                                kayit_ekleme();
                             }
                             
                             cout <<"Soyad            ....   :";
                             cin  >>Rehber[kSayi].soyad;
                             cout<<"\n";
                             
                             cout <<"Ev Telefonu      ....   :";
                             cin  >>Rehber[kSayi].tel1;
                             cout<<"\n";
                             
                             cout <<"is Telefonu      ....   :";
                             cin  >>Rehber[kSayi].tel2;
                             cout<<"\n";
                             
                             cout <<"Cep Telefonu     ....   :";
                             cin  >>Rehber[kSayi].tel3;
                             cout<<"\n";
                             
                             cout <<"Email            ....   :";
                             cin  >>Rehber[kSayi].e_posta;
                             cout<<"\n";
                             
                             cout <<"Web Adresi      ....   :";
                             cin  >>Rehber[kSayi].web;
                             cout<<"\n";
                             
                             cout <<"Adres           ....   :";
                             cin  >>Rehber[kSayi].adres;
                             cout<<"\n";
                             
                     fprintf(dosya,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",Rehber[kSayi].ad,Rehber[kSayi].soyad,Rehber[kSayi].tel1 , Rehber[kSayi].tel2 , Rehber[kSayi].tel3 ,Rehber[kSayi].e_posta , Rehber[kSayi].web ,Rehber[kSayi].adres);
                     kSayi++;        
                     cout <<"\n\nEkleme islemine devam etmek istiyorsaniz 'e' veya 'E' tusuna basiniz. �stemiyorsaniz herhangi bir tusa basiniz.\n ";
                     cin >>tus;
                    }while(tus == 'e' || tus== 'E' );
                    {          fclose(dosya);
                               menu();
                    }
                
}


//Kullanıocıya yapmayı istedigi islemi soran menu fonksiyonu
void menu(){
             
                    int secim;      
                    
                    cout <<"Yapmak istediginiz islemi seciniz.\n";
                    cout <<"---------------------------------\n";
                    cout <<"1-Kayit Ekleme\n";
                    cout <<"2-Kayit Silme\n";
                    cout <<"3-Kayit Siralama\n";
                    cout <<"4-Kayit Duzeltme\n";
                    cout <<"5-Cikis\n";
                    cout <<"---------------------------------\n";
                    cin  >>secim;
                             
                             /*Secilen i�lemin ait oldugu fonk. �a��ral�m*/
                             switch(secim){
                                    
                                    case 1:
                                            kayit_ekleme();
                                            break;
                                    case 2:
                                           kayit_sil();
                                           break;
                                    case 3:
                                           kayit_listele();
                                           break;
                                    case 4:
                                           kayit_duzeltme();
                                           break;   
                             }
            
         
     
}
