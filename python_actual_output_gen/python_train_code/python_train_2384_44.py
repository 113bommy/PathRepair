for _ in range(int(input())):
    n, m = map(int, input().split())
    if m % n == 0:
        print('Yes')
    else:
        print('No')