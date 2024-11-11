k = int(input())
a, b = map(int, input().split(" "))
if b%k >= b-a:
  print("OK")
else:
  print("NG")