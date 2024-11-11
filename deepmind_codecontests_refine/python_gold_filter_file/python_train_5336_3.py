t=int(input())
while t :
    n=int(input())
    ans=n
    for i in range(2,n):
        if i*i>n :
            break
        if n%i==0 :
            ans=i
            break
    print("{} {}".format(int(n-n/ans),int(n/ans)))
    t-=1