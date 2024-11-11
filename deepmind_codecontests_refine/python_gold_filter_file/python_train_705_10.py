n,m=map(int,input().split())
s=[list(map(int,input().split())) for i in range(m)]
p=list(map(int,input().split()))
ans = 0

for i in range(2**n):
  ans += 1
  for j in range(len(s)):
    on = 0
    for k in range(s[j][0]):
      on += ((i>>(s[j][k+1]-1))%2)
    if(on%2 != p[j]):
      ans -= 1
      break
      
print(ans)