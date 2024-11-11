N = int(input())
P = list(map(int, input().split()))
geta = 30000

A = [i*geta for i in range(N)]
B = [(N-1-i)*geta for i in range(N)]

for i, p in enumerate(P):
    A[p-1] += i
print(*A)
print(*B)
