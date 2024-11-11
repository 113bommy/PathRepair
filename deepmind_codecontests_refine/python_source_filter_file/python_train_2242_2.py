def solve():
  n = int(input())
  s = input()
  a = list(map(int, input().split()))
  jumps = set()
  pos = 0
  for _ in range(n):
    if s[pos] == '<':
      next = pos - a[pos]
    else:
      next = pos + a[pos]
    if next not in range(0, n):
      print('FINITE')
      return
    elif next not in jumps:
      jumps.add(next)
    else:
      print('INFINITE')
      return
    pos = next
      
solve()