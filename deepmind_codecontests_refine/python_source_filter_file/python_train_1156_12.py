def inint():
    return int(input())
def inlist():
    return list(map(int,input().split()))
def pf(a):
    factor=[]
    i=2
    while i*i<a:
        ch=0
        while a%i==0:
            ch+=1
            a//=i
        if ch!=0:factor.append([i,ch])
        i+=1
    if a>1:
        factor.append([a,1])
    return factor
def main():
    n=inint()
    f=pf(n)
    sol=1
    mxp=0
    for i,j in f:
        mxp=max(mxp,j)
    from math import log,ceil
    ans=0
    if mxp>0:ans=ceil(log(mxp,2))
#    print(ans,mxp,f)
    for i,j in f:
        if j<2**ans:ans+=1;break
    for i,j in f:
        sol*=i
    print(sol,ans)


if __name__ == "__main__":
    #import profile
    #profile.run("main()")
    main()