n,m,k=map(int,input().split())

for i in range(m):
    for j in range(n):
        if i*n+j*m-2*i*j==k:
            print('Yes')
            exit()
print('No')