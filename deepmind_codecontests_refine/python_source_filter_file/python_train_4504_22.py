import math
from collections import Counter,deque,defaultdict
L=lambda:list(map(int,input().split()))
M=lambda:map(int,input().split())
I=lambda:int(input())
IN=lambda:input()
mod=10**9+7
def s(a):print("".join(list(map(str,a))))
#______________________-------------------------------_____________________#
def solve():
    n,m=M()
    a=[]
    for i in range(n):
        a.append(L())
    for i in range(n):
        for j in range(m):
            if (i==0 and j==0) or (i==0 and j==m-1) or (i==n-1 and j==0) or (i==n-1 and j==m-1):
                if a[i][j]>2:
                    print("NO")
                    return
                else:
                    a[i][j]=2
            elif i==0 or i==n-1 or j==0 or j==m-1:
                if a[i][j]>3:
                    print("NO")
                    return
                else:
                    a[i][j]=3
            else:
                if a[i][j]>4:
                    print("NO")
                    return
                else:
                    a[i][j]=4
    print("YES")
    for i in range(n):
        s(a[i])
for _ in range(I()):
    solve()
