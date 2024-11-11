n=int(input())
t=[[0 for i in range(10)]for j in range(10)]
for i in range(1,n+1):
  i=str(i)
  t[int(i[0])][int(i[-1])]+=1
  
ans=0
for i in range(10):
  for j in range(10):
    ans+=t[i][j]*t[j][i]
    
print(ans)