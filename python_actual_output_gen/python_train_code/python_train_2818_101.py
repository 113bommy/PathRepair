x = int(input())
p, q = divmod(x, 11)
print(p*2 if q < 7 else p*2+1)