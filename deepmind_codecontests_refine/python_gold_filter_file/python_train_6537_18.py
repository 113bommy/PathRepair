N = int(input())
B = list(map(int, input().split()))

S = B[0] + B[-1]

for i in range(0, N-2):
  S += min(B[i], B[i+1])

print(S)