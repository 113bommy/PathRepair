n=int(input())
a=list(map(int, input().split()))
b=sorted(a)
c=0
for i in range(n):
 x=a.index(b[i])
 j=0
 while x>i:
  j+=1
  y=a.index(b[x])
  c+=a[y]
  a[x],a[y]=a[y],a[x]
  x=y
 c+=min(b[i]*j,b[i]*2+b[0]*(j+2))
print(c)
