n = int(input())
for i in range(n):
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))
    b.sort()
    b.reverse()
    c1 = 0
    c = min(b)
    for j in range(len(b) - 1):
        d = (a[1] - b[j])
        if d>0:
            e = d / c
            c1 += e

    print(int(c1))