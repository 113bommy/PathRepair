n, k = map(int, input().split())
a = list(input())
n, k = n-1, k-1
if k == n:
    a = a[::-1]
    for i in range(len(a) - 1):
        print('PRINT', a[i])
        print('LEFT')
    print('PRINT', a[-1])
elif k == 0:
    for i in range(len(a) - 1):
        print('PRINT', a[i])
        print('RIGHT')
    print('PRINT', a[-1])
elif k < n/2:
    for i in range(k):
        print('LEFT')
    for i in range(len(a) - 1):
        print('PRINT', a[i])
        print('RIGHT')
    print('PRINT', a[-1])   
else:
    for i in range(n - k):
        print('RIGHT')
    a = a[::-1]
    for i in range(len(a)):
        print('PRINT', a[i])
        print('LEFT')
    print('PRINT', a[-1])        