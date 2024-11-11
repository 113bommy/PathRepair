def puzzle(allPoint):  # col, row!!!!!
    n = len(allPoint)
    if n % 2 == 1:
        return "NO"
    allPoint.sort()
    while allPoint:
        l1, r1 = allPoint.pop()
        l2, r2 = allPoint.pop()
        if l1 == l2:
            continue
        if (l1 + r1) % 2 != (l2 + r2) % 2:
            return "NO"
        if allPoint and l2 == allPoint[-1][0]:
            return "NO"
    return "YES"

t = int(input())
for qwq in range(t):
    input()
    ll = list(map(int, input().split()))
    allPoint = []
    for i in range(ll[1]):
        cin = list(map(int, input().split()))
        allPoint.append((cin[1], cin[0]))
    print(puzzle(allPoint))
