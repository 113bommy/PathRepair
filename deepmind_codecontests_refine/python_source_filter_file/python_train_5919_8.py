def solve():
  ans = 1
  N = int(input())
  A = list(map(int, input().split()))
  ud = 0
  for i in range(N-1):
    a = A[i+1]-A[i]
    if a*ud<0:
      ans += 1
      ud = 0
    elif a*ud==0:
      ud = a
  return ans
print(solve())