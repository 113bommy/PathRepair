n = int(input())
b = list(map(int,input().split()))
a = 0
for i in range(n-1):
    a += min(b[i],b[i+1])
a += b[n-2]
print(a)