a, b, c = list(map(int, input().split()))
k = int(input())

while a > b:
  b *= 2
  k -=1
while b > c:
  c *=2
  k -=1
if k < 0:
  print("No")
else:
  print("Yes")