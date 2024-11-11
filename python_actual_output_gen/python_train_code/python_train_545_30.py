N=int(input())
a=list(map(int,input().split()))
b=[0]*N
c=[]
cnt=0
for i in range(1,N+1)[::-1]:
  if sum(b[::i])%2 != a[i-1]:
    a[i-1]=1
    c.append(i)
    cnt+=1
print(cnt)
if len(c)>0:
  print(*c,sep='\n')