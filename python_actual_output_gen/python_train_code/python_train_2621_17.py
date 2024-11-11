n = int(input())

curh = 0
total = 0

for i in range(n):
    a = int(input())
    if curh == 0:
        total += a + 1
        curh = a
    elif curh <= a:
        total += a - curh + 1 + 1
        curh = a
    else:
        total += ((curh - a) * 2) + 1
        curh = a

    """print(i)
    print("curh : " + str(curh))
    print("total : " + str(total))
    print()"""

print(total)
