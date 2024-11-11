n,m = map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
aEven=0
aOdd=0
bEven=0
bOdd=0
for i in range(len(a)):
    if(a[i]%2==0):
        aEven=aEven+1
    else:
        aOdd=aOdd+1
for i in range(len(b)):
    if(b[i]%2==0):
        bEven=bEven+1
    else:
        bOdd=bOdd+1
print((min(aEven,bOdd)+min(aOdd,bEven)))