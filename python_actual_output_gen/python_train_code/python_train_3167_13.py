
#number = int(input())
array = input().split()

number = int(array[0])
nArray = []
for i in array:
    nArray.append(int(i))
nArray.pop(0)

count = 0 

count = number - abs(nArray[3]-nArray[0])-abs(nArray[2]-nArray[1])
print (count * number)
                        
                    