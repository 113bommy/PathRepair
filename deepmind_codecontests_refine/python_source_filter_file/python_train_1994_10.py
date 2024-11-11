n = int(input())
a = sorted(list(set(map(int, input().split()))))

min_a = min(a)
max_a = max(a)

if len(a) == 1:
    print(0)
elif len(a) == 2:
    if (a[1] - a[0]) % 2:
        print((a[1] - a[0]) // 2)
    else:
        print(a[1] - a[0])
elif len(a) == 3:
    if int(a[1]) - int(a[0]) == int(a[2]) - int(a[1]):
        print(a[2] - a[1])
    else:
        print(-1)
else:
    print(-1)
