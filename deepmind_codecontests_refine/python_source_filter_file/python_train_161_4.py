def count(x):
    if x == 0:
        return 1
    ans = 0
    holes = [1, 0, 0, 0, 0, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0]
    while x:
        ans += holes[x % 16]
        x //= 16
    return ans
print(count(int(input())))
