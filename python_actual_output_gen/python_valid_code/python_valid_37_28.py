n = int(input())

for i in range(n):
  if int(i*1.08) == n:
    print(i)
    exit()
else:
  print(':(')

