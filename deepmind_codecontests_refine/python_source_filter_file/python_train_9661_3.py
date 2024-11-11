def main():
    import sys
    input = sys.stdin.readline
    N = int(input())
    A = sorted([int(x) for x in input().strip().split()])
    maxi = max(A)
    mini = min(A)
    plus = [a for a in A[1:-1] if a > 0]
    minus = [a for a in A[1:-1] if a < 0]
    print(maxi + sum(plus) - sum(minus) - mini)
    for p in plus:
        print(mini, p)
        mini -= p
    print(maxi, mini)
    maxi -= mini
    for m in minus:
        print(maxi, m)
        maxi -= m

if __name__ == '__main__':
    main()