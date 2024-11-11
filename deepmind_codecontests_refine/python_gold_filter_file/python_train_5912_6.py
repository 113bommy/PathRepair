L=[]
R=[]
N,K,C=map(int,input().split())
S=list(input())
s=S[::-1]
i=0
while len(L)<K:
    if S[i]=='o':
        L.append(i+1)
        if i+C<N:
            for j in range(1,C+1):
                S[i+j]='x'
    i+=1
k=0
while len(R)<K:
    if s[k]=='o':
        R.append(N-k)
        if k+C<N:
            for l in range(1,C+1):
                s[k+l]='x'
    k+=1
R=R[::-1]
ans=[]
for i in range(K):
    if L[i]==R[i]:
        ans.append(L[i])
print(*ans)