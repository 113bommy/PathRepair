def gazirovka(lst):
    return min(min(lst[1] * lst[2] // lst[6], lst[5] // lst[7]), lst[3] * lst[4]) // lst[0]


n, k, l, c, d, p, nl, np = [int(i) for i in input().split()]
print(gazirovka(list((n, k, l, c, d, p, nl, np))))
