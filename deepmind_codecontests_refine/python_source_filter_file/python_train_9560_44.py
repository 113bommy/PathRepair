a, b = map(int, input().split())
r = 0
for i in range(a, b):
  if str(i) == str(i)[::-1]:
    r += 1
print(r)