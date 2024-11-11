import bisect
N,M,V,P=map(int,input().split())
A=list(map(int,input().split()))
A.sort()

def is_ok(ind):
  bigs = bisect.bisect_right(A,A[ind]+M)
  if N-bigs >= P:
    return False
  votes = M*(V-1)
  j = 0
  for i in range(N-1,-1,-1):
    if i==ind:
      continue
    if j < P-1:
      votes = max(votes-M,0)
    else:
      cur = min(A[ind]+M,A[i]+M,A[i]+votes)
      votes -= max(0,cur-A[i])
    j += 1
  if votes == 0:
    return True
  else:
    return False

lo = 0
hi = N
mid = (lo+hi)//2
while lo < hi:
  mid = (lo+hi)//2
  if is_ok(mid):
    hi = mid
  else:
    lo = mid+1
print(N-hi)