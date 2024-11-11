#TO MAKE THE PROGRAM FAST

''' ----------------------------------------------------------------------------------------------------  '''
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000000)
from collections import *
''' ----------------------------------------------------------------------------------------------------  '''




#FOR TAKING INPUTS

''' ----------------------------------------------------------------------------------------------------  '''
def li():return [int(i) for i in input().rstrip('\n').split(' ')]
def val():return int(input().rstrip('\n'))
def st():return input().rstrip('\n')
def sttoli():return [int(i) for i in input().rstrip('\n')]
''' ----------------------------------------------------------------------------------------------------  '''


visited = {}
def giveind(b,c):
    for _____ in range(3):
        if b != _____ and c != _____:return _____

def dfs(a,d,prev,temp):
    global visited
    q = deque()
    q.append([a,prev[0],prev[1]])
    while q:
        root,a,b = q.pop()
        if root not in visited:
            visited[root] = 1
            temp[root - 1] = giveind(a,b)
            a, b = b, temp[root - 1]
            for j in d[root]:
                q.append([j,a,b])
    # if a not in visited:
    #     visited[a] = 1
    #     temp[a-1] = giveind(prev[-1],prev[-2])
    #     prev[-1],prev[-2] = temp[a-1],prev[-1]
    #     for j in d[a]:
    #         dfs(j,d,prev,temp)
    

def givecost(c,a):
    tot = 0
    for ind,i in enumerate(a):
        tot+=c[i][ind]
    return tot


#MAIN PROGRAM

''' ----------------------------------------------------------------------------------------------------  '''

n = val()
c1 = li()
c2 = li()
c3 = li()
c = [c1,c2,c3]
d= defaultdict(list)
for i in range(n-1):
    a,b = sorted(li())
    d[a].append(b)
    d[b].append(a)
    if len(d[a]) > 2 or len(d[b]) > 2:
        print(-1)
        exit()
print(d)


pairs = [[0,1],[1,2],[0,2],[1,0],[2,1],[2,0]]
micost = 1000000000001000
temp = [1]*n
ind = [0,1,2]
# print(d)
for i in pairs:
    temp[0] = i[0]
    visited = {}
    visited[1] = 1
    temp[d[1][0]-1] = i[1]
    visited[d[1][0]] = 1

    if len(d[1]) > 1:
        prev = [i[1],i[0]]
        dfs(d[1][1],d,prev,temp)


        prev = prev[::-1]
        if d[d[1][0]][0] != 1:dfs(d[d[1][0]][0],d,prev,temp)
        else:
            try:
                dfs(d[d[1][0]][1],d,prev,temp)
            except:
                afszxgeadgaedvzx =2


    else:
        prev = [i[0],i[1]]
        if d[d[1][0]][0] == 1:
            dfs(d[d[1][0]][1],d,prev,temp)
        else:
            dfs(d[d[1][0]][0],d,prev,temp)


    cost = givecost(c,temp)

    if cost<micost:
        micost = cost
        ans = [i+1 for i in temp]

    

print(micost)
print(*ans)



''' ----------------------------------------------------------------------------------------------------  '''