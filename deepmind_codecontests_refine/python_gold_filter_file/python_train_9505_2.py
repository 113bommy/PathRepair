import sys,os,io
from collections import defaultdict
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
input = sys.stdin.readline
for _ in range (int(input())):
    n,m = [int(i) for i in input().split()]
    grid = []
    for i in range (n):
        grid.append(list(input().strip()))
    a,b = 0,0
    flag = 0
    for i in range (n):
        for j in range (n):
            if i==j:
                continue
            if grid[i][j]==grid[j][i]:
                a,b=i+1,j+1
                flag = 1
                break
    if flag==1:
        ans = []
        for i in range (m+1):
            if i%2:
                ans.append(a)
            else:
                ans.append(b)
        print("YES")
        print(*ans)
        continue
    elif m%2:
        ans = []
        for i in range (m+1):
            if i%2:
                ans.append(1)
            else:
                ans.append(2)
        print("YES")
        print(*ans)
    else:
        if n==2:
            print("NO")
            continue
        a,b,c,d = 0,0,0,0
        if grid[0][1]==grid[1][2]:
            a = 0
            b = 1
            c = 2
        elif grid[1][2]==grid[2][0]:
            a=1
            b=2
            c=0
        elif grid[2][0]==grid[0][1]:
            a = 2
            b = 0
            c = 1
        a+=1
        b+=1
        c+=1
        if m%4==0:
            ans = []
            for i in range (m+1):
                if i%4==0:
                    ans.append(b)
                elif i%4==1:
                    ans.append(c)
                elif i%4==2:
                    ans.append(b)
                elif i%4==3:
                    ans.append(a)
            print("YES")
            print(*ans)
            continue
        else:
            ans = []
            print("YES")
            for i in range (m+1):
                if i%4==0:
                    ans.append(a)
                elif i%4==1:
                    ans.append(b)
                elif i%4==2:
                    ans.append(c)
                elif i%4==3:
                    ans.append(b)
            print(*ans)