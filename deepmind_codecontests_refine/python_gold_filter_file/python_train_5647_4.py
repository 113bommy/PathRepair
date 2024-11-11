for _ in range(int(input())):
    n, m = map(int, input().split())
    print('W' + 'B' * (m - 1) + '\n' + '\n'.join(['B' * m for i in range(n - 1)]))
