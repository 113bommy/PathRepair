N,M =map(int, input().split())
L,R =[],[]

for i in range(M+1):
  x,y = map(int,input().split())
  L.append(x)
  R.append(y)

print(max(0,min(R)-max(L)+1))