aa=input().split()
n=int(aa[0])
k=int(aa[1])
d=int(aa[2])
if(k*(n-1)<d or d<k):
    print("NO")
else:
    print("YES")
    p=1
    while(d>0):
        if(k==1 and p==1):
            print(1+d,end=' ')
            d=0
        elif(k==1 and p==n):
            print(n-d,end=' ')
            d=0
        elif(k==1 and p==n-1):
            print(n-1-d,end=' ')
            d=0
        elif(k==1 and p==2):
            print(2+d,end=' ')
            d=0
        elif(d>=(n+k-2)):
            if(p==1):
                print(n,end=' ')
                p=n
            else:
                print("1",end=' ')
                p=1
            d=d-n+1
        elif(p==1):
            print("2",end=' ')
            p=2
            d-=1
        elif(p==2):
            print("1",end=' ')
            p=1
            d-=1;
        elif(p==n):
            print(n-1,end=' ')
            p=n-1
            d-=1
        elif(p==n-1):
            print(n,end=' ')
            p=n
            d-=1
        k-=1
    
