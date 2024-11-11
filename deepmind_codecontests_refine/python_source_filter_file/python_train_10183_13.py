N, K = map(int, input().split())
sushi = [list(map(int, input().split())) for _ in range(N)]
sushi = sorted(sushi, key=lambda x: x[1], reverse=True)
typ = set()
lstA = []
lstB = []
for item in sushi:
    if item[0] in typ:
        item[0] = 0
        lstB.append(item[1])
    else:
        typ.append(item[0])
        item[0] = 1
        lstA.append(item[1])
ans = 0
neta = 0
for i in range(K):
    ans += sushi[i][1]
    if sushi[i][0] == 1:
        neta += 1
ans += neta ** 2
C = sum(lstA[:neta])
D = sum(lstB[:K - neta])
for i in range(neta + 1, min(K, len(lstA)) + 1):
    C += lstA[i - 1]
    D -= lstB[K - i]
    tmp = C + D + i ** 2
    ans = max(ans, tmp)
print(ans)