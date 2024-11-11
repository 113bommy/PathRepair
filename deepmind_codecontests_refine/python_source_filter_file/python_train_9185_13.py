def g(A,i,y,move):
    n = min(i,y-2)
    A[n-1],A[n],A[n+1] = A[n+1],A[n-1],A[n]
    move.append(max(1,n))
    
def f(A,x,y,move):
    i = A.index(x)+1
    while i<y:
        g(A,i,y,move)
        i+=1
    
for tc in range(int(input())):
    n = int(input())
    A = input().split(' ')
    B = []
    S = []
    Amove = []
    Bmove = []
    for i in range(n):
        A[i] = int(A[i])
        B.append(A[i])
        S.append(A[i])
    S.sort()
    dupin = -1
    for i in range(n-1):
        if S[i] == S[i+1]:
            dupin = i
            break
    if dupin == -1:
        for i in range(n-2):
            f(A,S[n-i-1],n-i,Amove)
        if A[0]>A[1]:
            print(-1)
        else:
            print(len(Amove))
            for i in Amove:
                print(i,end = ' ')
            print()
    else:
        for i in range(n-2):
            f(A,S[n-i-1],n-i,Amove)
        if A[0]<=A[1]:
            print(len(Amove))
            for i in Amove:
                print(i,end = ' ')
            print()
            continue
        elif A[0] == A[2]:
            Amove.append(1)
            Amove.append(1)
            print(len(Amove))
            for i in Amove:
                print(i,end = ' ')
            print()
            continue
        else:
            for i in range(n-2):
                f(B,S[n-i-1],n-i,Bmove)
                if n-i-1 == dupin:
                    g(B,n-i-2,n,Bmove)
                    g(B,n-i-3,n,Bmove)
            print(len(Bmove))
            for i in Bmove:
                print(i,end = ' ')
            print()
            
