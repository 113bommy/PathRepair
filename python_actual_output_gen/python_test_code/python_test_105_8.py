type1=input()
type2=input()
s=input()
d={}
for i in range(26):
    d[type1[i]]=type2[i]
    
answer=''
for i in s:
    if i.isdigit():
        s+=i
    else:
        if i.isupper():
            answer+=d[i.lower()].upper()
        else:
            answer+=d[i]

print(answer)