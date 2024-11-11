from math import ceil

t = int(input())
for _ in range(t):
    n = int(input())
    a = []
    b = []
    for i in range(n):
        t_a, t_b = map(int, input().split())
        a.append(t_a)
        b.append(t_b)
    tm = list(map(int, input().split()))
    time = 0
    for i in range(n-1):
        if i==0:
            time += a[i]+tm[i]
        else:
            time += a[i]-b[i-1]+tm[i]
        wait = max(b[i]-time, 0)
        time += max(wait, ceil((b[i]-a[i])/2))
    if n==1:
        time = a[0]+tm[0]
    else:
        time += a[n-1]-b[n-2]+tm[n-1]
    print(time)
