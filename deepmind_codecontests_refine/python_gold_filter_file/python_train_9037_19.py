def solve():
  N = int(input())
  A = [int(input()) for _ in range(N)]
  if N==1:
    if A[0]==0:
      return 0
    return -1
  if A[0]>0 or A[1]>1:
    return -1
  ans = N - A.count(0)
  for i in range(1,N-1):
    if A[i]+1<A[i+1]:
      return -1
    if A[i]>=A[i+1] and A[i+1]>0:
      ans += A[i+1]-1
  return ans
print(solve())