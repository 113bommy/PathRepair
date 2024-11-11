t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    print('abc' * (n // 3), end='')
    if n % 3 == 1:
        print('a', end='')
    elif n % 3 == 2:
        print('ab', end='')
    print()