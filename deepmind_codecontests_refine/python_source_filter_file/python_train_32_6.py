import math
n, x, y = map(int, input().split())

porc = (y*n)/100
# print(porc)
faltam = math.ceil(porc - x)
print(faltam)
