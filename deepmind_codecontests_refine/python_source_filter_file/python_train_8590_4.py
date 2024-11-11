#!/usr/bin/python3

def read_ints():
    return list(map(int, input().split()))

def make_path(start, length):
    global cur
    
    print(str(start)+" "+str(cur))
    if cur>n: return
    
    if length>1:
        for i in range(length-1):            
            if cur+1>n: 
                cur+=1
                return
            print(str(cur)+" "+str(cur+1))
            cur+=1
        cur+=1
    else:
        cur+=1

cur = 2

(n,d,h)=read_ints()

if h >= n or d >= n or d < h or d-h>h or d==1 and n>1:
    print(-1)
    exit()

make_path(1,h)

branch_length = d - h 

if branch_length == 0:
    branch_start = 2
else:
    branch_start = 1
        
while cur<=n:
    make_path(branch_start,branch_length)
        
