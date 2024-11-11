s=input()
s1=""
caps=True
if ord(s[0])<=122 and ord(s[0])>=97:
    s1+=chr(ord(s[0])-32)
    s=s[1:]
i=0
while i<len(s):
    if ord(s[i])<=90 and ord(s[i])>=65:
        i+=1
    else:
        caps=False
        break

if caps:
    for a in s:
        s1+= chr(ord(a)+32)
    print(s1)
else:
    print(s1+s)
