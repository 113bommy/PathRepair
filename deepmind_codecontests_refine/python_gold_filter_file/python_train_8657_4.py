import sys

n = int(sys.stdin.readline().strip())
b = list(map(int, sys.stdin.readline().strip().split()))
c = sorted(b)
if n == 2 or n == 3:
    print(1)
else:
    d = c[1] - c[0]
    v = False
    x = c[-1]
    ans = True
    for i in range (0, n-1):
        if v == False and c[i] != c[0] + i * d:
            v = True
            x = c[i]
        if v == True and c[i+1] != c[0] + i * d:
            ans = False
    if ans == True:
        print(b.index(x) + 1)
    else:
        d = c[-1] - c[-2]
        v = False
        x = c[0]
        ans = True
        for i in range (0, n-1):
            if v == False and c[n-1-i] != c[n-1] - i * d:
                v = True
                x = c[n-1-i]
            if v == True and c[n-2-i] != c[n-1] - i * d:
                ans = False
        if ans == True:
            print(b.index(x) + 1)
        else:
            print(-1)