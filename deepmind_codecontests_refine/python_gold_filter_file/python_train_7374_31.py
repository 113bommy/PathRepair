n = int(input())
c = 0
for i in range(n):
  l,r = map(int, input().split())
  c += r-l+1
print(c)