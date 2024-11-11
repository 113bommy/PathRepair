s=str(input())
c1=0
c2=0
for i in s:
    if i<="a" and i<="z":
        c1+=1
    else:
        c2+=1
if c1<c2:
    print(s.upper())
else:
    print(s.lower())
