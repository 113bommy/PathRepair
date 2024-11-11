acc = input()
bS = -1
bE = -1
cS = -1
cE = -1
for i in range(0,len(acc)):
    if(acc[i] == '['):
        bS = i
        break
temp1 = len(acc) - 1
while(temp1 > bS):
    if(acc[temp1] == "]"):
        bE = temp1
        break
    else:
        temp1 = temp1 - 1
if((bS==-1) or (bE==-1)):
    print("-1")
    exit()
for i in range((bS+1),bE):
    if(acc[i] == ':'):
        cS = i
        break
temp1 = bE - 1
while(temp1 > bS):
    if(acc[temp1] == ':'):
        cE = temp1
        break
    else:
        temp1 = temp1 - 1

if((cS == -1) or (cE == -1)):
    print("-1")
    exit()
temp = 4
for i in range(cS,cE):
    if(acc[i] == '|'):
        temp += 1
print(temp)
