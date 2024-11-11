x=input()
a=0
c=0
s=0
if len(x)<5:
    print("Too weak")
else:
    for i in x:
        if i.isalpha():
            a=1
        if i.isupper():
            c=1
        if i.islower():
            s=1
    if a==1 and c==1 and s==1:
        print("Correct")
    else:
        print("Too weak")