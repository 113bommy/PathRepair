n=input()
ans="NO"
i=0
for a in range(len(n)):
    if n[a]=="7":
        ans="YES"
    elif n[a]=="4":
        ans="YES"
    else:
        ans="NO"
        break
n=int(n)
l=[4,7,47,74,447,747,474,774]

for a in l:
    if n%a==0:
        ans="YES"


print (ans)

    
    
    

    
