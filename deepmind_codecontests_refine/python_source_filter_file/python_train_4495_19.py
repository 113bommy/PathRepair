x=input()
x=x.lower()
vow=('a','e','i','o','u')
p=''
for i in x :
    if i in vow :
        x=x.replace(i,'')
for i in x:
    p=p+'.'+i
print(p)