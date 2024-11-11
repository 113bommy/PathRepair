n=int(input())
a=list(map(int,input().split()))
s=set()
fr=0
for i in a:
  x=i//400
  if(x<8):s.add(x)
  else:fr+=1
ki=len(s)
ma=min(ki+fr,8)
mi=max(ki,1)
print(mi,ma)
