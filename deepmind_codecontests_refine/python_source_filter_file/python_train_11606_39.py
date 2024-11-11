n=int(input())
z=[]
for i in range(n):
    z.append([1]+[0]*n)
for i in range(n):
    for j in range(n):
        if i==0:
            z[i][j]=1
for i in range(1,n):
    for j in range(1,n):
        z[i][j]=z[i-1][j]+z[i][j-1]
print(z[i][j])
for i in range(n):
    for j in range(n):
        print(z[i][j], end=' ')
    print()
