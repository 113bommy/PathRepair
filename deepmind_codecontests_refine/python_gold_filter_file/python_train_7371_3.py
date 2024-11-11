s=int(input())
l=[]
while(s not in l):
  l.append(s)
  if s%2==0:s//=2
  else:s=s*3+1
print(len(l)+1)
