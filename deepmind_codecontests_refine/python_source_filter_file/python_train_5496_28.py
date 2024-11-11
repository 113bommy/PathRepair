m=int(input())
a=0
ans=-1
for i in range(m):
  x,y=map(int,input().split())
  a+=x*y
  ans+=y
    
if a%9==0:
  ans+=(a/9)-1
else:
  ans+=a//9
  
print(ans)