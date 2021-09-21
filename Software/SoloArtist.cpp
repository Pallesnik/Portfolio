#include "SoloArtist.h"

bool SoloArtist::hasBackingBand(){
    char h;
    cout << "Does the artist have a backing band?(Y for yes or N for no):";
    cin >> h;
    toupper(h);
    if(h == 'Y'){
        return true;
    }
    else if (h == 'N'){
        return false;
    }
    else{
        cout << "Enter a valid answer:";
        cin >> h;
    }

}
