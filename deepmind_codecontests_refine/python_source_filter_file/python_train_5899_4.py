lst = list(input())
a1=0
b1=0
c1=0
lst2=[]
z=0
for i in range(len(lst)):
    if lst[i]=="a":
        a1+=1
    elif lst[i]=="b":
        b1+=1
    else:
        c1+=1
    if lst[i] not in lst2:
        lst2.append(lst[i])
    if len(lst2)>0:
        if lst2[-1]!=lst[i]:
            z=1

if len(lst2)==0:
    z=1
elif len(lst2)==3:
    if lst2[0]=='b' or lst2[0]=='c':
        z=1
    elif lst2[1]=='a' or lst2[1]=='c':
        z=1
    elif lst2[2]=='b' or lst2[2]=='a':
        z=1
elif len(lst2)==2:
    if lst2[0]=='c' and lst2[1]=='b':
        z=1
    elif lst2[0]=='c' and lst2[1]=='a':
        z=1
    elif lst2[0]=='b' and lst2[1]=='a':
        z=1
    elif lst2[0]=='b' and lst2[1]=='c':
        z=1
    elif lst2[0]=='a' and lst[1]=='c':
        z=1
elif len(lst2)==1:
    z=1

if (a1==c1 or (b1==c1) or (a1==c1 and b1==c1)) and z==0:
    print("YES")
else:
    print("NO")