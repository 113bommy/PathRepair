n = int(input())
a = list(map(int, input().split()))
x = [0]*n
x[0] = sum(a)-(2*sum(a[1:n-1:2]))
for i in range(1, n):
    x[i] = 2*a[i-1]-x[i-1]
print(*x)