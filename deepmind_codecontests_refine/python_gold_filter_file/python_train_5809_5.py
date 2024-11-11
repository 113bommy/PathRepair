N, M = map(int, input().split())
a = [10**18] + sorted(map(int, input().split()), reverse=True)


def solve(x):
   count = 0
   j = N
   for i in range(1, N+1):
      while a[i] + a[j] < x:
         j -= 1
      count += j
   
   return count


left, right = 0, 10**18
while left < right - 1:
   mid = (left + right) // 2
   if solve(mid) >= M:
      left = mid
   else:
      right = mid

acc = a[:]
acc[0] = 0
for i in range(N):
   acc[i+1] += acc[i]

ans = 0
j = N
for i in range(1, N+1):
   while a[i] + a[j] < left+1:
      j -= 1
   ans += a[i]*j + acc[j]
   M -= j

if M:
   ans += left * M

print(ans)