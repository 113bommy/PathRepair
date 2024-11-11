n=int(input())
A=list(map(int,input().split()))
x=abs(A[0])
for i in range(1,n):
    x+=abs(A[i]-A[i-1])
print(x)