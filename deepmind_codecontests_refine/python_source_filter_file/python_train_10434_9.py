## python 3
from math import log

MAX_EXP = 0
used = []

def getExpo(x, k):
    global MAX_EXP
    l, r = 0, MAX_EXP
    ##
    while l <= r:
        mid = (l + r + 1)//2
        if x % k**mid == 0 and x % k**(mid+1) != 0:
            return mid
        if x % k**mid == 0:
            l = mid
        else:
            r = mid - 1
    ##
    return -1

def test(x, k):
    global used
    D = {}

    cumExp = 0

    ##
    while x > 0:
        exp = getExpo(x, k)
        if exp == -1:
            return False
        # print("x = %d | exp = %d\n" % (x, exp))
        ##
        x /= (k ** exp)
        x -= 1
        ##
        cumExp += exp
        D[cumExp] = D.get(cumExp, 0) + 1
        if D[cumExp] > 1:
            return False

    ## Check for collision
    for k in D.keys():
        if used[k] == 1:
            return False
    ## Comfirmation
    for k in D.keys():
        used[k] = 1
    return True
        

def solve():
    n, k = map(int, input().split())
    a    = list(map(int, input().split()))
    ###
    global used
    used = [0] * 64
    global MAX_EXP
    MAX_EXP = int(log(max(a) + 1, k)) + 5
    # print("MAX_EXP = ", MAX_EXP)
    ###
    for x in a:
        # print("$Testing ", x);
        if test(x, k) == False:
            print("NO\n")
            return
    ###
    print("YES\n")

t = int(input())
while t > 0:
    t -= 1
    ##
    solve()
