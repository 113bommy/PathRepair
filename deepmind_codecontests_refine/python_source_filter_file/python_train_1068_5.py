def ceil_div(y,k):
    return (y+(k-1))//k

t = int(input())
for i in range(t):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    b = set(a)
    d = len(b)
    zero = False
    for x in b:
        if x==0:
            zero = True;
    # we can do mi rounds with k in each. Then we can only have k-1 in each
    # not all are zero.
    if k==1:
        if d>1:
            print(-1)
        else:
            print(1)
        continue
    if zero:
        print(ceil_div(d-1,k-1))
    else:
        if d <= k:
            print(1)
        else:
            d-=k;
            print(1+ceil_div(d-1,k-1))
