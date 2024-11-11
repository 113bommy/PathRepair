N,C,K=map(int,input().split())
T=[]

for i in range(N):
    T.append(int(input()))

T.sort()
ans=1
mem=1
s=T[0]

for i in range(N):
    if T[i]>s+K or mem>=C:
        ans+=1
        s=T[i]
        mem=1
    else:
        mem+=1
print(ans)