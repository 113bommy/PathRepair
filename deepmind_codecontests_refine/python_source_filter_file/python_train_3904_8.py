n, m, k = [int(x) for x in input().split()]
canwin = False
for i in range(k):
  x, y = [int(x) for x in input().split()]
  canwin |= x <= 3 or n - x <= 2
  canwin |= y <= 3 or m - y <= 2
print("YES" if canwin else "NO")
