s=input()
n=len(s)
t=""
i=3
f=0
while(i<n-3):
  if(s[i:i+3]=="WUB"):
    i+=3
    if(f):
      t+=" "

  else:
    f=1

    t+=s[i]
    i+=1
print(t)