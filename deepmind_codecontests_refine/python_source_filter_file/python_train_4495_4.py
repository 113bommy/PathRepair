a=input().lower()
b=[]
for i in range(0,len(a)):
    if (ord(a[i])) >= 97 and (ord(a[i])) <= 122:
        b.append(a[i])
for i in range(0,len(b)):
    if b[i]!="a" and b[i]!="e" and b[i]!="i" and b[i]!="o" and b[i]!="u" and b[i]!="y":
        print (".",b[i],end="")