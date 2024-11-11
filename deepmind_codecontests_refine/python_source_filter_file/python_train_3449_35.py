numero=int(input())
a=9
while numero%a != 0:
  a-=1
print(a)
print((str(numero//a) + " ") * a)