K=int(input())
A,B=map(int,input().split())

if B//K > A//K or B%K==0:
    print('OK')
else:
    print('NG')