def clc(a,b,c):
    if (min(a, c) == c and a != c) or (min(b,c) == b or b == c):
        return 0
    else:
        return 1

h,m,s,t1,t2 = map(int, input().split())

h = (5 *h)%60
t1 = (5 *t1)%60
t2 = (5 *t2)%60

t1,t2 = min(t1,t2), max(t1,t2)

if clc(t1,t2, h) == clc(t1,t2, m) and clc(t1,t1, m) == clc(t1,t2, s):
    print('YES')
else:
    print('NO')
