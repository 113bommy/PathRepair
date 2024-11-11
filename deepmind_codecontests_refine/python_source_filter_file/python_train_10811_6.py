input()
temp=0
maxV=-1
for s in input():
  temp+=1 if s=="I" else -1
  if maxV<temp:maxV=temp 
print(maxV)