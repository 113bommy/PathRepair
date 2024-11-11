n=int(input())
l=list(map(int ,input().split()))
k=0
for i in range(n):
    k+=l[i]

print((k/n))