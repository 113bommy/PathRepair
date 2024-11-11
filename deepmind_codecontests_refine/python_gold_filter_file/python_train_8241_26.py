q = int(input())
out = []
for st in range(0, q):
    [n, m] = [int(x) for x in input().split()]
    if(m > n):
        out += [0]
        continue
    iter = m
    sum = 0
    period = []

    while(iter <= n):
        tmp = iter%10
        if(tmp in period):
            break
        period += [tmp]
        iter += m


    N = n//m
    No = N // len(period)
    for i in period:
        sum += No * i
    i = 1
    No *= len(period)
    while(i + No <= N):
        sum += period[i-1]
        i += 1
    out += [sum]



for i in range(0, q):
    print(out[i])