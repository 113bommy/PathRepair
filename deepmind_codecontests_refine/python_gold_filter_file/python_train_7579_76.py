n,k=map(int,input().split())
h=sorted([int(input())for _ in range(n)])
a=10**9
for i in range(n-k+1):
    a=min(a,h[i+k-1]-h[i])
print(a)