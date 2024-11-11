
x=input()
y=input()
c=''
z='qwertyuiopasdfghjkl;zxcvbnm,.'
for i in y:
    if x=="R":
        c+=z[z.index(i)-1]
    else:
        if z.index(i)==len(z)-1:
            c+=z[z.index(i)-1]
        else:
            c+=z[z.index(i)+1]
            
print(c)