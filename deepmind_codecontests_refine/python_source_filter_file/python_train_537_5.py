t = int(input())

for i in range(t):
    kol = int(1e9)
    n, k, d = map(int, input().split())
    ti = list(map(int, input().split()))
    for j in range(n - d + 1):
        s = set(ti[j:j + d+1])
        if len(s) < kol:
            kol = len(s)
    print(kol)
