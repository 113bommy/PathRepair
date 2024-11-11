n = int(input())
a = list(map(int, input().split()))
r = 0
for j in a:
  if j % 2 == 0:
    r += 1
print(r)
