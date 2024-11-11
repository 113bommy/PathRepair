n = int(input())
P = list(map(int, input().split()))
Pi = [0] * n
for i, p in enumerate(P):
    Pi[p-1] = i

A = [30000*(i+1) for i in range(n)]
B = [30000*(n-i-1)+pi for i, pi in enumerate(Pi)]

print(' '.join(map(str, A)))
print(' '.join(map(str, B)))
