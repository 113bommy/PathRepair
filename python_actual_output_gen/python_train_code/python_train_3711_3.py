a,b,c,d=map(int,input().split())
if abs(a-b)<=d and (abs(a-c)<=d or abs(b-c)<=d):
    print('Yes')
else:
    print('No')
