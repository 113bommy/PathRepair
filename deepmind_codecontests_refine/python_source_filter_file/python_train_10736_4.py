n,m = [int(x) for x in input().split()]

L = [int(x) for x in input().split()]

large = max(L)
R = []
used = 0
Pairs = []
best = 0
lol = []
for i in range(n):
    if L[i] == large:
        R.append(i)


for T in range(m):
    l,j = [int(x) for x in input().split()]
    Pairs.append((l,j))

for j in range(0,n):
    S = L[:]
    tu = 0
    tuu = []
    for i in range(m):
        if (Pairs[i][0]-1 > j) or (Pairs[i][1] <= j):
            tu += 1
            tuu.append(i+1)
            for k in range(Pairs[i][0]-1,Pairs[i][1]):
                S[k] -= 1
    t = max(S)-min(S)
    if t > best:
        best = t
        used = tu
        lol = tuu
        
print(t)
print(used)
print(' '.join(str(i) for i in lol))
