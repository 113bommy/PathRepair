R = lambda: map(int, input().split())
for _ in range(int(input())):
    n = int(input())
    pmin = prev = 10 ** 6
    good = True
    for num in R():
        if num != prev + 1:
            good = good and num < pmin
            pmin = prev
        prev = num
    print('YES' if good else 'NO')