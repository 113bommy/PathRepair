n=int(input())
p=list(map(int,input().split()))
print(*[30000*i for i in range(n)])
b=[30000*(n-i-1)for i in range(n)]
for i in range(n):
    b[p[i]-1]+=i
print(*b)