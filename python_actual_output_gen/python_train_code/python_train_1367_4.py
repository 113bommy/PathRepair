def char(s,i,exp):
    dif = s-i
    r=exp
    l=0
    ans = None
    while r>l:
        m = l+(r-l)//2
        mreal = exp*-1+m*2
        if mreal+dif>0:
            r=m-1
            ans = m
        else: l = m+1
    if ans==None:
        if dif>0:
            return 1
        return 0
    return exp+1-ans
T = int(input())
for _ in range(T):
    s,i,exp = map(int,input().split())
    print(char(s,i,exp))
