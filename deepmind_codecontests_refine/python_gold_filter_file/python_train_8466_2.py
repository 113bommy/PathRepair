import sys
n,c = map(int,sys.stdin.readline().split())
a = []
b = []
maxi = 0
for i in range (n):
    t1,t2 = map (int,sys.stdin.readline().split())
    a.append(t1)
    b.append(t2)
    if  (b[i]*c//a[i] > maxi ):
        maxi = b[i]*c//a[i]


def letstry(x, a, b):
    """try the result we search for and return the number of days it takes for that value x"""
    res = 0 # total number of day
    for i in range (len(a)):
        res  += x*a[i] // b[i] +1
    return res

def bsl (l,r,val,a,b):
    """search the farthest position on the left that satisfy """
    l1=l
    r1 =r
    res =-1
    while l1 <= r1 :
        mid = (l1+r1)//2
        if (letstry (mid,a,b)< val):
            l1 = mid +1
        if (letstry(mid,a,b) > val):
            r1 = mid -1
        if (letstry(mid,a,b) == val):
            res = mid
            r1 = mid-1
    return res
def bsr (l,r,val,a,b):
    """ search the farthest positon on the right that satisfy the constrain """
    l1=l
    r1 =r
    res =-1
    while l1 <= r1 :
        mid = (l1+r1)//2
        if (letstry (mid,a,b)< val):
            l1 = mid +1
        if (letstry(mid,a,b) > val):
            r1 = mid -1
        if (letstry(mid,a,b) == val):
            res = mid
            l1 = mid +1
    return res
r = bsr(1,maxi,c,a,b)
l = bsl(1,maxi,c,a,b)
#print (l," ",r)
#print (maxi)
if l > r or l==-1 or r ==-1:
    print (0)
else :
    print (r-l +1)