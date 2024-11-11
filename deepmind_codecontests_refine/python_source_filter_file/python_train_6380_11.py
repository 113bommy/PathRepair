import math,sys
t=int(input())
for i in range(t):
    p,q=list(map(int,sys.stdin.readline().strip().split()))
    if p%q!=0:
        print(p)
    else:
        p_fctr=[]
        lim_fctr=int(math.sqrt(q))+1
        Q=q
        i=2
        while Q>1 and i<=lim_fctr:
            while Q%i==0:
                if len(p_fctr)>0 and p_fctr[-1]!=i:
                    p_fctr.append(i)
                Q//=i
            i+=1
        if Q>1:
            p_fctr.append(Q)
        print(p_fctr)
        x=1
        for i in range(len(p_fctr)):
            fctr=p_fctr[i]
            P=p
            while P%q==0:
                P=P//fctr
            print(P)
            x=max(x,P)
        print(x)
    