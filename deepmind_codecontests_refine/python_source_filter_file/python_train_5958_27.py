from math import ceil
t = int(input())
while(t>0):
    d,g,b = [int(i) for i in input().split()]
    ans = 0
    req = 0
    need =0
    remi =0
    bneed = 0
    temp=0
    if d&1!=0:
        req=d//2+1
    else:
        req = d//2
    if d<g:
        ans= d
    elif d>g:
        need = ceil(req/g)
        remi = need*g-req
        bneed  = b*(need-1)
        temp = bneed+(g*need)-remi
        if temp>=d:
            ans =temp
        else:
            ans=d
    print(ans)
    t-=1
    
    