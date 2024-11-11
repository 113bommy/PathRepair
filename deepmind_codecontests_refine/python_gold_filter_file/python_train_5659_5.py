s=input()
n=len(s)
t=""
i=0
f=0
while(i<n):

  if(s[i:i+3]=="WUB"):
    i+=3
    if(f):
      t+=" "

  else:
    f=1

    t+=s[i]
    i+=1
print(t)