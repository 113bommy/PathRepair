s=input()
l=[]
for i in range(97,123):
    l.append(chr(i))
print(l)
rot=0
for i in range(len(s)):
    if i==0:
        a=abs(l.index(s[i])-l.index("a"))
        b=26-l.index(s[i])
        rot=rot+min(a,b)
    else:
        a=abs(l.index(s[i])-l.index(s[i-1]))
        b=26-a
        rot=rot+min(a,b)
print(rot)