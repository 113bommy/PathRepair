N=int(input())
A=list(map(int,input().split()))

O=[0]*N

for i in range(N):
    O[A[i]-1]=i+1

print(*O)
