
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    print('W' + 'B' * (m - 1))
    for i in range(m - 1):
        print('B' * m)
