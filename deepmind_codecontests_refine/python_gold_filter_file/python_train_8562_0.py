daf = list(input())

count = 0
current = 'X'
num_current = 5

for x in daf:
    if num_current >= 5:
        count += 1
        current = x
        num_current = 1
    elif current == x:
        num_current += 1
    else:
        count += 1
        num_current = 1
        current = x
        
    '''
    print('count', count)
    print('num_current', num_current)
    print('current', current)
    print()
    ''' 

print(count)
        
