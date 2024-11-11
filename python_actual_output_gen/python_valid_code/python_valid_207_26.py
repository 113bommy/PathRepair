n=int(input())
if(n%2!=0):
    print(-1)
else:
    L=[0]*n
    for i in range(n):
        L[i]=1+i+((-1)**i)  
    print(L)