n=int(input())
X=[]
XD=False
for i in range(n):
    x,d=list(map(int,input().split(' ')))
    X.append([x,x+d])
    if(x+d,x in X):
        XD=True
if XD:    print('YES')
else:   print('NO')