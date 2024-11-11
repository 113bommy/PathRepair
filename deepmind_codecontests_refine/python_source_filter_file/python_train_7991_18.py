import sys
readline = sys.stdin.readline
 
N, K = map(int, readline.split())
A = list(map(int, readline().split()))
 
l = 0, r = 10**10
 
def test(m):
  return sum((a + m - 1) // m for a in A) <= K

while l + 1 < r:
  m = (l + r) // 2
  if test(m):
  	r = m
  else:
    l = m
print(r)