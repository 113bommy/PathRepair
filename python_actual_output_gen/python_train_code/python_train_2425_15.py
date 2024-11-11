arr = list(map(int, input().split()))
n=arr[0]
m=arr[1]
if(n==0):
    print("Impossible")
else:
    a=max(m,n)
    b=m+n-1
    if(m==0):
        b=n
        a=n
    print(str(a)+" "+str(b))    