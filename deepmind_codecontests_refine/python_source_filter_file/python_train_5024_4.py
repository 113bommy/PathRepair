def run(n, a):
    for i in range(30, -1, -1):
        count = 0
        for j in range(n):
            count += (a[j] >> i) & 1
        if count == 1:
            return 'WIN'
        elif count % 2 == 1 and n % 2 == 1:
            return 'LOSE'
        elif count % 2 == 1:
            return 'WIN'
    return 'DRAW'


def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))

        ans = run(n, a)
        print(ans)


if __name__ == '__main__':
    main()
