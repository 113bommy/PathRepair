a,b=input().split()
a=int(a)
b=int(b)
c=0
while a<=b:
    a+=a*3
    b+=b*2
    c+=1
print(c)