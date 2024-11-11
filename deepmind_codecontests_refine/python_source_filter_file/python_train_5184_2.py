N = int(input)
A = list(map(int, input().split()))
L = [0 for i in range(max(A)+2)]
ans = 1
L[0] = 3
p = 10 ** 9 + 7
for i in range(N):
  ai = A[i]
  ans *= (L[ai] - L[ai + 1])
  ans = ans % p
  L[ai + 1] += 1
print(ans)