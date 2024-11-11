n,k=map(int,input().split())
a=[[0]*n for _ in range(100)]
A=list(map(int,input().split()))
for i,j in enumerate(A):
    a[0][i]=j-1
i=1
while 2**i<k:
    for x,y in enumerate(a[i-1]):
        a[i][x]=a[i-1][y]
    i+=1
x=0
for j in range(i):
    if k>>j&1:
        x=a[j][x]
print(x+1)