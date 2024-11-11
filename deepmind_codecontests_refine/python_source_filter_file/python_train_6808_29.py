s = str(input())
li = list(s)
n = len(s)
i=0
while i<n-1:
    if li[i] == '.':
        print('0', end='')
        i+=1
        continue
    elif li[i] == '-' and li[i+1] == '.':
        print('1', end='')
        i+=2
        continue
    elif li[i] == '-' and li[i+1] == '-':
        print('2', end='')
        i+=2
        continue