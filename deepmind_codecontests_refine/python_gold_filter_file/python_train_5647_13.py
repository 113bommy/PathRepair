for i in range(int(input())):
    n, m = map(int, input().split())
    print('B' * m)
    for i in range(n-1):
        print('B' + 'W' * (m-1))




