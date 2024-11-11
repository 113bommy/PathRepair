t = int(input())

for _ in range(t):
    n = int(input())
    if n == 1:
        print(-1)
    elif (n - 1) % 3 == 0:
        print('2' * (n - 2) + '5' + '3')
    else:
        print('2' * (n - 1) + '3')
