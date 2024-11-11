import sys
import math
def II():
	return int(sys.stdin.readline())
 
def LI():
	return list(map(int, sys.stdin.readline().split()))
 
def MI():
	return map(int, sys.stdin.readline().split())
 
def SI():
	return sys.stdin.readline().strip()
t = II()
for q in range(t):
    n = II()
    a = LI()
    s = sum(a)
    if len(set(a)) == 0:
        print(0)
        continue
    if s%n == 0:
        ans = []
        for i in range(1,n):
            if a[i]%(i+1)!=0:
                ans.append([1,i+1,i+1-a[i]%(i+1)])
            ans.append([i+1, 1, math.ceil(a[i]/(i+1))])
            a[i]%=(i+1)
        b = s//n
        for i in range(1,n):
            ans.append([1, i+1, b-a[i]])
            a[0]-=b
        l = len(ans)
        print(len(ans))
        for i in ans:
            print(*i)
    else:
        print(-1)
'''1
8
0 0 8 0 0 0
6 0 2 0 0 0
'''
