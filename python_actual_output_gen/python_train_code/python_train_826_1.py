a, b = map(int, input().split())
c= [b]
while b != a:
    if b % 10 == 1:
        b //= 10
    elif b % 2 == 0 and b > 0:
        b //= 2
    else:
        break
    c.append(b)
if (a == b):
    c.reverse()
    print('YES')
    print(len(c))
    for i in c:
        print(i, end = ' ')
else:
    print('N0')