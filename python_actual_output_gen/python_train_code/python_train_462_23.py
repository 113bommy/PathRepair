a,b,c = map(int,input().split())
if a==b:
    print('YES')
elif c==0 and a!=b:
    print('NO')
elif (b%abs(c)==a%b) and ((a<b and c>0) or (a>b and c<0)):
    print('YES')
else:
    print('NO')