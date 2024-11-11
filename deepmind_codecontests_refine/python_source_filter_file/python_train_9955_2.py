a=input()
for i in range(6):
    a+="_"
m=0
for i in range(len(a)-6):
    if a[i]=="A":
        if a[i:i+3]=="Ann":
            m+=1
    elif a[i]=="O":
        if a[i:i+4]=="Olya":
            m+=1
    elif a[i]=="D" or a[i]=="S":
        if a[i:i+5]=="Danil" or a[i:i+6]=="Slava":
            m+=1
    elif a[i]=="N":
        if a[i:i+6]=="Nikita":
            m+=1
    elif m>1:
        print("NO")
        break
if m==0:
    print("NO")
elif m==1:
    print("YES")