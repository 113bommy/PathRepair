def f(n, k, t):
    le, rg = 0, 10 ** 8
    while rg - le > 1:
        mid = (le + rg) // 2

        persons = (k * mid) // t
        if persons >= n:
            rg = mid
        else:
            le = mid
    return rg

n, k = map(int, input().split())

print(f(n, k, 2) + f(n, k, 5) + f(n, k, 8))
