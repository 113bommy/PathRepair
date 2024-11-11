n = str(input())
lis = [0 for i in range(26)]
ans = 1
for i in range(1,len(n)+1):
  ans += i
  lis[ord(n[i])-"a"] += 1
for i in range(26):
  for k in range(lis[i]-1):
    ans -= (k+1)
print(ans)