l=list(input())
i=0
s=0
k=""
while(i<len(l)):
   try:
    if(l[i]=='W' and l[i+1]=='U' and l[i+2]=='B'):
        s=1
        i=i+3
        continue
   except:
       pass
   if(s==1):
        k=k+" "+l[i]
        s=0
   else:
        k=k+l[i]
   i=i+1
print(k)