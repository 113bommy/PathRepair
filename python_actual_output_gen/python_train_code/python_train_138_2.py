N, x = map(int, input().split())
tmp = x
A = list(map(int, input().split()))
ans = 0
A.sort()
for a in A:
  if x >= a:
    x -= a
    ans += 1
if x > sum(A):
  ans -= 1
print(ans)
         
