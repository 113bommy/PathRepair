x=input()
count=0
count1=0
for i in x:
    if(i.islower()):
        count=count+1
    else:
        count1=count+1
if(count>=count1):
    print(x.lower())
else:
    print(x.upper())