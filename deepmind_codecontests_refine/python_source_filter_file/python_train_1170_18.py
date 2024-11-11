t = int(input())
for _ in range(t):
    n, m, x, y = map(int, input().split())

    ans = 0
    if x <= y:
        for _ in range(n):
            string = input()
            ans += string.count('.') * x
    else:
        for _ in range(n):
            string = input()

            long = string.count('..')
            short = string.count('.')

            ans += long * y + (short - long * 2) * x

    print(ans)
