W=0
B=0
for i in range(8):
    x=[j for j in input()]
    for k in x:
        if k=='Q':
            W+=9
        elif k=='R':
            W+=5
        elif k=='B':
            W+=3
        elif k=='K':
            W+=3
        elif k=='P':
            W+=1
        elif k=='q':
            B+=9
        elif k=='r':
            B+=5
        elif k=='b':
            B+=3
        elif k=='k':
            B+=3
        elif k=='p':
            B+=1
if W==B:
    print("Draw")
elif W>B:
    print("White")
else:
    print("Black")
