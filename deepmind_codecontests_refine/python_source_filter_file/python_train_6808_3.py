borze = input()

result = ''

i = 0

while i < len(borze) - 1:
    if borze[i] == '.':
        result += '0'
        i += 1
    elif borze[i] == '-' and borze[i+1] == '.':
        result += '1'
        i += 2
    else:
        if borze[i] == '-' and borze[i+1] == '-':
            result += '2'
            i += 2

print(result)
