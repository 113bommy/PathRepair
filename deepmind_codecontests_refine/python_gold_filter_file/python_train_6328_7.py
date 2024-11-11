n=int(input())
res=0
M=[[0 for _ in range(10)] for _ in range(10)]
for i in range(n+1):
  a=i%10
  b=int(str(i)[0])
  M[a][b]+=1
for i in range(1,10):
  for j in range(1,10):
    res+=M[i][j]*M[j][i]
    
print(res)