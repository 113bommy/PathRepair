N=int(input())
A=list(map(int,input().split()))
arrN=[0]*N
for i in range(N):
    arrN[A[i]-1]=i+1
print(*arrN)