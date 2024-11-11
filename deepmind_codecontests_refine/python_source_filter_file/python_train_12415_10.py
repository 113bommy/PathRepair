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
 
 
 
 
def pr_list(a):
    print(*a, sep=" ")
def main():
    tests =  inp()
    # tests = 1
    mod = 1000000007
    limit = 10**18
    ans = 0
    for test in range(tests):
        n = inp()
        a = inlt()
        def find_mse(arr,n):
            hashm = {}
            for i in arr:
                hashm[i] = 1
            for i in range(n):
                if i not in hashm:
                    return i
            return n
        ans = []
        while(True):
            mse = find_mse(a,n)
            if mse!= n:
                a[mse] = mse
                ans.append(mse)
                continue
            flag = 0
            for i in range(n):
                if a[i] != i:
                    a[i] = n
                    ans.append(i)
                    flag = 1
                    break
            if flag == 0:
                break
        print(len(ans))
        pr_list(ans)



        

        #     print("NO")
        #     continue
        
        # def find_sides (grid,i,j,n,m):
        #     k = [-1,1]
        #     side = 0
        #     for x in k:
        #         if i+x >=0 and i+x<n:
        #             side = side + (grid[i+x][j]>0) 
 
        #         if j+x >=0 and j+x<m:
        #             side = side + (grid[i][j+x]>0)                
        #     return side
 
             
        # for i in range(0,n):
        #     for j in range(0,m):
            
        #         if grid[i][j] == 0:
        #             continue
        #         sides = find_sides (grid,i,j,n,m)
        #         if sides == grid[i][j]:
        #             continue
        #         if sides >grid[i][j]:
        #             grid[i][j] = sides
        #             # continue
        #         left = grid[i][j] - sides
        #         for x in [+1,-1]:
        #             if i+x >=0 and i+x<n and grid[i+x][j] == 0 and left > 0: 
        #                 grid[i+x][j] = 1
        #                 left = left -1
        #             if j+x >=0 and j+x<m and grid[i][j+x] == 0 and left > 0: 
        #                 grid[i][j+x] = 1
        #                 left = left -1
        #         if left >0:
        #             flag =1
        #         # print(i,j,left)
        # if flag == 1:
        #     print("NO")
        # else:
        #     print("YES")
        #     for i in range(n):
        #         pr_list(grid[i])
                
                        
 
            
 
    
 
 
 
        
 
#  YES
# 2 3 3 2
# 2 4 4 3
# 1 3 4 3
# 2 3 3 2

# YES
# 2 3 3 2 
# 3 4 4 3 
# 3 4 4 3 
# 2 3 3 2 
        
 
 
 
 
 
 
 
 
            
 
            
 
 
 
 
if __name__== "__main__":
	main()