import sys, threading
from math import inf
input = sys.stdin.readline
def put():
    return map(int, input().split())

def dfs(tree,i, sum, p):
    if len(tree[i])==1 and i!=0:
        return 1
    cnt=0
    for j,w,c in tree[i]:
        if j!=p:
            z=dfs(tree,j, sum+w, i)
            cnt+=z
            if c==1:one.append((w, z))
            else:   two.append((w, z))
    return cnt

def solve():
    t = int(input())
    for _ in range(t):
        n, w = put()
        tree = [[] for i in range(n)]
        for i in range(n-1):
            x,y,z,c = put()
            x,y = x-1,y-1
            tree[x].append((y,z,c))
            tree[y].append((x,z,c))

        dfs(tree, 0,0,-1)
        s,flag  = 0, True
        diffone, difftwo = [],[]
        for arr in [one, two]:
            for i in range(len(arr)):
                s+= arr[i][0]*arr[i][1]
            while arr:
                i,j = arr.pop()
                while i>0:
                    if flag:
                        diffone.append((i-i//2)*j)
                    else:
                        difftwo.append((i-i//2)*j)
                    i//=2
            flag = False

        diffone.sort(reverse=True)
        difftwo.sort(reverse=True)
        s,cnt=s-w, inf
        for i in difftwo:
            s-= i
        p,q = len(diffone), len(difftwo)
        i,j=q-1,0
        while i>=-1:
            while s>0 and j<p:
                    s-=diffone[j]
                    j+=1
            if s<=0:
                cnt = min(cnt, 2*i+j+2)
            if i>-1:
                s+= difftwo[i]
            i-=1
        print(cnt)


one,two = [],[]
max_recur_size = 10**5*2 + 1000
max_stack_size = max_recur_size*500
sys.setrecursionlimit(max_recur_size)
threading.stack_size(max_stack_size)
thread = threading.Thread(target=solve)
thread.start()
