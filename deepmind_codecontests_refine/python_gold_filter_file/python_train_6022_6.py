import bisect
N = int(input())
A = []
for _ in range(3):
  a = list(map(int, input().split()))
  a.sort()
  A.append(a)
  
ans = 0
for b in A[1]:
  a = bisect.bisect_left(A[0], b)
  c = bisect.bisect_right(A[2], b)
  ans += a * (N-c)
print(ans)  