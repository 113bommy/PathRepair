n=int(input())
a=[int(i) for i in input().split()]
c=0
for i in range(n):
  c+=(a[i]==i+1)*1
print(['YES','NO'][c<n-1])