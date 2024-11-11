#include <CodeforcesSolutions.h>
#include <ONLINE_JUDGE <solution.cf(contestID = "1370",problemID = "A",method = "GET")>.h>
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

def qw(n):
    if n == 2:
        return True
    if n % 2 == 0 or n <= 1:
        return False

    sqr = int(math.sqrt(n)) + 1

    for divisor in range(3, sqr, 2):
        if n % divisor == 0:
            return False
    return True

def solve():
    n = inp()
    q = n
    if n == 1:
        print("FastestFinger")
    elif n % 2 != 0 or n == 2:
        print("Aashishgup")
    else:
        while q % 2 == 0:
            q = q // 2
        if q == 1:
            print("FastestFinger")
        elif n // q > 2 or not qw(q):
            print("Aashishgup")
        else:
            print("FastestFinger")
            
################## ---- THE ACTUAL CODE ENDS ABOVE ---- ##################
##########################################################################
 
def main():
    global tt
    if not ONLINE_JUDGE:
        sys.stdin = open("input.txt","r")
        sys.stdout = open("output.txt","w")
    t = 1
    t = inp()
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