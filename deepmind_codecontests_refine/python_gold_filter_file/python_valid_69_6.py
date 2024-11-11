import sys
input = sys.stdin.readline

P=[str(2**i) for i in range(100)]

t=int(input())
for tests in range(t):
    n=input().strip()

    ANS=1<<30

    for p in P:
        ind=0
        for k in n:
            if ind<len(p) and k==p[ind]:
                ind+=1

        #print(n,p,ind)

        ANS=min(ANS,len(n)-ind+len(p)-ind)

    print(ANS)
    
