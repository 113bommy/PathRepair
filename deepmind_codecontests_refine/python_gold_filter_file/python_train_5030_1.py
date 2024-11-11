import sys
input = sys.stdin.readline

def calc(x):
    ANS=0
    for i in range(len(B)):
        ANS+=abs(B[i]-(x+i))
    return ANS

t=int(input())
for tests in range(t):
    n=int(input())
    A=list(input().strip())
    B=[]
    for i in range(n):
        if A[i]=="*":
            B.append(i)

    left=0
    right=n-len(B)

    while right-left>3:
        mid=left+(right-left)//3
        mid2=left+(right-left)*2//3

        c=calc(mid)
        c2=calc(mid2)

        if c==c2:
            left=mid
            right=mid2
        elif c>c2:
            left=mid
        else:
            right=mid2

    ANS=1<<60
    for i in range(left,right+1):
        ANS=min(ANS,calc(i))
    print(ANS)
        
        

    
            
