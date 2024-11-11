n,k=list(map(int, input().split()))

minv = 1
maxv = 1

if (k == 0 and k == n):
  minv=0

maxv=min(k*2, n - k)
print(minv, maxv)
