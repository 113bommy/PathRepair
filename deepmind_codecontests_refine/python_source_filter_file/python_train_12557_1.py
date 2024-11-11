n=input()
D = sum([int(d) for d in n])
N = int(n)
a = []
for d in range(1,101):
  if (d>=N): continue
  num = N - d
  digits = 0
  for x in str(num): digits += int(x)
  # print(num,d,digits)
  if digits == d:
    a.append(num)
 
 
print(len(a))
for x in a:
  print(x)