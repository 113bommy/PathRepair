
N,Q=map(int,input().split())
AB = [list(map(int,input().split())) for _ in range(N-1)]
PQ = [list(map(int,input().split())) for _ in range(Q)]
AB.sort()
PQ.sort()
l=[[] for _ in range(N)]
ans=[0]*N
for a,b in AB:
	l[a-1].append(b-1)
for p,q in PQ:
	ans[p-1]+=q
for i in range(N-1):
	for j in l[i]:
		ans[j]+=ans[i]
	
print(*ans)