def ints():
  return [int(x) for x in input().split(' ')]

def find_index(ranges, x, i, j):
  if i == j:
    return i
  if i == j - 1:
    return j if ranges[j][0] <= x else i
  m = (i + j) // 2
  a, b = ranges[m]
  if x < a:
    return find_index(ranges, x, i, m - 1)
  if x > b:
    return find_index(ranges, x, m + 1, j)
  return m

def remove_item(ranges, x):
  i = find_index(ranges, x, 0, len(ranges) - 1)
  a, b = ranges[i]
  if a == b:
    ranges.pop(i)
    return ranges
  if x == a:
    ranges[i][0] += 1
    return ranges
  if x == b:
    ranges[i][1] -= 1
    return ranges
  return ranges[0:i] + [[a, x - 1], [x + 1, b]] + ranges[i + 1:]

for _ in range(int(input())):
  n = int(input())
  q = ints()
  up = set([i + 1 for i in range(n)])
  down = [[1, n]]
  last = None
  for i in range(n):
    if q[i] == last:
      q[i] = 0
    else:
      up.remove(q[i])
      down = remove_item(down, q[i])
      last = q[i]

  up = list(up)
  up.sort()
  p = q[:]
  j = 0
  last = q[0]
  for i in range(n):
    if p[i] == 0:
      p[i] = up[j]
      j += 1
      k = find_index(down, last, 0, len(down) - 1)
      a, b = down[k]
      q[i] = b
      if a == b:
        down.pop(k)
      else:
        down[k][1] -= 1
    else:
      last = q[i]
  
  print(' '.join([str(x) for x in p]))
  print(' '.join([str(x) for x in q]))