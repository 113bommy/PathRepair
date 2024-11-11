c=input().split();
a=int(c[0])
b=int(c[1])
e=0
f=0
c=0
while True:    
    c+=int(a)
    if((a+f)<b):
        break
    e=int(a)%int(b)
    a=int((int(a)+int(f))/int(b))
    f=e

print(int(c))
