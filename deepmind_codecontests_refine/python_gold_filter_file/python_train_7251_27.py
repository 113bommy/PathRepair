n, s = list(map(int, input().split()))
h, m = list(map(int, input().split()))
perTime = h*60 + m
can = True
if perTime > s:
    print('{} {}'.format(0, 0))
else:
    for _ in range(n-1):
        h, m = list(map(int, input().split()))
        if (h*60 + m) - perTime >= (2*s + 2) and can:
            Time = int(perTime + s + 1)
            print('{} {}'.format(Time//60, Time % 60))
            can = False
            break
        perTime = h*60 + m
    if can:
        Time = int(perTime + s + 1)
        print('{} {}'.format(Time // 60, Time % 60))
