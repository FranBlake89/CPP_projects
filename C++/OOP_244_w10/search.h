/*
Francisco Castillo
fcastillo-rojas1@myseneca.ca
*/
#ifndef SDDS_SEARCH_H_
#define SDDS_SEARCH_H_
namespace sdds {
    template <class Templ>
        bool searching(Templ arr[], int nElemArr, const char* strKey, Collection <Templ> *resp)
    {
            bool isMatch = false;

            int size = nElemArr;
            
            for (int i = 0; i < size; i++) {
                if (arr[i] == strKey) {
                    isMatch = true;
                    resp->add(arr[i]);
                }
            }

        return isMatch;
    }
}

#endif // !SDDS_SEARCH_H_