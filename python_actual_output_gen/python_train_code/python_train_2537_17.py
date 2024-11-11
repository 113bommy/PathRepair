temp = input().split()
NumberOfOranges = int(temp[0])
MaximumSize = int(temp[1])
Container = int(temp[2])

OrangesList = input().split()
for i in range(0, len(OrangesList)):
    OrangesList[i] = int(OrangesList[i])

SumOfJuice=0
count=0
for i in range(0,NumberOfOranges):
    if(OrangesList[i] < MaximumSize):
        SumOfJuice += OrangesList[i]
    if(SumOfJuice>Container):
        SumOfJuice=0
        count +=1

print(count)