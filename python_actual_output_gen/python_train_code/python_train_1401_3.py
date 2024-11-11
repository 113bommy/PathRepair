import sys
def test (pos):
    current_pack = k
    count =1
    for i in range (pos,n):
        if a[i] > current_pack :
            count +=1
            current_pack = k
        else:
            current_pack -= a[i]
    if (count > m ):
        return False
    else:
        return True

def bs (l,r):
    l1 = l
    r1 = r
    res = 0
    while (l1<=r1):
        mid = (l1+r1)//2
        if test (mid) == True:
            res = mid
            r1 = mid-1
        else: l1 = mid +1
    return res

n,m,k  = map (int, sys.stdin.readline().split())
a = list (map(int,sys.stdin.readline().split()))

print (n-bs (0,n-1))