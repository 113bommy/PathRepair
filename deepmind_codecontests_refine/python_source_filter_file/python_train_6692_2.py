a = int(input())
for x in range(a):
    f = 0
    b = input()
    d = len(b)
    if d == 1:
        f += 1
    elif d == 2:
        f += 3
    elif d == 3:
        f += 6
    elif d == 4:
        f += 10
    j = b[0]
    k = 10*(int(j)-1)
    f += k
    print(d)