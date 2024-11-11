N = 50001
a = [True] *  N
i = 3
while i * i < N:
    for j in range(3 * i, N, 2 * i): a[j] = False
    i += 2
 
while True:
    try:
        n = int(input())
    except:
        break

    n0 = n + 2 if (n & 1) else n + 1
    for maxv in range(n0, N, 2):
        if a[maxv]: break
    n0 = n - 2 if (n & 1) else n - 1
    for minv in range(n0, 2, -2):
        if a[minv]: break
    else:
        minv = 2

    print(minv, maxv)