import math
n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if(n>m):
    if(a[0]>0):
        print("Infinity")
    else:
        print("-Infinity")
elif(n<m):
    print("0/1")
else:
    k=math.gcd(a[0],b[0])
    if (a[0]*b[0] >0):
        print(int(abs(a[0]//k)), '/', int(abs(b[0]//k)), sep='')
    else:
        print('-',int(abs(a[0]//k)), '/',int(abs(b[0]//k)), sep='')
        
        