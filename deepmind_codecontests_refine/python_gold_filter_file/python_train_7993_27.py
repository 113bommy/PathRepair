x,y=map(int,input().split())
a=-1
p=10**9+7
for i in range(x//2+1):
  if i+2*(x-2*i)==y:
    a=i
    break
if a==-1:
  print(0)
  exit()
elif a==0:
  print(1)
else:
  gyaku=[0,1]
  for i in range(2,a+1):
    gyaku.append(((p//i)*-gyaku[p%i])%p)
  com=[1]
  for i in range(1,a+1):
    com.append(com[-1]*gyaku[i]*(x-a+1-i)%p)
  print(com[-1])  
