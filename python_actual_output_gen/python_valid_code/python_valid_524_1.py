import sys
input= sys.stdin.buffer.readline


for _ in range(int(input())):
    w,h=[int(c) for c in input().split()]
    x1,y1,x2,y2=[int(c) for c in input().split()]
    nw,nh = [int(c) for c in input().split()]
    ow,oh = x2-x1,y2-y1
    if(ow+nw >w and oh+nh>h):
        ans = -1
        # print("herere")
    else:
        ans = float("inf")
        if(ow+nw <= w):
        ## right fit
            ans = min(ans,max(nw-ow+x2,0))
        ## left fit
            ans= min(ans,max(0,nw-x1))
        ##top fit
        
        if(oh+nh <=h):
            ans= min(ans,max(0,nh-oh+y2))
        ##bottom fit
            ans = min(ans,max(0,nh-y1))
    print(ans)
    