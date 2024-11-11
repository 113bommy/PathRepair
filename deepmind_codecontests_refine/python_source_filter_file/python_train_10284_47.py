k = int(input())
a, b = map(int, input().split())
if b//k - a//k >= 1:
  print("OK")
else:
  print("NG")