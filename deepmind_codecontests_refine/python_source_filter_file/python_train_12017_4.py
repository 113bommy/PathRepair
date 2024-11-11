str = input()
instr = str.split('=')
output = ''
if '+' in instr[0]:
    if len(instr[1]) == len(instr[0])-1:
        output = str
    elif len(instr[1])+1 == len(instr[0])-2:
        if len(instr[0].split('+')[0]) == 1:
            output = str[:2]+str[4:]+'|'
        else:
            output=str[1:]+'|'
    elif len(instr[1])-1 == len(instr[0]):
        output='|'+str[:len(str)-1]
    else:
        output = 'Impossible'
else:
    first = instr[0].split('-')
    if len(first[0])-len(first[1]) == len(instr[1]):
        output = str
    elif len(first[0])-len(first[1])-1 == len(instr[1])+1:
        if len(first[0]) == 1:
            output = str[:2]+str[4:]+'|'
        else:
            output=str[1:]+'|'
    elif len(first[0])-len(first[1])+1 == len(instr[1])-1:
        output='|'+str[:len(str)-1]
    else:
        output = 'Impossible'
print(output)