t = int(input())

for _ in range(t):
    n,l = map(int,input().split())
    a = list(map(int,input().split()))
    one = [(1,0,0),(2,a[0],a[0])]
    speed = 2
    time = a[0]
    onet = [0,a[0]]
    for i in range(1,n):
        time += (a[i] - a[i-1]) / speed
        speed += 1
        one.append((speed,time,a[i]))
        onet.append(time)
    second = [(1,0,0),(2,l-a[-1],l-a[-1])]
    speed = 2
    time = l-a[-1]
    secondt = [0,l-a[-1]]
    for i in reversed(range(n-1)):
        time += (a[i+1] - a[i]) / speed
        speed += 1
        second.append((speed,time,l-a[i]))
        secondt.append(time)

    import bisect
    def f(time):
        i = bisect.bisect_right(onet, time) - 1
        j = bisect.bisect_right(secondt, time) - 1
        res = (one[i][2] + second[j][2] + one[i][0]*(time-onet[i]) + second[j][0]*(time-secondt[j]) >= l)
        return res

    lb, ub = 0, l
    for i in range(100):
        mid = (lb + ub) / 2
        if f(mid):
            ub = mid
        else:
            lb = mid
    print(lb,ub)