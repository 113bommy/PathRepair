n,m,k=map(int,input().split())

for i in range(1,n+1):
    for j in range(1,m+1):
        black=i*m+j*n-2*i*j
        if black==k:
            print('Yes')
            exit()
print('No')