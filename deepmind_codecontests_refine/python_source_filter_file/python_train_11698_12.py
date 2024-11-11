#245A System Administrator

n = int(input())

x_a = 0
y_a = 0

x_b = 0
y_b = 0

for i in range(n):
    packages = input()
    packages = [int(x) for x in packages.split()]
    t = packages[0]
    x = packages[1]
    y = packages[2]

    if t == 1:
        x_a += x 
        y_a += y 
    else:
        x_b += x
        y_b += y

first, second = 'LIVE', 'LIVE'

if x_a <y_a:
    fisrt = 'DEAD'

if x_b < y_b:
    second = 'DEAD'

print(first)
print(second)
    