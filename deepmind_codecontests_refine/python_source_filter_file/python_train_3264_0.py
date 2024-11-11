a = input()
a = a.split(' ')
a[0] = int(a[0])
a[1] = int(a[1])

b = input()
b = b.split(' ')
y = list()
for i in range(len(b)):
    b[i] = int(b[i])
    y.append(int(b[i]))
max , min = 0,0

if a[1] == 1:
    while a[0] != 0:
        max += b[0]
        b[0] -= 1
        a[0] -= 1
    print(max, max)
    exit()

if a[0] == sum(b):
    b.sort(reverse=0)
    i = 0
    while a[0] != 0 :
        if i < len(b)-1:
            while b[i] <= b[i+1] and b[i] != 0:
                min += b[i]
                b[i] -= 1
                a[0] -= 1

        elif i == len(b)-1:
            while b[i] > 0 :
                min += b[i]
                b[i] -= 1
                a[0] -= 1
                if a[0] == 0:
                    print(min, min)
                    exit()
        i += 1

x = a[0]
i = 0

y.sort()
while x != 0 :
    if i < len(y)-1:
        while y[i] <= y[i+1] and y[i] != 0 and x != 0:
            min += y[i]
            y[i] -= 1
            x -= 1

    i += 1
    if i == len(y)-1:
        while y[i] > 0 and x != 0:
            min += y[i]
            y[i] -= 1
            x -= 1
            if x == 0:
                break

while a[0] != 0:
    b.sort(reverse=1)
    max += b[i]
    b[0] -= 1
    a[0] -= 1
print(max, min)
