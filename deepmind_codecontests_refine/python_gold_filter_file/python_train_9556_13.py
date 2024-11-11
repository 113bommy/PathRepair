n,x,d = map(int, input().split())
if d<0:
    d = -d
    x = -x

if d != 0:
    ans = 0
    it = list()
    for i in range(n+1):
        it.append((i*x%d,i))
    it.sort()
    prev = -1
    lsall = []
    ls = [100,-100]
    for idx,i in it:
        if prev != idx:
            lsall.append(ls)
            lsall.sort()
            mnp_,mxp_ = lsall[0]
            for j in range(1,len(lsall)):
                mn_,mx_ = lsall[j]
                if mxp_ < mn_:
                    mxp_ = mx_
                    mnp_ = mn_
                else:
                    ans -= mxp_-mn_+1
                    mxp_ = max(mx_,mxp_)
                    mnp_ = min(mn_,mnp_)
            lsall = list()
            ls = None
            prev = idx
        plus = x*i//d
        mn = i*(i-1)//2 + plus
        mx = i*(n-1+n-i)//2 + plus
        if ls is None:
            ans += mx - mn + 1
            ls = [mn,mx]
        else:
            mnp,mxp = ls
            if mxp + 1 < mn or mnp - 1 > mx:
                ans += mx - mn + 1
                lsall.append(ls)
                ls =[mn,mx]
            else:
                ans += max(mx-mxp,0)
                ans += max(mnp-mn,0)
                ls = [min(mn,mnp),max(mx,mxp)]
    
    

    lsall.append(ls)
    lsall.sort()
    mnp,mxp = lsall[0]
    for i in range(1,len(lsall)):
        mn,mx = lsall[i]
        if mxp < mn:
            mxp = mx
            mnp = mn
        else:
            ans -= mxp-mn+1
            mxp = max(mx,mxp)
            mnp = min(mn,mnp)
    print(ans)
else:
    if x != 0:
        print(n+1)
    else:
        print(1)


