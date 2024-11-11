K=int(input())
A,B=(int(x) for x in input().split())
if K-(A%K)<=B-A or k==A:print('OK')
else:print('NG')
