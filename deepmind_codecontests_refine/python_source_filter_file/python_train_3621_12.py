import sys
input = sys.stdin.readline

N=int(input())
A=list(map(int,list(input().strip())))

def next(A):
    B=[]
    for i in range(1,len(A)):
        B.append(abs(A[i]-A[i-1]))
    return B

A=next(A)

if len(A)<=5:
    while len(A)>1:
        A=next(A)
    print(A[0])
    sys.exit()

def in2(x):
    if x==0:
        return 0
    ANS=0
    while x%2==0:
        ANS+=1
        x//=2
    return ANS


if not (1 in A):
    LEN=len(A)
    SUM=0
    COMBI=1

    for i in range(LEN):
        if COMBI==0:
            SUM+=A[i]//2

        COMBI=COMBI+in2(LEN-1-i)-in2(i+1)

    if SUM%2==1:
        print(2)
    else:
        print(0)
else:
    LEN=len(A)
    SUM=0
    COMBI=1

    for i in range(LEN):
        if COMBI==0:
            SUM+=A[i]

        COMBI=COMBI+in2(LEN-1-i)-in2(i+1)

    if SUM%2==1:
        print(1)
    else:
        print(0)

