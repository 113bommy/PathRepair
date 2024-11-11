n, k = map(int, input().split())
S = input()
k -= 1
if k >= (n - 1) / 2:
    print('PRINT', S[k])
    for i in range(k+1, n):
        print('RIGHT')
        print('PRINT', S[i])
    for i in range(k+1, n):
        print('LEFT')
    for i in range(k-1, -1, -1):
        print('LEFT')
        print('PRINT', S[i])
else:
    print('PRINT', S[k])   
    for i in range(k-1, -1, -1):
        print('LEFT')
        print('PRINT', S[i])
    for i in range(k-1, -1, -1):
        print('RIGHT')
    for i in range(k+1, n):
        print('RIGHT')
        print('PRINT', S[i])