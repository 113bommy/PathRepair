n=int(input())
a=[i*40000 for i in range(n)]
b=[40000**2-i for i in a]
p=list(map(int,input().split()))
for i in range(n):
  a[p[i]-1]+=i
  b[p[i]-1]+=i
print(*a)
print(*b)
