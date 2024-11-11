s=input()
cap='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
sml='abcdefghijklmnopqrstuvwxyz'
s1=0
c1=0
for i in s:
    if i in cap:
        c1+=1
    elif i in sml:
        s1+=1
if(c1>=s1):
    print(s.upper())
else:
    print(s.lower())