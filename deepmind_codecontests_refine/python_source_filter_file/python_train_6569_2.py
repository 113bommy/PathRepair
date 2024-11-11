from collections import *

def li():return [int(i) for i in input().rstrip('\n').split(' ')]
def st():return input().rstrip('\n')
def val():return int(input())



n, h = li()
l = []
for i in range(n):l.append(li())
l.sort()
ans = h + l[0][1] - l[0][0]
d = deque()
d.append(l[0])
currrem = h
currdist = l[0][1] - l[0][0]


for i in range(1,n):

    cant = 0
    while currrem < l[i][0] - l[i-1][1]:
        if cant:break
        a,b = d.popleft()
        if len(d):
            currrem += d[0][0] - b
            currrem = min(currrem,h)
            currdist -= d[0][0] - a
        else:
            if l[i][0] - b <= h:
                d.append(l[i-1])
                break
            cant = 1
            currrem = h
            currdist = 0
    currdist += l[i][1] - l[i][0]
    if len(d):
        currdist += l[i][0] - d[-1][1]
        currrem -= l[i][0] - d[-1][1]
    d.append(l[i])
    ans = max(ans,currdist + currrem)
print(ans)
