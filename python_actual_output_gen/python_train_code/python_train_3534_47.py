N = int(input())
A, B = map(int, input().split())

if B - A >= N - 1:
    print('OK')
else:
    print('NG')