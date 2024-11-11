n = int(input())
t = list(map(int, input().split()))
if n < 3 or (n == 3 and t[0] == t[2]) or all(i == t[0] for i in t): print(-1)
else:
    i = 1
    while t[i] == t[i - 1]: i += 1
    if i > 1: print('2 ' + str(i + 1))
    elif t[0] < t[1]:
        if t[1] <= t[2]: print('1 2')
        elif t[0] == t[2]:
            if t[0] == t[3]: print('2 3')
            else: print('2 4')
        else: print('1 3')
    else:
        if t[1] >= t[2]: print('1 2')
        elif t[0] == t[2]:
            if t[0] == t[3]: print('2 3')
            else: print('2 4')
        else: print('1 3')