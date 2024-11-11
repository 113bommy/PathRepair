for _ in range(1):
    n=int(input())
    a=list(map(int,input().split()))
    d={}
    b=[4,8,15,16,23,42]
    c=[0]*50
    for i in a:
        if i==4:
            c[i]+=1
        elif c[b.index(i) - 1]>0:
            c[b[b.index(i) - 1]]-=1
            c[i]+=1
            
    print(n- (c[42])*6)
    