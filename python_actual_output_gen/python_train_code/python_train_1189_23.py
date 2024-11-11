n, k = map(int, input().split())
a = list(input())
if k == 0:
    print(a)
elif len(a) == 1:
    print(0)
else:
    if a[0] != '1':
        a[0] = '1'
        k -= 1
    for q in range(1, n):
        if k == 0:
            break
        if a[q] != '0':
            a[q] = '0'
            k -= 1
    print(*a, sep='')
