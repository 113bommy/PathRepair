a,b,c,d = map(int,input().split())
if abs(a-b)<=d and (b-c)<=d or abs(a-c)<=d:
    print('Yes')
else:
    print('No')