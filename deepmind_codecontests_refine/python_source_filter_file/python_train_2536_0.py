line = input()
count = 0
if line[0:4] == 'http':
    for i in range(4,len(line)-1):
        if line[i:i+2] == 'ru':
            count = i
            break
    if count == len(line) - 2:
        print('http://'+ line[4:i] + '.ru' )
    else:
        print('http://'+ line[4:i] + '.ru/' + line[i+2:])
else:
    for i in range(3,len(line)-1):
        if line[i:i+2] == 'ru':
            count = i
            break
    if count == len(line) - 2:
        print('ftp://'+ line[3:i] + '.ru' )
    else:
        print('ftp://'+ line[3:i] + '.ru/' + line[i+2:])