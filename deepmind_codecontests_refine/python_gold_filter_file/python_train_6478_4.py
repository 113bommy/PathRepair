n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
ans=0
for i in range(n):
  if a[i]==1 and b[i] ==1:
    ans+=1
    a[i]=0
    b[i]=0
sa=sum(a)
sb=sum(b)
if ((sa==0 and sb==0) or (sa==0 and sb!=0)):
  print(-1)
elif sa>sb:
  print(1)
else:
  ans=sb//sa+1 
  print(ans)
