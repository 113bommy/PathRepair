import bisect

def ctoi(char):
  return ord(char)-ord('a')

s=input()
l=len(s)
t=input()
if len(set(t)-set(s))!=0:
  print(-1)
  exit()
pos=[[] for _ in range(26)]
for i in range(2*l):
  pos[ctoi(s[i%l])].append(i+1)
index=0
loop=0
for i in range(len(t)):
  tmp=bisect.bisect_right(pos[ctoi(t[i])],index)
  next_index=pos[ctoi(t[i])][tmp]
  if next_index>=l:
    loop+=1
  index=next_index%l
print(l*loop+index)