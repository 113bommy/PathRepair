n = int(input())
a = [int(x) for x in input().split(' ')]
a.sort()
a = a[::-1]
if sum(a) < n:
    print(0)
else:
    s = 0
    while s < n:
        s += a.pop(0)
    print(12 - len(a))
