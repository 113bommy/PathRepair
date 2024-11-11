import sys
# import heapq
from math import ceil,floor



RI = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()
mod = 10**7+1
for _ in range(int(ri())):
    n = int(ri())
    arr = []
    for i in range(n):
        temp = RI()
        temp = [i]+temp[1:]
        arr.append(temp)

    # arr.sort(key = lambda x : len(x))
    # print(arr)
    # print(arr)
    s = set()
    pos = -1
    # flag = True
    outflag = False 
    for i in range(len(arr)):
        # print(s)
        flag = True
        if len(arr[i]) == 1:
            flag = False
            
        for j in range(1,len(arr[i])):
            if arr[i][j] not in s:
                s.add(arr[i][j])
                flag = False
                break
        if not flag and not outflag :
            pos = arr[i][0]
            outflag = True
    
    lis = [i for i in s]
    # print(lis)
    lis.sort()
    lis  = [0]+lis+[10**10]
    flag = -1
    # print(s)
    for i in range(0,len(lis)-1):
        if lis[i]+1 != lis[i+1]:
            flag = lis[i]+1
            break
    # print(len(lis))
    if len(lis)-2 == n:
        print("OPTIMAL")
    else:
        if flag == -1:
            flag = 1
      
        print("IMPROVE")
        print(pos+1,flag)
                

    

