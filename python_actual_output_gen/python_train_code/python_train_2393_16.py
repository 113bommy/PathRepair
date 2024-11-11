[n, m] = list(map(int, input().rstrip().split()))
dontStop = True
count = 0

for i in range(m):
    if(n>=m):
        if (m - 1 >= 0 and n - 2 >= 0):
            m -= 1
            n -= 2
            count += 1
        if (m - 2 >= 0 and n - 1 >= 0):
            m -= 2
            n -= 1
            count += 1
    else:
        if (m - 2 >= 0 and n - 1 >= 0):
            m -= 2
            n -= 1
            count += 1
        elif (m - 1 >= 0 and n - 2 >= 0):
            m -= 1
            n -= 2
            count += 1
print(count)