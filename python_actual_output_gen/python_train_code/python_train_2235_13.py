x = input()
z = []
a = 1
for y in range(int(x)+1):
    z.append(str(a))
    a += 1
print(z)
b = ''.join(z)
print(b[int(x)-1])
