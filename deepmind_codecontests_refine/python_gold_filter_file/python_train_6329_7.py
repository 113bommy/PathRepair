n,k = map(int, input().split())
*a, = map(int, input().split())
ans = 0
wer = 0

for i in range(n-1):
  for j in range(i+1, n):
    if a[i] > a[j]:
      ans += 1
ans *= k

for i in range(n):
  for j in range(n):
    if a[i] > a[j]:
      wer += 1
wer *= k*(k-1)//2

ans += wer
ans %= 10**9 + 7
  
print(ans)