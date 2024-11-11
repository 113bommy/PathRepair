def good_combination(m, a, b, f):
    weight = m+f
    for i in range(len(a)):
        burnt_takeoff = weight / a[i]
        weight -= burnt_takeoff
        burnt_landing = weight / b[i]
        weight -= burnt_landing
        if weight < m:
            return False
    return True

def solve(m, a, b):
    if not good_combination(m, a, b, 1000000001):
        return -1

    l = 1
    r = 1000000000
    while r-l > 10 ** -6:
        mid = (l+r)/2
        if good_combination(m, a, b, mid):
            r = mid
        else:
            l = mid
    return l if good_combination(m, a, b, l) else r

input()
m = int(input().strip())
a = [int(x) for x in input().strip().split()]
b = [int(x) for x in input().strip().split()]
print(solve(m, a, b))