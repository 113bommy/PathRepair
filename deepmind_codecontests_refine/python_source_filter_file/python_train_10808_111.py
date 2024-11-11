a,b,c,d=map(int,input().split())
if abs(a-b)<=d or abs(a-c)<=b or abs(b-c)<=d:
    print('Yes')
else:
    print('No')