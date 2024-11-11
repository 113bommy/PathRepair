n=int(input())

a=[int(_) for _ in input().split()]
b=[int(_) for _ in input().split()]

m=sum(b)-sum(a)
l=0
for i in range(n):
  if a[i]<b[i]:
    l+= (b[i]-a[i]+1)//2
    
if l>m:
  print("No")
else:
  print("Yes")