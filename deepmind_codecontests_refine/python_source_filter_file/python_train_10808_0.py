a,b,c,d=map(int,input().split())
if (abs(a-b)<=b and abs(b-c)<=b) or abs(a-c)<=b:
    print('Yes')
else:
    print('No')