a=input()
b=len(a)
if b==1:
    print(a)
else:
    l=[]
    for i in range(0,b,2):
        l.append(i)
    l=sorted(l)
    for i in range(len(l)):
        if l[i]==l[len(l)-1]:
            print(l[i],end='')
        else:
            print(l[i],end='+')