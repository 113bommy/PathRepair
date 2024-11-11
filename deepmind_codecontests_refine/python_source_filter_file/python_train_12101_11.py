t=int(input())
while t>0:
    t-=1
    n,k=input().split( )
    n=int(n)
    k=int(k)
    l=0;
    while (n*(n+1))/2<k:
        l+=1
    j=(n*(n+1))/2-k
    l=n-l 
    j=j+l+1
    s=''
    for m in range(n):
        if m==l-1 or m==j-1:
            s=s+'b'
        else:
            s=s+'a'
    print(s)    