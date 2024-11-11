def main():
    from bisect import bisect_left
    I=10**9+1
    n,q,*t=map(int,open(0).read().split())
    d=tuple(t[-q:])
    t=t[:-q]
    N0=2**(q-1).bit_length()
    data=[I]*2*N0
    for x,l,r in sorted(((x,bisect_left(d,s-x)+N0,bisect_left(d,t-x)+N0)for s,t,x in zip(t[::3],t[1::3],t[2::3])),reverse=1):
        while l<r:
            if r&1:
                r-=1
                data[r-1]=x
            if l&1:
                data[l-1]=x
                l+=1
            l>>=1
            r>>=1
    for k in range(N0-1,q+N0-1):
        s=I
        while~k:
            if data[k]<s:s=data[k]
            k=(k-1)//2
        print(-(s==I)or s)
if __name__=='__main__':
    main()