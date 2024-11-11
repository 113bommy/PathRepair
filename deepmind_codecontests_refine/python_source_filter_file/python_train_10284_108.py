n = int(input())
a,b = map(int,input().split())
if b-a >= n-1:
    print('OK')
else:
    print('NG')