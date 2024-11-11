a,b=map(int,input().split())
c=[list(map(int,input().split()))for i in[0]*b]
d=[]
e=[]
for i in c:
  if i[0]==1:d+=[i[1]]
  elif i[1]==a:e+=[i[0]]
print((set(d)&set(e)=={})*'IM'+'POSSIBLE')