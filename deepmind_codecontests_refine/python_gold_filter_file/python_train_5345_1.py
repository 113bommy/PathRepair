s1=input()
s2=input()
count=0
x=[]
for i in range(min(len(s1),len(s2))):
    if(s1[i]!=s2[i]):
        x.append(i)
        count=count+1
    if(count>=3):
        break
if(count==2):
    s1=list(s1)
    temp=s1[x[0]]
    s1[x[0]]=s1[x[1]]
    s1[x[1]]=temp
    s1="".join(s1)
print("YES") if(s1==s2) else print("NO")