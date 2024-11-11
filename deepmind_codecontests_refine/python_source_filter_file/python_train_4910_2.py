import sys
n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

if max(B)==0:
    print(n)
    sys.exit()

if 1 in B:
    x=B.index(1)
    y=n-x+1

    for i in range(x,n):
        if B[i]!=i-x+1:
            break

    else:
        for i in range(x):
            if B[i]>0 and B[i]-y-i<=0:
                break

        else:
            print(x)
            sys.exit()


ANS=-100
for i in range(n):
    if B[i]!=0:
        ANS=max(ANS,i-B[i])

print(ANS+n+2)
