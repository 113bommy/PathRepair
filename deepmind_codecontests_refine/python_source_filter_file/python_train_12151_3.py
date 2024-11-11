n,m=map(int,input().split())
l=[]
d=[['.']*m for i in range(n)]
n,m=n-1,m-1
def check(l,i):
    if "*" in l[i]:
        a=l[i].index("*")
    else:
        a=-1
    while a>=0:
        d[i][a]='*'
        if a+1<=m:
            if d[i][a+1]=='.':
                d[i][a+1]=1
            elif d[i][a+1]!='.' and d[i][a+1]!='*':
                d[i][a+1]+=1
            if i-1>=0 and d[i-1][a+1]=='.':
                d[i-1][a+1]=1
            elif i-1>=0 and d[i-1][a+1]!='.' and d[i-1][a+1]!='*':
                d[i-1][a+1]+=1
            if i+1<=n and d[i+1][a+1]=='.':
                d[i+1][a+1]=1
            elif  i+1<=n and d[i+1][a+1]!='.' and d[i+1][a+1]!='*':
                d[i+1][a+1]+=1
        if a-1>=0:
            if d[i][a-1]=='.':
                d[i][a-1]=1
            elif d[i][a-1]!='.' and d[i][a-1]!='*':
                d[i][a-1]+=1
            if i-1>=0 and d[i-1][a-1]=='.':
                d[i-1][a-1]=1
            elif i-1>=0 and d[i-1][a-1]!='.' and d[i-1][a-1]!='*':
                d[i-1][a-1]+=1
            if i+1<=n and d[i+1][a-1]=='.':
                d[i+1][a-1]=1
            elif i+1<=n and d[i+1][a-1]!='.' and d[i+1][a-1]!='*':
                d[i+1][a-1]+=1
        if i-1>=0 and d[i-1][a]=='.':
            d[i-1][a]=1
        elif i-1>=0 and d[i-1][a]!='.' and d[i-1][a]!='*':
            d[i-1][a]+=1
        if i+1<=n and d[i+1][a]=='.':
            d[i+1][a]=1
        elif i+1<=n and d[i+1][a]!='.' and d[i-1][a]!='*':
            d[i+1][a]+=1
        if '*' in l[i][a+1:]:
            a=l[i][a+1:].index('*')+a+1
        else:
            a=-1
    return d
for i in range(n+1):
    l.append(list(input()))
for i in range(n+1):
    li=check(l,i)
for i in range(n+1):
    for j in range(m+1):
        if d[i][j]!='.' and d[i][j]!='*':
            d[i][j]=str(d[i][j])
if d==l:
    print("YES")
else:
    print("NO")
