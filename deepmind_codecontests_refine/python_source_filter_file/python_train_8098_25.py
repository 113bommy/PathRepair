n = int(input())
m = 0
for i in range(n):
  if len(str(i))%2 != 0:
    m += 1
print(m)