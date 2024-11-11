t = int(input())
for _ in range(t):
    s = input()
    R, S, P = 0, 0, 0
    for i in s:
        if i == 'R':
            R += 1
        elif i == 'S':
            S += 1
        elif i == 'P':
            R += 1
    mV = max(R, S, P)
    if R == mV:
        print('P' * len(s))
    elif S == mV:
        print('R' * len(s))
    else:
        print('S' * len(s))