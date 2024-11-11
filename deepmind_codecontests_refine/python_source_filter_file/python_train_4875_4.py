N,M = map(int,input().split())
L = []
for _ in range(M):
    L.append(list(map(int,input().split())))
L = sorted(L,key=lambda x:x[1])
now = -10
cnt = 0
for x in L:
    if now < x[0]:
        now = x[1]
        cnt += 1
print(cnt)
