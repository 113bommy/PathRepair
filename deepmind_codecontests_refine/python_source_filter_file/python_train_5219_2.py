from sys import stdin,stdout
from collections import defaultdict
import sys, threading
#sys.setrecursionlimit(10**6) # max depth of recursion
threading.stack_size(2**25)
def main():
    def power(x, p):
        re = 1
        mode= 998244353
        while p:
            if p & 1:
                re = re * x % mode
            x = x * x % mode
            p >>= 1
        return re;

    def dfs(node,col):
        visited[node]=True
        c[col]+=1
        color[node]=col
        for j in dic[node]:
            if not visited[j]:
                if not dfs(j, col ^ 1):
                    return False
            else:
                if color[j]==color[node]:
                    return False
        return True


    t=int(stdin.readline())
    for _ in range(t):
        mod=998244353
        n,m=map(int,stdin.readline().split())
        dic=defaultdict(list)
        for i in range(m):
            u,v=map(int,stdin.readline().split())
            dic[u].append(v)
            dic[v].append(u)
        visited=[False]*(n+1)
        color=[-1]*(n+1)
        c=[0]*2
        result=1
        flag=0
        #print(dic)
        for i in range(1,n+1):
            if not visited[i]:
                res=dfs(i,0)
                if not res:
                    flag=1
                    break
                else:
                    result=(result*(power(2,c[0])+power(2,c[1])))%mod
                    c[0]=0
                    c[1]=0
        if flag==1:
            stdout.write("0\n")
        else:
            stdout.write(str(result)+"\n")
threading.Thread(target=main).start()



