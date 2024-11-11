x = int(input())
p, q = divmod(x-1, 11)
print(p*2+1 if q < 6 else p*2+2)