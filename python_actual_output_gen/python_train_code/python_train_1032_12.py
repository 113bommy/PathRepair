s=input()
l=list(s.split())
if l[2]=='week':
    if l[0]==5 or l[0]==6:
        print(53)
    else:
        print(52)
else:
    if l[0]=='30':
        print(11)
    elif l[0]=='31':
        print(7)
    else:
        print(12)
    