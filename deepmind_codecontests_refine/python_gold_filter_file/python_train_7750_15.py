n,s = map(int, input().split())
L = [list(map(int, input().split())) for _ in range(n)]

P = []
for i in range(n):
    if L[i][0] < s or (L[i][0] == s and L[i][1] == 0):
        P = P + [L[i][1]]
if P == []:
    print(-1)
else:
    m = P[0]
    for i in range(1,len(P)):
        if P[i] and P[i] < m:
            m = P[i]
    if m:
        print(100-m)
    else:
        print(0)
