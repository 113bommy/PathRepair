n = int(input())
a = [int(i) for i in input().split()]
x=0
k=sum(a)
m = 3*(10**5)

for i in range(n-1):
  x+=a[i]
  if m>abs(2*x-k):
    m=abs(2*x-k)
print(m)
