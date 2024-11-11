k=int(input())
l=int(input())
cnt=0; i=k
while i<l:
  i*=k
  cnt+=1
  if i==l: l=0
if l==0 or k==l: print("YES"); print(cnt)
else: print("NO")