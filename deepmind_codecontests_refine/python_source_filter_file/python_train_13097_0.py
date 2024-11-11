n = int(input())
a = []
b = []
for _ in range(n):
    a.append(list(map(int,input().split())))
    d.append([0,0,0])
d[0]=a[0]
for i in range(1,n):
    for j in range(3):
        d[i][j]=max(d[i-1][(j+1)%3],d[i-1][(j+2)%3])+a[i][j]
print(max(d[n-1]))
