t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    count = 0
    for x in range(1, 1000000):
        a_fits = (a-x)//x
        if a_fits < x or b < x:
            continue
        count += min(a_fits, b) - x
    print(count)
