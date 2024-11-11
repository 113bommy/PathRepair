def f(L,res):
    for i in range(1,M+1):
        #print(i,L[i])
        if len(L[i]) == 1:
          L[L[i][0]].remove(i)
          L[i] = []
          res = f(L,res+1)
    return res


N,M = map(int,input().split())
L = [[] for _ in range(N+1)]

for i in range(M):
    a,b = map(int,input().split())
    L[a].append(b)
    L[b].append(a)
print(f(L,0))