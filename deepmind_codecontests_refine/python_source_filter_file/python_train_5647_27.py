def func(n, m):
    counter_b = 0
    counter_w = 0
    if n == 1 and m >= 3:
        tmp = 'B' * (m - 3)
        print('BWB' + tmp)
    elif n > 2 and m == 1:
        print('B')
        print('W')
        print('B')
        for i in range(n - 3):
            print('B')
    elif n > 1 and m > 1:
        tmp = 'B' * (m - 2)
        print('WB' + tmp)
        print('B' + tmp + 'b')
        for j in range(n - 2):
            print('B' * m)


k = int(input())
for g in range(k):
    func(*list(map(int, input().split())))








