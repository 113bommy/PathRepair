s=l=c=0
for a in open(0).read().split()+[0]:
 if a!=l:l=a;s+=c//2;c=0
 c+=1
print(s)