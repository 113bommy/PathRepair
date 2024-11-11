n=int(input())
L=list(map(int,input().split()))
LL=[0]*n
for i in range(n):
    LL[L[i]-1]=i+1
print(*LL)