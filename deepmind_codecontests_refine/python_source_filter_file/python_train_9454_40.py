n=int(input())
n2=n*2
key=[0,0]
for i in range(1,int(n2**0.5)+2):
  if n2%i==0:
    if i*(i+1)==n2:
      key=[i,i+1]
      break
if key==[0,0]:
  print('No')
  exit()
print('Yes')
a,b=key
print(b)
ans=[[0]*a for _ in range(b)]
cnt=1
for i in range(b):
  for j in range(a):
    if j<i:
      ans[i][j]=ans[j][i-1]
    else:
      ans[i][j]=cnt
      cnt+=1
for x in ans:
  print(' '.join(map(str,x)))