k = int(input())
a, b = map(int, input().split())
if b-a+1 >= k:
    print('OK')
else:
    print('NG')