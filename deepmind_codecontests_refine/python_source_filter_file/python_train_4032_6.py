MOD = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())

if __name__=="__main__":
    n=ii()
    l=[[] for i in range(n)]
    deg=[0]*n
    for _ in range(n-1):
        a,b=f()
        l[a-1].append(b-1)
        l[b-1].append(a-1)
        deg[a-1]+=1
        deg[b-1]+=1
    mx=max(deg)
    if mx==1:
        print('Yes')
        print(1)
        print(mx,l[mx][0])
        exit()
    if (mx>2 and deg.count(mx)>1) or any(not i in [mx,0,1,2] for i in deg):
        exit(print('No'))
    ind=deg.index(mx)
    path=[]
    for i in range(n):
        if len(l[i])==1:
            path.append(i)
    print('Yes')
    print(len(path))
    for i in path:
        print(ind+1,i+1)
