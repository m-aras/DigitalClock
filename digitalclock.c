#include <stdio.h>
#include <windows.h>
#include <conio.h>   // _kbhit, _getch
#include <ctype.h>   // tolower

int main(void) {

    printf("Cikmak icin Q\nDijital Saat\n\n");

    while (1) {
        SYSTEMTIME st;
        GetLocalTime(&st); // doğrudan yıl/ay/gün/saat/dk/sn hazır

        // Aynı satırı güncelle
        printf("\r%02d:%02d:%02d  %02d/%02d/%04d",
               st.wHour, st.wMinute, st.wSecond,
               st.wDay, st.wMonth, st.wYear);
        fflush(stdout);

        // Bloklamadan çıkış kontrolü
        if (_kbhit()) {
            int ch = _getch();
            if (tolower(ch) == 'q') break;
        }

        // Bir sonraki saniye sınırına kadar bekle
        DWORD ms = (st.wMilliseconds >= 1000) ? 0 : (1000 - st.wMilliseconds);
        Sleep(ms ? ms : 1); // 0 verirsen bazen beklemeyebilir; 1ms güvenli
    }
    return 0;
}
