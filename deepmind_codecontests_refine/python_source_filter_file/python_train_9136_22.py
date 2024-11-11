from collections import defaultdict
mem = defaultdict(lambda : None)
mem[(0,0,0)] = 0
def dp(a,b,s):
  if mem[(a,b,s)] is not None:
    return mem[(a,b,s)]
  x = a&1
  y = b&1
  xor = s&1
  res = float("inf")
  if x^y != xor:
    mem[(a,b,s)] = res
    return res
  else:
    res = 2*dp(a>>1,b>>1,s>>1)
    if a > 1:
      pants = 2*dp((a-1)>>1,(b+1)>>1,s>>1)+1
      if pants > res:
        res = pants
  mem[(a,b,s)] = res
  return res

n = int(input())
a = list(map(int, input().split()))
s = 0
for i in a[2:]:
  s ^= i
b = a[1]
a = a[0]
ans = dp(a,b,s)
if ans == float("inf"):
  ans = -1
print(ans)
