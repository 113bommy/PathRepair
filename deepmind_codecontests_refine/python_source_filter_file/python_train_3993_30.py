x = input()
z = x
n = int(x.split()[0])
m = int(x.split()[1])
a = int(x.split()[2])
x = n / a
if not (x == int(x)):
    x = int(x) + 1
y = m / a
if not (y == int(y)):
    y = int(y) + 1


print(x * y)
