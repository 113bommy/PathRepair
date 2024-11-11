#!/usr/bin/env pypy3
def I(): return int(input())
def MI(): return map(int, input().split())
def LI(): return list(map(int, input().split()))

def main():
    mod=10**9+7
    N=I()
    f=[1]*N#根が白
    g=[1]*N
    
    adj=[[]for _ in range(N)]
    for i in range(N-1):
        x,y=MI()
        x-=1
        y-=1
        adj[x].append(y)
        adj[y].append(x)
        
    Ld=[[]for _ in range(N)]#深さ別
    Lp=[0]*N
    Md=0#最深部
    
    import queue
    
    q=queue.Queue()
    q.put((0,-1,0))#v,p,d
    
    while not q.empty():
        v,p,d=q.get()
        Ld[d].append(v)
        Lp[v]=p
        Md=max(d,Md)
        for i in range(len(adj[v])):
            nv=adj[v][i]
            if nv!=p:
                q.put((nv,v,d+1))
                

        
    for i in range(Md-1,-1,-1):
        for j in range(len(Ld[i])):
            v=Ld[i][j]
            tempf=1
            tempg=1
            for k in range(len(adj[v])):
                pv=adj[v][k]
                if pv!=Lp[v]:
                    tempf*=(f[pv]+g[pv])
                    tempg*=f[pv]
                    tempf%=mod
                    tempg%=mod
                
            f[v]=tempf
            g[v]=tempg
            
    print((f[0]+g[0])%mod)

                
    

main()
