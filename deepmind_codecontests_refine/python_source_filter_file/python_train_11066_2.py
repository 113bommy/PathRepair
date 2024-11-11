import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n=int(input())

    AA=[]
    for i in range((n+2)//2,n):
        AA.append((1,i))
    for i in range((n+2)//2-1,0,-1):
        AA.append((i,n))
        
    L=list(range(1,n+1))
    sc=0

    for x,y in AA[::-1]:
        L[x-1],L[y-1]=L[y-1],L[x-1]
        sc+=(x-y)**2

    print(sc)
    print(*L)
    print(len(AA))
    for x,y in AA:
        if L[x-1]!=x:
            print(y,x)
        else:
            print(x,y)
        L[x-1],L[y-1]=L[y-1],L[x-1]
