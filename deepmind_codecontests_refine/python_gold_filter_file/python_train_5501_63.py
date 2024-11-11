n,m,k=map(int,input().split())

for i in range(m+1):
    for j in range(n+1):
        if i*n+j*m-2*i*j==k:
            print('Yes')
            exit()
print('No')