n=int(input())
a=[int(i) for i in input().split()]
hashi=[0]*(n+1)
for i in a:
    hashi[i]+=1
ans=0
for i in range(1,n):
    if hashi[i]-1:
        hashi[i+1]+=hashi[i]-1
        ans+=hashi[i]-1
print(ans)
