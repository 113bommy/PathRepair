n,m=map(int,input().split())
l=list(map(int,input().split()))
count=0
if l[i]>m:
  count+=-m+l[i]
  l[i]=m
for i in range(1,n):
  if l[i-1]+l[i]>m:
    count+=l[i]+l[i-1]-m
    l[i]=m-l[i-1]   
print(count)
