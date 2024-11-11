n,w,b=map(int,input().split())
a=list(map(int,input().split()))
price=0
flag=0
if (n%2!=0 and a[n//2]==2):
    price+=min(w,b)
for i in range(0,n//2):
    if(a[i]==1 and a[n-i-1]==0) or (a[i]==0 and a[n-i-1]==1):
        flag=-1
        break
    elif (a[i]==1 and a[n-i-1]==2) or (a[i]==2 and a[n-i-1]==1):
        price+=b
    elif (a[i]==0 and a[n-i-1]==2) or (a[i]==2 and a[n-i-1]==0):
        price+=w
    elif (a[i]==2 and a[n-i-1]==2):
        price+=min(w,b)
if flag==-1:
    print(-1)
else:
    print(price)
