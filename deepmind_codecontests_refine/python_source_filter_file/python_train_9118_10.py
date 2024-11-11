n = int(input())
inputSring = input()
result = ""
while len(inputSring) > 0:
    if '0' in inputSring:
        countOfOnes = inputSring.find('0')
        result += str(countOfOnes)
        inputSring = inputSring[countOfOnes:]
    else:
        result += str(len(inputSring))
        break
    if '1' in inputSring:
        countOfZeros = inputSring.find('1')
        result += ('0' * (countOfZeros-1))
        inputSring = inputSring[countOfZeros:]
    else:
        result += str(len(inputSring))
        break
print(result)