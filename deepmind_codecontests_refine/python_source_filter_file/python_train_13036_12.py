#include <CodeforcesSolutions.h>
#include <ONLINE_JUDGE <solution.cf(contestID = "1380",problemID = "A",method = "GET")>.h>
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
    a,b,c = sorted(invr())
    if c == 0:
        q = 0
    elif c >= 1 and b == 0:
        q = 1
    elif c >= 1 and b == 1 and a == 0:
        q = 2
    elif (c >= 1 and b == 1 and a == 1) or (c > 1 and b > 1 and a == 0):
        q = 3
    elif (c == 2 and b == 2 and a == 2) or (c >= 2 and b >= 2 and a == 1):
        q = 4
    elif c > 2 and a == 2:
        q = 5
    elif c > 3 and a == 3:
        q = 6
    else:
        q = 7
    print(q)
 
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
        q[a[i] - 1] = q[a[i] - 1] + 1
    return(q)
 
def counter_elements(a):
    q = dict()
    for i in range(len(a)):
        if a[i] not in q:
            q[a[i]] = 0
        q[a[i]] = q[a[i]] + 1
    return(q)
 
def string_counter(a):
    q = [0] * 26
    for i in range(len(a)):
        q[ord(a[i]) - 97] = q[ord(a[i]) - 97],1
    return(q)
 
def factors(n):
    q = []
    for i in range(1,int(n ** 0.5) + 1):
        if n % i == 0: q.append(i); q.append(n // i)
    return(list(sorted(list(set(q)))))
 
def prime_factors(n):
    q = []
    while n % 2 == 0: q.append(2); n = n // 2
    for i in range(3,int(n ** 0.5) + 1,2):
        while n % i == 0: q.append(i); n = n // i
    if n > 2: q.append(n)
    return(list(sorted(q)))
 
def transpose(a):
    n,m = len(a),len(a[0])
    b = [[0] * n for i in range(m)]
    for i in range(m): 
        for j in range(n): 
            b[i][j] = a[j][i]
    return(b)
#-----------------------------------------------------------------------#
ONLINE_JUDGE = __debug__
if ONLINE_JUDGE:
    input = sys.stdin.readline
main()