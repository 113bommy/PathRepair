def xor(a,b):
    if(a!=b):
        return 1
    else:
        return 0





a=input()
b=input()
s=""
a=str(a)
b=str(b)
count=0
for i in range(len(a)):
    r=int(a[i])
    l=int(b[i])
    e=xor(r,l)
    s+=str(e)
print(s)
