n,k= map(int,input().split())
a= list(map(int,input().split()))
c=2
maxi=c
if n==1:
    print("1")
    exit(0)
if n==2 and a[0]!=a[1]:
    print("2")
    exit(0)
if n==2 and a[0]==a[1]:
    print("1")
    exit(0)
for i in range(1,n-1):
    if a[i+1]==a[i]:
        c=1
    else:
        c+=1
        if c>maxi:
            maxi=c
print(maxi)