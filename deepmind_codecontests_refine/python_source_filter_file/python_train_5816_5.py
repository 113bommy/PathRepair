def main():
    import heapq
    from sys import stdin
    input=stdin.readline
    xs,ys,xt,yt=map(int,input().split())
    n=int(input())
    xyr=[[xs,ys,0],[xt,yt,0]]+[list(map(int,input().split())) for _ in [0]*n]
    g=[[] for _ in [0]*(n+2)]
    for i in range(n+1):
        x1,y1,r1=xyr[i]
        for j in range(i+1,n+2):
            x2,y2,r2=xyr[j]
            d_temp=max(0,((x1-x2)**2+(y1-y2)**2)**0.5-r1-r2)
            g[i].append((j,d_temp))
            g[j].append((i,d_temp))
    d=[0]*(n+2)
    visit=[False]*(n+2)
    visit[0]=True
    h=[]
    for i,j in g[0]:
        h.append((j,i))
    heapq.heapify(h)
    while h:
        i,j=heapq.heappop(h)
        if visit[j]==True:
            continue
        visit[j]=True
        d[j]=i
        for k,l in g[j]:
            if visit[k]==False:
                heapq.heappush(h,(l+i,k))
    print(d[1])
main()
