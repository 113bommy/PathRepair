n, k = map(int, input().split())
x = 1
while n >= k*(k**x):
  x += 1
print(x+1)