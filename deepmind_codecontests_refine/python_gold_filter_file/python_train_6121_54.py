n=int(input())
a=list(map(int,input().split()))
b=[0 for i in range(n)]
for j in range(n):
    b[a[j]-1]=j+1
print(*b)