from bisect import bisect_left as bl
from itertools import accumulate
INF = 10 ** 20

def get_score(acc, head, end):
  sec_head = acc[head - 1]
  sec_end = acc[end]
  sec_sum = sec_end - sec_head
  cut = bl(acc, sec_head + sec_sum // 2) - 1
  score = INF
  reta, retb = None, None
  for i in range(cut - 1, cut + 2):
    if head <= i < end: 
      a = acc[i] - sec_head
      b = sec_end - acc[i]
      if score > abs(a - b):
        score = abs(a - b)
        reta, retb = a, b
  return (reta, retb)

n = int(input())
acc = [0]
acc += accumulate(map(int, input().split()))

ans = INF
for i in range(2, n - 1):
  p, q = get_score(acc, 1, i)
  r, s = get_score(acc, i + 1, n)
  if not None in (p, q, r, s):
    ans = min(ans, max(p, q, r, s) - min(p, q, r, s))
print(ans)