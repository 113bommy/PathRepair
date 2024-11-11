
days,bowl,plate = map(int,(input().split()))
#print(days)
#print(bowl)
#print(plate)
count1 = 0
count2 = 0
menu = (input().split())
#menu.append(inp)
for i in range(days):
    #print(menu[i])
    if(menu[i]=='1'):
        count1 = count1+1
    elif(menu[i]=='2'):
        count2 = count2+1
bowl = bowl-count1
if(bowl>0):
    left = bowl+plate
    plate = left - count2
    if(plate>=0):
        print("0")
    else:
        print(abs(plate))
if(bowl<0):
    plate = plate - count2
    if(plate<0):
        print(abs(plate+bowl))
    else:
        print(abs(bowl))

