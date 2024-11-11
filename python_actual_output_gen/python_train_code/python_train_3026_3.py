x = int(input())
y = x ** 2
i = 0
j = 0
a = 1
number = []

while i <= x:
    while j < (x/2):
        number.append(a)
        number.append(y)
        a += 1
        y -= 1
        j += 1
        if j >= (x/2):
            j = 0
            print(' '.join(map(str, number)))
            number = []
            break
    i += 1
