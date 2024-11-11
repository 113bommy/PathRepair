a=input()
m=0
b=[]
c=''
for i in a[:-1]:
    if m==0:
        if i==' ':pass
        elif i=='"':m=2
        else:m=1;c+=i
    elif m==1:
        if i==' ':m=0;b+=[c];c=''
        else:c+=i
    elif m==2:
        if i=='"':m=0;b+=[c];c=''
        else:c+=i
for i in b:print('<'+i+'>')
if c:print('<'+i+'>')
