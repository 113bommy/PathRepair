t = int(input())
for _ in range(t):
    n, m = [int(x) for x in input().split()]
    a = [[int(x) for x in input().split()] for i in range(n)]
    b = 0
    sum_ = 0
    min_ = 101
    for row in range(n):
        for column in range(m):
            y = a[row][column]
            sum_ += abs(y)
            if y < min_:
                min_ = abs(y)
            if y <= 0:
                b += 1
    if b % 2 == 0:
        print(sum_)
    else:
        print(sum_ - 2*min_)