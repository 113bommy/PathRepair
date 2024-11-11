N=int(input())
A=list(map(int,input().split()))

A.sort()
if A[-1]-A[0]>1:
    print('No')
else:
    if A[-1]-A[0]==1:
        n=A.count(A[0])
        m=A.count(A[-1])
        kind=A[-1]-n
        if m>=2*kind and kind!=0:
            print('Yes')
        else:
            print('No')
    else:
        if A[0]==N-1:
            print('Yes')
        else:
            if N>=2*A[0]:
                print('Yes')
            else:
                print('No')