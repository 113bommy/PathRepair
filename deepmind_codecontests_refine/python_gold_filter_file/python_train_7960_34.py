def create_number(number):
    digits=[]
    factorials={2:[2],3:[3],4:[3,2,2],5:[5],6:[5,3],7:[7],8:[2,2,2,7],9:[2,3,3,7]}

    while number>0:
        last_digit=number%10
        number=number//10
        if last_digit in factorials:
            cdigits=factorials[last_digit]
            for cdigit in cdigits:
                digits.append(cdigit)
    digits.sort()
    new_number=0
    power=0

    for index in range(len(digits)):
        digit=digits[index]
        new_number=new_number+digit*(10**power)
        power+=1
    result=new_number
    return result


digits_ammount=int(input())
number=int(input())
result=create_number(number)
print(result)