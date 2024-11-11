input()
a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
dica={}
dicb={}
dicc={}
r=[]
for i in a:
  if i in dica :
    dica[i]+=1
  else:
    dica[i]=1
for i in b:
  if i in dicb:
    dicb[i]+=1
  else:
    dicb[i]=1
for i in c:
  if i in dicc:
    dicc[i]+=1
  else:
    dicc[i]=1
for i in a:
  if i not in dicb:
      r.append(i)
  elif dica[i]!=dicb[i]:
      r.append(i)
for i in b:
  if i not in dicc:
      r.append(i)
  elif dicb[i]!=dicc[i]:
      r.append(i)   
for i in r:
    print(i)