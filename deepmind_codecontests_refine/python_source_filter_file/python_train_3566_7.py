import sys

t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    li = []
    ans = 0
    for i in range(n):
        if i % 2 == 0:
            ans += arr[i]
    for i in range(1, n, 2):
        li.append((i - 1, arr[i] - arr[i - 1]))
    temp = 0
    if len(li) != 0:
        m = -10 ** 18
        min_so_far = 0
        a = 0
        b = 0
        c = 0
        p = 0
        for i in range(len(li)):
            p += li[i][1]
            x = p - min_so_far
            if x > m:
                m = x
                b = li[i][0] + 1
                c = a
            if p < min_so_far:
                min_so_far = p
                a = li[i][0]
        if m > 0:
            for i in range(c, b + 1):
                if i % 2 != 0:
                    temp += arr[i]
            for i in range(c):
                if i % 2 == 0:
                    temp += arr[i]
            for i in range(b + 1, n):
                if i % 2 == 0:
                    temp += arr[i]
    ans = max(ans, temp)
    li = []
    for i in range(2, n, 2):
        li.append((i - 1, arr[i - 1] - arr[i]))
    temp = 0
    if len(li) != 0:
        m = -10 ** 18
        min_so_far = 0
        a = 1
        c = 0
        b = 0
        p = 0
        for i in range(len(li)):
            p += li[i][1]
            x = p - min_so_far
            if x > m:
                m = x
                b = li[i][0] + 1
                c = a
            if p < min_so_far:
                min_so_far = p
                a = li[i][0] + 2
        if m > 0:
            for i in range(c, b + 1):
                if i % 2 != 0:
                    temp += arr[i]
            for i in range(c):
                if i % 2 == 0:
                    temp += arr[i]
            for i in range(b + 1, n):
                if i % 2 == 0:
                    temp += arr[i]
    ans = max(ans, temp)
    print(ans)
