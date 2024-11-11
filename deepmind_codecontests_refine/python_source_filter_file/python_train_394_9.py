n,x=map(int,input().split())
a=list(map(int,input().split()))
sort(a)
for i in range(n):
  x-=a[i]
  if(x<0):
    break
if(x!=0):
  print(i)
else:
  print(n)