def solve(n, a, b, c):
    r = n % 4
    if r == 0:
        return 0
    elif r == 3: # nado 1
        return min(a, b + c, 3 * c)
    elif r == 2:
        return min(2 * a, b, 2 * c, a + 2 * c)
    # r == 1
    return min(3 * a, 2 * a + b, c, b + 2 * c)


n, a, b, c = map(int, input().split())
print(solve(n, a, b, c))


# 1, 2+3, 3+3+3
# 1+1, 2, 3+3, 1+3*3
# 1+1+1, 1+2, 3, 2+3*3

# print(solve(1, 1, 3, 4))
# print(solve(6, 2, 1, 1))
# print(solve(4, 4, 4, 4))
# print(solve(999999999, 1000000000, 1000000000, 1000000000))
