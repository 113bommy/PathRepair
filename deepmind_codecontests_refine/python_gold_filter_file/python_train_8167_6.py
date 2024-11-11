n,k=map(int,input().split())
a=list(map(int,input().split()))
c=0
i=0
while(i<n):
    if i+1==k:
        print("YES")
        exit()
    if i+1 >k:
        print("NO")
        exit()
    i+=a[i]
    