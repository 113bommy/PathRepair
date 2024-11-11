N = int(input())
S = input()
count = 0
ans = 1
m = 10**9 + 7
 
for i in range(N):
  if S[2*i] == "W":
    ans = ans * (((2*i) - (count*2))%m)
    count += 1
  if S[2*i + 1] == "B":
    ans = ans * (((2*i + 1) - (count*2))%m)
    count += 1
 
if count != N:
  print(0)
else:
  for o in range(1, N+1):
    ans *= o
    ans %= m
  print(ans % m)