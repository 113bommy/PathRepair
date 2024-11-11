n,p = list(map(int,input().split()))
S = input()

if p == 2 or p == 5:
  ans = 0
  for i,s in enumerate(S):
    if int(s)%p == 0:
      ans += i+1
  print(ans)
  exit()

def MS(i,s,pre):
  return (int(s)*i+pre)%p
 
M = [0]*p
M[0] = 1
i = 1
pre = 0
for s in S[::-1]:
  pre = MS(i,int(s),pre)
  M[pre] += 1
  i *= 10

ans = sum(map(lambda m:(m*(m-1))//2, M))
print(ans)

