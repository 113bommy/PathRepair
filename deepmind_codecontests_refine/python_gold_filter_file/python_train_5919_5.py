n=int(input())
a=list(map(int,input().split()))
ans=1
temp=0
for i in range(1,n):
  if a[i-1]<a[i] and temp==0:
    temp=1
  elif a[i-1]>a[i] and temp==0:
    temp=2
  elif a[i-1]>a[i] and temp==1:
    temp=0
    ans=ans+1
  elif a[i-1]<a[i] and temp==2:
    temp=0
    ans=ans+1
print(ans)