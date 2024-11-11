from math import ceil

n,m,d = map(int,input().split())
c = list(map(int,input().split()))
total_gap = n-sum(c)
dist_gap = total_gap/(m+1)
#print(total_gap)
#print(dist_gap)
if ceil(dist_gap)<=d:
    print('YES')
    a,b = ceil(dist_gap),ceil(dist_gap)-1 #possible gaps
    no_a = (total_gap - ((m+1)*b))//(a-b) #no of a gaps
    no_b = m+1-no_a
    res = []
    ci = 0
    while ci<m:
        if no_a:
            for i in range(a):
                res.append('0')
            no_a -= 1
        else:
            for i in range(b):
                res.append('0')
            no_b -= 1
        for i in range(c[ci]):
            res.append(str(ci+1))
        ci += 1
    if no_a:
        for i in range(a):
            res.append('0')
        no_a -= 1
    else:
        for i in range(b):
            res.append('0')
        no_b -= 1
    print(' '.join(res))
else:
    print('NO')
