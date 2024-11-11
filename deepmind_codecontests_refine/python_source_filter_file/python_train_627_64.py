a,b,c = map(int, input().split())
n = 0
for i in range(a, b+1):
  if i % c == 0:
    n += 1
print(n)
