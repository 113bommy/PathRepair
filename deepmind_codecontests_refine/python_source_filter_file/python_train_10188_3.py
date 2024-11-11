N = int(input())
P = [int(x) for x in input().split()]

a = [i*N + 1 for i in range(N)]
b = [i*N + 1 for i in reversed(range(N))]

for i in range(N) :
    a[i] += P[i]

print(*a)
print(*b)
