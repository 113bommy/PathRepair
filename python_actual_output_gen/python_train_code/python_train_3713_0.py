N = int(input())
S = input()

ans = -10000
for i in range(1,N+1):
  ans = max(S[:i].count('I')-S[:i].count('D'),ans)

print(ans)