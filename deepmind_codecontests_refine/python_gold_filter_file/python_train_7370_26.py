N=int(input())
xy=[list(map(int,input().split())) for _ in [0]*N]

pq = {0:0}
for i in range(N):
    for j in range(N):
        if i==j:continue
        p = xy[i][0] - xy[j][0]
        q = xy[i][1] - xy[j][1]
        pq[(p,q)] = pq.get((p,q),0)+1

print(N - max(pq.values()))