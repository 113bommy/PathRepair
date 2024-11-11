s=input()
a,b=map(int,s.split())
d=""
if(a>b):
    d=">"
elif(a==b):
    d="=="
else:
    d="<"
print("%d %s %d"%(a,d,b))