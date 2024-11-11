N,K=map(int,input().split())
S=list(map(int,input().split()))
ans=float("inf")
if N==1:
	ans=S[0]
for i in range(N-K):
	L=S[i]
	R=S[i+K-1]
	ans=min(abs(L)+abs(R-L),abs(R)+abs(L-R),ans)
print(ans)