n = int(input())
number = input()
sum = 0
flag = False
counter = 0
for i in range (n) :
    sum = sum + int(number[i])
if (sum == 0 and n > 1) :
    flag = True
for i in range (2, int(sum/2)) :
    if (sum % i == 0) :
        for j in range (n) :
            counter = counter + int(number[j])
            if (counter == sum/i) :
                counter = 0
        if (counter == 0) :
            flag = True
            counter = 0
            break
        counter = 0
if (flag == True) :
    print ("YES")
else :
    print ("NO")