s=input()
e,q,w=s.index("^"),0,0
for i in range(e):
    if s[i]!="=":q+=int(s[i])*(e-i)
for i in range(e+1,len(s)):
    if s[i]!="=":w+=int(s[i])*(i-e)
print("left"if q>w else "right"if w>q else"balanced")