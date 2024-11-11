N = int(input())
A = list(map(int,input().split()))
sum = 0
cnt_two = 0
for i in range(N):
  if A[i] % 4 == 0:
    sum += 1
  elif A[i] % 2 == 0:
    cnt_two += 1
print("Yes" if sum + cnt_two // 2 >= N // 2 else "No")