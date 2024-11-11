k = int(input())
a, b = map(int, input().split())

if (a//k+1)*k < b:
    print('OK')
else:
    print('NG')