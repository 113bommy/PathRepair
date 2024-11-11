n,m=map(int,input().split())
S,C=[], []
for i in range(m):
  a,b=map(int,input().split())
  S.append(a)
  C.append(b)
for j in range(10**n):
  if len(str(j))==n and all(str(j)[x-1]==str(y) for x,y in zip(S,C)):
    print(j)
    break;
else:
  print(-1)