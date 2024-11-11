def solve(n):
    if n == 1:
        return -1
    return int('9'*(n-1) + '8')


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(solve(n))


main()
