N=int(input())
A=list(map(int,input().split()))
x=(N+1)*N//2
a=0 if sum(A)%x else 1
d=sum(A)//x
y=0
for i in range(N):
    if (A[i]-A[i-1])%N!=d%N or A[i]-A[i-1]>d:
        a=0
    else:
        y-=(A[i]-A[i-1]-d)//N
print(['NO','YES'][a and y==d])