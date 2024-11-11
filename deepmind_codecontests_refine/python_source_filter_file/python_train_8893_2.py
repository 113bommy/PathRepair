m = 1e9 + 7


def add_mod(numb: int, ways: int) -> int:
    numb += ways
    if numb >= m:
        return numb - m
    return numb


n, k, d = map(int, input().split())
a = [[0] * 2 for i in range(n + 1)]
a[0][0] = 1
for i in range(1, n + 1):
    for j in range(1, k + 1):
        if i - j < 0:
            break

        if j < d:
            a[i][0] = add_mod(a[i][0], a[i - j][0])
            a[i][1] = add_mod(a[i][1], a[i - j][1])
        else:
            a[i][1] = add_mod(a[i][1], a[i - j][0])
            a[i][1] = add_mod(a[i][1], a[i - j][1])

print(a[n][1])
