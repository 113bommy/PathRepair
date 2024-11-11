txt=str(input())
txt=txt+"+"
st=""
li=[]
for i in range(len(txt)):
    if(txt[i]!="+"):
        st=""+txt[i]

        li.append(st)
       

li.sort()
print(li)
s=""
s=(s.join(li))
x=[]
for i in s:
    if i not in x:
        x.append(i)
        s=s.replace(i,"+"+i)
        
    else:
        continue

        
    
print(s[1:])