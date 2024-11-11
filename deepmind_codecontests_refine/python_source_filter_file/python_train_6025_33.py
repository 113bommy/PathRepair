n,l = map(int,input().split())
a = list(map(int,input().split()))

for i in range(n-1):
    if a[i]+a[i+1] >= l:
        print("Possible")
        for j in range(1,i+1):
            print(j)
        for k in range(i,n-1):
            print(k+1)
        exit()
print("Impossible")  