n = int(input())
a = list(map(int, input().split()))
res = []
if n == 1:
    print(1)
    exit(0)

i = 0
if a[0] < a[1]:

    if i >= n - 2:
        res = [1]
        cur = 2
    else:
        if a[i + 1] < a[i + 2]:
            res = [1]
            cur = 2
        elif a[i + 1] > a[i + 2]:
            res = [1]
            cur = 5
        else:
            res = [1]
            cur = 2

    # res = [1]
    # cur = 2
elif a[0] > a[1]:

    if i >= n - 2:
        res = [5]
        cur = 4
    else:
        if a[i + 1] < a[i + 2]:
            res = [5]
            cur = 1
        elif a[i + 1] > a[i + 2]:
            res = [5]
            cur = 4
        else:
            res = [5]
            cur = 4

    # res = [5]
    # cur = 4
else:
    if i >= n - 2:
        res.append(1)
        cur = 2
    else:
        if a[i + 1] < a[i + 2]:
            res.append(2)
            cur = 1
        elif a[i + 1] > a[i + 2]:
            res.append(4)
            cur = 5
        else:
            res.append(2)
            cur = 3

for i in range(1, n - 1):
    if not (1 <= cur <= 5):
        # print(i, res)
        print(-1)
        exit(0)
    res.append(cur)
    if a[i] > a[i + 1]:

        if i >= n - 2:
            cur -= 1
        else:
            if a[i + 1] < a[i + 2]:
                cur = min(cur - 1, 1)
            elif a[i + 1] > a[i + 2]:
                cur -= 1
            else:
                cur -= 1

        # cur -= 1
    elif a[i] < a[i + 1]:

        if i >= n - 2:
            cur += 1
        else:
            if a[i + 1] < a[i + 2]:
                cur += 1
            elif a[i + 1] > a[i + 2]:
                cur = max(cur + 1, 5)
            else:
                cur += 1

        # cur += 1
    else:
        if i >= n - 2:
            if cur != 3:
                cur = 3
            else:
                cur = 2
        else:
            if a[i + 1] < a[i + 2]:
                if cur == 1:
                    cur = 2
                else:
                    cur = 1
            elif a[i + 1] > a[i + 2]:
                if cur == 5:
                    cur = 4
                else:
                    cur = 5
            else:
                if cur != 3:
                    cur = 3
                else:
                    cur = 2
if not (1 <= cur <= 5):
    # print(i, res)
    print(-1)
    exit(0)
res.append(cur)
print(*res)
