vowels="AaOoYyEeUuIi"
s=input()
for i in s:
    if i in vowels:
        s = s.replace(i, "")
for m in s:
    print('.', end=" ")
    print (m.lower(),end=" " )


