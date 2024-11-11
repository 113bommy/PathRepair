S = int(input())
v = int(1e9)
x = (v - S%v)%v
y = (S + x) // v
print(0, 0, v, 1, x, y)
