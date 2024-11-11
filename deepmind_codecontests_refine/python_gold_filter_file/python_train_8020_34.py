s=input()
a,b=map(int,s.split())
d=""
if(a>b):
    d=">"
elif(a==b):
    d="=="
else:
    d="<"
print("a %s b"%(d))