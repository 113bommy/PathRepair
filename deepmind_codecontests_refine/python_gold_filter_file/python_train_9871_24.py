######################################################
############Created by Devesh Kumar###################
#############devesh1102@gmail.com####################
##########For CodeForces(Devesh1102)#################
#####################2020#############################
######################################################
import sys
input = sys.stdin.readline

# import sys
import heapq 
import copy
import math
import decimal

# import sys.stdout.flush as flush
# from decimal import *
#heapq.heapify(li) 
#
#heapq.heappush(li,4) 
#
#heapq.heappop(li)
#
# &	Bitwise AND Operator	10 & 7 = 2
# |	Bitwise OR Operator	10 | 7 = 15
# ^	Bitwise XOR Operator	10 ^ 7 = 13

# <<	Bitwise Left Shift operator	10<<2 = 40
# >>	Bitwise Right Shift Operator
# '''############ ---- Input Functions ---- #######Start#####'''


def inp():
    return(int(input()))
def inlt(): 
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def insr2():
    s = input()
    return((s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
############ ---- Input Functions ---- #######End
# #####   

def seg_fun(fun,a,b):
    if fun == "max":
        return max(a,b)
    elif fun == "min":
        return min(a,b)
    elif fun == "sum":
        return a+b
def build_seg_tree(arr,n,fun) : 
    # insert leaf nodes in tree  
    tree = [ 0 for i in range(2*n)]
    for i in range(n) :  
        tree[n + i] = arr[i]  
    # build the tree by calculating parents  
    for i in range(n - 1, 0, -1) :  
        tree[i] = seg_fun(fun,tree[i << 1],tree[i << 1 | 1])
        # tree[i] = tree[i << 1] + tree[i << 1 | 1]
    return tree  
  
# function to update a tree node  
def updateTreeNode(p, value,tree,n,fun) :  
    # set value at position p  
    tree[p + n] = value;  
    p = p + n;  
    # move upward and update parents  
    i = p
    while i > 1 : 
        tree[i >> 1] = seg_fun(fun,tree[i],tree[i ^ 1])
        # tree[i >> 1] = tree[i] + tree[i ^ 1];  
        i >>= 1;  
    return tree
  
# function to get sum on interval [l, r)  
def query(l, r,tree,n,fun) :  
    if fun == "max":
        res = -1*sys.maxsize
    if fun == "min":
        res = sys.maxsize
    if fun == "sum":
        res = 0
    # loop to find the sum in the range  
    l += n; 
    r += n; 
    while l < r : 
        if (l & 1) : 
            # res += tree[l]  
            res = seg_fun(fun,res,tree[l])
            l += 1
      
        if (r & 1) : 
            r -= 1
            # res += tree[r]  
            res = seg_fun(fun,res,tree[r])
              
        l >>= 1
        r >>= 1
      
    return res;  


def pr_list(a):
    print(*a, sep=" ")
def main():
	# tests =  inp()
    tests = 1
    mod = 1000000007
    limit = 10**18
    ans = 0
    for test in range(tests):
        n = inp()
        h = inlt()
        a= inlt()
        dp = [-1*sys.maxsize for i in range(n+1)]
        tree = build_seg_tree(dp,len(dp),"max")
        
        ans = 0
        for i in range(0,n):
            dp[h[i]] = max(0, query(0, h[i],tree,len(dp),"max")) + a[i]
            ans = max(dp[h[i]],ans)
            tree = updateTreeNode(h[i], dp[h[i]],tree,len(dp),"max")
            # print(h[i],tree)

    print(ans)
if __name__== "__main__":
	main()