def starNumber(n):
    star = [0] * n
    star[0] = 1
    for i in range(1, n):
        star[i] = star[i - 1] + 6 * (i + 1)
    return star[n - 1]
n = int(input())
print(starNumber(n))
