n,m=map(int,input().split())
l=list(map(int,input().split()))
count=0
if l[0]>m:
  count+=m-l[0]
  l[0]=m
for i in range(1,n):
  if l[i-1]+l[i]>m:
    count+=l[i]+l[i-1]-m
    l[i]=m-l[i-1]   
print(count)
