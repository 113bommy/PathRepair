t = int(input())
for i in range(t):
    re = 0
    a, b, c, d = map(int, input().split())
    re += b
    if re >= a:
        print(re)
    elif d >= c:
        print(-1)
    else:
        re1 = a - re
        if re1 % d == 0:
            re += (c) * (re1 // (c - d))
        else:
            re += (c) * (re1 // (c - d) + 1)
        print(re)
