for _ in range(int(input())):
    n = int(input())
    a = input().split(' ')
    if n == 1:
        print(0)
        continue
    for i in range(n):
        a[i] = int(a[i])
    s = []
    for i in range(1,n):
        s.append(a[i]-a[i-1])
    values = []
    i = 0
    while i < n - 1 and s[i] == 0:
        i = i + 1
    if i == n - 1:
        print(0)
        continue
    values.append(i)
    if s[i] > 0:
        trend = 1
    elif s[i] < 0:
        trend = -1
    for j in range(i+1,n-1):
        if s[j] < 0 and trend == 1:
            values.append(j)
            trend = -1
        elif s[j] > 0 and trend == -1:
            values.append(j)
            trend = 1
    if n-1 not in values:
        values.append(n-1)
    print(len(values))
    for i in values:
        print(a[i],end = ' ')
    print()