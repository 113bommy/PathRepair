N = int(input())
x = 0
for i in range(N):
  l, r = map(int, input().split())
  x += r - l + 1
print(x)