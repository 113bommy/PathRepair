s=input()
l1=['q','w','e','r','t','y','u','i','o','p']
l2=['a','s','d','f','g','h','j','k','l',';']
l3=['z','x','c','v','b','n','m',',','.''/']
l=input()
outputer=''
if s=='R':
    for i in range(len(l)):
        if l[i] in l1:
            x=l1.index(l[i])
            outputer=outputer+str(l1[x-1])
        if l[i] in l2:
            x=l2.index(l[i])
            outputer=outputer+str(l2[x-1])
        if l[i] in l3:
            x=l3.index(l[i])
            outputer=outputer+str(l3[x-1])
else:
    for i in range(len(l)):
        if l[i] in l1:
            x=l1.index(l[i])
            outputer=outputer+str(l1[x+1])
        if l[i] in l2:
            x=l2.index(l[i])
            outputer=outputer+str(l2[x+1])
        if l[i] in l3:
            x=l3.index(l[i])
            outputer=outputer+str(l3[x+1])
print(outputer)
    
