n=int(input())
l=[]
for i in range(n):
    k=list(input())
    l.append(k)
#print(l)
for i in range(1,n-1):
    for j in range(1,n-1):
        if l[i][j]=='.' and l[i-1][j]=='.' and l[i+1][j]=='.' and l[i][j-1]=='.' and l[i][j+1]=='.':
            l[i][j]=l[i-1][j]=l[i+1][j]=l[i][j-1]=l[i][j+1]='#'
#print(l)
for i in range(n):
    for j in range(n):
        if l[i][j]=='.':
            print("NO")
            k=1
            break
    if k==1:
        break
if k==0:
    print("YES")
        