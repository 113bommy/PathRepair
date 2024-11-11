N = int(input())
p = list(map(int, input().split()))

a = [0] * N
b = [0] * N
for i in range(N):
    a[p[i]-1] = p[i] * 22000 + 25000000
    b[p[i]-1] = -p[i] * 22000 + i + 25000000
print(*a)
print(*b)
