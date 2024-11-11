from collections import Counter

N, M = map(int, input().split())
adjL = [[] for _ in range(N)]
degs = [0] * N
for _ in range(M):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    adjL[a].append(b)
    adjL[b].append(a)
    degs[a] += 1
    degs[b] += 1

cnt = Counter(degs)

if any([key%2 for key in cnt.keys()]):
    print('No')
else:
    cnt[2] = 0
    if sum(cnt.values()) >= 4 or max(cnt.keys()) >= 6:
        print('Yes')
    elif cnt[4] < 2:
        print('No')
    else:
        useds = [False] * N
        vs = []
        for v in range(N):
            if degs[v] == 4:
                useds[v] == True
                vs.append(v)
        for v2 in adjL[vs[0]]:
            v, vPar = v2, vs[0]
            while not useds[v]:
                useds[v] = True
                for v2 in adjL[v]:
                    if v2 != vPar:
                        vPar = v
                        v = v2
                        break
        if all(useds):
            print('No')
        else:
            print('Yes')
