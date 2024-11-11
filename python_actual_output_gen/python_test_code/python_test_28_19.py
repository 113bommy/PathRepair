a=input()
upper=0
lower=0
for i in range(len(a)):
    if(a[i].isupper()):
        upper=upper+1
    else:
        lower=lower+1
if(upper>lower):
    print(a[0:].upper())
elif(lower<=upper):
    print(a[0:].lower())