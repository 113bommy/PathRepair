times = int(input())

current = []
pointer = 0

for n in range(times):
    i = input()
    if i == 'pwd':
        print('/' + ''.join(map(lambda x: x + '/', current)))
    else:
        i = i[3:] # remove the "cd "
        
        if i[0] == '/':
            i = i[1:]
            current = []
            pointer = 0
            
        for part in i.split('/'):
            #print('processing: ' + part)
            if part == '..':
                pointer -= 1
                current = current[:pointer]
            else:
                current.append(part)
                pointer += 1
                
            #print(pointer, current)
