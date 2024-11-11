T = int(input())
for testcase in range(1,T+1):
    a,b = list(map(int, input().split()))
    if (a+b)%2 == 0:
        half = (a+b)//2
        mi = min(a,b)
        mib = half-mi
        mab = half+mi
        num = (mab-mib)//2+1
        print(num)
        res = []
        i = mib
        while i <= mab:
            res.append(i)
            i += 2
        print(*res)
    else:
        mi = min(a,b)
        ma = max(a,b)
        less = (a+b)//2
        more = (a+b)-less
        mib = less-mi
        mab = more+mi
        num = mab-mib+1
        print(num)
        res = []
        i = mib
        while i <= mab:
            res.append(i)
            i += 1
        print(*res)


