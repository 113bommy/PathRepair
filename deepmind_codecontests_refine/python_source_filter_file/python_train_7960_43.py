from collections import Counter
x=int(input())
n=input()
s=""
for i in n:
    if i=="2":
        s+="2"
    elif i=="3":
        s+="3"
    elif i=="4":
        s+="322"
    elif i=="5":
        s+="5"
    elif i=="6":
        s+="53"
    elif i=="7":
        s+="7"
    elif i=="8":
        s+="72222"
    elif i=="9":
        s+="733"
s=list(s)
s.sort()
s=s[::-1]
print("".join(s))
        