N = int(input())
p = 0
for i in range(N):
  a,b = map(int, input().split())
  p += b - a + 1
print(p)