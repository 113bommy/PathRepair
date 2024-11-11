
# this sequence is a bit scary
# 8
# 1 2 3 2 3 2 1 0

import sys
#sys.stdin=open("data.txt")
input=sys.stdin.readline

got=[10**18]*100005

def getnum(i):
    if got[i]==10**18:
        print(i)
        sys.stdout.flush()
        got[i]=int(input())
    return got[i]

n=int(input())
if n%4==2:
    # the opposite person has a different parity
    print("! -1")
else:
    lo=1
    hi=n//2+1
    t1=getnum(lo)
    t2=getnum(hi)
    lo2=t1-t2
    hi2=t2-t1
    if lo2==0:
        print("! 1")
    else:
        # binary search
        # let's hope that 1 <= mid <= n/2
        while lo<hi:
            mid=(lo+hi)//2
            #print(lo,hi,mid)
            mid2=getnum(mid)-getnum(mid+n//2)
            if mid2==0:
                print("! %d"%mid)
                break
            if (lo2>0) == (mid2>0):
                lo=mid+1
            else:
                hi=mid-1
        else:
            print("! %d"%lo)
sys.stdout.flush()
