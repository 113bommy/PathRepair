"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys,math,cmath,time
start_time = time.time()

################# ---- USER DEFINED INPUT FUNCTIONS ---- #################
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(s[:len(s)])
def invr():
    return(map(int,input().split()))
##########################################################################
################# ---- THE ACTUAL CODE STARTS BELOW ---- #################

def solve():
    a,b,q = invr()
    w = a * b // math.gcd(a,b)
    qw = []
    for i in range(w):
        if not qw:
            qw.append(0)
        qq = qw[-1]
        if ((i + 1) % a) % b != ((i + 1) % b) % a:
            qq = qq + 1
        qw.append(qq)
    qwqw = []
    for i in range(q):
        l,r = invr()
        l = l - 1
        lc = math.floor(l / w) * qw[-1]
        rc = math.floor(r / w) * qw[-1]
        qwqw.append(max(0,rc - lc + qw[r % w] - qw[l % w]))
    print(*qwqw)
    
################## ---- THE ACTUAL CODE ENDS ABOVE ---- ##################
##########################################################################
def main():
    ONLINE_JUDGE = __debug__
    if not ONLINE_JUDGE:
        sys.stdin = open('input.txt','r')
        sys.stdout = open('output.txt','w')
    else:
        input = sys.stdin.readline
    t = 1
    t = inp()
    for tt in range(t):
        solve()
    if not ONLINE_JUDGE:
        print("Time Elapsed:",time.time() - start_time,"seconds")

############## ---- USER DEFINED PROGRAMMING FUNCTIONS ---- ##############
def counter(a):
    q = [0] * max(a)
    for i in range(len(a)):
        q[a[i] - 1] = q[a[i] - 1] + 1
    return(q)

main()
sys.stdout.close()
