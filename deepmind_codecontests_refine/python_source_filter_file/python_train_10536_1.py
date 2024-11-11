MOD = 1000000007
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
for _ in range(ii()):
    a=[]
    s=input("")
    l=s.count('L')
    r=s.count('R')
    u=s.count('U')
    d=s.count('D')
    n=min(l,r)
    p=min(u,d)
    for i in range(0,n):
        a.append('L')
    for i in range(0,p):
        a.append('U')
    for i in range(0,n):
        a.append('R')
    for i in range(0,p):
        a.append('D')
    if(l==0):
        if(u==0):
            print(0)
        else:
            print(2)
            print("UD")
    else:
        if(u==0):
            print(2)
            print("LR")
        else:
            print(len(a))
            print(''.join(a))
    