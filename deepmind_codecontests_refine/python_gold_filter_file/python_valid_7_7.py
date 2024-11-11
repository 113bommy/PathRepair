from math import gcd

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    dif = [abs(a[i] - a[i+1]) for i in range(n-1)]
    maxim, cua = 1, []
    for i, d in enumerate(dif):
        cua.append((d, i))
        nova_cua = []
        for c, p in cua:
            c = gcd(d, c)
            if c != 1 and (not nova_cua or c > nova_cua[-1][0]):
                nova_cua.append((c, p))
                maxim = max(maxim, i - p + 2)
        cua = nova_cua
    print(maxim)