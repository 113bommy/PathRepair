T = int(input())
def m(A):
    # print(A)
    if len(A)<=1:
        return(A)
    else:
        mi = min(A)
        a = A.index(mi)
        if a==0:
          return([mi]+m(A[a+1:]))
        return([mi]+A[:a-1]+m([A[a-1]]+A[a+1:]))
for i in range(T):
    n = int(input())
    A = [int(i) for i in input().strip().split()]
    A = m(A)
    print(' '.join([str(a) for a in A]))

