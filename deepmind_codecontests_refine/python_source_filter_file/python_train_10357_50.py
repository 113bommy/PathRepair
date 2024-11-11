def single(num:int) -> str:
    if num == 1:
        return 'one'
    if num == 2:
        return 'two'
    if num == 3:
        return 'three'
    if num == 4:
        return 'four'
    if num == 5:
        return 'five'
    if num == 6:
        return 'six'
    if num == 7:
        return 'seven'
    if num == 8:
        return 'eight'
    if num == 9:
        return 'nine'

def decade(num:int) -> str:
    if num == 2:
        return 'twenty'
    if num == 3:
        return 'thirty'
    if num == 4:
        return 'forty'
    if num == 5:
        return 'fifty'
    if num == 6:
        return 'sixty'
    if num == 7:
        return 'seventy'
    if num == 8:
        return 'eighty'
    if num == 9:
        return 'ninety'

score = int(input())
if score == 0:
    print('zero')
elif score == 10:
    print('ten')
elif score == 11:
    print('eleven')
elif score == 12:
    print('twelve')
elif score == 13:
    print('thirteen')
elif score == 14:
    print('fourteen')
elif score == 15:
    print('fifteen')
elif score == 16:
    print('sixteen')
elif score == 17:
    print('senventeen')
elif score == 18:
    print('eighteen')
elif score == 19:
    print('nineteen')
elif score%10 == 0:
    print(decade(score//10))
elif score<10:
    print(single(score))
else:
    print(decade(score//10)+'-'+single(score%10))
