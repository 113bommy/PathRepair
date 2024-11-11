#from collections import deque
y,k,n = map(int,input().split())
start = ((y+k-1)//k)*k
if start == y: start +=k
if start > n:
    print (-1)
else:
    print (" ".join(str(x-y) for x in range(start,n+1,k)))