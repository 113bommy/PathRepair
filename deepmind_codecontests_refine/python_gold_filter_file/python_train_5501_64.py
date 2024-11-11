n,m,k = map(int,input().split())
for i in range(0,n+1):
    for j in range(0,m+1):
        if n*j+m*i-2*i*j == k:
            print("Yes")
            exit(0)
print("No")


