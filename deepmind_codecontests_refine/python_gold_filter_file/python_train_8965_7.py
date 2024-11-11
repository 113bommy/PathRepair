def distPoint(aa):
    l1, r1, l2, r2 = aa[0], aa[1], aa[2], aa[3]
    if l1 == l2:
        return [l1, r2]
    elif r1 == r2:
        return [l1, r2]
    else:
        return [l1, l2]

tc = int(input())
for i in range(tc):
    nn = list(map(int, input().split()))
    print(*distPoint(nn))