
n=input()
l=[]
for i in n:
    l.append(i)
i=0
while(i+2<=len(l)-1):
    if(l[i]=='W' and l[i+1]=='U' and l[i+2]=='B'):
        del l[i:i+3]
        l.insert(i," ")
        i+=0
    else:
        i+=1
print(("".join(l)).strip())
