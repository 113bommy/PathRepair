t=int(input())
x=[]
a=list(map(int,input().strip().split(" ")))
b=list(map(int,input().strip().split(" ")))

for i in range(t):
    a[i]-=b[i]
a.sort()
ans=0
pp=t-1
for i in range(t):
    while(pp and a[pp]+a[i]>0):
        pp-=1
    ans+=min(t-pp,t-i)
print(ans)
    
