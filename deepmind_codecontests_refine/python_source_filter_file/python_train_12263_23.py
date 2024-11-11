n = int(input())
f = 0
for i in range(n):
  if int(i*1.08) == n:
    print(i)
    exit()
print(':(')