def solve(n):
    if n == 1:
        return -1
    return '2'*(n-1) + '9'


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(solve(n))


main()
