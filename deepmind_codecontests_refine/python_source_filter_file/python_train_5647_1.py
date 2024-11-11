for _ in range(int(input())):
    m, n = map(int, input().split())
    print('W' + 'B' * (m - 1) + '\n' + '\n'.join(['B' * m for i in range(n - 1)]))
