a=input().strip()
c=0
s=0
for i in a:
    if ord(i)>=65 and ord(i)<=90:
        c+=1
    else:
        s+=1
if c>s:
    print(a.lower())
else:
    print(a.upper())
