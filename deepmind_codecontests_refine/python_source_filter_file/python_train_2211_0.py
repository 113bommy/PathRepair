import os
import sys
input = sys.stdin.buffer.readline
#sys.setrecursionlimit(int(3e5)) 
from collections import deque
from queue import PriorityQueue
import math
import copy
#  list(map(int, input().split()))
#####################################################################################

class CF(object):    
    def __init__(self):
        self.n = int(input())
        self.g = [[] for _ in range(self.n)]
        self.v = [[] for _ in range(self.n)]
        self.r = []                            # last order path    
        self.f = [-1] * self.n
        self.vis = [0] * self.n             
        for _ in range(self.n-1):
            x, y = list(map(int, input().split()))
            x-=1
            y-=1
            self.v[x].append(y)
            self.v[y].append(x)
        pass      
        self.g = copy.deepcopy(self.v)    
        self.dp = [[0,0] for _ in range(self.n)]
        self.leaf = [0] * self.n
        for i in range(self.n):
            if(len(self.g[i]) == 1):
                self.leaf[i] = True
        pass

    def dfs(self, root=0): # last order path    
        s = [root]
        v = [self.g[root]]        
        self.vis[root] = 1
        while(len(s)> 0):
            if(v[-1] == []):
                v.pop()                
                self.r.append(s.pop())
            else:
                now = v[-1].pop()
                if(not self.vis[now]):
                    self.vis[now] = 1
                    self.f[now] = s[-1]
                    s.append(now)
                    v.append(self.g[now])
        pass
    

    def update(self, temp, x):
        temp.append(x)
        for i in range(len(temp)-1)[::-1]:
            if(temp[i+1]> temp[i]):
                temp[i+1], temp[i] = temp[i], temp[i+1]                
        pass
        return temp[:2]                


    def main(self):
        self.dfs()
        ans = 0
        for now in self.r:
            if(self.leaf[now]):
                self.dp[now][1] = 1
                self.dp[now][0] = 0
            else:
                temp = []
                t2 = []
                for to in self.v[now]:
                    if(to != self.f[now]):
                        #temp = max(temp, self.dp[to][0])
                        temp = self.update(temp, self.dp[to][0])
                        t2 = self.update(t2, max(self.dp[to][1], self.dp[to][0]))
                        #t2 = max(t2, max(self.dp[to][1], self.dp[to][0]))
                pass
                self.dp[now][1] = temp[0] + 1                 
                self.dp[now][0] = t2[0] + len(self.v[now])-1-1
                ans = max(ans, 1+sum(temp))
                ans = max(ans, len(self.v[now]) - 1 - len(t2) + sum(t2))
        pass        
        ar = []
        for to in self.v[0]:
            ar.append(self.dp[to][0])
        ar.sort()
        if(len(ar)>=2):
            ans = max(ans, 1+ar[-1]+ar[-2])
        else:
            ans = max(ans, 1+ar[-1])
        
        ar = []
        for to in self.v[0]:
            ar.append(max(self.dp[to][1], self.dp[to][0]))
        ar.sort()
        for i in range(len(ar)-2):
            ar[i] = 1
        ans = max(ans, sum(ar))
        print(ans)
        pass

        # print(self.dp)
        # print(self.leaf)
        # print(self.r)
        # print(self.f)

if __name__ == "__main__":
    cf = CF()
    cf.main()
    pass
    


