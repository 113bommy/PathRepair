n = int(input())
L = list(map(int,input().split()));
p = 0
f = tuple(L);
k = 0
for m in range(1,101):
    for i in range(0,n):
        if L[i] >= p:
            p = L[i]
            k = i
    if k == 0:
        print(L[0] - f[0])
        break
    L[k] = L[k] - 1
    L[0] = L[0] + 1
    p = 0

