#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, d;
    float delta, k, x1, x2, x3, x0, x, X;

    printf("Nhập hệ số của phương trình bậc 3: ");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    delta = pow(b, 2) - 3 * a * c;
    k = (9 * a * b * c - 2 * pow(b, 3) - 27 * pow(a, 2) * d) / (2 * sqrt(fabs(pow(delta, 3))));

    if (delta > 0) {
        if (fabs(k) <= 1) {
            x1 = (2 * sqrt(delta) * cos(acos(k) / 3) - b) / (3 * a);
            x2 = (2 * sqrt(delta) * cos(acos(k) / 3 - (2 * M_PI / 3)) - b) / (3 * a);
            x3 = (2 * sqrt(delta) * cos(acos(k) / 3 + (2 * M_PI / 3)) - b) / (3 * a);
            printf("Phương trình có ba nghiệm thực:\n%.2f\n%.2f\n%.2f", x1, x2, x3);
        } else {
            x0 = ((sqrt(delta) * fabs(k)) / (3 * a * k)) *
                 (pow(fabs(k) + sqrt(pow(k, 2) - 1), 1.0 / 3.0)
                  + pow(fabs(k) - sqrt(pow(k, 2) - 1), 1.0 / 3.0))
                 - (b / (3 * a));
            printf("Phương trình có nghiệm duy nhất:\n%.2f", x0);
        }
    } else if (delta == 0) {
        X = (-b + pow(pow(b, 3) - 27 * pow(a, 2) * d, 1.0 / 3.0)) / (3 * a);
        printf("Phương trình có nghiệm kép:\n%.2f", X);
    } else {
        x = (sqrt(fabs(delta)) / (3 * a)) *
            (pow(k + sqrt(pow(k, 2) + 1), 1.0 / 3.0)
             + pow(k - sqrt(pow(k, 2) + 1), 1.0 / 3.0))
            - (b / (3 * a));
        printf("Phương trình có nghiệm duy nhất:\n%.2f", x);
    }

    return 0;
}