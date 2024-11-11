s=str(input())
s=list(s)
if s[0]!="A":
  s.insert(0,"A")
if len(s)>=5:
  if s[4]!="A":
    s.insert(4,"A")
if len(s)>=7:
  if s[6]!="A":
    s.insert(6,"A")
if s[len(s)-1]!="A":
  s.append("A")
if "".join(s)=="AKIHABARA":
  print("YES")
else:
  print("NO")