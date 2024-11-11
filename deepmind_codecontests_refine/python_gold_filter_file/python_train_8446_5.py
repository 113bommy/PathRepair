s=list(map(str,input().split(' ')))
g=[['lios','liala'],['etr','etra'],['initis','inites']]
if len(s)==1:
    n=len(s[0])
    if s[0][n-len(g[0][0]):]==g[0][0] or s[0][n-len(g[0][1]):]==g[0][1] or s[0][n-len(g[1][0]):]==g[1][0] or s[0][n-len(g[1][1]):]==g[1][1] or s[0][n-len(g[2][0]):]==g[2][0] or s[0][n-len(g[2][1]):]==g[2][1]:
        print('YES')
    else:
        print('NO')
else:
    j=0
    f=1
    c=None
    i=0
    nc=0
    while i<len(s):
        if i==0:
            n=len(s[i])
            if s[i][n-len(g[j][0]):]==g[j][0] or s[i][n-len(g[j][1]):]==g[j][1]:
                if s[i][n-len(g[j][0]):]==g[j][0]:
                    c=0
                elif s[i][n-len(g[j][1]):]==g[j][1]==g[j][1]:
                    c=1
                if j==1:
                    nc=nc+1
                i=i+1
            else:
                j=j+1
        else:
            n=len(s[i])
            if s[i][n-len(g[j][c]):]==g[j][c]:
                if j==1:
                    nc=nc+1
                i=i+1
            else:
                j=j+1
        if j==3:
            f=0
            break
    if f and nc==1:
        print('YES')
    else:
        print('NO')