n,m=map(int,input().split())
s=(2*n+m)//4
if (s+1)*4<=2*n+m:
  s+=1
print(min(2*m,s))