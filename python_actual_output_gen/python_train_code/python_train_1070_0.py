n=int(input())
a=input()
b=[]
c=''
a1=len(a)
i=0
while i < len(a):
    c+=a[i]
    if a[i] in ['.','?','!']:
        b.append(len(c))
        c=''
        i+=1
    i+=1
d=0
e=0
f=0
for i in b:
    if e+i+f>n:
        if e==0 or i>n:
            print('Impossible')
            break
        e=0
        f=0
        d+=1
    else:
        f+=1
    e+=i
else:
    print(d+1)