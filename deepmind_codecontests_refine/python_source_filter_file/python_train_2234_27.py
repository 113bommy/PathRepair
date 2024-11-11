n,m = map(int,input().strip().split(" "))
q=n//2
r=n%2
a=q+r
#print(a)
if(a%m==0):
    print(a)
else:
    k=0
    while(a<=n and n>=m):
        print("ha")
        a=a+1
        if(a%m==0):
            print(a)
            k=1
            break;
    if(k==0):
        print(-1)