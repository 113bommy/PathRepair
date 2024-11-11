t=int(input())
for i in range(t):
    n=int(input())
    count=0
    flag=0
    if n==1:
        print(0)
    if n==2 or n==4 or n==5:
        print(-1)
    if n==6:
        print(1)
    if n==3:
        print(2)
    if n>6:
        j=0
        k=0
        p=n
        while n%3==0:
            n=n/3
            j+=1
        while n%2==0:
            n=n/2
            k+=1
        r=(2**k)*(3**j)
        if j==0:
            print(-1)
        if j>=k:
            if r==p:
                print(2*j-k)
            elif r!=n:
                print(-1)
                
        elif j<k:
            print(-1)