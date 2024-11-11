s=['','']
s[0]=input()
s[1]=input()

pcs=0
emp=0
half=False
n=len(s[1])
for i in range(n):
    if(s[0][i]=='0' and s[1][i]=='0'):
        emp+=1
        if(emp==3):
            emp=0
            pcs+=2
        if(emp==1 and half):
            print('ehe')
            pcs+=1
            emp=0
        half=False
    elif(s[0][i]=='X' and s[1][i]=='X'):
        if(emp==2):
            pcs+=1          
        emp=0
        half=False
    else:
        half=True
        if(emp==2):
            pcs+=1
        elif(emp==1):
            half=False
            pcs+=1
        emp=0
if(emp==3):
    pcs+=2
elif(emp==2):
    pcs+=1
elif(emp==1 and half):
    pcs+=1
print(pcs)