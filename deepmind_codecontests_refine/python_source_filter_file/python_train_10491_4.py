def main():
    M=10**9+7
    n,k,*a=map(int,open(0).read().split())
    x,y=[],[]
    for i in a:
        if i>0:x+=i,
        if i<0:y+=i,
    if len(x)+len(y)<k or k%2 and not x and len(y)<n:
        print(0)
        return
    if n==k or k%2 and not x:
        c=1
        for i in sorted(y)[-k:]:
            c=c*i%M
        print(c)
        return
    x=sorted(x)[::-1][:k]
    i=len(x)
    y.sort()
    m=len(y)
    j=k-i
    if j%2:
        x=x[:-1]
        i-=1
        j+=1
    x+=y[:j]
    while i>1 and j+1<m and x[i-1]*x[i-2]<y[j]*y[j+1]:
        x[i-1],x[i-2]=y[j],y[j+1]
        i-=2
        j+=2
    c=1
    for i in x:
        c=c*i%M
    print(c)
main()