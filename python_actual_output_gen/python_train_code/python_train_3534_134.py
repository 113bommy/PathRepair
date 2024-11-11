
K= int(input())
A, B = map(int, input().split())
if B/K-A/K>=1:
    print('OK')
else:
     print('NG')