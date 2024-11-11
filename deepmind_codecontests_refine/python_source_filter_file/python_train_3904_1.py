n, m, k = [int(x) for x in input().split()]
canwin = False
for i in range(k):
  x, y = [int(x) for x in input().split()]
  canwin |= x <= 9 or n - x <= 8
  canwin |= y <= 9 or m - y <= 8
print("YES" if canwin else "NO")
