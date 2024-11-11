def second_maximum(lst):
    b = list()
    for i in range(len(lst)):
        b.append(tuple([lst[i], i]))
    d = sorted(b, key=lambda x: x[0])
    return d[len(d) - 2][1], d[len(d) - 2][0]


n = int(input())
a = [int(i) for i in input().split()]
print(*second_maximum(a))
