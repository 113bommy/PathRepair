n, k = map(int, input().split())
L = list(map(int, input().split()))
ins = 0
INS = []
while k - min(L) >= 0:
        k -= min(L)
        i = L.index(min(L))
        INS += [i+1]
        ins += 1
        L[i] = 101
if ins == 0:
    print(0)
else:
    print(ins)
    for i in INS[:-1]:
        print(i, end=' ')
    print(INS[-1])
