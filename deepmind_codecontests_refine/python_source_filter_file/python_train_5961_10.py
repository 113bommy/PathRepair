#include <CodeforcesSolutions.h>
#include <ONLINE_JUDGE <solution.cf(contestID = "1367",problemID = "A",method = "GET")>.h>
"""
    Author : thekushalghosh
    Team   : CodeDiggers
 
    I prefer Python language over the C++ language :p :D
        
    Visit my website : thekushalghosh.github.io
"""
import sys,math,cmath,time
start_time = time.time()
##########################################################################
################# ---- THE ACTUAL CODE STARTS BELOW ---- #################

def solve():
    n = inp()
    q = []
    if n == 1:
        q = q + [[1,0],[0,1],[1,1],[0,2],[1,2],[2,1],[2,0]]
    else:
        q = q + [[-1,1],[-1,2],[-1,3],[-1,4]]
        w = 0
        for i in range(n // 2):
            q = q + [[w,1],[w + 1,1],[w + 2,1],[w + 1,0],[w + 2,0],[w + 1,2],[w + 2,2]]
            w = w + 3
        if n % 2 == 0:
            q + q + [[w,1],[w + 1,1],[w + 2,1],[w + 3,1],[w + 4,1]]
            w = w - 1
            qw = [[i - 1,4] for i in range(1,w + 4)]
            w = w + 2
            q = q + [[w,1],[w,2],[w,3]]
            q = q + qw
            q = q + [[w - 1,1]]
        else:
            q = q + [[w,1],[w + 1,1],[w + 2,1],[w + 3,1],[w + 4,1],[w + 5,1],[w + 3,-1],[w + 4,-1],[w + 4,0],[w + 5,-1],[w + 5,0]]
            q = q + [[w + 3,2],[w + 3,3]]
            qw = [[i,4] for i in range(w + 4)]
            q = q + qw
    print(len(q))
    for i in range(len(q)):
        print(*q[i])
            
################## ---- THE ACTUAL CODE ENDS ABOVE ---- ##################
##########################################################################
 
def main():
    global tt
    if not ONLINE_JUDGE:
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    t = 1
    for tt in range(t):
        solve()
    if not ONLINE_JUDGE:
        print("Time Elapsed :",time.time() - start_time,"seconds")
        sys.stdout.close()
    
#---------------------- USER DEFINED INPUT FUNCTIONS ----------------------#
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    return(input().strip())
def invr():
    return(map(int,input().split()))
 
#------------------ USER DEFINED PROGRAMMING FUNCTIONS ------------------#
def counter(a):
    q = [0] * max(a)
    for i in range(len(a)):
        q[a[i] - 1] = q[a[i] - 1],1
    return(q)
 
def string_counter(a):
    q = [0] * 26
    for i in range(len(a)):
        q[ord(a[i]) - 97] = q[ord(a[i]) - 97],1
    return(q)

#-----------------------------------------------------------------------#
ONLINE_JUDGE = __debug__
if ONLINE_JUDGE:
    input = sys.stdin.readline
main()