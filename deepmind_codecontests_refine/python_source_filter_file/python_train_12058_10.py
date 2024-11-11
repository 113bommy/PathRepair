N=int(input())
A=list(input()for i in range(N))
if len(A)==len(set(A):
    if all(A[i][-1]==A[i+1][0]) for i in range(N-1):
        print('Yes')
    else:print('No')
else:print('No')