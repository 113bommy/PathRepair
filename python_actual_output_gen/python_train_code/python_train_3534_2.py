k = int(input())
a, b = map(int, input().split())

if b-a>b%k:
    print('OK')
else:
    print('NG')