
/****************************************************************************
**					          SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				             PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				        ÖDEV NUMARASI....: 1.PROJE
**				        ÖĞRENCİ ADI......: Ali Halit Örnek
**				        ÖĞRENCİ NUMARASI.: B231210385
**				        DERS GRUBU.......: A
****************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <random>
#include <algorithm>
using namespace std;
class Takim
{
public:
	int takimno;
	int takimpuani = 0;//başlangıçta her takımın puanı 0 dır
	string takimadi;
	string adres;
	long long telefon;
	int oyuncusayisi;
	string yoneticisiismi;
	string takimlar[100] = { "Besiktas","Fenerbahce","Galatasaray","Trabzonspor","Basaksehir","Alanyaspor","Antalyaspor","GaziantepFK","Goztepe","Hatayspor","Kasimpasa","Konyaspor","Rizespor","Malatyaspor","Sivasspor","Karagumruk","Kayserispor","Erzurumspor","Ankaragucu","Giresunspor" };
	string sehirler[100] = { "Istanbul","Istanbul","Istanbul","Trabzon","Istanbul","Alanya","Antalya","Gaziantep","Izmir","Hatay","Istanbul","Konya","Rize","Malatya","Sivas","Istanbul","Kayseri","Erzurum","Ankara","Giresun" };
	string isimler[49] = { "Ahmet", "Mehmet", "Mustafa", "Ali", "Kemal","Cem", "Murat", "Emre", "Eren", "Serkan","Tolga", "Omer", "Huseyin", "Baris", "Oguz","Berkay", "Fatih", "Yigit", "Taylan", "Okan","Onur", "Yasin", "Burak", "Furkan", "Can","Selim", "Umut", "Kaan", "Cihan", "Bora","Kerem", "Enes", "Ismail", "Orhan", "Levent","Mert", "Emir", "Hakan", "Cengiz", "Tarkan","Ruzgar", "Gokhan", "Deniz", "Yavuz", "Ilker","Volkan", "Ege", "Ozan", "Efe" };
	string soyisimler[50] = { "Yilmaz", "Kaya", "Demir", "Yildirim", "Celik","Karahan", "Aslan", "Sahin", "Turan", "Taskin","Cengiz", "Bilgin", "Toprak", "Arslan", "Guven","Yalcin", "Erbay", "Baysal", "Karabulut", "Akin","Cinar", "Duru", "Kilic", "Yilmazer", "Bulut","Duman", "Soylu", "Simsek", "Coskun", "Ozdemir","Unlu", "Uysal", "Yavuz", "Gunduz", "Tunc","Cetin", "Turk", "Erdogan", "Gokturk", "Yucel","Ege", "Sen", "Turkoglu", "Coban", "Aydin","Yaman", "Buyuk", "Erdem", "Kaplan", "Aykan" };
	int takimsayisi = 20;
	int haftasayisi = 20;//haftasayısı takımsayısı kadar olacak
	string yenitakimadi;//olusacak yeni takım

public:
	void takimlistele()//takımları listeler
	{
		int i = 0;
		string takimnodizi[20], takimpuanidizi[20], takimadidizi[20], adresdizi[20], telefondizi[20], oyuncusayisidizi[20], yoneticisiismidizi[20];
		system("cls");
		ifstream dosyaOku("takim.txt");
		cout << setw(15) << "Takim No" << setw(15) << "Takim puani" << setw(20) << "Takim Adi" << setw(20) << "Adres" << setw(15) << "Telefon" << setw(15) << "Oyuncu Sayisi" << setw(20) << "Yonetici Ismi" << endl;

		while (dosyaOku >> takimno >> takimpuani >> takimadi >> adres >> telefon >> oyuncusayisi >> yoneticisiismi)
		{
			takimnodizi[i] = to_string(takimno);
			takimpuanidizi[i] = to_string(takimpuani);
			takimadidizi[i] = takimadi;
			adresdizi[i] = adres;
			telefondizi[i] = to_string(telefon);
			oyuncusayisidizi[i] = to_string(oyuncusayisi);
			yoneticisiismidizi[i] = yoneticisiismi;
			i++;
		}
		for (int i = 0; i < takimsayisi - 1; i++)
		{
			for (int j = 0; j < takimsayisi - i - 1; j++)
			{
				if (takimpuanidizi[j] < takimpuanidizi[j + 1])
				{
					swap(takimpuanidizi[j], takimpuanidizi[j + 1]);
				}
			}
		}
		for (int i = 0; i < takimsayisi; i++)
		{
			cout << setw(15) << takimnodizi[i] << setw(15) << takimpuanidizi[i] << setw(20) << takimadidizi[i] << setw(20) << adresdizi[i] << setw(15) << telefondizi[i] << setw(15) << oyuncusayisidizi[i] << setw(20) << yoneticisiismidizi[i] << endl;
		}


		dosyaOku.close();
	}
	void rastgeletakimolustur()// program yeni başladığında rastgele takımlar oluşturur
	{

		ofstream dosyaYaz("takim.txt");

		for (int i = 0; i < 20; ++i) // 20 takım oluşturmak için
		{

			t[i].takimno = rand() % 100 + 1; // 1 ile 100 arasında rastgele takım numarası
			t[i].takimadi = takimlar[i];
			t[i].adres = sehirler[i];
			t[i].telefon = pow(rand() % 30000, 2) + 5000000000; // Rastgele bir 10 haneli telefon numarası
			t[i].oyuncusayisi = rand() % 20 + 20; // 20 ile 39 arasında rastgele oyuncu sayısı
			t[i].yoneticisiismi = isimler[rand() % 50] + soyisimler[rand() % 50];

			dosyaYaz << t[i].takimno << " " << t[i].takimpuani << " " << t[i].takimadi << ' ' << t[i].adres << ' ' << t[i].telefon << ' ' << t[i].oyuncusayisi << ' ' << t[i].yoneticisiismi << "\n";
		}

		dosyaYaz.close();
		cout << "Rastgele takımlar dosyaya yazıldı." << endl;
	}

	void macsonuclarigoster()// maç sonuclarını gösterir
	{
		int evSahibiGol, deplasmanGol;
		string takimadi1, takimadi2;
		ifstream dosyaOku("mac_sonuclari.txt");
		for (int hafta = 1; hafta <= haftasayisi; hafta++)
		{
			cout << "Hafta " << hafta << " Maclar ve Sonuclar:" << endl;
			for (int i = 0; i < takimsayisi; i += 2)
			{
				dosyaOku >> takimadi1 >> takimadi2 >> evSahibiGol >> deplasmanGol;
				cout << takimadi1 << " vs " << takimadi2 << ": " << evSahibiGol << "-" << deplasmanGol << endl;
			}
			cout << endl;
		}
	}

	void karisiktakimlar()// takimlari kariştırır
	{
		for (int i = takimsayisi - 1; i > 0; i--)
		{
			int r = rand() % (i + 1);
			swap(t[i], t[r]);

		}
	}


}t[100];

class Futbolcu : public Takim
{
private:
	long long tcno;
	string oyuncununtakimadi;
	string secilenoyuncununtakimadi;
	string ad;
	string soyad;
	int lisansno;
	string mevki;
	float maas;
	string oyuncular[50];
public:
	void oyuncuekle() //takim bilgilerini gosterir ve oyuncu kaydı yapar
	{
		char cevap = 'e';
		bool tckontrol = true;
		cout << " Oyuncunun takimadi :";
		cin >> oyuncununtakimadi;

		ifstream DosyaOku("takim.txt");
		ofstream DosyaYaz("futbolcu.txt", ios::app);
		ofstream geciciDosya("gecici.txt", ios::app);

		while (DosyaOku >> takimno >> takimpuani >> takimadi >> adres >> telefon >> oyuncusayisi >> yoneticisiismi)
		{
			if (takimadi == oyuncununtakimadi)
			{
				cout << "\n Takim Bilgileri \n";
				cout << " Takim numarasi   :" << takimno << endl;
				cout << " Takim puani   :" << takimpuani << endl;
				cout << "Takim adi      :" << takimadi << endl;
				cout << "Adresi  :" << adres << endl;
				cout << "Telefonu     :" << telefon << endl;
				cout << "Oyuncu sayisi :" << oyuncusayisi << endl;
				cout << "Yonetici ismi:" << yoneticisiismi << endl;
				cout << " Futbolcu eklemek istiyor musun? (e/h)" << endl;
				cin >> cevap;

				if (cevap == 'e')
				{
					// yeni oyuncu ekleme kısmı
					cout << "\n Futbolcu Bilgileri \n";

					while (tckontrol)
					{
						cout << "TC no   : ";
						cin >> tcno;

						// TC nonun 11 basamaklı olduğunu kontrol et
						if (to_string(tcno).length() == 11)
						{
							tckontrol = false;
						}
						else
						{
							cout << "Hata: TC no 11 basamakli olmalidir. Tekrar deneyin.\n";
						}
					}
					tckontrol = true;
					cout << "Adi  :"; cin >> ad;
					cout << "Soyadi     :"; cin >> soyad;
					cout << "Lisans No :"; cin >> lisansno;
					cout << "Mevki: "; cin >> mevki;
					cout << "Maas: "; cin >> maas;

					// yeni oyuncuyu dosyaya yazar
					DosyaYaz << tcno << " " << oyuncununtakimadi << ' ' << ad << ' ' << soyad << ' ' << lisansno << ' ' << mevki << ' ' << maas << "\n";

					// dosyada güncellenmiş takım bilgilerini yazar
					geciciDosya << takimno << " " << takimpuani << " " << takimadi << " " << adres << " " << telefon << " " << (oyuncusayisi + 1) << " " << yoneticisiismi << "\n";

					cout << "Yeni oyuncu eklendi.\n";
				}
			}
			else
			{
				// takım eşleşmediği durumda dosyaya aynı bilgileri yazar
				geciciDosya << takimno << " " << takimpuani << " " << takimadi << " " << adres << " " << telefon << " " << oyuncusayisi << " " << yoneticisiismi << "\n";
			}
		}

		DosyaOku.close();
		DosyaYaz.close();
		geciciDosya.close();
		// orijinal takım dosyasını sil
		remove("takim.txt");

		// geçici takım dosyasını orijinal dosya adıyla yeniden adlandır
		rename("gecici.txt", "takim.txt");
	}
	void oyuncusil() // oyuncu siler
	{
		long long silinecekoyuncutc;
		cout << "Silinecek futbolcunun TC kimlik numarasini yaziniz: ";
		cin >> silinecekoyuncutc;

		ifstream dosyaOku("futbolcu.txt");
		ofstream geciciDosya("gecici.txt", ios::app);

		while (dosyaOku >> tcno >> oyuncununtakimadi >> ad >> soyad >> lisansno >> mevki >> maas)
		{
			if (tcno != silinecekoyuncutc)
			{
				// silinmeyecek futbolcuları geçici dosyaya yaz
				geciciDosya << tcno << " " << oyuncununtakimadi << ' ' << ad << ' ' << soyad << ' ' << lisansno << ' ' << mevki << ' ' << maas << "\n";
			}
			else
			{
				secilenoyuncununtakimadi = oyuncununtakimadi;
			}
		}

		dosyaOku.close();
		geciciDosya.close();

		// orijinal dosyayı sil
		remove("futbolcu.txt");

		// geçici dosyayı orijinal dosya adıyla yeniden adlandır
		rename("gecici.txt", "futbolcu.txt");

		// Takım dosyasını güncelle
		ifstream dosyaOkuTakim("takim.txt");
		ofstream geciciDosyaTakim("gecici_takim.txt");

		while (dosyaOkuTakim >> takimno >> takimpuani >> takimadi >> adres >> telefon >> oyuncusayisi >> yoneticisiismi)
		{
			if (secilenoyuncununtakimadi == takimadi)
			{
				oyuncusayisi--; // oyuncu sayısını bir azalt
				geciciDosyaTakim << takimno << " " << takimpuani << " " << takimadi << " " << adres << " " << telefon << " " << oyuncusayisi << " " << yoneticisiismi << "\n";
			}
			else
			{
				geciciDosyaTakim << takimno << " " << takimpuani << " " << takimadi << " " << adres << " " << telefon << " " << oyuncusayisi << " " << yoneticisiismi << "\n";
			}
		}

		dosyaOkuTakim.close();
		geciciDosyaTakim.close();

		// orijinal takım dosyasını sil
		remove("takim.txt");

		// geçici takım dosyasını orijinal dosya adıyla yeniden adlandır
		rename("gecici_takim.txt", "takim.txt");

		cout << "Islem tamamlandi." << endl;
	}
	void oyuncuguncelle()//oyuncu günceller
	{
		long long guncellenecekoyuncutc;
		cout << "Guncellenecek futbolcunun TC kimlik numarasini yaziniz: ";
		cin >> guncellenecekoyuncutc;

		ifstream dosyaOku("futbolcu.txt");
		ofstream geciciDosya("gecici.txt", ios::app);

		bool oyuncubulundu = false;

		while (dosyaOku >> tcno >> oyuncununtakimadi >> ad >> soyad >> lisansno >> mevki >> maas)
		{
			if (tcno == guncellenecekoyuncutc)
			{
				// guncellenecek futbolcuyu kullanıcıdan alınan yeni bilgilerle güncelle
				cout << "Yeni adi giriniz: "; cin >> ad;
				cout << "Yeni soyadi giriniz: "; cin >> soyad;
				cout << "Yeni lisans numarasini giriniz: "; cin >> lisansno;
				cout << "Yeni mevkisini giriniz: "; cin >> mevki;
				cout << "Yeni maasi giriniz: "; cin >> maas;

				// güncellenmiş futbolcuyu geçici dosyaya yaz
				geciciDosya << tcno << " " << oyuncununtakimadi << ' ' << ad << ' ' << soyad << ' ' << lisansno << ' ' << mevki << ' ' << maas << "\n";

				cout << "Futbolcu basariyla guncellendi." << endl;
				oyuncubulundu = true;
			}
			else
			{
				// güncellenmeyecek futbolcuları geçici dosyaya yaz
				geciciDosya << tcno << " " << oyuncununtakimadi << ' ' << ad << ' ' << soyad << ' ' << lisansno << ' ' << mevki << ' ' << maas << "\n";
			}
		}

		dosyaOku.close();
		geciciDosya.close();

		// orijinal dosyayı sil
		remove("futbolcu.txt");

		// geçici dosyayı orijinal dosya adıyla yeniden adlandır
		rename("gecici.txt", "futbolcu.txt");

		if (!oyuncubulundu)
		{
			cout << "Belirtilen TC kimlik numarasina sahip futbolcu bulunamadi." << endl;
		}
	}
	void takimguncelle()// secilen bir takımın yerine yeni bir takım ekler
	{
		string guncellenecektakimadi;
		cout << "Guncellenecek takimin adini giriniz: ";
		cin >> guncellenecektakimadi;
		bool takimbulundu = false;
		ifstream dosyaOku("takim.txt");
		ofstream geciciDosya("gecici.txt");
		int sayac = 0;
		bool telefonkontrol = true;
		while (dosyaOku >> takimno >> takimpuani >> takimadi >> adres >> telefon >> oyuncusayisi >> yoneticisiismi)
		{

			if (takimadi == guncellenecektakimadi)
			{
				//kullanıcıdan yeni bilgileri alır
				cout << "\n Yeni Bilgileri Giriniz \n";
				cout << " Takim numarasi      :"; cin >> t[sayac].takimno;
				cout << " Takim adi           :"; cin >> t[sayac].takimadi;
				cout << " Adresi              :"; cin >> t[sayac].adres;
				while (telefonkontrol)
				{

					cout << " Telefonu            :";
					cin >> t[sayac].telefon;

					// telefon no'nun 10 basamaklı olduğunu kontrol et
					if (t[sayac].telefon > 5000000000 && t[sayac].telefon < 6000000000)
					{
						telefonkontrol = false;
					}

					else
					{

						cout << "Hata: Telefon no 5000000000 ile 6000000000 arasinda olmalidir. Tekrar deneyin.\n";
					}
				}
				telefonkontrol = true;
				cout << " Oyuncu sayisi       :"; cin >> t[sayac].oyuncusayisi;
				cout << " Yonetici ismi       :"; cin >> t[sayac].yoneticisiismi;
				yenitakimadi = t[sayac].takimadi;

				//güncellenmiş takımı geçici dosyaya yazar
				geciciDosya << t[sayac].takimno << " " << t[sayac].takimpuani << " " << t[sayac].takimadi << ' ' << t[sayac].adres << ' ' << t[sayac].telefon << ' ' << t[sayac].oyuncusayisi << ' ' << t[sayac].yoneticisiismi << "\n";

				cout << "Takim basariyla guncellendi." << endl;
				takimbulundu = true;
			}
			else
			{
				//güncellenmeyecek takımları geçici dosyaya yazar
				geciciDosya << t[sayac].takimno << " " << t[sayac].takimpuani << " " << t[sayac].takimadi << ' ' << t[sayac].adres << ' ' << t[sayac].telefon << ' ' << t[sayac].oyuncusayisi << ' ' << t[sayac].yoneticisiismi << "\n";
			}
			sayac++;
		}

		dosyaOku.close();
		geciciDosya.close();

		//orijinal dosyayı siler
		remove("takim.txt");

		//geçici dosyayı orijinal dosya adıyla yeniden adlandırır
		rename("gecici.txt", "takim.txt");
		if (!takimbulundu)
		{
			cout << "Belirtilen takim adina sahip takim bulunamadi." << endl;
		}

		oyuncuguncelleyenitakimicin(guncellenecektakimadi);
	}
	void oyuncuguncelleyenitakimicin(string guncellenecektakimadi)// yeni takım için oyuncuları yeni takıma göre günceller
	{

		ifstream dosyaOku("futbolcu.txt");
		ofstream geciciDosya("gecici.txt", ios::app);

		bool oyuncubulundu = false;

		while (dosyaOku >> tcno >> oyuncununtakimadi >> ad >> soyad >> lisansno >> mevki >> maas)
		{
			if (oyuncununtakimadi == guncellenecektakimadi)
			{


				//güncellenmiş futbolcuyu geçici dosyaya yazar
				geciciDosya << tcno << " " << yenitakimadi << ' ' << ad << ' ' << soyad << ' ' << lisansno << ' ' << mevki << ' ' << maas << "\n";

				oyuncubulundu = true;
			}
			else
			{
				//güncellenmeyecek futbolcuları geçici dosyaya yazar
				geciciDosya << tcno << " " << oyuncununtakimadi << ' ' << ad << ' ' << soyad << ' ' << lisansno << ' ' << mevki << ' ' << maas << "\n";
			}
		}

		dosyaOku.close();
		geciciDosya.close();

		//orijinal dosyayı siler
		remove("futbolcu.txt");

		//geçici dosyayı orijinal dosya adıyla yeniden adlandırır
		rename("gecici.txt", "futbolcu.txt");

		if (!oyuncubulundu)
		{
			cout << "Belirtilen TC kimlik numarasına sahip futbolcu bulunamadı." << endl;
		}
	}
	void rastgeleoyuncuolustur()// program ilk başladığında rastgele oyuncular oluşturur
	{

		ofstream dosyaYaz("futbolcu.txt");
		for (int j = 0; j < takimsayisi; j++)//bu döngü takimsayisi kadar oyuncu oluşturur 
		{
			for (int i = 0; i < t[j].oyuncusayisi; i++)//bu dögngü takim için oluşturulmuş oyuncu sayisi kadar oyuncu basar
			{

				f[i].tcno = pow(rand() % 4400, 3) + 10000000000; // rastgele tc numarası
				f[j].takimadi = takimlar[j];
				f[i].ad = isimler[rand() % 50];
				f[i].soyad = soyisimler[rand() % 50];
				f[i].lisansno = rand() % 100000;
				f[i].mevki = rastgelemevkisec();
				f[i].maas = rand() % 1000000 + 100000;

				dosyaYaz << f[i].tcno << " " << f[j].takimadi << " " << f[i].ad << ' ' << f[i].soyad << ' ' << f[i].lisansno << ' ' << f[i].mevki << ' ' << f[i].maas << "\n";
			}
		}


		dosyaYaz.close();
		cout << "Rastgele takımlar dosyaya yazıldı." << endl;
	}
	string rastgelemevkisec()// oyunculara rastgele mevkiler atar 1/11 ihtimalle haleci 4/11 ihtimalle defans 4/11 ihtimalle ortasaha 2/11 ihtimalle forvet olurlar
	{
		int sayi = rand() % 11;
		if (sayi == 0)
			return "kaleci";
		else if (sayi == 1 || sayi == 2 || sayi == 3 || sayi == 4)
			return "defans";
		else if (sayi == 5 || sayi == 6 || sayi == 7 || sayi == 8)
			return "ortasaha";
		else
			return "forvet";
	}
	void bilgigoster()// secilen bir takimin oyuncularını listeler
	{
		cout << " Oyuncunun takimadi :"; cin >> oyuncununtakimadi;
		ifstream DosyaOku("takim.txt");
		while (!DosyaOku.eof())
		{
			DosyaOku >> takimno >> takimpuani >> takimadi >> adres >> telefon >> oyuncusayisi >> yoneticisiismi;
			if (takimadi == oyuncununtakimadi)
			{
				cout << "\n Takim Bilgileri \n";
				cout << " Takim numarasi   :" << takimno << endl;
				cout << " Takim puani   :" << takimpuani << endl;
				cout << "Takim adi      :" << takimadi << endl;
				cout << "Adresi  :" << adres << endl;
				cout << "Telefonu     :" << telefon << endl;
				cout << "Oyuncu sayisi :" << oyuncusayisi << endl;
				cout << "Yonetici ismi:" << yoneticisiismi << endl;
				DosyaOku.close();

				DosyaOku.open("futbolcu.txt", ios::in);
				cout << " futbolcu bilgileri \n" << endl;
				cout << setw(11) << " TC no  " << setw(20) << " oyuncunun takimadi " << setw(12) << " adi " << setw(10) << "  soyadi " << setw(10) << " lisansno" << setw(10) << " mevki" << setw(10) << " maas" << endl;
				while (DosyaOku >> tcno >> oyuncununtakimadi >> ad >> soyad >> lisansno >> mevki >> maas)
				{



					if (takimadi == oyuncununtakimadi)
					{
						cout << setw(11) << tcno << setw(20) << oyuncununtakimadi << setw(12) << ad << setw(10) << soyad << setw(10) << lisansno << setw(10) << mevki << setw(10) << maas << endl;
					}
				}
				DosyaOku.close();

			}
		}
	}
	void oyuncuSec(string istenentakimadi)// her takım için ayrı ve her hafta için ayrı olmak üzere oynayan oyuncuları dosyalara kayıt eder
	{
		int i = 0;

		ifstream DosyaOku1("futbolcu.txt");

		//takimadlarina göre oyuncuları parçalıyotuz 35 oyuncu varsa 35 oyuncu için oyuncular[] dizisi yapılıyor
		while (DosyaOku1 >> tcno >> oyuncununtakimadi >> ad >> soyad >> lisansno >> mevki >> maas)
		{
			if (istenentakimadi == oyuncununtakimadi)
			{
				oyuncular[i] = ad + " " + soyad;
				i++;
			}

		}

		int r;
		for (int i = 1;i <= 20;i++)//20 hafta için 20 kere dönmeli
		{
			for (int k = 1; k < 40; k++)//en fazla 39 kişilik bir takım olabilir oyuzden 40 yazıldı bu işlem rastgele oyuncuları sıralıyor
			{
				r = rand() % (k + 1);
				swap(oyuncular[k], oyuncular[r]);
			}
			ofstream DosyaYaz1(to_string(i) + istenentakimadi + "oynayanoyuncular.txt");//hafta sayısı + takim adı + txt formatında

			for (int j = 0;j < 11;j++)
			{
				DosyaYaz1 << oyuncular[j] << "\n";//sıralanmış oyuncular ilgili haftaya kayıt ediliyor
			}
			DosyaYaz1.close();
		}

		DosyaOku1.close();


	}
	void secilenoyuncularıgoster()// istenilen hafta için ve istenilen takım için secilen oyuncuları gösterir
	{
		system("cls");
		int kacıncıhafta;
		string istenentakimadi;
		cout << "Kacinci haftanin verisini istiyorsun\n"; cin >> kacıncıhafta;
		cout << "Hangi takimin verisini istiyorsun\n"; cin >> istenentakimadi;
		system("cls");
		ifstream DosyaOku(to_string(kacıncıhafta) + istenentakimadi + "oynayanoyuncular.txt");
		while (DosyaOku >> ad >> soyad)
		{
			cout << ad << " " << soyad << "\n";
		}

		DosyaOku.close();
	}
	void macsonuclarihesapla()
	{
		ofstream dosyaYaz("mac_sonuclari.txt");
		ofstream dosyaYaz2("takim.txt");


		for (int hafta = 1; hafta <= haftasayisi; hafta++)
		{
			karisiktakimlar();
			for (int i = 0; i < takimsayisi; i++)
			{
				oyuncuSec(t[i].takimadi);
			}
			cout << "Hafta " << hafta << " Maclar ve Sonuclar:" << endl;

			for (int i = 0; i < takimsayisi; i += 2)
			{
				int evsahibigol = rand() % 5;   // 0-4 arasında rastgele gol sayısı
				int deplasmangol = rand() % 5; // 0-4 arasında rastgele gol sayısı
				rasgelegolatanlar(hafta, t[i].takimadi, evsahibigol);
				rasgelegolatanlar(hafta, t[i + 1].takimadi, deplasmangol);

				cout << t[i].takimadi << " vs " << t[i + 1].takimadi << ": " << evsahibigol << "-" << deplasmangol << endl;

				dosyaYaz << t[i].takimadi << " " << t[i + 1].takimadi << " " << evsahibigol << " " << deplasmangol << endl;

				if (evsahibigol > deplasmangol) // ev sahibi galibiyeti +3 puan
				{
					t[i].takimpuani += 3;
				}
				else if (evsahibigol < deplasmangol) // deplasman galibiyeti +3 puan
				{
					t[i + 1].takimpuani += 3;
				}
				else // beraberlik her iki takıma +1'er puan
				{
					t[i].takimpuani++;
					t[i + 1].takimpuani++;
				}


			}

			cout << endl;
		}



		for (int i = 0; i < takimsayisi; i++)
		{
			dosyaYaz2 << t[i].takimno << " " << t[i].takimpuani << " " << t[i].takimadi << ' ' << t[i].adres << ' ' << t[i].telefon << ' ' << t[i].oyuncusayisi << ' ' << t[i].yoneticisiismi << "\n";
		}

		dosyaYaz.close();
		dosyaYaz2.close();
	}
	void rasgelegolatanlar(int hafta, string takimadi, int golsayisi)
	{
		ofstream DosyaYaz("hafta" + to_string(hafta) + takimadi + "golatanlar.txt");
		ifstream DosyaOku(to_string(hafta) + takimadi + "oynayanoyuncular.txt");
		string ad, soyad;
		string oyuncular[50];
		int i = 0;

		while (DosyaOku >> ad >> soyad)
		{
			oyuncular[i] = ad + " " + soyad;
			i++;
		}

		for (int i = 0; i < golsayisi; i++)
		{
			string golcu = oyuncular[i];
			DosyaYaz << golcu << "\n";
		}

		DosyaYaz.close();
		DosyaOku.close();
	}



}f[1000];

int main()
{

	srand(time(0));
	string secim = "0";
	t[0].rastgeletakimolustur();
	f[0].rastgeleoyuncuolustur();
	system("color E1");
	while (1)
	{
		secim = "0";
		do
		{
			system("cls");
			cout << "   Ne yapmak istiyorsunuz ? " << endl;
			cout << "   1) Takim olustur " << endl;
			cout << "   2) Takim listele " << endl;
			cout << "   3) Takim bilgilerini goster ve oyuncu kayit ekle  " << endl;
			cout << "   4) Oyuncu kayit sil  " << endl;
			cout << "   5) Oyuncu kayit guncelle  " << endl;
			cout << "   6) Oyunculari listele " << endl;
			cout << "   7) Macsonuclari hesapla " << endl;
			cout << "   8) Macsonuclari goster " << endl;
			cout << "   9) Secilen bir haftadaki oynayan oyunculari goster" << endl;
			cin.clear();
			cin >> secim;
		} while (secim != "1" && secim != "2" && secim != "3" && secim != "4" && secim != "5" && secim != "6" && secim != "7" && secim != "8" && secim != "9");
		if (secim == "1")
		{
			f[0].takimguncelle();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "2")
		{
			t[0].takimlistele();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "3")
		{
			f[0].oyuncuekle();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "4")
		{
			f[0].oyuncusil();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "5")
		{
			f[0].oyuncuguncelle();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "6")
		{
			f[0].bilgigoster();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "7")
		{
			f[0].macsonuclarihesapla();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "8")
		{
			t[0].macsonuclarigoster();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}
		if (secim == "9")
		{
			f[0].secilenoyuncularıgoster();
			cout << "Ana menuye donmek icin herhangi bir tusa basin";
			_getch();
		}

	}



}

