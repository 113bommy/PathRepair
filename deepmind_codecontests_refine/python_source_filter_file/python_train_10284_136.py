K = int(input())
A, B = map(int, input().split())

if (B // K) * B >= A:
    print('OK')
else:
    print('NG')
