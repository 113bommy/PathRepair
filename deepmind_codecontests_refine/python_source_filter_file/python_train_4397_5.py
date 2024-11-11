t = int(input())
ans1,ans2,ns=[],[],[]
for i in range(t):
    n=int(input())
    ns.append(n)
    x,y,aas,bbs=[],[],[],[]
    aas=[int(a) for a in input().split()]
    bbs=[int(a) for a in input().split()]
    aas.sort
    bbs.sort
    x,y=sorted(aas),sorted(bbs)
    ans1.append(x)
    ans2.append(y)
    s1,s2=str(),str()
for i in range(t):
    for j in range(ns[i]):
        print(ans1[i][j], end=' ')
    print('', end='\n')
    for j in range(n):
        print(ans2[i][j], end=' ')
    print('\n')