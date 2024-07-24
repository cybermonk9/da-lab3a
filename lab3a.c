#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 10
void floyd(int w[MAX_VERTICES][MAX_VERTICES], int n) {
int i, j, k;
for (k = 1; k <= n; k++) {
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (w[i][k] != INT_MAX && w[k][j] != INT_MAX) {

{if (w[i][j] > w[i][k] + w[k][j]) {
w[i][j] = w[i][k] + w[k][j];
}
}
}
}
}
}
int main() {
int a[MAX_VERTICES][MAX_VERTICES];
int n, i, j;
printf("Enter the number of vertices: ");
scanf("%d", &n);
printf("Enter the weighted matrix:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
scanf("%d", &a[i][j]);
if (a[i][j] == 0 && i != j) {
a[i][j] = INT_MAX;
}
}
}
floyd(a, n);
printf("The shortest path matrix is:\n");
for (i = 1; i <= n; i++) {
for (j = 1; j <= n; j++) {
if (a[i][j] == INT_MAX) {
printf("INT_MAX\t");
} else {
printf("%d\t", a[i][j]);
}
}
printf("\n");
}
return 0;
}
