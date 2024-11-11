n = int(input())
x = 0
for i in range(n):
  a, b = map(int, input().split())
  x += b-a +1
print(x)