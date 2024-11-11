import math

class Solution():
  def __init__(self):
    test = int(input())
    for i in range(0, test):
      n, k = list(map(int, input().split()))
      self.solve(n, k)
  
  def solve(self, n, k):
    res = n
    i = 1
    while i * i <= n:
      if n % i == 0:
        if i <= k:
          res = min(res, int(n / i))
        if n / i <= k:
          res = min(res, i)
      i += 1
    print(res)
  
Solution()