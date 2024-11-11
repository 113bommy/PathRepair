a,b,s = input().split()
a=int(a)
b=int(b)
s=int(s)

def modu(a):
    if(a>=0):
        return a
    else:
        return -a
if(s<modu(a)+modu(b) or s==modu(a)+modu(b)+1):
    print("NO")
else:
    print("YES")
