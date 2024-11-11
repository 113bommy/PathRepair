n = int(input())
a = sorted([int(x) for x in input().split()])
if n == 2:
    print(0)
else:
    if a[-2] - a[0] <  a[-1] - a[0]:
        print(a[-2] - a[0])
    else:
        print(a[-1] - a[0])
