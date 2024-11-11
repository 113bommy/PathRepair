"""
a - candles
  if (n // m) == m:
        return 0

    elif  (n // m) < m:
        return 1

    else:

"""


def ans(n):
    if n < 1:
        return n
    else:
        return n + ans(n/m)

n, m = map(int, input().split())
print(ans(n))



