n=int(input())
l=[tuple(map(int,input().split())) for i in range(n)]
d1={}
d2={}
for i in range(n):
    x,y=l[i]    
    d1[x-y]=d1.get(x-y,0)+1
    d2[y+x]=d2.get(y+x,0)+1
ans=0
for k in d1: ans+=(d1[k]-1)*d1[k]//2
for k in d1: ans+=(d1[k]-1)*d1[k]//2
print(ans)