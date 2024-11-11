n=int(input())
A=list(map(int,input().split()))
B=[0]*n
for i in range(n):
    B[A[i]-1]=i+1
print(*B)