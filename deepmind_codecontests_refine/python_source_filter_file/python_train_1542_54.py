N = int(input())
*A, = map(int, input().split())
b = [0] * N
for i in range(N-1, -1, -1):
   chk = sum(b[i:N:i+1])
   if chk ^ A[i]:
       b[i] = 1

print(sum(b))
ans = []
for i, v in enumerate(b):
    if v == 1:
        ans.append(i+1)
print(*ans)