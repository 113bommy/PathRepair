def arr_2d(n):
    return [[int(x) for x in input().split()] for i in range(n)]

n,m=map(int,input().split())
a=arr_2d(n)

for i in range(n):
    if((i==0 or i==n-1)and sum(a[i])==1):
        exit(print(2))
    elif(a[i][0]==1 or a[i][m-1]==1):
        exit(print(2))
print(4)
