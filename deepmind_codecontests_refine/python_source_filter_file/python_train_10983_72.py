n=input()
up,lo=0,0
for i in (n):
    if i.isupper():
        up+=1
    else :
        lo+=1
    print(up,lo)
if up>lo:
    n=n.upper()
else:
    n=n.lower()
print(n)
