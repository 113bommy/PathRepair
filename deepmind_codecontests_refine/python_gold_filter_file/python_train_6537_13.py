n = int(input())
b = list(map(int,input().split()))
a = b[0]
for i in range(1,n-1):
    a +=min(b[i-1],b[i])
a += b[n-2]
print(a)