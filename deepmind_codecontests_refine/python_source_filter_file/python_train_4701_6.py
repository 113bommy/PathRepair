length=int(input())
string=input()
LeftParens=0
questionMarks=0
imposs=False
moreLeftAndQ=0
moreRightAndQBack=0
if length % 2 == 1:
    imposs=True
for i in range(length):
    if string[i]=="(":
        LeftParens+=1
        moreLeftAndQ+=1
    elif string[i]==")":
        moreLeftAndQ+=1
        if moreLeftAndQ<1:
            imposs=True
            break
    else:
        moreLeftAndQ+=1
    if string[length-i-1]=="(":
        moreRightAndQBack-=1
        if moreRightAndQBack<1:
            imposs=True
            break
    elif string[length-i-1]==")":
        moreRightAndQBack+=1
    else:
        moreRightAndQBack+=1
        
if imposs:
    print(": (")
else:
    newString=""
    for i in range(length):
            if string[i]=="?":
                if (length/2)-LeftParens>0:
                    newString=newString+"("
                    LeftParens+=1
                else:
                    newString=newString+")"
            else:
                newString=newString+string[i]
    print(newString)