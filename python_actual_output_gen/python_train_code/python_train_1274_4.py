n=int(input())
d=list(map(int,input().split()))
a,b=map(int,input().split())
ans=0
for i in range(abs(a-b)):
     ans+=d[i]
print(ans)
     
     
