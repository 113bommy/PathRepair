X = int(input())

for i in range(50000):
  if int(i*1.05) == X:
    print(i)
    break
else:
  print(':(')