import sys
def input():
    return sys.stdin.readline().strip()
 
 
def iinput():
    return int(input())
 
 
def tinput():
    return input().split()
 
 
def rinput():
    return map(int, tinput())
 
 
def rlinput():
    return list(rinput())

n,x0 = rinput()
left = []
right = []
for _ in range(n):
    l,r = rinput()
    left.append(min(l,r))
    right.append(max(l,r))
left.sort(reverse = True)
right.sort()
m = left[0]
M =  right[0]

if m > M:
    print(-1)
elif x0 < m:
    print(m-x0)
elif x0 >= m and x0 <= M:
    print(0)
else:
    print(M-x0)
