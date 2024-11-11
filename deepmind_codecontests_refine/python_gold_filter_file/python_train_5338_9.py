N = int(input())
A = list(map(int, input().split()))
print((N-1)//2)
A.sort(reverse=True)
left = 0
right = N-1
B = [0]*N
cnt = 0
while cnt<N:
  B[cnt] = A[left]
  left += 1
  cnt += 1
  if cnt==N:
    break
  B[cnt] = A[right]
  right -= 1
  cnt += 1
print(*B)
