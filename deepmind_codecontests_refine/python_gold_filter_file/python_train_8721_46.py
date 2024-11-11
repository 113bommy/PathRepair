n,m=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
B=A[::-1]
if B[m-1]>=sum(A)/(4*m):
    print("Yes")
else:
    print("No")