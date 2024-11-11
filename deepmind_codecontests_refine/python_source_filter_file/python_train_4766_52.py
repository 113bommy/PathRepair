x,y = map(int,input().split())

if 2 <= y <= 4 and (x*y) %2 == 0:
    print('Yes')
else:
    print('No')