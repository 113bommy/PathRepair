n,k=list(map(int,input().split()));
x=n**2;
a=[[0 for i in range(n)]for j in range(n)];
for i in range(n):
    for j in range(n-1,k-2,-1):
        a[i][j]=x;
        x-=1;
for i in range(n):
    for j in range(k-2,-1,-1):
        a[i][j]=x;
        x-=1;
print(sum([a[i][k-1]for i in range(n)]));
for i in range(n):
    print(' '.join(list(map(str,a[i]))));
