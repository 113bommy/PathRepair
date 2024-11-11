def solve():
    k = [int(x) for x in input().split(' ')]
    k.sort()
    if min(k) == 1:
        return "YES"
    elif k.count(2) == 2:
        return "YES"
    elif k.count(3) == 3:
        return "YES"
    elif k == [2, 4, 4]:
        return "YES"
    return "NO"


print(solve())