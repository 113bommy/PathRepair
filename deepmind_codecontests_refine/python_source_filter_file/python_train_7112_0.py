def gift_set(x, y, a, b):
    # This was a very easy binary search one - right limit is 10 ** 9
    if a == b: return min( x // a, y // a)
    if a > b: a, b = b, a
    diff = b - a

    def can_make_gifts(mid):

        minx, miny = x - a * mid, y - a * mid
        can_make_sets = minx // diff + miny // diff >= mid

        return minx > 0 and miny > 0 and can_make_sets

    left, right, res = 0, 10 ** 9, 0
    while left <= right:

        mid = (left + right) // 2
        if can_make_gifts(mid):
            res   = mid
            left  = mid + 1
        else:
            right = mid - 1

    return res
    

R=lambda:map(int,input().split())
test_cases,  = R()
for test_case in range(test_cases):
    x, y, a, b = R()
    print(gift_set(x, y, a, b))
