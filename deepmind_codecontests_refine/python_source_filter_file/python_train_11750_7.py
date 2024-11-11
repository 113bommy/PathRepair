S = input()
n = len(S)
ans = 0
for i in range(n):
  a = int(S[i])
  for j in range(n-i):
    ans+=a * 10**j * 2**i * 2**(n-i-j-2)
print(ans)