x=input()
y=0
for a in x:
    if a=='4' or a== '7':
        y+=1

if y%4==0 or y%7==0:
    print ("YES")
else:
    print("NO")