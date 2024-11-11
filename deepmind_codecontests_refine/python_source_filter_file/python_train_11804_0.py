import sys
def exi():
    print("NO")
    sys.exit()
I=lambda:list(map(int,input().split()))
g=[]
n,m=I()
for i in range(n):
    g.append(list(input()))
for i in range(n):
    temp=0
    for j in range(1,m):
        if g[i][j-1]!=g[i][j]:
            temp+=1
    #print(temp)
    if temp>2 or temp==2 and g[i][0]=='B':exi()
for j in range(m):
    temp=0
    for i in range(n):
        if g[i-1][j]!=g[i][j]:
            temp+=1
    if temp>2 or temp==2 and g[0][j]=='B':exi()
for i1 in range(n):
    for j1 in range(m):
        if g[i1][j1]=='B':
                
            for i2 in range(n):
                for j2 in range(m):
                    if g[i2][j2]=='B':
                        if g[i1][j2]=='W' and g[i2][j1]=='W':exi()
print("YES")
