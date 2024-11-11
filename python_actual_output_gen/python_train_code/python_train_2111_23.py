n = int(input())
a = list(map(int, input().split()))
ans = [0] * n
for i in range(n):
    x[a[i]-1]=i+1
print(*x)