n ,k = map(int, input().split())
s = input()
if k - 1 >= n - k:
    for i in range(n - k):
        print('RIGHT')
    for j in range(n - 1):
        print( 'PRINT ' + s[n - j - 1])
        print('LEFT')
    print('PRINT ' + s[0])
else:
    for i in range(k - 1):
        print('LEFT')
    for j in range(n - 1):
        print( 'PRINT ' + s[j])
        print('RIGHT')
    print('PRINT' + s[n - 1])