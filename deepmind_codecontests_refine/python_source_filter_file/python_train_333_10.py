


from collections import Counter
n,k = map(int,input().split())
a = sorted(map(int,input().split()))
arr = Counter(a)
lsum = 0
lcnt = 0
rsum= sum(a)
rcnt = len(a)
ans = 10**10
for val,cnt in sorted(arr.items()):
    req = max(0,k-cnt)
    if(req==0):
        ans = 0
        break
    rcnt = rcnt-cnt
    rsum = rsum-val*cnt
    lr = min(req,lcnt)
    rr = max(0,req-lr)
    ta = ((val-1)*lcnt) - lsum + lr
    if lr<req:
        ta += (rsum-((val+1)*rcnt)) + rr
    ans = min(ans,ta)
    rr = min(rcnt,req)
    lr = max(0,req-rr)
    ta = rsum - ((val+1)*rcnt)+ rr
    if rr<req:
        ta += ((val-1)*lcnt) - lsum + lr
    ans = min(ans,ta)
    lcnt += cnt
    lsum += cnt*val
print(ans)
 
 