# -*- coding: utf-8 -*-
"""
Created on Sat Jul 14 10:14:13 2018
ALDS1_11_D
@author: maezawa
"""
import sys
sys.setrecursionlimit(100000)

n, m = list(map(int, input().split()))
v = [-1 for _ in range(n)]
stack = []
adj = [[] for _ in range(n)]
for i in range(m):
    s, t = list(map(int, input().split()))
    adj[s].append(t)
    adj[t].append(s)
#print(*adj, sep='\n')
def dfs(u, color):
    if v[u] > 0:
        return 0
    v[u] = color
    #print(u, current, stack)
    for k in adj[u]:
        if v[k] > 0:
            continue
        dfs(k, color)
    return 1

color = 1
for start in range(n):
    if dfs(start, color) == 1:
        color += 1
#for i in range(n):        
#    print('color:{} for node:{}'.format(i, v[i]))

q = int(input())
for i in range(q):
    s, t = list(map(int, input().split()))
    if v[s] == v[t]:
        print('yes')
    else:
        print('no')
