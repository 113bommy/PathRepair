n = int(input())
h = 0
cur = 1
ind = 1
while n > 0 and cur <= n:
  n -= cur
  ind += 1
  cur += ind
  h += 1
print(ind)
