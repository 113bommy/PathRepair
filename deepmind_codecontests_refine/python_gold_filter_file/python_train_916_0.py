from collections import Counter

N=int(input())
L=list(map(int,input().split()))
S=[0]*(N+1)
for i in range(1,N+1):
	S[i]=S[i-1]+L[i-1]
#print(S)
M=Counter(S)
#print(M)
ans=0
for i,j in M.items():
	ans+=(j*(j-1)//2)
print(ans)