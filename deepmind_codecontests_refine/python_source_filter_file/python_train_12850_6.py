from collections import defaultdict
def dfs(d,visited,l,i):
    visited[i]=True
    for j in d[i+1]:
        if(not visited[j-1]):
            dfs(d,visited,l,j-1)
    l.append(i+1)
def dfs1(d,visited,x,i):
    visited[i-1]=True
    x.add(i)
    for j in d[i]:
        if(not visited[j-1]):
            dfs1(d,visited,x,j)
def main():
    n=int(input())
    a=list(map(int,input().split()))
    d=defaultdict(list)
    d1=defaultdict(list)
    for i in range(int(input())):
        u,v=list(map(int,input().split()))
        d[u].append(v)
        d1[v].append(u)
    l=[]
    visited=[False]*n
    for i in range(n):
            if(not visited[i]):
                dfs(d,visited,l,i)
    visited=[False]*n
    l1=[]
    # l=l[::-1]
    # print(l)
    while(l):
        i=l.pop()
        if(not visited[i-1]):
            x=set()
            dfs1(d1,visited,x,i)
            l1.append(x)
    cost,ways=0,1
    for i in l1:
        x=list(i)
        z=a[min(x,key=lambda x: a[x-1])-1]
        cost=(cost+z)
        y=0
        for i in x:
            if(a[i-1]==z):
                y+=1
        ways=(max(y,1)*ways)%(10**9+7)
    print(cost,ways)
import sys,threading
max_recur_size = 10**5+ 10000
max_stack_size = max_recur_size*50
sys.setrecursionlimit(max_recur_size)
threading.stack_size(max_stack_size)
thread = threading.Thread(target=main)
thread.start()