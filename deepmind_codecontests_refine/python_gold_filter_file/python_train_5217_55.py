def solve(n):
    if n <= 10: return 0
    r = n - 10
    if r <= 9 or r == 11: return 4
    elif r == 10: return 15
    else: return 0


def main():
    n = int(input())
    print(solve(n))


main()
