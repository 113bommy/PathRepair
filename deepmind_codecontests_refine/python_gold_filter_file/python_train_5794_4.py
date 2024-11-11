n, k = map(int, input().split());
A = list(map(int, input().split()));
B = [];
for q in range(n):
    B.append(0);
y = n - k - 1;
if y > 0:
    y = 0;
B[0] = k + 1 + y;
for q in range(1, n):
    z = k - q;
    y = n - q - k - 1;
    y1 = n - A[q] + 1 - k - 1;
    if y1 > 0:
        y1 = 0;
    if y > 0:
        y = 0;
    if z < 0:
        z = 0;
    #print("z =", z, end = " ");
    r = q - A[q] + 1;
    x1 = r - 2 * k - 1;
    x = (r - 2 * k - 1) + z - y1;
    #print("r =", r, "x1 =", x1, "x =", x, "y =", y, "y1 =", y1);
    if x > 0:
        x = 0;
    if A[q] != 0:
        B[q] = B[A[q] - 1] + 2 * k + 1 + x + y - z;
    else:
        B[q] = 2 * k + 1 + y - z;
#print();
print(*B);