# http://codeforces.com/contest/46/problem/B

shirt = input().strip().split()
k = int(input())
prefarence = []
for i in range(0,k):
    prefarence.append(input())

count = 0
for i in range(0,len(shirt)):
    shirt[i] = int(shirt[i])
    count = count + shirt[i]

def size_to_number(x):
    if(x=="S"):
        return 0
    elif(x=="M"):
        return 1
    elif(x=="L"):
        return 2
    elif(x=="XL"):
        return 3
    elif(x=="XXL"):
        return 4

def number_to_size(x):
    if(x==0):
        return "S"
    elif(x==1):
        return "M"
    elif(x==2):
        return "L"
    elif(x==3):
        return "XL"
    elif(x==4):
        return "XXL"



for x in prefarence:
    if(shirt[size_to_number(x)] > 0):
        print (x)
        shirt[size_to_number(x)] = shirt[size_to_number(x)] - 1
    else:
        for i in range(1,4):
            if (size_to_number(x) + i < len(shirt)):
                if(shirt[size_to_number(x) + i] > 0):
                    print (number_to_size(size_to_number(x) + i))
                    shirt[size_to_number(x) + i] = shirt[size_to_number(x) + i] - 1 
                    break   
            elif (size_to_number(x) - i > 0):
                if(shirt[size_to_number(x) - i] > 0):
                    print (number_to_size(size_to_number(x) - i))
                    shirt[size_to_number(x) - i] = shirt[size_to_number(x) - i] - 1    
                    break
