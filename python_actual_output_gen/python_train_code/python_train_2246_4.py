n,d=input().split(" ")
d=int(d)
oldn=int(n)
h=int(n)
i=1
while i<=len(n):
    if (n[-i]!="9"):
        h=h-(int(n[-i])+1)*(10**(i-1))
        if oldn-h<d:
            n=str(h)
        else: break
    i+=1
print(n)