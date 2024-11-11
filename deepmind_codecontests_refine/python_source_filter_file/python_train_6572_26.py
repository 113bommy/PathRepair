n=int(input())
a=[]
for i in range(n):
    a.append(list(input()))
print(a)
c=0
for i in range(1,n-1,1):
    for j in range(1,n-1,1):
        if(i+1>-1 and i+1<n and i-1>-1 and i-1<n and j+1>-1 and j+1<n and j-1>-1 and j-1<n):
            if(a[i][j] == a[i+1][j+1] == a[i-1][j+1] == a[i+1][j-1] == a[i-1][j-1]=='X'):
                c=c+1
            
print(c)
    