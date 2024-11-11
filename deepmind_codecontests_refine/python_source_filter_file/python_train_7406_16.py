_ = input()
a = list(map(int, input().split()))
a.append(a[0])

max = 0
cur = 0
for ai in a:
    if ai == 1:
        cur += 1
        if cur > max:
            max = cur
    else:
        cur = 0

print(max)
