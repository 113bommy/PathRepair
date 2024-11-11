N = int(input())
for i in range(int(N**0.5+1)):
  if N % i == 0:
    ans = i + N // i - 2
print(ans)