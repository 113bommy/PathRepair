def bulildResponse(number, digits, group=None):
    i = 0
    response = ""
    if group is not None:
    
        while i < digits:

            for j in range(group):
                response += number[j]
            
            if i + group < digits:
                response += "-"
            
            i += group
    else:
        response += number[0] + number[1] + number[2] + "-"
        i = 3
        while i < digits:
            
            response += number[i] + number[i+1]
            
            if i + 2 < digits:
                response += "-"
            
            i += 2
                

    return response

digits = int(input())
number = input()

if digits % 2 == 0:
    print(bulildResponse(number, digits, 2))
elif digits % 3 == 0:
    print(bulildResponse(number, digits, 3))
else:
    print(bulildResponse(number, digits))