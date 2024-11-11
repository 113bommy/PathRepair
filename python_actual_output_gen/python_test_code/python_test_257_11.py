def check(number):
    if number * m <= n:
        if number * m - k >= L:
            return True
    return False


def bin_search():
    left = 0
    right = n // m
    while left < right - 1:
        middle = (left + right) // 2
        if check(middle):
            left = middle
        else:
            right = middle
    return right


n, m, k, L = map(int, input().split())
a = bin_search()
if not check(a):
    print(-1)
else:
    print(a)
