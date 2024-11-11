A=[int(input()) for _ in range(6)]
m=min(A[1:])
print((A[0]+m-1)//m+4)