number = int(input())
var = True
count = 0

if number < 10:
    var = False
else:
    answer = sum(int(digit) for digit in str(number))
    while var == True:
        count+=1
        if int(answer) >= 10: 
            answer = sum(int(digit) for digit in str(answer))
        else: 
            var = False
print(count)
