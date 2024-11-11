n,m=map(int,input().split())
mat = [input() for i in range(n)]
x = [0]*n
y = [0]*m
c=0
for i in range(n):
    for  j in range(m):
        if mat[i][j] == '*':
          x[i]+=1
          y[j]+=1
          c+=1
for i in range(n):
    for j in range(m):
        if x[i]+y[i]+('*'==mat[i][j]) == c:
            print("YES\n",i+1," ",j+1)
            exit(0)
print("NO\n")
