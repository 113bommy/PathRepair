count = int(0)
count2 = int(0)
count3 = int(0)
count4 = int(0)
low=int(0)

s = input()
size = len(s)
i=0
for i in range(size):
    if(s[i]=='i'):
        count = count + 1
    elif(s[i]=='t'):
        count2 = count2 + 1
    elif(s[i]=='n'):
        count3 = count3 + 1
    elif(s[i]=='e'):
        count4 = count4 + 1

low = int(count4/3)
if(count<low):
    low = count
if(count2<low):
    low = count2
if(((count3-1)/2) < low):
    low = (count3-1)/2
print(low)
