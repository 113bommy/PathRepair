t = int(input())

for i in range(t):
    a, b, c = map(int, input().split())

    half = abs(a-b)
    total = half * 2

    if a > total or b > total or c > total:
        print(-1)
        continue

    if c > half:
        test = c - half
    else:
        test = c + half

    if test in range(1, total+1):
        print(test)
    else:
        print(-1)