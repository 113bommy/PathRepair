n = int(input())
a = [int(input()) for _ in range(n)]

a.sort()

suma = sum(a)

if suma % 10 != 0:
  print(suma)
else:
  for i in a:
    if i % 10 != 0:
      print(suma - i)
      exit()
print(0)
