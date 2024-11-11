t=int(input())
for _ in range(t):
  c=sorted(list(input()))
  b=list(input())
  print(c)
  if c in b:
    print("YES")
  else:
    d={}
    f={}
    s=1
    for i in c:
      try:
        d[i]+=1
      except Exception:
        d[i]=1
    for j in range(len(b)):
      try:
        u=d[b[j]]
        x=min(j+len(c),len(b))
        p=sorted(b[j:x:1])
        print(p)
        if c==p:
          print("YES")
          s=0
          break
      except Exception:
        pass
    if(s==1):
      print("NO")

