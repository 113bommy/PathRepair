s = input()

for i in range(len(s)-2):
    if s[i:i+2] == 'AC':
        print('Yes')
        exit()

print('No')