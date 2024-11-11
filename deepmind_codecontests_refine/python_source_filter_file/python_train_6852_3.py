def main():
    def add(i,x):
        while i<=size:
            tree[i]+=x
            i+=i&-i
    n,*a=map(int,open(0).read().split())
    size=n-~n
    m=n*-~n//2+1>>1
    ng=max(a)+1
    ok=0
    while ng-ok>1:
        mid=(ok+ng)//2
        tree=[0]*-~size
        c=n+1
        s=0
        add(c,1)
        for t in a:
            c+=1if t>=mid else-1
            i=c
            while i:
                s+=tree[i]
                i-=i&-i
            add(c,1)
        if s>=m:ok=mid
        else:ng=mid
    print(ok)
main()