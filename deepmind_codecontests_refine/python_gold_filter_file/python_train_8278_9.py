def is_possible(a, b, k, target):
    for x, y in zip(a, b):
        req = x * target
        avi = y
        if req > avi:
            k = k - (req - avi)
            if k < 0:
                return False
    return True


f = lambda: list(map(int, input().split()))


def search(a, b, k, low=0, high=10 ** 10):
    while low < high-1:
        mid = (low + high) // 2
        r = is_possible(a, b, k, mid)
        # print(low, mid, high, r)
        if r:
            low = mid
        else:
            high = mid - 1
    if is_possible(a,b,k,low+1):
        return low+1
    return low


n, k = f()
a = f()
b = f()
k = search(a,
           b, k)

print(k)
# print(is_possible(a,b,3,5))
