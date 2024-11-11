a=[0 for i in range(100010)]
b=[0 for i in range(100010)]
c=[0 for i in range(100010)]
n, a[1:] = int(input()), map(int,input().split(' '))
for i in range(1,n+1):
    if b[a[i]-1]:
        c[a[i]]=c[a[i]-1]+1
    else:
        c[a[i]]=1
    b[a[i]]=1
print (n-max(c[1:n+1]))
