n=int(input())
l=list(map(int,input().split()))
a=sum(l)/n
ans=0
b=100
for i in range(n):
  if b>abs(l[i]-a):
    b=abs(l[i]-a)
    ans=i
print(ans)