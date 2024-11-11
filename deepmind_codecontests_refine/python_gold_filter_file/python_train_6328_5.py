N = int(input())
ans = 0
l=[[0]*10 for _ in range(10)]
for i in range(1,N+1):
  s = str(i)
  l[int(s[0])][int(s[-1])]+=1
  
for i in range(10):
  for j in range(10):
    ans+=l[i][j]*l[j][i]
    
print(ans)