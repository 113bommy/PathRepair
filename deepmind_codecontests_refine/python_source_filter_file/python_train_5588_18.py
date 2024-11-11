n=input()
t=0

for i in range(len(n)):

    if n[i]=="." and n[i-1]!="9" and n[i+1]<"5":
        t=0
        break

    elif n[i]=="." and n[i-1]!="9" and n[i+1] >= "5" :
        t+=1
        break

    elif n[i]=="." and n[i-1]=="9" :
        t=-1
        break

l=[]

for i in range(len(n)):
    if n[i]==".":
        break
    else:
        l.append(int(n[i]))

if t==1:
    l[len(l)-1]+=1
    print(''.join(str(i) for i in l))

elif t==0:
    print(''.join(str(i) for i in l))

else:
    print("GOTO VASILISA")