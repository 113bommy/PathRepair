x = int(input())
y = input()

a = 0
b = 0
c = 0

z = []

while x > 0:
    a += 1
    x -= a

for i in range(a):
    z.append(c)
    b += 1
    c += b

for i in z:
    print(y[i], end = " ")
