s=str(input())
l=list(s)
c=0
for i in l:
    if ord(i)<91:
        c+=1
if c==len(l):
    z=[l[0]]
    for i in range(1,len(l)):
        z.append(l[i].lower())
    print("".join(z))
elif c==len(l)-1 and ord(l[0])>91:
    l1=[l[0].upper()]
    for i in range(1,len(l)):
        l1.append(l[i].lower())
    print("".join(l1))
else:
    print(s)