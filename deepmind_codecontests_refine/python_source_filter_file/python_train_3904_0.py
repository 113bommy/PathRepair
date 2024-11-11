n, m, k = [int(x) for x in input().split()]
canwin = False
for i in range(k):
  x, y = [int(x) for x in input().split()]
  canwin |= x <= 8 or n - x <= 7
  canwin |= y <= 8 or m - y <= 7
print("YES" if canwin else "NO")
