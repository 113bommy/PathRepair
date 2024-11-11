a=[]
for i in range(10):
    a.append([])
    p=[c for c in input()]
    for j in range(10):
        if p[j]=='X':
            a[i].append(1)
        elif p[j]=='O':
            a[i].append(-1)
        elif p[j]=='.':
            a[i].append(0)
f=True
for i in range(10):
    for j in range(10):
        s1,s2,s3=0,0,0
        if i<=5:
            s1=a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j]+a[i+4][j]
        if j<=5:
            s2=a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3]+a[i][j+4]
        if i<=5 and j<=5:
            s3=a[i][j]+a[i+1][j+1]+a[i+2][j+2]+a[i+3][j+3]+a[i+4][j+4]
        if i>=4 and j<=5:
            s3=a[i][j]+a[i-1][j+1]+a[i-2][j+2]+a[i-3][j+3]+a[i-4][j+4]        
        if max(s1,s2,s3)==4:
            f=False
if f:
    print("NO")
else:
    print("YES")