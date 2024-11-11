n,m,k=map(int,input().split())
for i in range(n+1):
    for j in range(m+1):
        if k==i*j+(n-i)*(n-j):
            print('Yes')
            exit()
print('No')