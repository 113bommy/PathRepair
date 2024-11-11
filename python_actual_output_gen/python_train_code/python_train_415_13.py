for test_i in range(int(input())):
    n, m, x, y = map(int, input().split())
    ans = 0
    if y >= x * 2:
        for r in range(n):
            for ch in input():
                if ch == '.':
                    ans += x
    else:
        for r in range(n):
            prev = '*'
            for ch in input() + '*':
                if prev == '.':
                    if ch == '.':
                        ans += y
                        prev = '*'
                    else:
                        ans += x
                        prev = '.'
                else:
                    prev = ch
    print(ans)