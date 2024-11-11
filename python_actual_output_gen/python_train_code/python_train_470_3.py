s=input()
 
tmp=""
last=""
cnt=1
for s_ in s:
  tmp+=s_
  if tmp != last:
    last=tmp
    tmp=''
    cnt+=1
print(cnt)