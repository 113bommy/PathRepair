n=int(input())
a=list(map(int,input().split()))
b=[None for _ in range(n)]
for i,j in enumerate(a):b[j-1]=i
print(*[20001*i+b[i] for i in range(n)])
print(*[20001*(n-i) for i in range(n)])