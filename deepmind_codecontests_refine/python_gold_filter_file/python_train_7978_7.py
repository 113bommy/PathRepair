n=int(input())
s=input()
x=y=a=0
p=2
for c in s:        
 if c=='U':y+=1
 else:x+=1
 if y!=x:
  np=y>x
  if np!=p<2:a+=1
  p=np
print(a)
