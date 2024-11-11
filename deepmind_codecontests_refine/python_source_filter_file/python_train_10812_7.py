X='abcdefghijklmnopqrstuvwxyz'*2
S=input()
k=int(input())
N=[]
for s in S:
    if s=='a':
        N.append(0)
    else:
        N.append(26-X.index(s))
ans=''
for i in range(len(S)):
    if N[i]<=k :
        k-=N[i]
        ans+='a'
    else:
        ans+=S[i]
ans=ans[:-1]+X[X.index(ans[-1])+k]

print(ans)
