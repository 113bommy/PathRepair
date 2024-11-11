inn=int(input())
o=0
i=0
s=[]
sc=0
ba=[]
while i<inn:
  b=input()
  if b == "OUT":
    o+=1
    if o%3 == 0 and o>0:
      s.append(sc)
      sc=0
      i+=1
      o=0
      ba=[]
  elif b == "HIT":
    ba.append(1)
    if len(ba)>=4:
      sc+=1
      ba=[1,1,1,1]
      
  elif b == "HOMERUN":
    ba.append(1)
    sc+=len(ba)
    ba=[]
[print(i) for i in s]
