n = int(input())
r = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

w = sum(1 for i in range(n) if r[i] > b[i])
l = sum(1 for i in range(n) if r[i] < b[i])

if w == 0:
    print(-1)
else:
    # smallest k such that w*k > l, i.e. k > l/w
    if l % w == 0:
        print((l // w) + 1)
    else:
        print(l//w)
