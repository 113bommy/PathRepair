n, a, b = input().split()
n = int(n)
a = int(a)
b = int(b)
t = 0
a1 = 0
b1 = 0
x = [int(x) for x in input().split()]
k = 0
for i in x:
    if i is 1:
        if a < 1 and b < 1:
            if t >= 1:
                t -= 1
            elif t < 1:
                a1 += 1
        if a < 1:
            b -= 1
            t += 1
        elif a >= 1:
            a -= 1
    elif i is 2:
        if b >= 1:
            b -= 1
        elif b < 1:
            b1 += 2

print(a1+b1)
