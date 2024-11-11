str = input()
array = [0,0,0,0]
for i in range(len(str)):
    if(str[i] == 'n'):
        array[0] +=1
    elif(str[i] == 'i'):
        array[1] +=1
    elif(str[i] == 'e'):
        array[2] +=1
    elif(str[i] == 't'):
        array[3] +=1
if(array[0]<3 or array[1]<1 or array[2]<3 or array[3]<1):
    print('0')
else:
    sum =1
    array[0] -= 3
    array[1] -= 1
    array[2] -= 3
    array[3] -= 1
    while(array[0] >= 2 and array [1] >=1 and array [2] >= 3 and array[3] >=1):
        array[0] -=2
        array[1] -=1
        array[2] -=3
        array[3] -=1
        sum+=1
    print(sum)


