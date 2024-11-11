s=input('')
a,b,r=s.split(' ')
a=int(a)
b=int(b)
r=int(r)
if(min(a,b)<=2*r):
    print("Second")
else:
    print("First")