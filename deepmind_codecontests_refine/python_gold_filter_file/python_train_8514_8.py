s=input()
t=input()
leng=len(s)
lent=len(t)
count=0
tmp=0
i=0
while True:
   ans=s[tmp:].find(t[i])
   if ans!=-1:
       i += 1
       tmp += ans+1
       if i ==lent:
           count += tmp
           break
       continue
   if tmp==0:
       count=-1
       break
   tmp=0
   count+=leng
if count>leng*10**100:
    count=-1
print(count)