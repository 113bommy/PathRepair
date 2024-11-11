n=int(input())
f=n//7
g=n%7
s=[]
if g==6:
    s.append(f*2+1)
else:
    s.append(f*2)
if g<=2:
    s.append(f*2+g)
else:
    s.append(f*g+2)
for i in s:
    print(i,end=' ')
