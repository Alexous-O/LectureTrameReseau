
#include <iostream>
using namespace std ;

int main()
{
    unsigned char	cTrame[] = {
                            0x00, 0x15, 0xC6, 0x02, 0x6B, 0xA6, 0x54, 0x42,
                            0x49, 0xF5, 0x77, 0x75, 0x08, 0x00, 0x45, 0x10,
                            0x00, 0x49, 0x80, 0x93, 0x40, 0x00, 0x40, 0x06,
                            0x4E, 0x53, 0xAC, 0x10, 0x00, 0x01, 0xC0, 0xA8,
                            0xFE, 0xFE, 0x4A, 0x65, 0x20, 0x73, 0x75, 0x69,
                            0x73, 0x20, 0x50, 0x61, 0x74, 0x20, 0x50, 0x73,
                            0x79, 0x6B, 0x6F, 0x2C, 0x20, 0x6A, 0x27, 0x68,
                            0x61, 0x62, 0x69, 0x74, 0x65, 0x20, 0x4E, 0x61,
                            0x6E, 0x74, 0x65, 0x73, 0x20, 0x65, 0x74, 0x20,
                            0x6A, 0x65, 0x20, 0x74, 0x65, 0x6E, 0x74, 0x65,
                            0x20, 0x64, 0x65, 0x20, 0x70, 0x69, 0x72, 0x61,
                            0x74, 0x65, 0x72, 0x20, 0x4E, 0x65, 0x74, 0x20,
                            0x4F, 0x27, 0x46, 0x72, 0x69, 0x67, 0x6F, 0x20,
                            0x21, 0x0D, 0x0A, 0x00, 0x32, 0x30, 0x32, 0x30,
                            0x2D, 0x31, 0x32, 0x2D, 0x30, 0x37, 0x00, 0x00   } ;

    unsigned char   cTabIP[4] ;
    unsigned char   cTabMAC[6] ;
    unsigned char   cTabPaquet[86] ;
	unsigned int    Offset  (0) ;

    // INIT DES TABLEAUX
	for (unsigned int i (0); i < 6; i++)
    {
        cTabMAC[i] = 0 ;
    }
	for (unsigned int i (0); i < 4; i++)
    {
        cTabIP[i] = 0 ;
    }
	for (unsigned int i (0); i < 86; i++)
    {
        cTabPaquet[i] = 0 ;
    }

    // TRAITEMENT
    //Extraction de l'adresse MAC source
    Offset = 6 ;
	for (unsigned int i (0); i < 6; i++)
    {
        cTabMAC[i] = cTrame[i+Offset] ;
    }

    //Extraction de l'adresse IP source
    Offset = 26 ;
	for (unsigned int i (0); i < 4; i++)
    {
        cTabIP[i] = cTrame[i+Offset] ;
    }

    //Extraction des données de paquet
    Offset = 34 ;
	for (unsigned int i (0); i < 86; i++)
    {
        cTabPaquet[i] = cTrame[i+Offset] ;
    }


    // AFFICHAGES
    // L'adresse MAC doit être affichée en hexa
	for (unsigned int i (0); i < 6; i++)
    {
		cout << hex << static_cast<unsigned int>(cTabMAC[i]) ;
		if(i < 6-1)
		{
			cout << ":" ;
		}
    }
    cout << endl ;

    // L'adresse IP doit être affichée en décimal
	for (unsigned int i (0); i < 4; i++)
    {
		cout << dec << static_cast<unsigned int>(cTabIP[i]) ;
		if(i < 4-1)
		{
			cout << "." ;
		}
	}
    cout << endl ;

    // Les données doivent être affichées sous forme de texte
	for (unsigned int i (0); i < 86; i++)
    {
        cout << cTabPaquet[i] ;
    }
    cout << endl ;

    // La date doit être affichée sous forme de texte
	for (int i (74) ; i < 86; i++)
    {
        cout << cTabPaquet[i] ;
    }
    cout << endl ;
	// ou plus simplement… Mais on reverra ça plus tard…
	// cout << &(cTabPaquet[74]) << endl ;

    return 0 ;
}
