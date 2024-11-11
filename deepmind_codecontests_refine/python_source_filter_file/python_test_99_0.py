t = int(input())


def solve(x, n):
    if n % 4 == 0:
        return x
    if n % 4 == 2:
        if x % 2 == 0:
            return x + 1
        return x - 1
    if n % 4 == 1:
        if x % 2 == 0:
            return x - n
        return x + n
    if x % 2 == 0:
        return x + n + 1
    return x - n + 1


for _ in range(t):
    x, n = map(int, input().split())

    print(solve(x, n))
