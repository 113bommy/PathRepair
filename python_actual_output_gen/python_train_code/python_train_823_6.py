l = []
r = 0
p = 0
s = 0
 
for i in range(3):
    st = input()
    l.append(s)
    if (st == "rock"):
        r+=1
    if (st == "paper"):
        p+=1
    if (st == "scissors"):
        s+=1
 
if ((r == 2) and (p == 1)):
    if (l[0] == "paper"):
        print("F")
    elif (l[1] == "paper"):
        print("M")
    else:
        print("S")
elif ((p == 2) and (s == 1)):
    if (l[0] == "scissors"):
        print("F")
    elif (l[1] == "scissors"):
        print("M")
    else:
        print("S")
elif ((s == 2) and (r == 1)):
    if (l[0] == "rock"):
        print("F")
    elif (l[1] == "rock"):
        print("M")
    else:
        print("S")
else:
    print("?")