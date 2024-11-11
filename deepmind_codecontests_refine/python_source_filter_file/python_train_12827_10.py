def solve(n):
    s = n
    m = 1
    while s > 0:
        m += (s-1)/s
        s -= 1
    return m


def main():
    n = int(input())
    print(solve(n))


main()
