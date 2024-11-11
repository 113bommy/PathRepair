N=int(input())
a=list(map(int,input().split()))
b=[0]*N
for i in range(N):
    b[a[i]-1]=i+1

print(*b)
