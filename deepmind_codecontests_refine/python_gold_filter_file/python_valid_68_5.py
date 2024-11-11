import math
t = int(input())
for _ in range(t):
    n = int(input())
    row = (math.ceil(math.sqrt(n))//1)
    start = row**2
    flag=1
    for i in range(row-1):
        if start==n:
            print(row,i+1)
            flag=0
            break
        start-=1
    if flag:
        for i in range(row,0,-1):
            if start==n:
                print(i,row)
                break
            start-=1











