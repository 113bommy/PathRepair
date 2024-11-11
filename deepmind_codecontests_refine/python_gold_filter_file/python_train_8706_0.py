arr=[int(item) for item in input().split()]
count2=0
count4=0
count=0
count3=0
for j in arr:
    if(j==2):
        count2=count2+1
    if(j==4):
        count4=count4+1
    if(j==1):
        count=1
    if(j==3):
        count3=count3+1
if(count3==3):
    print("YES")
    exit()
if(count==1):
    print("YES")
    exit()
if(count2>=2):
    print("YES")
    exit()
elif(count2==1 and count4==2):
    print("YES")
    exit()
else:
    print("NO")

        
