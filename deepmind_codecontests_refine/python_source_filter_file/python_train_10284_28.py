k = int(input())
a,b = map(int,input().split())

if k/b - k/a >= 1:
    print('OK')
else:
    print('NG')