n = int(input())
for i in range(n):
    m, k = map(int, input().split())
    if m == 0:
        print('Bob')
    else:
        if k % 3 == 0:
            m %= k - 1
        if m != k and m % 3 == 0:
            print('Bob')
        else:
            print('Alisa')