n = int(input())

b = list(map(int, input().split()))

a = [0] * ((n + 1)//2)
a += b[::-1]
for i in range(n - 2, n // 2 - 1, - 1):
    diff_a = a[i + 1] - a[i]
    diff_b =  a[n - i - 1] - a[n - i - 2]
    if diff_a >= 0 and diff_b >= 0:
        continue
    if diff_a < 0:
        a[i] += diff_a
        a[n - i - 1] -= diff_a
        diff_b =  a[n - i - 1] - a[n - i - 2]
    if diff_b < 0:
        a[n -  i - 1] -=  diff_b
        a[i] += diff_a
for i in a:
    print(i, end=' ')