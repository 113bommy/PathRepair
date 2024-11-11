n,m = map(int,input().split())
A = list(map(int,input().split()))
A.sort(reverse=True)
if A[m]<sum(A)/4/m:
    print('No')
else:
    print('Yes')