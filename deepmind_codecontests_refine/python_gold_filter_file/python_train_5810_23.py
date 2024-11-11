a,b = map(int,input().split())
k = a+b
if k%2:
    print('IMPOSSIBLE')
else:
    print(k//2)
