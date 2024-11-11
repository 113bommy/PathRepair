N=int(input())
A=list(map(int,input().split()))
x=A[0]*N
for i in A:
    x[i-1]+=1
for j in x:
    print(j)