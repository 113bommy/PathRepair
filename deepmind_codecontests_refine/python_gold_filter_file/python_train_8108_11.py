while True:
    n = int(input())
    if n == 0: break
    sum_a = sum_b = 0
    for i in range(n):
        a, b = map(int, input().split())
        if a > b:sum_a = sum_a + a + b
        elif a < b:sum_b = sum_b + a + b
        else:
            sum_a = sum_a + a
            sum_b = sum_b + b
    print(sum_a,sum_b)

