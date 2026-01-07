#include <stdio.h>
#include <math.h>

/* Fonksiyon Prototipleri */
void serbestDusme(double *g, char **gezegenler, int n);
void yukariAtis(double *g, char **gezegenler, int n);
void agirlikDeneyi(double *g, char **gezegenler, int n);
void potansiyelEnerji(double *g, char **gezegenler, int n);
void hidrostatikBasinc(double *g, char **gezegenler, int n);
void arsimet(double *g, char **gezegenler, int n);
void basitSarkac(double *g, char **gezegenler, int n);
void ipGerilmesi(double *g, char **gezegenler, int n);
void asansor(double *g, char **gezegenler, int n);

int main() {
    char bilimInsani[50];

    char *gezegenler[] = {
        "Merkur", "Venus", "Dunya", "Mars",
        "Jupiter", "Saturn", "Uranus", "Neptun"
    };

    double g[] = {
        3.7, 8.87, 9.81, 3.71,
        24.79, 10.44, 8.69, 11.15
    };

    int secim;

    printf("Uzay Simulasyonu Programina Hos Geldiniz!\n");
    printf("Bilim insaninin adini giriniz: ");
    fgets(bilimInsani, 50, stdin);

    for (int i = 0; bilimInsani[i] != '\0'; i++) {
        if (bilimInsani[i] == '\n') {
            bilimInsani[i] = '\0';
            break;
        }
    }

    do {
        printf("\n==============================\n");
        printf("1- Serbest Dusme Deneyi\n");
        printf("2- Yukari Atis Deneyi\n");
        printf("3- Agirlik Deneyi\n");
        printf("4- Potansiyel Enerji Deneyi\n");
        printf("5- Hidrostatik Basinc Deneyi\n");
        printf("6- Arsimet Kaldirma Kuvveti\n");
        printf("7- Basit Sarkac Periyodu\n");
        printf("8- Sabit Ip Gerilmesi\n");
        printf("9- Asansor Deneyi\n");
        printf("-1- Cikis\n\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);
        printf("\n");

        switch (secim) {
            case 1: serbestDusme(g, gezegenler, 8); break;
            case 2: yukariAtis(g, gezegenler, 8); break;
            case 3: agirlikDeneyi(g, gezegenler, 8); break;
            case 4: potansiyelEnerji(g, gezegenler, 8); break;
            case 5: hidrostatikBasinc(g, gezegenler, 8); break;
            case 6: arsimet(g, gezegenler, 8); break;
            case 7: basitSarkac(g, gezegenler, 8); break;
            case 8: ipGerilmesi(g, gezegenler, 8); break;
            case 9: asansor(g, gezegenler, 8); break;
            case -1: printf("Program sonlandiriliyor...\n"); break;
            default: printf("Gecersiz secim!\n");
        }

    } while (secim != -1);

    return 0;
}

/* ===================== DENEYLER ===================== */

void serbestDusme(double *g, char **gezegenler, int n) {
    double t;
    printf("Sure (s): ");
    scanf("%lf", &t);
    printf("\n");
    t = (t < 0) ? -t : t;

    for (int i = 0; i < n; i++) {
        double h = 0.5 * (*(g+i)) * t * t;
        printf("%s: %.2f metre\n", *(gezegenler+i), h);
    }
}

void yukariAtis(double *g, char **gezegenler, int n) {
    double v;
    printf("Ilk hiz (m/s): ");
    scanf("%lf", &v);
    printf("\n");
    v = (v < 0) ? -v : v;

    for (int i = 0; i < n; i++) {
        double h = (v*v) / (2 * (*(g+i)));
        printf("%s: %.2f metre\n", *(gezegenler+i), h);
    }
}

void agirlikDeneyi(double *g, char **gezegenler, int n) {
    double m;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("\n");
    m = (m < 0) ? -m : m;

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f Newton\n", *(gezegenler+i), m * (*(g+i)));
    }
}

void potansiyelEnerji(double *g, char **gezegenler, int n) {
    double m, h;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Yukseklik (m): ");
    scanf("%lf", &h);
    printf("\n");
    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f Joule\n", *(gezegenler+i), m * (*(g+i)) * h);
    }
}

void hidrostatikBasinc(double *g, char **gezegenler, int n) {
    double rho, h;
    printf("Yogunluk (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Derinlik (m): ");
    scanf("%lf", &h);
    printf("\n");
    rho = (rho < 0) ? -rho : rho;
    h = (h < 0) ? -h : h;

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f Pascal\n", *(gezegenler+i), rho * (*(g+i)) * h);
    }
}

void arsimet(double *g, char **gezegenler, int n) {
    double rho, V;
    printf("Yogunluk (kg/m^3): ");
    scanf("%lf", &rho);
    printf("Hacim (m^3): ");
    scanf("%lf", &V);
    printf("\n");
    rho = (rho < 0) ? -rho : rho;
    V = (V < 0) ? -V : V;

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f Newton\n", *(gezegenler+i), rho * (*(g+i)) * V);
    }
}

void basitSarkac(double *g, char **gezegenler, int n) {
    double L;
    printf("Ip uzunlugu (m): ");
    scanf("%lf", &L);
    printf("\n");
    L = (L < 0) ? -L : L;

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f saniye\n", *(gezegenler+i), 2 * M_PI * sqrt(L / (*(g+i))));
    }
}

void ipGerilmesi(double *g, char **gezegenler, int n) {
    double m;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("\n");
    m = (m < 0) ? -m : m;

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f Newton\n", *(gezegenler+i), m * (*(g+i)));
    }
}

void asansor(double *g, char **gezegenler, int n) {
    double m, a;
    int yon;

    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Ivme (m/s^2): ");
    scanf("%lf", &a);
    printf("\n");

    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    printf("\nIvme yonunu seciniz:\n");
    printf("1- Yukari ivmelenme (g + a)\n");
    printf("2- Asagi ivmelenme (g - a)\n");
    printf("Seciminiz: ");
    scanf("%d", &yon);

    printf("\n");

    for (int i = 0; i < n; i++) {
        double N;

        if (yon == 1) {
            N = m * ((*(g+i)) + a);
        } else if (yon == 2) {
            N = m * ((*(g+i)) - a);
        } else {
            printf("Gecersiz yon secimi!\n");
            return;
        }

        printf("%s: %.2f Newton\n", *(gezegenler+i), N);
    }
}



