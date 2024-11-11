import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n=int(input())
    A=list(map(int,input().split()))

    MAX=-1<<30
    ANS=0

    for a in A:
        MAX=max(MAX,a)
        if a<MAX:
            ANS=max(ANS,MAX-a)

    #print(ANS)

    if ANS==0:
        print(0)
        continue

    for i in range(100):
        if (1<<i)>=ANS:
            print(i+1)
            break
