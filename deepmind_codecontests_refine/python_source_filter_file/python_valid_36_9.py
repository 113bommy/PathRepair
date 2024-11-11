def solve(n, i):
    if n <= 6:
        res = ''
        for j in range(n):
            res += chr(i + j + ord('a'))
        return res
    a = chr(i + ord('a'))
    b = chr(i + 1 + ord('a'))
    if n % 3 == 0:
        c = a + a + b
        d = b + b + a
        s = solve((n - 6) // 3, i + 2)
        return ''.join([s, c, s, d, s])
    elif n % 3 == 1:
        c = a + a + a + b + b
        d = b + b + b + a + b
        if n > 10:
            s = solve((n - 10) // 3, i + 2)
            return ''.join([s, c, s, d, s])
        else:
            s = solve(n - 1, i + 1)
            return ''.join([s, a])
    else:
        s = solve((n - 2) // 3, i + 2)
        return ''.join([s, a, s, b, s])


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(solve(n, 0))


if __name__ == "__main__":
    main()
