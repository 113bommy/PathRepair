from collections import defaultdict as df
d=df(list)
n=int(input())
a=[[0]*n for i in range(n)]
y=1
for i in range(n):
    if i==0:
        pass
    else:
        if a[i-1][0]=='W':
            
            y=2
        else:
            y=1
    for j in range(n):
        if y==1:
            a[i][j]='W'
            y=2
        else:
            a[i][j]='B'
            y=1
for i in a:
    print(*i)
        
            
        
        