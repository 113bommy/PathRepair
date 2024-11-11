q = int(input())
for _  in range(q):
    c,m,x = map(int,input().split())
    l = 0
    r = min(c,m)
    while l<r:
        mid = (l+r)//2
        var1 = c-mid+m-mid
        if var1+x>mid:
            l=mid
        else:
            r=mid
        if r-l<=1:
            if c-r+m-r +x>=r:
                print(r)
            else:
                print(l)
            break