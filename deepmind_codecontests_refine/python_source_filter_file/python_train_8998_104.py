n = int(input())
ans = n%4
a2 = (1, 2, 4, 3)
a3 = (1, 3, 4, 3)
a4 = (1, 4, 1, 4)

print((1+a2[ans] +a3[ans] + a4[ans])%5)