n = input()

if int(n) % 10 == 0:
  print(10)
else:
  res = 0
  for i in n:
  	res += int(i)
  print(res)
