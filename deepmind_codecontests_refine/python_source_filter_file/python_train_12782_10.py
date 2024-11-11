import collections
N = int(input())
A = list(map(int, input().split()))

c = collections.Counter(A)
ans = 0
for i in range(N):
  ans+=c[i]*(c[i]-1)//2

for i in range(N):
  print(ans-(c[A[i]]-1))