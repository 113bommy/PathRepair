s=input()
c=0
for i in s:
    c+=1
if c==1 :
    if s.islower():
        print(s.upper())
    else:
        print(s)
elif c>1:
    if s[0].islower()==True and s[1::].isupper()==True:
        l=s[0].upper()+s[1::].lower()
        print(l)
    elif s.isupper()==True:
        l=s.lower()
        print(l)
    else:
        print(s)
else:
    print(s)