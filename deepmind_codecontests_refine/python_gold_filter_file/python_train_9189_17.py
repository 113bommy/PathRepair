T=int(input())
for i in range(T):
    A=list(map(int,input().split()))
    
    if A[0]==A[2]:
        print(abs(A[1]-A[3]))
    elif A[1]==A[3]:
        print(abs(A[0]-A[2]))
    else:
        print(abs(A[0]-A[2])+abs(A[1]-A[3])+2)