import sys
input=sys.stdin.readline  #危険！基本オフにしろ！

def BELLMANFORD(point,n,d,p):
    cost       = [-float("inf")]*(n+1)  #infじゃないと閉路検出がうまくいかない
    cost[point]= 0
    for i in range(n-1):                                  #経路の長さは最大n-1であるため
        for nownode,nextnode,c in d:
            if cost[nextnode]<cost[nownode]+c-p:
                cost[nextnode]=cost[nownode]+c-p

    negative=[0]*(n+1)                                        #負閉路の長さは最大nであるため
    
    for i in range(n):                  #閉路判定 negativeの1は閉路に入っている部分を表す
        for nownode,nextnode,c in d:
            if negative[nownode]==1:
                negative[nextnode]=1
            if cost[nextnode]<cost[nownode]+c-p:
                cost[nextnode]=cost[nownode]+c-p
                negative[now]=1
 
    return cost,negative

def main():    
    n,m,p=map(int,input().split())

    d=[tuple(map(int,input().split()))for i in [0]*m]
    
    x,y=(BELLMANFORD(1,n,d,p))
    
    if y[n]==1:
        print(-1)
    else:
        print(max(x[n],0))

    
if __name__ == '__main__':
    main()
