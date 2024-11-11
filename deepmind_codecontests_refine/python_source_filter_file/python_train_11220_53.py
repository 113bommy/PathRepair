n = int(input())
a = list(map(int, input().split()))
s = 1
for i in a:
  s *= i
  if s => 10 ** 8:
    ans = -1
    break
if 0 in n:
  ans = 0
print(ans)
 