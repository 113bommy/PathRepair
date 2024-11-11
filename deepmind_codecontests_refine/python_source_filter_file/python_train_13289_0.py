n = input()
length = len(n)
if length % 2 == 1:
    result = '4'*((length + 1) // 2) + '7'*((length + 1) // 2)
else:
    half = length // 2
    if n > half*'7' + half*'4':
        result = (half + 1)*'4' + (half + 1)*'7' 
    elif n < half*'4' + half*'7':
        result = half*'4' + half*'7'
    else:
        four_count = seven_count = half
        for i in range(length):
            digit = n[i]
            if digit < '4':
                    result = n[:i] + '4'*four_count + '7'*seven_count
                    break
            if digit < '7' and digit != '4':
                if seven_count == 0:
                    result = n[:nearest_four] + '7' + '4'*(four_count + 1)
                    result += '7'*(length - len(result))
                else:
                    result = n[:i] + '7' + '4'*four_count + '7'*(seven_count - 1)
                break
            if digit > '7':
                result = n[:nearest_four] + '7' + '4'*(four_count + 1) 
                result += '7'*(length - len(result))
                break
            if digit == '4':
                nearest_four = i
                four_count -= 1
                if four_count < 0:
                    result = n[:i] + '7'*seven_count
                    break
            if digit == '7':
                seven_count -= 1
                if seven_count == 0:
                    result = n[:nearest_four] + '7' + '4'*(four_count + 1)
                    result += '7'*(length - len(result))
                    break
            if four_count == 0 and seven_count == 0:
                result = n                
                break
print(result)