n = int(input())
events = list(input())

output = list('0000000000')
for i in range(n):
    if events[i] == 'L':
        output[output.index('0')] = '1'
    elif events[i] == 'R':
        output[10-1-output[::-1].index('0')] = '1'
    else:
        output[int(events[i])] = '0'
print(''.join(output))

        