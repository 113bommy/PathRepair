s=input()
z=0
m=0
k=len(s)
zag="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
mal="abcdefghijklmnopqrstuvwxyz"
for a in range(0,k):
    for i in range(0,25):
        if s[a]==zag[i]:
            z=1+z
        if s[a]==mal[i]:
            m=1+m
if z>m:
    for a in range(0,k):
        for i in range(0,25):
            if s[a]==mal[i]:
                s=s.replace(s[a],zag[i])
else:
    for a in range(0,k):
        for i in range(0,25):
            if s[a]==zag[i]:
                s=s.replace(s[a],mal[i])
print(s)