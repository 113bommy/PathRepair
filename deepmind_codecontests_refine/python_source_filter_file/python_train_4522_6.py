b=['o','a','b','c','d','e','f','g','h']
s=input()
s1=b.index(s[0])
s2=int(s[1])
e=input()
e1=b.index(e[0])
e2=int(e[1])

m=max(abs(s1-e1),abs(s2-e2))
print(m)
while s1!=e1 or s2!=e2:
    ss=''
    if s1!=e1:
        if s1<e1:
            ss+='R'
        else:
            ss+='L'
        s1-=(s1-e1)//abs(s1-e1)
        
    if s2!=e2:
        if s2<e2:
            ss+='D'
        else:
            ss+='U'
        s2-=(s2-e2)//abs(s2-e2)
        
    print(ss)
