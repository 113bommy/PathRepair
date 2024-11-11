n=int(input())
for i in range(n):
    a, b, c = map(int, input().split())
    r = max(a, b) - min(a, b)
    d = r + c
    ne = r - 1
    z = min(a, b) - ne
    if (z <= 1 and c<=2*r):
        if d <= (2 * r):
            print(d)
        else:
            d = d - (2 * r)
            print(d)
    else:
        print("-1")