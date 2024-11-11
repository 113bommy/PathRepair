N,M,Q = map(int, input().split())

LR = [list(map(int, input().split())) for i in range(M)]
pq = [list(map(int, input().split())) for i in range(Q)]

res = [[0]*N for i in range(N)]

def lsadd(L,R):
    L-=1
    R-=1
    for i in range(0,L+1):  
        res[i][R] += 1

for l,r in LR:
    lsadd(l,r)

for p,q in pq:
    print(sum(res[p-1][:q]))
