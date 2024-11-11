N = input()
A = [int(x) for x in input().split()]

answer = 0
for i in range(1,N):
  if A[i] == A[i-1]:
    A[i] = -1
    answer += 1
print(answer)