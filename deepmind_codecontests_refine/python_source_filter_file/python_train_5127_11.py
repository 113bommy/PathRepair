import math
t=int(input())
for i in range(t):
    n,k=[int(n) for n in input().split()]
    div=0
    if(n%2==0):
        n=n+2
    else:
        for j in range(3,int(math.sqrt(n)),2):
            if(n%j==0):
                div=j
                break
            else:
                continue
        if(div==0):
            div=n
        n=n+div
    k=k-1
    if(k>0):
        n=n+2*(k)
    print(n)    