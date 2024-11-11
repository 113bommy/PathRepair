t = int(input())
x = str(input())
t = len(x)
acount = 0
dcount = 0
for i in range (0, len(x)):
    if (x[i]>= 'A'):
        acount += 1
    else:
        dcount += 1
if acount >= dcount :
    print("Anton")
elif acount == dcount :
    print("Friendship")
else:
    print("Danik")