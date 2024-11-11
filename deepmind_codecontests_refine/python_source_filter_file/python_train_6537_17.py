n = int(input())
b = list(map(int,input().split()))
a = 0
for i in range(n-1):
    a += min(b[i-1],b[i])
a += b[n-2]
print(a)