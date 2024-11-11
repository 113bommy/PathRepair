def solve(n):
    if n == 1:
        return 10, 9

    if n == 2:
        return 4, 2

    if n % 2 == 0: return n + 2, 2
    else: return 3*n, 2*n
        

def main():
    n = int(input())
    print(*solve(n))


main()
