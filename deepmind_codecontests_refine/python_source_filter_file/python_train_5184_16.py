MOD = 10**9+7
N = int(input())
A = list(map(int, input().split()))
C = [0] * 100000
C[0] = 3
答 = 1
for x in A:
  答 *= C[x]
  答 %= MOD
  C[x] -= 1
  C[x+1] += 1
print(答)
