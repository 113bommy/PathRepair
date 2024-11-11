N,K = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
M = max(A)
m = 1
mid = (M+1)//2
while m<M:
  n = 0
  for a in A:
    n += -(-a//mid)-1
    if n > K:
      m = mid+1
      break
  else:
    M = mid
  mid = (M+m)//2
print(mid)