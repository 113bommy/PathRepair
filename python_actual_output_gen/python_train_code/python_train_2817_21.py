n=int(input())
a=[int(i) for i in input().split()]

x=a[0]
y=sum(a[1:])
m=abs(x - y)

i=1

while i < n:
  x+=a[i]
  y-=a[i]
  m = min(abs(x - y),m)
  i+=1
print(m)
