K = int(input())
r = 7 % K
ans = -1
for i in range(K):
   if r == 0:
      ans = i
      break
   r = 10r + 7
   r = r % K
print(ans)