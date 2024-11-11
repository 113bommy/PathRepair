n = int(input())
H = list(map(int, input().split()))
d = 0; f = 0; m = 10 ** 9 + 7

if n > 1:
    for i in range(n):
        if H[i] < 0:
            f += 1
        d += abs(H[i])
        if abs(H[i]) < m:
            m = abs(H[i])

    if f == 0 or f == n:
        print(d - m*2)
    else:
        print(d)
else:
    print(d)