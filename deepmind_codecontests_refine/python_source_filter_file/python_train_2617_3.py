n,k,A,B = map(int,input().split())
a = list (map(int,input().split()))

def  bs (l,r,val,a):
    """ a normal binary search function that gonna search between l and r and find a position pos in array a which  a[pos] <= val """
    l1 = l
    r1 =r
    res = -1
    while (l1 <= r1 ):
        mid = (l1+r1) // 2 # position that we are considering
        if (a[mid] <= val):
             res = mid
             l1 = mid +1
        else :
            r1 =mid -1
    return res
def bsfl  (l,r,val,a):
    l1 =l
    r1 = r
    res = -1
    while (l1 <= r1):
        mid = (l1+r1)//2
        if a[mid] < val :
            l1= mid+1
        elif a[mid] >= val :
            res = mid
            r1 = mid -1
    return res
def  split  (left,right,a):
    """ here we solve the problem given either take A or split """
    l1 = bsfl(0,k-1,left,a)
    if a[l1] > right :
        l1 = -1

    r1 = bs (0,k-1,right,a)
    if a[r1] < left:
        r1 = -1
    # print (left,"--------",right )
    # print (l1,"+++++++++",r1)
    if (r1 == -1 or l1  == -1  ):
#        print  ("returning A")
        return A
    if left == right  :
        res = B * (right - left + 1) * (r1 - l1 + 1);
#        print  ("returning res ",res)
        return res
    res =min(B*(right -left +1)*(r1-l1+1),split(left,(right+left)//2,a) + split((right+left)//2+1,right ,a))
#    print ("returning res split",res )
    return res

print (split (1,2**n,a))
