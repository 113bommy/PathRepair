import sys
import math
from collections import defaultdict,deque

input = sys.stdin.readline
def inar():
    return [int(el) for el in input().split()]
def main():
    arr=input().strip()
    n=len(arr)
    ans=0
    start,end=0,0
    c1,c2,c3,c4=False,False,False,False
    for i in range(n):
        if arr[i]=="[":
            ans+=i
            start=i+1
            c1=True
            break
    for i in range(n-1,-1,-1):
        if arr[i]=="]":
            ans+=n-i-1
            end=i-1
            c2=True
            break
    for i in range(start,end+1):
        if arr[i]==":":
            ans+=i-start
            start=i+1
            c3=True
            break
    for i in range(end,start-1,-1):
        if arr[i]==":":
            ans+=end-i
            end=i-1
            c4=True
            break
    for i in range(start,end+1):
        if arr[i]!="|":
            ans+=1
    if c1 and c2 and c3 and c4:
        print(ans)
    else:
        print(-1)




if __name__ == '__main__':
    main()



