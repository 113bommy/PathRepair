str1=input()
s=0
c=0
if len(str1)==1:
    print(1)
else:
    while(1):
        s=0
        for i in str1:
            s+=int(i)
        str1=str(s)
        c+=1
        if len(str1)==1:
            break
    print(c)