n = int(input())
a = [int(i) for i in input().split()]
s = 0
for i in a:
    if i > 0:
        s += i
if s % 2 == 1:
    print(s)
else:
    maxot = -100000000000000
    for i in a:
        if i % 2 == 1 and i < 0 and i >= maxot:
            maxot = i
    minpo = 10000000000000000
    for i in a:
        if i > 0 and i % 2 == 1 and i <= minpo:
            minpo = i
    if (s + maxot) % 2 == 0:
        print(s - minpo)
    elif (s - minpo) % 2 == 0:
        print(s + maxot)
    else:
        max(s + maxot, s - minpo)