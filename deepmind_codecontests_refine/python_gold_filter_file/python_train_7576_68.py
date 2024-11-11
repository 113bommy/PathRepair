from fractions import gcd

N = int(input())
A = list(map(int, input().split()))
res = 0

l = A[0]
for i in range(1, N):
    l = l * A[i] // gcd(l, A[i])

for a in A:
    res += l//a

print(res % 1000000007)