N = int(input())
A = [list(map(str, input().split())) for i in range(N)]
S = input()
i = 0
while A[i][0] != S:
  i += 1
print(sum(int(A[j][1]) for j in range(i + 1, N))