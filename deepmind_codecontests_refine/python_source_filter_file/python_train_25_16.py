import sys
input = sys.stdin.readline
import math
for _ in range(int(input())):
    n = int(input())
    lis=[]
    for i in range(n):
        tmp = list(input())
        lis.append(tmp)
    #print(lis[0][1],lis[1][0],lis[n-2][n-1],lis[n-1][n-2])
    if lis[0][1]==lis[1][0]:
        if lis[n-1][n-2]==lis[n-2][n-1]:
            if lis[0][1]!=lis[n-1][n-2]:
                print(0)
            else:
                print(2)
                print(1,2)
                print(2,1)
        else:
            print(1)
            if lis[n-1][n-2]!=lis[1][0]:
                print(n-1,n)
            else:
                print(n,n-1)
    else:
        if lis[n-1][n-2]==lis[n-2][n-1]:
            print(1)
            if lis[n-1][n-2]!=lis[1][0]:
                print(1,2)
            else:
                print(2,1)
        else:
            print(2)
            if lis[0][1]=='1':
                print(1,2)
            if lis[1][0]=='1':
                print(2,1)
            if lis[n-1][n-2]=='1':
                print(n,n-1)
            if lis[n-2][n-1]=='1':
                print(n-1,n)
            
                
    
            
                     
        
