def picture(n, a, b, c, d):
    result = 0
    for j in range(1, n + 1):
        y = j + b - c
        z = j + a - d
        w = j + y - d
        if 1 <= y <= n and 1 <= z <= n and 1 <= w <= n:
            result += 1
    result *= n
    return result


N, A, B, C, D = [int(i) for i in input().split()]
print(picture(N, A, B, C, D))
