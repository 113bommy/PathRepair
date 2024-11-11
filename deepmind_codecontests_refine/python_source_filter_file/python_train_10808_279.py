a,b,c,d=map(int,input().split())
if abs(a-c) <= d or (abs(a-b)<=d and ans(b-c)<=d):
    print('Yes')
else:
    print('No')
