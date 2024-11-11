n=int(input())

lamps=input()

if n==1:
    print(0)
    exit(print(lamps))
if n==2:
    if lamps[0]!=lamps[1]:
        print(0)
        exit(print(lamps))
    else:
        print(1)
        if lamps[0]=="R":
            exit(print("RG"))
        elif lamps[0]=="G":
            exit(print("GR"))
        else:
            exit(print("BR"))


first=[0,0,0]
second=[0,0,0]
third=[0,0,0]


for i in range(n//3):
    if lamps[3*i]=="R":
        first[0]+=1
    elif lamps[3*i]=="G":
        first[1]+=1
    else:
        first[2]+=1

    if lamps[3*i+1]=="R":
        second[0]+=1
    elif lamps[3*i+1]=="G":
        second[1]+=1
    else:
        second[2]+=1

    if lamps[3*i+2]=="R":
        third[0]+=1
    elif lamps[3*i+2]=="G":
        third[1]+=1
    else:
        third[2]+=1

ost=n%3
if ost==1:
    if lamps[n-1]=="R":
        first[0]+=1
    elif lamps[n-1]=="G":
        first[1]+=1
    else:
        first[2]+=1

if ost==2:
    if lamps[n-2]=="R":
        first[0]+=1
    elif lamps[n-2]=="G":
        first[1]+=1
    else:
        first[2]+=1

    if lamps[n-1] == "R":
        second[0] += 1
    elif lamps[n-1] == "G":
        second[1] += 1
    else:
        second[2] += 1


firstn=[0,0,0]
secondn=[0,0,0]
thirdn=[0,0,0]

firstn[0]=first[1]+first[2]
firstn[1]=first[0]+first[2]
firstn[2]=first[0]+first[1]

secondn[0]=second[1]+second[2]
secondn[1]=second[0]+second[2]
secondn[2]=second[0]+second[1]

thirdn[0]=third[1]+third[2]
thirdn[1]=third[0]+third[2]
thirdn[2]=third[0]+third[1]

min = n
str = "BBB"

if firstn[0]+secondn[1]+thirdn[2]<min:
    min=firstn[0]+secondn[1]+thirdn[2]
    str="RGB"

if firstn[0]+secondn[2]+thirdn[1]<min:
    min=firstn[0]+secondn[2]+thirdn[1]
    str="RBG"

if firstn[1]+secondn[0]+thirdn[2]<min:
    min=firstn[1]+secondn[0]+thirdn[2]
    str="GRB"

if firstn[1]+secondn[2]+thirdn[0]<min:
    min=firstn[1]+secondn[2]+thirdn[0]
    str="GBR"

if firstn[2]+secondn[0]+thirdn[1]<min:
    min=firstn[2]+secondn[0]+thirdn[1]
    str="BRG"

if firstn[2]+secondn[1]+thirdn[0]<min:
    min=firstn[2]+secondn[1]+thirdn[0]
    str="BRG"

print(min)

str=str*(n//3)+str[:ost]

print(str)