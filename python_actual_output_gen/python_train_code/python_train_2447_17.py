S = input()
c = S.find('C')
f = S.find('F')
if c < 0 or f < 0:
    print('No')
    exit()
print('Yes' if f-c > 0 else 'No')
