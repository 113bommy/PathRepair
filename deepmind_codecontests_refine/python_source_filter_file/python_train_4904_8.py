import math 
n=int(input())
S1=list()
S2=list()
if(n<3):
    print("NO")
else:
    k=0
    if(n%2==0):
        k=n//2
    else:
        k=(n+1)//2
    S2.append(k)
    for i in range(1,n+1):
        if(i!=k):
            S1.append(i)
    print("YES")
    print(len(S2),end=' ')
    print(' '.join(map(str,S2)))
    print(len(S1),end=' ')
    print(' '.join(map(str,S1)))
