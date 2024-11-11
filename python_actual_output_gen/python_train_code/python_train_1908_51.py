n,m,k = map(int,input().split())

for i in range(1,n+1):
    for j in range(1,m+1):
        #print(n*j+m*i-i*j*2)
        if i*(m-j)+j*(n-i)==k:
            print('Yes');exit()
print('No')