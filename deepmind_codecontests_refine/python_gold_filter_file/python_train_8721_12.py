n,m=map(int,input().split())
A = sorted(list(map(int,input().split())))[::-1]
s = sum(A)
print('Yes' if A[m-1]>=s/(4*m) else 'No')