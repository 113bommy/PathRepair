from math import*
s=input()
n=int(input())
s=s.upper()
it=''
for i in range(len(s)):

    if s[i]=="L" or s[i]=="I":
        it=it+"1"
    elif s[i]=="O":
        it=it+"1"
    else:
        it=it+s[i]
for i in range(n):
    s2=input()
    it2=""
    s2=s2.upper()
    for i in range(len(s2)):

        if s2[i] == "L" or s2[i] == "I":
            it2=it2+"1"
        elif s2[i] == "O":
            it2=it2+"0"
        else:
            it2=it2+s2[i]
    if it2==it:
        print("No")
        exit()
print("Yes")