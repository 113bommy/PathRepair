n=int(input())
a=list(map(int,input().split()))
c=[0]*(n-1)
for i in range(n-1):
  c[i]=abs(sum(a[:i])-sum(a[i:]))
print(min(c))